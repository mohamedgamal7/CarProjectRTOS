// Include necessary TivaWare and FreeRTOS headers
#include <APP/APP_Config.h>
#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "inc/hw_can.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
#include "driverlib/can.h"

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

#include "APP/LDR_Module/ldr_module.h"
#include "APP/BUTTONS_Module/Buttons.h"
#include "App/TEMP_Module/temperature.h"
#include "APP/DISPLAY_Module/display.h"
#include "APP/ULTRASONIC_Module/Ultrasonic_Module.h"
#include "APP/INIT_module/TasksInitiation.h"


void CanHandler(void)
{
    uint32_t Status;
    Status = CANIntStatus(CAN0_BASE, CAN_INT_STS_CAUSE);

    if(Status == CAN_INT_INTID_STATUS)
    {
        Status = CANStatusGet(CAN0_BASE, CAN_STS_CONTROL);
    }
    else if(Status == 1)
    {
        CANIntClear(CAN0_BASE, Status);
        SysCtlReset();
    }
}


void vApplicationStackOverflowHook(xTaskHandle *pxTask, signed char *pcTaskName)
{
    while (1);
}

QueueHandle_t MBXcurrunt_state;
QueueHandle_t MBXLDR_reading;
QueueHandle_t MBXReading_differece;
QueueHandle_t MBXtemperature_reading;
QueueHandle_t MBXstart_tick;

int main(void)
{

    MBXcurrunt_state = xQueueCreate(1, sizeof(car_state));
    MBXLDR_reading = xQueueCreate(1, sizeof(dirType));
    MBXReading_differece = xQueueCreate(1, sizeof(int32_t));
    MBXtemperature_reading = xQueueCreate(1, sizeof(uint32_t));
    MBXstart_tick = xQueueCreate(1, sizeof(uint32_t));

    car_state CAR_initial_state = free_running;
    dirType LDR_initial_direction = STAY;
    int32_t LDR_initial_Reading_differece = 0;
    uint32_t temperature_initial_reading = 0;
    uint32_t start_tick_initial = 0;

    xQueueOverwrite(MBXcurrunt_state, &CAR_initial_state);
    xQueueOverwrite(MBXLDR_reading, &LDR_initial_direction);
    xQueueOverwrite(MBXReading_differece, &LDR_initial_Reading_differece);
    xQueueOverwrite(MBXtemperature_reading, &temperature_initial_reading);
    xQueueOverwrite(MBXstart_tick, &start_tick_initial);

    xTaskCreate((TaskFunction_t)APP_Init, "Initialization", configMINIMAL_STACK_SIZE + 200, NULL, 10, NULL);
    xTaskCreate((TaskFunction_t)avoid_obstacles, "avoid_obstacles", configMINIMAL_STACK_SIZE + 200, NULL, 5, NULL);
    xTaskCreate((TaskFunction_t)lcd_display, "lcd_display", configMINIMAL_STACK_SIZE + 200, NULL, 4, NULL);
    xTaskCreate((TaskFunction_t)ldr_swing_car, "ldr_swing_car", configMINIMAL_STACK_SIZE + 200, NULL, 3, NULL);
    xTaskCreate((TaskFunction_t)button_check, "button_check", configMINIMAL_STACK_SIZE + 200, NULL, 2, NULL);
    xTaskCreate((TaskFunction_t)Read_temperature, "Read_temprature", configMINIMAL_STACK_SIZE + 200, NULL, 1, NULL);

    // Start the FreeRTOS scheduler
    vTaskStartScheduler();
}
