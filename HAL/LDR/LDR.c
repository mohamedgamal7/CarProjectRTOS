#include "HAL/LDR/LDR.h"

#define MIN_DIFFERENCE  250 // Minimum difference to consider movement

int R1_DIFF = 0; // Calibration difference for LDR1
int R2_DIFF = 0; // Calibration difference for LDR2

// Function to perform calibration for LDR1 and LDR2
void Calibrate(void) {
    unsigned int R1 = ADCRead(ADC0, SAMPLER3); // Read LDR1
    unsigned int R2 = ADCRead(ADC1, SAMPLER3); // Read LDR2
    if (R1 > R2) {
        R1_DIFF = R1 - R2; // Set calibration difference for LDR1
    } else {
        R2_DIFF = R2 - R1; // Set calibration difference for LDR2
    }
}

void LDR_Init(void) {
    // Initialize LDR1
    ADCStartUse(ADC0);
    ADCInitSampler(ADC0, SAMPLER3, WHEN_REQUIRED, AIN0);

    // Initialize LDR2
    ADCStartUse(ADC1);
    ADCInitSampler(ADC1, SAMPLER3, WHEN_REQUIRED, AIN1);

    Calibrate(); // Perform calibration
}

dirType LDR_Comp(int32 *difference) {
    int32_t read1 = 0;
    int32_t read2 = 0;

    dirType retVal = STAY;

    // Read LDR values
    read1 = ADCRead(ADC0, SAMPLER3);
    read2 = ADCRead(ADC1, SAMPLER3);

    // Compare LDR values to detect movement
    if (((read2 - R2_DIFF) - (read1 - R1_DIFF)) > MIN_DIFFERENCE) {
        retVal = RIGHT;
        *difference = ((read2 - R2_DIFF) - (read1 - R1_DIFF));
    } else if (((read1 - R1_DIFF) - (read2 - R2_DIFF)) > MIN_DIFFERENCE) {
        retVal = LEFT;
        *difference = (read1 - R1_DIFF) - (read2 - R2_DIFF);
    } else {
        // If the difference is not significant, the direction is STAY
        retVal = STAY;
        *difference = (read1 - R1_DIFF) - (read2 - R2_DIFF);
    }
    return retVal;
}
