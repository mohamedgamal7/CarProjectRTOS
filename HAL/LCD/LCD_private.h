/**
 * @file LCD_Private.h
 *
 * @brief LCD Driver Private header
 *
 * This source file contains the private implementation of the LCD driver,
 * including static helper functions and data declarations.
 *
 * @date 21/8/2023
 * @version 0.1
 * @author Ehab Roshdy
 */

/* Declaration of static helper functions */

/**
 * @brief Sends the enable pulse to the LCD.
 *
 * This function sends the enable pulse (EN signal) to the LCD to latch data.
 */
static void sendEnablePulse();

/**
 * @brief Configures the LCD data mode (4-bit or 8-bit).
 *
 * This function configures the LCD data mode based on the selected mode (4-bit or 8-bit).
 */
static void lcdSetMode();

/**
 * @brief Array to store data port configurations.
 */
static unsigned char dataPorts[4];

/**
 * @brief Array to store data pin configurations.
 */
static unsigned char dataPins[4];
