/*
 * STEPM_interface.h
 *
 *  Created on: Jul 31, 2024
 *      Author: aya
 */

#ifndef HAL_STEPPER_MOTOR_STEPM_INTERFACE_H_
#define HAL_STEPPER_MOTOR_STEPM_INTERFACE_H_

void STEPM_voidInit();

void STEPM_voidStepCW(void);

void STEPM_voidStepCCW(void);

void STEPM_voidStepwithDelay(void);

#endif /* HAL_STEPPER_MOTOR_STEPM_INTERFACE_H_ */
