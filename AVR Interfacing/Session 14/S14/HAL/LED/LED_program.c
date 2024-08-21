/*
 * LED_program.c
 *
 *  Created on: Jul 25, 2024
 *      Author: aya
 */

#include "../../LIB/STD_Types.h"

#include "../../MCAL/DIO/DIO_interface.h"

#include "LED_interface.h"
#include "LED_private.h"


void LED_voidInit()
{
	DIO_u8SetPinDirection(LED1_PORT,LED1_PIN,OUTPUT);
	DIO_u8SetPinDirection(LED2_PORT,LED2_PIN,OUTPUT);

}


void LED_voidSetLedHigh(u8 L_u8Led)
{
	switch(L_u8Led)
	{
	case LED1:
		DIO_u8SetPinValue(LED1_PORT,LED1_PIN,HIGH);
		break;
	case LED2:
		DIO_u8SetPinValue(LED2_PORT,LED2_PIN,HIGH);
		break;

	}

}

void LED_voidSetLedLow(u8 L_u8Led)
{
	switch(L_u8Led)
	{
	case LED1:
		DIO_u8SetPinValue(LED1_PORT,LED1_PIN,LOW);
		break;
	case LED2:
		DIO_u8SetPinValue(LED2_PORT,LED2_PIN,LOW);
		break;

	}

}
