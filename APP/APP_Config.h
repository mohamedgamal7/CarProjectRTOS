/**
 * @file app.h
 *
 * @brief Application Configuration Header
 *
 * This header file defines configuration parameters and enumerations for the application.
 *
 * @date 05/10/2023
 * @author Mohamed Gamal - Ehab Roushdy
 */

#ifndef _APP_H
#define _APP_H

/**
 * @brief Period (in milliseconds) for ultrasonic sensor readings.
 */
#define ULTRASONIC_PERIOD       60

/**
 * @brief Period (in milliseconds) for LCD display updates.
 */
#define LCD_PERIOD              200

/**
 * @brief Period (in milliseconds) for button checks.
 */
#define BUTTON_CHECK_PERIOD     80

/**
 * @brief Period (in milliseconds) for LDR (Light Dependent Resistor) module.
 */
#define LDR_PERIOD              100

/**
 * @brief Period (in milliseconds) for temperature sensor readings.
 */
#define TEMP_PERIOD             150

/**
 * @brief Enumeration representing the car's current state.
 */
typedef enum
{
    free_running,       /**< Car is freely running. */
    blocked_reverse,   /**< Car is blocked and reversing. */
    blocked_turning     /**< Car is blocked and turning. */
} car_state;

#endif /* _APP_H */
