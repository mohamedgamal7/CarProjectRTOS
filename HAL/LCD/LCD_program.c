/*
  Author:      Ehab Roshdy
  Version:     0.1
  Date:        21/8/2023
  Description: LCD driver program file

  This program file contains the implementation of functions for LCD interfacing and
  controlling. The functions allow you to initialize the LCD module, send data and
  commands, display strings, position the cursor, and save custom characters on the LCD.

  Please note that these functions should be used to interact with the LCD module.

  To use this module, include the necessary LCD header files and call the functions
  as needed.

  Dependencies:
  - LCD_interface.h: Header file containing function prototypes for user interaction.
  - LCD_private.h: Private header file with static helper functions and configuration.
  - LCD_config.h: Configuration file for specifying the data mode and pin/port details.
  - DIO.h: Header for Digital I/O (DIO) functions.
  - Delay.h: Header for time delay functions.
*/

#include "./HAL/LCD/LCD_interface.h"
#include "./HAL/LCD/LCD_private.h"
#include "./HAL/LCD/LCD_config.h"

#include "MCAL/DIO/DIO.h"
#include "LIB/Delay.h"
//////////////////////////////////////////////////////////////////////////////////////////////

// Initialize the LCD module
void LcdInit()
{
    // Extract data pin/port information from the configuration file
    dataPorts[0] = dataPin0Port;
    dataPorts[1] = dataPin1Port;
    dataPorts[2] = dataPin2Port;
    dataPorts[3] = dataPin3Port;
    
    dataPins[0] = dataPin0Pin;
    dataPins[1] = dataPin1Pin;
    dataPins[2] = dataPin2Pin;
    dataPins[3] = dataPin3Pin;

    // Initialize control pins (RS and RW)
    DIO_Write(rwPort, 1 << rwPin, 0x00);

    // Initialize the LCD module
    lcdSetMode();

    // Send commands to configure the LCD
    LcdSendCommand(LCD_DATA_MODE | DISPLAY_2_LINE | FONT_5X7);
    LcdSendCommand(CURSOR_AUTO_SHIFT_RIGHT);
    LcdSendCommand(DISPLAY_ON);
    LcdSendCommand(CLEAR_DISPLAY);
    delay_ms(2);
}

// Send a data byte to the LCD
void LcdSendData(char c)
{
    // Set RS to indicate data
    DIO_Write(rsPort, 1 << rsPin, 1 << rsPin);

    // Send the higher 4 bits of the data
    int i;
    for (i = 0; i < 4; ++i)
    {
        DIO_Write(dataPorts[i], 1 << dataPins[i], ((c >> (4 + i)) & 1) << dataPins[i]);
    }
    sendEnablePulse();

    // Send the lower 4 bits of the data
    for (i = 0; i < 4; ++i)
    {
        DIO_Write(dataPorts[i], 1 << dataPins[i], ((c >> i) & 1) << dataPins[i]);
    }
    sendEnablePulse();
}

// Send a command byte to the LCD
void LcdSendCommand(char c)
{
    // Clear RS to indicate a command
    DIO_Write(rsPort, 1 << rsPin, 0 << rsPin);

    int i;
    for (i = 0; i < 4; ++i)
    {
        DIO_Write(dataPorts[i], 1 << dataPins[i], ((c >> (4 + i)) & 1) << dataPins[i]);
    }
    sendEnablePulse();

    for (i = 0; i < 4; ++i)
    {
        DIO_Write(dataPorts[i], 1 << dataPins[i], ((c >> i) & 1) << dataPins[i]);
    }
    sendEnablePulse();
}

// Send a string of characters to the LCD
void LcdSendString(char* str)
{
    int i = 0;
    for (i = 0; str[i] && (i < 16); ++i)
    {
        LcdSendData(str[i]);
    }
}

// Function to send the enable pulse to the LCD
static void sendEnablePulse()
{
    DIO_Write(enPort, 1 << enPin, 1 << enPin); // Set EN to high
    delay_us(50); // Delay for stability
    DIO_Write(enPort, 1 << enPin, 0 << enPin); // Set EN to low
    delay_us(50); // Delay for stability
}

// Position the cursor to a specified row and column
void LcdGoTo(unsigned char row, unsigned char col)
{
    LcdSendCommand(0x80 + (row * 0x40) + (col));
}

// Save a custom character to the LCD
void LcdSaveCustomChar(unsigned char c[8], uint8 ID)
{
    LcdSendCommand(0x40 + ID * 8);

    int i = 0;
    for (i = 0; i < 8; i++)
    {
        LcdSendData(c[i]);
    }

    LcdGoTo(ROW1, COL1);
}

// Set the LCD data mode (4-bit or 8-bit) based on the configuration
static void lcdSetMode()
{
    if (LCD_DATA_MODE == MODE_4_BIT)
    {
        // Set up the 4-bit data communication
        DIO_Write(dataPorts[0], 1 << dataPins[0], 0); // Set 4-bit mode
        DIO_Write(dataPorts[1], 1 << dataPins[1], 0xFF); // Set 4-bit mode
        DIO_Write(dataPorts[2], 1 << dataPins[2], 0); // Set 4-bit mode
        DIO_Write(dataPorts[3], 1 << dataPins[3], 0); // Set 4-bit mode
        sendEnablePulse();
    }
    else
    {
        // Add code for 8-bit mode if needed
    }
}

// Function to send an integer to the LCD
void LCDSendInt(int32 num)
{
    int j = 0, i = 0;
    char str[32];

    // Handle negative numbers
    if (num < 0)
    {
        LcdSendData('-');
        num *= -1;
    }

    // Extract digits from the number
    while (num != 0)
    {
        str[i] = num % 10;
        num = num / 10;
        i++;
    }

    // Send each digit to the LCD
    for (j = i - 1; j >= 0; j--)
        LcdSendData('0' + str[j]);
}
