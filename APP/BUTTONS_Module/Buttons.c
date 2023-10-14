/**
 * @file button_check.c
 *
 * @brief Button Check Task Implementation
 *
 * This module contains the implementation of a task that continuously monitors buttons and performs actions based on button presses.
 * It starts or stops a process based on button inputs and communicates with other tasks using a queue.
 *
 * @author Ehab Roshdy
 * @date 05/10/2023
 */

#include "stdbool.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "MCAL/DIO/DIO.h"
#include "HAL/MOTOR/Motor.h"
#include "HAL/LDR/LDR.h"
#include "APP/APP_Config.h"
#include "APP/BUTTONS_Module/Buttons.h"

extern QueueHandle_t MBXstart_tick;



/** @brief Continuously monitors buttons and performs actions based on button presses.
 *
 *  This function continuously monitors buttons and performs actions based on button presses.
 *  It starts or stops a process based on button inputs and communicates with other tasks using a queue.
 *
 *  @arguments None
 *
 *  @reentrancy This function is not reentrant as it uses static variables to track the process state.
 */
void button_check(void)
{
    /* Flag indicating if the process is running or stopped */
    bool isRunning = true;
    /* Last wake time for task */
    TickType_t xLastWakeTime = xTaskGetTickCount();
    /* Stores the tick count for time tracking */
    uint32_t tick_count;

    while(1)
    {
        xLastWakeTime = xTaskGetTickCount();
        xQueuePeek( MBXstart_tick, &tick_count, 0);

        /* Start button pressed, and the process is not running */
        if (!DIO_Read(PORTF, P0) && !isRunning)
        {
            while(!DIO_Read(PORTF, P0));
            xTaskResumeAll();
            tick_count = xTaskGetTickCount();
            xQueueOverwrite( MBXstart_tick, &tick_count );
            Calibrate();
            isRunning = true;
        }
        /* Stop button pressed or process has been running for 60 seconds */
        else if ((!DIO_Read(PORTF, P4) || ((xTaskGetTickCount() - tick_count) / 1000) >= 60) && isRunning)
        {
            while(!DIO_Read(PORTF, P4));
            MotorStop();
            vTaskSuspendAll();
            isRunning = false;
        }
        vTaskDelayUntil(&xLastWakeTime, pdMS_TO_TICKS(BUTTON_CHECK_PERIOD));
    }
}
