#ifndef LDR_H__
#define LDR_H__

#include <stdint.h>
#include "MCAL/ADC/ADC.h"

// Enum for the direction
typedef enum {
    STAY = 0,
    RIGHT,
    LEFT
} dirType;

// Function to initialize LDR
void LDR_Init(void);

// Function to compare LDR readings and determine direction
dirType LDR_Comp(int32 *difference);

// Function to calibrate the LDR
void Calibrate(void);

#endif
