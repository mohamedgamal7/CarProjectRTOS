/*
 * TasksInitiation.c
 *
 *  Created on: Oct 2, 2023
 *      Author: Kareem Hani
 */
/* This file is made for the Initialization of the needed modules */

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

extern QueueHandle_t MBXstart_tick;


void APP_Init(void)
{  uint32_t tick_count;
    while(1)
    {

    PORTS_Operation();
    Ultrasonic_Init();
    MotorInit();
    LcdInit();
    LDR_Init();
    TempInit();
    while(DIO_Read(PORTF, P0));
    tick_count = xTaskGetTickCount();
    xQueueOverwrite( MBXstart_tick, &tick_count );
    vTaskSuspend(NULL);
    }
}





