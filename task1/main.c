#include<avr/io.h>
#include<avr/delay.h>
#include <avr/interrupt.h>
#include"MCAL\adc\adc.h"
#include"MCAL\dio\dio.h"
#include"MCAL\timer\timer.h"
#include"MCAL\lm35\lm35.h"
#include"MCAL\lcd\lcd.h"

#define F_CPU 8000000UL

int main(){
	LCD_Init();
	lm_init();
	ADC_Init();

	while(1){
		lm_calc();
	}
	
}
