
/*Author:      Mohamed Gamal Roushdy                                                                      
  Version:     0.2
  Date:        10/09/2023
  Description: ULTRASONIC driver private file                                       
*/
#ifndef _ULTRASONIC_PRIVATE_H
#define _ULTRASONIC_PRIVATE_H

#define TIMEOUT_DURATION_TICKS    5*3180  /* represent 0.5 millisecond time out */

static void Ultrasonic_GPIO_Init(void);
static void Ultrasonic_Timer_Init(void);


#endif

