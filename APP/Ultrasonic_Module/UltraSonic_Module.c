/*
 * UltraSonic_Module.c
 *
 *  Created on: Oct 1, 2023
 *      Author: ERoshdy
 */
#include "APP/Ultrasonic_Module/Ultrasonic_Module.h"

void avoid_obstacles(void)
{
    float distance = -1;
    while(1)
    {
//        if(xSemaphoreTake(sMutex, 0))
//        {
            static uint8 turnning_counter = 35;
            static uint8 block_counter = 100;
            switch (currunt_state)
            {
                case blocked_reverse:
                {
                    distance = -1;
                    vTaskDelay(pdMS_TO_TICKS(500));
                    distance = Measure_Distance();
                    if(distance > 20 || distance < 0)
                    {
                        MotorTurnRight(ENGINE_POWER);
                        currunt_state = blocked_turning;
                    }
                    else
                    {
                        currunt_state = blocked_reverse;
                    }

                    break;
                }
                case blocked_turning:
                {
                    vTaskDelay(pdMS_TO_TICKS(500));
                    currunt_state = free_running;


                    break;
                }
                default: /* free_running */
                {
                    distance = -1;
                    distance = Measure_Distance();

                    if(distance < 10 && distance > -1)
                    {
                        currunt_state = blocked_reverse;
                        MotorBackward(ENGINE_POWER);
                    }
                    else
                    {
                        currunt_state = free_running;
                    }
                    break;
                }
            }
//            xSemaphoreGive(sMutex);
//        }
//        else
//        {
//
//        }
        vTaskDelay(pdMS_TO_TICKS(ULTRASONIC_PERIOD));
    }
}



