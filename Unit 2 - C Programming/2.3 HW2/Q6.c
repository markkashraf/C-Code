/*C Program to Check positive or negative*/
#include "stdio.h"

int main()
{
    printf("Enter an integer: ");
    int n;
    scanf("%d",&n);
    int sum = (n * (n+1))/2;

    printf("Sum = %d",sum);

}

