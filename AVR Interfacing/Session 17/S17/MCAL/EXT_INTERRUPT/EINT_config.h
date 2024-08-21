/*
 * EINT_config.h
 *
 *  Created on: Jul 30, 2024
 *      Author: aya
 */

#ifndef MCAL_EXT_INTERRUPT_EINT_CONFIG_H_
#define MCAL_EXT_INTERRUPT_EINT_CONFIG_H_

// INTERRUPT MODE
#define EINT_LOWLEVEL         0
#define EINT_ANYCHANGE        1
#define EINT_FALLING          2
#define EINT_RISING           3



#define EINT0_MODE      EINT_FALLING
#define EINT1_MODE      EINT_FALLING
#define EINT2_MODE      EINT_RISING

#endif /* MCAL_EXT_INTERRUPT_EINT_CONFIG_H_ */
