#define F_CPU 8000000ul
#include <util/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>


#define SET_BIT(REGISTER,BIT) REGISTER |= (1<<BIT)
#define RESET_BIT(REGISTER,BIT) REGISTER &= ~(1<<BIT)
#define TOGGLE_BIT(REGISTER,BIT) REGISTER ^= (1<<BIT)
#define READ_BIT(REGISTER,BIT) (REGISTER & (1<<BIT)) >> BIT






ISR(INT0_vect)
{
	//DDRD = 0xff;
	PORTD |= 1<<5;
	_delay_ms(1000);
}

ISR(INT1_vect)
{
	//DDRD = 0xff;
	PORTD |= 1<<6;
	_delay_ms(1000);
}

ISR(INT2_vect)
{
	//DDRD = 0xff;
	PORTD |= 1<<7 ;
	_delay_ms(1000);
}




int main(void)
{

	
	/* Int0 any change*  Int 1 rising edge  int2 falling edge*/
	
	
	//STEP 1 : MCUCR (MCU Control Register)
	/* external interrupt is activated by setting bits in this register (ISC stands for interrupt sense control)
	bit 0 and bit 1 are used to control external interrupt 1 */

	//make int0 read any change
	SET_BIT(MCUCR,0);
	RESET_BIT(MCUCR,1);
	//make int1 read rising edge 
	SET_BIT(MCUCR,2);
	SET_BIT(MCUCR,3);
	//make int2 read falling edge
	// If ISC2 in register MCUCSR is written to zero, a falling edge on INT2 activates the interrupt.
	SET_BIT(MCUCSR,6);
	
	//STEP 2 : GICR (General interrupt control register) which is used to enable interrupts on those pins
	SET_BIT(GICR,5);
	SET_BIT(GICR,6);
	SET_BIT(GICR,7);
	// enable interrupts SREG [global interrupt enable]
	sei();
	
	
	
		
	
	
    while(1)
    {
        RESET_BIT(PORTD,5);
		RESET_BIT(PORTD,6);
		RESET_BIT(PORTD,7);
    }
}