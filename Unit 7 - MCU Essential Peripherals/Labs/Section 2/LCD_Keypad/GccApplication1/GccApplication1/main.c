/*
 * GccApplication1.c
 *
 * Created: 9/8/2023 5:04:28 PM
 * Author : Mark
 */ 

#include <avr/io.h>
#include "LCD_Driver/lcd.h"


int main(void)
{
    /* Replace with your application code */
	LCD_INIT();
	LCD_WRITE_STRING("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAb");
    while (1) 
    {
    }
}

