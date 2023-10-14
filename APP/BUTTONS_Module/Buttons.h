/**
 * @file button_check.c
 *
 * @brief Button Check Task Implementation
 *
 * This module contains the implementation of a task that continuously monitors buttons and performs actions based on button presses.
 * It starts or stops a process based on button inputs and communicates with other tasks using a queue.
 *
 * @author Ehab Roshdy
 * @date 05/10/2023
 */


#ifndef BUTTONS_H_
#define BUTTONS_H_

/**
 * @brief Continuously monitors buttons and performs actions based on button presses.
 *
 * This function continuously monitors buttons and performs actions based on button presses.
 * It is responsible for handling button-related functionality.
 */
void button_check(void);

#endif /* BUTTONS_H_ */
