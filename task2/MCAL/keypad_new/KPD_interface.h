/***************************************************************************************/
/****************************  IMT School Training Center ******************************/
/***************************************************************************************/
/** This file is developed by IMT School training center, All copyrights are reserved **/
/***************************************************************************************/
/* Description ! Keypad driver for 4x4 keypad                                          */
/* Release Date! 28/6/2016                                                             */
/* Version     ! V01                                                                   */
/***************************************************************************************/


#ifndef KPD_H_
#define KPD_H_
#include "STD_TYPES.h"
#define PORT DIO_u8PORTC

#define ROW_INIT   0

#define ROW_FIN    4

#define COL_INIT   4

#define COL_FIN    8

#define NOT_PRESSED    0xff

void KPD_voidInit(void);
/***************************************************************************************/
/* Description! Interface to get the ID of the pressed key, return 0 incase no key     */
/*              is pressed, this function doesn't handle the sitaution if 2 keys are   */
/*              pressed at the same time                               	     		   */
/* Input      ! Nothing                                                                */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
u8 KPD_u8GetPressedKey(void);

#endif /* KPD_H_ */
