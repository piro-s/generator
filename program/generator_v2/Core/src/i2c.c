/**
 * @file i2c.c
 *
 * Lib for I2C
 *
 * To work, select the interface number during initialization
 * In address send them as xxxx xxxY, where Y - read/write
 *
 * ----------
 *
 * Init:
 * - i2c_Init(i2c, mode); // Set number I2C - i2c_I2C1 or i2c_I2C2, and mode (Sm - 100kHz, Fm - 400kHz)
 *
 *
 * Transmit:
 * - transmit byte:
 * i2c_TransmitByte(i2c, address, reg_add, byte); // Number I2C, device address, register address, data byte
 *
 * - transmit buffer:
 * i2c_TransmitBuffer(i2c, address, reg_add, &buffer, length); // Number I2C, device address, register address, pointer buffer, length of buffer
 *
 *
 * Receive:
 * - receive byte:
 * i2c_ReceiveByte(i2c, address, reg_add, data); // Number I2C, device address, register address, pointer data; return error code
 *
 * - receive buffer:
 * i2c_ReceiveBuffer(i2c, address, reg_add, &buffer, length); // Number I2C, device address, register address, pointer buffer, length of buffer; return error code
 *
 * ----------
 *
 * @Created: 10.10.2019 16:30:25
 * @Author : stre_l0k
 */ 
 
///--- include's
#include "../inc/i2c.h"
#include "../inc/tools.h"


///--- functions
uint8_t i2c_Init(uint8_t i2c, uint8_t mode, uint8_t duty) // Init
{
    ///--- http://mcu.goodboard.ru/viewtopic.php?id=14 ----------------------///
    if(i2c == i2c_I2C1)
    {
        //--- Set PORTB.6 and PORTB.7
        RCC->APB2ENR |= (RCC_APB2ENR_IOPBEN | RCC_APB2ENR_AFIOEN); // RCC PORTB
        RCC->APB1ENR |= (RCC_APB1ENR_I2C1EN); // RCC I2C1
        GPIOB->CRL |= (GPIO_CRL_CNF6 | GPIO_CRL_CNF7); // Alternative function - open drain
        GPIOB->CRL |= (GPIO_CRL_MODE6_0 | GPIO_CRL_MODE7_0); // Set 10 MHz
        
        //--- Disable I2C1 before set parameters, if he was working
        I2C1->CR1 &= ~I2C_CR1_PE; // Disable I2C1

        //--- Set freq pclk1 and rise time
        I2C1->CR2 |= (I2C_CR2_FREQ & 36); // Freq PLCK1
        I2C1->TRISE = 36 + 1; // Rise time

        //--- Set mode and duty
        if(mode == i2c_mode_Sm) // Sm mode
        {
            // Max Fplck1 = 36 MHz, so for 100kHz speed
            I2C1->CCR |= (I2C_CCR_CCR | 180); // CCR = (1 / 100kHz) / (1 / Fplck1) / 2 ==> (1 / 100kHz) / (1 / 36MHz) / 2 = 180
        } // if(mode == i2c_mode_Sm)
        else if(mode == i2c_mode_Fm) // Fm mode
        {
            // Max Fplck1 = 36 MHz, so for 400kHz speed
            if(duty == i2c_duty_2) //  t_low/t_high = 2
            {
                I2C1->CCR |= (I2C_CCR_CCR | 30); // CCR = (1 / 400kHz) / (1 / Fplck1) / 3 ==> (1 / 400kHz) / (1 / 36MHz) / 3 = 30
            } // if(duty == i2c_duty_2)
            else if(duty == i2c_duty_16_9) //  t_low/t_high = 16/9
            {
                I2C1->CCR |= (I2C_CCR_CCR | 4); // CCR = (1 / 400kHz) / (1 / Fplck1) / 25 ==> (1 / 400kHz) / (1 / 36MHz) / 25 = 4
            } // else if(duty == i2c_duty_16_9)
            else
                return i2c_Error_Wrong_Duty;
        } // else if(mode == i2c_mode_Fm)
        else
            return i2c_Error_Wrong_Mode;

        I2C1->CR1 |= I2C_CR1_ACK; // Generate ACK after bit receive
        I2C1->CR1 |= I2C_CR1_PE; // Start I2C1
    } // if(i2c == i2c_I2C1)
    else if(i2c == i2c_I2C2)
    {
        //--- Set PORTB.10 and PORTB.11
        RCC->APB2ENR |= (RCC_APB2ENR_IOPBEN | RCC_APB2ENR_AFIOEN); // RCC PORTB
        RCC->APB1ENR |= (RCC_APB1ENR_I2C2EN); // RCC I2C2
        GPIOB->CRH |= (GPIO_CRH_CNF10 | GPIO_CRH_CNF11); // Alternative function - open drain
        GPIOB->CRH |= (GPIO_CRH_MODE10_0 | GPIO_CRH_MODE11_0); // Set 10 MHz
        
        //--- Disable I2C2 before set parameters, if he was working
        I2C2->CR1 &= ~I2C_CR1_PE; // Disable I2C1

        //--- Set freq pclk1 and rise time
        I2C2->CR2 |= (I2C_CR2_FREQ & 36); // Freq PLCK1
        I2C2->TRISE = 36 + 1; // Rise time

        //--- Set mode and duty
        if(mode == i2c_mode_Sm) // Sm mode
        {
            // Max Fplck1 = 36 MHz, so for 100kHz speed
            I2C2->CCR |= (I2C_CCR_CCR | 180); // CCR = (1 / 100kHz) / (1 / Fplck1) / 2 ==> (1 / 100kHz) / (1 / 36MHz) / 2 = 180
        } // if(mode == i2c_mode_Sm)
        else if(mode == i2c_mode_Fm) // Fm mode
        {
            // Max Fplck1 = 36 MHz, so for 400kHz speed
            if(duty == i2c_duty_2) //  t_low/t_high = 2
            {
                I2C2->CCR |= (I2C_CCR_CCR | 30); // CCR = (1 / 400kHz) / (1 / Fplck1) / 3 ==> (1 / 400kHz) / (1 / 36MHz) / 3 = 30
            } // if(duty == i2c_duty_2)
            else if(duty == i2c_duty_16_9) //  t_low/t_high = 16/9
            {
                I2C2->CCR |= (I2C_CCR_CCR | 4); // CCR = (1 / 400kHz) / (1 / Fplck1) / 25 ==> (1 / 400kHz) / (1 / 36MHz) / 25 = 4
            } // else if(duty == i2c_duty_16_9)
            else
                return i2c_Error_Wrong_Duty;
        } // else if(mode == i2c_mode_Fm)
        else
            return i2c_Error_Wrong_Mode;

        I2C2->CR1 |= I2C_CR1_ACK; // Generate ACK after bit receive
        I2C2->CR1 |= I2C_CR1_PE; // Start I2C2
    } // else if(i2c == i2c_I2C2)
    else
        return i2c_Error_Wrong_I2C;
    
    return i2c_Error_NoError;
} // i2c_Init

uint8_t i2c_TransmitByte(uint8_t i2c, uint8_t address, uint8_t reg_add, uint8_t byte) // Transmit byte to I2C
{
    ///--- http://mcu.goodboard.ru/viewtopic.php?id=14 ----------------------///
    if(i2c == i2c_I2C1)
    {
        I2C1->CR1 |= I2C_CR1_START; // Formirate start
        uint8_t u8_waitingTime = 0;
        while(!(I2C1->SR1 & I2C_SR1_SB))
        {
            u8_waitingTime++;
            delay_us(1);
            if(u8_waitingTime > i2c_Error_maxTime)
                return i2c_Error_NotResponse_SB;
        } // while(!(I2C1->SR1 & I2C_SR1_SB))
        (void) I2C1->SR1;
        
        
        I2C1->DR = (address & i2c_Mask_WriteAnd); // Send device address - write
        
        u8_waitingTime = 0;
        while(!(I2C1->SR1 & I2C_SR1_ADDR))
        {
            u8_waitingTime++;
            delay_us(1);
            if(u8_waitingTime > i2c_Error_maxTime)
                return i2c_Error_NotResponse_ADDR;
        } // while(!(I2C1->SR1 & I2C_SR1_ADDR))
        (void) I2C1->SR1;
        (void) I2C1->SR2;
        
        
        I2C1->DR = reg_add; // Send register address (control register)
        
        u8_waitingTime = 0;
        while(!(I2C1->SR1 & I2C_SR1_TXE))
        {
            u8_waitingTime++;
            delay_us(1);
            if(u8_waitingTime > i2c_Error_maxTime)
                return i2c_Error_NotResponse_TXE;
        } // while(!(I2C1->SR1 & I2C_SR1_TXE))
        
        
        I2C1->DR = byte; // Send data
        
        u8_waitingTime = 0;
        while(!(I2C1->SR1 & I2C_SR1_BTF))
        {
            u8_waitingTime++;
            delay_us(1);
            if(u8_waitingTime > i2c_Error_maxTime)
                return i2c_Error_NotResponse_BTF;
        } // while(!(I2C1->SR1 & I2C_SR1_BTF))
        
        I2C1->CR1 |= I2C_CR1_STOP;
    } // if(i2c == i2c_I2C1)
    else if(i2c == i2c_I2C2)
    {
        I2C2->CR1 |= I2C_CR1_START; // Formirate start
        uint8_t u8_waitingTime = 0;
        while(!(I2C2->SR1 & I2C_SR1_SB))
        {
            u8_waitingTime++;
            delay_us(1);
            if(u8_waitingTime > i2c_Error_maxTime)
                return i2c_Error_NotResponse_SB;
        } // while(!(I2C2->SR1 & I2C_SR1_SB))
        (void) I2C2->SR1;
        
        
        I2C2->DR = (address & i2c_Mask_WriteAnd); // Send device address - write
        
        u8_waitingTime = 0;
        while(!(I2C2->SR1 & I2C_SR1_ADDR))
        {
            u8_waitingTime++;
            delay_us(1);
            if(u8_waitingTime > i2c_Error_maxTime)
                return i2c_Error_NotResponse_ADDR;
        } // while(!(I2C2->SR1 & I2C_SR1_ADDR))
        (void) I2C2->SR1;
        (void) I2C2->SR2;
        
        
        I2C2->DR = reg_add; // Send register address (control register)
        
        u8_waitingTime = 0;
        while(!(I2C2->SR1 & I2C_SR1_TXE))
        {
            u8_waitingTime++;
            delay_us(1);
            if(u8_waitingTime > i2c_Error_maxTime)
                return i2c_Error_NotResponse_TXE;
        } // while(!(I2C2->SR1 & I2C_SR1_TXE))
        
        
        I2C2->DR = byte; // Send data
        
        u8_waitingTime = 0;
        while(!(I2C2->SR1 & I2C_SR1_BTF))
        {
            u8_waitingTime++;
            delay_us(1);
            if(u8_waitingTime > i2c_Error_maxTime)
                return i2c_Error_NotResponse_BTF;
        } // while(!(I2C2->SR1 & I2C_SR1_BTF))
        
        I2C2->CR1 |= I2C_CR1_STOP;
    } // else if(i2c == i2c_I2C2)
    else
        return i2c_Error_Wrong_I2C;
    
    
    return i2c_Error_NoError;
} // i2c_TransmitByte

uint8_t i2c_TransmitBuffer(uint8_t i2c, uint8_t address, uint8_t reg_add, uint8_t* buffer, uint8_t length) // Transmit buffer to I2C
{
    ///--- http://mcu.goodboard.ru/viewtopic.php?id=14 ----------------------///
    if(i2c == i2c_I2C1)
    {
        I2C1->CR1 |= I2C_CR1_START; // Formirate start
        uint8_t u8_waitingTime = 0;
        while(!(I2C1->SR1 & I2C_SR1_SB))
        {
            u8_waitingTime++;
            delay_us(1);
            if(u8_waitingTime > i2c_Error_maxTime)
                return i2c_Error_NotResponse_SB;
        } // while(!(I2C1->SR1 & I2C_SR1_SB))
        (void) I2C1->SR1;
        
        
        I2C1->DR = (address & i2c_Mask_WriteAnd); // Send device address - write
        
        u8_waitingTime = 0;
        while(!(I2C1->SR1 & I2C_SR1_ADDR))
        {
            u8_waitingTime++;
            delay_us(1);
            if(u8_waitingTime > i2c_Error_maxTime)
                return i2c_Error_NotResponse_ADDR;
        } // while(!(I2C1->SR1 & I2C_SR1_ADDR))
        (void) I2C1->SR1;
        (void) I2C1->SR2;
        
        
        I2C1->DR = reg_add; // Send register address (control register)
        
        u8_waitingTime = 0;
        while(!(I2C1->SR1 & I2C_SR1_TXE))
        {
            u8_waitingTime++;
            delay_us(1);
            if(u8_waitingTime > i2c_Error_maxTime)
                return i2c_Error_NotResponse_TXE;
        } // while(!(I2C1->SR1 & I2C_SR1_TXE))
        
        
        for(uint8_t it = 0; it < length; it++)
        {
            I2C1->DR = buffer[it]; // Send data
            
            u8_waitingTime = 0;
            while(!(I2C1->SR1 & I2C_SR1_TXE))
            {
                u8_waitingTime++;
                delay_us(1);
                if(u8_waitingTime > i2c_Error_maxTime)
                    return i2c_Error_NotResponse_TXE;
            } // while(!(I2C1->SR1 & I2C_SR1_TXE))
        } // for(uint8_t it = 0; it < length; it++)
        
        //--- Waiting transmition complete
        u8_waitingTime = 0;
        while(!(I2C1->SR1 & I2C_SR1_BTF))
        {
            u8_waitingTime++;
            delay_us(1);
            if(u8_waitingTime > i2c_Error_maxTime)
                return i2c_Error_NotResponse_BTF;
        } // while(!(I2C1->SR1 & I2C_SR1_BTF))
        
        I2C1->CR1 |= I2C_CR1_STOP;
    } // if(i2c == i2c_I2C1)
    else if(i2c == i2c_I2C2)
    {
        I2C2->CR1 |= I2C_CR1_START; // Formirate start
        uint8_t u8_waitingTime = 0;
        while(!(I2C2->SR1 & I2C_SR1_SB))
        {
            u8_waitingTime++;
            delay_us(1);
            if(u8_waitingTime > i2c_Error_maxTime)
                return i2c_Error_NotResponse_SB;
        } // while(!(I2C2->SR1 & I2C_SR1_SB))
        (void) I2C2->SR1;


        I2C2->DR = (address & i2c_Mask_WriteAnd); // Send device address - write

        u8_waitingTime = 0;
        while(!(I2C2->SR1 & I2C_SR1_ADDR))
        {
            u8_waitingTime++;
            delay_us(1);
            if(u8_waitingTime > i2c_Error_maxTime)
                return i2c_Error_NotResponse_ADDR;
        } // while(!(I2C2->SR1 & I2C_SR1_ADDR))
        (void) I2C2->SR1;
        (void) I2C2->SR2;


        I2C2->DR = reg_add; // Send register address (control register)

        u8_waitingTime = 0;
        while(!(I2C2->SR1 & I2C_SR1_TXE))
        {
            u8_waitingTime++;
            delay_us(1);
            if(u8_waitingTime > i2c_Error_maxTime)
                return i2c_Error_NotResponse_TXE;
        } // while(!(I2C2->SR1 & I2C_SR1_TXE))


        for(uint8_t it = 0; it < length; it++)
        {
            I2C2->DR = buffer[it]; // Send data

            u8_waitingTime = 0;
            while(!(I2C2->SR1 & I2C_SR1_TXE))
            {
                u8_waitingTime++;
                delay_us(1);
                if(u8_waitingTime > i2c_Error_maxTime)
                    return i2c_Error_NotResponse_TXE;
            } // while(!(I2C2->SR1 & I2C_SR1_TXE))
        } // for(uint8_t it = 0; it < length; it++)

        //--- Waiting transmition complete
        u8_waitingTime = 0;
        while(!(I2C2->SR1 & I2C_SR1_BTF))
        {
            u8_waitingTime++;
            delay_us(1);
            if(u8_waitingTime > i2c_Error_maxTime)
                return i2c_Error_NotResponse_BTF;
        } // while(!(I2C2->SR1 & I2C_SR1_BTF))

        I2C2->CR1 |= I2C_CR1_STOP;
    } // if(i2c == i2c_I2C2)
    else
        return i2c_Error_Wrong_I2C;

    return i2c_Error_NoError;
} // i2c_TransmitBuffer

uint8_t i2c_ReceiveByte(uint8_t i2c, uint8_t address, uint8_t reg_add, uint8_t* data) // Receive byte from I2C
{
    ///--- http://mcu.goodboard.ru/viewtopic.php?id=14 ----------------------///
    uint8_t u8_temp = 0; // Receive byte
    
    if(i2c == i2c_I2C1)
    {
        //--- Send
        I2C1->CR1 |= I2C_CR1_START; // Formirate start
        uint8_t u8_waitingTime = 0;
        while(!(I2C1->SR1 & I2C_SR1_SB))
        {
            u8_waitingTime++;
            delay_us(1);
            if(u8_waitingTime > i2c_Error_maxTime)
                return i2c_Error_NotResponse_SB;
        } // while(!(I2C1->SR1 & I2C_SR1_SB))
        (void) I2C1->SR1;
        
        I2C1->DR = (address & i2c_Mask_WriteAnd); // Send device address - write
        u8_waitingTime = 0;
        while(!(I2C1->SR1 & I2C_SR1_ADDR))
        {
            u8_waitingTime++;
            delay_us(1);
            if(u8_waitingTime > i2c_Error_maxTime)
                return i2c_Error_NotResponse_ADDR;
        } // while(!(I2C1->SR1 & I2C_SR1_ADDR))
        (void) I2C1->SR1;
        (void) I2C1->SR2;
        
        I2C1->DR = reg_add; // Send register address
        u8_waitingTime = 0;
        while(!(I2C1->SR1 & I2C_SR1_TXE))
        {
            u8_waitingTime++;
            delay_us(1);
            if(u8_waitingTime > i2c_Error_maxTime)
                return i2c_Error_NotResponse_TXE;
        } // while(!(I2C1->SR1 & I2C_SR1_TXE))
        
        //--- Receive
        I2C1->CR1 |= I2C_CR1_START; // Formirate start
        u8_waitingTime = 0;
        while(!(I2C1->SR1 & I2C_SR1_SB))
        {
            u8_waitingTime++;
            delay_us(1);
            if(u8_waitingTime > i2c_Error_maxTime)
                return i2c_Error_NotResponse_SB;
        } // while(!(I2C1->SR1 & I2C_SR1_SB))
        (void) I2C1->SR1;
        
        I2C1->DR = (address | i2c_Mask_ReadOr); // Send device address - read
        u8_waitingTime = 0;
        while(!(I2C1->SR1 & I2C_SR1_ADDR))
        {
            u8_waitingTime++;
            delay_us(1);
            if(u8_waitingTime > i2c_Error_maxTime)
                return i2c_Error_NotResponse_ADDR;
        } // while(!(I2C1->SR1 & I2C_SR1_ADDR))
        (void) I2C1->SR1;
        (void) I2C1->SR2;
        
        
        I2C1->CR1 &= ~I2C_CR1_ACK; // Formirate NACK
        
        u8_waitingTime = 0;
        while(!(I2C1->SR1 & I2C_SR1_RXNE)) // Waiting receive comlete
        {
            u8_waitingTime++;
            delay_us(1);
            if(u8_waitingTime > i2c_Error_maxTime)
                return i2c_Error_NotResponse_RXNE;
        } // while(!(I2C1->SR1 & I2C_SR1_RXNE))
        u8_temp = I2C1->DR; // Read data
        
        I2C1->CR1 |= I2C_CR1_STOP;
    } // if(i2c == i2c_I2C1)
    else if(i2c == i2c_I2C2)
    {
        //--- Send
        I2C2->CR1 |= I2C_CR1_START; // Formirate start
        uint8_t u8_waitingTime = 0;
        while(!(I2C2->SR1 & I2C_SR1_SB))
        {
            u8_waitingTime++;
            delay_us(1);
            if(u8_waitingTime > i2c_Error_maxTime)
                return i2c_Error_NotResponse_SB;
        } // while(!(I2C2->SR1 & I2C_SR1_SB))
        (void) I2C2->SR1;
        
        I2C2->DR = (address & i2c_Mask_WriteAnd); // Send device address - write
        u8_waitingTime = 0;
        while(!(I2C2->SR1 & I2C_SR1_ADDR))
        {
            u8_waitingTime++;
            delay_us(1);
            if(u8_waitingTime > i2c_Error_maxTime)
                return i2c_Error_NotResponse_ADDR;
        } // while(!(I2C2->SR1 & I2C_SR1_ADDR))
        (void) I2C2->SR1;
        (void) I2C2->SR2;
        
        I2C2->DR = reg_add; // Send register address
        u8_waitingTime = 0;
        while(!(I2C2->SR1 & I2C_SR1_TXE))
        {
            u8_waitingTime++;
            delay_us(1);
            if(u8_waitingTime > i2c_Error_maxTime)
                return i2c_Error_NotResponse_TXE;
        } // while(!(I2C2->SR1 & I2C_SR1_TXE))
        
        //--- Receive
        I2C2->CR1 |= I2C_CR1_START; // Formirate start
        u8_waitingTime = 0;
        while(!(I2C2->SR1 & I2C_SR1_SB))
        {
            u8_waitingTime++;
            delay_us(1);
            if(u8_waitingTime > i2c_Error_maxTime)
                return i2c_Error_NotResponse_SB;
        } // while(!(I2C2->SR1 & I2C_SR1_SB))
        (void) I2C2->SR1;
        
        I2C2->DR = (address | i2c_Mask_ReadOr); // Send device address - read
        u8_waitingTime = 0;
        while(!(I2C2->SR1 & I2C_SR1_ADDR))
        {
            u8_waitingTime++;
            delay_us(1);
            if(u8_waitingTime > i2c_Error_maxTime)
                return i2c_Error_NotResponse_ADDR;
        } // while(!(I2C2->SR1 & I2C_SR1_ADDR))
        (void) I2C2->SR1;
        (void) I2C2->SR2;
        
        
        I2C2->CR1 &= ~I2C_CR1_ACK; // Formirate NACK
        
        u8_waitingTime = 0;
        while(!(I2C2->SR1 & I2C_SR1_RXNE)) // Waiting receive comlete
        {
            u8_waitingTime++;
            delay_us(1);
            if(u8_waitingTime > i2c_Error_maxTime)
                return i2c_Error_NotResponse_RXNE;
        } // while(!(I2C2->SR1 & I2C_SR1_RXNE))
        u8_temp = I2C2->DR; // Read data
        
        I2C2->CR1 |= I2C_CR1_STOP;
    } // else if(i2c == i2c_I2C2)
    else
        return i2c_Error_Wrong_I2C;
    
    *data = u8_temp; // Save received byte in data

    return i2c_Error_NoError;
} // i2c_ReceiveByte

uint8_t i2c_ReceiveBuffer(uint8_t i2c, uint8_t address, uint8_t reg_add, uint8_t* buffer, uint8_t length) // Receive buffer from I2C
{
    if(i2c == i2c_I2C1)
    {
        //--- Send
        I2C1->CR1 |= I2C_CR1_START; // Formirate start
        uint8_t u8_waitingTime = 0;
        while(!(I2C1->SR1 & I2C_SR1_SB))
        {
            u8_waitingTime++;
            delay_us(1);
            if(u8_waitingTime > i2c_Error_maxTime)
                return i2c_Error_NotResponse_SB;
        } // while(!(I2C1->SR1 & I2C_SR1_SB))
        (void) I2C1->SR1;
        
        I2C1->DR = (address & i2c_Mask_WriteAnd); // Send device address - write
        u8_waitingTime = 0;
        while(!(I2C1->SR1 & I2C_SR1_ADDR))
        {
            u8_waitingTime++;
            delay_us(1);
            if(u8_waitingTime > i2c_Error_maxTime)
                return i2c_Error_NotResponse_ADDR;
        } // while(!(I2C1->SR1 & I2C_SR1_ADDR))
        (void) I2C1->SR1;
        (void) I2C1->SR2;
        
        I2C1->DR = reg_add; // Send register address
        u8_waitingTime = 0;
        while(!(I2C1->SR1 & I2C_SR1_TXE))
        {
            u8_waitingTime++;
            delay_us(1);
            if(u8_waitingTime > i2c_Error_maxTime)
                return i2c_Error_NotResponse_TXE;
        } // while(!(I2C1->SR1 & I2C_SR1_TXE))
        
        //--- Receive
        I2C1->CR1 |= I2C_CR1_START; // Formirate start
        u8_waitingTime = 0;
        while(!(I2C1->SR1 & I2C_SR1_SB))
        {
            u8_waitingTime++;
            delay_us(1);
            if(u8_waitingTime > i2c_Error_maxTime)
                return i2c_Error_NotResponse_SB;
        } // while(!(I2C1->SR1 & I2C_SR1_SB))
        (void) I2C1->SR1;
        
        I2C1->DR = (address | i2c_Mask_ReadOr); // Send device address - read
        u8_waitingTime = 0;
        while(!(I2C1->SR1 & I2C_SR1_ADDR))
        {
            u8_waitingTime++;
            delay_us(1);
            if(u8_waitingTime > i2c_Error_maxTime)
                return i2c_Error_NotResponse_ADDR;
        } // while(!(I2C1->SR1 & I2C_SR1_ADDR))
        (void) I2C1->SR1;
        (void) I2C1->SR2;
        
        
        I2C1->CR1 |= I2C_CR1_ACK; // Formirate ACK
        
        for(uint8_t it = 0; it < length; it++)
        {
            u8_waitingTime = 0;
            while(!(I2C1->SR1 & I2C_SR1_RXNE)) // Waiting receive complete
            {
                u8_waitingTime++;
                delay_us(1);
                if(u8_waitingTime > i2c_Error_maxTime)
                    return i2c_Error_NotResponse_RXNE;
            } // while(!(I2C1->SR1 & I2C_SR1_RXNE))
            buffer[it] = I2C1->DR; // Read data
        } // for(uint8_t it = 0; it < length; it++)
        
        I2C1->CR1 &= ~I2C_CR1_ACK; // Formirate NACK
        I2C1->CR1 |= I2C_CR1_STOP;
    } // if(i2c == i2c_I2C1)
    else if(i2c == i2c_I2C2)
    {
        //--- Send
        I2C2->CR1 |= I2C_CR1_START; // Formirate start
        uint8_t u8_waitingTime = 0;
        while(!(I2C2->SR1 & I2C_SR1_SB))
        {
            u8_waitingTime++;
            delay_us(1);
            if(u8_waitingTime > i2c_Error_maxTime)
                return i2c_Error_NotResponse_SB;
        } // while(!(I2C2->SR1 & I2C_SR1_SB))
        (void) I2C2->SR1;
        
        I2C2->DR = (address & i2c_Mask_WriteAnd); // Send device address - write
        u8_waitingTime = 0;
        while(!(I2C2->SR1 & I2C_SR1_ADDR))
        {
            u8_waitingTime++;
            delay_us(1);
            if(u8_waitingTime > i2c_Error_maxTime)
                return i2c_Error_NotResponse_ADDR;
        } // while(!(I2C2->SR1 & I2C_SR1_ADDR))
        (void) I2C2->SR1;
        (void) I2C2->SR2;
        
        I2C2->DR = reg_add; // Send register address
        u8_waitingTime = 0;
        while(!(I2C2->SR1 & I2C_SR1_TXE))
        {
            u8_waitingTime++;
            delay_us(1);
            if(u8_waitingTime > i2c_Error_maxTime)
                return i2c_Error_NotResponse_TXE;
        } // while(!(I2C2->SR1 & I2C_SR1_TXE))
        
        //--- Receive
        I2C2->CR1 |= I2C_CR1_START; // Formirate start
        u8_waitingTime = 0;
        while(!(I2C2->SR1 & I2C_SR1_SB))
        {
            u8_waitingTime++;
            delay_us(1);
            if(u8_waitingTime > i2c_Error_maxTime)
                return i2c_Error_NotResponse_SB;
        } // while(!(I2C2->SR1 & I2C_SR1_SB))
        (void) I2C2->SR1;
        
        I2C2->DR = (address | i2c_Mask_ReadOr); // Send device address - read
        u8_waitingTime = 0;
        while(!(I2C2->SR1 & I2C_SR1_ADDR))
        {
            u8_waitingTime++;
            delay_us(1);
            if(u8_waitingTime > i2c_Error_maxTime)
                return i2c_Error_NotResponse_ADDR;
        } // while(!(I2C2->SR1 & I2C_SR1_ADDR))
        (void) I2C2->SR1;
        (void) I2C2->SR2;
        
        
        I2C2->CR1 |= I2C_CR1_ACK; // Formirate ACK
        
        for(uint8_t it = 0; it < length; it++)
        {
            u8_waitingTime = 0;
            while(!(I2C2->SR1 & I2C_SR1_RXNE)) // Waiting receive complete
            {
                u8_waitingTime++;
                delay_us(1);
                if(u8_waitingTime > i2c_Error_maxTime)
                    return i2c_Error_NotResponse_RXNE;
            } // while(!(I2C2->SR1 & I2C_SR1_RXNE))
            buffer[it] = I2C2->DR; // Read data
        } // for(uint8_t it = 0; it < length; it++)
        
        I2C2->CR1 &= ~I2C_CR1_ACK; // Formirate NACK
        I2C2->CR1 |= I2C_CR1_STOP;
    } // else if(i2c == i2c_I2C2)
    else
        return i2c_Error_Wrong_I2C;

    return i2c_Error_NoError;
} // i2c_Receivebuffer
