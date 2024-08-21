/*
 * EINT_private.h
 *
 *  Created on: Jul 30, 2024
 *      Author: aya
 */

#ifndef MCAL_EXT_INTERRUPT_EINT_PRIVATE_H_
#define MCAL_EXT_INTERRUPT_EINT_PRIVATE_H_

#define MCUCR    *((volatile u8*)0x55)
#define MCUCSR   *((volatile u8*)0x54)
#define GICR     *((volatile u8*)0x5B)
#define GIFR     *((volatile u8*)0x5A)



#define MCUCR_ISC00             0
#define MCUCR_ISC01             1
#define MCUCR_ISC10             2
#define MCUCR_ISC11             3
#define MCUCR_SM0               4
#define MCUCR_SM1               5
#define MCUCR_ISC00             0



/* MCUCR register bits */
#define MCUCR_ISC00	0
#define MCUCR_ISC01	1
#define MCUCR_ISC10	2
#define MCUCR_ISC11	3
#define MCUCR_SM0		4
#define MCUCR_SM1		5
#define MCUCR_SM2		6
#define MCUCR_SE		7

/* MCUCSR register bits */
#define MCUCSR_PORF	0
#define MCUCSR_EXTRF	1
#define MCUCSR_BORF	2
#define MCUCSR_WDRF	3
#define MCUCSR_JTRF	4
#define MCUCSR_ISC2	6
#define MCUCSR_JTD		7

/* GICR register bits */
#define GICR_IVCE	0
#define GICR_IVSEL	1
#define GICR_INT2	5
#define GICR_INT0	6
#define GICR_INT1	7

/* GIFR register bits */
#define GIFR_INTF2	5
#define GIFR_INTF0	6
#define GIFR_INTF1	7


void __vector_1(void) __attribute__((signal));
void __vector_2(void) __attribute__((signal));
void __vector_3(void) __attribute__((signal));










#endif /* MCAL_EXT_INTERRUPT_EINT_PRIVATE_H_ */
