/*
 * LED_interface.h
 *
 *  Created on: Jul 25, 2024
 *      Author: aya
 */

#ifndef HAL_LED_LED_INTERFACE_H_
#define HAL_LED_LED_INTERFACE_H_

#define LED1             0
#define LED2             1

#define LED1_PORT        PORTA
#define LED1_PIN         PIN0

#define LED2_PORT        PORTC
#define LED2_PIN         PIN5


void LED_voidInit();

void LED_voidSetLedHigh(u8 L_u8Led);

void LED_voidSetLedLow(u8 L_u8Led);

#endif /* HAL_LED_LED_INTERFACE_H_ */
