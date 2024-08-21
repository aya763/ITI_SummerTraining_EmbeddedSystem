/*
 * LM35_program.c
 *
 *  Created on: Aug 4, 2024
 *      Author: aya
 */
#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_Math.h"

#include "../../MCAL/ADC/ADC_interface.h"


#include "LM35_config.h"
#include "LM35_interface.h"
#include "LM35_private.h"


void LM35_Init(void)
{
	ADC_voidInit();
	ADC_voidSelectChannel(LM35_CHANNEL);
}

u8 LM35_u8GetTemp(void)
{
	u16 adc_read=ADC_voidStartConversion();
	f32 temp =(adc_read*5*100)/1024;
	return (u8) temp;

}
