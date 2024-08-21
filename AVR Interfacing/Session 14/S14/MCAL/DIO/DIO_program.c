/*
 * DIO_program.c
 *
 *  Created on: Jul 25, 2024
 *      Author: aya
 */

#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_Math.h"


#include "DIO_interface.h"
#include "DIO_private.h"


u8 DIO_u8SetPinValue(u8 L_u8Port , u8 L_u8Pin ,u8 L_u8Value)
{
	if(L_u8Value==HIGH)
	{
		switch(L_u8Port)
		{
		case PORTA:
			SET_BIT(PORTA_Register,L_u8Pin);
			break;
		case PORTB:
			SET_BIT(PORTB_Register,L_u8Pin);
			break;
		case PORTC:
			SET_BIT(PORTC_Register,L_u8Pin);
			break;
		case PORTD:
			SET_BIT(PORTD_Register,L_u8Pin);
			break;
		}
	}
	else if(L_u8Value==LOW)
	{
		switch(L_u8Port)
		{
		case PORTA:
			CLEAR_BIT(PORTA_Register,L_u8Pin);
			break;
		case PORTB:
			CLEAR_BIT(PORTB_Register,L_u8Pin);
			break;
		case PORTC:
			CLEAR_BIT(PORTC_Register,L_u8Pin);
			break;
		case PORTD:
			CLEAR_BIT(PORTD_Register,L_u8Pin);
			break;
		}
	}
	else
	{
		return DIO_ERROR;
	}
	return DIO_NOERROR;

}

u8 DIO_u8SetPinDirection(u8 L_u8Port , u8 L_u8Pin ,u8 L_u8Direction)
{
	if(L_u8Direction==OUTPUT)
	{
		switch(L_u8Port)
		{
		case PORTA:
			SET_BIT(DDRA_Register,L_u8Pin);
			break;
		case PORTB:
			SET_BIT(DDRB_Register,L_u8Pin);
			break;
		case PORTC:
			SET_BIT(DDRC_Register,L_u8Pin);
			break;
		case PORTD:
			SET_BIT(DDRD_Register,L_u8Pin);
			break;
		}
	}
	else if(L_u8Direction==INPUT)
	{
		switch(L_u8Port)
		{
		case PORTA:
			CLEAR_BIT(DDRA_Register,L_u8Pin);
			break;
		case PORTB:
			CLEAR_BIT(DDRB_Register,L_u8Pin);
			break;
		case PORTC:
			CLEAR_BIT(DDRC_Register,L_u8Pin);
			break;
		case PORTD:
			CLEAR_BIT(DDRD_Register,L_u8Pin);
			break;
		}
	}
	else
	{
		return DIO_ERROR;
	}
	return DIO_NOERROR;

}


u8 DIO_u8SetPortValue(u8 L_u8Port ,u8 L_u8Value)
{
	switch(L_u8Port)
	{
	case PORTA:
		PORTA_Register=L_u8Value;
		break;
	case PORTB:
		PORTB_Register=L_u8Value;
		break;
	case PORTC:
		PORTC_Register=L_u8Value;
		break;
	case PORTD:
		PORTD_Register=L_u8Value;
		break;
	default:
		return DIO_ERROR;
	}
	return DIO_NOERROR;
}

u8 DIO_u8SetPortDirection(u8 L_u8Port ,u8 L_u8Direction)
{
	switch(L_u8Port)
	{
	case PORTA:
		PORTA_Register=L_u8Direction;
		break;
	case PORTB:
		PORTB_Register=L_u8Direction;
		break;
	case PORTC:
		PORTC_Register=L_u8Direction;
		break;
	case PORTD:
		PORTD_Register=L_u8Direction;
		break;
	default:
		return DIO_ERROR;
	}
	return DIO_NOERROR;
}


u8 DIO_u8GetPinValue(u8 L_u8Port ,u8 L_u8Pin)
{
	u8 L_u8Result;
	switch(L_u8Port)
	{
	case PORTA:
		L_u8Result = (PINA_Register>>L_u8Pin)&1;
		break;
	case PORTB:
		L_u8Result = (PINB_Register>>L_u8Pin)&1;
		break;
	case PORTC:
		L_u8Result = (PINC_Register>>L_u8Pin)&1;
		break;
	case PORTD:
		L_u8Result = (PIND_Register>>L_u8Pin)&1;
		break;
	default:
		return DIO_ERROR;
	}
	return L_u8Result;
}









