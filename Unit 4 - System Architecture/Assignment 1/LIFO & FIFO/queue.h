/*
 * queue.h
 *
 *  Created on: Jul 16, 2023
 *      Author: Administrator
 */

#ifndef QUEUE_H_
#define QUEUE_H_

#define type unsigned int
typedef struct {
	unsigned int Max_Size; // MAX_SIZE
	unsigned int size; // number of elements
    type* tail; //tail
	type* base; // starting point of the array
	type* head; // pointer to the next free element
} FIFO_Buf_t;



typedef enum {
	FIFO_NO_ERROR,
	FIFO_FULL,
	FIFO_NOT_FULL,
	FIFO_EMPTY,
	FIFO_NOT_EMPTY,
	FIFO_NULL
}E_Buffer_Status;

E_Buffer_Status FIFO_Push(FIFO_Buf_t* lBuf,type item);
E_Buffer_Status FIFO_Pop(FIFO_Buf_t* lBuf);
type FIFO_Top(FIFO_Buf_t* lBuf);
E_Buffer_Status FIFO_Is_Full(FIFO_Buf_t* lBuf);
E_Buffer_Status FIFO_Is_Empty(FIFO_Buf_t* lBuf);
E_Buffer_Status FIFO_Init(FIFO_Buf_t* lBuf,type* item ,unsigned int capacity);
void FIFO_Print(FIFO_Buf_t* lBuf);





#endif /* QUEUE_H_ */
