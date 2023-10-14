/**
 * @file temperature.c
 *
 * @brief Temperature Module Implementation
 *
 * This module implements a task to read temperature using a temperature sensor
 * and store the temperature reading in a queue for further processing.
 *
 * @author Mohamed Gamal
 * @date 05/10/2023
 */

#include "stdbool.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

#include "HAL/TEMPSENSOR/TempSensor.h"
#include "APP/APP_Config.h"
#include "APP/TEMP_Module/temperature.h"

extern QueueHandle_t MBXtemperature_reading;

/**
 * @brief Reads and stores the temperature in a queue.
 *
 * This function continuously reads the temperature using a temperature sensor
 * and stores the temperature reading in a queue for further processing.
 */
void Read_temperature(void)
{
    TickType_t xLastWakeTime = xTaskGetTickCount();
    uint32_t temperature_reading;

    while(1)
    {
        xLastWakeTime = xTaskGetTickCount();

        // Read the temperature using the TempRead function
        temperature_reading = TempRead();

        // Store the temperature reading in the temperature_reading mailbox
        xQueueOverwrite(MBXtemperature_reading, &temperature_reading);

        // Delay until the next temperature reading
        vTaskDelayUntil(&xLastWakeTime, pdMS_TO_TICKS(TEMP_PERIOD));
    }
}
