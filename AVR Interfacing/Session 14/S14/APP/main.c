/*
 * main.c
 *
 *  Created on: Jul 25, 2024
 *      Author: aya
 */

#include <util/delay.h>

#include "../LIB/STD_Types.h"

#include "../MCAL/DIO/DIO_interface.h"


#include "../HAL/STEPPER_MOTOR/STEPM_interface.h"


#define F_CPU  8000000ul




int main()
{
	STEPM_voidInit();

	while(1)
	{
		STEPM_voidStepCW();
		_delay_ms(5000);
	}


	/* Operate DC motor
	DIO_u8SetPinDirection(PORTC,PIN1,OUTPUT);
	DIO_u8SetPinValue(PORTC,PIN1,LOW);


	while(1)
	{
		DIO_u8SetPinValue(PORTC,PIN1,HIGH);
		_delay_ms(1000);
		DIO_u8SetPinValue(PORTC,PIN1,LOW);
		_delay_ms(1000);
	}*/



	return 0;
}
