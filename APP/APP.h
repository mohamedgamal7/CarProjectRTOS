
#ifndef _APP_H
#define _APP_H

#include "LIB/Delay.h"

#include "MCAL/DIO/DIO.h"
#include "MCAL/SYSTICK/Systick.h"
#include "HAL/ULTRASONIC/ULTRASONIC_interface.h"
#include "HAL/MOTOR/Motor.h"
#include "HAL/LDR/LDR.h"
#include "HAL/LCD/LCD_interface.h"
#include "HAL/TEMPSENSOR/TempSensor.h"

#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"


#define LDR_PERIOD              100
#define LCD_PERIOD              200
#define TEMP_READ               300
#define ULTRASONIC_PERIOD       60
#define BUTTON_CHECK_PERIOD     80

typedef enum
{
    free_running,
    blocked_reverse,
    blocked_turning
} car_state;

//extern SemaphoreHandle_t sMutex;

void ldr_swing_car(void);
void lcd_display(void);
void avoid_obstacles(void);
void button_check(void);

void lcd_display_const_string(void);

#endif
