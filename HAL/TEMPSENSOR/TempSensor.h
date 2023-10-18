#ifndef TEMPSENSOR_H__
#define TEMPSENSOR_H__

#include <stdbool.h>
#include <stdint.h>
#include "MCAL/ADC/ADC.h"

/* Function to initialize the temperature sensor */
void TempInit(void);

/* Function to read the temperature value from the sensor */
unsigned int TempRead(void);

#endif
