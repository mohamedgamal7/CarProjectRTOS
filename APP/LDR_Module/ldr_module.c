/*
 * ldr_module.c
 *
 *  Created on: Oct 1, 2023
 *      Author: eme
 */

#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

#include "HAL/LDR/LDR.h"
#include "HAL/MOTOR/Motor.h"

#include "APP/APP_Config.h"
#include "APP/LDR_Module/ldr_module.h"

extern QueueHandle_t MBXcurrunt_state;
extern QueueHandle_t MBXLDR_reading;
extern QueueHandle_t MBXReading_differece;

// Function for controlling a swing car based on LDR readings
void ldr_swing_car(void)
{
    // Initialize variables and task management
    TickType_t xLastWakeTime = xTaskGetTickCount(); // Initialize a variable to keep track of time
    car_state current_state; // Variable to store the current state of the swing car
    dirType LDR_direction; // Variable to store the LDR reading direction
    int32_t Reading_differece; // Variable to store the difference in LDR readings

    while (1)
    {
        xLastWakeTime = xTaskGetTickCount();

        // Check the current state
        xQueuePeek(MBXcurrunt_state, &current_state, 0);

        if (current_state == free_running)
        {
            // Calculate LDR reading and direction difference
            LDR_direction = LDR_Comp(&Reading_differece);
            xQueueOverwrite(MBXReading_differece, &Reading_differece);
            xQueueOverwrite(MBXLDR_reading, &LDR_direction);

            // Control the swing car based on LDR direction
            switch (LDR_direction)
            {
                case RIGHT:
                {
                    MotorTurnRight(ENGINE_POWER);
                    break;
                }
                case LEFT:
                {
                    MotorTurnLeft(ENGINE_POWER);
                    break;
                }
                default:
                {
                    MotorForward(ENGINE_POWER);
                    break;
                }
            }
        }
        // Delay until the next LDR reading
        vTaskDelayUntil(&xLastWakeTime, pdMS_TO_TICKS(LDR_PERIOD));
    }
}
