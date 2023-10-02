// Include necessary TivaWare and FreeRTOS headers
#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"

#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"

#include "LIB/Delay.h"
#include "MCAL/DIO/DIO.h"
#include "HAL/ULTRASONIC/ULTRASONIC_interface.h"
#include "HAL/MOTOR/Motor.h"
#include "HAL/LDR/LDR.h"
#include "HAL/LCD/LCD_interface.h"
#include "HAL/TEMPSENSOR/TempSensor.h"
#include "APP/APP.h"
//#include "SERVICE/Scheduler.h"


void vApplicationStackOverflowHook(xTaskHandle *pxTask, signed char *pcTaskName)
{
    while(1);
}

 SemaphoreHandle_t sMutex;

int main(void)
{

    PORTS_Operation();
    Ultrasonic_Init();
    MotorInit();
    LcdInit();
    LDR_Init();
    TempInit();

    lcd_display_const_string();

    // Create the task
    while(DIO_Read(PORTF, P0));

    sMutex = xSemaphoreCreateMutex();

    xTaskCreate((TaskFunction_t)avoid_obstacles, "avoid_obstacles", configMINIMAL_STACK_SIZE + 200, NULL, 4, NULL);
    xTaskCreate((TaskFunction_t)lcd_display, "lcd_display", configMINIMAL_STACK_SIZE + 200, NULL, 3, NULL);
    xTaskCreate((TaskFunction_t)ldr_swing_car, "ldr_swing_car", configMINIMAL_STACK_SIZE + 200, NULL, 2, NULL);
    xTaskCreate((TaskFunction_t)button_check, "button_check", configMINIMAL_STACK_SIZE + 200, NULL, 1, NULL);

    // Start the FreeRTOS scheduler
    vTaskStartScheduler();



}
