/**
 * @file generator_impulse.c
 *
 *
 * @Created: 16.01.2021 ‏‎9:11:10
 * @Author : piro.tex
 */

///--- include's
#include "../inc/generator.h"


///--- variables struct
gen_imp generator_impulse; // Current
gen_imp generator_impulse_rec; // For receive from PC


///--- variables


///--- buffers
uint16_t dataToSendDMA[size_buffer_DMA]; // Buffer for DMA


///--- handlers
void TIM3_IRQHandler(void) // Handler interrupt TIM3
{
    // Set out as high and start pulse
    TIM2->CR1 |= TIM_CR1_CEN; // Enable TIM2
    DMA1_Channel1->CCR |= DMA_CCR_EN; // Enable DMA

    TIM3->SR &= ~TIM_SR_UIF; // Clear bit interrupt

    return;
} // TIM3_IRQHandler

void DMA1_Channel1_IRQHandler(void) // Handler DMA1
{
    if(DMA1->ISR & DMA_ISR_TCIF1) // If tranmit complete
    {
        if(generator_impulse.state_pack == state_pack) // If pulses not infinite
        {
            TIM2->CR1 &= ~TIM_CR1_CEN; // Stop TIM2
            DMA1_Channel1->CCR &= ~DMA_CCR_EN; // Disable DMA
        } // if(generator_impulse.state_pack == state_pack)

        DMA1->IFCR = DMA_IFCR_CTCIF1; // Clear interrupt flag
    } // if(DMA1->ISR & DMA_ISR_TCIF1)

    return;
} // DMA1_Channel1_IRQHandler


//***
//------------------------------------------------------------------------------
//***


///--- impulse generator functions()
void change_Generator_Impulse(void) // Change generator mode
{
    stop_Generator_Impulse(); // Stop all generator timers
    set_Generator_Impulse(); // Setting generator timers
    start_Generator_Impulse(); // Start all generator timers

    return;
} // void change_Generator_Impulse(void)

void stop_Generator_Impulse(void) // Stop all generator timers
{
    DMA1_Channel1->CCR &= ~DMA_CCR_EN; // Disable DMA
    TIM2->CCMR2 &= ~TIM_CCMR2_OC3M_1; // 100: Force inactive TIM2
    TIM2->CR1 &= ~TIM_CR1_CEN; // Disable TIM2
    TIM3->CR1 &= ~TIM_CR1_CEN; // Disable TIM3

    return;
} // void stop_Generator_Impulse(void)

void set_Generator_Impulse(void) // Setting timers
{
    // Set pulse parameters
    TIM2->PSC = generator_impulse.pulse_psc;
    TIM2->ARR = generator_impulse.pulsePeriod;
    TIM3->PSC = generator_impulse.pack_psc;
    TIM3->ARR = generator_impulse.packPeriod;
    DMA1_Channel1->CNDTR = generator_impulse.pulseN; // Number of pulses in package

    for(uint16_t it = 0; it < size_buffer_DMA; it++)
        dataToSendDMA[it] = generator_impulse.pulseWidth; // Pulse width in ticks

    return;
} // void set_Generator_Impulse(void)

void start_Generator_Impulse(void) // Start all generator timers
{
    TIM3->CR1 |= TIM_CR1_CEN; // Enable TIM3
    TIM2->CCMR2 |= TIM_CCMR2_OC3M_1; // 110: PWM mode 1
    TIM2->CR1 |= TIM_CR1_CEN; // Enable TIM2
    DMA1_Channel1->CCR |= DMA_CCR_EN; // Enable DMA

    return;
} // void start_Generator_Impulse(void)

void copy_Generator_Impulse(gen_imp* from, gen_imp* to) // Copy parameters generator
{
    to->pulseWidth = from->pulseWidth;
    to->pulsePeriod = from->pulsePeriod;
    to->pulseN = from->pulseN;
    to->packPeriod = from->packPeriod;

    to->packPeriodMltpl = from->packPeriodMltpl;
    to->pulseWidthMltpl = from->pulseWidthMltpl;
    to->pulsePeriodMltpl = from->pulsePeriodMltpl;

    to->pulse_psc = from->pulse_psc;
    to->pack_psc = from->pack_psc;

    to->state_pack = from->state_pack;
    to->state_generation = from->state_generation;

    return;
} // void copy_Generator_Impulse(generator_impulse* from, generator_impulse* to)
