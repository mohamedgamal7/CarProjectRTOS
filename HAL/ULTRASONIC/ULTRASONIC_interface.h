/*
 * Author:      Mohamed Gamal Roushdy
 * Version:     0.1
 * Date:        31/08/2023
 * Description: Ultrasonic Sensor Driver Interface
 *              This file contains the interface for an Ultrasonic sensor driver.
 *              It provides functions to initialize the sensor, handle measurement callbacks,
 *              and measure distances using the sensor.
 *
 * Important Note: The driver assumes that F_CPU is defined and set to the microcontroller's
 * clock frequency (in Hertz) to perform accurate timing for distance measurements.
 * Make sure to set F_CPU accordingly before using the driver.
 */

#ifndef _ULTRASONIC_INTERFACE_H
#define _ULTRASONIC_INTERFACE_H

#define F_CPU 16000000UL // Microcontroller clock frequency (adjust as needed)

/*
 * Function: Ultrasonic_Init
 * Description: Initialize the Ultrasonic sensor. This function sets up the necessary pins
 *              and configurations for the sensor to operate properly.
 */
void Ultrasonic_Init(void);

/*
 * Function: Ultrasonic_Callback
 * Description: Callback function that handles sensor measurements. This function is typically
 *              triggered by an external interrupt or timer interrupt when the sensor receives
 *              an echo signal. It processes the time duration of the echo signal to calculate
 *              the distance to the detected object.
 */
void Ultrasonic_Callback(void);

/*
 * Function: Measure_Distance
 * Description: Measure and return the distance from the Ultrasonic sensor to the detected object.
 *              This function returns the distance in centimeters as a floating-point value.
 * Returns: The measured distance in centimeters.
 */
float Measure_Distance(void);

#endif
