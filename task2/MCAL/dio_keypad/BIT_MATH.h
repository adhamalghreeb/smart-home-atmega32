/*
 * BIT_MATH.h
 *
 *  Created on: Aug 11, 2022
 *      Author: sama
 */

#ifndef LIB_BIT_MATH_H_
#define LIB_BIT_MATH_H_

#define       SET_BIT(reg,bit_number)     reg|=(1<<bit_number)
#define       CLR_BIT(reg,bit_number)     reg&=(~(1<<bit_number))
#define       TOGGLE_BIT(reg,bit_number)  reg^=(1<<bit_number)
#define       GET_BIT(reg,bit_number)     (reg>>bit_number)&1


#endif /* LIB_BIT_MATH_H_ */
