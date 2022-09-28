#ifndef SERVO_H
#define SERVO_H
#include "..\Common_Macros.h"
#include "..\dio\dio.h"

void servo_init();
void servo_cnt(uint8_t position);
void servo_task();
#endif
