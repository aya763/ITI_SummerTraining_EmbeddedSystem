/*
 * main.c
 *
 *  Created on: Jul 25, 2024
 *      Author: aya
 */

#include <util/delay.h>

#include "../LIB/STD_Types.h"
#include "../LIB/errorState.h"

#include "../HAL/Button_Sensor/BS_interface.h"

#include "../HAL/AIRBAG/AB_int.h"


#define F_CPU  8000000ul




int main()
{

	BS_voidInit();
	AB_voidInit();
	u8 Check=0;

	while(1)
	{
		BS_CheckCollsion(&Check);
		if(Check==1)
		{
			AB_voidActivate();
			_delay_ms(5000);
		}
		else
		{
			AB_voidDeActivate();
		}

	}

	return 0;
}




















