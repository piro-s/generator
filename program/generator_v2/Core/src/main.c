/**
 *******************************************************************************
 * @file           : main.c
 * @author         : piro.tex
 * @brief          : Programmable generator - impulse & impulse packs, analog,
 * mode set in program on PC. Value in TIM set for f=72 MHz.
 * Max number of impulses in package - 2048.
 * Min pulse width 100 ns.
 *
 * Init mode:
 * - width - 1 us;
 * - period - 10 us;
 * - pack period - 100 us;
 * - number of impulses - 5.
 *
 * Periphery:
 * - TIM2 - PWM 3 channel - pulse length and period;
 * - TIM3 - start TIM2 - pack period;
 * - TIM4 - 1 ms dispatcher;
 * - DMA - 1 channel for TIM2 PWM channel 3;
 * - UART1 - 115200;
 * - I2C2 - for DAC & BMP180.
 *
 *******************************************************************************
**/


///--- #include
#include "stm32f1xx.h"

//#include "../inc/i2c.h"
#include "../inc/uart.h"

//#include "../inc/mcp4728.h"
//#include "../inc/ssd1306.h"

#include "../inc/tools.h"
#include "../inc/generator.h"
#include "../inc/protocol.h"
#include "../inc/dispatcher.h"


///--- initializations
void Init_TIM(void); // Init timers
void Init_DMA(void); // Init DMA
void Init_Struct(void); // Init structs


///--- handlers


///--- functions


///--- enum's


///--- struct


///--- constants


///--- counters


///--- flags                // for all flags state_on - set; state_off - reset


///--- varibles


///--- generator init value
uint16_t u16_packPeriod = 100 * 72 - 1; // Package period - 100 us (Init value)
uint16_t u16_pulseN = 5; // Size transmit package in DMA (number of impulses in package)
uint16_t u16_pulseWidth = 1 * 72 - 2; // Pulse width - 1 us (Init value)
uint16_t u16_pulsePeriod = 10 * 72 - 1; // Pulse period - 10 us (Init value)

uint8_t u8_packPeriodMltpl = 'u'; // Package period multiplier (us - init value)
uint8_t u8_pulseWidthMltpl = 'u'; // Pulse width multiplier (us - init value)
uint8_t u8_pulsePeriodMltpl = 'u'; // Pulse period multiplier (us - init value)

uint16_t u16_pack_psc = 0; // Prescaler for pack period
uint16_t u16_pulse_psc = 0; // Prescaler for pulse period

uint8_t u8_state_pack = state_pack; // State - pack or inf


///--- variables struct


///--- setters/getters



int main(void)
{
    //--- Core
    SetSysClockTo72(); // Set f = 72 MHz
    SystemCoreClockUpdate(); // Update core clock (necessary)


    //--- Periphery
    ///////////////////////// TODO led for error
    uart_Init(uart_UART1, 115200, uart_RXNEIE, uart_TXEIE_n);


    //--- Init
    Init_TIM(); // Init timers
    Init_DMA(); // Init DMA
    Init_Struct(); // Init structs
    //Init_LED(); // Init LED


    //--- Start
    clear_uartRecData(); // Clear uart receive data, counters and flags
    clear_uartTrData(); // Clear uart transmit data

    //LED(LED_OFF, LED_OFF); // Turn off all LED
    //LED(LED_ON, LED_COLOR_GREEN); // Turn on green LED

    start_Generator_Impulse(); // Start generator in init mode

    while(1)
    {
        dispatcher(); // Dispatcher
    } // while(1

} // int main(void)


//***
//------------------------------------------------------------------------------
//***


///--- initializations
void Init_TIM(void) // Init timers
{
    //--- TIM2 set us PWM channel 3 - for impulses -----------------------------
    //--- TIM3 set for start TIM2 - for impulse packages -----------------------
    //--- TIM4 set for 1 ms count ----------------------------------------------

    //--- Set TIM2
    RCC->APB1ENR |= RCC_APB1ENR_TIM2EN; // RCC TIM2
    RCC->APB2ENR |= RCC_APB2ENR_IOPAEN; // RCC Port A (PA2 - TIM2 Channel 3)

    GPIOA->CRL |= GPIO_CRL_CNF2_1; // Set PA2 as output and alter mode
    GPIOA->CRL &= ~GPIO_CRL_CNF2_0; // Set PA2 as output and alter mode
    GPIOA->CRL |= GPIO_CRL_MODE2; // Set front 50MHz

    TIM2->CCER = 0; // Reset CCER
    TIM2->PSC = u16_pulse_psc; // Without prescale (1 tick = 1 / f,  72 ticks - 1us)
    TIM2->ARR = u16_pulsePeriod; // Impulse period in ticks


    TIM2->CCR3 = u16_pulseWidth; // Pulse width in ticks
    TIM2->CCMR2 |= (TIM_CCMR2_OC3M_1 | TIM_CCMR2_OC3M_2); // 110: PWM mode 1
    TIM2->CCMR2 &= ~TIM_CCMR2_OC3M_0; // 110: PWM mode 1
    TIM2->CCER |= TIM_CCER_CC3E; // Set signal us output (output contorl enable)

    //--- Set DMA in TIM2
    TIM2->DIER |= TIM_DIER_UIE; // Enable interrupt from event
    TIM2->DIER |= TIM_DIER_CC3DE; // Enable request from DMA
    TIM2->CCMR2 |= TIM_CCMR2_OC3PE; // Enable preload


    //--- Set TIM3
    RCC->APB1ENR |= RCC_APB1ENR_TIM3EN; // RCC TIM3

    TIM3->PSC = u16_pack_psc; // Without prescale (1 tick = 1 / f,  72 ticks - 1us)
    TIM3->ARR = u16_packPeriod; // Impulse package period in ticks

    TIM3->DIER |= TIM_DIER_UIE; // Enable interrupt from overload
    NVIC_EnableIRQ(TIM3_IRQn); // Enable handler interrupt TIM3


    //--- Set TIM4
    RCC->APB1ENR |= RCC_APB1ENR_TIM4EN; // RCC TIM4

    TIM4->PSC = 72 - 1; // Prescaler (1 tick = 1 us)
    TIM4->ARR = 1000; // 1 ms - period in ticks
    TIM4->DIER |= TIM_DIER_UIE; // Enable interrupt from overload
    TIM4->CR1 |= TIM_CR1_CEN; // Enable TIM4
    NVIC_EnableIRQ(TIM4_IRQn); // Enable handler interrupt TIM4

    return;
} // Init_TIM

void Init_DMA(void) // Init DMA
{
    //--- DMA set channel 1 for TIM2 Channel 3 ---------------------------------
    for(uint16_t it = 0; it < size_buffer_DMA; it++)
        dataToSendDMA[it] = u16_pulseWidth; // Pulse width in ticks

    RCC->AHBENR |= RCC_AHBENR_DMA1EN; // RCC DMA1

    DMA1_Channel1->CCR |= (DMA_CCR_TCIE | DMA_CCR_TEIE); // Interrupt for complete transmit or error
    DMA1_Channel1->CCR |= DMA_CCR_DIR; // Direction - from memory to periphery
    DMA1_Channel1->CCR |= DMA_CCR_CIRC; // Cycle transmit
    DMA1_Channel1->CCR |= DMA_CCR_MINC; // Memory increment mode
    DMA1_Channel1->CCR |= DMA_CCR_PSIZE_0; // Receive data - 16 bit
    DMA1_Channel1->CCR |= DMA_CCR_MSIZE_1; // Transmit data - 32 bit

    DMA1_Channel1->CNDTR = u16_pulseN; // Size tranmit package
    DMA1_Channel1->CPAR = (uint32_t)&(TIM2->CCR3); // Address periphery
    DMA1_Channel1->CMAR = (uint32_t)dataToSendDMA; // Address buffer in memory

    NVIC_EnableIRQ(DMA1_Channel1_IRQn); // Enable interrupt for DMA

    return;
} // void Init_DMA(void)

void Init_Struct(void) // Init struct
{
    generator_impulse.pulseWidth = u16_pulseWidth;
    generator_impulse.pulsePeriod = u16_pulsePeriod;
    generator_impulse.pulseN = u16_pulseN;
    generator_impulse.packPeriod = u16_packPeriod;

    generator_impulse.packPeriodMltpl = u8_packPeriodMltpl;
    generator_impulse.pulseWidthMltpl = u8_pulseWidthMltpl;
    generator_impulse.pulsePeriodMltpl = u8_pulsePeriodMltpl;

    generator_impulse.pulse_psc = u16_pulse_psc; // Prescaler for pulse period
    generator_impulse.pack_psc = u16_pack_psc; // Prescaler for package period

    generator_impulse.state_pack = u8_state_pack;
    generator_impulse.state_generation = state_on;

    copy_Generator_Impulse(&generator_impulse, &generator_impulse_rec);

    return;
} // Init_Struct


//***
//------------------------------------------------------------------------------
//***


///--- handlers


//***
//------------------------------------------------------------------------------
//***


//***
//------------------------------------------------------------------------------
//***


///--- functions


//**------------------------------------------------------------------------**//
//**------------------------------------------------------------------------**//
//**------------------------------------------------------------------------**//
