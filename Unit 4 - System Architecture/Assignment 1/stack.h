
#ifndef STACK_H_
#define STACK_H_

#define type unsigned int

typedef struct {
	unsigned int Max_Size; // MAX_SIZE
	unsigned int size; // number of elements
	type* base; // starting point ??
	type* head; // pointer to the next free element
} LIFO_Buf_t;

typedef enum {
	LIFO_NO_ERROR,
	LIFO_FULL,
	LIFO_NOT_FULL,
	LIFO_EMPTY,
	LIFO_NOT_EMPTY,
	LIFO_NULL
}Buffer_Status;




Buffer_Status LIFO_Push(LIFO_Buf_t* lBuf,type item);
Buffer_Status LIFO_Pop(LIFO_Buf_t* lBuf);
type LIFO_Top(LIFO_Buf_t* lBuf);
Buffer_Status LIFO_Is_Full(LIFO_Buf_t* lBuf);
Buffer_Status LIFO_Is_Empty(LIFO_Buf_t* lBuf);
Buffer_Status LIFO_Init(LIFO_Buf_t* lBuf,type* item ,unsigned int capacity);
void LIFO_Print(LIFO_Buf_t* lBuf);

#endif /* STACK_H_ */
