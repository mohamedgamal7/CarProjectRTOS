/*
  Author:      Ehab Roshdy                                                                      
  Version:     0.1                                                                       
  Date:        21/8/2023                                                                             
  Description: LCD driver interface file      
*/

#pragma once

#define CLEAR_DISPLAY       0X01

#define RETURN_HOME         0X02

/* Function Set */
#define MODE_4_BIT          0X20
#define MODE_8_BIT          0X30
#define DISPLAY_1_LINE      0X20
#define DISPLAY_2_LINE      0X28
#define FONT_5X7            0X20
#define FONT_5X10           0X24

/* Entry mode set */
#define CURSOR_AUTO_SHIFT_RIGHT \
                            0X06
#define DIPLAY_AUTO_SHIFT   0X05

/* Display/Cursor/Blink on/off control */
#define DISPLAY_ON           0X0C
#define CURSOR_ON           0X0A
#define BLINK_ON            0X09

/* Display/Cursor Switch with no data entry */
#define SHIFT_CURSOR_POSITION_LEFT \
                            0X10
#define SHIFT_CURSOR_POSITION_RIGHT \
                            0X14
#define SHIFT_DISPLAY_LEFT  0X18
#define SHIFT_DISPLAY_RIGHT 0X1C




/* Rows for goTo function */
#define ROW1                0x00
#define ROW2                0x01

/* Cols for goTo function */
#define COL1                0x00
#define COL2                0x01
#define COL3                0x02
#define COL4                0x03
#define COL5                0x04
#define COL6                0x05
#define COL7                0x06
#define COL8                0x07
#define COL9                0x08
#define COL10               0x09
#define COL11               0x0A
#define COL12               0x0B
#define COL13               0x0C
#define COL14               0x0D
#define COL15               0x0E
#define COL16               0x0F


// Function prototype for initializing the LCD module
// Initializes the LCD module with specified configuration.
// Arguments:
//   dataPort: Data port for the LCD module.
//   dataPins: Data pins connected to the LCD module.
//   rsPort: Port where the Register Select (RS) pin is connected.
//   rsPin: Specific pin number of the RS pin.
//   enPort: Port where the Enable (EN) pin is connected.
//   enPin: Specific pin number of the EN pin.
void LcdInit();

// Function prototype for sending a command to the LCD module
// Sends a command to configure the LCD module.
// Argument:
//   c: Command to be sent to the LCD module.
void LcdSendCommand(char c);

// Function prototype for sending data to the LCD module
// Sends character data to be displayed on the LCD screen.
// Argument:
//   c: Character data to be sent to the LCD module.
void LcdSendData(char c);

// Function prototype for sending a string to the LCD module
// Sends a sequence of characters (a string) to be displayed on the LCD screen.
// Argument:
//   str: Pointer to a char array (string) containing the data to be sent.
void LcdSendString(char* str);


void LcdGoTo(unsigned char row, unsigned char col);

void LcdSaveCustomChar(unsigned char c[8], unsigned char ID);

void LCDSendInt(int num);
