/**
 * @file LCD_Interface.h
 *
 * @brief LCD Driver Interface Header
 *
 * This header file provides the interface for the LCD driver, including command codes,
 * function prototypes, and definitions for rows and columns.
 *
 * @date 21/8/2023
 * @version 0.1
 * @author Ehab Roshdy
 */

#pragma once

/**
 * @brief Command code to clear the display.
 */
#define CLEAR_DISPLAY       0X01

/**
 * @brief Command code to return to the home position.
 */
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

/**
 * @brief Initializes the LCD module with specified configuration.
 *
 * Initializes the LCD module with data pins, RS pin, and EN pin configuration.
 */
void LcdInit();

/**
 * @brief Sends a command to configure the LCD module.
 *
 * Sends a command to configure the behavior of the LCD module.
 *
 * @param c Command to be sent to the LCD module.
 */
void LcdSendCommand(char c);

/**
 * @brief Sends character data to be displayed on the LCD screen.
 *
 * Sends character data to be displayed on the LCD screen.
 *
 * @param c Character data to be sent to the LCD module.
 */
void LcdSendData(char c);

/**
 * @brief Sends a sequence of characters (a string) to be displayed on the LCD screen.
 *
 * Sends a sequence of characters (a string) to be displayed on the LCD screen.
 *
 * @param str Pointer to a char array (string) containing the data to be sent.
 */
void LcdSendString(char* str);

/**
 * @brief Sets the cursor position on the LCD screen.
 *
 * Sets the cursor position to the specified row and column on the LCD screen.
 *
 * @param row Row number (0 or 1) where the cursor should move.
 * @param col Column number (0 to 15) where the cursor should move.
 */
void LcdGoTo(unsigned char row, unsigned char col);

/**
 * @brief Saves a custom character pattern to the LCD.
 *
 * Saves a custom character pattern to the LCD with a specified ID.
 *
 * @param c Array containing the custom character pattern (8 bytes).
 * @param ID ID (0 to 7) for the custom character.
 */
void LcdSaveCustomChar(unsigned char c[8], unsigned char ID);

/**
 * @brief Sends an integer value to the LCD for display.
 *
 * Converts an integer value to a string and sends it to the LCD for display.
 *
 * @param num Integer value to be displayed on the LCD.
 */
void LCDSendInt(int num);
