/******************************************************************************
*
* [FILE NAME]: <Scheduler_Types.h>
*
* [AUTHOR]: Teleb, Aya, Ehab, Jemy
*
* [DATE CREATED]: <09/09/2023>
*
* [DESCRIPTION]:
*
*******************************************************************************/

#ifndef  SHEDULER_TYPES_H__
#define  SHEDULER_TYPES_H__

#include <stdint.h>

typedef struct{
    void(*taskPtr)();
    uint32_t period;
    uint32_t delay;

}TCB_Type;


#endif
