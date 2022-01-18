/**
 * @file dispatcher.h
 *
 *
 * @Created: 30.01.2021 ‏‎‏‎11:31:56
 * @Author : piro.tex
 */

#ifndef __dispatcher_h__
#define __dispatcher_h__


///--- #include
#include "stm32f1xx.h"


///--- handlers
void TIM4_IRQHandler(void); // Handler TIM4


///--- constants
extern const uint16_t u16_maxTmr_uartRec; // Time waiting in ms before check uart receive


///--- varibles
extern uint16_t u16_tmr_uartRec;


///--- functions()
void dispatcher(void); // Dispatcher
void doUartRec(void); // Dispatcher UART receive


///--- setters/getters
void SetTmrUartRec(uint16_t time);
uint16_t GetTmrUartRec(void);


#endif
