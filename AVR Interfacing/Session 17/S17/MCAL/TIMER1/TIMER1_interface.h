/*
 * TIMER1_interface.h
 *
 *  Created on: Aug 5, 2024
 *      Author: aya
 */

#ifndef MCAL_TIMER1_TIMER1_INTERFACE_H_
#define MCAL_TIMER1_TIMER1_INTERFACE_H_

#define PWM_OCR1A          0
#define PWM_OCR1B          1

#define PWM_INVERT         3
#define PWM_NONINVERT      2



void TIM1_voidInitPWM(void);

void TIM1_voidStartPWM(void);

void TIM1_voidSetDutyCycle(u8 channel,u8 duty);

void TIM1_voidSetPeriod(u16 us );

void TIM1_voidPWMSetMode(u8 mode,u8 channel);

void TIM1_voidSetTON(u8 channel,u16 us );

//constant prescaler 8


#endif /* MCAL_TIMER1_TIMER1_INTERFACE_H_ */
