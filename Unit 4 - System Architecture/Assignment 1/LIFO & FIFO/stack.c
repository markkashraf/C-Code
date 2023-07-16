#include "stack.h"
#include "stdio.h"


Buffer_Status LIFO_Push(LIFO_Buf_t* lBuf,type item)
{
	/*if the pointers are valid, ie. != null*/
	if(!lBuf)       return LIFO_NULL;
	if(!lBuf->head) return LIFO_NULL;
	if(!lBuf->base) return LIFO_NULL;

	/*check if the buffer is full*/
	if(LIFO_Is_Full(lBuf)==LIFO_FULL) return LIFO_FULL;

	*(lBuf->head) = item;

	lBuf->head++; /*move the head to the next free slot*/
	lBuf->size++; /*increment the size*/
	return LIFO_NO_ERROR;
}


Buffer_Status LIFO_Pop(LIFO_Buf_t* lBuf)
{
	/*if the pointers are valid != null*/
	if(!lBuf)       return LIFO_NULL;
	if(!lBuf->head) return LIFO_NULL;
	if(!lBuf->base) return LIFO_NULL;
	if(LIFO_Is_Empty(lBuf)==LIFO_EMPTY) return LIFO_EMPTY;
	lBuf->head--; /*move the head to the next free slot*/
	lBuf->size--; /*increment the size*/
	return LIFO_NO_ERROR;
}

Buffer_Status LIFO_Init(LIFO_Buf_t* lBuf,type* item ,unsigned int capacity)
{

	lBuf->base = item;
	lBuf->head = item;
	lBuf->size = 0;
	lBuf->Max_Size = capacity;

	return LIFO_NO_ERROR;
}

/*Error checking must be done before this function is used*/
type LIFO_Top(LIFO_Buf_t* lBuf)
{
	if(!lBuf)       return LIFO_NULL;
	if(!lBuf->head) return LIFO_NULL;
	if(!lBuf->base) return LIFO_NULL;
	if(LIFO_Is_Empty(lBuf)==LIFO_EMPTY) return LIFO_EMPTY;
	type* P_item = lBuf->head;
	P_item--;
	return *(P_item);
}

Buffer_Status LIFO_Is_Full(LIFO_Buf_t* lBuf)
{
	if(!lBuf)       return LIFO_NULL;
	if(!lBuf->head) return LIFO_NULL;
	if(!lBuf->base) return LIFO_NULL;


	/*or like this*/
	if(lBuf->size==lBuf->Max_Size) return LIFO_FULL;

	return LIFO_NOT_FULL;
}
Buffer_Status LIFO_Is_Empty(LIFO_Buf_t* lBuf)
{
		if(!lBuf)       return LIFO_NULL;
		if(!lBuf->head) return LIFO_NULL;
		if(!lBuf->base) return LIFO_NULL;
		/*it can be done like this*/
		if(lBuf->base == lBuf->head) return LIFO_EMPTY;
		/*or like this*/
		if(lBuf->size == 0) return LIFO_EMPTY;

		return LIFO_NOT_EMPTY;
}


void LIFO_Print(LIFO_Buf_t* lBuf)
{
	printf("\n-----LIFO CONTENTS-----\n");
	int i;

	printf("Stack base------> ");
	for(i = 0; i<lBuf->size; i++)
	{
		printf("%d ",lBuf->base[i]);
	}
	printf("<------ Stack top \n");

	printf("Current size : %d \n",lBuf->size);
	printf("Max size : %d \n\n",lBuf->Max_Size);

}





