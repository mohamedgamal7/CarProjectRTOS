/*
 * Author:      Mohamed Gamal Roushdy
 * Version:     0.2
 * Date:        10/09/2023
 * Description: Ultrasonic Driver Private Header
 *              This private header file contains internal definitions and functions used
 *              by the Ultrasonic driver. It should not be included or used directly in
 *              application code.
 */

#ifndef _ULTRASONIC_PRIVATE_H
#define _ULTRASONIC_PRIVATE_H

#define TIMEOUT_DURATION_TICKS    5*3180  /* Represents a 5-millisecond timeout duration */

/*
 * Static function: Ultrasonic_GPIO_Init
 * Description: Initialize GPIO pins and configurations for the Ultrasonic sensor.
 *              This function is private and not intended for direct use in application code.
 */
static void Ultrasonic_GPIO_Init(void);

/*
 * Static function: Ultrasonic_Timer_Init
 * Description: Initialize timers used for Ultrasonic sensor measurements.
 *              This function is private and not intended for direct use in application code.
 */
static void Ultrasonic_Timer_Init(void);

#endif
