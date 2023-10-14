#include "TempSensor.h"



void TempInit(void)
{

    ADCStartUse(ADC0);
    ADCInitSampler(ADC0, SAMPLER2, WHEN_REQUIRED, AIN8 /*TSCHANNEL*/);
    ADCTempEnable(ADC0, SAMPLER2);
}

unsigned int TempRead(void){
    uint32_t Temp = 0;
    Temp = ADCRead(ADC0, SAMPLER2);
    Temp = 147.5 - ((75 * 3.3 * Temp) / 4096);

    return Temp;
}
