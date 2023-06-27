#include "stdio.h"





struct student
{
    char name[20];
    int marks; 
};

int main()
{
    struct student students[10];

    printf("Enter information of the students\n");
    int i; 
    for(i = 0; i<10; i++)
    {
        printf("For roll number %d\n",i+1);
        printf("Enter name: ");
        scanf("%s",&students[i].name);
        fflush(stdout);
        printf("Enter marks: ");
        scanf("%d",&students[i].marks);
    }

      printf("Displaying information of the students\n");

        for(i = 0; i<10; i++)
    {
        printf("information for roll number %d\n",i+1);
        printf("name: %s\n",students[i].name);
        printf("marks: %d\n",students[i].marks);
       
    }

    





 
}






