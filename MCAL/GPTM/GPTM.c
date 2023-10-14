/********************************************************************************************/
/* Authors: Mohamed Gamal, Ehab Roushdy, Mohamed abelmoteleb, and Aya Yasser                */
/* Version: V01                                                                             */
/* Date: 10/09/2023                                                                         */
/* Description: General-Purpose Timer (GPTM) driver program                                 */
/********************************************************************************************/
#include "GPTM.h"


volatile GPTMRegType* TIMERS[] = {TIMER0, TIMER1, TIMER2, TIMER3, TIMER4, TIMER5, WIDE_TIMER0, WIDE_TIMER1, WIDE_TIMER2, WIDE_TIMER3, WIDE_TIMER4, WIDE_TIMER5};
volatile uint32 * NVIC_RegPtr[] = {NVIC_EN0, NVIC_EN1, NVIC_EN2, NVIC_EN3, NVIC_EN4};

void (*TimersISR_ptr[24])(void);

void TimerStartUse(uint32 TimerIndex){
    if(TimerIndex < WTIMER_0){
        SYSCTL_RCGCTIMER_R |= (1 << TimerIndex);
    }else{
        SYSCTL_RCGCWTIMER_R |= (1 << (TimerIndex - WTIMER_0));
    }
}


void TimerConfigure (uint32 TimerIndex, uint32 ui32Timer, uint32 ui32Config, uint32 config){
    TIMERS[TimerIndex]->GPTMCFG = ui32Config;
    if(ui32Timer == TIMERA){
        TIMERS[TimerIndex]->GPTMTAMR = config;
    }else{
        TIMERS[TimerIndex]->GPTMTBMR = config;
    }

}

void TimerControlEvent (uint32 TimerIndex, uint32 ui32Timer, uint32 ui32Event){
    if(TIMERS[TimerIndex]->GPTMCFG == 0x00U){
        TIMERS[TimerIndex]->GPTMCTL &=(~ (0x03U << 2));
        TIMERS[TimerIndex]->GPTMCTL |= (ui32Event << 2);
    }else{
        if(ui32Timer == TIMERA){
            TIMERS[TimerIndex]->GPTMCTL &=~ (0x03 << 2);
            TIMERS[TimerIndex]->GPTMCTL |= (ui32Event << 2);
        }else if(ui32Timer == TIMERB){
            TIMERS[TimerIndex]->GPTMCTL &=~ (0x03 << 10);
            TIMERS[TimerIndex]->GPTMCTL |= (ui32Event << 10);
        }
    }
}

void TimerControlLevel (uint32 TimerIndex, uint32 ui32Timer, bool bInvert){
    if(TIMERS[TimerIndex]->GPTMCFG == 0x00U){
        TIMERS[TimerIndex]->GPTMCTL &=~ (1 << 6);
        TIMERS[TimerIndex]->GPTMCTL |= (bInvert << 6);
    }else{
        if(ui32Timer == TIMERA){
            TIMERS[TimerIndex]->GPTMCTL &=~ (1 << 6);
            TIMERS[TimerIndex]->GPTMCTL |= (bInvert << 6);
        }else if(ui32Timer == TIMERB){
            TIMERS[TimerIndex]->GPTMCTL &=~ (1 << 14);
            TIMERS[TimerIndex]->GPTMCTL |= (bInvert << 14);
        }
    }
}

void TimerControlStall (uint32 TimerIndex, uint32 ui32Timer, bool bStall){
    if(TIMERS[TimerIndex]->GPTMCFG == 0x00U){
        TIMERS[TimerIndex]->GPTMCTL &=~ (1 << 1);
        TIMERS[TimerIndex]->GPTMCTL |= (bStall << 1);
    }else{
        if(ui32Timer == TIMERA){
            TIMERS[TimerIndex]->GPTMCTL &=~ (1 << 1);
            TIMERS[TimerIndex]->GPTMCTL |= (bStall << 1);
        }else if(ui32Timer == TIMERB){
            TIMERS[TimerIndex]->GPTMCTL &=~ (1 << 9);
            TIMERS[TimerIndex]->GPTMCTL |= (bStall << 9);
        }
    }
}

void TimerControlTrigger (uint32 TimerIndex, uint32 ui32Timer, bool bEnable){
    if(TIMERS[TimerIndex]->GPTMCFG == 0x00U){
        TIMERS[TimerIndex]->GPTMCTL &=~ (1 << 5);
        TIMERS[TimerIndex]->GPTMCTL |= (bEnable << 5);
    }else{
        if(ui32Timer == TIMERA){
            TIMERS[TimerIndex]->GPTMCTL &=~ (1 << 5);
            TIMERS[TimerIndex]->GPTMCTL |= (bEnable << 5);
        }else if(ui32Timer == TIMERB){
            TIMERS[TimerIndex]->GPTMCTL &=~ (1 << 13);
            TIMERS[TimerIndex]->GPTMCTL |= (bEnable << 13);
        }
    }
}

void TimerControlWaitOnTrigger (uint32 TimerIndex, uint32 ui32Timer, bool bWait){
    if(TIMERS[TimerIndex]->GPTMCFG == 0x00U){
        TIMERS[TimerIndex]->GPTMTAMR &=~ (1 << 6);
        TIMERS[TimerIndex]->GPTMTAMR |= (bWait << 6);
    }else{
        if(ui32Timer == TIMERA){
            TIMERS[TimerIndex]->GPTMTAMR &=~ (1 << 6);
            TIMERS[TimerIndex]->GPTMTAMR |= (bWait << 6);
        }else if(ui32Timer == TIMERB){
            TIMERS[TimerIndex]->GPTMTBMR &=~ (1 << 6);
            TIMERS[TimerIndex]->GPTMTBMR |= (bWait << 6);
        }
    }
}

void TimerDisable (uint32 TimerIndex, uint32 ui32Timer){
    if(TIMERS[TimerIndex]->GPTMCFG == 0x00U){
        TIMERS[TimerIndex]->GPTMCTL &=~ (1 << 0);
    }else{
        if(ui32Timer == TIMERA){
            TIMERS[TimerIndex]->GPTMCTL &=~ (1 << 0);
        }else if(ui32Timer == TIMERB){
            TIMERS[TimerIndex]->GPTMCTL &=~ (1 << 8);
        }
    }
}

void TimerEnable (uint32 TimerIndex, uint32 ui32Timer){
    if(TIMERS[TimerIndex]->GPTMCFG == 0x00U){
        TIMERS[TimerIndex]->GPTMCTL |= (1 << 0);
    }else{
        if(ui32Timer == TIMERA){
            TIMERS[TimerIndex]->GPTMCTL |= (1 << 0);
        }else if(ui32Timer == TIMERB){
            TIMERS[TimerIndex]->GPTMCTL |= (1 << 8);
        }
    }
}


void TimerIntClear (uint32 TimerIndex, uint32 ui32IntFlags){
    TIMERS[TimerIndex]->GPTMICR = ui32IntFlags;
}


void TimerIntDisable (uint32 TimerIndex, uint32 ui32IntFlags){
    TIMERS[TimerIndex]->GPTMIMR &=~ ui32IntFlags;
}


void TimerIntEnable (uint32 TimerIndex, uint32 ui32IntFlags){
    TIMERS[TimerIndex]->GPTMIMR |= ui32IntFlags;
}

void TimerIntNVICEnable(){
    *NVIC_RegPtr[0] |= (1U << 19);
}

void TimerIntRegister (uint32 TimerIndex, uint32 ui32Timer, void (*pfnHandler)(void)){
    if(TIMERS[TimerIndex]->GPTMCFG == 0x00U){
        TimersISR_ptr[TimerIndex] = pfnHandler;
    }else{
        if(ui32Timer == TIMERA){
            TimersISR_ptr[TimerIndex] = pfnHandler;
        }else if(ui32Timer == TIMERB){
            TimersISR_ptr[TimerIndex + 12] = pfnHandler;
        }
    }
}

uint32 TimerIntStatus (uint32 TimerIndex, uint32 ui32IntFlags){
    return (TIMERS[TimerIndex]->GPTMRIS & ui32IntFlags);
}

uint32 TimerLoadGet (uint32 TimerIndex, uint32 ui32Timer){
    if(TIMERS[TimerIndex]->GPTMCFG == 0x00U){
        return(TIMERS[TimerIndex]->GPTMTAILR);
    }else{
        if(ui32Timer == TIMERA){
            return(TIMERS[TimerIndex]->GPTMTAILR);
        }else if(ui32Timer == TIMERB){
            return(TIMERS[TimerIndex]->GPTMTBILR);
        }
    }
    return 0;
}


uint64 TimerLoadGet64 (uint32 TimerIndex){
    uint64 l_retVal = 0;
    if(TimerIndex < WTIMER_0){
        return 0;
    }
    l_retVal = TIMERS[TimerIndex]->GPTMTAILR;
    l_retVal |= ((TIMERS[TimerIndex]->GPTMTBILR & 0xFFFF) << 31) << 1;
    return l_retVal;
}


void TimerLoadSet (uint32 TimerIndex, uint32 ui32Timer, uint32 ui32Value){
    if(TIMERS[TimerIndex]->GPTMCFG == 0x00U){
        TIMERS[TimerIndex]->GPTMTAILR = ui32Value;
    }else{
        if(ui32Timer == TIMERA){
            TIMERS[TimerIndex]->GPTMTAILR = ui32Value;
        }else if(ui32Timer == TIMERB){
            TIMERS[TimerIndex]->GPTMTBILR = ui32Value;
        }
    }
}


void TimerLoadSet64 (uint32 TimerIndex, uint64 ui64Value){
    if(TimerIndex < WTIMER_0){
        return;
    }
    TIMERS[TimerIndex]->GPTMTAILR = ui64Value & 0xFFFF;
    TIMERS[TimerIndex]->GPTMTBILR = ((ui64Value & 0xFFFF0000) >> 31) >> 1 ;
}

uint32 TimerMatchGet (uint32 TimerIndex, uint32 ui32Timer){
    if(TIMERS[ui32Timer]->GPTMCFG == 0x00U){
        return (TIMERS[TimerIndex]->GPTMTAMATCHR);
    }else{
        if(ui32Timer == TIMERA){
            return (TIMERS[TimerIndex]->GPTMTAMATCHR);
        }else if(ui32Timer == TIMERB){
            return (TIMERS[TimerIndex]->GPTMTBMATCHR);
        }
    }
    return 0;
}

uint64 TimerMatchGet64 (uint32 TimerIndex){
    if(TimerIndex < WTIMER_0){
        return 0;
    }
    uint64 l_retVal = 0;
    l_retVal = TIMERS[TimerIndex]->GPTMTAMATCHR & 0xFFFF;
    l_retVal |= ((TIMERS[TimerIndex]->GPTMTAMATCHR & 0xFFFF) << 31) << 1;
    return l_retVal;
}

void TimerMatchSet (uint32 TimerIndex, uint32 ui32Timer, uint32 ui32Value){
    if(TIMERS[ui32Timer]->GPTMCFG == 0x00U){
        TIMERS[TimerIndex]->GPTMTAMATCHR = ui32Value;
    }else{
        if(ui32Timer == TIMERA){
            TIMERS[TimerIndex]->GPTMTAMATCHR = ui32Value;
        }else{
            TIMERS[TimerIndex]->GPTMTBMATCHR = ui32Value;
        }
    }
}

void TimerMatchSet64 (uint32 TimerIndex, uint64 ui64Value){
    TIMERS[TimerIndex]->GPTMTAMATCHR = ui64Value & 0xFFFF;
    TIMERS[TimerIndex]->GPTMTBMATCHR = ((ui64Value & 0xFFFF0000) >> 31) >> 1;
}

uint32 TimerPrescaleGet (uint32 TimerIndex, uint32 ui32Timer){
    if(TIMERS[ui32Timer]->GPTMCFG == 0x00U){
        return(TIMERS[TimerIndex]->GPTMTAPR);
    }else{
        if(ui32Timer == TIMERA){
            return(TIMERS[TimerIndex]->GPTMTAPR);
        }else{
            return(TIMERS[TimerIndex]->GPTMTBPR);
        }
    }
    //return 0;
}

uint32 TimerPrescaleMatchGet (uint32 TimerIndex, uint32 ui32Timer){
    if(TIMERS[ui32Timer]->GPTMCFG == 0x00U){
        return(TIMERS[TimerIndex]->GPTMTAPMR);
    }else{
        if(ui32Timer == TIMERA){
            return(TIMERS[TimerIndex]->GPTMTAPMR);
        }else{
            return(TIMERS[TimerIndex]->GPTMTBPMR);
        }
    }
    //return 0;
}

void TimerPrescaleMatchSet (uint32 TimerIndex, uint32 ui32Timer, uint32 ui32Value){
    if(TIMERS[ui32Timer]->GPTMCFG == 0x00U){
        TIMERS[TimerIndex]->GPTMTAPMR = ui32Value;
    }else{
        if(ui32Timer == TIMERA){
            TIMERS[TimerIndex]->GPTMTAPMR = ui32Value;
        }else{
            TIMERS[TimerIndex]->GPTMTBPMR = ui32Value;
        }
    }
}

void TimerPrescaleSet (uint32 TimerIndex, uint32 ui32Timer, uint32 ui32Value){
    if(TIMERS[TimerIndex]->GPTMCFG == 0x00U){
        TIMERS[TimerIndex]->GPTMTAPR = ui32Value;
    }else{
        if(ui32Timer == TIMERA){
            TIMERS[TimerIndex]->GPTMTAPR = ui32Value;
        }else{
            TIMERS[TimerIndex]->GPTMTAPR = ui32Value;
        }
    }
}

//void TimerRTCDisable (uint32 TimerIndex);
//void TimerRTCEnable (uint32 TimerIndex);
//void TimerSynchronize (uint32 TimerIndex, uint32 ui32Timers);
//void TimerUpdateMode (uint32 TimerIndex, uint32 ui32Timer, uint32 ui32Config);

uint32 TimerValueGet (uint32 TimerIndex, uint32 ui32Timer){
    if(TIMERS[TimerIndex]->GPTMCFG == 0x00U){
        return(TIMERS[TimerIndex]->GPTMTAPR);
    }else{
        if(ui32Timer == TIMERA){
            return(TIMERS[TimerIndex]->GPTMTAR);
        }else{
            return(TIMERS[TimerIndex]->GPTMTBR);
        }
    }
    //return 0;
}

uint64 TimerValueGet64 (uint32 TimerIndex){
    uint64 l_retVal = 0;
    l_retVal = TIMERS[TimerIndex]->GPTMTAPR & 0xFFFF;
    l_retVal |= ((TIMERS[TimerIndex]->GPTMTAPR & 0xFFFF) << 31) << 1;
    return l_retVal;
}

uint8 GetEnBit(uint32 TimerIndex, uint32 ui32Timers){
    if(TIMERS[TimerIndex]->GPTMCFG == 0x00U){
        return(TIMERS[TimerIndex]->GPTMCTL & 1);
    }else{
        if(ui32Timers == TIMERA){
            return(TIMERS[TimerIndex]->GPTMCTL & 1);
        }else{
            return((TIMERS[TimerIndex]->GPTMCTL >> 8) & 1);
        }
    }
}

void Timer0AISR(void){
    TimersISR_ptr[0]();
}
void Timer0BISR(void){
    TimersISR_ptr[12]();
}
void Timer1AISR(void){
    TimersISR_ptr[1]();
}
void Timer1BISR(void){
    TimersISR_ptr[13]();
}
void Timer2AISR(void){
    TimersISR_ptr[2]();
}
void Timer2BISR(void){
    TimersISR_ptr[14]();
}
void Timer3AISR(void){
    TimersISR_ptr[3]();
}
void Timer3BISR(void){
    TimersISR_ptr[15]();
}
void Timer4AISR(void){
    TimersISR_ptr[4]();
}
void Timer4BISR(void){
    TimersISR_ptr[16]();
}
void Timer5AISR(void){
    TimersISR_ptr[5]();
}
void Timer5BISR(void){
    TimersISR_ptr[17]();
}


void WTimer0AISR(void){
    TimersISR_ptr[6]();
}
void WTimer0BISR(void){
    TimersISR_ptr[18]();
}
void WTimer1AISR(void){
    TimersISR_ptr[7]();
}
void WTimer1BISR(void){
    TimersISR_ptr[19]();
}
void WTimer2AISR(void){
    TimersISR_ptr[8]();
}
void WTimer2BISR(void){
    TimersISR_ptr[20]();
}
void WTimer3AISR(void){
    TimersISR_ptr[9]();
}
void WTimer3BISR(void){
    TimersISR_ptr[21]();
}
void WTimer4AISR(void){
    TimersISR_ptr[10]();
}
void WTimer4BISR(void){
    TimersISR_ptr[22]();
}
void WTimer5AISR(void){
    TimersISR_ptr[11]();
}
void WTimer5BISR(void){
    TimersISR_ptr[23]();
}
