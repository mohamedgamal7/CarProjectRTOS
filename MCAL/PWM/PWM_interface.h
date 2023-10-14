/*
 * Author:      Ehab Roshdy                                                                      
 * Version:     0.1                                                                       
 * Date:        10/9/2023                                                                             
 * Description: PWM driver interface file      
*/

#pragma once

////////////////////////////           MACROS           //////////////////////////////////////
#define PWM0                0
#define PWM1                1
////////////////////////////          VARIABLES         //////////////////////////////////////

////////////////////////////          FUNCTIONS         //////////////////////////////////////

void pwm_init(void);
void pwm_set_duty_cycle(unsigned char percent);
