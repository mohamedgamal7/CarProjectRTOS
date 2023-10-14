/**
 * @file LCD_Program.c
 *
 * @brief LCD Driver Program Implementation
 *
 * This source file contains the program implementation of the LCD driver,
 * including functions to initialize the LCD module, send data and commands,
 * send strings, set cursor position, and save custom characters.
 *
 * @date 21/8/2023
 * @version 0.1
 * @author Ehab Roshdy
 */

#include "./HAL/LCD/LCD_interface.h"
#include "./HAL/LCD/LCD_private.h"
#include "./HAL/LCD/LCD_config.h"

#include "MCAL/DIO/DIO.h"
#include "LIB/Delay.h"

/* Initialize the LCD module */
void LcdInit()
{
    dataPorts[0] = dataPin0Port;
    dataPorts[1] = dataPin1Port;
    dataPorts[2] = dataPin2Port;
    dataPorts[3] = dataPin3Port;
    
    dataPins[0] = dataPin0Pin;
    dataPins[1] = dataPin1Pin;
    dataPins[2] = dataPin2Pin;
    dataPins[3] = dataPin3Pin;
    
    DIO_Write(rwPort, 1<<rwPin, 0x00);

    /* Initialize the LCD module */
    lcdSetMode();

    /* Send commands to configure the LCD */
    LcdSendCommand(LCD_DATA_MODE|DISPLAY_2_LINE|FONT_5X7); /* Set display mode to 2 lines, 4-bit, 5x7 dot */
    LcdSendCommand(CURSOR_AUTO_SHIFT_RIGHT); /* Set cursor increment mode, no display shift */
    LcdSendCommand(DISPLAY_ON); /* Turn on display, cursor, and blinking */
    LcdSendCommand(CLEAR_DISPLAY); /* Clear display */
    delay_ms(2);
}

/* Send a data byte to the LCD */
void LcdSendData(char c)
{
    DIO_Write(rsPort, (1 << rsPin), (1 << rsPin)); /* Set RS to indicate data */

    /* Send the higher 4 bits of the data */
    int i;
    for (i = 0; i < 4; ++i)
    {
        DIO_Write(dataPorts[i], (1 << dataPins[i]), ((c >> (4+i))&1)<<dataPins[i]);
    }
    sendEnablePulse();

    /* Send the lower 4 bits of the data */
    for (i = 0; i < 4; ++i)
    {
        DIO_Write(dataPorts[i], (1 << dataPins[i]), ((c>>i) & 1)<<dataPins[i]);
    }
    sendEnablePulse();
}

/* Send a command byte to the LCD */
void LcdSendCommand(char c)
{
    DIO_Write(rsPort, (1<<rsPin), (0<<rsPin)); /* Clear RS to indicate command */

    int i;
    for (i = 0; i < 4; ++i)
    {
        DIO_Write(dataPorts[i], (1 << dataPins[i]), ((c >> (4+i))&1)<<dataPins[i]);
    }
    sendEnablePulse();

    for (i = 0; i < 4; ++i)
    {
        DIO_Write(dataPorts[i], (1 << dataPins[i]), ((c>>i) & 1)<<dataPins[i]);
    }
    sendEnablePulse();
}

/* Send a string of characters to the LCD */
void LcdSendString(char* str)
{
    int i = 0;
    for (i = 0; str[i] && (i < 16); ++i)
    {
        LcdSendData(str[i]);
    }
}

/* Function to send the enable pulse to the LCD */
static void sendEnablePulse()
{
    DIO_Write(enPort, 1<<enPin, (1<<enPin)); /* Set EN to high */
    delay_us(50); /* Delay for stability */
    DIO_Write(enPort, 1<<enPin, (0<<enPin)); /* Set EN to low */
    delay_us(50); /* Delay for stability */
}

void LcdGoTo(unsigned char row, unsigned char col)
{
    LcdSendCommand(0x80 + (row * 0x40) + (col));
}

void LcdSaveCustomChar(unsigned char c[8], uint8 ID)
{
    LcdSendCommand(0x40 + ID*8);

    int i = 0;
    for(i = 0; i < 8; i++)
    {
        LcdSendData(c[i]);
    }

    LcdGoTo(ROW1, COL1);
}

static void lcdSetMode()
{
    if (LCD_DATA_MODE == MODE_4_BIT)
    {
        /* Set up the 4-bit data communication */
        DIO_Write(dataPorts[0], 1<<dataPins[0], 0); /* Set 4-bit mode */
        DIO_Write(dataPorts[1], 1<<dataPins[1], 0xFF); /* Set 4-bit mode */
        DIO_Write(dataPorts[2], 1<<dataPins[2], 0); /* Set 4-bit mode */
        DIO_Write(dataPorts[3], 1<<dataPins[3], 0); /* Set 4-bit mode */
        sendEnablePulse();
    }
    else
    {
        /* Set up the 8-bit data communication */
    }
}

void LCDSendInt(int32 num)
{
    int j = 0, i = 0;
    char str[32];
    if(num < 0)
    {
        LcdSendData('-');
        num *= -1;
    }
    while(num != 0)
    {
        str[i] = num % 10;
        num = num/10;
        i++;
    }
    for(j = i-1; j >=0 ; j--)
        LcdSendData('0' + str[j]);
}
