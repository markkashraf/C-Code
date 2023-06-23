/*C Program to Check Largest Number among 3*/
#include "stdio.h"

int main()
{
    float a,b,c;
    printf("Enter three numbers: ");
    scanf("%f%f%f",&a,&b,&c);
    printf("Largest number: ");

    if(a>=b && a>=c)
    {
        printf("Largest number = %.2f",a);
    }
    else if(b>=a && b>=c)
    {
        printf("Largest number = %.2f",b);
    }
    else
    {
        printf("Largest number = %.2f",c);
    }




}

