/*
 * STEPM_config.h
 *
 *  Created on: Jul 31, 2024
 *      Author: aya
 */

#ifndef HAL_STEPPER_MOTOR_STEPM_CONFIG_H_
#define HAL_STEPPER_MOTOR_STEPM_CONFIG_H_

#define NUM_OF_COILS       (sizeof(coils)/sizeof(coils[0]))


struct Coil{
	u8 port;
	u8 pin;
};

struct Coil coils[]={
		{PORTC,PIN0},
		{PORTC,PIN1},
		{PORTC,PIN2},
		{PORTC,PIN3},
};

#endif /* HAL_STEPPER_MOTOR_STEPM_CONFIG_H_ */
