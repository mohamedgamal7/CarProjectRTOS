/********************************************************************************************/
/* Authors: Mohamed Gamal, Ehab Roushdy, Ahmed Maher and Kareem Hany                        */
/* Version: V01                                                                             */
/* Date: 10/09/2023                                                                         */
/* Description: LDR Driver Program                                                          */
/********************************************************************************************/

#include "HAL/LDR/LDR.h"

#define MIN_DIFFERENCE  250

int R1_DIFF = 0;
int R2_DIFF = 0;

/* Calibrates the LDR readings by computing the difference between two readings. */
void Calibrate (void) {
    unsigned int R1 = ADCRead(ADC0, SAMPLER3);
    unsigned int R2 = ADCRead(ADC1, SAMPLER3);

    if (R1 > R2) {
        R1_DIFF = R1 - R2;
    }
    else {
        R2_DIFF = R2 - R1;
    }
}


/* Initializes the LDR module by configuring ADC and performing calibration. */
void LDR_Init(void){
    /*clock gate the adc*/
    ADCStartUse(ADC0);
    /*use sequencer 3 and channel 0*/
    ADCInitSampler(ADC0, SAMPLER3, WHEN_REQUIRED, AIN0);
    /*use sequencer 3 and channel 1*/
    ADCStartUse(ADC1);
    ADCInitSampler(ADC1, SAMPLER3, WHEN_REQUIRED, AIN1);
    Calibrate();

}



/* Compares LDR readings and returns the direction based on the difference. */
dirType LDR_Comp(int32 * difference) {
    int32_t read1 = 0; /* Initialize read1 to zero. */
    int32_t read2 = 0; /* Initialize read2 to zero. */
    dirType retVal = STAY; /* Initialize retVal to STAY. */

    read1 = ADCRead(ADC0, SAMPLER3); /* Read ADC0 value and store it in read1. */
    read2 = ADCRead(ADC1, SAMPLER3); /* Read ADC1 value and store it in read2. */

    if (((read2 - R2_DIFF) - (read1 - R1_DIFF)) > MIN_DIFFERENCE) {
        retVal = RIGHT; /* Set retVal to RIGHT. */
        *difference = ((read2 - R2_DIFF) - (read1 - R1_DIFF)); /* Calculate and assign the difference. */
    }
    else if (((read1 - R1_DIFF) - (read2 - R2_DIFF)) > MIN_DIFFERENCE) {
        retVal = LEFT; /* Set retVal to LEFT. */
        *difference = (read1 - R1_DIFF) - (read2 - R2_DIFF); /* Calculate and assign the difference. */
    }
    else if ((read1 - R1_DIFF) - (read2 - R2_DIFF) < MIN_DIFFERENCE) {
        retVal = STAY; /* Set retVal to STAY. */
        *difference = (read1 - R1_DIFF) - (read2 - R2_DIFF); /* Calculate and assign the difference. */
    }
    else if ((read2 - R2_DIFF) - (read1 - R1_DIFF) < MIN_DIFFERENCE) {
        retVal = STAY; /* Set retVal to STAY. */
        *difference = (read2 - R2_DIFF) - (read1 - R1_DIFF); /* Calculate and assign the difference. */
    }

    return retVal; /* Return the final result in retVal. */
}

