/*
 * DIO_interface.h
 *
 *  Created on: Jul 25, 2024
 *      Author: aya
 */

#ifndef MCAL_DIO_DIO_INTERFACE_H_
#define MCAL_DIO_DIO_INTERFACE_H_

#define PORTA    1
#define PORTB    2
#define PORTC    3
#define PORTD    4

#define PIN0     0
#define PIN1     1
#define PIN2     2
#define PIN3     3
#define PIN4     4
#define PIN5     5
#define PIN6     6
#define PIN7     7

#define HIGH     1
#define LOW      0

#define INPUT    0
#define OUTPUT   1

#define DIO_ERROR     0xFF
#define DIO_NOERROR    1

u8 DIO_u8SetPinValue(u8 L_u8Port , u8 L_u8Pin ,u8 L_u8Value);

u8 DIO_u8SetPinDirection(u8 L_u8Port , u8 L_u8Pin ,u8 L_u8Direction);

u8 DIO_u8SetPortValue(u8 L_u8Port ,u8 L_u8Value);

u8 DIO_u8SetPortDirection(u8 L_u8Port ,u8 L_u8Direction);

u8 DIO_u8GetPinValue(u8 L_u8Port ,u8 L_u8Pin);



#endif /* MCAL_DIO_DIO_INTERFACE_H_ */
