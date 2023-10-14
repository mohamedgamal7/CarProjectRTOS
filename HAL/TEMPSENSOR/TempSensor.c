/********************************************************************************************/
/* Authors: Mohamed Gamal, Ehab Roushdy, Ahmed Maher and Kareem Hany                        */                                  */
/* Version: V01                                                                             */
/* Date: 10/09/2023                                                                         */
/* Description: Temperature Sensor Driver Program                                           */
/********************************************************************************************/

/* Library includes */
#include "TempSensor.h"

void TempInit(void)
{
    /*Clock gate for ADC*/
    ADCStartUse(ADC0);
    /*Sample using 2nd sample sequencer */
    ADCInitSampler(ADC0, SAMPLER2, WHEN_REQUIRED, AIN8);
    /*Enable the temprature sensor*/
    ADCTempEnable(ADC0, SAMPLER2);
}

uint32_t TempRead(void)
{
    uint32_t Temp = 0;
    /*Read the temprature from sequencere two*/
    Temp = ADCRead(ADC0, SAMPLER2);
    /*Equation for temprature conversion from digital value to physical value*/
    Temp = 147.5 - ((75 * 3.3 * Temp) / 4096);

    return Temp;
}

