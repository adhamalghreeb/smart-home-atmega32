/***************************************************************************************/
/****************************  IMT School Training Center ******************************/
/***************************************************************************************/
/** This file is developed by IMT School training center, All copyrights are reserved**/
/***************************************************************************************/
/* Description ! Keypad driver for 4x4 keypad                                          */
/* Release Date! 28/6/2016                                                             */
/* Version     ! V01                                                                   */
/***************************************************************************************/
///
///test for read
///
///is it ???

/********************************** Header Files INCLUSIONS ****************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "util/delay.h"

#include "C:\Users\Administrator\Desktop\ES ITI\project\pro22\MCAL\dio_keypad\DIO_interface.h"
#include "KPD_interface.h"
/***************************************************************************************/

/************* KeyPad Key Index ***************/                         
/*         Col_3    Col_2   Col_1   Col_0     */
/*	                                          */
/* row_0      1        2       3       4      */
/*	                                          */
/* row_1  	  5        6       7       8      */
/*	                                          */
/* row_2	  9        10      11      12     */
/*	                                          */
/* row_3	  13       14      15      16     */
/**********************************************/


/*************************************** Constants *************************************/
/* Values of the Key Pad switches                                                      */
/* Matrix is not standard it depends on the connection between the Micro and KeyPad    */
const u8 KPD_au8SwitchVal[4][4] =
{
  {
    '7','4','1','%' },
  {
    '8','5','2','0' },
  {
    '9','6','3','=' },
  {
    '/','*','-','+' }
};

/***************************************************************************************/


/***************************************** Macros **************************************/

/***************************************************************************************/
void KPD_voidInit(void)
{
	DIO_u8SetPortDirection(PORT,0b11110000);
	DIO_u8SetPortValue(PORT,0xFF);
}

/***************************************************************************************/
/* Description! Interface to get the ID of the pressed key, return 0 incase no key     */
/*              is pressed, this function doesn't handle the sitaution if 2 keys are   */
/*              pressed at the same time                               	     		   */
/* Input      ! Nothing                                                                */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
u8 KPD_u8GetPressedKey(void)
{

  u8 LOC_u8Column;

  u8 LOC_u8Row;

  u8 LOC_u8PINVAL;
  /* Initialize the switch status to NOT Pressed                                                                     */
  u8 LOC_u8Retrun = NOT_PRESSED;

  /* Looping on columns of the Key Pad                                                                               */
  for (LOC_u8Column = 0 + COL_INIT; LOC_u8Column < COL_FIN; LOC_u8Column++)
  {
    /* Activate the Column                                                                                           */
    DIO_u8SetPinValue(PORT, LOC_u8Column, DIO_u8PIN_LOW);

    /* Loop on the rows of the Key Pad                                                                               */
    for (LOC_u8Row = 0 + ROW_INIT; LOC_u8Row < ROW_FIN; LOC_u8Row++)
    {
      /* Check the status of the switch */
    	DIO_u8GetPinValue(PORT, LOC_u8Row,&LOC_u8PINVAL);
      if (!LOC_u8PINVAL)
      {
        /* Get the value of the currently pressed switch                                                             */
        LOC_u8Retrun = KPD_au8SwitchVal[LOC_u8Column - COL_INIT][LOC_u8Row - ROW_INIT];
        DIO_u8GetPinValue(PORT, LOC_u8Row,&LOC_u8PINVAL);
        /* Wait until the switch is released (Single Press)                                                          */
        while (!LOC_u8PINVAL)
        {
        	DIO_u8GetPinValue(PORT, LOC_u8Row,&LOC_u8PINVAL);
        }

        /* Delay to avoid bouncing                                                                                   */
        _delay_ms(10);

      }
    }

    /* Deactivate the Column                                                                                         */
    DIO_u8SetPinValue(PORT, LOC_u8Column, DIO_u8PIN_HIGH);
  }

  return LOC_u8Retrun;
}
