/*
 * main.c
 *
 *  Created on: Jul 25, 2024
 *      Author: aya
 */

#include <util/delay.h>

#include "../LIB/STD_Types.h"
#include "../LIB/errorState.h"

#include "../MCAL/USART/USART_int.h"
#include "../MCAL/DIO/DIO_interface.h"

#include "../HAL/LED/LED_config.h"
#include "../HAL/LED/LED_interface.h"


#define CODE        0


#if CODE==1

int main()
{
	DIO_enuInit();
	DIO_enuSetPinDirection(DIO_u8PORTD,DIO_u8PIN0,DIO_u8INPUT);
	DIO_enuSetPinDirection(DIO_u8PORTD,DIO_u8PIN1,DIO_u8OUTPUT);
	USART_enuInit();
	USART_enuEnableTransmitter();
	USART_enuEnableReceiver();

	while(1)
	{
		USART_enuSendChar('7');
		_delay_ms(1000);
		USART_enuSendChar('8');
		_delay_ms(1000);

	}

	return 0;
}

#elif CODE==0

extern LED_t LED_AstrLedConfig[LED_NUM];

int main()
{
	LED_enuInit(LED_AstrLedConfig);
	DIO_enuInit();
	DIO_enuSetPinDirection(DIO_u8PORTD,DIO_u8PIN0,DIO_u8INPUT);
	DIO_enuSetPinDirection(DIO_u8PORTD,DIO_u8PIN1,DIO_u8OUTPUT);
	USART_enuInit();
	USART_enuEnableTransmitter();
	USART_enuEnableReceiver();
	u8 Char=0;

	while(1)
	{
		USART_enuRecieveChar(&Char);
		if(Char=='7')
		{
			LED_enuTurnON(&LED_AstrLedConfig[0]);
			LED_enuTurnOFF(&LED_AstrLedConfig[1]);
		}
		else if(Char=='8')
		{
			LED_enuTurnON(&LED_AstrLedConfig[1]);
			LED_enuTurnOFF(&LED_AstrLedConfig[0]);
		}

	}

	return 0;
}


#endif


















