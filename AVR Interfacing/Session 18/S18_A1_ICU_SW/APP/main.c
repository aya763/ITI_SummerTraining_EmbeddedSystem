/*
 * main.c
 *
 *  Created on: Jul 25, 2024
 *      Author: aya
 */



#include "../LIB/STD_Types.h"
#include "../LIB/errorState.h"


//#include "../HAL/PWM/PWM_int.h"

#include "APP_interface.h"



int main()
{
	APP_enuInit();


	while(1)
	{
		APP_enuDisplayCaptureUnit();
	}

	return 0;
}




















