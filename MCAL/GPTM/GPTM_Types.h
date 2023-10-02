#ifndef GPTM_TYPES_H__
#define GPTM_TYPES_H__

#include "LIB/types.h"

typedef struct{
    uint32 GPTMCFG; //00
    uint32 GPTMTAMR; //04
    uint32 GPTMTBMR;// 08
    uint32 GPTMCTL;//0C
    uint32 GPTMSYNC;//10
    uint32 RES;//14
    uint32 GPTMIMR;//18
    uint32 GPTMRIS;//1C
    uint32 GPTMMIS;//20
    uint32 GPTMICR;//24
    uint32 GPTMTAILR;//28
    uint32 GPTMTBILR;//2C
    uint32 GPTMTAMATCHR;//30
    uint32 GPTMTBMATCHR;//34
    uint32 GPTMTAPR;//38
    uint32 GPTMTBPR;
    uint32 GPTMTAPMR;
    uint32 GPTMTBPMR;
    uint32 GPTMTAR;
    uint32 GPTMTBR;
    uint32 GPTMTAV;
    uint32 GPTMTBV;
    uint32 GPTMRTCPD;
    uint32 GPTMTAPS;
    uint32 GPTMTBPS;
    uint32 GPTMTAPV;
    uint32 GPTMTBPV;
    uint32 GPTMPP;
}GPTMRegType;

typedef enum{
    NORMAL = 0,
    PWM
}TimerType;



#endif
