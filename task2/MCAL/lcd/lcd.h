/*
 * lcd.h
 *
 *  Created on: Aug 16, 2022
 *      Author: Administrator
 */

#ifndef MCAL_LCD_LCD_H_
#define MCAL_LCD_LCD_H_

#include "C:\Users\Administrator\Desktop\ES ITI\project\pro22\MCAL\Micro_config.h"
#include "C:\Users\Administrator\Desktop\ES ITI\project\pro22\MCAL\Common_Macros.h"
#include "C:\Users\Administrator\Desktop\ES ITI\project\pro22\MCAL\dio\dio.h"

#define LCD_Data_Dir DDRB
#define LCD_Data_Out PORTB
#define LCD_Ctrl_Dir DDRD
#define LCD_Ctrl_Out PORTD

#define E 1
#define W 2
#define RS 0    

#define Eight_Bit_Mode 0x38
#define CLEAR_COMMAND 0x01
#define CURSOR_OFF 0x0C
#define CURSOR_ON 0x0E
#define SET_CURSOR_LOCATION 0x80

void LCD_Init(void);
void LCD_SendCommand(uint8_t data);
void LCD_SendCharacter(uint8_t data);
void LCD_SendString(uint8_t *str);
void LCD_GoToRowCol(uint8_t row, uint8_t col);
void LCD_SendStringRowCol(uint8_t row, uint8_t col, uint8_t *str);
void LCD_IntegerToString(uint16_t data);
void LCD_ClearScreen();


#endif /* LCD_H_ */

