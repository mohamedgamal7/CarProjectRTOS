#ifndef TYPES_
#define TYPES_
#define Port_Num 6

/* Data Types */

typedef char int8;           // 8-bit signed integer
typedef char* int8_ptr;      // Pointer to an 8-bit signed integer
typedef unsigned char uint8; // 8-bit unsigned integer
typedef unsigned char* uint8_ptr; // Pointer to an 8-bit unsigned integer
typedef int int32;           // 32-bit signed integer
typedef int* int32_ptr;      // Pointer to a 32-bit signed integer
typedef unsigned int uint32; // 32-bit unsigned integer
typedef unsigned int* uint32_ptr; // Pointer to a 32-bit unsigned integer
typedef short int16;         // 16-bit signed integer
typedef short* int16_ptr;    // Pointer to a 16-bit signed integer
typedef unsigned short uint16; // 16-bit unsigned integer
typedef unsigned short* uint16_ptr; // Pointer to a 16-bit unsigned integer
typedef long int64;          // 64-bit signed integer
typedef long* int64_ptr;     // Pointer to a 64-bit signed integer
typedef unsigned long uint64; // 64-bit unsigned integer
typedef unsigned long* uint64_ptr; // Pointer to a 64-bit unsigned integer

/* Enums */

typedef enum {
    PORTA, PORTB , PORTC, PORTD, PORTE, PORTF
} Port_Select; // Enumeration of possible ports

typedef enum {
    PIN0, PIN1, PIN2, PIN3, PIN4, PIN5, PIN6, PIN7
} Pin_Select; // Enumeration of possible pins

typedef enum {
    Input, Output = 1
} Direction; // Enumeration for pin direction (Input or Output)

typedef enum {
    LOW = 0, HIGH = 1, NOT_WORKING = 2
} Polarity; // Enumeration for polarity (Low, High, or Not Working)

/* Union */

typedef union {
    struct {
        unsigned char Pin0 : 1;
        unsigned char Pin1 : 1;
        unsigned char Pin2 : 1;
        unsigned char Pin3 : 1;
        unsigned char Pin4 : 1;
        unsigned char Pin5 : 1;
        unsigned char Pin6 : 1;
        unsigned char Pin7 : 1;
    };
    unsigned char Pins_Data;
} Pins_Init; // Union for working with individual pins or the entire data

/* Structure */

typedef struct {
    Pins_Init Pins;                // The pins' state (e.g., 0b00101011 for eight pins)
    Pins_Init Pin_DirectionHigh;   // The direction of each pin (Input or Output)
    unsigned char PullUp_Down;     // Configuration for Pull-Up or Pull-Down (Polarity)
    Pins_Init Pull_Up;             // Pins with Pull-Up enabled
    Pins_Init Pull_Down;           // Pins with Pull-Down enabled
    unsigned char Interrupts_Enable; // Configuration for enabling or disabling interrupts
    Pins_Init Level_Detection;     // Pins configured for level-based interrupt detection
    Pins_Init Both_Edges;         // Pins configured for both rising and falling edge interrupt detection
    Pins_Init RisingFalling_Edge; // Pins configured for any edge interrupt detection
    Pins_Init Interrupt_Mask;     // Mask to enable or disable specific interrupts
} PinConfig; // Structure to configure various pin-related settings

typedef struct {
    char ReadPORT;                  // Read state of a specific port
    Pins_Init WritePIN;             // Write data to specific pins in a port
} Read_Write; // Structure for reading from and writing to ports

#endif
