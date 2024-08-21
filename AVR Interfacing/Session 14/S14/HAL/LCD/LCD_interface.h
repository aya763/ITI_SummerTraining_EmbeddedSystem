/*
 * LCD_interface.h
 *
 *  Created on: Jul 29, 2024
 *      Author: aya
 */

#ifndef HAL_LCD_LCD_INTERFACE_H_
#define HAL_LCD_LCD_INTERFACE_H_


#define LCD_CLEAR           0x01
#define LCD_RETURN_HOME    0x02// 0x03
#define LCD_ENTRY_MODE1     0x06 // normal mode
#define LCD_ENTRY_MODE2     0x07 // shift right mode
#define LCD_DISPLAY_MODE1   0x0F // display on cursor on
#define LCD_DISPLAY_MODE2   0x0D // display on cursor off
#define LCD_FUNCTION_SET1   0x3B // 8bit Mode , 2Lines, 5*7font
#define LCD_FUNCTION_SET2   0x3F // 8bit Mode , 2Lines, 5*10font


/*
#define 	LCD_CLEAR          	0b00000001
#define 	LCD_RETURN_HOME		0b00000011
#define 	LCD_ENTRY_MODE1		0b00000110 //normal mode
#define 	LCD_ENTRY_MODE2		0b00000111 //display shift right mode
#define 	LCD_DISPLAY_MODE1	0b00001111 //display on,curor on,cusrsor blink on
#define 	LCD_DISPLAY_MODE2	0b00001101 //display on,curor off
#define 	LCD_FUNCTION_SET1	0b00111011 //Function SET ,8BItMode,2Lines,5*7 Font
#define 	LCD_FUNCTION_SET2	0b00111111 //Function SET ,8BItMode,2Lines,5*10 Font
*/








void LCD_voidInit(void);

void LCD_voidSendCommand(u8 L_u8Command);

void LCD_voidSetDDRAMAddress(u8 L_u8Address);

void LCD_voidSendData(u8 L_u8Data);


#endif /* HAL_LCD_LCD_INTERFACE_H_ */
