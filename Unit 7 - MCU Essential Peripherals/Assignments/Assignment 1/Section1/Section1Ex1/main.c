/*
 * Section1Ex1.c
 *
 * Created: 9/7/2023 2:17:30 PM
 * Author : Mark
 */ 

#include "MemoryMap.h" 
#include "utils.h"
#include "util/delay.h"

int main(void)
{
	DDRD = 0b11100000;
	unsigned char numbers[] = {0b000,0b001,0b011,0b111,0b011,0b001};
    
    while (1) 
    {
		int i = 0;
		for(i = 0; i<6; i++)
		{
			PORTD = numbers[i] << 5;
			_delay_ms(5000);	
		}
	
    }
}

