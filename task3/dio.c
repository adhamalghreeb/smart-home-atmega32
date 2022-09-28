#include"dio.h"
#include<avr/io.h>
#include<stdint.h>


void dio_set_direction(port_x port ,dio_pin pin ,dio_direction direction){

	switch(port){
		case PORT_A: if(direction == OUTPUT)
		DDRA |= (0b1 << pin);
		else if(direction == INPUT)
		DDRA &= ~(0b1<<pin);
		break;
		case PORT_B: if(direction == OUTPUT)
		DDRB |= (0b1 << pin);
		else if(direction == INPUT)
		DDRB &= ~(0b1<<pin);
		break;
		case PORT_C: if(direction == OUTPUT)
		DDRC |= (0b1 << pin);
		else if(direction == INPUT)
		DDRC &= ~(0b1<<pin);
		break;
		case PORT_D: if(direction == OUTPUT)
		DDRD |= (0b1 << pin);
		else if(direction == INPUT)
		DDRD &= ~(0b1<<pin);
		break;
		default:
		break;
	}
}

void dio_set_value(port_x port ,dio_pin pin,dio_value value){
	switch(port){
		case PORT_A: if(value == HIGH)
		PORTA |= (0b1 << pin);
		else if(value == LOW)
		PORTA &= ~(0b1<<pin);
		break;
		case PORT_B: if(value == HIGH)
		PORTB |= (0b1 << pin);
		else if(value == LOW)
		PORTB &= ~(0b1<<pin);
		break;
		case PORT_C: if(value == HIGH)
		PORTC |= (0b1 << pin);
		else if(value == LOW)
		PORTC &= ~(0b1<<pin);
		break;
		case PORT_D: if(value == HIGH)
		PORTD |= (0b1 << pin);
		else if(value == LOW)
		PORTD &= ~(0b1<<pin);
		break;
		default:
		break;
	}
}

dio_value dio_get_value(port_x port,dio_pin pin){

	dio_value pinvalue;

	switch(port){

		case PORT_A: if(PINA & (0b1<<pin))
		pinvalue = HIGH;
		else
		pinvalue = LOW;
		break;
		case PORT_B: if(PINB & (0b1<<pin))
		pinvalue = HIGH;
		else
		pinvalue = LOW;
		break;
		case PORT_C: if(PINC & (0b1<<pin))
		pinvalue = HIGH;
		else
		pinvalue = LOW;
		break;
		case PORT_D: if(PIND & (0b1<<pin))
		pinvalue = HIGH;
		else
		pinvalue = LOW;
		break;
		default:
		break;
	}
	return pinvalue;
}

