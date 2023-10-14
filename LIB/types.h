#ifndef TYPES_
#define TYPES_
#define Port_Num 6
/*                                    TYPEDEF                                      */
typedef char int8;
typedef char* int8_ptr;
typedef unsigned char uint8;
typedef unsigned char* uint8_ptr;
typedef int int32;
typedef int* int32_ptr;
typedef unsigned int uint32;
typedef unsigned int* uint32_ptr;
typedef short int16;
typedef short* int16_ptr;
typedef unsigned short uint16;
typedef unsigned short* uint16_ptr;
typedef long int64;
typedef long* int64_ptr;
typedef unsigned long uint64;
typedef unsigned long* uint64_ptr;
/*                                    ENUM                                      */
typedef enum {
    PORTA, PORTB , PORTC, PORTD, PORTE, PORTF
}Port_Select;
typedef enum {
    PIN0, PIN1, PIN2, PIN3, PIN4, PIN5, PIN6, PIN7
}Pin_Select;
typedef enum {
    Input , Output = 1
}Direction;
typedef enum {
    LOW = 0, HIGH = 1, NOT_WORKING=2
}Polarity;
/*                                    UNION                                      */
typedef union {
    struct{
        unsigned char Pin0:1;
        unsigned char Pin1:1;
        unsigned char Pin2:1;
        unsigned char Pin3:1;
        unsigned char Pin4:1;
        unsigned char Pin5:1;
        unsigned char Pin6:1;
        unsigned char Pin7:1;
    };
    unsigned char Pins_Data;
}Pins_Init;
/*                                    STRUCTURE                                      */
typedef struct {
    Pins_Init Pins ;
    Pins_Init Pin_DirectionHigh;
    unsigned char PullUp_Down;
    Pins_Init Pull_Up;
    Pins_Init Pull_Down;
    unsigned char   Interrupts_Enable;
    Pins_Init Level_Detection;
    Pins_Init Both_Edges;
    Pins_Init RisingFalling_Edge;
    Pins_Init Interrupt_Mask;
}PinConfig;
typedef struct {
    char ReadPORT;
    Pins_Init WritePIN;
}Read_Write;
#endif
