/*
 * main.c
 *
 *  Created on: Jul 25, 2024
 *      Author: aya
 */

#include <util/delay.h>

#include "../LIB/STD_Types.h"
#include "../LIB/errorState.h"



#include "APP_int.h"




int main()
{

	APP_enuInit();


	while(1)
	{
		if(APP_enuLogin()==ES_OK)
		{
			while(1)
			{
				if(APP_enuChangePass()==ES_OK)
				{
					APP_enuGetNewPass();
					break;
				}
			}
		}


	}

	return 0;
}




















