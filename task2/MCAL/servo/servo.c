#include"servo.h"
#include<avr/io.h>
#include<avr/delay.h>
#include <avr/interrupt.h>
#include "..\dio\dio.h"
#include "C:\Users\Administrator\Desktop\ES ITI\project\pro22\MCAL\timer\timer.h"
#include"../keypad_new/KPD_interface.h"
#include"../lcd/lcd.h"

void servo_init(){
    dio_set_direction(DIOD, DIO_PIN5, DIO_DIRECTION_OUTPUT);
}
void servo_cnt(uint8_t position){
    if(position == 85){
        timer1_init();
        _delay_ms(500);
        OCR1A = 65;	/* Set servo shaft at -90° position */
    }
    else if(position == 199){
        _delay_ms(500);
		OCR1A = 175;	/* Set servo shaft at 0° position */
        _delay_ms(500);
        OCR1A = 300;	/* Set servo at +90° position */
    }
}
