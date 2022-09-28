#include"lm35.h"
#include"../adc/adc.h"
#include"../dio/dio.h"
#include"../Common_Macros.h"

void lm_init(){
	dio_set_direction(DIOD,DIO_PIN7,DIO_DIRECTION_OUTPUT);
}

void lm_calc(){
    
    float celsius;
    uint8_t Temperature[10];

    celsius = (ADC_Read(0)*4.88);
	celsius = (celsius/10.00);

    sprintf(Temperature,"%d%cC  ", (int)celsius, degree_sysmbol);/* convert integer value to ASCII string */

    // LCD_SendString(Temperature);/* send string data for printing */
	memset(Temperature,0,10); 

	celsius = (int)celsius;

	timer2_init();
	if(celsius > 0 && celsius <= 30){
		OCR2 = 0;
		// LCD_SendCharacter('a');
		_delay_ms(1000);
	}
	else if(celsius > 30 && celsius <= 60){
		OCR2 = 77;
		// LCD_SendCharacter('b');
		_delay_ms(1000);
	}
	else if(celsius > 60 && celsius <= 80){
		OCR2 = 100;
		// LCD_SendCharacter('c');
		_delay_ms(1000);
	}
	else if(celsius > 80 && celsius <= 100){
		OCR2 = 255;
		// LCD_SendCharacter('d');
		_delay_ms(1000);
	}
	// LCD_ClearScreen();
}
