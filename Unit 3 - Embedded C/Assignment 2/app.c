#include <stdio.h>
#include "uart.h"
unsigned char string_buffer[100] = "learn-in-depth: Mark Ashraf";

int main()
{
	Uart_Send_String(string_buffer);	
}