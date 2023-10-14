/********************************************************************************************/
/*Author: Mohamed Gamal Rousdhy                                                             */
/*Version: V01																			    */
/*Date:	19/08/2023																			*/
/*Description: Bit maipulation macros 														*/
/********************************************************************************************/

#ifndef _BIT_MATH_H
#define _BIT_MATH_H

#define SET_BIT(REG, BIT)   ((REG) |= (1 << BIT))
#define CLR_BIT(REG,BIT)   	(REG&=~(1<<BIT))
#define TOG_BIT(REG,BIT)   	(REG^=(1<<BIT))
#define Get_Bit(REG,BIT)   ((REG)>>(BIT)&1)
#define INSERT_BITS(REG,VALUE,P) (REG|=(VALUE<<P))


#endif
