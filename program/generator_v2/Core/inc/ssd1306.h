/*
 * @file ssd1306.h
 *
 * @Created on: 12.10.2021 09:46:34
 * @Author: stre_l0k
*/

#ifndef __ssd1306_h__
#define __ssd1306_h__


///--- #include
#include "stm32f1xx.h"


///--- enum's
enum ssd1306
{
    ssd1306_address                         = 0x78, // Device address on I2C
};

enum ssd1306_command
{

};


///--- initializations
uint8_t init_ssd1306(uint8_t i2c); // Init module

///--- handlers


///--- functions


///--- setters/getters


///--- struct


///--- constants


///--- varibles


///--- variables struct


///--- counters


///--- flags

#endif
