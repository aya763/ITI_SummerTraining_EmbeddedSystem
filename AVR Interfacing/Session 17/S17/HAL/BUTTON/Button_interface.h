/*
 * Button_interface.h
 *
 *  Created on: Jul 28, 2024
 *      Author: aya
 */

#ifndef HAL_BUTTON_BUTTON_INTERFACE_H_
#define HAL_BUTTON_BUTTON_INTERFACE_H_


#define BUTTON1       0
#define BUTTON2       1


void Button_Init();

u8 Button_u8GetButtonStatus(u8 L_u8ButtonNum);

void Button_voidWaitForButton(u8 L_u8ButtonNum);


#endif /* HAL_BUTTON_BUTTON_INTERFACE_H_ */
