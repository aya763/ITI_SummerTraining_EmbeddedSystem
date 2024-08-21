/*
 * main.c
 *
 *  Created on: Jul 25, 2024
 *      Author: aya
 */

#include <util/delay.h>

#include "../LIB/STD_Types.h"
#include "../LIB/errorState.h"

#include "../HAL/LCD/LCD_int.h"

#include "APP_interface.h"



#define F_CPU  8000000ul


u8 alef[8] = {
    0b00000111,
	0b00000100,
    0b00011111,
    0b00000000,
    0b00000110,
    0b00000110,
    0b00000110,
    0b00000110
};

u8 ya[8] = {
    0b00000000,
    0b00000011,
    0b00000011,
    0b00000011,
    0b00011111,
    0b00000000,
    0b00011011,
    0b00011011
};


u8 ta_marbuta[8] = {
    0b00001010,
    0b00000000,
    0b00001110,
    0b00001010,
    0b00000111,
    0b00000000,
	0b00000000,
	0b00000000
};




int main()
{
	APP_voidInit();
	APP_voidCreateCustomChar(0, alef);
	APP_voidCreateCustomChar(1, ya);
	APP_voidCreateCustomChar(2, ta_marbuta);

	APP_voidDisplay_Custom_Chars(2);
	APP_voidDisplay_Custom_Chars(1);
	APP_voidDisplay_Custom_Chars(0);


	_delay_ms(1000);

	while(1)
	{
		APP_voidScrollText();
	}

	return 0;
}




















