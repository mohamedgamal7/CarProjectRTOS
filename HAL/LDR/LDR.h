/********************************************************************************************/
/* Authors: Mohamed Gamal, Ehab Roushdy, Ahmed Maher and Kareem Hany                        */
/* Version: V01                                                                             */
/* Date: 10/09/2023                                                                         */
/* Description: LDR Driver header                                                           */
/********************************************************************************************/
#ifndef LDR_H__
#define LDR_H__

#include <stdint.h> /* Include the standard integer types. */

#include "MCAL/ADC/ADC.h" /* Include the ADC module. */

typedef enum {
    STAY = 0,   /* Enumeration: STAY represents a stationary state. */
    RIGHT,      /* RIGHT represents a rightward movement. */
    LEFT        /* LEFT represents a leftward movement. */
} dirType; /* Define the direction type. */

void LDR_Init(void); /* Initialize the LDR module. */
dirType LDR_Comp(int32 * difference); /* Compare LDR readings and return the direction. */
void Calibrate(void); /* Calibrate the LDR readings. */

#endif
