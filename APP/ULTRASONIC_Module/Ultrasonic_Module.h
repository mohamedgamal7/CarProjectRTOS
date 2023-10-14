/**
 * @file Ultrasonic_Module.h
 *
 * @brief Ultrasonic Module Interface for Obstacle Avoidance
 *
 * This module provides an interface for implementing obstacle avoidance logic in a car
 * using an ultrasonic sensor. It defines the function for avoiding obstacles.
 *
 * @date Oct 1, 2023
 * @author Aya Yasser
 */

#ifndef APP_ULTRASONIC_MODULE_ULTRASONIC_MODULE_H_
#define APP_ULTRASONIC_MODULE_ULTRASONIC_MODULE_H_

/**
 * @brief Implements obstacle avoidance logic for a car with an ultrasonic sensor.
 *
 * This function continuously monitors the car's current state and controls its movement
 * to avoid obstacles based on ultrasonic sensor readings.
 */
void avoid_obstacles(void);

#endif /* APP_ULTRASONIC_MODULE_ULTRASONIC_MODULE_H_ */
