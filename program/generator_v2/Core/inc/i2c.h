/**
 * @file i2c.h
 *
 * Lib for I2C
 *
 * To work, select the interface number during initialization
 * In address send them as xxxx xxxY, where Y - read/write
 *
 * ----------
 *
 * Init:
 * i2c_Init(i2c, mode, duty); // Set number I2C - i2c_I2C1 or i2c_I2C2, mode (Sm - 100kHz, Fm - 400kHz) and duty (Sm or 2, or 16/9)
 *
 *
 * Transmit:
 * - transmit byte:
 * i2c_TransmitByte(i2c, address, reg_add, byte); // Number I2C, device address, register address, data byte; return error code
 *
 * - transmit buffer:
 * i2c_TransmitBuffer(i2c, address, reg_add, &buffer, length); // Number I2C, device address, register address, pointer buffer, length of buffer; return error code
 *
 *
 * Receive:
 * - receive byte:
 * i2c_ReceiveByte(i2c, address, reg_add, &data); // Number I2C, device address, register address, pointer data; return error code
 *
 * - receive buffer:
 * i2c_ReceiveBuffer(i2c, address, reg_add, &buffer, length); // Number I2C, device address, register address, pointer buffer, length of buffer; return error code
 *
 * ----------
 *
 * @Created: 10.10.2019 16:30:13
 * @Author : piro.tex
 */ 
 
#ifndef __i2c_h__
#define __i2c_h__


///--- #include's
#include "stm32f1xx.h"


///--- enum's
enum i2c
{
    i2c_I2C1                    = 0x01, // I2C1
    i2c_I2C2                    = 0x02, // I2C2
    i2c_mode_Sm                 = 0x01, // 100 kHz SCL
    i2c_mode_Fm                 = 0x02, // 400 kHz SCL
    i2c_duty_Sm                 = 0x00, // Sm mode
    i2c_duty_2                  = 0x01, // t_low/t_high = 2
    i2c_duty_16_9               = 0x02, // t_low/t_high = 16/9
    
    i2c_Mask_WriteAnd           = 0xFE, // Mask for write in device
    i2c_Mask_ReadOr             = 0x01, // Mask for read from device
    i2c_Error_maxTime           = 0xF0, // Max waiting time
    
    i2c_Error_NoError           = 0x70, // No error
    i2c_Error_Wrong_I2C         = 0x71, // Wrong I2C number
    i2c_Error_Wrong_Mode        = 0x72, // Wrong I2C mode
    i2c_Error_Wrong_Duty        = 0x73, // Wrong I2C duty
    i2c_Error_NotResponse       = 0x74, // No response from device
    i2c_Error_NotResponse_RXNE  = 0x75, // Return from RXNE
    i2c_Error_NotResponse_ADDR  = 0x76, // Return from ADDR
    i2c_Error_NotResponse_SB    = 0x77, // Return from SB
    i2c_Error_NotResponse_TXE   = 0x78, // Return from TXE
    i2c_Error_NotResponse_BTF   = 0x79, // Return from BTF
}; // enum i2c


///--- functions
uint8_t i2c_Init(uint8_t i2c, uint8_t mode, uint8_t duty); // Init
uint8_t i2c_TransmitByte(uint8_t i2c, uint8_t address, uint8_t reg_add, uint8_t byte); // Transmit byte to I2C
uint8_t i2c_TransmitBuffer(uint8_t i2c, uint8_t address, uint8_t reg_add, uint8_t* buffer, uint8_t length); // Transmit buffer to I2C
uint8_t i2c_ReceiveByte(uint8_t i2c, uint8_t address, uint8_t reg_add, uint8_t* data); // Receive byte from I2C
uint8_t i2c_ReceiveBuffer(uint8_t i2c, uint8_t address, uint8_t reg_add, uint8_t* buffer, uint8_t length); // Receive buffer from I2C


#endif
