/**
 * @file uart.h
 *
 * Lib for UART
 *
 * UART1 - APB2, so max frequency 72 MHz, other 36 MHz. Uncomment necessary
 * f_apb in uart_Init.

void USARTn_IRQHandler(void) // handler USARTn
{
    if(USARTn->SR & USART_SR_RXNE) // Receive
    {
    
    } // if(USARTn->SR & USART_SR_RXNE)
    
    if(USARTn->SR & USART_SR_TXE) // Transmit
    {
    
    } // if(USARTn->SR & USART_SR_TXE)
    
    return;
} // USARTn_IRQHandler

 *
 * ----------
 *
 * Init:
 * uart_Init(uart, brr, irq_rx, irq_tx); // Set UART number, brr, need to interrupt RX and TX
 *
 *
 * Transmit:
 * uart_TransmitByte(uart, data); // Number UART, data byte; return error if wrong UART number
 * uart_TransmitBuffer(uart, &buffer, length); // Number UART, pointer buffer, length of buffer; return error if wrong UART number
 *
 * ----------
 *
 * @Created: 30.10.2019 16:12:59
 * @Author : piro.tex
 */
 
#ifndef __uart_h__
#define __uart_h__
 
 
///--- #include's
#include "stm32f1xx.h"


///--- enum's
enum uart
{
    uart_UART1              = 0x01, // UART1
    uart_UART2              = 0x02, // UART2
    uart_UART3              = 0x03, // UART3
    uart_RXNEIE_n           = 0x00, // No need interrupt
    uart_TXEIE_n            = 0x00, // No need interrupt
    uart_RXNEIE             = 0x01, // Need interrupt
    uart_TXEIE              = 0x01, // Need interrupt
    
    uart_maxTime            = 0xF0, // Max waiting time

    uart_Error_NoError      = 0x60, // No error
    uart_Error_Uart         = 0x61, // Wrong UART
    uart_Error_RX           = 0x62, // Max waiting time
}; // enum uart



///--- functions()
uint8_t uart_Init(uint8_t uart, uint32_t brr, uint8_t irq_rx, uint8_t irq_tx); // Init UART
uint8_t uart_TransmitByte(uint8_t uart, uint8_t data); // Send symbol on UART
uint8_t uart_TransmitBuffer(uint8_t uart, uint8_t* buffer, uint8_t length); // Send mass on UART



















#endif
