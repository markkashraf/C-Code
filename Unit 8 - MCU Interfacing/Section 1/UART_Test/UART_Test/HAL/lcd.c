#include "lcd.h"





void LCD_KICK()
{
LCD_CTRL &= ~(1<<ENABLE_SWITCH);
_delay_ms(30);
LCD_CTRL |= 1<<ENABLE_SWITCH;
}



void LCD_clear_screen()
{
	LCD_WRITE_COMMAND(LCD_CLEAR_SCREEN);
}

void LCD_isBusy()
{

	DataDir_LCD_PORT = 0x00; //set data direction to be input
	LCD_CTRL |= (1<<RW_SWITCH); // set to read mode 
	LCD_CTRL &= ~(1<<RS_SWITCH); // set to command mode
	LCD_KICK();
	DataDir_LCD_PORT = 0xFF;
	LCD_CTRL &= ~(1 << RW_SWITCH);// set to ##  mode 
}




void LCD_INIT()
{
_delay_ms(20);
#ifdef EIGHT_BIT_MODE
	LCD_isBusy();
	DataDir_LCD_CTRL |= (1<<ENABLE_SWITCH) | (1<<RW_SWITCH) | (1<<RS_SWITCH);
	LCD_CTRL &= ~(1<<ENABLE_SWITCH) | (1<<RW_SWITCH) | (1<<RS_SWITCH);
	DataDir_LCD_PORT = 0xFF;
	LCD_clear_screen();
	LCD_WRITE_COMMAND(LCD_FUNCTION_8BIT_2LINES);
	
#endif

#ifdef FOUR_BIT_MODE

#endif
LCD_WRITE_COMMAND(LCD_ENTRY_MODE);
LCD_WRITE_COMMAND(LCD_BEGIN_AT_FIRST_ROW);
LCD_WRITE_COMMAND(LCD_DISP_ON_CURSOR_BLINK);
}



void LCD_WRITE_COMMAND( unsigned char command)
{
	#ifdef EIGHT_BIT_MODE
	LCD_isBusy();
	LCD_PORT = command;
	LCD_CTRL &= ~((1<<RW_SWITCH) | (1<<RS_SWITCH));
	LCD_KICK();
	#endif
}


void LCD_WRITE_CHAR( unsigned char data)
{
	#ifdef EIGHT_BIT_MODE
	LCD_isBusy();
	LCD_PORT = data;
	LCD_CTRL &= ~(1<<RW_SWITCH);
	LCD_CTRL |= (1<<RS_SWITCH);
	LCD_KICK();
	#endif
}

void LCD_GOTO_XY(int line,  int position)
{
	if(line == 1)
	{
		LCD_WRITE_COMMAND(LCD_BEGIN_AT_FIRST_ROW+position);
		
	}
	
	if(line == 2)
	{
		LCD_WRITE_COMMAND(LCD_BEGIN_AT_SECOND_ROW+position);
	
	}
	
}

void LCD_WRITE_STRING(char* data)
{
	int count = 0;
	while(*data > 0)
	{
		count++;
		if(count == 16) {
			LCD_GOTO_XY(2,0);
		}
		else if(count==32)
		{
			LCD_clear_screen();
			LCD_GOTO_XY(1,0);
		}
		LCD_WRITE_CHAR(*data++);
		
	
	}
}



