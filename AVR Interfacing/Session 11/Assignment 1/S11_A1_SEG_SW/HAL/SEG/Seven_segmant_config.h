/*
 * Seven_segmant_config.h
 *
 *  Created on: Jul 25, 2023
 *      Author: aya
 */

#ifndef SEVEN_SEGMANT_CONFIG_H_
#define SEVEN_SEGMANT_CONFIG_H_

#define SEG_NUM 2

typedef struct
{
	u8 SEG_u8APort;
	u8 SEG_u8APin;

	u8 SEG_u8BPort;
	u8 SEG_u8BPin;

	u8 SEG_u8CPort;
	u8 SEG_u8CPin;

	u8 SEG_u8DPort;
	u8 SEG_u8DPin;

	u8 SEG_u8EPort;
	u8 SEG_u8EPin;

	u8 SEG_u8FPort;
	u8 SEG_u8FPin;

	u8 SEG_u8GPort;
	u8 SEG_u8GPin;

	u8 SEG_u8CMN_Port;
	u8 SEG_u8CMN_Pin;

	u8 SEG_u8DOT_Port;
	u8 SEG_u8DOT_Pin;

	u8 SEG_u8Type;

}SEG_t;

#endif /* SEVEN_SEGMANT_CONFIG_H_ */
