/*
 * APP_prog.c
 *
 *  Created on: Aug 13, 2024
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

#include "../HAL/Servo_Motor/Servo_int.h"

#include "../HAL/EEPROM/EEPROM_int.h"

#include "APP_config.h"
#include "APP_priv.h"





extern LED_t LED_AstrLedConfig[LED_NUM];

static volatile u8 LOCK_Password[5]="1234\0";

static volatile u8 EEPROM_Address=0;


ES_t APP_enuInit(void)
{
	ES_t Local_enuErrorState=ES_NOK;

	Local_enuErrorState =DIO_enuSetPinDirection(DIO_u8PORTC,DIO_u8PIN0,DIO_u8INPUT);
	Local_enuErrorState =DIO_enuSetPinDirection(DIO_u8PORTC,DIO_u8PIN1,DIO_u8INPUT);

	Local_enuErrorState =DIO_enuSetPinValue(DIO_u8PORTC,DIO_u8PIN0,DIO_u8LOW);
	Local_enuErrorState =DIO_enuSetPinValue(DIO_u8PORTC,DIO_u8PIN1,DIO_u8LOW);

	Local_enuErrorState =EEPROM_enuInit();
	Local_enuErrorState =SERVO_enudInit();
	Local_enuErrorState =KEYPAD_enuInit();
	Local_enuErrorState =LCD_enuInit();
	Local_enuErrorState =LED_enuInit(LED_AstrLedConfig);

	//SAVE PASSWORD IN EEPROM
	for(u8 i=0;i<4;i++)
	{
		Local_enuErrorState= EEPROM_enuWriteData(EEPROM_Address,LOCK_Password[i]);
		_delay_ms(10);
		EEPROM_Address++;
	}
	Local_enuErrorState =SERVO_enuSetAngle(-90);//Door closed Initially

	return Local_enuErrorState;
}



ES_t APP_enuLogin(void)
{
	ES_t Local_enuErrorState =ES_NOK;

	u8 key,i=0;
	u8 APP_Password[5];

	LCD_enuClearLcd();
	LED_enuTurnOFF(&LED_AstrLedConfig[0]);
	LED_enuTurnOFF(&LED_AstrLedConfig[1]);
	LCD_enuDisplayString("Pass=");

	for(i=0; i<4; i++)
	{
		key = KEYPAD_u8GetPressedKey();
		  if(key != KPD_NO_PRESSED_KEY)
		  {
			  APP_Password[i]=key;
			 LCD_enuDisplayChar('*');
		  }
		  if(key == KPD_NO_PRESSED_KEY)
		  {
			  i--;
		  }

	}

	if (Check(APP_Password)==ES_OK)
	{
		LCD_enuClearLcd();
		LCD_enuDisplayString("Access Granted");
		// Turn on Green Led
		LED_enuTurnON(&LED_AstrLedConfig[0]);//Green LED
		LED_enuTurnOFF(&LED_AstrLedConfig[1]);//RED LED
		SERVO_enuSetAngle(90);//open Door
		_delay_ms(5000);
		SERVO_enuSetAngle(-90);

		Local_enuErrorState=ES_OK;
	}else
	{
		LCD_enuClearLcd();
		LCD_enuDisplayString("Access Denied");
		// Turn on RED Led
		LED_enuTurnON(&LED_AstrLedConfig[1]);//RED LED
		LED_enuTurnOFF(&LED_AstrLedConfig[0]);//Green LED
		_delay_ms(2000);
		Local_enuErrorState=ES_NOK;

	}
	return Local_enuErrorState;
}

ES_t Check(const u8* str1)
{
	ES_t Local_enuErrorState=ES_NOK;

		u8 key=0;

	for(u8 i=0;i<EEPROM_Address;i++)
	{
		EEPROM_enuReadData(i,&key);

		if(str1[i]!=key)
		{
			Local_enuErrorState=ES_NOK;
			break;
		}
		else
		{
			Local_enuErrorState=ES_OK;
		}
	}

	return Local_enuErrorState;
}

ES_t APP_enuChangePass(void)
{
	ES_t Local_enuErrorState=ES_NOK;

	LCD_enuClearLcd();
	LCD_enuDisplayString("FOR Change pass ");
	LCD_enuGoToPosition(2,1);
	LCD_enuDisplayString("Press % :");
	u8 key=0;
	for(; ; )
	{
		key = KEYPAD_u8GetPressedKey();
		if(key != KPD_NO_PRESSED_KEY)
		{
			LCD_enuDisplayChar(key);
			break;
		}
	}
	if(key=='%')
	{
		//APP_enuGetNewPass();
		Local_enuErrorState=ES_OK;
	}
	else
	{
		LCD_enuClearLcd();
		LCD_enuGoToPosition(1,1);
		LCD_enuDisplayString("Wrong key");
		_delay_ms(3000);
		Local_enuErrorState=ES_NOK;
	}

	return Local_enuErrorState;
}

ES_t APP_enuGetNewPass(void)
{
	ES_t Local_enuErrorState=ES_NOK;

	LCD_enuClearLcd();
	LCD_enuDisplayString("New pass:");
	for(u8 i=0; i<4; i++)
	{
		u8 key = KEYPAD_u8GetPressedKey();
		if(key != KPD_NO_PRESSED_KEY)
		{
			LCD_enuDisplayChar('*');
			EEPROM_enuWriteData(i,key);
			_delay_ms(10);
		}
		if(key == KPD_NO_PRESSED_KEY)
		{
			i--;
		}

	}
	Local_enuErrorState=ES_OK;

	return Local_enuErrorState;
}




