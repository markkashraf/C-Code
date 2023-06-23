/*C Program to Check positive or negative*/
#include "stdio.h"

int main()
{
    printf("Enter a number: ");
    float x;
    scanf("%f",&x);

    if(x>0)
    {
        printf("%.2f is positive.",x);
    }  
    else if(x<0)
    {
        printf("%.2f is negative.",x);
    }
    else
    {
        printf("You entered zero.");
    } 



}

