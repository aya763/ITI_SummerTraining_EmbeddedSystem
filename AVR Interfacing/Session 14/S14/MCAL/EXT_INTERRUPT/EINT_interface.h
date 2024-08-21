/*
 * EINT_interface.h
 *
 *  Created on: Jul 30, 2024
 *      Author: aya
 */

#ifndef MCAL_EXT_INTERRUPT_EINT_INTERFACE_H_
#define MCAL_EXT_INTERRUPT_EINT_INTERFACE_H_

#define EINT0       0
#define EINT1       1
#define EINT2       2


void EINT_voidInit(void);

void EINT_voidEnable(u8 L_u8EINT_Num);

void EINT_voidDisable(u8 L_u8EINT_Num);

void EINT_voidSetCallback(void(*ptr)() , u8 L_u8EINT_Num);

#endif /* MCAL_EXT_INTERRUPT_EINT_INTERFACE_H_ */
