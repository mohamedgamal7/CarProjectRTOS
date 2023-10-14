
/*
  Author:      Ehab Roshdy                                                                      
  Version:     0.1                                                                       
  Date:        21/8/2023                                                                             
  Description: LCD driver configuration file                                 
*/

#ifndef _LCD_CONFIG_H
#define _LCD_CONFIG_H

#include "LIB/types.h"
//#include "LCD_interface.h"

#define LCD_DATA_MODE       MODE_4_BIT

static uint8 dataPin0Pin = PIN5;
static uint8 dataPin0Port = PORTE;

static uint8 dataPin1Pin = PIN4;
static uint8 dataPin1Port = PORTE;

static uint8 dataPin2Pin = PIN1;
static uint8 dataPin2Port = PORTB;

static uint8 dataPin3Pin = PIN2;
static uint8 dataPin3Port = PORTD;

static uint8 rsPin = PIN3;
static uint8 rsPort = PORTA;

static uint8 rwPin = PIN5;
static uint8 rwPort = PORTA;

static uint8 enPin = PIN6;
static uint8 enPort = PORTA;




#endif

