#ifndef ADC_TYPES_H__
#define ADC_TYPES_H__

#include "LIB/types.h"

typedef struct{
    volatile uint32 ADCACTSS; // 00
    volatile uint32 ADCRIS; //04
    volatile uint32 ADCIM; //08
    volatile uint32 ADCISC; // 0c
    volatile uint32 ADCOSTAT; // 10
    volatile uint32 ADCEMUX; // 14
    volatile uint32 ADCUSTAT; //18
    volatile uint32 ADCTSSEL; //1c
    volatile uint32 ADCSSPRI; //20
    volatile uint32 ADCSPC; //24
    volatile uint32 ADCPSSI;//28
    volatile uint32 RES1;//2c
    volatile uint32 ADCSAC;//30
    volatile uint32 ADCDCISC;//34
    volatile uint32 ADCCTL;//38
    volatile uint32 RES2;//3c
    volatile uint32 ADCSSMUX0;//40
    volatile uint32 ADCSSCTL0;//44
    volatile uint32 ADCSSFIFO0;//48
    volatile uint32 ADCSSFSTAT0;//4c
    volatile uint32 ADCSSOP0;//50
    volatile uint32 ADCSSDC0;//54
    volatile uint32 RES3;//58
    volatile uint32 RES4;//5c
    volatile uint32 ADCSSMUX1; // 60
    volatile uint32 ADCSSCTL1; //64
    volatile uint32 ADCSSFIFO1; //68
    volatile uint32 ADCSSFSTAT1; // 6c
    volatile uint32 ADCSSOP1; //70
    volatile uint32 ADCSSDC1; //74
    volatile uint32 RES5; //78
    volatile uint32 RES6;//7c
    volatile uint32 ADCSSMUX2;//80
    volatile uint32 ADCSSCTL2;//84
    volatile uint32 ADCSSFIFO2;//88
    volatile uint32 ADCSSFSTAT2;//8c
    volatile uint32 ADCSSOP2;//90
    volatile uint32 ADCSSDC2;//94
    volatile uint32 RES[2];
    volatile uint32 ADCSSMUX3;//a0
    volatile uint32 ADCSSCTL3;//a4
    volatile uint32 ADCSSFIFO3;//a8
    volatile uint32 ADCSSFSTAT3;//ac
    volatile uint32 ADCSSOP3;//b0
    volatile uint32 ADCSSDC3;//b4
    volatile uint32 RESS[312];
    volatile uint32 ADCDCRIC;//d00
    volatile uint32 RESSS[63];
    volatile uint32 ADCDCCTL0;//e00
    volatile uint32 ADCDCCTL1;//e04
    volatile uint32 ADCDCCTL2;//e08
    volatile uint32 ADCDCCTL3;//e0c
    volatile uint32 ADCDCCTL4;//e10
    volatile uint32 ADCDCCTL5;//e14
    volatile uint32 ADCDCCTL6;//e18
    volatile uint32 ADCDCCTL7;//e1c
    volatile uint32 RESSSS[9];
    volatile uint32 ADCDCCMP0;//e40
    volatile uint32 ADCDCCMP1;//e44
    volatile uint32 ADCDCCMP2;//e48
    volatile uint32 ADCDCCMP3;//e4c
    volatile uint32 ADCDCCMP4;//e50
    volatile uint32 ADCDCCMP5;//e54
    volatile uint32 ADCDCCMP6;//e58
    volatile uint32 ADCDCCMP7;//e5c
    volatile uint32 RESSSSS[88];
    volatile uint32 ADCPP;//fc0
    volatile uint32 ADCPC;//fc4
    volatile uint32 ADCCC;//

}ADC_RegType;




#endif
