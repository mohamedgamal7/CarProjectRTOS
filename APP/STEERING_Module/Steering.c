#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

#include "HAL/MOTOR/Motor.h"
#include "HAL/LDR/LDR.h"

#include "APP/APP_Config.h"
#include "APP/STEERING_Module/Steering.h"

extern QueueHandle_t MBXcurrunt_state;
extern QueueHandle_t MBXLDR_reading;

void (*MotorDirections[4])(unsigned char) = {MotorForward,MotorTurnRight,MotorTurnLeft,MotorBackward};


void SteerControl(void)
{   const uint32_t * pPbConfig = PbConfigAddress;
    TickType_t xLastWakeTime = xTaskGetTickCount();
    car_state current_state;
    dirType LDR_direction;
    while(1)
    {
        xLastWakeTime = xTaskGetTickCount();
        xQueuePeek( MBXcurrunt_state, &current_state, 0);
        xQueuePeek( MBXLDR_reading, &LDR_direction, 0);
        switch (current_state)
        {
        case blocked_reverse:
            MotorBackward(ENGINE_POWER);
            break;
        case blocked_turning:
            if(*pPbConfig==Pb_TurnRight)
            {
            MotorTurnRight(ENGINE_POWER);
            }
            else
            {
            MotorTurnLeft(ENGINE_POWER);
            }
            break;

        default:
            /*Move the car to the appropriate direction based on LDR reading*/
            (*MotorDirections[LDR_direction])(ENGINE_POWER);
            break;
        }

        vTaskDelayUntil(&xLastWakeTime, pdMS_TO_TICKS(STEERING_PERIOD));

    }


}
