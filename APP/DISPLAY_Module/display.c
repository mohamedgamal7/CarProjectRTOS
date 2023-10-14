/**
 * @file lcd_display.c
 *
 * @brief LCD Display Module Implementation
 *
 * This module implements functions for displaying information on an LCD screen.
 * It includes functions for displaying constant strings and dynamic data.
 *
 * @author Mohamed Gamal
 * @date 05/10/2023
 */

#include <APP/APP_Config.h>
#include "stdbool.h"

#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

#include "MCAL/DIO/DIO.h"
#include "HAL/LCD/LCD_interface.h"
#include "HAL/LDR/LDR.h"
#include "APP/APP_Config.h"
#include "APP/DISPLAY_Module/display.h"

extern QueueHandle_t MBXstart_tick;
extern QueueHandle_t MBXtemperature_reading;
extern QueueHandle_t MBXcurrunt_state;
extern QueueHandle_t MBXLDR_reading;
extern QueueHandle_t MBXReading_differece;

/**
 * @brief Initialize the LCD display with a constant string.
 *
 * This function initializes the LCD display with a constant string that includes placeholders for dynamic data.
 * It sets up the initial display structure.
 */
void lcd_display_const_string(void)
{
    LcdSendString("TEMP:00 LDR:0000");
    LcdGoTo(ROW2, COL1);
    LcdSendString("DIR:      SEC:00");
}

/**
 * @brief Continuously update and display dynamic data on the LCD.
 *
 * This function continuously updates and displays dynamic data on the LCD screen.
 * It retrieves data from various queues and displays it on the screen in real-time.
 */
void lcd_display(void)
{
    TickType_t xLastWakeTime = xTaskGetTickCount();
    lcd_display_const_string();
    uint32_t start_count;
    uint32_t temperature_reading;
    car_state current_state;
    dirType LDR_direction;
    int32_t Reading_differece;

    while(1)
    {
        xLastWakeTime = xTaskGetTickCount();

        /* Retrieve data from queues */
        xQueuePeek(MBXstart_tick, &start_count, 0);
        xQueuePeek(MBXcurrunt_state, &current_state, 0);
        xQueuePeek(MBXtemperature_reading, &temperature_reading, 0);
        xQueuePeek(MBXLDR_reading, &LDR_direction, 0);
        xQueuePeek(MBXReading_differece, &Reading_differece, 0);

        /* Display temperature reading */
        LcdGoTo(ROW1, COL6);
        LCDSendInt(temperature_reading);

        /* Clear the previous reading difference */
        LcdGoTo(ROW1, COL13);
        LcdSendString("    ");

        /* Display reading difference */
        LcdGoTo(ROW1, COL13);
        LCDSendInt(Reading_differece);

        /* Display current state */
        LcdGoTo(ROW2, COL5);
        if (current_state == blocked_reverse || current_state == blocked_turning)
        {
            LcdSendString("block");
        }
        else
        {
            /* Display LDR direction */
            switch (LDR_direction)
            {
                case RIGHT:
                    LcdSendString("right");
                    break;
                case LEFT:
                    LcdSendString("left ");
                    break;
                default:
                    LcdSendString("front");
                    break;
            }
        }

        /* Clear the previous seconds */
        LcdGoTo(ROW2, COL15);
        LcdSendString("  ");

        /* Display elapsed seconds */
        LcdGoTo(ROW2, COL15);
        LCDSendInt((xTaskGetTickCount() - start_count) / 1000);

        /* Delay for LCD update period */
        vTaskDelayUntil(&xLastWakeTime, pdMS_TO_TICKS(LCD_PERIOD));
    }
}
