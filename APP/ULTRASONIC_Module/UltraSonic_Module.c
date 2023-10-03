/*
 * UltraSonic_Module.c
 *
 *  Created on: Oct 1, 2023
 *      Author: ERoshdy
 */
#include "APP/Ultrasonic_Module/Ultrasonic_Module.h"

extern dirType LDR_reading;
//extern car_state current_state;
extern int32  Reading_differece;
extern QueueHandle_t MBXcurrunt_state;

void avoid_obstacles(void)
{
    TickType_t xLastWakeTime = xTaskGetTickCount();
    float distance = -1;
    car_state current_state;
    while(1)
    {
            xLastWakeTime = xTaskGetTickCount();
//            static uint8 turnning_counter = 35;
//            static uint8 block_counter = 100;
            xQueuePeek( MBXcurrunt_state, &current_state, 0);
            switch (current_state)
            {
                case blocked_reverse:
                {
                    distance = -1;
                    vTaskDelay(pdMS_TO_TICKS(500));
                    distance = Measure_Distance();
                    if(distance > 20 || distance < 0)
                    {
                        MotorTurnRight(ENGINE_POWER);
                        current_state = blocked_turning;
                        xQueueOverwrite( MBXcurrunt_state, &current_state );
                    }
                    else
                    {
                        current_state = blocked_reverse;
                        xQueueOverwrite( MBXcurrunt_state, &current_state );
                    }

                    break;
                }
                case blocked_turning:
                {
                    vTaskDelay(pdMS_TO_TICKS(500));
                    current_state = free_running;
                    xQueueOverwrite( MBXcurrunt_state, &current_state );


                    break;
                }
                default: /* free_running */
                {
                    distance = -1;
                    distance = Measure_Distance();

                    if(distance < 10 && distance > -1)
                    {
                        current_state = blocked_reverse;
                        xQueueOverwrite( MBXcurrunt_state, &current_state );
                        MotorBackward(ENGINE_POWER);
                    }
                    else
                    {
                        current_state = free_running;
                        xQueueOverwrite( MBXcurrunt_state, &current_state );
                    }
                    break;
                }
            }

            vTaskDelayUntil(&xLastWakeTime, pdMS_TO_TICKS(ULTRASONIC_PERIOD));
//        vTaskDelay(pdMS_TO_TICKS(ULTRASONIC_PERIOD));
    }
}



