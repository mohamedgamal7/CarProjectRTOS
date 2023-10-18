#include "MCAL/PWM/PWM_interface.h"
#include "LIB/types.h"
#include "MCAL/DIO/DIO.h"

void MotorInit(void)
{
    // Initialize PWM module 0 generators 0 and 1 to be used
    pwm_init();

    /* Initially set all motors to forward */
    DIO_Write(PORTC, P6 | P7, P6);
    DIO_Write(PORTD, P6 | P7, P6);
}

void MotorForward(unsigned char percent)
{
    /* Set all motors to forward */
    DIO_Write(PORTC, P6 | P7, P6);
    DIO_Write(PORTD, P6 | P7, P6);

    // Set duty cycle for forward motion
    pwm_set_duty_cycle(percent);
}

void MotorTurnRight(unsigned char percent)
{
    /* Turn the motors right */
    DIO_Write(PORTC, P6 | P7, P7);
    DIO_Write(PORTD, P6 | P7, P6);

    // Set duty cycle for turning right
    pwm_set_duty_cycle(percent);
}

void MotorTurnLeft(unsigned char percent)
{
    /* Turn the motors left */
    DIO_Write(PORTC, P6 | P7, P6);
    DIO_Write(PORTD, P6 | P7, P7);

    // Set duty cycle for turning left
    pwm_set_duty_cycle(percent);
}

void MotorBackward(unsigned char percent)
{
    /* Set all motors to reverse */
    DIO_Write(PORTC, P6 | P7, P7);
    DIO_Write(PORTD, P6 | P7, P7);

    // Set duty cycle for reverse motion
    pwm_set_duty_cycle(percent);
}

void MotorStop(void)
{
    // Stop all motors
    DIO_Write(PORTC, P6 | P7, P6 | P7);
    DIO_Write(PORTD, P6 | P7, P6 | P7);
}
