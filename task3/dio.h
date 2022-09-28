/*
 * dio.h
 *
 *  Created on: Aug 21, 2022
 *      Author: Shiko
 */


#ifndef MCAL_DIO_DIO_H_
#define MCAL_DIO_DIO_H_

typedef enum{
	INPUT=0,
	OUTPUT=1,
}dio_direction;

typedef enum{
	LOW,
	HIGH,
}dio_value;

typedef enum{
	PORT_A=0,
	PORT_B,
	PORT_C,
	PORT_D
}port_x;

typedef enum{
	PIN_0=0,
	PIN_1,
	PIN_2,
	PIN_3,
	PIN_4,
	PIN_5,
	PIN_6,
	PIN_7
}dio_pin;

void dio_set_direction(port_x port ,dio_pin pin ,dio_direction direction);

void dio_set_value(port_x port ,dio_pin pin,dio_value value);

dio_value dio_get_value(port_x port,dio_pin pin);

#endif /* MCAL_DIO_DIO_H_ */

