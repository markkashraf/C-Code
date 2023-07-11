#include <stdio.h>
#include <stdint.h>
typedef unsigned int vuint32;
#define RCC_BASE 0x40021000
#define GPIOA_BASE 0x40010800
#define RCC_IOPAEN (1<<2)
#define GPIOA13    (1UL<< 13)
#define RCC_APB2ENR *(vuint32*)(RCC_BASE   + 0x18)
#define GPIOA_CRH   *(vuint32*)(GPIOA_BASE + 0x04)
#define GPIOA_ODR   *(vuint32*)(GPIOA_BASE + 0x0C)

typedef union {
	vuint32 all_fields;
	struct
	{
		vuint32 reserver:13;
		vuint32 P_13:1;
	} Pin;

} R_ODR_t;



volatile R_ODR_t* R_ODR = (volatile R_ODR_t*)(GPIOA_BASE + 0x0C);
unsigned char g_variables[3] = {1,2,3};
unsigned char const const_variables[3] = {1,2,3};



int main(void)
{
	RCC_APB2ENR |= RCC_IOPAEN;;
	GPIOA_CRH &= 0xff0fffff;
	GPIOA_CRH |= 0x00200000;
    int i;

	while(1)
	{
		R_ODR->Pin.P_13 = 1;       
		for(i=0; i<5000; i++);
		R_ODR->Pin.P_13 = 0;    
		for(i=0; i<5000; i++);
	}

}