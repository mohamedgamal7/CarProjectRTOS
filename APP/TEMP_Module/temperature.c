#include "stdbool.h"

#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"

#include "HAL/TEMPSENSOR/TempSensor.h"
#include "APP/TEMP_Module/temperature.h"

extern QueueHandle_t MBXtemperature_reading ;


void Read_temperature(void)
{
    uint32_t temperature_reading;
    while(1)
    {
        temperature_reading = TempRead();
        xQueueOverwrite( MBXtemperature_reading, &temperature_reading );


     vTaskDelay(pdMS_TO_TICKS(TEMP_PERIOD));
    }

}
