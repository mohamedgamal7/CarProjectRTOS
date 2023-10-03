

#include <APP/APP_Config.h>
#include "stdbool.h"

#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"


#include "MCAL/DIO/DIO.h"
#include "HAL/LCD/LCD_interface.h"
#include "HAL/LDR/LDR.h"
#include "APP/DISPLAY_Module/display.h"


/* extern global variables */
extern dirType LDR_reading;
extern int32  Reading_differece;
//extern uint8_t temperature_reading ;
//extern uint32_t start_tick;
extern QueueHandle_t MBXstart_tick;
extern QueueHandle_t MBXtemperature_reading ;
extern QueueHandle_t MBXcurrunt_state;
extern QueueHandle_t MBXLDR_reading;
extern QueueHandle_t MBXReading_differece;


void lcd_display_const_string(void)
{
    LcdSendString("TEMP:00 LDR:0000");
    LcdGoTo(ROW2, COL1);
    LcdSendString("DIR:      SEC:00");
}

void lcd_display(void)
{
    lcd_display_const_string();
    uint32_t start_count;
    uint32_t temperature_reading;
    car_state current_state;
    dirType LDR_direction;
    int32_t  Reading_differece;



    while(1)
    {

            xQueuePeek( MBXstart_tick, &start_count, 0);
            xQueuePeek( MBXcurrunt_state, &current_state, 0);
            xQueuePeek( MBXtemperature_reading, &temperature_reading, 0);
            xQueuePeek( MBXLDR_reading, &LDR_direction, 0);
            xQueuePeek( MBXLDR_reading, &LDR_direction, 0);
            xQueuePeek( MBXReading_differece, &Reading_differece, 0);

            LcdGoTo(ROW1, COL6);
            LCDSendInt(temperature_reading);
            LcdGoTo(ROW1, COL13);
            LcdSendString("    ");
            LcdGoTo(ROW1, COL13);
            LCDSendInt(Reading_differece);
            LcdGoTo(ROW2,COL5);
            if (current_state == blocked_reverse || current_state == blocked_turning)
            {
               LcdSendString("block");
            }
            else
            {
               switch (LDR_direction)
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
            LCDSendInt((xTaskGetTickCount()-start_count) / (1000));
            vTaskDelay(pdMS_TO_TICKS(LCD_PERIOD));
    }
}
