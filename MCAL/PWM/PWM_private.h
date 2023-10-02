/*
 * Author:      Ehab Roshdy                                                                      
 * Version:     0.1                                                                       
 * Date:        10/9/2023                                                                             
 * Description: PWM driver private file                                       
*/

#pragma once

////////////////////////////           MACROS           //////////////////////////////////////
#define SYSCTL_RCGC0_R          (*((volatile unsigned long *)0x400FE100))
#define SYSCTL_RCGC2_R          (*((volatile unsigned long *)0x400FE108))

#define GPIO_PORTB_AFSEL_R      (*((volatile unsigned long *)0x40005420))
#define GPIO_PORTB_PCTL_R       (*((volatile unsigned long *)0x4000552C))

#define SYSCTL_RCC_R            (*((volatile unsigned long *)0x400FE060))

#define PWM0_0_CTL_R            (*((volatile unsigned long *)0x40028040))
#define PWM0_0_GENA_R           (*((volatile unsigned long *)0x40028060))
#define PWM0_0_GENB_R           (*((volatile unsigned long *)0x40028064))

#define PWM0_0_LOAD_R           (*((volatile unsigned long *)0x40028050))
#define PWM0_0_CMPA_R           (*((volatile unsigned long *)0x40028058))
#define PWM0_0_CMPB_R           (*((volatile unsigned long *)0x4002805C))

#define PWM0_0_CTL_R            (*((volatile unsigned long *)0x40028040))
#define PWM0_ENABLE_R           (*((volatile unsigned long *)0x40028008))


////////////////////////////          VARIABLES         //////////////////////////////////////

////////////////////////////          FUNCTIONS         //////////////////////////////////////

