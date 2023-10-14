/********************************************************************************************/
/* Authors: Mohamed Gamal, Ehab Roushdy, Mohamed abelmoteleb, and Aya Yasser                */
/* Version: V01                                                                             */
/* Date: 10/09/2023                                                                         */
/* Description: General-Purpose Timer (GPTM) driver header                                 */
/********************************************************************************************/
#ifndef GPTM_H__
#define GPTM_H__

#include "GPTM_Types.h"
#include <stdbool.h>

#define F_CPU   16000000UL

#define TIMER0 ((volatile GPTMRegType *)0x40030000)
#define TIMER1 ((volatile GPTMRegType *)0x40031000)
#define TIMER2 ((volatile GPTMRegType *)0x40032000)
#define TIMER3 ((volatile GPTMRegType *)0x40033000)
#define TIMER4 ((volatile GPTMRegType *)0x40034000)
#define TIMER5 ((volatile GPTMRegType *)0x40035000)

#define WIDE_TIMER0 (((volatile GPTMRegType *)0x40036000))
#define WIDE_TIMER1 (((volatile GPTMRegType *)0x40037000))
#define WIDE_TIMER2 (((volatile GPTMRegType *)0x4004C000))
#define WIDE_TIMER3 (((volatile GPTMRegType *)0x4004D000))
#define WIDE_TIMER4 (((volatile GPTMRegType *)0x4004E000))
#define WIDE_TIMER5 (((volatile GPTMRegType *)0x4004F000))

#define TIMER_0     0U
#define TIMER_1     1U
#define TIMER_2     2U
#define TIMER_3     3U
#define TIMER_4     4U
#define TIMER_5     5U

#define WTIMER_0    6U
#define WTIMER_1    7U
#define WTIMER_2    8U
#define WTIMER_3    9U
#define WTIMER_4    10U
#define WTIMER_5    11U

/***************CONFIGS******************/
#define TIMER_MODE32   (0x00U)
#define TIMER_MODE16   (0x04U)

#define WTIMER_MODE32   (0x04U)
#define WTIMER_MODE64   (0x00U)

#define TIMER_RTC       (0x01U)
#define WTIMER_RTC      (0x01U)

#define TIMERA          (1U)
#define TIMERB          (2U)

/*****************MODES*******************/
#define TPLO           (1U << 11) /*GPTM Timer PWM Legacy Operation*/
#define TMRSU          (1U << 10) /*GPTM Timer Match Register Update*/

/*0 Update the GPTMTBMATCHR register and the GPTMTBPR
register, if used, on the next cycle.
1 Update the GPTMTBMATCHR register and the GPTMTBPR
register, if used, on the next timeout.
*/

#define TPWMIE         (1U << 9) /*GPTM Timer PWM Interrupt Enable*/
#define TILD           (1U << 8) /*GPTM Timer Interval Load Write*/

/*0 Update the GPTMTBR and GPTMTBV registers with the value
in the GPTMTBILR register on the next cycle. Also update the
GPTMTBPS and GPTMTBPV registers with the value in the
GPTMTBPR register on the next cycle.

1 Update the GPTMTBR and GPTMTBV registers with the value
in the GPTMTBILR register on the next timeout. Also update
the GPTMTBPS and GPTMTBPV registers with the value in
the GPTMTBPR register on the next timeout.
*/

#define TSNAPS         (1U << 7) /*GPTM Timer Snap-Shot Mode*/
#define TWOT           (1U << 6) /*GPTM Timer Wait-on-Trigger*/
#define TMIE           (1U << 5) /*GPTM Timer Match Interrupt Enable*/
#define TCDIR          (1U << 4) /*GPTM Timer Count Direction UP and DOWN*/
#define TAMS           (1U << 3) /*GPTM Timer Alternate Mode Select PWM*/
#define TCMR           (1U << 2) /*GPTM Timer Capture Mode*/
#define TMR_ONE_SHOT   (0x01) /*in TAMR or TBMR*/
#define TMR_PERIODIC   (0x02) /*in TAMR or TBMR*/
#define TMR_CAPTURE    (0x03) /*in TAMR or TBMR*/

/******************EVENTS********************/
#define POSITIVE_EDGE  (0x00U)
#define NEGATIVE_EDGE  (0x01U)
#define BOTH_EDGES     (0x03U)

/********************INTSCLR*****************/
#define TATOCINT       (1U << 0)
#define CAMCINT        (1U << 1)
#define CAECINT        (1U << 2)
#define RTCCINT        (1U << 3)
#define TAMCINT        (1U << 4)
#define TBTOCINT       (1U << 8)
#define CBMCINT        (1U << 9)
#define CBECINT        (1U << 10)
#define TBMCINT        (1U << 11)
#define WUECINT        (1U << 16)

/*********************INTS********************/
#define TATOIM         (1U << 0)
#define CAMIM          (1U << 1)
#define CAEIM          (1U << 2)
#define RTCIM          (1U << 3)
#define TAMIM          (1U << 4)
#define TBTOIM         (1U << 8)
#define CBMIM          (1U << 9)
#define CBEIM          (1U << 10)
#define TBMIM          (1U << 11)
#define WUEIM          (1U << 16)



#define NORMAL_MODE    (1U)
#define PWM_MODE       (2U)






/**********************************FUNC*********************************/


void TimerStartUse(uint32 TimerIndex);
void TimerConfigure (uint32 TimerIndex, uint32 ui32Timer, uint32 ui32Config, uint32 config);
void TimerControlEvent (uint32 TimerIndex, uint32 ui32Timer, uint32 ui32Event);
void TimerControlLevel (uint32 TimerIndex, uint32 ui32Timer, bool bInvert);
void TimerControlStall (uint32 TimerIndex, uint32 ui32Timer, bool bStall);
void TimerControlTrigger (uint32 TimerIndex, uint32 ui32Timer, bool bEnable);
void TimerControlWaitOnTrigger (uint32 TimerIndex, uint32 ui32Timer, bool bWait);
void TimerDisable (uint32 TimerIndex, uint32 ui32Timer);
void TimerEnable (uint32 TimerIndex, uint32 ui32Timer);
void TimerIntClear (uint32 TimerIndex, uint32 ui32IntFlags);
void TimerIntDisable (uint32 TimerIndex, uint32 ui32IntFlags);
void TimerIntEnable (uint32 TimerIndex, uint32 ui32IntFlags);
void TimerIntNVICEnable ();
void TimerIntRegister (uint32 TimerIndex, uint32 ui32Timer, void (*pfnHandler)(void));
uint32 TimerIntStatus (uint32 TimerIndex, uint32 ui32IntFlags);
uint32 TimerLoadGet (uint32 TimerIndex, uint32 ui32Timer);
uint64 TimerLoadGet64 (uint32 TimerIndex);
void TimerLoadSet (uint32 TimerIndex, uint32 ui32Timer, uint32 ui32Value);
void TimerLoadSet64 (uint32 TimerIndex, uint64 ui64Value);
uint32 TimerMatchGet (uint32 TimerIndex, uint32 ui32Timer);
uint64 TimerMatchGet64 (uint32 TimerIndex);
void TimerMatchSet (uint32 TimerIndex, uint32 ui32Timer, uint32 ui32Value);
void TimerMatchSet64 (uint32 TimerIndex, uint64 ui64Value);
uint32 TimerPrescaleGet (uint32 TimerIndex, uint32 ui32Timer);
uint32 TimerPrescaleMatchGet (uint32 TimerIndex, uint32 ui32Timer);
void TimerPrescaleMatchSet (uint32 TimerIndex, uint32 ui32Timer, uint32 ui32Value);
void TimerPrescaleSet (uint32 TimerIndex, uint32 ui32Timer, uint32 ui32Value);
void TimerRTCDisable (uint32 TimerIndex);
void TimerRTCEnable (uint32 TimerIndex);
void TimerSynchronize (uint32 TimerIndex, uint32 ui32Timers);
void TimerUpdateMode (uint32 TimerIndex, uint32 ui32Timer, uint32 ui32Config);
uint32 TimerValueGet (uint32 TimerIndex, uint32 ui32Timer);
uint64 TimerValueGet64 (uint32 TimerIndex);
uint8 GetEnBit(uint32 TimerIndex, uint32 ui32Timers);


#define SYSCTL_RCGCWTIMER_R     (*((volatile unsigned long *)0x400FE65C))
#define SYSCTL_RCGCTIMER_R      (*((volatile unsigned long *)0x400FE604))

#define NVIC_EN0              (((volatile uint32 *)0xE000E100))
#define NVIC_EN1              (((volatile uint32 *)0xE000E104))
#define NVIC_EN2              (((volatile uint32 *)0xE000E108))
#define NVIC_EN3              (((volatile uint32 *)0xE000E10C))
#define NVIC_EN4              (((volatile uint32 *)0xE000E110))


#endif
