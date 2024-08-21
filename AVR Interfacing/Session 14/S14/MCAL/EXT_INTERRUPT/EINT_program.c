/*
 * EINT_program.c
 *
 *  Created on: Jul 30, 2024
 *      Author: aya
 */

#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_Math.h"



#include "EINT_config.h"
#include "EINT_interface.h"
#include "EINT_private.h"

void (* ptr1)();
void (* ptr2)();
void (* ptr3)();

void EINT_voidInit(void)
{
#if EINT0_MODE==EINT_LOWLEVEL
	CLEAR_BIT(MCUCR,MCUCR_ISC00);
	CLEAR_BIT(MCUCR,MCUCR_ISC01);

#elif EINT0_MODE==EINT_ANYCHANGE
	SET_BIT(MCUCR,MCUCR_ISC00);
	CLEAR_BIT(MCUCR,MCUCR_ISC01);

#elif EINT0_MODE==EINT_FALLING
	CLEAR_BIT(MCUCR,MCUCR_ISC00);
	SET_BIT(MCUCR,MCUCR_ISC01);

#elif EINT0_MODE==EINT_RISING
	SET_BIT(MCUCR,MCUCR_ISC00);
	SET_BIT(MCUCR,MCUCR_ISC01);

#endif

#if EINT1_MODE==EINT_LOWLEVEL
	CLEAR_BIT(MCUCR,MCUCR_ISC10);
	CLEAR_BIT(MCUCR,MCUCR_ISC11);

#elif EINT1_MODE==EINT_ANYCHANGE
	SET_BIT(MCUCR,MCUCR_ISC10);
	CLEAR_BIT(MCUCR,MCUCR_ISC11);

#elif EINT1_MODE==EINT_FALLING
	CLEAR_BIT(MCUCR,MCUCR_ISC10);
	SET_BIT(MCUCR,MCUCR_ISC11);

#elif EINT1_MODE==EINT_RISING
	SET_BIT(MCUCR,MCUCR_ISC10);
	SET_BIT(MCUCR,MCUCR_ISC11);

#endif



#if EINT2_MODE==EINT_FALLING
	CLEAR_BIT(MCUCR,MCUCSR_ISC2);

#elif EINT2_MODE==EINT_RISING
	SET_BIT(MCUCR,MCUCSR_ISC2);
#endif

}

void EINT_voidEnable(u8 L_u8EINT_Num)
{
	switch(L_u8EINT_Num)
	{
	case EINT0:
		SET_BIT(GICR,GICR_INT0);
		break;
	case EINT1:
		SET_BIT(GICR,GICR_INT1);
		break;
	case EINT2:
		SET_BIT(GICR,GICR_INT2);
		break;
	}
}

void EINT_voidDisable(u8 L_u8EINT_Num)
{
	switch(L_u8EINT_Num)
	{
	case EINT0:
		CLEAR_BIT(GICR,GICR_INT0);
		break;
	case EINT1:
		CLEAR_BIT(GICR,GICR_INT1);
		break;
	case EINT2:
		CLEAR_BIT(GICR,GICR_INT2);
		break;
	}

}

void EINT_voidSetCallback(void(*ptr)() , u8 L_u8EINT_Num)
{
	if(ptr!=0x00)
	{
		switch(L_u8EINT_Num)
		{
		case EINT0:
			ptr1=ptr;
			break;
		case EINT1:
			ptr2=ptr;
			break;
		case EINT2:
			ptr3=ptr;
			break;
		}

	}
}

void __vector_1(void)
{
	ptr1();
}
void __vector_2(void)
{
	ptr2();
}
void __vector_3(void)
{
	ptr3();
}





