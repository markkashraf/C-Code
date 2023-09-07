/*
 * MemoryMap.h
 *
 * Created: 9/7/2023 2:19:20 PM
 *  Author: Mark
 */ 


#ifndef MEMORYMAP_H_
#define MEMORYMAP_H_

#define DDRA  *((volatile unsigned char *)0x3A)
#define PORTA *((volatile unsigned char *)0x3B)


#define DDRD  *((volatile unsigned char *)0x31)
#define PORTD *((volatile unsigned char *)0x32)




#endif /* MEMORYMAP_H_ */