/*
 * TIMER0_program.c
 *
 *  Created on: Aug 1, 2024
 *      Author: aya
 */

#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_Math.h"

#include "TIMER0_interface.h"
#include "TIMER0_private.h"
#include "TIMER0_config.h"


u32 preload,NoCounts;
void (* func_ptr)(void);
void (* func_ptr_ctc)(void);


void TIMER0_voidInit(void)
{
#if TIMER0_MODE==TIMER0_NORMAL
	//NORMAL MODE
	CLEAR_BIT(TCCR0_Register,WGM00);
	CLEAR_BIT(TCCR0_Register,WGM01);

	//Enable Interrupt
	SET_BIT(TIMSK_Register,TOIE0);

#elif TIMER0_MODE==TIMER0_CTC
	CLEAR_BIT(TCCR0_Register,WGM00);
	SET_BIT(TCCR0_Register,WGM01);

		//Enable Interrupt
		SET_BIT(TIMSK_Register,OCIE0);

#endif





}

void TIMER0_voidSetValueMS(u32 us)
{
#if TIMER0_MODE==TIMER0_NORMAL
	//F_CPU=8MHZ
	//prescaler:8
	//Timer FREQ=1MHZ
	//Tick Time=1uS
	//OVF= 2^(8 bits)*1uS=256uS

	NoCounts=us/256;
	u32 mod=us%256;

	preload=256-mod;

	TCNT0_Register=preload;

#elif TIMER0_MODE==TIMER0_CTC

	//1mS/1uS=1000counts
	for(u8 i=255;i>=0;i--)
	{
		if(us%i==0)
		{
			OCR0_Register=i;
			NoCounts=us/i;
			break;
		}
	}




#endif


	//Set prescaler 8
		CLEAR_BIT(TCCR0_Register,CS00);
		SET_BIT(TCCR0_Register,CS01);
		CLEAR_BIT(TCCR0_Register,CS02);
}

void TIMER0_voidDisable(void)
{
	//Set prescaler 8
		CLEAR_BIT(TCCR0_Register,CS00);
		CLEAR_BIT(TCCR0_Register,CS01);
		CLEAR_BIT(TCCR0_Register,CS02);
}

void TIMER0_voidSetCallbackCTC(void(*ptr)(void))
{
	func_ptr_ctc=ptr;
}


void __vector_11(void)
{
	static u32 counter=0;

	if(counter==(NoCounts))
	{
		func_ptr();
		counter=0;
		TCNT0_Register=preload;
	}
	counter++;
}

void __vector_10(void)
{
	static u32 counter=0;

	if(counter==(NoCounts))
	{
		func_ptr_ctc();
		counter=0;

	}
	counter++;
}




