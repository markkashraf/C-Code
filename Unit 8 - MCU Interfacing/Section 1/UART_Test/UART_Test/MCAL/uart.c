#include "uart.h"
void uart_init()
{
	UBRRL = 51; // USART Baud rate register
			  // UBRR = f[osc] / (16*BAUD) - 1
			  // Baud = 2400, 4800, 9600, etc
			  // we are using an 8mhz crystal, so according to table 70 in TRM we set UBRR to 51

	//USART Control and Status Register B
	UCSRB |= 1<<3; // Writing this bit to one enables the USART Transmitter.

	UCSRB |= 1<<4; // Writing this bit to one enables the USART Receiver.
}

void uart_Send(char x)
{
	//USART Control and Status Register A – UCSRA
	/*Bit 5 – UDRE: USART Data Register Empty
The UDRE Flag indicates if the transmit buffer (UDR) is ready to receive new data. 
If UDRE is one, the buffer is empty, and therefore ready to be written. 
The UDRE Flag can generate a Data Register empty Interrupt (see description of the UDRIE bit).
UDRE is set after a reset to indicate that the transmitter is ready */

	while(!(UCSRA & (1<<5) ));
	UDR = x;
}


/* Bit 7 – RXC: USART Receive Complete
This flag bit is set when there are unread data in the receive buffer and cleared when the receive
buffer is empty (that is, does not contain any unread data). If the receiver is disabled, the receive
buffer will be flushed and consequently the RXC bit will become zero. The RXC Flag can be
used to generate a Receive Complete interrupt (see description of the RXCIE bit).*/
char uart_rec()
{
	while(!(UCSRA & (1<<7)));
	return UDR;
}

void uart_rec_string()
{
	char i=0;
	while(i<150)
	{
		string[i] = uart_rec();
		if(string[i]==13) break;//if press enter string will send
		i++;
	}
	string[i]=0;
	LCD_WRITE_STRING(string);
	
}


void uart_send_string(char * text)
{
	while(*text!=0)
	uart_Send(*text++);
}