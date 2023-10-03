/*
 * Ultrasonic_Module.h
 *
 *  Created on: Oct 1, 2023
 *      Author: ERoshdy
 */

#ifndef APP_ULTRASONIC_MODULE_ULTRASONIC_MODULE_H_
#define APP_ULTRASONIC_MODULE_ULTRASONIC_MODULE_H_

#include <APP/APP_Config.h>
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
#include "queue.h"



#define ULTRASONIC_PERIOD       60




void avoid_obstacles(void);



#endif /* APP_ULTRASONIC_MODULE_ULTRASONIC_MODULE_H_ */
