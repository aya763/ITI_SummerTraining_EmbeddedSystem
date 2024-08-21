/*
 * TIMER1_private.h
 *
 *  Created on: Aug 5, 2024
 *      Author: aya
 */

#ifndef MCAL_TIMER1_TIMER1_PRIVATE_H_
#define MCAL_TIMER1_TIMER1_PRIVATE_H_

#define TCCR1A_Register	 	*((volatile u8 *) 0x4F)
#define TCCR1B_Register	 	*((volatile u8 *) 0x4E)
#define TIMSK_Register	 	*((volatile u8 *) 0x59)
#define TIFR_Register	 	*((volatile u8 *) 0x58)
#define SFIOR_Register 		*((volatile u8 *) 0x50)

#define TCNT1_Register		*((volatile u16*) 0x4C)
#define OCR1A_Register	 	*((volatile u16*) 0x4A)
#define OCR1B_Register	 	*((volatile u16*) 0x48)
#define ICR1_Register	 	*((volatile u16*) 0x46)

/* TCCR1A register bits */
#define TCCR1A_COM1A1  7
#define TCCR1A_COM1A0  6
#define TCCR1A_COM1B1  5
#define TCCR1A_COM1B0  4
#define TCCR1A_FOC1A   3
#define TCCR1A_FOC1B   2
#define TCCR1A_WGM11   1
#define TCCR1A_WGM10   0

/* TCCR1B register bits */
#define TCCR1B_ICNC1   7
#define TCCR1B_ICES1   6
/* bit 5 reserved */
#define TCCR1B_WGM13   4
#define TCCR1B_WGM12   3
#define TCCR1B_CS12    2
#define TCCR1B_CS11    1
#define TCCR1B_CS10    0

/* TIMSK register bits */
#define TIMSK_OCIE2   7
#define TIMSK_TOIE2   6
#define TIMSK_TICIE1  5
#define TIMSK_OCIE1A  4
#define TIMSK_OCIE1B  3
#define TIMSK_TOIE1   2
#define TIMSK_OCIE0   1
#define TIMSK_TOIE0   0

/* TIFR register bits */
#define TIFR_OCF2    7
#define TIFR_TOV2    6
#define TIFR_ICF1    5
#define TIFR_OCF1A   4
#define TIFR_OCF1B   3
#define TIFR_TOV1    2
#define TIFR_OCF0    1
#define TIFR_TOV0    0

/* SFIOR register bits */
#define SFIOR_ADTS2   7
#define SFIOR_ADTS1   6
#define SFIOR_ADTS0   5
/* bit 4 reserved */
#define SFIOR_ACME    3
#define SFIOR_PUD     2
#define SFIOR_PSR2    1
#define SFIOR_PSR10   0

#endif /* MCAL_TIMER1_TIMER1_PRIVATE_H_ */
