/*
 * lcd.c
 *
 *  Created on: Aug 16, 2022
 *      Author: Administrator
 */
#include <avr/io.h>
#include"lcd.h"
#include"..\dio\dio.h"


void LCD_Init()
{
	LCD_Data_Dir = 0xFF;
	LCD_Ctrl_Dir |= (1<<E) | (1<<W) | (1<<RS);
	LCD_SendCommand(Eight_Bit_Mode);
	LCD_SendCommand(CURSOR_OFF);
	LCD_SendCommand(CLEAR_COMMAND);
}

void LCD_SendCommand(uint8_t data)
{
	Clear_Bit(LCD_Ctrl_Out,RS);
	Clear_Bit(LCD_Ctrl_Out,W);
	_delay_ms(1);
	Set_Bit(LCD_Ctrl_Out,E);
	_delay_ms(1);
	LCD_Data_Out = data;
	_delay_ms(1);
	Clear_Bit(LCD_Ctrl_Out,E);
	_delay_ms(1);
}

void LCD_SendCharacter(uint8_t data)
{
	Set_Bit(LCD_Ctrl_Out,RS);
	Clear_Bit(LCD_Ctrl_Out,W);
	_delay_ms(1);
	Set_Bit(LCD_Ctrl_Out,E);
	_delay_ms(1);
	LCD_Data_Out = data;
	_delay_ms(1);
	Clear_Bit(LCD_Ctrl_Out,E);
	_delay_ms(1);
}

void LCD_SendString(uint8_t *str)
{
	while(*str != '\0')
	{
		LCD_SendCharacter(*str);
		str++;
	}
}

void LCD_GoToRowCol(uint8_t row, uint8_t col)
{
	uint8_t address;
	switch (row)
	{
		case 0:
			address = col;
			break;
		case 1:
			address = col + 0x40;
			break;
	}
	LCD_SendCommand(address | SET_CURSOR_LOCATION);
}

void LCD_SendStringRowCol(uint8_t row, uint8_t col, uint8_t *str)
{
	LCD_GoToRowCol(row,col);
	LCD_SendString(str);
}

void LCD_IntegerToString(uint16_t data)
{
	uint8_t BUFF[16];
	itoa(data,BUFF,10);
	LCD_SendString(BUFF);
}

void LCD_ClearScreen()
{
	LCD_SendCommand(CLEAR_COMMAND);
}
