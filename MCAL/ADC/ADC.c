#include "MCAL/ADC/ADC.h"

volatile ADC_RegType * ADCs[] = {ADC0_Reg, ADC1_Reg};

void ADCStartUse(uint32 ui32ADC){
    SYSCTL_RCGCADC_R |= (1<<ui32ADC);
    while(!(SYSCTL_RCGCADC_R >> ui32ADC));
}

void ADCInitSampler(uint32 ui32ADC, uint32 ui32Sampler, uint32 Event, uint32 ui32Channel){
    ADCs[ui32ADC]->ADCACTSS &=~ (1U << ui32Sampler);
    ADCs[ui32ADC]->ADCEMUX |= (Event << (ui32Sampler*4));
    ADCs[ui32ADC]->ADCIM |=  (1U << ui32Sampler);

    switch(ui32Sampler)
    {
    case 0:
        ADCs[ui32ADC]->ADCSSMUX0 |= ui32Channel;
        ADCs[ui32ADC]->ADCSSCTL0 |= 6; //for now
        break;
    case 1:
        ADCs[ui32ADC]->ADCSSMUX1 |= ui32Channel;
        ADCs[ui32ADC]->ADCSSCTL1 |= 6; //for now
        break;
    case 2:
        ADCs[ui32ADC]->ADCSSMUX2 |= ui32Channel;
        ADCs[ui32ADC]->ADCSSCTL2 |= 6; //for now
        break;
    case 3:
        ADCs[ui32ADC]->ADCSSMUX3 |= ui32Channel;
        ADCs[ui32ADC]->ADCSSCTL3 |= 6; //for now
        break;
    }

    ADCs[ui32ADC]->ADCACTSS |= (1U << ui32Sampler);


}

int32 ADCRead(uint32 ui32ADC, uint32 ui32Sampler){
    int32 retVal = 0;

    ADCs[ui32ADC]->ADCPSSI |= (1U << ui32Sampler);
    while(!(ADCs[ui32ADC]->ADCRIS >> ui32Sampler) & 1);
    ADCs[ui32ADC]->ADCISC |= (1U << ui32Sampler);

    switch(ui32Sampler){
    case 0:
        retVal = ADCs[ui32ADC]->ADCSSFIFO0;
        break;
    case 1:
        retVal = ADCs[ui32ADC]->ADCSSFIFO1;
        break;
    case 2:
        retVal = ADCs[ui32ADC]->ADCSSFIFO2;
        break;
    case 3:
        retVal = ADCs[ui32ADC]->ADCSSFIFO3;
        break;
    }
    return retVal;
}

void ADCTempEnable(uint32 ui32ADC, uint32 ui32Sampler)
{
    switch(ui32Sampler){
        case 0:
            ADCs[ui32ADC]->ADCSSCTL0 |= (1 << 3); //for now
            break;
        case 1:
            ADCs[ui32ADC]->ADCSSCTL1 |= (1 << 3); //for now
            break;
        case 2:
            ADCs[ui32ADC]->ADCSSCTL2 |= (1 << 3); //for now
            break;
        case 3:
            ADCs[ui32ADC]->ADCSSCTL3 |= (1 << 3); //for now
            break;
        }

}
