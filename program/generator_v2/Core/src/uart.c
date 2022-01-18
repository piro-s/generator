/**
 * @file uart.c
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
 * @Created: 30.10.2019 16:13:16
 * @Author : piro.tex
 */
 
///--- include's
#include "../inc/uart.h"
#include "../inc/tools.h"


///--- functions()
uint8_t uart_Init(uint8_t uart, uint32_t brr, uint8_t irq_rx, uint8_t irq_tx) // Init UART
{
    if(uart == uart_UART1)
    {
        //uint8_t f_apb = 8; // 8 MHz
        //uint8_t f_apb = 24; // 24 MHz
        //uint8_t f_apb = 36; // 36 MHz
        //uint8_t f_apb = 48; // 48 MHz
        //uint8_t f_apb = 56; // 56 MHz
        uint8_t f_apb = 72; // 72 MHz
        
        RCC->APB2ENR |= RCC_APB2ENR_USART1EN; // RCC USART1
        RCC->APB2ENR |= (RCC_APB2ENR_IOPAEN | RCC_APB2ENR_AFIOEN); // RCC Port A and alter mode

        //--- Set PA9 - TX
        GPIOA->CRH |= GPIO_CRH_CNF9_1; // Set Port A.9 as alter out
        GPIOA->CRH &= ~GPIO_CRH_CNF9_0; // Set Port A.9 as alter out
        GPIOA->CRH |= GPIO_CRH_MODE9; // Set 50 MHz
        //--- Set PA10 - RX
        GPIOA->CRH &= ~GPIO_CRH_CNF10_1; // Set Port A.10 as float input
        GPIOA->CRH |= GPIO_CRH_CNF10_0; // Set Port A.10 as float input
        GPIOA->CRH &= ~GPIO_CRH_MODE10; // Set Port A.10 as input

        //--- Set speed
        USART1->BRR = f_apb * 1000000.f / brr;
        
        if(irq_rx == uart_RXNEIE)
            USART1->CR1 |= USART_CR1_RXNEIE; // Interrupt on receive
        
        if(irq_tx == uart_TXEIE)
            USART1->CR1 |= USART_CR1_TXEIE; // Interrupt on transmit

        if((irq_rx == uart_RXNEIE) | (irq_tx == uart_TXEIE))
            NVIC_EnableIRQ(USART1_IRQn); // Enable handler interrupt USART1
        
        USART1->CR1 |= (USART_CR1_TE | USART_CR1_RE); // Enable receiver and transmiter USART1
        USART1->CR1 |= USART_CR1_UE; // Enable USART1
    } // if(uart == uart_UART1)
    else if(uart == uart_UART2)
    {
        //uint8_t f_apb = 8; // 8 MHz
        //uint8_t f_apb = 24; // 24 MHz
        uint8_t f_apb = 36; // 36 MHz
        //uint8_t f_apb = 48; // 48 MHz
        //uint8_t f_apb = 56; // 56 MHz
        //uint8_t f_apb = 72; // 72 MHz
        
        RCC->APB1ENR |= RCC_APB1ENR_USART2EN; // RCC USART2
        RCC->APB2ENR |= (RCC_APB2ENR_IOPAEN | RCC_APB2ENR_AFIOEN); // RCC Port A and alter mode

        //--- Set PA2 - TX
        GPIOA->CRL |= GPIO_CRL_CNF2_1; // Set Port A.2 as alter out
        GPIOA->CRL &= ~GPIO_CRL_CNF2_0; // Set Port A.2 as alter out
        GPIOA->CRL |= GPIO_CRL_MODE2; // Set 50 MHz
        //--- Set PA3 - RX
        GPIOA->CRL &= ~GPIO_CRL_CNF3_1; // Set Port A.3 as float input
        GPIOA->CRL |= GPIO_CRL_CNF3_0; // Set Port A.3 as float input
        GPIOA->CRL &= ~GPIO_CRL_MODE3; // Set Port A.3 as input

        //--- Set speed
        USART2->BRR = f_apb * 1000000.f / brr;
        
        if(irq_rx == uart_RXNEIE)
            USART2->CR1 |= USART_CR1_RXNEIE; // Interrupt on receive
        
        if(irq_tx == uart_TXEIE)
            USART2->CR1 |= USART_CR1_TXEIE; // Interrupt on transmit

        if((irq_rx == uart_RXNEIE) | (irq_tx == uart_TXEIE))
            NVIC_EnableIRQ(USART2_IRQn); // Enable handler interrupt USART2
        
        USART2->CR1 |= (USART_CR1_TE | USART_CR1_RE); // Enable receiver and transmiter USART2
        USART2->CR1 |= USART_CR1_UE; // Enable USART2
    } // else if(uart == uart_UART2)
    else if(uart == uart_UART3)
    {
        //uint8_t f_apb = 8; // 8 ���
        //uint8_t f_apb = 24; // 24 ���
        uint8_t f_apb = 36; // 36 ���
        //uint8_t f_apb = 48; // 48 ���
        //uint8_t f_apb = 56; // 56 ���
        //uint8_t f_apb = 72; // 72 ���
        
        RCC->APB1ENR |= RCC_APB1ENR_USART3EN; // RCC USART3
        RCC->APB2ENR |= (RCC_APB2ENR_IOPBEN | RCC_APB2ENR_AFIOEN); // RCC Port B and alter mode

        //--- Set PB10 - TX
        GPIOB->CRH |= GPIO_CRH_CNF10_1; // Set Port B.10 as alter out
        GPIOB->CRH &= ~GPIO_CRH_CNF10_0; // Set Port B.10 as alter out
        GPIOB->CRH |= GPIO_CRH_MODE10; // Set 50 MHz
        //--- Set PB11 - RX
        GPIOB->CRH &= ~GPIO_CRH_CNF11_1; // Set Port B.11 as float input
        GPIOB->CRH |= GPIO_CRH_CNF11_0; // Set Port B.11 as float input
        GPIOB->CRH &= ~GPIO_CRH_MODE11; // Set Port B.11 as input

        //--- Set speed
        USART3->BRR = f_apb * 1000000.f / brr;
        
        if(irq_rx == uart_RXNEIE)
            USART3->CR1 |= USART_CR1_RXNEIE; // Interrupt on receive
        
        if(irq_tx == uart_TXEIE)
            USART3->CR1 |= USART_CR1_TXEIE; // Interrupt on transmit

        if((irq_rx == uart_RXNEIE) | (irq_tx == uart_TXEIE))
            NVIC_EnableIRQ(USART3_IRQn); // Enable handler interrupt USART3

        USART3->CR1 |= (USART_CR1_TE | USART_CR1_RE); // Enable receiver and transmiter USART3
        USART3->CR1 |= USART_CR1_UE; // Enable USART3
    } // else if(uart == uart_UART3)
    else
        return uart_Error_Uart;
    
    return uart_Error_NoError;
} // uart_Init

uint8_t uart_TransmitByte(uint8_t uart, uint8_t data) // Send symbol on UART
{
    if(uart == uart_UART1)
    {
        while(!(USART1->SR & USART_SR_TC)) {}; // Checking the end of sending the previous character
        USART1->DR = data; // Send byte
    } // if(uart == uart_UART1)
    else if(uart == uart_UART2)
    {
        while(!(USART2->SR & USART_SR_TC)) {}; // Checking the end of sending the previous character
        USART2->DR = data; // Send byte
    } // else if(uart == uart_UART2)
    else if(uart == uart_UART3)
    {
        while(!(USART3->SR & USART_SR_TC)) {}; // Checking the end of sending the previous character
        USART3->DR = data; // Send byte
    } // else if(uart == uart_UART3)
    else
        return uart_Error_Uart;
    
    return uart_Error_NoError;
} // uart_TransmitByte

uint8_t uart_TransmitBuffer(uint8_t uart, uint8_t* buffer, uint8_t length) // Send mass on UART
{
    if(uart == uart_UART1)
    {
        for(uint8_t it = 0; it < length; it++)
        {
            while(!(USART1->SR & USART_SR_TC)) {}; // Checking the end of sending the previous character
            USART1->DR = buffer[it]; // Send byte
        } // for(uint8_t it = 0; it < length; it++)
    } // if(uart == uart_UART1)
    else if(uart == uart_UART2)
    {
        for(uint8_t it = 0; it < length; it++)
        {
            while(!(USART2->SR & USART_SR_TC)) {}; // Checking the end of sending the previous character
            USART2->DR = buffer[it]; // Send byte
        } // for(uint8_t it = 0; it < length; it++)
    } // else if(uart == uart_UART2)
    else if(uart == uart_UART3)
    {
        for(uint8_t it = 0; it < length; it++)
        {
            while(!(USART3->SR & USART_SR_TC)) {}; // Checking the end of sending the previous character
            USART3->DR = buffer[it]; // Send byte
        } // for(uint8_t it = 0; it < length; it++)
    } // else if(uart == uart_UART3)
    else
        return uart_Error_Uart;
    
    return uart_Error_NoError;
} // uart_TransmitBuffer
