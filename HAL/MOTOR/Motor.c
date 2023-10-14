/********************************************************************************************/
/* Authors: Mohamed Gamal, Ehab Roushdy, Ahmed Maher and Kareem Hany                        */
/* Version: V01                                                                             */
/* Date: 10/09/2023                                                                         */
/* Description: Motor driver Progran file                                                   */
/********************************************************************************************/
#include "MCAL/PWM/PWM_interface.h"
#include "LIB/types.h"
#include "MCAL/DIO/DIO.h"

void MotorInit(void)
{
    /* Initialize PWM module 0 generators 0 and 1 for usage */
    pwm_init();

    /* Initially set all motor pins for forward direction */
    DIO_Write(PORTC, P6 | P7, P6);
    DIO_Write(PORTD, P6 | P7, P6);
}

void MotorForward(unsigned char percent)
{
    /* Initially set all motor pins for forward direction */
    DIO_Write(PORTC, P6 | P7, P6);
    DIO_Write(PORTD, P6 | P7, P6);

    /* Set the PWM duty cycle */
    pwm_set_duty_cycle(percent);
}

void MotorTurnRight(unsigned char percent)
{
    /* Set the motor pins for a right turn */
    DIO_Write(PORTC, P6 | P7, P7);
    DIO_Write(PORTD, P6 | P7, P6);

    /* Set the PWM duty cycle */
    pwm_set_duty_cycle(percent);
}

void MotorTurnLeft(unsigned char percent)
{
    /* Set the motor pins for a left turn */
    DIO_Write(PORTC, P6 | P7, P6);
    DIO_Write(PORTD, P6 | P7, P7);

    /* Set the PWM duty cycle */
    pwm_set_duty_cycle(percent);
}

void MotorBackward(unsigned char percent)
{
    /* Clamp percent between 0 and 100 */
    /* percent = ((percent > 100) ? 100 : ((percent < 0) ? 0 : percent)) / 100; */

    /* Set the motor pins for backward direction */
    DIO_Write(PORTC, P6 | P7, P7);
    DIO_Write(PORTD, P6 | P7, P7);

    /* Set the PWM duty cycle */
    pwm_set_duty_cycle(percent);
}

void MotorStop(void)
{
    /* Stop the motors by setting all motor pins to low */
    DIO_Write(PORTC, P6 | P7, P6 | P7);
    DIO_Write(PORTD, P6 | P7, P6 | P7);
}
