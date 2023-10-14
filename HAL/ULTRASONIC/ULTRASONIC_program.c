//
//
///*Library includes*/
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
    GPIO_PORTC_AFSEL_R|=(1<<4);
    GPIO_PORTC_PCTL_R|=(0x7<<4*4);

}

static void Ultrasonic_Timer_Init(void)
{
    /* Enable WTIMER0 Clock */
    TimerStartUse(WTIMER_0);
    TimerDisable( WTIMER_0,TIMERA);
    TimerConfigure (WTIMER_0, TIMERA, WTIMER_MODE32 , TMR_CAPTURE | TCMR);
    TimerControlStall(WTIMER_0, TIMERA, true);
    TimerControlEvent (WTIMER_0,TIMERA, BOTH_EDGES);
    TimerEnable(WTIMER_0, TIMERA); /* Enable Timer A */
}
void Ultrasonic_Init(void)
{


    Ultrasonic_GPIO_Init();
    Ultrasonic_Timer_Init();
}

static void trigger_measurement(void)
{

      DIO_Write(PORTB, P0, HIGH);
      delay_us(15);
      DIO_Write(PORTB, P0, LOW);


}

float Measure_Distance(void)
{
    uint32 Rise=0, Fall=0;
    float Distance;
    float Period = 0U;
    uint32 timeOut = TIMEOUT_DURATION_TICKS;
    TimerIntClear(WTIMER_0, CAECINT);

    trigger_measurement();
    while(!TimerIntStatus(WTIMER_0, CAEIM) && --timeOut);
    if(timeOut <= 0)
        return -1;
    Rise = TimerValueGet(WTIMER_0, TIMERA);

    TimerIntClear(WTIMER_0, CAECINT);
    timeOut = TIMEOUT_DURATION_TICKS;
    while(!TimerIntStatus(WTIMER_0, CAEIM) && --timeOut);
    if(timeOut <= 0)
        return -1;
    Fall = TimerValueGet(WTIMER_0, TIMERA);
    Period = (Rise - Fall) / 16000000.0f;
    Distance = (Period * 34300U) / 2U;


    return Distance;


}




