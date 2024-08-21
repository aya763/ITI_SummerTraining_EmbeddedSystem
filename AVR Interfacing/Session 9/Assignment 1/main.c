/*
 * main.c
 *
 *  Created on: Jul 24, 2024
 *      Author: aya
 */


#include <avr/io.h>

#include "blink.h"

#include <util/delay.h>

void main()
{

	DDRA=3;

	while(1)
	{
		PORTA=1;
		_delay_ms(BLINK_LED_TIME);
		PORTA=2;
		_delay_ms(BLINK_LED_TIME);
	}
}

