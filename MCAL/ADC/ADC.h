#ifndef ADC_H__
#define ADC_H__

#include <stdbool.h>
#include "MCAL/ADC/ADC_Types.h"

#define SYSCTL_RCGCADC_R        (*((volatile unsigned long *)0x400FE638))

#define ADC0_Reg (((volatile ADC_RegType *)0x40038000))
#define ADC1_Reg (((volatile ADC_RegType *)0x40039000))

/*******************Active Sample Sequencer********************/

#define ASEN0 (1<<0)
#define ASEN1 (1<<1)
#define ASEN2 (1<<2)
#define ASEN3 (1<<3)
#define BUSY  (1<<16)

/****************************Int Mask*****************************/

#define MASK0 (1<<0)
#define MASK1 (1<<1)
#define MASK2 (1<<2)
#define MASK3 (1<<3)

#define DCONSS0 (1<<16)
#define DCONSS1 (1<<17)
#define DCONSS2 (1<<18)
#define DCONSS3 (1<<19)

/******************************Int Clr********************************/

#define IN0 (1<<0)
#define IN1 (1<<1)
#define IN2 (1<<2)
#define IN3 (1<<3)

/*******************************Event MUX****************************/

#define PROCESSOR (0x0U)
#define COMP0     (0x1U)
#define COMP1     (0x2U)
#define GPIOEX    (0x4U)
#define TIMER     (0x5U)
#define PWM0      (0x6U)
#define PWM1      (0x7U)
#define PWM2      (0x8U)
#define PWM3      (0x9U)
#define ALWAYS    (0xFU)
#define WHEN_REQUIRED (0x0U)

/*******************************PRIORITY******************************/

#define PR_0  (0x0U)
#define PR_1  (0x1U)
#define PR_2  (0x2U)
#define PR_3  (0x3U)

/******************************HW OverSampling*************************/

#define   NoHWSAMPLING  0x0
#define   HWSAMPLING2x  0x1
#define   HWSAMPLING4x  0x2
#define   HWSAMPLING8x  0x3
#define   HWSAMPLING16x 0x4
#define   HWSAMPLING32x 0x5
#define   HWSAMPLING64x 0x6

/******************************DIGITAL Comp clr********************************/

#define DCINT0  (1<<0) 
#define DCINT1  (1<<1)
#define DCINT2  (1<<2)
#define DCINT3  (1<<3)
#define DCINT4  (1<<4)
#define DCINT5  (1<<5)
#define DCINT6  (1<<6)
#define DCINT7  (1<<7)

/********************************Channels**********************************/

#define AIN0  (0U)  /*E3*/
#define AIN1  (1U)  /*E2*/
#define AIN2  (2U)  /*E1*/
#define AIN3  (3U)  /*E0*/
#define AIN4  (4U)  /*D3*/
#define AIN5  (5U)  /*D2*/
#define AIN6  (6U)  /*D1*/
#define AIN7  (7U)  /*D0*/
#define AIN8  (8U)  /*E5*/
#define AIN9  (9U)  /*E4*/
#define AIN10 (10U) /*B4*/
#define AIN11 (11U) /*B5*/

/********************************Sampler************************************/

#define SAMPLER0  (0U)
#define SAMPLER1  (1U)
#define SAMPLER2  (2U)
#define SAMPLER3  (3U)

/********************************ADC***************************/

#define ADC0 (0U)
#define ADC1 (1U)

#include <stdbool.h>

/*************************************FUNCS Prototypes*************************************/
bool ADCBusy (uint32 ui32ADC);

void ADCStartUse(uint32 ui32ADC);
void ADCInitSampler(uint32 ui32ADC, uint32 ui32Sampler, uint32 Event, uint32 ui32Channel); // ALWAYS
void ADCAssignChannel(uint32 ui32ADC, uint32 ui32Sampler, uint32 ui32Channel);
int32 ADCRead(uint32 ui32ADC, uint32 ui32Sampler);
void ADCTempEnable(uint32 ui32ADC, uint32 ui32Sampler);

void ADCIntClear (uint32 ui32ADC, uint32 ui32SequenceNum);
void ADCIntDisable (uint32 ui32ADC, uint32 ui32SequenceNum);
void ADCIntEnable (uint32 ui32ADC, uint32 ui32SequenceNum);
void ADCIntRegister (uint32 ui32ADC, uint32 ui32SequenceNum, void (*pfnHandler)(void));
uint32 ADCIntStatus (uint32 ui32ADC, uint32 ui32SequenceNum, bool bMasked);



#endif
