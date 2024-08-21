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


extern LED_t LED_AstrLedConfig[LED_NUM];



int main()
{
	DIO_enuInit();
	LED_enuInit(LED_AstrLedConfig);


	while(1)
	{
		for(u8 i=0;i<5;i++)
		{
			LED_enuTurnON(&LED_AstrLedConfig[i]);
			_delay_ms(1000);
			LED_enuTurnOFF(&LED_AstrLedConfig[i]);
		}
	}

	return 0;
}
