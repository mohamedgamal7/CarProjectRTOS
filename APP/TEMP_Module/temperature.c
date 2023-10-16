#include "stdbool.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "HAL/TEMPSENSOR/TempSensor.h"
#include "APP/APP_Config.h"
#include "APP/TEMP_Module/temperature.h"

extern QueueHandle_t MBXtemperature_reading; // Declare an external queue handle to share temperature readings

void Read_temperature(void)
{
    TickType_t xLastWakeTime = xTaskGetTickCount(); // Initialize the last wake time

    uint32_t temperature_reading; // Variable to store temperature readings
    while (1)
    {
        xLastWakeTime = xTaskGetTickCount(); // Reset the last wake time for periodic task execution
        temperature_reading = TempRead(); // Read the temperature using the TempRead function
        xQueueOverwrite(MBXtemperature_reading, &temperature_reading); // Send the temperature reading to the shared queue

        vTaskDelayUntil(&xLastWakeTime, pdMS_TO_TICKS(TEMP_PERIOD)); // Delay the task until the next execution period
    }
}
