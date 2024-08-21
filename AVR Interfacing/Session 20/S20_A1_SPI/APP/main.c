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

#include "../MCAL/SPI/SPI_int.h"


#define CODE        1


#if CODE==1

int main()
{
	DIO_enuSetPinDirection(DIO_u8PORTB,DIO_u8PIN5,DIO_u8OUTPUT);
	DIO_enuSetPinDirection(DIO_u8PORTB,DIO_u8PIN6,DIO_u8INPUT);
	DIO_enuSetPinDirection(DIO_u8PORTB,DIO_u8PIN7,DIO_u8OUTPUT);
	SPI_enuMaster_Init();
	SPI_enuSPIEnable();
	u8 Value=0;
	u8 arr[]="ayart";
	u8 i=0;

	while(1)
	{
		while(arr[i]!='\0')
		{
			SPI_enuTranceive(arr[i],&Value);
			_delay_ms(200);
			i++;

		}
		i=0;

		/*for(u8 i=0;i<8;i++)
		{
			SPI_enuTranceive(i,&Value);
						_delay_ms(200);
		}*/

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


















