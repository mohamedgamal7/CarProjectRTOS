/********************************************************************************************/
/* Author: Mohamed Gamal Rousdhy                                                             */
/* Version: V01                                                                            */
/* Date: 19/08/2023                                                                       */
/* Description: Bit manipulation macros for register and bit operations                   */
/********************************************************************************************/

#ifndef _BIT_MATH_H
#define _BIT_MATH_H

// Macro to set a specific bit in a register
#define SET_BIT(REG, BIT)   ((REG) |= (1 << BIT))

// Macro to clear (reset) a specific bit in a register
#define CLR_BIT(REG, BIT)   (REG &= ~(1 << BIT))

// Macro to toggle (invert) a specific bit in a register
#define TOG_BIT(REG, BIT)   (REG ^= (1 << BIT))

// Macro to get the value of a specific bit in a register
#define GET_BIT(REG, BIT)   (((REG) >> (BIT)) & 1)

// Macro to insert a value into specific bits of a register
#define INSERT_BITS(REG, VALUE, POSITION) (REG |= ((VALUE) << (POSITION)))

#endif
