/*
 * DIO.h
 *
 *  Created on: Aug 13, 2023
 *      Author: EUI-Support
 */

#ifndef DIO_H_
#define DIO_H_
#include "LIB/tm4c123gh6pm.h"
#include "LIB/BIT_MATH.h"
#include "LIB/types.h"
/*                                    #DEFINE                                      */

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

#define PORTA_CC 0x01   /* PORT A CLOCK CONTROL FOR SYSCTL_RCGCGPIO_R */
#define PORTB_CC 0x02   /* PORT B CLOCK CONTROL FOR SYSCTL_RCGCGPIO_R */
#define PORTC_CC 0x04   /* PORT C CLOCK CONTROL FOR SYSCTL_RCGCGPIO_R */
#define PORTD_CC 0x08   /* PORT D CLOCK CONTROL FOR SYSCTL_RCGCGPIO_R */
#define PORTE_CC 0x10   /* PORT E CLOCK CONTROL FOR SYSCTL_RCGCGPIO_R */
#define PORTF_CC 0x20   /* PORT F CLOCK CONTROL FOR SYSCTL_RCGCGPIO_R */
#define PORTS_CC 0x3F   /* ALL PORT CLOCK CONTROL FOR SYSCTL_RCGCGPIO_R */
#define SET 1
#define CLEAR 0

/*EXTERN*/
extern PinConfig * PortStruct_ptr[Port_Num];
extern char Ports_Operating[Port_Num];
extern void PORT_CONFIG(void);

/*FUNCTION PTOTOTYPES*/
/* Configure which ports will operate */
void PORTS_Operation(void);

/* Initialize a specific port with the provided configuration settings */
void PORT_Init(Port_Select Port, PinConfig *StructPtr);

/* Initialize GPIO interrupts on a specific port with the provided configuration settings */
void GPIO_InterruptInit(Port_Select Port, PinConfig *StructPtr);

/* Configure an alternative function for a specific pin on the selected port */
void alt_Function(uint8 Port, uint8 pin, uint8 pinmux);

/* Set a specific pin or pins on the selected port to work in analog mode */
void analog_Mode(Port_Select Port, uint8 Pins);

/* Write a specified value to a specific pin on the selected port */
void DIO_WritePin(Port_Select Port, Read_Write *StructPtr);

/* Write a specified value to a set of pins (mask) on a given port */
void DIO_Write(uint8 CpyPort_ID, uint8 CpyPinMask, uint8 CpyValue);

/* Read the value of a specific pin on the selected port */
int DIO_ReadPin(Port_Select Port, Read_Write *StructPtr, char Bit);

/* Read the entire port and store the result in the provided data structure */
void DIO_ReadPort(Port_Select Port, Read_Write *StructPtr);

/* Read the value of a set of pins (mask) on a given port */
uint8 DIO_Read(uint8 CpyPort_ID, uint8 CpyPinMask);

/* Set pull-up resistors for the specified pins on the selected port */
void DIO_Set_Pullup(uint8 Cpy_Port, uint8 Cpy_PinMask);

#endif /* DIO_H_ */
