/*
 * ICU_SW_int.h
 *
 *  Created on: Aug 7, 2024
 *      Author: aya
 */

#ifndef HAL_ICU_SW_ICU_SW_INT_H_
#define HAL_ICU_SW_ICU_SW_INT_H_

ES_t ICU_SW_enuInit(void);

ES_t ICU_SW_enuGetONTime(u16 *Copy_pu16TON);

ES_t ICU_SW_enuGetOFFTime(u16 *Copy_pu16TOFF);

ES_t ICU_SW_enuGetPeriod(u16 *Copy_pu16Period);

#endif /* HAL_ICU_SW_ICU_SW_INT_H_ */
