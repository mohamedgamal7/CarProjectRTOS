/**
 * @file main.c
 * @brief Main application file for configuring DIO ports and pins.
 */

#include "LIB/types.h"

/* Flags to indicate whether each port is operating or not (1 for operating, 0 for not operating) */
char Ports_Operating[Port_Num] = {1, 1, 1, 1, 1, 1};

/* Array of Pointers to struct */
PinConfig *PortStruct_ptr[Port_Num];

/**
 * @brief Configure the DIO ports and pins.
 */
void PORT_CONFIG(void)
{
    /* PORT A */
    PinConfig StructPtr_PORT_A = {
        .Pins.Pins_Data = 0,
        .Pins.Pins_Data = 0x68, /* Define used pins */
        .Pin_DirectionHigh.Pins_Data = 0,
        .Pin_DirectionHigh.Pins_Data = 0x68, /* Define output pins */
        .Interrupts_Enable = LOW, /* Interrupts are disabled */
    };
    PortStruct_ptr[PORTA] = &StructPtr_PORT_A;

    /* PORT B */
    PinConfig StructPtr_PORT_B = {
        .Pins.Pins_Data = 0,
        .Pins.Pins_Data = 0xC3, /* Define used pins */
        .Pin_DirectionHigh.Pins_Data = 0,
        .Pin_DirectionHigh.Pins_Data = 0xC3, /* Define output pins */
        .Interrupts_Enable = LOW, /* Interrupts are disabled */
    };
    PortStruct_ptr[PORTB] = &StructPtr_PORT_B;

    /* PORT C */
    PinConfig StructPtr_PORT_C = {
        .Pins.Pins_Data = 0,
        .Pins.Pins_Data = 0xF0, /* Define used pins */
        .Pin_DirectionHigh.Pins_Data = 0,
        .Pin_DirectionHigh.Pins_Data = 0xC0, /* Define output pins */
        .PullUp_Down = NOT_WORKING, /* Pull-up is not working */
        .Interrupts_Enable = LOW, /* Interrupts are disabled */
        .Pull_Up.Pins_Data = 0, /* Initialize pull-up pins */
        .Pull_Up.Pins_Data = 0x10, /* Define pull-up pins */
    };
    PortStruct_ptr[PORTC] = &StructPtr_PORT_C;

    /* PORT D */
    PinConfig StructPtr_PORT_D = {
        .Pins.Pins_Data = 0,
        .Pins.Pins_Data = 0xC4, /* Define used pins */
        .Pin_DirectionHigh.Pins_Data = 0,
        .Pin_DirectionHigh.Pins_Data = 0xC4, /* Define output pins */
        .PullUp_Down = NOT_WORKING, /* Pull-up is not working */
        .Interrupts_Enable = LOW, /* Interrupts are disabled */
    };
    PortStruct_ptr[PORTD] = &StructPtr_PORT_D;

    /* PORT E */
    PinConfig StructPtr_PORT_E = {
        .Pins.Pins_Data = 0,
        .Pins.Pins_Data = 0x3C, /* Define used pins */
        .Pin_DirectionHigh.Pins_Data = 0,
        .Pin_DirectionHigh.Pins_Data = 0x30, /* Define output pins */
        .PullUp_Down = NOT_WORKING, /* Pull-up is not working */
        .Interrupts_Enable = LOW, /* Interrupts are disabled */
    };
    PortStruct_ptr[PORTE] = &StructPtr_PORT_E;

    /* PORT F */
    PinConfig StructPtr_PORT_F = {
        .Pins.Pins_Data = 0,
        .Pins.Pins_Data = 0x11, /* Define used pins (e.g., SWITCH 2) */
        .Pin_DirectionHigh.Pins_Data = 0, /* Input pins */
        .PullUp_Down = HIGH, /* Enable pull-up */
        .Interrupts_Enable = LOW, /* Interrupts are disabled */
        .Pull_Up.Pins_Data = 0, /* Initialize pull-up pins */
        .Pull_Up.Pins_Data = 0x11, /* Define pull-up pins */
        .Level_Detection.Pins_Data = 0, /* Level detection disabled */
        .Level_Detection.Pins_Data = 0x00, /* Define level detection settings */
        .Both_Edges.Pins_Data = 0, /* Both edges disabled */
        .RisingFalling_Edge.Pins_Data = 0, /* All falling edge interrupts */
        .Interrupt_Mask.Pins_Data = 0x00, /* Interrupts disabled on PIN0 and PIN4 */
    };
    PortStruct_ptr[PORTF] = &StructPtr_PORT_F;
}
