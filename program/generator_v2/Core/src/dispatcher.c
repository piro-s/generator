/**
 * @file dispatcher.c
 *
 *
 * @Created: 30.01.2021 ‏‎‏‎11:31:32
 * @Author : piro.tex
 */

///--- include's
#include "../inc/dispatcher.h"
#include "../inc/protocol.h"
#include "../inc/generator.h"


///--- constants
const uint16_t u16_maxTmr_uartRec = 1; // Time waiting in ms before check uart receive


///--- varibles
uint16_t u16_tmr_uartRec = 0;


//***
//------------------------------------------------------------------------------
//***


///--- handlers
void TIM4_IRQHandler(void) // Handler interrupt TIM4
{
    if(u16_tmr_uartRec)u16_tmr_uartRec--;


    TIM4->SR &= ~TIM_SR_UIF; // Clear bit interrupt

    return;
} // TIM4_IRQHandler


//***
//------------------------------------------------------------------------------
//***


///--- functions
void dispatcher(void) // Dispatcher
{
    doUartRec(); // Dispatcher UART receive

    return;
} // void dispatcher(void)

void doUartRec(void) // Dispatcher UART receive
{
    if(GetTmrUartRec() == 0)
    {
        /////////////////TODO send response
        uint8_t response = check_uart();
        if(response != uart_error_noPack)
            get_transmit_pack(dataTransmitUART[uart_n_command], response);

        SetTmrUartRec(u16_maxTmr_uartRec);
    } // if(GetTmrUartRec() == 0)

    return;
} // void doUartRec(void)


//***
//------------------------------------------------------------------------------
//***


///--- setters/getters
void SetTmrUartRec(uint16_t time) { u16_tmr_uartRec = time; }
uint16_t GetTmrUartRec(void) { return u16_tmr_uartRec; }
