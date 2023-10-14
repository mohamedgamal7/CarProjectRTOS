/**
 * @file LCD_Config.h
 *
 * @brief LCD Driver Configuration Header
 *
 * This header file provides the configuration for the LCD driver.
 *
 * @date 21/8/2023
 * @author Ehab Roshdy
 */

#ifndef _LCD_CONFIG_H
#define _LCD_CONFIG_H

#include "LIB/types.h"

/**
 * @brief LCD data mode (4-bit or 8-bit).
 */
#define LCD_DATA_MODE       MODE_4_BIT

/**
 * @brief Configuration for data pin 0.
 */
static uint8 dataPin0Pin = PIN5;
static uint8 dataPin0Port = PORTE;

/**
 * @brief Configuration for data pin 1.
 */
static uint8 dataPin1Pin = PIN4;
static uint8 dataPin1Port = PORTE;

/**
 * @brief Configuration for data pin 2.
 */
static uint8 dataPin2Pin = PIN1;
static uint8 dataPin2Port = PORTB;

/**
 * @brief Configuration for data pin 3.
 */
static uint8 dataPin3Pin = PIN2;
static uint8 dataPin3Port = PORTD;

/**
 * @brief Configuration for RS (Register Select) pin.
 */
static uint8 rsPin = PIN3;
static uint8 rsPort = PORTA;

/**
 * @brief Configuration for RW (Read/Write) pin.
 */
static uint8 rwPin = PIN5;
static uint8 rwPort = PORTA;

/**
 * @brief Configuration for EN (Enable) pin.
 */
static uint8 enPin = PIN6;
static uint8 enPort = PORTA;

#endif /* _LCD_CONFIG_H */
