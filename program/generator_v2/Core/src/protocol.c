/**
 * @file protocol.c
 *
 *
 * @Created: 16.01.2021 ‏‎9:17:18
 * @Author : piro.tex
 */

///--- include's
#include "../inc/protocol.h"
#include "../inc/generator.h"

#include "../inc/uart.h"


///--- buffers
uint8_t dataReceiveUART[size_buffer_UART]; // Buffer for receive from UART
uint8_t dataTransmitUART[size_buffer_UART]; // Buffer for transmit to UART


///--- counters
uint8_t u8_counterRecUart = 0; // Counter received symbols from UART
uint8_t u8_counterRecUartWaiting = 0; // Counter waiting for the end of receiving data (if == 0xFF, clear all received data and counters)


///--- flags                // for all flags state_on - set; state_off - reset
uint8_t flag_uart_start = state_off; // Start receive from PC


///--- variables


//***
//------------------------------------------------------------------------------
//***


///--- handlers
void USART1_IRQHandler(void) // Handler interrupt USART1
{
    if(USART1->SR & USART_SR_RXNE)
    {
        uint8_t u8_data = USART1->DR;
        //while(!(USART1->SR & USART_SR_TC)) {}; // Checking the end of sending the previous character
        USART1->DR = u8_data; // Check receice
        if((u8_data == uart_com_start) & (flag_uart_start == state_off))
        {
            flag_uart_start = state_on;
            u8_counterRecUart = 0;
            u8_counterRecUartWaiting = 0;
        } // if((u8_data == uart_com_start) & (flag_uart_start == state_off))

        dataReceiveUART[u8_counterRecUart++] = u8_data; // Save data to buffer
    } // if(USART1->SR & USART_SR_RXNE)

    return;
} // USART1_IRQHandler


//***
//------------------------------------------------------------------------------
//***


///--- functions
uint8_t check_uart(void) // Check UART1 (data from pc)
{
    if(flag_uart_start == state_on) // If data start receive
    {
        if(dataReceiveUART[dataReceiveUART[uart_n_quantity]] == uart_com_stop) // if last byte == stop byte
        {
            if(dataReceiveUART[dataReceiveUART[uart_n_quantity] - uart_n_sum] == get_SUM(dataReceiveUART))
            {
                if(dataReceiveUART[dataReceiveUART[uart_n_quantity] - uart_n_xor] == get_XOR(dataReceiveUART))
                {
                    getUartData();
                    dataTransmitUART[uart_n_command] = dataReceiveUART[uart_n_command];
                    clear_uartRecData();
                    return uart_error_no;
                } // if(dataReceiveUART[dataReceiveUART[uart_n_quantity] - uart_n_xor] == get_XOR(dataReceiveUART))
                else
                {
                    clear_uartRecData();
                    dataTransmitUART[uart_n_command] = dataReceiveUART[uart_n_command];
                    return uart_error_xor;
                } // else
            } // if(dataReceiveUART[dataReceiveUART[uart_n_quantity] - uart_n_sum] == get_SUM(dataReceiveUART))
            else
            {
                clear_uartRecData();
                dataTransmitUART[uart_n_command] = dataReceiveUART[uart_n_command];
                return uart_error_sum;
            } // else
        } // if(dataReceiveUART[dataReceiveUART[uart_n_quantity]] == uart_com_stop)
    } // if(flag_uart_start == state_on)

    if(dataReceiveUART[0] != 0x00)
        u8_counterRecUartWaiting++;

    if(u8_counterRecUartWaiting >= uart_maxTime) // Data not received
        clear_uartRecData();

    return uart_error_noPack;
} // void check_uart(void)

uint8_t get_SUM(uint8_t* data) // Return SUM
{
    uint8_t sum = 0;

    for(uint8_t it = 0; it < data[uart_n_quantity] - uart_n_sum; it++)
        sum += data[it];
    sum += uart_com_stop;

    return sum;
} // uint8_t get_SUM(uint8_t* data)

uint8_t get_XOR(uint8_t* data) // Return XOR
{
    uint8_t xor = 0;

    for(uint8_t it = 0; it < data[uart_n_quantity] - uart_n_xor; it++)
        xor ^= data[it];
    xor ^= uart_com_stop;

    return xor;
} // uint8_t get_XOR(uint8_t* data)

uint8_t getUartData(void) // Get data from uart mass
{
    switch(dataReceiveUART[uart_n_command])
    {
    case uart_com_send_pulseWidth: // Save pulse width in generator_impulse_rec
        generator_impulse_rec.pulseWidth = (dataReceiveUART[uart_n_value] << 8) + (dataReceiveUART[uart_n_value + 1]);
        generator_impulse_rec.pulseWidthMltpl = dataReceiveUART[uart_n_measure];
        break;
    case uart_com_send_pulsePeriod: // Save pulse period in generator_impulse_rec
        generator_impulse_rec.pulsePeriod = (dataReceiveUART[uart_n_value] << 8) + (dataReceiveUART[uart_n_value + 1]);
        generator_impulse_rec.pulse_psc = (dataReceiveUART[uart_n_presscale] << 8) + (dataReceiveUART[uart_n_presscale + 1]);
        generator_impulse_rec.pulsePeriodMltpl = dataReceiveUART[uart_n_measure];
        break;
    case uart_com_send_packPeriod: // Save pack period in generator_impulse_rec
        generator_impulse_rec.packPeriod = (dataReceiveUART[uart_n_value] << 8) + (dataReceiveUART[uart_n_value + 1]);
        generator_impulse_rec.pack_psc = (dataReceiveUART[uart_n_presscale] << 8) + (dataReceiveUART[uart_n_presscale + 1]);
        generator_impulse_rec.packPeriodMltpl = dataReceiveUART[uart_n_measure];
        break;
    case uart_com_send_pulseN: // Save number pulses in pack in generator_impulse_rec
        generator_impulse_rec.pulseN = (dataReceiveUART[uart_n_value] << 8) + (dataReceiveUART[uart_n_value + 1]);
        // Set states
        if(generator_impulse_rec.pulseN == 0)
            generator_impulse_rec.state_pack = state_inf;
        else
            generator_impulse_rec.state_pack = state_pack;
        break;
    case uart_com_get_pulseWidth: // Send pulse width in generator on pc
        // In get_transmit_pack()
        break;
    case uart_com_get_pulsePeriod: // Send pulse period in generator on pc
        // In get_transmit_pack()
        break;
    case uart_com_get_packPeriod: // Send pack period in generator on pc
        // In get_transmit_pack()
        break;
    case uart_com_get_pulseN: // Send number pulses in pack in generator on pc
        // In get_transmit_pack()
        break;
    case uart_com_get_BMP180: // Send sensor availability on pc
        break;
    case uart_com_get_temp: // Send temp on pc
        break;
    case uart_com_set_parameters: // Save parameters in generator and change generator mode
        copy_Generator_Impulse(&generator_impulse_rec, &generator_impulse); // Copy received parameters
        change_Generator_Impulse(); // Change impulse generator mode
        break;
    case uart_com_on: // On generator
        start_Generator_Impulse(); // Start generation
        generator_impulse.state_generation = state_on;
        break;
    case uart_com_off: // Off generator
        stop_Generator_Impulse(); // Stop generation
        generator_impulse.state_generation = state_off;
        break;
    case uart_com_generation: // Generation state
        // In get_transmit_pack()
        break;
    default: // Return wrong command error
        return uart_error_command;
    } // switch(dataReceiveUART[uart_n_command])

    return uart_error_no;
} // uint8_t getUartData(void)

void clear_uartRecData(void) // Clear uart receive data, counters and flags
{
    for(uint8_t it = 0; it < size_buffer_UART; it++)
        dataReceiveUART[it] = 0x00;

    u8_counterRecUart = 0;
    u8_counterRecUartWaiting = 0;
    flag_uart_start = state_off;

    return;
} // void clear_uartRecData(void)

void clear_uartTrData(void) // Clear uart transmit data
{
    for(uint8_t it = 0; it < size_buffer_UART; it++)
        dataTransmitUART[it] = 0x00;

    return;
} // void clear_uartTrData(void)

void send_char(uint8_t data) // Send char to pc
{
    uart_TransmitByte(uart_UART1, data);

    return;
} // void send_char(uint8_t data)

void send_string(uint8_t* data, uint8_t length) // Send string to pc
{
    uart_TransmitBuffer(uart_UART1, data, length);

    return;
} // void send_string(uint8_t* data, uint8_t length)

void get_transmit_pack(uint8_t command, uint8_t error) // Send error/no error on pc
{
    clear_uartTrData(); // Clear uart transmit data

    dataTransmitUART[uart_n_start] = uart_com_start;
    dataTransmitUART[uart_n_command] = command;


    switch(command)
    {
    case uart_com_send_pulseWidth: // Save pulse width in generator_impulse_rec
        dataTransmitUART[uart_n_quantity] = uart_pack_response;
        dataTransmitUART[uart_n_response] = error;
        break;
    case uart_com_send_pulsePeriod: // Save pulse period in generator_impulse_rec
        dataTransmitUART[uart_n_quantity] = uart_pack_response;
        dataTransmitUART[uart_n_response] = error;
        break;
    case uart_com_send_packPeriod: // Save pack period in generator_impulse_rec
        dataTransmitUART[uart_n_quantity] = uart_pack_response;
        dataTransmitUART[uart_n_response] = error;
        break;
    case uart_com_send_pulseN: // Save number pulses in pack in generator_impulse_rec
        dataTransmitUART[uart_n_quantity] = uart_pack_response;
        dataTransmitUART[uart_n_response] = error;
        break;
    case uart_com_get_pulseWidth: // Send pulse width in generator on pc
        dataTransmitUART[uart_n_quantity] = uart_pack_pulseWidth;
        dataTransmitUART[uart_n_value] = (generator_impulse.pulseWidth >> 8);
        dataTransmitUART[uart_n_value + 1] = (uint8_t)generator_impulse.pulseWidth;
        dataTransmitUART[uart_n_measure] = generator_impulse.pulseWidthMltpl;
        break;
    case uart_com_get_pulsePeriod: // Send pulse period in generator on pc
        dataTransmitUART[uart_n_quantity] = uart_pack_period;
        dataTransmitUART[uart_n_value] = (generator_impulse.pulsePeriod >> 8);
        dataTransmitUART[uart_n_value + 1] = (uint8_t)generator_impulse.pulsePeriod;
        dataTransmitUART[uart_n_measure] = generator_impulse.pulsePeriodMltpl;
        dataTransmitUART[uart_n_presscale] = (generator_impulse.pulse_psc >> 8);
        dataTransmitUART[uart_n_presscale + 1] = (uint8_t)generator_impulse.pulse_psc;
        break;
    case uart_com_get_packPeriod: // Send pack period in generator on pc
        dataTransmitUART[uart_n_quantity] = uart_pack_period;
        dataTransmitUART[uart_n_value] = (generator_impulse.packPeriod >> 8);
        dataTransmitUART[uart_n_value + 1] = (uint8_t)generator_impulse.packPeriod;
        dataTransmitUART[uart_n_measure] = generator_impulse.packPeriodMltpl;
        dataTransmitUART[uart_n_presscale] = (generator_impulse.pack_psc >> 8);
        dataTransmitUART[uart_n_presscale + 1] = (uint8_t)generator_impulse.pack_psc;
        break;
    case uart_com_get_pulseN: // Send number pulses in pack in generator on pc
        dataTransmitUART[uart_n_quantity] = uart_pack_pulseN;
        dataTransmitUART[uart_n_value] = (generator_impulse.pulseN >> 8);
        dataTransmitUART[uart_n_value + 1] = (uint8_t)generator_impulse.pulseN;
        break;
    case uart_com_get_BMP180: // Send sensor availability on pc
        dataTransmitUART[uart_n_quantity] = uart_pack_response;
        dataTransmitUART[uart_n_response] = error;
        break;
    case uart_com_get_temp: // Send temp on pc
        ////////////TODO get value
        break;
    case uart_com_set_parameters: // Save parameters in generator and change generator mode
        dataTransmitUART[uart_n_quantity] = uart_pack_response;
        dataTransmitUART[uart_n_response] = error;
        break;
    case uart_com_on: // On generator
        dataTransmitUART[uart_n_quantity] = uart_pack_response;
        dataTransmitUART[uart_n_response] = error;
        break;
    case uart_com_off: // Off generator
        dataTransmitUART[uart_n_quantity] = uart_pack_response;
        dataTransmitUART[uart_n_response] = error;
        break;
    case uart_com_generation: // Generation state
        dataTransmitUART[uart_n_quantity] = uart_pack_response;
        dataTransmitUART[uart_n_response] = generator_impulse.state_generation;
        break;
    default: // Return wrong command error
        dataTransmitUART[uart_n_quantity] = uart_pack_response;
        dataTransmitUART[uart_n_response] = uart_error_command;
        break;
    } // switch(command)

    dataTransmitUART[dataTransmitUART[uart_n_quantity] - uart_n_sum] = get_SUM(dataTransmitUART);
    dataTransmitUART[dataTransmitUART[uart_n_quantity] - uart_n_xor] = get_XOR(dataTransmitUART);
    dataTransmitUART[dataTransmitUART[uart_n_quantity]] = uart_com_stop;

    /////////////TODO check +1
    send_string(dataTransmitUART, dataTransmitUART[uart_n_quantity] + 1); // +1, because check_sum
    clear_uartTrData(); // Clear uart transmit data


    return;
} // void get_transmit_pack(uint8_t command, uint8_t error)
