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

#include "../HAL/SWITCH/Switch_config.h"
#include "../HAL/SWITCH/Switch_int.h"

#include "../HAL/SEG/Seven_segmant_config.h"
#include "../HAL/SEG/Seven_segmant_int.h"


extern SEG_t SEVSEG_AstrSegConfig[SEG_NUM];

extern SW_t Switch_AstrSwitchState [SW_NUM];

#define F_CPU  8000000ul

int main()
{
	Seven_Segmant_enuInit(SEVSEG_AstrSegConfig);
	Switch_enuInit(Switch_AstrSwitchState);
	u8 pinstate, num=0;
	while(1)
	{

			/*Seven_Segmant_enuDisplayNum(1,0);
			for(u8 j=0;j<10;j++)
			{
				Seven_Segmant_enuDisplayNum(1,j);
				_delay_ms(1000);
			}*/

		Seven_Segmant_enuDisplayNum(1,num);

		Switch_enuGetState(&Switch_AstrSwitchState[2],&pinstate);
		if(pinstate==0)
		{
			while(pinstate==0)
			{
				Switch_enuGetState(&Switch_AstrSwitchState[2],&pinstate);
			}
			num++;
		}
		if(num==10)
		{
			num=0;
		}

	}

	return 0;
}
