/*
 * STEPM_program.c
 *
 *  Created on: Jul 31, 2024
 *      Author: aya
 */

#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_Math.h"


#include "../../MCAL/DIO/DIO_interface.h"

#include "STEPM_config.h"
#include "STEPM_interface.h"
#include "STEPM_private.h"

static u8 Current_SEQ=0;

void STEPM_voidInit()
{
	for(u8 i=0;i<NUM_OF_COILS;i++)
	{
		DIO_u8SetPinDirection(coils[i].port,coils[i].pin,OUTPUT);
	}
	/*for(u8 i=0;i<NUM_OF_COILS;i++)
		{
			DIO_u8SetPinValue(coils[i].port,coils[i].pin,READ_BIT(Seguence_array[Current_SEQ],i));

		}*/

}

void STEPM_voidStepCW(void)
{

	Current_SEQ++;
	for(u8 i=0;i<NUM_OF_COILS;i++)
	{
		DIO_u8SetPinValue(coils[i].port,coils[i].pin,READ_BIT(Seguence_array[Current_SEQ],i));

	}
	if(Current_SEQ==8)
	{
		Current_SEQ=0;
	}

}

void STEPM_voidStepCCW(void)
{
	Current_SEQ--;
	for(u8 i=0;i<NUM_OF_COILS;i++)
	{
		DIO_u8SetPinValue(coils[i].port,coils[i].pin,READ_BIT(Seguence_array[Current_SEQ],i));

	}
	if(Current_SEQ>7)
	{
		Current_SEQ=0;
	}

}


