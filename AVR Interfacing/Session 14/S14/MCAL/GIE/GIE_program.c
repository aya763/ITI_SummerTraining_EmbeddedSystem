/*
 * GIE_program.c
 *
 *  Created on: Jul 30, 2024
 *      Author: aya
 */

#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_Math.h"

#include "GIE_config.h"
#include "GIE_interface.h"
#include "GIE_private.h"




void GIE_voidEnable()
{
	SET_BIT(SREG,SREG_IBIT);
}

void GIE_voidDisable()
{
	CLEAR_BIT(SREG,SREG_IBIT);
}

