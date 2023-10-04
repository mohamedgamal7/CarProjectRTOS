#include "stdbool.h"

#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"

#include "MCAL/DIO/DIO.h"
#include "HAL/MOTOR/Motor.h"
#include "HAL/LDR/LDR.h"

#include "APP/BUTTONS_Module/Buttons.h"

extern QueueHandle_t MBXstart_tick;


void button_check(void)
{
    bool isRunning = true;
    TickType_t xLastWakeTime = xTaskGetTickCount();
    uint32_t tick_count;

    while(1)
    {
        xLastWakeTime = xTaskGetTickCount();
        xQueuePeek( MBXstart_tick, &tick_count, 0);
        if(!DIO_Read(PORTF, P0) && !isRunning) /* start */
        {
            while(!DIO_Read(PORTF, P0));
            xTaskResumeAll();
            tick_count = xTaskGetTickCount();
            xQueueOverwrite( MBXstart_tick, &tick_count );
            Calibrate();
            isRunning = true;
        }
        else if((!DIO_Read(PORTF, P4) || ((xTaskGetTickCount() - tick_count) / 1000) >= 60) && isRunning) /* stop */
        {
            while(!DIO_Read(PORTF, P4));
            MotorStop();
            vTaskSuspendAll();
            isRunning = false;
        }
        vTaskDelayUntil(&xLastWakeTime, pdMS_TO_TICKS(BUTTON_CHECK_PERIOD));
    }
}
