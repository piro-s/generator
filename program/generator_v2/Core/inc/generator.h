/**
 * @file generator.h
 *
 *
 * @Created: 16.01.2021 ‏‎9:10:54
 * @Author : piro.tex
 */

#ifndef __generator_h__
#define __generator_h__


///--- #include
#include "stm32f1xx.h"

#include "../inc/tools.h"


///--- struct
typedef struct
{
    uint32_t pulseWidth; // Pulse width
    uint32_t pulsePeriod; // Pulse period
    uint16_t pulseN; // Size transmit package in DMA
    uint32_t packPeriod; // Package period

    uint32_t pulse_psc; // Presclaer for pulse period
    uint32_t pack_psc; // Prescaler for package period

    uint8_t packPeriodMltpl; // Package period multiplier (example: 's' ==> it's seconds)
    uint8_t pulseWidthMltpl; // Pulse width multiplier (example: 'm' ==> it's mili)
    uint8_t pulsePeriodMltpl; // Pulse period multiplier (example: 'u' ==> it's micro)

    uint8_t state_pack; // State - pack or inf
    uint8_t state_generation; // State - on or off
} gen_imp; // Struct for impulse generator data


///--- handlers
void TIM3_IRQHandler(void); // Handler TIM3
void DMA1_Channel1_IRQHandler(void); // Handler DMA1


///--- impulse generator functions()
void change_Generator_Impulse(void); // Change impulse generator mode
void stop_Generator_Impulse(void); // Stop all generator timers
void set_Generator_Impulse(void); // Setting generator timers
void start_Generator_Impulse(void); // Start all generator timers
void copy_Generator_Impulse(gen_imp* from, gen_imp* to); // Copy parameters generator


///--- buffers
extern uint16_t dataToSendDMA[size_buffer_DMA]; // Buffer for DMA


///--- variables struct
extern gen_imp generator_impulse; // Current
extern gen_imp generator_impulse_rec; // For receive from PC


///--- variables


#endif
