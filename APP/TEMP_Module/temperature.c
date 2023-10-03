#include "stdbool.h"

#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

#include "HAL/TEMPSENSOR/TempSensor.h"
#include "APP/APP_Config.h"
#include "APP/TEMP_Module/temperature.h"

extern QueueHandle_t MBXtemperature_reading ;


void Read_temperature(void)
{
    TickType_t xLastWakeTime = xTaskGetTickCount();

    uint32_t temperature_reading;
    while(1)
{

        xLastWakeTime = xTaskGetTickCount();
        temperature_reading = TempRead();
        xQueueOverwrite( MBXtemperature_reading, &temperature_reading );


        vTaskDelayUntil(&xLastWakeTime, pdMS_TO_TICKS(TEMP_PERIOD));

//     vTaskDelay(pdMS_TO_TICKS(TEMP_PERIOD));
    }

}
