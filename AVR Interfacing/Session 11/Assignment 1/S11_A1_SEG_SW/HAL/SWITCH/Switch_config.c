/*
 * Switch_config.c
 *
 *  Created on: Jul 23, 2023
 *      Author: aya
 */

#include "../../LIB/STD_Types.h"
#include "../../LIB/errorState.h"
#include "Switch_priv.h"
#include "Switch_config.h"
#include "../../MCAL/DIO/DIO_interface.h"

SW_t Switch_AstrSwitchState [SW_NUM]={
		{DIO_u8PORTD,DIO_u8PIN4,DIO_u8FLOAT},
		{DIO_u8PORTD,DIO_u8PIN3,DIO_u8PULL_UP},
		{DIO_u8PORTB,DIO_u8PIN5,DIO_u8PULL_UP}
};
