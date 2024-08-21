/*
 * main.c
 *
 *  Created on: Jul 25, 2024
 *      Author: aya
 */



#include "../LIB/STD_Types.h"
#include "../LIB/errorState.h"


#include "../HAL/PWM/PWM_int.h"





int main()
{
	PWM_enuInit();
	PWM_enuSetPeriod(10000);
	PWM_enuSetDutyCyle(30);

	while(1)
	{


	}

	return 0;
}




















