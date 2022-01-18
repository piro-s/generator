/**
 * @file tools.h
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
 * @Created: 24.07.2019 14:46:17
 * @Author : piro.tex
 */ 
 
#ifndef __tools_h__
#define __tools_h__


///--- #include
#include "stm32f1xx.h"

///--- enums
enum LED
{
    LED_ON                  = 10, // Selector - turn on
    LED_OFF                 = 11, // Selector - turn off
    LED_COLOR_RED           = 0, // Port A.0
    LED_COLOR_GREEN         = 1, // Port A.1
    LED_COLOR_BLUE          = 3, // Port A.3
    LED_COLOR_LIME          = 4, // Port A.0 + Port A.1
    LED_COLOR_WHITE         = 5 // Port A.0 + Port A.1 + Port A.3
}; // enum LED

enum states
{
    state_off               = 0,
    state_on                = 1,
    state_inf               = 20, // No pack, infinite impulse
    state_pack              = 21 // Pack mode
}; // enum states


enum sizes
{
    size_limit_PWM          = 900 * 72, // Max size for PWM
    size_buffer_DMA         = 2048, // Size buffer for DMA
    size_buffer_UART        = 32 // Size buffer for UART
}; // enum sizes


///--- functions()
void delay_us(uint32_t us); // delay in us
void delay_ms(uint32_t ms); // delay in ms
void Init_LED(void); // Init LED
void LED(uint8_t selector, uint8_t color); // On / off color


///--- variables
extern uint32_t u32_delay_ms; // delay in ms


#endif
