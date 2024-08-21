/*
 * APP_program.c
 *
 *  Created on: Jul 31, 2024
 *      Author: aya
 */

#include <util/delay.h>

#include "../LIB/STD_Types.h"
#include "../LIB/errorState.h"


#include "../HAL/LCD/LCD_int.h"

#include "APP_config.h"
#include "APP_private.h"


void APP_voidInit()
{
	LCD_enuInit();

	LCD_enuDisplayString(SCROLL_MESSAGE);
}

void APP_voidScrollText()
{

	for (u8 j = 0; j < 32; j++)
	{
		LCD_enuSendCommand(LCD_SHIFT_ENTRIE_DISPLAY_TO_RIGHT);
		_delay_ms(300); // Adjust delay for scrolling speed
	}
}

void APP_voidCreateCustomChar(u8 loc, u8 *pattern)
{
    if (loc < 8)
    {
    	 LCD_enuSendCommand(LCD_GO_TO_CGRAM + (loc * 8)); // Set CGRAM address
        for (u8 i = 0; i < 8; i++)
        {
            LCD_enuDisplayChar(pattern[i]);
        }
    }
}


void APP_voidDisplay_Custom_Chars(u8 loc)
{
	static u8 i=0;
	if(i==0)
	{
		LCD_enuSendCommand(LCD_FORCE_CURSOR_START_SECOND_LINE); // Set cursor to Seconed line
		i++;
	}

    LCD_enuDisplayChar(loc);

}
