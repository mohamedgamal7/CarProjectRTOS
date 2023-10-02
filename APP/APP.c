#include "APP.h"

//#define ENGINE_POWER    70

extern car_state currunt_state;
extern dirType LDR_reading;
extern int32  Reading_differece;

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
void lcd_display_const_string(void)
{
    LcdSendString("TEMP:00 LDR:0000");
    LcdGoTo(ROW2, COL1);
    LcdSendString("DIR:      SEC:00");
}

