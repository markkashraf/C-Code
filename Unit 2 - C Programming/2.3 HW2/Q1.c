/*Write C Program to Check Whether a Number is Even or Odd*/
#include "stdio.h"

int main()
{
    int x;
    printf("Enter an integer you want to check: ");
    scanf("%d",&x);

    if(x%2==0)
    {
        printf("%d is even.",x);
    }
    else
    {
        printf("%d is odd.",x);
    }
}

