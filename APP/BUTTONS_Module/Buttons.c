#include "stdbool.h"

#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

#include "MCAL/DIO/DIO.h"
#include "HAL/MOTOR/Motor.h"
#include "HAL/LDR/LDR.h"
#include "APP/APP_Config.h"
#include "APP/BUTTONS_Module/Buttons.h"

// Queue handle for storing the start tick
extern QueueHandle_t MBXstart_tick;

// Function to check the state of buttons
void button_check(void)
{
    bool isRunning = true; // Variable to track if the system is running
    TickType_t xLastWakeTime = xTaskGetTickCount(); // Initialize the time variable
    uint32_t tick_count; // Variable to store the tick count

    while (1)
    {
        xLastWakeTime = xTaskGetTickCount(); // Get the current time

        xQueuePeek(MBXstart_tick, &tick_count, 0); // Read the start tick from the queue

        // Check the start button and if the system is not running
        if (!DIO_Read(PORTF, P0) && !isRunning) /* Start button is pressed and system is not running */
        {
            while (!DIO_Read(PORTF, P0)); // Wait for the button to be released
            xTaskResumeAll(); // Resume all tasks
            tick_count = xTaskGetTickCount(); // Get the current tick count
            xQueueOverwrite(MBXstart_tick, &tick_count); // Store the tick count in the queue
            Calibrate(); // Calibrate the system
            isRunning = true; // Set the system state to running
        }
        // Check the stop button or if the system has been running for 60 seconds
        else if (!DIO_Read(PORTF, P4) || ((xTaskGetTickCount() - tick_count) / 1000) >= 60)
        {
            while (!DIO_Read(PORTF, P4)); // Wait for the stop button to be released
            MotorStop(); // Stop the motor
            vTaskSuspendAll(); // Suspend all tasks
            isRunning = false; // Set the system state to not running
        }

        // Delay until the next button check
        vTaskDelayUntil(&xLastWakeTime, pdMS_TO_TICKS(BUTTON_CHECK_PERIOD));
    }
}
