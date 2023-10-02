/*
 * Ultrasonic_Module.h
 *
 *  Created on: Oct 1, 2023
 *      Author: ERoshdy
 */

#ifndef APP_ULTRASONIC_MODULE_ULTRASONIC_MODULE_H_
#define APP_ULTRASONIC_MODULE_ULTRASONIC_MODULE_H_

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
#include "APP/APP.h"

extern car_state currunt_state;
extern dirType LDR_reading;
extern int32  Reading_differece;





#endif /* APP_ULTRASONIC_MODULE_ULTRASONIC_MODULE_H_ */
