/********************************************************************************************/
/*Authors: Mohamed Gamal                 */
/*Version: V01                                                                              */
/*Date: 19/08/2023                                                                          */
/*Description: Ultrasonic Driver program                                                     */
/********************************************************************************************/

/*Library includes*/
#include "LIB/BIT_MATH.h"
#include "LIB/tm4c123gh6pm.h"
#include "LIB/types.h"
#include "LIB/Delay.h"
//
/*MCAL includes*/
#include "MCAL/GPTM/GPTM.h"
#include "MCAL/GPTM/GPTM_Types.h"
#include "MCAL/DIO/DIO.h"


/*Ulttrasonic includes*/
#include "./HAL/ULTRASONIC/ULTRASONIC_interface.h"
#include "./HAL/ULTRASONIC/ULTRASONIC_private.h"
#include "./HAL/ULTRASONIC/ULTRASONIC_config.h"


static void Ultrasonic_GPIO_Init(void)
{
    /*select  Pin4 PORTC as an alternative function*/
    GPIO_PORTC_AFSEL_R|=(1<<4);
    /*Select the CCP pin by inserting the PINMUX value in its position*/
    GPIO_PORTC_PCTL_R|=(0x7<<4*4);

}

static void Ultrasonic_Timer_Init(void)
{
    /* Enable WTIMER0 Clock */
    TimerStartUse(WTIMER_0);
    /* Disable WTIMER0 Clock */
    TimerDisable( WTIMER_0,TIMERA);
    /* Configure WTIMER0 as input capture */
    TimerConfigure (WTIMER_0, TIMERA, WTIMER_MODE32 , TMR_CAPTURE | TCMR);
    /*Used for stalling the timer at debugging*/
    TimerControlStall(WTIMER_0, TIMERA, true);
    /*Wait for interuppt on both edges*/
    TimerControlEvent (WTIMER_0,TIMERA, BOTH_EDGES);
    /* Enable Timer A */
    TimerEnable(WTIMER_0, TIMERA);
}
void Ultrasonic_Init(void)
{


    Ultrasonic_GPIO_Init();
    Ultrasonic_Timer_Init();
}

static void trigger_measurement(void)
{

    /* Triggers start of measurement of Ultrasonic device */
      DIO_Write(PORTB, P0, HIGH);
      delay_us(15);
      DIO_Write(PORTB, P0, LOW);


}

float Measure_Distance(void)
{
    uint32 Rise=0, Fall=0;
    float Distance;
    float Period = 0U;
    uint32 TimeOut = TIMEOUT_DURATION_TICKS;

    /*clear timer interuppt before trigger as a safety procedure*/
    TimerIntClear(WTIMER_0, CAECINT);
    trigger_measurement();
    /*Timeout is a protection mechanism to prevent being stuck in the while loop*/
    while(!TimerIntStatus(WTIMER_0, CAEIM) && --TimeOut);
    if(TimeOut <= 0)
        return -1;
    /*Capture rising edge time */
    Rise = TimerValueGet(WTIMER_0, TIMERA);
    /*Clear timer interuppt flag to start recieving new interuppts*/
    TimerIntClear(WTIMER_0, CAECINT);
    /*reset the timeout duration for the new edge*/
    TimeOut = TIMEOUT_DURATION_TICKS;
    while(!TimerIntStatus(WTIMER_0, CAEIM) && --TimeOut);
    if(TimeOut <= 0)
        return -1;
    /*Capture Falling edge time */
    Fall = TimerValueGet(WTIMER_0, TIMERA);
    /*Calculate the period in Secs*/
    Period = (Rise - Fall) / 16000000.0f;
    /*Measure distance by multiplying by the speed of sound in cm and dividing by 2 as the wave took this paths twice*/
    Distance = (Period * 34300U) / 2U;


    return Distance;


}




