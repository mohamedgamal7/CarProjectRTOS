#include "TempSensor.h"

/* Function to initialize the temperature sensor */
void TempInit(void)
{
    // Start using ADC0
    ADCStartUse(ADC0);

    // Initialize ADC sampler for temperature sensor channel (AIN8)
    ADCInitSampler(ADC0, SAMPLER2, WHEN_REQUIRED, AIN8 /*TSCHANNEL*/);

    // Enable the temperature sensor on the specified sampler
    ADCTempEnable(ADC0, SAMPLER2);
}

/* Function to read the temperature value from the sensor */
unsigned int TempRead(void)
{
    uint32_t Temp = 0;

    // Read the temperature value from the ADC
    Temp = ADCRead(ADC0, SAMPLER2);

    // Calculate the temperature in Celsius using the formula
    Temp = 147.5 - ((75 * 3.3 * Temp) / 4096);

    return Temp;
}
