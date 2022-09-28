#include"pwm.h"
#include"avr/io.h" 
#include<stdint.h>




void PWM_Timer0_start(uint8_t set_duty_cycle)
{

	TCCR0 = (1<<WGM00) | (0<<WGM01) | (1<<COM01) | (1<<COM00) | (1<<CS00) | (0<<CS01) | (1<< CS02) ; //phase correct pwm , inverted pwm ,prescaler 1024
	TIMSK=0x00;  //Disable Timer compare matcth interrupt;
	OCR0  = set_duty_cycle; // Set Compare Value ,Duty cycle now =0;

}
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          