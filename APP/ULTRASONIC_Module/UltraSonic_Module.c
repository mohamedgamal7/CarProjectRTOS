/**
 * @file UltraSonic_Module.c
 *
 * @brief Ultrasonic Module Implementation for Obstacle Avoidance
 *
 * This module implements the logic for obstacle avoidance in a car using an ultrasonic sensor.
 * It continuously monitors the car's current state and controls its movement to avoid obstacles.
 *
 * @date Oct 1, 2023
 * @author Aya Yasser
 */

#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

#include "HAL/ULTRASONIC/ULTRASONIC_interface.h"
#include "HAL/MOTOR/Motor.h"

#include "APP/APP_Config.h"
#include "APP/Ultrasonic_Module/Ultrasonic_Module.h"

extern QueueHandle_t MBXcurrunt_state;

/**
 * @brief Implements obstacle avoidance logic for a car with an ultrasonic sensor.
 *
 * This function continuously monitors the car's current state and performs obstacle avoidance
 * based on ultrasonic sensor readings. It controls the car's movement to avoid obstacles.
 */
void avoid_obstacles(void)
{
    TickType_t xLastWakeTime = xTaskGetTickCount();
    float distance = -1;
    car_state current_state;

    while(1)
    {
        xLastWakeTime = xTaskGetTickCount();
        xQueuePeek(MBXcurrunt_state, &current_state, 0);

        switch (current_state)
        {
            case blocked_reverse:
            {
                distance = -1;
                vTaskDelay(pdMS_TO_TICKS(500));
                distance = Measure_Distance();

                if (distance > 20 || distance < 0)
                {
                    MotorTurnRight(ENGINE_POWER);
                    current_state = blocked_turning;
                    xQueueOverwrite(MBXcurrunt_state, &current_state);
                }
                else
                {
                    current_state = blocked_reverse;
                    xQueueOverwrite(MBXcurrunt_state, &current_state);
                }
                break;
            }
            case blocked_turning:
            {
                vTaskDelay(pdMS_TO_TICKS(500));
                current_state = free_running;
                xQueueOverwrite(MBXcurrunt_state, &current_state);
                break;
            }
            default: /* free_running */
            {
                distance = -1;
                distance = Measure_Distance();

                if (distance < 10 && distance > -1)
                {
                    current_state = blocked_reverse;
                    xQueueOverwrite(MBXcurrunt_state, &current_state);
                    MotorBackward(ENGINE_POWER);
                }
                else
                {
                    current_state = free_running;
                    xQueueOverwrite(MBXcurrunt_state, &current_state);
                }
                break;
            }
        }

        vTaskDelayUntil(&xLastWakeTime, pdMS_TO_TICKS(ULTRASONIC_PERIOD));
    }
}
