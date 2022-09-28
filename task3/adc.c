#include "adc.h"
#include <avr/io.h>
#include "adc_config.h"


void adc_init(void)
{
	DDRA=0x00; //input ADC1
	ADCSRA |= 1<<7 ; //Enable the ADC
	ADCSRA |= 0b00000110; // Set the prescaler to 64
	ADMUX |= 0b11000000; // reference volt is internal volt 2.56
	//ADMUX|= 1<< ADLAR; // set adlar =1
	//ADMUX |= 0b0000000; // select channel 0
	/*End of initialization*/

}



void adc_select_channel(uint8_t channel)
{
	ADMUX &= ~(0b11111<<MUX0);
	ADMUX |= channel<<MUX0;
}

void adc_set_trigger(uint8_t state)
{
	if(state == 0)
	{
		ADCSRA &= ~(0b1<<ADATE);
	}
	else
	{
		ADCSRA |= 0b1<<ADATE;
	}
}


void adc_select_trigger(adc_trigger_t trigger)
{
	SFIOR &= ~(0b111<<ADTS0);
	SFIOR |= trigger<<ADTS0;
}


void adc_start_conv()
{
	ADCSRA |= 0b1<<ADSC;
}
uint8_t adc_is_dataready()
{
	uint8_t result = 0x01&(ADCSRA>>ADIF);  //read flag
	ADCSRA |= 0b1 <<ADIF;  //clear flag
	return result;
}
uint16_t adc_get_data()
{
	uint16_t adc_val;
	adc_val = ADCL;
	adc_val |= ADCH << 8;
	return adc_val;
}