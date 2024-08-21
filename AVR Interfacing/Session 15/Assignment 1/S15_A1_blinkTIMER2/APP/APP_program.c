/*
 * APP_program.c
 *
 *  Created on: Jul 31, 2024
 *      Author: aya
 */



#include "../LIB/STD_Types.h"
#include "../LIB/errorState.h"

#include "../HAL/LED/LED_config.h"
#include "../HAL/LED/LED_interface.h"

#include "../MCAL/TIMER/TIMER2/TIMER2_int.h"
#include "../MCAL/GIE/GIE_int.h"


extern LED_t LED_AstrLedConfig[LED_NUM];


#include "APP_config.h"
#include "APP_private.h"


ES_t APP_voidInit()
{
	ES_t Local_enuErrorState=ES_NOK;

	LED_enuInit(LED_AstrLedConfig);
	TIMER2_enuInit();
	TIMER2_enuSetCTC(250);
	TIMER2_enuCallBackCTC(blink,NULL);
	TIMER2_enuEnableCTCINTERRUPT();
	GIE_enuEnable();

	return Local_enuErrorState;
}

/* Timing Calculations for blink Led
 * Prescaler=8
 * F_CPU=8MHZ
 * Tick time= 1uS
 * OCR2=250
 * Desired time=500 mS
 * NumofCounts= (500000/(250*1))=2000
 *
 */


static void blink(void)
{
	static u16 Counter=0;
	static u8 state=0;
	if(Counter==2000)
	{

		if(state==0)
		{
			LED_enuTurnON(&LED_AstrLedConfig[0]);
			state=1;
		}
		else
		{
			LED_enuTurnOFF(&LED_AstrLedConfig[0]);
			state=0;
		}
		Counter=0;
	}
	Counter++;
}


