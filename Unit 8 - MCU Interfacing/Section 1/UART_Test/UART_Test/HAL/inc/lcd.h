/*
 * lcd.h
 *
 * Created: 9/8/2023 5:05:44 PM
 *  Author: Mark
 */ 


#ifndef LCD_H_
#define LCD_H_
#define F_CPU 1000000UL

#include <avr/io.h>
#include <util/delay.h>

#define LCD_PORT PORTA
#define DataDir_LCD_PORT DDRA

#define LCD_CTRL PORTB
#define DataDir_LCD_CTRL DDRB

#define RS_SWITCH 1
#define RW_SWITCH 2
#define ENABLE_SWITCH 3

#define EIGHT_BIT_MODE

#define LCD_FUNCTION_8BIT_2LINES   					(unsigned char)(0x38)
#define LCD_FUNCTION_4BIT_2LINES   					(unsigned char)(0x28)
#define LCD_MOVE_DISP_RIGHT       					(unsigned char)(0x1C)
#define LCD_MOVE_DISP_LEFT   						(unsigned char)(0x18)
#define LCD_MOVE_CURSOR_RIGHT   					(unsigned char)(0x14)
#define LCD_MOVE_CURSOR_LEFT 	  					(unsigned char)(0x10)
#define LCD_DISP_OFF   								(unsigned char)(0x08)
#define LCD_DISP_ON_CURSOR   						(unsigned char)(0x0E)
#define LCD_DISP_ON_CURSOR_BLINK   					(unsigned char)(0x0F)
#define LCD_DISP_ON_BLINK   						(unsigned char)(0x0D)
#define LCD_DISP_ON   								(unsigned char)(0x0C)
#define LCD_ENTRY_DEC   							(unsigned char)(0x04)
#define LCD_ENTRY_DEC_SHIFT   						(unsigned char)(0x05)
#define LCD_ENTRY_INC_   							(unsigned char)(0x06)
#define LCD_ENTRY_INC_SHIFT   						(unsigned char)(0x07)
#define LCD_BEGIN_AT_FIRST_ROW						(unsigned char)(0x80)
#define LCD_BEGIN_AT_SECOND_ROW						(unsigned char)(0xC0)
#define LCD_CLEAR_SCREEN							(unsigned char)(0x01)
#define LCD_ENTRY_MODE								(unsigned char)(0x06)

void LCD_INIT(void);
void LCD_WRITE_COMMAND(unsigned char command);
void LCD_WRITE_CHAR(unsigned char command);
void LCD_WRITE_STRING(char* data);
void LCD_isBusy(void);
void LCD_clear_screen();


#endif /* LCD_H_ */