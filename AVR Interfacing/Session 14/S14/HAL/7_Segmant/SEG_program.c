/*
 * SEG_program.c
 *
 *  Created on: Jul 28, 2024
 *      Author: aya
 */

#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_Math.h"

#include "../../MCAL/DIO/DIO_interface.h"


#include "SEG_config.h"
#include "SEG_interface.h"
#include "SEG_private.h"



void SEG_voidInit(void)
{
	DIO_u8SetPinDirection(SEG_PORTA,SEG_PINA,OUTPUT);
	DIO_u8SetPinDirection(SEG_PORTB,SEG_PINB,OUTPUT);
	DIO_u8SetPinDirection(SEG_PORTC,SEG_PINC,OUTPUT);
	DIO_u8SetPinDirection(SEG_PORTD,SEG_PIND,OUTPUT);
	DIO_u8SetPinDirection(SEG_PORTE,SEG_PINE,OUTPUT);
	DIO_u8SetPinDirection(SEG_PORTF,SEG_PINF,OUTPUT);
	DIO_u8SetPinDirection(SEG_PORTG,SEG_PING,OUTPUT);
	DIO_u8SetPinDirection(SEG_PORTH,SEG_PINH,OUTPUT);


	SEG_voidClear();

}

void SEG_voidDisplayNum(u8 L_u8Num)
{
	if(L_u8Num>=0 && L_u8Num<10)
	{
		DIO_u8SetPinValue(SEG_PORTA,SEG_PINA,!READ_BIT(SEG_ARRNum[L_u8Num],0));
		DIO_u8SetPinValue(SEG_PORTB,SEG_PINB,!READ_BIT(SEG_ARRNum[L_u8Num],1));
		DIO_u8SetPinValue(SEG_PORTC,SEG_PINC,!READ_BIT(SEG_ARRNum[L_u8Num],2));
		DIO_u8SetPinValue(SEG_PORTD,SEG_PIND,!READ_BIT(SEG_ARRNum[L_u8Num],3));
		DIO_u8SetPinValue(SEG_PORTE,SEG_PINE,!READ_BIT(SEG_ARRNum[L_u8Num],4));
		DIO_u8SetPinValue(SEG_PORTF,SEG_PINF,!READ_BIT(SEG_ARRNum[L_u8Num],5));
		DIO_u8SetPinValue(SEG_PORTG,SEG_PING,!READ_BIT(SEG_ARRNum[L_u8Num],6));
		DIO_u8SetPinValue(SEG_PORTH,SEG_PINH,!READ_BIT(SEG_ARRNum[L_u8Num],7));
	}
	else
	{
		// nothing
	}
}

void SEG_voidClear(void)
{
	DIO_u8SetPinValue(SEG_PORTA,SEG_PINA,LOW);
	DIO_u8SetPinValue(SEG_PORTB,SEG_PINB,LOW);
	DIO_u8SetPinValue(SEG_PORTC,SEG_PINC,LOW);
	DIO_u8SetPinValue(SEG_PORTD,SEG_PIND,LOW);
	DIO_u8SetPinValue(SEG_PORTE,SEG_PINE,LOW);
	DIO_u8SetPinValue(SEG_PORTF,SEG_PINF,LOW);
	DIO_u8SetPinValue(SEG_PORTG,SEG_PING,LOW);
	DIO_u8SetPinValue(SEG_PORTH,SEG_PINH,LOW);
}


