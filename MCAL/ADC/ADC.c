#include "MCAL/ADC/ADC.h"

// Array to hold ADC register structures
volatile ADC_RegType * ADCs[] = {ADC0_Reg, ADC1_Reg};

// Function to enable the specified ADC
void ADCStartUse(uint32 ui32ADC) {
    SYSCTL_RCGCADC_R |= (1 << ui32ADC);
    while (!(SYSCTL_RCGCADC_R >> ui32ADC));
}

// Function to initialize an ADC sampler
void ADCInitSampler(uint32 ui32ADC, uint32 ui32Sampler, uint32 Event, uint32 ui32Channel) {
    // Disable the sampler
    ADCs[ui32ADC]->ADCACTSS &= ~(1U << ui32Sampler);

    // Set the event for the sampler
    ADCs[ui32ADC]->ADCEMUX |= (Event << (ui32Sampler * 4));

    // Enable the interrupt for the sampler
    ADCs[ui32ADC]->ADCIM |= (1U << ui32Sampler);

    // Configure the channel and control for the sampler
    switch (ui32Sampler) {
    case 0:
        ADCs[ui32ADC]->ADCSSMUX0 |= ui32Channel;
        ADCs[ui32ADC]->ADCSSCTL0 |= 6; // For now
        break;
    case 1:
        ADCs[ui32ADC]->ADCSSMUX1 |= ui32Channel;
        ADCs[ui32ADC]->ADCSSCTL1 |= 6; // For now
        break;
    case 2:
        ADCs[ui32ADC]->ADCSSMUX2 |= ui32Channel;
        ADCs[ui32ADC]->ADCSSCTL2 |= 6; // For now
        break;
    case 3:
        ADCs[ui32ADC]->ADCSSMUX3 |= ui32Channel;
        ADCs[ui32ADC]->ADCSSCTL3 |= 6; // For now
        break;
    }

    // Enable the sampler
    ADCs[ui32ADC]->ADCACTSS |= (1U << ui32Sampler);
}

// Function to read the result of a sampler
int32 ADCRead(uint32 ui32ADC, uint32 ui32Sampler) {
    int32 retVal = 0;

    // Initiate the sample sequence
    ADCs[ui32ADC]->ADCPSSI |= (1U << ui32Sampler);

    // Wait until the conversion is complete
    while (!((ADCs[ui32ADC]->ADCRIS >> ui32Sampler) & 1));

    // Clear the interrupt status
    ADCs[ui32ADC]->ADCISC |= (1U << ui32Sampler);

    // Read the result based on the sampler
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

// Function to enable the temperature sensor for a sampler
void ADCTempEnable(uint32 ui32ADC, uint32 ui32Sampler) {
    switch (ui32Sampler) {
    case 0:
        ADCs[ui32ADC]->ADCSSCTL0 |= (1 << 3); // For now
        break;
    case 1:
        ADCs[ui32ADC]->ADCSSCTL1 |= (1 << 3); // For now
        break;
    case 2:
        ADCs[ui32ADC]->ADCSSCTL2 |= (1 << 3); // For now
        break;
    case 3:
        ADCs[ui32ADC]->ADCSSCTL3 |= (1 << 3); // For now
        break;
    }
}
