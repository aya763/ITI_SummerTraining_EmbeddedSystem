/*
 * ADC_program.c
 *
 *  Created on: Aug 4, 2024
 *      Author: aya
 */

#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_Math.h"

#include "../../MCAL/DIO/DIO_interface.h"


#include "ADC_config.h"
#include "ADC_interface.h"
#include "ADC_private.h"


void ADC_voidInit(void)
{
	DIO_u8SetPortDirection(PORTA,INPUT);
	u8 ADCSRA_temp=0;
	ADCSRA=0;
	ADMUX=0;

	//Enable ADC UNIT
	SET_BIT(ADCSRA,ADCSRA_ADEN);

	//Select prescaler
	ADCSRA |=(ADC_PSC<<ADCSRA_ADPS0);

	//set reference
	ADMUX |=(ADC_REF<<ADMUX_REFS0);

	//Set Adjustment
	ADMUX |=(ADC_ADJUST<<ADMUX_ADLAR);



}

void ADC_voidSelectChannel(u8 L_u8Channel)
{
	ADMUX &=0b11100000;
	ADMUX |=(L_u8Channel<<ADMUX_MUX0);

}

u16 ADC_voidStartConversion(void)
{
	//start
	SET_BIT(ADCSRA,ADCSRA_ADSC);

	//wait for complete conversion
	while(READ_BIT(ADCSRA,ADCSRA_ADSC)==1)
	{
		// do nothing
	}

	return ADC_DATA; //(u16)(ADCH<<8)|ADCL

}
