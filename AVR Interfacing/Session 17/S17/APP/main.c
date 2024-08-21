/*
 * main.c
 *
 *  Created on: Jul 25, 2024
 *      Author: aya
 */

#include <util/delay.h>

#include "../LIB/STD_Types.h"

#include "../MCAL/DIO/DIO_interface.h"

#include "../MCAL/TIMER1/TIMER1_interface.h"

#include "../HAL/SERVO_MOTOR/SVM_interface.h"



#define  F_CPU  8000000ul



int main()
{
	SVM_voidInit();
	//SVM_voidSetAngle(30);
	/*TIM1_voidInitPWM();
	TIM1_voidSetPeriod(10000);
	TIM1_voidSetDutyCycle(PWM_OCR1A,80);
	TIM1_voidStartPWM();
	DIO_u8SetPinDirection(PORTD,PIN5,OUTPUT);*/

	while(1)
	{
		for(s8 i=-90;i<=90;i=i+5)
		{
			SVM_voidSetAngle(i);
			_delay_ms(1000);
		}

	}



	return 0;
}
