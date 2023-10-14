/**
 * @file display.h
 *
 * @brief Display Module Interface
 *
 * This module provides an interface for functions related to displaying information on an LCD screen.
 * It includes functions for initializing the display with a constant string and continuously updating and displaying dynamic data.
 *
 * @author Mohamed Gamal
 * @date 05/10/2023
 */

#ifndef DISPLAY_H_
#define DISPLAY_H_

/**
 * @brief Initialize the LCD display with a constant string.
 *
 * This function initializes the LCD display with a constant string that includes placeholders for dynamic data.
 * It sets up the initial display structure.
 */
void lcd_display_const_string(void);

/**
 * @brief Continuously update and display dynamic data on the LCD.
 *
 * This function continuously updates and displays dynamic data on the LCD screen.
 * It retrieves data from various sources and displays it on the screen in real-time.
 */
void lcd_display(void);

#endif /* DISPLAY_H_ */
