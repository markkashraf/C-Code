#include "stdio.h"
#include "stack.h"
#include "queue.h"

#define LIFO_SIZE 5
#define type unsigned int
#define FIFO_SIZE 5

void test_LIFO()
{
	type buffer[LIFO_SIZE];
	LIFO_Buf_t st;
	if (LIFO_Init(&st, buffer, LIFO_SIZE) == LIFO_NO_ERROR)
	printf("<<<<<<< LIFO INITIALIZED >>>>>>\n");
	else return;
	if (LIFO_Is_Empty(&st) == LIFO_EMPTY)
	printf("<<<<<<< LIFO IS EMPTY >>>>>>\n");
	
	LIFO_Push(&st, 1); /*1*/
	LIFO_Push(&st, 2); /*1 2 */
	LIFO_Push(&st, 3); /*1 2 3*/
	LIFO_Print(&st);
	printf("Current Stack Top -----> %d\n", LIFO_Top(&st));
	LIFO_Pop(&st); /*1 2*/
	printf("Current Stack Top -----> %d\n", LIFO_Top(&st));
	LIFO_Push(&st, 9); /*1 2 9*/
	printf("Current Stack Top -----> %d\n", LIFO_Top(&st));
	LIFO_Push(&st, 8); /*1 2 9 8 */
	printf("Current Stack Top -----> %d\n", LIFO_Top(&st));
	LIFO_Push(&st, 5); /*1 2 9 8 5*/
	printf("Current Stack Top -----> %d\n", LIFO_Top(&st));
	if (LIFO_Push(&st, 3) == LIFO_FULL)
	printf("<<<<<<< LIFO IS FULL >>>>>>\n");
	printf("Current Stack Top -----> %d\n", LIFO_Top(&st));
	LIFO_Pop(&st); /*1 2 9*/
	printf("Current Stack Top -----> %d\n", LIFO_Top(&st));
	LIFO_Print(&st);
}


void test_FIFO()
{
	type buffer[FIFO_SIZE];
	FIFO_Buf_t st;
	if (FIFO_Init(&st, buffer, FIFO_SIZE) == FIFO_NO_ERROR)
	printf("<<<<<<< FIFO INITIALIZED >>>>>>\n");
	else return;
	if (FIFO_Is_Empty(&st) == FIFO_EMPTY)
	printf("<<<<<<< FIFO IS EMPTY >>>>>>\n");
	
	FIFO_Push(&st, 1); /*1*/
	FIFO_Push(&st, 2); /*1 2 */
	FIFO_Push(&st, 3); /*1 2 3*/
	FIFO_Print(&st);
	FIFO_Pop(&st);

	printf("Current Queue Top -----> %d\n", FIFO_Top(&st));
	FIFO_Push(&st, 4); /*2 3 4*/
	FIFO_Push(&st, 5); /*2 3 4 5 */
	FIFO_Push(&st, 6); /*2 3 4 5 6*/
	FIFO_Push(&st, 7); /*2 3 4 5 6 (FIFO FULL)*/
	FIFO_Print(&st);
	FIFO_Pop(&st);     /*3 4 5 6*/
	printf("Current Queue Top -----> %d\n", FIFO_Top(&st));

	FIFO_Print(&st);

}



int main()
{
	test_FIFO();
}
