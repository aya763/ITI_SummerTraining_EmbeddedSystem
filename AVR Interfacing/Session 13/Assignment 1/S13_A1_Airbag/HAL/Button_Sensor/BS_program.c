/*
 * BS_program.c
 *
 *  Created on: Jul 31, 2024
 *      Author: aya
 */

#include "../../LIB/STD_Types.h"
#include "../../LIB/errorState.h"

#include "../../MCAL/EINT/INT_config.h"
#include "../../MCAL/EINT/INT_int.h"

#include "../../MCAL/GIE/GIE_int.h"

#include "../../MCAL/DIO/DIO_interface.h"

#include "BS_config.h"
#include "BS_private.h"


extern EINT_t EINT_tstrEINTcofig[3];

static volatile u8 BS_u8Collsion_Happened=0;


ES_t BS_voidInit(void)
{
	ES_t Local_enuErrorState=ES_NOK;

	Local_enuErrorState= DIO_enuSetPinDirection(BS_PORT,BS_PIN,DIO_u8INPUT);
	Local_enuErrorState= DIO_enuSetPinValue(BS_PORT,BS_PIN,DIO_u8PULL_UP);
	Local_enuErrorState= EINT_enuInit(EINT_tstrEINTcofig);
	Local_enuErrorState= EINT_enuCallBack(BS_InterruptCall,NULL,BS_INT_ID);
	Local_enuErrorState= EINT_enuEnableINT(BS_INT_ID);
	Local_enuErrorState= GIE_enuEnable();

	return Local_enuErrorState;

}

ES_t BS_CheckCollsion(u8 * Copy_pu8State)
{
	ES_t Local_enuErrorState=ES_NOK;
	if(Copy_pu8State!=NULL)
	{
		if(BS_u8Collsion_Happened)
		{
			*Copy_pu8State=BS_u8Collsion_Happened;
			BS_u8Collsion_Happened=0;
		}
		else
		{
			*Copy_pu8State=BS_u8Collsion_Happened;
		}
		Local_enuErrorState=ES_OK;
	}
	else
	{
		Local_enuErrorState=ES_NULL_POINTER;
	}

	return Local_enuErrorState;
}

static void BS_InterruptCall(void)
{
	BS_u8Collsion_Happened=1;
}




