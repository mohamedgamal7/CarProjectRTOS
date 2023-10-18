/*
 * Author:      Ehab Roshdy                                                                      
 * Version:     0.1                                                                       
 * Date:        10/9/2023                                                                             
 * Description: PWM driver program file    
*/

#include "MCAL/PWM/PWM_interface.h"
#include "MCAL/PWM/PWM_private.h"
#include "MCAL/PWM/PWM_config.h"
//////////////////////////////////////////////////////////////////////////////////////////////

void pwm_init(void)
{
    /* Enable the PWM clock by writing a value of 0x0010.0000 to the RCGC0 */
    SYSCTL_RCGCPWM_R |= 0x00000001;

    /* In the GPIO module, enable B6 and B7 pins for their alternate function using the GPIOAFSEL register */
    GPIO_PORTB_AFSEL_R |= 0x000000C0;

    /* Configure the PMC6 and PM7 fields in the GPIOPCTL register to assign the PWM signals to the appropriate pins */
    GPIO_PORTB_PCTL_R |= 0x44000000;

    /* Configure the Run-Mode Clock Configuration (RCC) register in the System Control module
       to use the PWM divide (USEPWMDIV) and set the divider (PWMDIV) to divide by 2 (000). */
    SYSCTL_RCC_R &= ~(0x000E0000);

    /* Configure the PWM generator for countdown mode with immediate updates to the parameters */
    /* Write the PWM0CTL register with a value of 0x0000.0000. */
    PWM0_0_CTL_R &= ~(0xFFFFFFFF);

    /* Write the PWM0GENA register with a value of 0x0000.008C. */
    PWM0_0_GENA_R |= 0x0000008C;

    /* Write the PWM0GENB register with a value of 0x0000.080C. */
    PWM0_0_GENB_R |= 0x0000080C;

    /* Write the PWM0LOAD register with a value of 0x0000.018F. */
    PWM0_0_LOAD_R |= 0x0000013F;

}

void pwm_set_duty_cycle(unsigned char percent)
{
    /* Write the PWM0CMP register with a value */
    PWM0_0_CMPA_R = (((100 - percent) * 320 / 100) - 1);
    PWM0_0_CMPB_R = (((100 - percent) * 320 / 100) - 1);

    /* start timers Write the PWM0CTL register with a value of 0x0000.0001. */
    PWM0_0_CTL_R |= 0x00000001;

    /* enable pwm Write the PWMENABLE register with a value of 0x0000.0003. */
    PWM0_ENABLE_R |= 0x00000003;
}
