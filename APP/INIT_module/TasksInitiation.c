/*
 * TasksInitiation.c
 *
 *  Created on: Oct 2, 2023
 *      Author: Kareem Hani
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

// Function to initialize various modules and components
void APP_Init(void)
{
    uint32_t tick_count;

    while (1)
    {
        // Initialize the DIO ports
        PORTS_Operation();

        // Initialize the Ultrasonic module
        Ultrasonic_Init();

        // Initialize the Motor module
        MotorInit();

        // Initialize the LCD module
        LcdInit();

        // Initialize the LDR module
        LDR_Init();

        // Initialize the Temperature Sensor module
        TempInit();

        // Wait for a specific condition (e.g., a button press)
        while (DIO_Read(PORTF, P0));

        // Get the current system tick count
        tick_count = xTaskGetTickCount();

        // Send the tick count to a queue for further processing
        xQueueOverwrite(MBXstart_tick, &tick_count);

        // Suspend this task indefinitely (effectively stopping it)
        vTaskSuspend(NULL);
    }
}
