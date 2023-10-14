
/*Author:      Mohamed Gamal Roushdy                                                                      
  Version:     V02
  Date:        10/09/2023
  Description: ULTRASONIC driver private file                                       
*/
#ifndef _ULTRASONIC_PRIVATE_H
#define _ULTRASONIC_PRIVATE_H

#define TIMEOUT_DURATION_TICKS    5*3180  /* represent 5 millisecond time out */

/*Private Functions ProtoTypes*/

/********************************************************************************************/
/* Static Function: Ultrasonic_GPIO_Init                                                  */
/* Description: Initializes the GPIO pins for the ultrasonic sensor. This static function   */
/*              configures the necessary GPIO pins to work with the ultrasonic sensor as     */
/*              per the specific hardware setup. It should not be called directly from      */
/*              outside this module.                                                       */
/********************************************************************************************/
static void Ultrasonic_GPIO_Init(void);

/********************************************************************************************/
/* Static Function: Ultrasonic_Timer_Init                                                */
/* Description: Initializes the timer for the ultrasonic sensor. This static function        */
/*              configures the timer module to work with the ultrasonic sensor for precise  */
/*              timing of distance measurements. It should not be called directly from      */
/*              outside this module.                                                       */
/********************************************************************************************/
static void Ultrasonic_Timer_Init(void);








#endif

