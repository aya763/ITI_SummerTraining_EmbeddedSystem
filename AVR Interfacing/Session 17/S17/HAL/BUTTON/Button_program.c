/*
 * Button_program.c
 *
 *  Created on: Jul 28, 2024
 *      Author: aya
 */

#include "../../LIB/STD_Types.h"


#include "../../MCAL/DIO/DIO_interface.h"

#include "Button_interface.h"
#include "Button_private.h"
#include "Button_config.h"


void Button_Init()
{
	//set direction
	DIO_u8SetPinDirection(BUTTON1_PORT,BUTTON1_PIN,INPUT);
	DIO_u8SetPinDirection(BUTTON2_PORT,BUTTON2_PIN,INPUT);

	// Enable pull up
	DIO_u8SetPinValue(BUTTON1_PORT,BUTTON1_PIN,HIGH);
	DIO_u8SetPinValue(BUTTON2_PORT,BUTTON2_PIN,HIGH);
}


u8 Button_u8GetButtonStatus(u8 L_u8ButtonNum)
{
	switch(L_u8ButtonNum)
	{
	case BUTTON1:
		DIO_u8GetPinValue(BUTTON1_PORT,BUTTON1_PIN);
		break;
	case BUTTON2:
		DIO_u8GetPinValue(BUTTON2_PORT,BUTTON2_PIN);
		break;

	}
}

void Button_voidWaitForButton(u8 L_u8ButtonNum);
