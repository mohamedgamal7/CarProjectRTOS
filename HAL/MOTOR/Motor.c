#include "MCAL/PWM/PWM_interface.h"
#include "LIB/types.h"
#include "MCAL/DIO/DIO.h"

void MotorInit(void)
{
    // Initialize pwm module 0 generators 0, 1 to be used
    pwm_init();

    /* initially all forward */
    DIO_Write(PORTC,  P6 | P7, P6);
    DIO_Write(PORTD,  P6 | P7, P6);

}

void MotorForward(unsigned char percent)
{
    /* initially all forward */
    DIO_Write(PORTC,  P6 | P7, P6);
    DIO_Write(PORTD,  P6 | P7, P6);

    // Set duty cycle.
    pwm_set_duty_cycle(percent);

}

void MotorTurnRight(unsigned char percent)
{
    /* initially all forward */
    DIO_Write(PORTC,  P6 | P7, P7);
    DIO_Write(PORTD,  P6 | P7, P6);

    // Set duty cycle.
    pwm_set_duty_cycle(percent);

}

void MotorTurnLeft(unsigned char percent)
{
    /* initially all forward */
    DIO_Write(PORTC,  P6 | P7, P6);
    DIO_Write(PORTD,  P6 | P7, P7);

    // Set duty cycle.
    pwm_set_duty_cycle(percent);
}

void MotorBackward(unsigned char percent)
{
    /* clamp percent between 100 and 0 */
//    percent = ((percent > 100) ? 100 : ((percent < 0) ? 0 : percent)) / 100;

    /* initially all forward */
    DIO_Write(PORTC,  P6 | P7, P7);
    DIO_Write(PORTD,  P6 | P7, P7);

    // Set duty cycle.
    pwm_set_duty_cycle(percent);

}

void MotorStop(void)
{
    DIO_Write(PORTC,  P6 | P7, P6 | P7);
    DIO_Write(PORTD,  P6 | P7, P6 | P7);
}
