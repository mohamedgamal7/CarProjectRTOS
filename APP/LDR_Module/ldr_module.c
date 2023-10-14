/*
 * ldr_module.c
 *
 * Created on: Oct 1, 2023
 * Author: Ahmed Maher
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

/**
 * @brief Implements the logic for a car with a swing LDR.
 *
 * This function continuously monitors the car's current state and controls its movement
 * based on the Light Dependent Resistor (LDR) readings.
 */
void ldr_swing_car(void)
{
    TickType_t xLastWakeTime = xTaskGetTickCount();
    car_state current_state;
    dirType LDR_direction;
    int32_t Reading_differece;

    while(1)
    {
        xLastWakeTime = xTaskGetTickCount();

        xQueuePeek(MBXcurrunt_state, &current_state, 0);

        if (current_state == free_running)
        {
            LDR_direction = LDR_Comp(&Reading_differece);

            // Update the LDR reading and difference in queues
            xQueueOverwrite(MBXReading_differece, &Reading_differece);
            xQueueOverwrite(MBXLDR_reading, &LDR_direction);

            // Control car movement based on LDR direction
            switch (LDR_direction)
            {
                case RIGHT:
                    MotorTurnRight(ENGINE_POWER);
                    break;
                case LEFT:
                    MotorTurnLeft(ENGINE_POWER);
                    break;
                default:
                    MotorForward(ENGINE_POWER);
                    break;
            }
        }

        vTaskDelayUntil(&xLastWakeTime, pdMS_TO_TICKS(LDR_PERIOD));
    }
}
