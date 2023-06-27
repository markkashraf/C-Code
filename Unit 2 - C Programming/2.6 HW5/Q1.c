#include "stdio.h"


struct student
{
    char name[20];
    int roll;
    float marks;
};



int main()
{
    struct student s1;
    printf("Enter information of students: \n\n");

    printf("Enter name: ");
    gets(s1.name);

    printf("Enter roll number: ");
    scanf("%d",&s1.roll);


    printf("Enter marks: ");
    scanf("%f",&s1.marks);

    printf("\nDisplaying information\n");
    printf("name: %s\n",s1.name);
    printf("Roll: %d\n",s1.roll);
    printf("Marks: %.2f",s1.marks);


 
}






