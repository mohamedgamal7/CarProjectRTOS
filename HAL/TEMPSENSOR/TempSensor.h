/********************************************************************************************/
/* Authors: Mohamed Gamal, Ehab Roushdy, Ahmed Maher and Kareem Hany                        */                                  */
/* Version: V01                                                                             */
/* Date: 10/09/2023                                                                         */
/* Description: Temperature Sensor header file                                              */
/********************************************************************************************/

#ifndef TEMPSENSOR_H__
#define TEMPSENSOR_H__


#include <stdbool.h> // Include the standard boolean types.
#include <stdint.h> // Include the standard integer types.
#include "MCAL/ADC/ADC.h" // Include the ADC module for reading temperature.

/**
 * @brief Initialize the temperature sensor module.
 */
void TempInit(void);

/**
 * @brief Read the temperature from the sensor.
 *
 * @return The temperature reading as an unsigned integer.
 */
unsigned int TempRead(void);

#endif
