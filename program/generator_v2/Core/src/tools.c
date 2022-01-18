/**
 * @file tools.c
 *
 * delay_us take from internet
 *
 * delay_ms - in TIM handler necessary add:
    if(u32_delay_ms)u32_delay_ms--;
 *
 * LED(selector, color) - selector (LED_ON or LED_OFF), color - color. Before
 * use this func need call Init_LED().
 *
 * getNorm() - for transform value from PC
 *
 * @Created: 24.07.2019 14:46:37
 * @Author : piro.tex
 */ 

///--- include's
#include "../inc/tools.h"
#include "../inc/protocol.h"


///--- variables
uint32_t u32_delay_ms = 0; // delay in ms


///--- functions
void delay_us(uint32_t us) // delay in us
{
    ///***--- Prescaler 9 take from internet -----------------------------***///
    
    //RCC_Clocks = 72000000; // Clock frequency
    us *= (72000000 / 1000000) / 9;
    while (us--) ;
    
    return;
} // void delay_us(uint32_t us)

void delay_ms(uint32_t ms) // delay in ms
{
    u32_delay_ms = ms;
    while(u32_delay_ms);
} // void delay_ms(uint32_t ms)

void Init_LED(void) // Init LED
{
    //--- LED Red - PA0, LED Green - PA1, LED Blue - PA3
    RCC->APB2ENR |= RCC_APB2ENR_IOPAEN; // RCC Port A

    GPIOA->CRL &= ~(GPIO_CRL_CNF0 | GPIO_CRL_CNF1 | GPIO_CRL_CNF3); // Set PA0,1,3 as output
    GPIOA->CRL |= (GPIO_CRL_MODE0 | GPIO_CRL_MODE1 | GPIO_CRL_MODE3); // Set PA0,1,3 as output - front 50 MHz

    return;
} // void Init_LED(void)

void LED(uint8_t selector, uint8_t color) // On/off color
{
    if(selector == LED_OFF) // Color must be off
        {
            switch(color)
            {
                case LED_COLOR_RED:
                    GPIOA->ODR |= (1 << LED_COLOR_RED);
                    break;
                case LED_COLOR_GREEN:
                    GPIOA->ODR |= (1 << LED_COLOR_GREEN);
                    break;
                case LED_COLOR_BLUE:
                    GPIOA->ODR |= (1 << LED_COLOR_BLUE);
                    break;
                case LED_COLOR_LIME:
                    GPIOA->ODR |= (1 << LED_COLOR_RED);
                    GPIOA->ODR |= (1 << LED_COLOR_GREEN);
                    break;
                case LED_COLOR_WHITE:
                case LED_OFF: // All off
                    GPIOA->ODR |= (1 << LED_COLOR_RED);
                    GPIOA->ODR |= (1 << LED_COLOR_GREEN);
                    GPIOA->ODR |= (1 << LED_COLOR_BLUE);
                    break;
            } // switch
        } // if
        else if(selector == LED_ON) // Color must be on
        {
            switch(color)
            {
                case LED_COLOR_RED:
                    GPIOA->ODR &= ~(1 << LED_COLOR_RED);
                    break;
                case LED_COLOR_GREEN:
                    GPIOA->ODR &= ~(1 << LED_COLOR_GREEN);
                    break;
                case LED_COLOR_BLUE:
                    GPIOA->ODR &= ~(1 << LED_COLOR_BLUE);
                    break;
                case LED_COLOR_LIME:
                    GPIOA->ODR &= ~(1 << LED_COLOR_RED);
                    GPIOA->ODR &= ~(1 << LED_COLOR_GREEN);
                    break;
                case LED_COLOR_WHITE:
                case LED_ON: // All on
                    GPIOA->ODR &= ~(1 << LED_COLOR_RED);
                    GPIOA->ODR &= ~(1 << LED_COLOR_GREEN);
                    GPIOA->ODR &= ~(1 << LED_COLOR_BLUE);
                    break;
            } // switch
        } // else if
} // void LED(uint8_t selector, uint8_t color)
