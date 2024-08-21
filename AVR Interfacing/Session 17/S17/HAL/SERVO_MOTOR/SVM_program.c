/*
 * SVM_program.c
 *
 *  Created on: Aug 5, 2024
 *      Author: aya
 */

#include "../../LIB/BIT_Math.h"
#include "../../LIB/STD_Types.h"

#include "../../MCAL/DIO/DIO_interface.h"
#include "../../MCAL/TIMER1/TIMER1_interface.h"

#include "SVM_config.h"
#include "SVM_interface.h"
#include "SVM_private.h"

void SVM_voidInit(void)
{
	DIO_u8SetPinDirection(PORTD,PIN5,OUTPUT);

	TIM1_voidInitPWM();
	TIM1_voidPWMSetMode(SVM_CHANNEL,PWM_NONINVERT);
	TIM1_voidSetPeriod(SVM_PERIOD);
	TIM1_voidStartPWM();

}

void SVM_voidSetAngle(s8 angle)
{
	angle+=90;
	u32 T_ON=1000+((u32)angle*1000/180);
	TIM1_voidSetTON(SVM_CHANNEL,T_ON);
}
