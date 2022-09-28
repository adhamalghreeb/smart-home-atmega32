/*
 * smart_ho.c
 *
 * Created: 9/7/2022 11:04:51 PM
 * Author : Shiko
 */ 

#include <avr/io.h>
#include <avr/delay.h>
#include <stdint.h>
#include "adc.h"
#include"dio.h"
//#include "pwm.h"
#define F_CPU 8000000U


int main(void)

{
	
	dio_set_direction(PORT_A ,PIN_0 ,INPUT);
	dio_set_direction(PORT_C ,PIN_6 ,OUTPUT);
	dio_set_direction(PORT_C ,PIN_7 ,OUTPUT);
	dio_set_direction(PORT_B ,PIN_3 ,OUTPUT);
	dio_set_direction(PORT_B ,PIN_0 ,INPUT);
	dio_set_direction(PORT_B ,PIN_1 ,INPUT);
	dio_set_direction(PORT_B ,PIN_5 ,OUTPUT);
	dio_set_direction(PORT_B ,PIN_6 ,OUTPUT);
	
	//DDRC=0xff; // outputand motor motion
	DDRB|=(1<<3); //Set OC0 as output to use PWM signal
    /* Replace with your application code */
	
	  adc_init();
	  adc_select_channel(0);
	  
	
	  /*end of initialization*/
	    //PWM initialization
	    PWM_Timer0_start(0);//Set OC0 as output to use PWM signal
	  
	 PORTC &= ~(1<<6);
	 PORTC|=(1<<7);
	 
	  uint8_t temp_read;
	  
    while (1) 
    {
		 adc_start_conv(); // STrat the conversion
		 while (adc_is_dataready() == 0); // wait untill read flag
		 temp_read=adc_get_data();
		 //temp_read=ADCH; // read the tempreture value
		
		 
		  /*Control Fan*/
		  if(temp_read<5)
		  {
			  OCR0=255;//0% duty cycle
		  }
		  else if(temp_read<10)
		  {
			  OCR0=229;//10% duty cycle
		  }
		  else if(temp_read<15)
		  {
			  OCR0=178; //30% duty cycle
		  }
		  else if(temp_read<20)
		  {
			  OCR0=102; //60% duty cycle
		  }
		  else if(temp_read<25)
		  {
			  OCR0=25; //90%duty cycle
		  }
		  else
		  {
			  OCR0=0; //100% duty cycle
		  }
		  
		   
		     if(dio_get_value(PORT_B,PIN_0)){
			  dio_set_value(PORT_B, PIN_5, HIGH);
		  }
		  else{
		  dio_set_value(PORT_B, PIN_5, LOW);}

		  if(dio_get_value(PORT_B,PIN_1)){
			  dio_set_value(PORT_B, PIN_6, HIGH);
		  }
		  else{
		  dio_set_value(PORT_B, PIN_6, LOW);}


    }
}

