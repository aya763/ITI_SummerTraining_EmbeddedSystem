/*
 * ADC_interface.h
 *
 *  Created on: Aug 4, 2024
 *      Author: aya
 */

#ifndef MCAL_ADC_ADC_INTERFACE_H_
#define MCAL_ADC_ADC_INTERFACE_H_

#define ADC_CH0        0
#define ADC_CH1        1
#define ADC_CH2        2
#define ADC_CH3        3
#define ADC_CH4        4
#define ADC_CH5        5
#define ADC_CH6        6
#define ADC_CH7        7



void ADC_voidInit(void);

void ADC_voidSelectChannel(u8 L_u8Channel);

u16 ADC_voidStartConversion(void);

#endif /* MCAL_ADC_ADC_INTERFACE_H_ */
