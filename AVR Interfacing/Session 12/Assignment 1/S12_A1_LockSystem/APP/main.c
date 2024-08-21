/*
 * main.c
 *
 *  Created on: Jul 25, 2024
 *      Author: aya
 */

#include <util/delay.h>

#include "../LIB/STD_Types.h"
#include "../LIB/errorState.h"


#include "../MCAL/DIO/DIO_interface.h"

#include "../HAL/LED/LED_config.h"
#include "../HAL/LED/LED_interface.h"

#include "../HAL/LCD/LCD_int.h"

#include "../HAL/KEYPAD/Keypad_config.h"
#include "../HAL/KEYPAD/Keypad_int.h"

#define F_CPU  8000000ul

#define PASS      1234ul


extern LED_t LED_AstrLedConfig[LED_NUM];

ES_t Login(void);


int main()
{
	LED_enuInit(LED_AstrLedConfig);
	KEYPAD_enuInit();
	LCD_enuInit();

	u8 counter=0;
	while(1)
	{
		if(Login()==ES_NOK)
		{
			counter++;
		}

		if(counter==3)
		{
			counter=0;
			LCD_enuClearLcd();
			LCD_enuDisplayString("End of Trial");
			LCD_enuGoToPosition(2,1);
			LCD_enuDisplayString("locked");
			_delay_ms(10000);
		}


	}

	return 0;
}


ES_t Login(void)
{
	ES_t Local_enuErrorState =ES_NOK;

	u8 key,i=0;
	u16 value=0;

	LCD_enuClearLcd();
	LED_enuTurnOFF(&LED_AstrLedConfig[0]);
	LED_enuTurnOFF(&LED_AstrLedConfig[1]);
	LCD_enuDisplayString("Pass=");

	for(i=0; i<4; i++)
	{
		key = KEYPAD_u8GetPressedKey();
		  if(key != KPD_NO_PRESSED_KEY)
		  {
			  value= value*10+(key-'0');
			  LCD_enuDisplayChar('*');
		  }
		  if(key == KPD_NO_PRESSED_KEY)
		  {
			  i--;
		  }

	}
	if (value == PASS)
	{
		LCD_enuClearLcd();
		LCD_enuDisplayString("Unlocked");
		// Turn on Green Led
		LED_enuTurnON(&LED_AstrLedConfig[0]);//Green LED
		LED_enuTurnOFF(&LED_AstrLedConfig[1]);//RED LED
		_delay_ms(5000);
		value =0;
		Local_enuErrorState=ES_OK;
	}else
	{
		LCD_enuClearLcd();
		LCD_enuDisplayString("locked");
		// Turn on RED Led
		LED_enuTurnON(&LED_AstrLedConfig[1]);//RED LED
		LED_enuTurnOFF(&LED_AstrLedConfig[0]);//Green LED
		_delay_ms(2000);
		Local_enuErrorState=ES_NOK;

	}
	return Local_enuErrorState;
}

















