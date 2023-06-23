/*C Program to Check factorial of a number*/
#include "stdio.h"

int main()
{
    printf("Enter an integer: ");
    int n;
    scanf("%d",&n);

    if(n>=0)
    {
        int result = 1;
        int i;
        for(i = 2; i<=n; i++)
        {
            result *= i;
        }
        printf("Factorial = %d",result);
    }
    else 
    {
        printf("Error!!! Factorial of a negative number doesn't exist.");
    }
    

    

   


}

