/******************************************************************************
*
* [FILE NAME]: <Scheduler.c>
*
* [AUTHOR]: Teleb, Aya, Ehab, Jemy
*
* [DATE CREATED]: <09/09/2023>
*
* [DESCRIPTION]:
*
*******************************************************************************/
#include "Scheduler.h"

TCB_Type Tasks[MAX_TASKS];
static uint32_t taskCount = 0;
volatile uint32_t ticksCount = 0;
static void reset_delays(void);


/************************************************************************************
* Service Name: create_task
* Sync/Async: -
* Reentrancy: -
* Parameters (in): ptr, period
* Parameters (inout): -
* Parameters (out): -
* Return value: -
* Description: -
************************************************************************************/
void create_task(void(*ptr)(), uint32_t period){
    if(taskCount < MAX_TASKS){
        Tasks[taskCount].taskPtr = ptr;
        Tasks[taskCount].period = period;
        Tasks[taskCount].delay = period;
        taskCount++;
    }
}


/************************************************************************************
* Service Name: ScheduleFunc
* Sync/Async: -
* Reentrancy: -
* Parameters (in): -
* Parameters (inout): -
* Parameters (out): -
* Return value: -
* Description: -
************************************************************************************/
void ScheduleFunc(void){
    ticksCount++;
    uint32_t i;
    for (i = 0; i < taskCount; i++){
        if (Tasks[i].taskPtr != 0x00){
            Tasks[i].delay -= SYSTIC_INT_PERIOD_MS;
            if (Tasks[i].delay == 0){
                Tasks[i].taskPtr();
                Tasks[i].delay = Tasks[i].period;
            }
        }
    }
}

/************************************************************************************
* Service Name: tasks_scheduler
* Sync/Async: -
* Reentrancy: -
* Parameters (in): -
* Parameters (inout): -
* Parameters (out): -
* Return value: -
* Description: -
************************************************************************************/
void tasks_scheduler(void)
{
    Systick_Set_ISR(ScheduleFunc);
    while(1)
    {
        if(!DIO_Read(PORTF, P0)) /* start */
        {
            Scheduler_ON();
            reset_delays();
            Calibrate();
            ticksCount = 0;
        }
        else if(!DIO_Read(PORTF, P4) || (ticksCount * SYSTIC_INT_PERIOD_MS / 1000) >= 60) /* stop */
        {
            Scheduler_OFF();
            MotorStop();
        }
    }
}


void Scheduler_ON(void){

    Systick_Init();

}

void Scheduler_OFF(void){
    Systick_off();
}

static void reset_delays(void)
{
    uint8 i = 0;
    for (i = 0; i < taskCount; i++)
    {
        Tasks[i].delay = Tasks[i].period;
    }
}
