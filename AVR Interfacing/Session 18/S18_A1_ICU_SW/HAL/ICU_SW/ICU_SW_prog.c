/*
 * ICU_SW_prog.c
 *
 *  Created on: Aug 7, 2024
 *      Author: aya
 */

#include "../../LIB/STD_Types.h"
#include "../../LIB/errorState.h"

#include "../../MCAL/DIO/DIO_interface.h"

#include "../../MCAL/TIMER/TIMER1/TIMER1_int.h"

#include "../../MCAL/EINT/INT_config.h"
#include "../../MCAL/EINT/INT_int.h"


#include "ICU_SW_config.h"
#include "ICU_SW_priv.h"


extern EINT_t EINT_tstrEINTcofig[3];


static u16 ICU_SW_Period=0,ICU_SW_ONTime=0,ICU_SW_OFFTime=0;



ES_t ICU_SW_enuInit(void)
{
	ES_t Local_enuErrorState=ES_NOK;
#if ICU_SW_EINT_SOURCE==EINT_INT0
	Local_enuErrorState= DIO_enuSetPinDirection(DIO_u8PORTD,DIO_u8PIN2,DIO_u8INPUT);

#elif ICU_SW_EINT_SOURCE==EINT_INT1
	Local_enuErrorState= DIO_enuSetPinDirection(DIO_u8PORTD,DIO_u8PIN3,DIO_u8INPUT);
#elif ICU_SW_EINT_SOURCE==EINT_INT2
	Local_enuErrorState= DIO_enuSetPinDirection(DIO_u8PORTB,DIO_u8PIN2,DIO_u8INPUT);

#else
#error "Attention!!!! ICU_SW_EINT_SOURCE Selection is Wrong "
#endif

	EINT_enuInit(EINT_tstrEINTcofig);
	EINT_enuSelectSenceLevel(ICU_SW_EINT_SOURCE,RISING_EDGE);
	EINT_enuCallBack(&ICU_SW_Process,NULL,ICU_SW_EINT_SOURCE);

	EINT_enuEnableINT(ICU_SW_EINT_SOURCE);

	TIMER1_enuInit();

	return Local_enuErrorState;
}

ES_t ICU_SW_enuGetONTime(u16 *Copy_pu16TON)
{
	ES_t Local_enuErrorState=ES_NOK;

	*Copy_pu16TON=ICU_SW_ONTime;

	return Local_enuErrorState;
}

ES_t ICU_SW_enuGetOFFTime(u16 *Copy_pu16TOFF)
{
	ES_t Local_enuErrorState=ES_NOK;

	*Copy_pu16TOFF=ICU_SW_OFFTime;

	return Local_enuErrorState;
}

ES_t ICU_SW_enuGetPeriod(u16 *Copy_pu16Period)
{
	ES_t Local_enuErrorState=ES_NOK;


	*Copy_pu16Period=ICU_SW_Period;

	return Local_enuErrorState;
}


static void ICU_SW_Process(void)
{



	  static u8 counter=0;
		counter++;

		if(counter==3)
		{
			TIMER1_enuSetTimerValue(0);
		}
		else if(counter==4)
		{
			TIMER1_enuReadTimerValue(&ICU_SW_Period);
			EINT_enuSelectSenceLevel(ICU_SW_EINT_SOURCE,FALLING_EDGE);
		}
		else if(counter==5)
		{
			TIMER1_enuReadTimerValue(&ICU_SW_ONTime);
			ICU_SW_ONTime-=ICU_SW_Period;
			EINT_enuDisableINT(ICU_SW_EINT_SOURCE);
			ICU_SW_OFFTime=ICU_SW_Period-ICU_SW_ONTime;
		}
}


/*static u8 state=ICU_SW_WAITING_FIRST_RISING;
	static u16 temp_ton=0, temp_toff=0;
	switch(state)
	{
	case ICU_SW_WAITING_FIRST_RISING:
		TIMER1_enuSetTimerValue(0);
		state=ICU_SW_WAITING_FALLING;
		EINT_enuSelectSenceLevel(ICU_SW_EINT_SOURCE,FALLING_EDGE);
		break;
	case ICU_SW_WAITING_FALLING:
		TIMER1_enuReadTimerValue(&temp_ton);
		TIMER1_enuSetTimerValue(0);
		EINT_enuSelectSenceLevel(ICU_SW_EINT_SOURCE,RISING_EDGE);
		state=ICU_SW_WAITING_SECOND_RISING;
		break;
	case ICU_SW_WAITING_SECOND_RISING:
		TIMER1_enuReadTimerValue(&temp_toff);
		EINT_enuSelectSenceLevel(ICU_SW_EINT_SOURCE,RISING_EDGE);
		TIMER1_enuSetTimerValue(0);
		state=ICU_SW_WAITING_FIRST_RISING;
		ICU_SW_ONTime=temp_ton;
		ICU_SW_OFFTime=temp_toff;
		ICU_SW_Period=ICU_SW_OFFTime+ICU_SW_ONTime;
		break;
	}*/

















