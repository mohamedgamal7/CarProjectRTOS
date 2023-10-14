/********************************************************************************************/
/* Authors: Mohamed Gamal, Ehab Roushdy, Mohamed abelmoteleb and Aya Yasse                  */
/* Version: V01                                                                             */
/* Date: 10/09/2023                                                                         */
/* Description: Motor driver Header file                                                    */
/********************************************************************************************/
#ifndef MOTOR_H
#define MOTOR_H


/** Engine power level (percentage) for motor control. */
#define ENGINE_POWER 70

/**
 * @brief Initialize the motor control module.
 */
void MotorInit(void);

/**
 * @brief Move the motors forward with a specified power level.
 *
 * @param percent Power level as a percentage.
 */
void MotorForward(unsigned char percent);

/**
 * @brief Turn the motors to the right with a specified power level.
 *
 * @param percent Power level as a percentage.
 */
void MotorTurnRight(unsigned char percent);

/**
 * @brief Turn the motors to the left with a specified power level.
 *
 * @param percent Power level as a percentage.
 */
void MotorTurnLeft(unsigned char percent);

/**
 * @brief Move the motors backward with a specified power level.
 *
 * @param percent Power level as a percentage.
 */
void MotorBackward(unsigned char percent);

/**
 * @brief Stop the motors.
 */
void MotorStop(void);

#endif
