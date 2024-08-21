/*
 * AB_prog.c
 *
 *  Created on: Jul 31, 2024
 *      Author: aya
 */

#include "../../LIB/STD_Types.h"
#include "../../LIB/errorState.h"

#include "../../MCAL/DIO/DIO_interface.h"

#include "AB_config.h"
#include "AB_priv.h"

static volatile u8 AB_u8Activate=0;

ES_t AB_voidInit(void)
{
	ES_t Local_enuErrorState=ES_NOK;
	Local_enuErrorState=DIO_enuSetPinDirection(AB_PORT,AB_PIN,DIO_u8OUTPUT);
	Local_enuErrorState=DIO_enuSetPinValue(AB_PORT,AB_PIN,DIO_u8LOW);
	return Local_enuErrorState;
}

ES_t AB_voidActivate(void)
{
	ES_t Local_enuErrorState=ES_NOK;
	Local_enuErrorState=DIO_enuSetPinValue(AB_PORT,AB_PIN,DIO_u8HIGH);
	AB_u8Activate=1;
	return Local_enuErrorState;
}
ES_t AB_voidDeActivate(void)
{
	ES_t Local_enuErrorState=ES_NOK;
	if(AB_u8Activate)
	{
		Local_enuErrorState=DIO_enuSetPinValue(AB_PORT,AB_PIN,DIO_u8LOW);
		AB_u8Activate=0;
	}
	return Local_enuErrorState;
}
