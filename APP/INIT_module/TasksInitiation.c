/*
 * TasksInitiation.c
 *
 * Created on: Oct 2, 2023
 * Author: Kareem Hani
 *
 * This file is made for the Initialization of the needed modules.
 */

#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

#include "MCAL/DIO/DIO.h"
#include "HAL/ULTRASONIC/ULTRASONIC_interface.h"
#include "HAL/MOTOR/Motor.h"
#include "HAL/LDR/LDR.h"
#include "HAL/LCD/LCD_interface.h"
#include "HAL/TEMPSENSOR/TempSensor.h"

extern QueueHandle_t MBXstart_tick;

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
void APP_Init(void)
{
    uint32_t tick_count;

    while(1)
    {
        /** Initialize port operations **/
        PORTS_Operation();

        /** Initialize Ultrasonic sensor **/
        Ultrasonic_Init();

        /** Initialize motor **/
        MotorInit();

        /** Initialize LCD display **/
        LcdInit();

        /** Initialize Light Dependent Resistor (LDR) **/
        LDR_Init();

        /** Initialize temperature sensor **/
        TempInit();

        /** Wait for a button press on PORTF, P0 **/
        while(DIO_Read(PORTF, P0));

        /** Store the current tick count **/
        tick_count = xTaskGetTickCount();

        /** Overwrite the start_tick mailbox with the tick count **/
        xQueueOverwrite(MBXstart_tick, &tick_count);

        /** Suspend the task indefinitely **/
        vTaskSuspend(NULL);
    }
}
