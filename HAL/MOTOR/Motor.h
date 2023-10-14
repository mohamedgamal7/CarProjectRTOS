#ifndef MOTOR_H
#define MOTOR_H


#define ENGINE_POWER    70


void MotorInit(void);

void MotorForward(unsigned char percent);

void MotorTurnRight(unsigned char percent);

void MotorTurnLeft(unsigned char percent);

void MotorBackward(unsigned char percent);

void MotorStop(void);

#endif
