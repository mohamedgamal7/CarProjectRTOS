#include "HAL/LDR/LDR.h"

#define MIN_DIFFERENCE  250

int R1_DIFF = 0;
int R2_DIFF = 0;

void Calibrate (void){
    unsigned int R1=  ADCRead(ADC0, SAMPLER3);
    unsigned int R2 = ADCRead(ADC1, SAMPLER3);
    if (R1 > R2)
    {
        R1_DIFF= R1-R2;
    }
    else
    {
        R2_DIFF= R2-R1;
    }
}

void LDR_Init(void){
    ADCStartUse(ADC0);
    ADCInitSampler(ADC0, SAMPLER3, WHEN_REQUIRED, AIN0);

    ADCStartUse(ADC1);
    ADCInitSampler(ADC1, SAMPLER3, WHEN_REQUIRED, AIN1);

    Calibrate();
}

dirType LDR_Comp(int32 * difference)
{
    int32_t read1 = 0;
    int32_t read2 = 0;

    dirType retVal = STAY;

    read1 = ADCRead(ADC0, SAMPLER3);
    read2 = ADCRead(ADC1, SAMPLER3);

    if(((read2 - R2_DIFF) - (read1 - R1_DIFF))> MIN_DIFFERENCE)
    {
        retVal = RIGHT;
        *difference = ((read2 - R2_DIFF) - (read1 - R1_DIFF));
    }
    else if (((read1 - R1_DIFF) - (read2 - R2_DIFF))> MIN_DIFFERENCE)
    {
        retVal = LEFT;
        *difference = (read1 - R1_DIFF) - (read2 - R2_DIFF);
    }
    else if((read1 - R1_DIFF) - (read2 - R2_DIFF ) < MIN_DIFFERENCE)
    {
        retVal = STAY;
        *difference = (read1 - R1_DIFF) - (read2 - R2_DIFF );
    }
    else if((read2 - R2_DIFF) - (read1 - R1_DIFF) < MIN_DIFFERENCE)
    {
        retVal = STAY;
        *difference = (read2 - R2_DIFF) - (read1 - R1_DIFF);
    }
    return retVal;
}
