

#ifndef UART_H_
#define UART_H_

#define  UBRRL *(volatile char *)(0x29)
#define  UCSRA *(volatile char *)(0x2b)
#define  UCSRB *(volatile char *)(0x2a)
#define  UDR   *(volatile char *)(0x2c)


char string [150] ;

void uart_init();


char uart_rec();

void uart_Send(char x);

void uart_rec_string();

void uart_send_string(char * text);

#endif /* UART_H_ */