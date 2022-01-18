/**
 * @file protocol.h
 *
 *
 * @Created: 16.01.2021 ‏‎9:17:08
 * @Author : piro.tex
 */

#ifndef __protocol_h__
#define __protocol_h__


///--- #include
#include "stm32f1xx.h"

#include "../inc/tools.h"

///--- enums
enum uarts // see protocol
{
    ///--- errors
    uart_error_no             = 0x90, // No error
    uart_error_xor            = 0x91, // Wrong XOR
    uart_error_sum            = 0x92, // Wrong SUM
    uart_error_time           = 0x93, // Long waiting pack
    uart_error_command        = 0x94, // Wrong receive command
    uart_error_noPack         = 0x95, // No packet


    ///--- byte number
    uart_n_start              = 0,
    uart_n_quantity           = 1, // Number of byte in pack
    uart_n_command            = 2,
    uart_n_value              = 3, // 2 byte
    uart_n_response           = 3,
    uart_n_measure            = 5,
    uart_n_presscale          = 6, // 2  byte
    uart_n_sum                = 2, // Quantity - 2
    uart_n_xor                = 1, // Quantity - 1


    ///--- pack length
    uart_pack_getParameters   = 5,
    uart_pack_setParameters   = 5,
    uart_pack_response        = 6,
    uart_pack_temp            = 7,
    uart_pack_pulseN          = 7,
    uart_pack_period          = 10,
    uart_pack_pulseWidth      = 8,


    ///--- command
    uart_com_start            = 0xA5,
    uart_com_stop             = 0x5A,
    uart_com_send_pulseWidth  = 0x70, // Save from pc
    uart_com_send_pulsePeriod = 0x71, // Save from pc
    uart_com_send_packPeriod  = 0x72, // Save from pc
    uart_com_send_pulseN      = 0x73, // Save from pc
    uart_com_get_pulseWidth   = 0x80, // Send on pc
    uart_com_get_pulsePeriod  = 0x81, // Send on pc
    uart_com_get_packPeriod   = 0x82, // Send on pc
    uart_com_get_pulseN       = 0x83, // Send on pc
    uart_com_get_BMP180       = 0x90, // Send sensor availability
    uart_com_get_temp         = 0x91, // Send temp on pc
    uart_com_set_parameters   = 0xE0, // Set parameters from generator_impulse_rec
    uart_com_on               = 0xE1, // On impulse generator
    uart_com_off              = 0xE2, // Off impulse generator
    uart_com_generation       = 0xE3, // State impulse generator


    ///--- measure
    uart_measure_u            = 'u', // us
    uart_measure_m            = 'm', // ms
    uart_measure_s            = 's', // s
    uart_measure_t            = 't' // tick
}; // enum uarts


///--- handlers
void USART1_IRQHandler(void); // Handler USART1

///--- functions()
uint8_t check_uart(void); // Check UART1 (data from pc)
uint8_t get_SUM(uint8_t* data); // Return SUM
uint8_t get_XOR(uint8_t* data); // Return XOR
uint8_t getUartData(void); // Get data from uart mass
void clear_uartRecData(void); // Clear uart receive data, counters and flags
void clear_uartTrData(void); // Clear uart transmit data
void send_char(uint8_t data); // Send char to pc
void send_string(uint8_t* data, uint8_t length); // Send string to pc
void get_transmit_pack(uint8_t command, uint8_t error); // Send error/no error or response on pc

///--- counters
extern uint8_t u8_counterRecUart; // Counter received symbols from UART
extern uint8_t u8_counterRecUartWaiting; // Counter waiting for the end of receiving data (if == 0xFF, clear all received data and counters)


///--- flags                // for all flags state_on - set; state_off - reset
extern uint8_t flag_uart_start; // Start receive from PC


///--- buffers
extern uint8_t dataReceiveUART[size_buffer_UART]; // Buffer for receive from UART
extern uint8_t dataTransmitUART[size_buffer_UART]; // Buffer for transmit to UART


///--- variables

#endif
