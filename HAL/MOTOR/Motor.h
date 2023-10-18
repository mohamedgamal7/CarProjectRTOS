#ifndef MOTOR_H
#define MOTOR_H

// Motor power level for forward and backward motion
#define ENGINE_POWER 70

// Initialize the motor
void MotorInit(void);

// Move the motor forward with the specified power percentage
void MotorForward(unsigned char percent);

// Turn the motor right with the specified power percentage
void MotorTurnRight(unsigned char percent);

// Turn the motor left with the specified power percentage
void MotorTurnLeft(unsigned char percent);

// Move the motor backward with the specified power percentage
void MotorBackward(unsigned char percent);

// Stop the motor
void MotorStop(void);

#endif
