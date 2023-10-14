/********************************************************************************************/
/* Authors: Mohamed Gamal, Ehab Roushdy,Kareem hani and aya yasser                         */
/* Version: V01                                                                            */
/* Date: 19/08/2023                                                                        */
/* Description: ADC Functions Implementation                                                */
/********************************************************************************************/
#include "MCAL/ADC/ADC.h"

/* Define an array of pointers to ADC registers for ADC0 and ADC1. */
volatile ADC_RegType * ADCs[] = {ADC0_Reg, ADC1_Reg};

/* Initialize ADC module. */
void ADCStartUse(uint32 ui32ADC) {
    /* Enable the clock for the specified ADC module. */
    SYSCTL_RCGCADC_R |= (1 << ui32ADC);
    /* Wait until the clock is stable and ready for use. */
    while (!(SYSCTL_RCGCADC_R >> ui32ADC));
}

/* Initialize ADC sampler settings. */
void ADCInitSampler(uint32 ui32ADC, uint32 ui32Sampler, uint32 Event, uint32 ui32Channel) {
    /* Disable the specified sampler. */
    ADCs[ui32ADC]->ADCACTSS &= ~(1U << ui32Sampler);
    /* Set the trigger event for the sampler. */
    ADCs[ui32ADC]->ADCEMUX |= (Event << (ui32Sampler * 4));
    /* Enable interrupt for the specified sampler. */
    ADCs[ui32ADC]->ADCIM |= (1U << ui32Sampler);

    switch (ui32Sampler) {
        case 0:
            ADCs[ui32ADC]->ADCSSMUX0 |= ui32Channel;
            ADCs[ui32ADC]->ADCSSCTL0 |= 6;
            break;
        case 1:
            ADCs[ui32ADC]->ADCSSMUX1 |= ui32Channel;
            ADCs[ui32ADC]->ADCSSCTL1 |= 6;
            break;
        case 2:
            ADCs[ui32ADC]->ADCSSMUX2 |= ui32Channel;
            ADCs[ui32ADC]->ADCSSCTL2 |= 6;
            break;
        case 3:
            ADCs[ui32ADC]->ADCSSMUX3 |= ui32Channel;
            ADCs[ui32ADC]->ADCSSCTL3 |= 6;
            break;
    }

    /* Enable the specified sampler. */
    ADCs[ui32ADC]->ADCACTSS |= (1U << ui32Sampler);
}

/* Read ADC value from the specified sampler. */
int32 ADCRead(uint32 ui32ADC, uint32 ui32Sampler) {
    int32 retVal = 0;

    /* Initiate the specified sampler's conversion. */
    ADCs[ui32ADC]->ADCPSSI |= (1U << ui32Sampler);
    /* Wait for the conversion to complete. */
    while (!((ADCs[ui32ADC]->ADCRIS >> ui32Sampler) & 1));
    /* Clear the interrupt status bit. */
    ADCs[ui32ADC]->ADCISC |= (1U << ui32Sampler);

    /* Read the converted value based on the sampler. */
    switch (ui32Sampler) {
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

/* Enable temperature sensor on the specified sampler. */
void ADCTempEnable(uint32 ui32ADC, uint32 ui32Sampler) {
    switch (ui32Sampler) {
        case 0:
            ADCs[ui32ADC]->ADCSSCTL0 |= (1 << 3);
            break;
        case 1:
            ADCs[ui32ADC]->ADCSSCTL1 |= (1 << 3);
            break;
        case 2:
            ADCs[ui32ADC]->ADCSSCTL2 |= (1 << 3);
            break;
        case 3:
            ADCs[ui32ADC]->ADCSSCTL3 |= (1 << 3);
            break;
    }
}
