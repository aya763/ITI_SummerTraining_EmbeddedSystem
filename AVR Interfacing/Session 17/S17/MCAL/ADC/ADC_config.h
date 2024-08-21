/*
 * ADC_config.h
 *
 *  Created on: Aug 4, 2024
 *      Author: aya
 */

#ifndef MCAL_ADC_ADC_CONFIG_H_
#define MCAL_ADC_ADC_CONFIG_H_

#define ADC_LEFTADJUST       1
#define ADC_RIGHTADJUST      0

#define ADC_ADJUST      ADC_RIGHTADJUST



// Prescaler configuration
#define ADC_PSC2              0
#define ADC_PSC4              2
#define ADC_PSC8              3
#define ADC_PSC16             4
#define ADC_PSC32             5
#define ADC_PSC64             6
#define ADC_PSC128            7



#define ADC_PSC        ADC_PSC32



// Referance voltage
#define ADC_REF_AREF             0
#define ADC_REF_AVCC             1
#define ADC_REF_INT              2


#define ADC_REF            ADC_REF_AVCC

#endif /* MCAL_ADC_ADC_CONFIG_H_ */
