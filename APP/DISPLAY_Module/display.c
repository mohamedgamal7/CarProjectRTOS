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

// Externally defined queues
extern QueueHandle_t MBXstart_tick;
extern QueueHandle_t MBXtemperature_reading;
extern QueueHandle_t MBXcurrunt_state;
extern QueueHandle_t MBXLDR_reading;
extern QueueHandle_t MBXReading_differece;

// Function to initialize the LCD with constant strings
void lcd_display_const_string(void)
{
    LcdSendString("TEMP:00 LDR:0000"); // Display initial temperature and LDR values
    LcdGoTo(ROW2, COL1);
    LcdSendString("DIR:      SEC:00"); // Display initial direction and time values
}

// Function to display dynamic data on the LCD
void lcd_display(void)
{
    TickType_t xLastWakeTime = xTaskGetTickCount(); // Initialize the task's last wake time

    lcd_display_const_string(); // Initialize the display with constant strings
    uint32_t start_count;
    uint32_t temperature_reading;
    car_state current_state;
    dirType LDR_direction;
    int32_t Reading_differece;

    while (1)
    {
        xLastWakeTime = xTaskGetTickCount(); // Update the last wake time

        // Retrieve data from queues
        xQueuePeek(MBXstart_tick, &start_count, 0);
        xQueuePeek(MBXcurrunt_state, &current_state, 0);
        xQueuePeek(MBXtemperature_reading, &temperature_reading, 0);
        xQueuePeek(MBXLDR_reading, &LDR_direction, 0);
        xQueuePeek(MBXLDR_reading, &LDR_direction, 0);
        xQueuePeek(MBXReading_differece, &Reading_differece, 0);

        // Update the LCD display with dynamic data
        LcdGoTo(ROW1, COL6);
        LCDSendInt(temperature_reading); // Display temperature reading
        LcdGoTo(ROW1, COL13);
        LcdSendString("    ");
        LcdGoTo(ROW1, COL13);
        LCDSendInt(Reading_differece); // Display LDR reading difference
        LcdGoTo(ROW2, COL5);

        if (current_state == blocked_reverse || current_state == blocked_turning)
        {
            LcdSendString("block"); // Display "block" when the car is blocked
        }
        else
        {
            switch (LDR_direction)
            {
                case RIGHT:
                {
                    LcdSendString("right"); // Display "right" when LDR direction is right
                    break;
                }
                case LEFT:
                {
                    LcdSendString("left "); // Display "left" when LDR direction is left
                    break;
                }
                default:
                {
                    LcdSendString("front"); // Display "front" when no specific direction
                    break;
                }
            }
        }

        LcdGoTo(ROW2, COL15);
        LcdSendString("  ");
        LcdGoTo(ROW2, COL15);
        LCDSendInt((xTaskGetTickCount() - start_count) / 1000); // Display time in seconds

        vTaskDelayUntil(&xLastWakeTime, pdMS_TO_TICKS(LCD_PERIOD)); // Delay until the next LCD update
    }
}
