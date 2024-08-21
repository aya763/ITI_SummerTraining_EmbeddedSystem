/*
 * APP_program.c
 *
 *  Created on: Jul 31, 2024
 *      Author: aya
 */



#include "../LIB/STD_Types.h"
#include "../LIB/errorState.h"

#include "../MCAL/EINT/INT_config.h"
#include "../MCAL/EINT/INT_int.h"

#include "../MCAL/DIO/DIO_interface.h"

#include "../MCAL/GIE/GIE_int.h"

#include "../MCAL/ADC/ADC_int.h"

#include "../HAl/LCD/LCD_int.h"

#include "../HAL/LM35/LM35_config.h"
#include "../HAL/LM35/LM35_int.h"

#include "APP_config.h"
#include "APP_private.h"


extern EINT_t EINT_tstrEINTcofig[3];

extern TR_t LM35_AstrLM35Config[2];




static volatile u8 APP_flag=0;
static volatile f32 APP_adc32=0;


ES_t APP_enuInit()
{
	ES_t Local_enuErrorState=ES_NOK;

	Local_enuErrorState= LCD_enuInit();

	Local_enuErrorState= DIO_enuSetPinDirection(DIO_u8PORTD,DIO_u8PIN2,DIO_u8INPUT);
	Local_enuErrorState= DIO_enuSetPinValue(DIO_u8PORTD,DIO_u8PIN2,DIO_u8PULL_UP);

	Local_enuErrorState= EINT_enuInit(EINT_tstrEINTcofig);
	Local_enuErrorState= EINT_enuSelectSenceLevel(0,FALLING_EDGE);
	Local_enuErrorState= EINT_enuEnableINT(0);

	Local_enuErrorState= ADC_enuEnable();
	Local_enuErrorState= LM35_enuInit(LM35_AstrLM35Config);
	Local_enuErrorState= ADC_enuEnableTriggeringMode(ADC_EXT_INT0_REQ);
	Local_enuErrorState= ADC_enuEnableInterruptMode();
	Local_enuErrorState= ADC_enuCallBack(read_temp ,&APP_adc32);
	Local_enuErrorState= ADC_enuStartConversion();

	Local_enuErrorState= GIE_enuEnable();




	return Local_enuErrorState;
}

//display temperature every interrupt using INT0
ES_t APP_enuDisplayTemp(void)
{
	ES_t Local_enuErrorState=ES_NOK;
	if(APP_flag==1)
	{
		Local_enuErrorState= LCD_enuDisplayString("Temp=");
		Local_enuErrorState= LCD_enuDisplayNum(APP_adc32);
		Local_enuErrorState= LCD_enuDisplayChar(0xDF);
		Local_enuErrorState= LCD_enuDisplayChar('C');
		APP_flag=0;
	}
	return Local_enuErrorState;
}




static void read_temp(void*p)
{
	LCD_enuClearLcd();
	LM35_enuGetTemp((f32 *)p);
	APP_flag=1;
}

