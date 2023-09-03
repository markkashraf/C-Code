#include "stdio.h"
#include "student.h"



struct sinfo st[55];


int main()
{
    setbuf(stdout, NULL);
	setbuf(stdin, NULL);

    add_student_file();

}



