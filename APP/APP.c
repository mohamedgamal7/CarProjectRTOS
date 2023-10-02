#include "APP.h"

#define ENGINE_POWER    70

car_state currunt_state = free_running;
dirType LDR_reading;
int32  Reading_differece = 0 ;


void ldr_swing_car(void)
{
    while(1)
    {
//        if(xSemaphoreTake(sMutex, 0))
//        {
            if(currunt_state == free_running)
            {
                LDR_reading =  LDR_Comp(&Reading_differece);
                switch (LDR_reading)
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
//            xSemaphoreGive(sMutex);
//        }
//        else
//        {
//
//        }
        vTaskDelay(pdMS_TO_TICKS(LDR_PERIOD));
    }
}

void lcd_display(void)
{
    while(1)
    {
//        if(xSemaphoreTake(sMutex, 0))
//        {
            LcdGoTo(ROW1, COL6);
            LCDSendInt(TempRead());
            LcdGoTo(ROW1, COL13);
            LcdSendString("    ");
            LcdGoTo(ROW1, COL13);
            LCDSendInt(Reading_differece);
            LcdGoTo(ROW2,COL5);
            if (currunt_state == blocked_reverse || currunt_state == blocked_turning)
            {
               LcdSendString("block");
            }
            else
            {
               switch (LDR_reading)
               {
                   case RIGHT:
                   {
                       LcdSendString("right");
                       break;
                   }
                   case LEFT:
                   {
                       LcdSendString("left ");
                       break;
                   }
                   default:
                   {
                       LcdSendString("front");
                       break;
                   }
               }
            }

            LcdGoTo(ROW2, COL15);
            LcdSendString("  ");
            LcdGoTo(ROW2, COL15);
            LCDSendInt(xTaskGetTickCount() / (1000));
//            xSemaphoreGive(sMutex);
//        }
//        else
//        {
//
//        }
        vTaskDelay(pdMS_TO_TICKS(LCD_PERIOD));
    }
}

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

void lcd_display_const_string(void)
{
    LcdSendString("TEMP:00 LDR:0000");
    LcdGoTo(ROW2, COL1);
    LcdSendString("DIR:      SEC:00");
}


void button_check(void)
{
    bool isRunning = true;
    while(1)
    {
//        if(xSemaphoreTake(sMutex, 0))
//        {
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
                vTaskSuspendAll();
                MotorStop();
                isRunning = false;
            }
//            xSemaphoreGive(sMutex);
//        }
//        else
//        {
//
//        }
//        taskYIELD();
        vTaskDelay(pdMS_TO_TICKS(BUTTON_CHECK_PERIOD));
//        vTaskDelay(BUTTON_CHECK_PERIOD / portTICK_PERIOD_MS);
    }
}
