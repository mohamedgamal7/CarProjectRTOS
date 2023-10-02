/******************************************************************************
*
* [FILE NAME]: <Systick.h>
*
* [AUTHOR]: Teleb, Aya, Ehab, Jemy
*
* [DATE CREATED]: <09/09/2023>
*
* [DESCRIPTION]:
*
*******************************************************************************/


#ifndef SYSTICK_H__
#define SYSTICK_H__

#define SYSTIC_INT_PERIOD_MS    20

#define NVIC_ST_CTRL_R          (*((volatile unsigned long *)0xE000E010))
#define NVIC_ST_RELOAD_R        (*((volatile unsigned long *)0xE000E014))
#define NVIC_ST_CURRENT_R       (*((volatile unsigned long *)0xE000E018))

void Systick_Init(void);
void Systick_Set_ISR(void (*funcPtr)());

void Systick_off(void);


#endif
