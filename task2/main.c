#include<avr/io.h>
#include<avr/delay.h>
#include <avr/interrupt.h>
#include"MCAL\adc\adc.h"
#include"MCAL\dio\dio.h"
#include"MCAL\timer\timer.h"
#include"MCAL\lcd\lcd.h"
#include"MCAL\keypad_new\KPD_interface.h"

#define F_CPU 8000000UL

int main(){
	LCD_Init();
	KPD_voidInit();
	servo_init();
	ADC_Init();
	uint8_t send;
	uint8_t pass[16];
		while(1){
				uint8_t key=NOT_PRESSED;
				key=KPD_u8GetPressedKey();
				if(key!=NOT_PRESSED){
					LCD_SendCharacter(key);
					for(int i = 0 ; i < 16 ; i++){
						if(key == '='){
							send = atoi(pass);
							servo_cnt(send);
							LCD_ClearScreen();
							break;
						}
						pass[i] = key;
					}
				}
			}
	
}
