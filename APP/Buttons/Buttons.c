#include "stdbool.h"

#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"

#include "MCAL/DIO/DIO.h"
#include "HAL/MOTOR/Motor.h"
#include "HAL/LDR/LDR.h"

#include "Buttons.h"

#define BUTTON_CHECK_PERIOD     80

void button_check(void)
{
    bool isRunning = true;
    TickType_t xLastWakeTime = xTaskGetTickCount();

    while(1)
    {
        if(!DIO_Read(PORTF, P0) && !isRunning) /* start */
        {
            while(!DIO_Read(PORTF, P0));
            xTaskResumeAll();
            Calibrate();
            isRunning = true;
        }
        else if((!DIO_Read(PORTF, P4) || (xTaskGetTickCount() / 1000) >= 60) && isRunning) /* stop */
        {
            while(!DIO_Read(PORTF, P4));
            MotorStop();
            vTaskSuspendAll();
            isRunning = false;
        }
        vTaskDelayUntil(&xLastWakeTime, pdMS_TO_TICKS(BUTTON_CHECK_PERIOD));
    }
}
