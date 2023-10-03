/*
 * ldr_module.c
 *
 *  Created on: Oct 1, 2023
 *      Author: eme
 */

#include <APP/APP_Config.h>
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"

#include "MCAL/DIO/DIO.h"
#include "HAL/LDR/LDR.h"
#include "../HAL/MOTOR/Motor.h"
#include "APP/LDR_Module/ldr_module.h"

extern QueueHandle_t MBXcurrunt_state;
extern QueueHandle_t MBXLDR_reading;
extern QueueHandle_t MBXReading_differece;


//extern car_state currunt_state;
//extern dirType LDR_reading;
//extern int32  Reading_differece;

void ldr_swing_car(void)

{   car_state current_state;
    dirType LDR_direction;
    int32_t  Reading_differece;

    while(1)
    {
            xQueuePeek( MBXcurrunt_state, &current_state, 0);
            if(current_state == free_running)
            {
                LDR_direction =  LDR_Comp(&Reading_differece);
                xQueueOverwrite( MBXReading_differece, &Reading_differece);
                xQueueOverwrite( MBXLDR_reading, &LDR_direction);

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

        vTaskDelay(pdMS_TO_TICKS(LDR_PERIOD));
    }
}

