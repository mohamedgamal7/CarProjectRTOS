/******************************************************************************
*
* [FILE NAME]: <Scheduler.h>
*
* [AUTHOR]: Teleb, Aya, Ehab, Jemy
*
* [DATE CREATED]: <09/09/2023>
*
* [DESCRIPTION]:
*
*******************************************************************************/

#ifndef SCHEDULER_H__
#define SCHEDULER_H__

#include "Scheduler_Types.h"
#include "MCAL/SYSTICK/Systick.h"
#include "HAL/MOTOR/Motor.h"
#include "HAL/LCD/LCD_interface.h"
#include "MCAL/DIO/DIO.h"
#include "LIB/types.h"

#define MAX_TASKS 10


void tasks_scheduler(void);
void create_task(void(*ptr)(), uint32_t period);

void Scheduler_ON(void);
void Scheduler_OFF(void);

#endif
