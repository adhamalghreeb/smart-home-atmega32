#ifndef TIMER_H
#define TIMER_H

#include "C:\Users\Administrator\Desktop\ES ITI\project\pro22\MCAL\Common_Macros.h"

// typedef enum{
//     timer,
//     counter
// }timer_mode_t;

typedef enum{
   NORMAL=0,
   PWM,
   CTC,
   FAST_PWM
}timer_output_t;

typedef enum{
   TIMER_NO_CLKSOURCE,
   TIMER_PRESCALAR_1,
   TIMER_PRESCALAR_8,
   TIMER_PRESCALAR_64,
   TIMER_PRESCALAR_256,
   TIMER_PRESCALAR_1024,
   TIMER_EXCLK_RISING,
   TIMER_EXCLK_FALLING,

}timer_clksource;

typedef enum{
   CTC_PIN_DISCON,
   CTC_PIN_TOGGLE,
   CTC_PIN_CLEAR,
   CTC_PIN_SET,
}ctc_outmode_t;

typedef enum{
   timer0,
   timer1,
   timer2,
}timer_t;

typedef struct
{
   // timer_mode_t mode;
   timer_output_t output_mode;
   timer_clksource prescalar;
   uint8_t int_state;  // 0 or 1
}timer_config_t;

// void timer_init(timer_t timer, timer_config_t config);
void timer0_init();
void timer0_deinit();

void timer1_init();
void timer1_deinit();

void timer2_init();
void timer2_deinit();

void timer_set_state(uint8_t state);
void timer_set_preload(timer_t timer ,uint16_t prelod);
uint16_t timer_get_counter();
void timer_set_int(timer_t timer, uint8_t state);
void timer_set_ctcmode(timer_t timer,ctc_outmode_t mode);
uint8_t timer_is_overflow(timer_t timer);

#endif
