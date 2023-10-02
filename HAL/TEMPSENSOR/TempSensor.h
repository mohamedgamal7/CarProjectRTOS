#ifndef TEMPSENSOR_H__
#define TEMPSENSOR_H__

#include <stdbool.h>
#include <stdint.h>
#include "MCAL/ADC/ADC.h"

void TempInit(void);
unsigned int TempRead(void);



#endif
