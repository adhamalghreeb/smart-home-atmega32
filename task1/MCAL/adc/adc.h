#ifndef ADC_H
#define ADC_H
#include"adc.h"
#include"../Common_Macros.h"
#include<avr/io.h>

void ADC_Init();
uint8_t ADC_Read(uint8_t channel);

#endif
