/*
  Author:      Ehab Roshdy
  Version:     0.1
  Date:        21/8/2023
  Description: LCD driver configuration file

  This code serves as the configuration file for an LCD driver. It defines various settings
  and hardware connections necessary for the proper functioning of the LCD module. The
  configuration includes data mode (4-bit or 8-bit), the assignment of data pins to specific
  ports and pins, and the control pins (RS, RW, EN) and their corresponding ports.

  You can customize these settings to match the actual hardware connections and requirements
  of your LCD module. By modifying this configuration, you can adapt the LCD driver to work
  with different microcontroller pin assignments and communication modes.
*/
#ifndef _LCD_CONFIG_H
#define _LCD_CONFIG_H

#include "LIB/types.h"

// Specify the data mode (4-bit or 8-bit)
#define LCD_DATA_MODE       MODE_4_BIT

// Define the assignment of data pins to ports and pins
static uint8 dataPin0Pin = PIN5;
static uint8 dataPin0Port = PORTE;

static uint8 dataPin1Pin = PIN4;
static uint8 dataPin1Port = PORTE;

static uint8 dataPin2Pin = PIN1;
static uint8 dataPin2Port = PORTB;

static uint8 dataPin3Pin = PIN2;
static uint8 dataPin3Port = PORTD;

// Define control pins (RS, RW, EN) and their corresponding ports
static uint8 rsPin = PIN3;
static uint8 rsPort = PORTA;

static uint8 rwPin = PIN5;
static uint8 rwPort = PORTA;

static uint8 enPin = PIN6;
static uint8 enPort = PORTA;

#endif
