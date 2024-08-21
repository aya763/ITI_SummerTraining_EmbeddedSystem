/*
 * APP_program.c
 *
 *  Created on: Jul 31, 2024
 *      Author: aya
 */

#include <util/delay.h>

#include "../LIB/STD_Types.h"
#include "../LIB/errorState.h"


#include "../MCAL/GIE/GIE_int.h"

#include "../HAl/LCD/LCD_int.h"

#include "../HAL/ICU_SW/ICU_SW_int.h"

#include "APP_config.h"
#include "APP_private.h"






static u16 TON=0,Period=0;



ES_t APP_enuInit()
{
	ES_t Local_enuErrorState=ES_NOK;

	Local_enuErrorState= LCD_enuInit();

	Local_enuErrorState= ICU_SW_enuInit();

	Local_enuErrorState= GIE_enuEnable();




	return Local_enuErrorState;
}


ES_t APP_enuDisplayCaptureUnit(void)
{
	ES_t Local_enuErrorState=ES_NOK;



	Local_enuErrorState =ICU_SW_enuGetONTime(&TON);
	Local_enuErrorState =ICU_SW_enuGetPeriod(&Period);


	Local_enuErrorState =LCD_enuGoToPosition(1,1);
	Local_enuErrorState =LCD_enuDisplayString("TON= ");
	Local_enuErrorState =LCD_enuSendSpecialNumber(TON);
	Local_enuErrorState =LCD_enuGoToPosition(2,1);
	Local_enuErrorState =LCD_enuDisplayString("Period= ");
	Local_enuErrorState =LCD_enuSendSpecialNumber(Period);

	_delay_ms(1000);
	LCD_enuClearLcd();
	return Local_enuErrorState;
}






