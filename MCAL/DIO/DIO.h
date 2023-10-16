/**
 * @file DIO.h
 * @brief Digital Input/Output (DIO) configuration and control functions.
 *
 * This file provides functions and definitions to configure and control the
 * Digital Input/Output (DIO) pins on a Tiva-C microcontroller.
 */

#ifndef DIO_H_
#define DIO_H_

#include "LIB/tm4c123gh6pm.h"
#include "LIB/BIT_MATH.h"
#include "LIB/types.h"

/* #DEFINE */

#define PORTS_BASE_ADDRESS  0x40004000

#define PORT_OFFSET(CpyPort_ID)  (((CpyPort_ID % 4) << 12) + (CpyPort_ID / 4) * (2 << 16))
#define GPIO_PORT_ADDRESS(REG_OFFSET)   (PORTS_BASE_ADDRESS + PORT_OFFSET(CpyPort_ID) + REG_OFFSET)

#define GPIOLOCK_OFFSET     0x520
#define GPIOCR_OFFSET       0x524
#define GPIODIR_OFFSET      0x400
#define GPIOPUR_OFFSET      0x510
#define GPIODEN_OFFSET      0x51c
#define GPIODATA_OFFSET     0x3fc
#define NO_OFFSET           0x000

/* Pin masks */

#define P0          0x01U
#define P1          0x02U
#define P2          0x04U
#define P3          0x08U
#define P4          0x10U
#define P5          0x20U
#define P6          0x40U
#define P7          0x80U
#define NO_PINS     0x00U
#define ALL_PINS    0xFFU
#define HIGH_NIBBLE 0XF0U
#define LOW_NIBBLE  0X0FU
#define TIMER_MUX   0x07

#define PORTA_CC 0x01   // PORT A CLOCK CONTROL FOR SYSCTL_RCGCGPIO_R
#define PORTB_CC 0x02   // PORT B CLOCK CONTROL FOR SYSCTL_RCGCGPIO_R
#define PORTC_CC 0x04   // PORT C CLOCK CONTROL FOR SYSCTL_RCGCGPIO_R
#define PORTD_CC 0x08   // PORT D CLOCK CONTROL FOR SYSCTL_RCGCGPIO_R
#define PORTE_CC 0x10   // PORT E CLOCK CONTROL FOR SYSCTL_RCGCGPIO_R
#define PORTF_CC 0x20   // PORT F CLOCK CONTROL FOR SYSCTL_RCGCGPIO_R
#define PORTS_CC 0x3F   // ALL PORT CLOCK CONTROL FOR SYSCTL_RCGCGPIO_R
#define SET 1
#define CLEAR 0

/* EXTERN */

extern PinConfig *PortStruct_ptr[Port_Num];
extern char Ports_Operating[Port_Num];
extern void PORT_CONFIG(void);

/* FUNCTION PROTOTYPES */

/**
 * @brief Configure which Ports will operate.
 */
void PORTS_Operation(void);

/**
 * @brief Initialize a specific port with given configuration settings.
 *
 * @param Port The port to configure.
 * @param StructPtr A pointer to the PinConfig structure containing port configuration.
 */
void PORT_Init(Port_Select Port, PinConfig *StructPtr);

/**
 * @brief Initialize GPIO interrupt for a specific port and pin.
 *
 * @param Port The port to configure.
 * @param StructPtr A pointer to the PinConfig structure containing port configuration.
 */
void GPIO_InterruptInit(Port_Select Port, PinConfig *StructPtr);

/* WRITE OPERATIONS */

/**
 * @brief Set a specific pin's alternate function mode.
 *
 * @param Port The port in which the pin is located.
 * @param pin The pin to set the alternate function mode for.
 * @param pinmux The alternate function mode to set.
 */
void alt_Function(uint8 Port, uint8 pin, uint8 pinmux);

/**
 * @brief Set a pin to analog mode.
 *
 * @param Port The port in which the pin is located.
 * @param Pins The pins to set to analog mode.
 */
void analog_Mode(Port_Select Port, uint8 Pins);

/**
 * @brief Write to a specific pin.
 *
 * @param Port The port in which the pin is located.
 * @param StructPtr A pointer to the Read_Write structure.
 */
void DIO_WritePin(Port_Select Port, Read_Write *StructPtr);

/**
 * @brief Write to a specific port.
 *
 * @param CpyPort_ID The ID of the port to write to.
 * @param CpyPinMask The mask representing pins to write to.
 * @param CpyValue The value to write (1 or 0).
 */
void DIO_Write(uint8 CpyPort_ID, uint8 CpyPinMask, uint8 CpyValue);

/* READ OPERATIONS */

/**
 * @brief Read the value of a specific pin.
 *
 * @param Port The port in which the pin is located.
 * @param StructPtr A pointer to the Read_Write structure.
 * @param Bit The bit number to read (0-7).
 * @return The value of the specified bit (1 or 0).
 */
int DIO_ReadPin(Port_Select Port, Read_Write *StructPtr, char Bit);

/**
 * @brief Read the values of a specific port.
 *
 * @param Port The port to read.
 * @param StructPtr A pointer to the Read_Write structure.
 */
void DIO_ReadPort(Port_Select Port, Read_Write *StructPtr);

/**
 * @brief Read the value of a specific pin.
 *
 * @param CpyPort_ID The ID of the port to read from.
 * @param CpyPinMask The mask representing pins to read from.
 * @return The value of the specified pins.
 */
uint8 DIO_Read(uint8 CpyPort_ID, uint8 CpyPinMask);

/**
 * @brief Set pull-up resistors for a specific port and pin.
 *
 * @param Cpy_Port The ID of the port to set pull-up resistors.
 * @param Cpy_PinMask The mask representing pins to set pull-up resistors.
 */
void DIO_Set_Pullup(uint8 Cpy_Port, uint8 Cpy_PinMask);

#endif /* DIO_H_ */
