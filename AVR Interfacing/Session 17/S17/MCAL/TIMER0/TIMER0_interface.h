/*
 * TIMER0_interface.h
 *
 *  Created on: Aug 1, 2024
 *      Author: aya
 */

#ifndef MCAL_TIMER0_TIMER0_INTERFACE_H_
#define MCAL_TIMER0_TIMER0_INTERFACE_H_

void TIMER0_voidInit(void);

void TIMER0_voidSetValueMS(u32 us);

void TIMER0_voidDisable(void);

void TIMER0_voidSetCallback(void(*ptr)(void));

void TIMER0_voidSetCallbackCTC(void(*ptr)(void));

#endif /* MCAL_TIMER0_TIMER0_INTERFACE_H_ */
