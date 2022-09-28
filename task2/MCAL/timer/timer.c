#include "timer.h";
#include "C:\Users\Administrator\Desktop\ES ITI\project\pro22\MCAL\Common_Macros.h"
#include<avr/io.h>

#define Clear_Bit(REG,BIT) (REG &= (~(1<<BIT)))
#define Set_Bit(REG,BIT) (REG |= (1<<BIT))

static void(*call_back)(void);

void timer0_init(){
		// FAST PWM
        Set_Bit(TCCR0,WGM00);
        Set_Bit(TCCR0,WGM01);
        //preload
        TCNT0 = 0;
        //clock source prescalar 64 edit it
        Set_Bit(TCCR0,CS00);
        Set_Bit(TCCR0,CS01);
        Clear_Bit(TCCR0,CS02);

        // nin inverting
        // Set_Bit(TCCR0,COM00);
        Set_Bit(TCCR0,COM01);
        //enable 
        Set_Bit(TIMSK, OCIE0); // OUTPUT COMPARE INTERRUPT

        OCR0 = 125; // FOR 1 MS SEC comp value
        // DO NOTHING on compare
        Clear_Bit(TCCR0,COM00);
        Clear_Bit(TCCR0,COM01);

}

void timer0_deinit(){
    // NO CLK SOURCE
    Clear_Bit(TCCR0,CS00);
    Clear_Bit(TCCR0,CS01);
    Clear_Bit(TCCR0,CS02);
    // CLEAR INT
    Clear_Bit(TIMSK,TOIE0);
}

void timer0_set_callback(void(*fun_prt)(void)){
    call_back = fun_prt;
}

void timer1_init(){ // for servo

        Set_Bit(TCCR1A,COM1A1);
        Set_Bit(TCCR1A,WGM11);

        Set_Bit(TCCR1B,WGM12);
        Set_Bit(TCCR1B,WGM13);

        // ICU HIGH
        // Set_Bit(TCCR1B,ICES1);
        
        TCNT1 = 0;		/* Set timer1 count zero */
        ICR1 = 2499;		/* Set TOP count for timer1 in ICR1 register */

        //clock source prescalar
        Set_Bit(TCCR1B,CS10);
        Set_Bit(TCCR1B,CS11);
}

void timer1_deinit(){
    // NO CLK SOURCE
    Clear_Bit(TCCR1B,CS00);
    Clear_Bit(TCCR1B,CS01);
    Clear_Bit(TCCR1B,CS02);
    // CLEAR INT
    Clear_Bit(TIMSK,TOIE0);
}

void timer2_init(){
        // FAST PWM
        Set_Bit(TCCR2,WGM20);
        Set_Bit(TCCR2,WGM21);
        
        

        //Clear on compare
        Set_Bit(TCCR2,COM21);

        //clock source prescalar no
        Set_Bit(TCCR2,CS20);
        Clear_Bit(TCCR2,CS21);
        Clear_Bit(TCCR2,CS22);

}
