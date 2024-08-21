/*
 * TIMER1_program.c
 *
 *  Created on: Aug 5, 2024
 *      Author: aya
 */

#include "../../LIB/BIT_Math.h"
#include "../../LIB/STD_Types.h"


#include "TIMER1_config.h"
#include "TIMER1_interface.h"
#include "TIMER1_private.h"



void TIM1_voidInitPWM(void)
{
	//Mode 14 >> Fast PWM
	CLEAR_BIT(TCCR1A_Register,TCCR1A_WGM10);
	SET_BIT(TCCR1A_Register,TCCR1A_WGM11);
	SET_BIT(TCCR1B_Register,TCCR1B_WGM12);
	SET_BIT(TCCR1B_Register,TCCR1B_WGM13);



	//SET MODE
	CLEAR_BIT(TCCR1A_Register,TCCR1A_COM1A0);
	SET_BIT(TCCR1A_Register,TCCR1A_COM1A1);

	CLEAR_BIT(TCCR1A_Register,TCCR1A_COM1B0);
	SET_BIT(TCCR1A_Register,TCCR1A_COM1B1);

}

void TIM1_voidStartPWM(void)
{

	//Select prescaler
	CLEAR_BIT(TCCR1B_Register,TCCR1B_CS12);
	SET_BIT(TCCR1B_Register,TCCR1B_CS11);
	CLEAR_BIT(TCCR1B_Register,TCCR1B_CS10);
}

void TIM1_voidSetDutyCycle(u8 channel,u8 duty)
{
	u32 T_ON=(u32)duty*ICR1_Register/100;
	switch(channel)
	{
	case PWM_OCR1A:
		OCR1A_Register=(u16)T_ON;
		break;
	case PWM_OCR1B:
		OCR1B_Register=(u16)T_ON;
		break;
	}
}

void TIM1_voidSetPeriod(u16 us )
{
	ICR1_Register=us;
}

void TIM1_voidPWMSetMode(u8 mode,u8 channel)
{
	switch(channel)
	{
	case PWM_OCR1A:
		TCCR1A_Register &= ~(0b11 <<TCCR1A_COM1A0);
		TCCR1A_Register |= (mode<<TCCR1A_COM1A0);
		break;
	case PWM_OCR1B:
		TCCR1A_Register &= ~(0b11 <<TCCR1A_COM1B0);
		TCCR1A_Register |= (mode<<TCCR1A_COM1B0);
		break;
	}

}

void TIM1_voidSetTON(u8 channel,u16 us )
{
	switch(channel)
	{
	case PWM_OCR1A:
		OCR1A_Register=(u16)us;
		break;
	case PWM_OCR1B:
		OCR1B_Register=(u16)us;
		break;
	}
}


