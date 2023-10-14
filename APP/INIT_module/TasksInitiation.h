/*
 * TasksInitiation.h
 *
 * Created on: Oct 2, 2023
 * Author: Kareem Hani
 *
 * Header file for Initialization of Modules
 */

#ifndef TASKSINITIATION_H_
#define TASKSINITIATION_H_

/**
 * @brief Initializes the necessary modules for the application.
 *
 * This function initializes various modules required for the application to function properly.
 * It performs the following tasks:
 * - Initializes port operations.
 * - Initializes the Ultrasonic sensor.
 * - Initializes the motor.
 * - Initializes the LCD display.
 * - Initializes the Light Dependent Resistor (LDR).
 * - Initializes the temperature sensor.
 * - Waits for a button press on PORTF, P0.
 * - Stores the current tick count and suspends the task indefinitely.
 */
void APP_Init(void);

#endif /* TASKSINITIATION_H_ */
