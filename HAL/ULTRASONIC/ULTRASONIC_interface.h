/*Author:      Mohamed Gamal Roushdy                                                                      
  Version:     0.1                                                                       
  Date:        31/08/2023                                                                             
  Description: ULTRASONIC driver interface file      
*/
#ifndef _ULTRASONIC_INTERFACE_H
#define _ULTRASONIC_INTERFACE_H

#define F_CPU 16000000UL


/*Public Functions Prototypes*/

/********************************************************************************************/
/* Function: Ultrasonic_Init                                                            */
/* Description: Initializes the ultrasonic sensor system. This function sets up the necessary */
/*              configurations and prepares the ultrasonic sensor for distance measurement.   */
/*              It should be called once before using any other ultrasonic sensor functions.  */
/********************************************************************************************/
void Ultrasonic_Init(void);

/********************************************************************************************/
/* Function: Ultrasonic_Callback                                                        */
/* Description: Callback function for handling ultrasonic sensor events or interrupts. This  */
/*              function is typically called when an event or interrupt is triggered by the  */
/*              ultrasonic sensor, allowing for custom processing of sensor data or events.  */
/*              The implementation of this function may vary based on specific application  */
/*              requirements.                                                              */
/********************************************************************************************/
void Ultrasonic_Callback(void);

/********************************************************************************************/
/* Function: Measure_Distance                                                            */
/* Description: Measures the distance using the ultrasonic sensor. This function triggers a */
/*              measurement with the ultrasonic sensor and calculates the distance based on   */
/*              the sensor's response. The distance is returned as a floating-point value.   */
/* Return Value:                                                                          */
/*   - float: The measured distance in centimeters (cm) as a floating-point value.           */
/********************************************************************************************/
float Measure_Distance(void);


#endif
