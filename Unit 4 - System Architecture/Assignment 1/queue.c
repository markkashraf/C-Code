#include "queue.h"
#include "stdio.h"

E_Buffer_Status FIFO_Push(FIFO_Buf_t *lBuf, type item)
{
    if(FIFO_Is_Full(lBuf)==FIFO_FULL)
    {
        return FIFO_FULL;
    }
    else
    {
        *(lBuf->head) = item;
        lBuf->size++;
        lBuf->head++;

        if(lBuf->head == lBuf->base+(lBuf->Max_Size*sizeof(type)))
        {
            lBuf->head = lBuf->base;
        }
        return FIFO_NO_ERROR;
        
    }
}

E_Buffer_Status FIFO_Pop(FIFO_Buf_t *lBuf)
{
     if(FIFO_Is_Empty(lBuf)==FIFO_EMPTY)
    {
        return FIFO_EMPTY;
    }
    else
    {
        lBuf->size--;
        if(lBuf->tail==lBuf->base+lBuf->Max_Size*sizeof(type))
            lBuf->tail = lBuf->base;

        else lBuf->tail++;
        return FIFO_NO_ERROR;
    }
}

type FIFO_Top(FIFO_Buf_t *lBuf)
{
    if(FIFO_Is_Empty(lBuf)==FIFO_EMPTY)
    {
        return FIFO_EMPTY;
    }
    return *(lBuf->tail);
}

E_Buffer_Status FIFO_Is_Full(FIFO_Buf_t *lBuf)
{
    if(!lBuf ||!lBuf->base) return FIFO_NULL;
    if(lBuf->size==lBuf->Max_Size) return FIFO_FULL;
    return FIFO_NOT_FULL;
}

E_Buffer_Status FIFO_Is_Empty(FIFO_Buf_t *lBuf)
{
    if(!lBuf ||!lBuf->base) return FIFO_NULL;
    if(lBuf->size==0) return FIFO_EMPTY;
    return FIFO_NOT_EMPTY;
   
}

E_Buffer_Status FIFO_Init(FIFO_Buf_t *lBuf, type *item, unsigned int capacity)
{
    lBuf->base = item;
    lBuf->head = item;
    lBuf->tail = item;
    lBuf->Max_Size = capacity;
    lBuf->size = 0;

    if(lBuf->base!=0 && capacity!=0) return FIFO_NO_ERROR;
    else return FIFO_NULL; 
}

void FIFO_Print(FIFO_Buf_t *lBuf)
{
    printf("\n-----FIFO CONTENTS-----\n");
	type* i;
	printf("Queue top------> ");
	for(i = lBuf->tail; i!=lBuf->head; i++)
	{
		 if(i==lBuf->base+lBuf->Max_Size*sizeof(type))
		            i = lBuf->base;

		printf("%d ",*i);
	}
	printf("<------ Queue base \n");

	printf("Current size : %d \n",lBuf->size);
	printf("Max size : %d \n\n",lBuf->Max_Size);
}
