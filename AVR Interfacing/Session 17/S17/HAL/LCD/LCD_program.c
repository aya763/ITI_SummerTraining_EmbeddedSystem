/*
 * LCD_program.c
 *
 *  Created on: Jul 29, 2024
 *      Author: aya
 */

#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_Math.h"

#include <util/delay.h>

#include "../../MCAL/DIO/DIO_interface.h"

#include "LCD_config.h"
#include "LCD_interface.h"
#include "LCD_private.h"


void LCD_voidInit(void)
{
	DIO_u8SetPinDirection(LCD_RS_PORT,LCD_RS_PIN,OUTPUT);
	DIO_u8SetPinDirection(LCD_RW_PORT,LCD_RW_PIN,OUTPUT);
	DIO_u8SetPinDirection(LCD_E_PORT ,LCD_E_PIN,OUTPUT);
	DIO_u8SetPinDirection(LCD_D0_PORT,LCD_D0_PIN,OUTPUT);
	DIO_u8SetPinDirection(LCD_D1_PORT,LCD_D1_PIN,OUTPUT);
	DIO_u8SetPinDirection(LCD_D2_PORT,LCD_D2_PIN,OUTPUT);
	DIO_u8SetPinDirection(LCD_D3_PORT,LCD_D3_PIN,OUTPUT);
	DIO_u8SetPinDirection(LCD_D4_PORT,LCD_D4_PIN,OUTPUT);
	DIO_u8SetPinDirection(LCD_D5_PORT,LCD_D5_PIN,OUTPUT);
	DIO_u8SetPinDirection(LCD_D6_PORT,LCD_D6_PIN,OUTPUT);
	DIO_u8SetPinDirection(LCD_D7_PORT,LCD_D7_PIN,OUTPUT);

	_delay_ms(30);
	LCD_voidSendCommand(LCD_FUNCTION_SET1);
	_delay_ms(1);
	LCD_voidSendCommand(LCD_DISPLAY_MODE1);
	_delay_ms(1);
	LCD_voidSendCommand(LCD_CLEAR);
	_delay_ms(2);
	LCD_voidSendCommand(LCD_ENTRY_MODE1);

}

void LCD_voidSendCommand(u8 L_u8Command)
{
	DIO_u8SetPinValue(LCD_RS_PORT,LCD_RS_PIN,LOW);
	DIO_u8SetPinValue(LCD_RW_PORT,LCD_RW_PIN,LOW);
	DIO_u8SetPinValue(LCD_D0_PORT,LCD_D0_PIN,READ_BIT(L_u8Command,0));
	DIO_u8SetPinValue(LCD_D1_PORT,LCD_D1_PIN,READ_BIT(L_u8Command,1));
	DIO_u8SetPinValue(LCD_D2_PORT,LCD_D2_PIN,READ_BIT(L_u8Command,2));
	DIO_u8SetPinValue(LCD_D3_PORT,LCD_D3_PIN,READ_BIT(L_u8Command,3));
	DIO_u8SetPinValue(LCD_D4_PORT,LCD_D4_PIN,READ_BIT(L_u8Command,4));
	DIO_u8SetPinValue(LCD_D5_PORT,LCD_D5_PIN,READ_BIT(L_u8Command,5));
	DIO_u8SetPinValue(LCD_D6_PORT,LCD_D6_PIN,READ_BIT(L_u8Command,6));
	DIO_u8SetPinValue(LCD_D7_PORT,LCD_D7_PIN,READ_BIT(L_u8Command,7));


	LCD_voidSendPulse();

}





void LCD_voidSetDDRAMAddress(u8 L_u8Address)
{

	SET_BIT(L_u8Address,7);
	LCD_voidSendCommand(L_u8Address);

}

void LCD_voidSendData(u8 L_u8Data)
{

	DIO_u8SetPinValue(LCD_RS_PORT,LCD_RS_PIN,HIGH);
	DIO_u8SetPinValue(LCD_RW_PORT,LCD_RW_PIN,LOW);
	DIO_u8SetPinValue(LCD_D0_PORT,LCD_D0_PIN,READ_BIT(L_u8Data,0));
	DIO_u8SetPinValue(LCD_D1_PORT,LCD_D1_PIN,READ_BIT(L_u8Data,1));
	DIO_u8SetPinValue(LCD_D2_PORT,LCD_D2_PIN,READ_BIT(L_u8Data,2));
	DIO_u8SetPinValue(LCD_D3_PORT,LCD_D3_PIN,READ_BIT(L_u8Data,3));
	DIO_u8SetPinValue(LCD_D4_PORT,LCD_D4_PIN,READ_BIT(L_u8Data,4));
	DIO_u8SetPinValue(LCD_D5_PORT,LCD_D5_PIN,READ_BIT(L_u8Data,5));
	DIO_u8SetPinValue(LCD_D6_PORT,LCD_D6_PIN,READ_BIT(L_u8Data,6));
	DIO_u8SetPinValue(LCD_D7_PORT,LCD_D7_PIN,READ_BIT(L_u8Data,7));


	LCD_voidSendPulse();
}


static void LCD_voidSendPulse(void)
{
	DIO_u8SetPinValue(LCD_E_PORT,LCD_E_PIN,HIGH);
	_delay_ms(1);
	DIO_u8SetPinValue(LCD_E_PORT,LCD_E_PIN,LOW);
	_delay_ms(1);
}

void LCD_Send_Num(u16 num)
{
	if(num>=0 && num<=9)
	{
		LCD_voidSendData(0x30+num);
	}
	else
	{
		u16 z=10,i=0;// z for division ---- i counter
		while(1)
		{
			if((num/z)==0)
			{
				for(u16 j=0;j<=i;j++)
				{
					z=z/10;
					if((num/z)>=0 && (num/z)<=9)
					{
						LCD_voidSendData(0x30+(num/z));
					}
					num=num%z;
				}
				break;
			}
			else
			{
				z=z*10;
				i++;
			}
		}
	}

}




