/*Factorial using recursion*/
#include <stdio.h>

unsigned int factorial(unsigned int n)
{
    if(n==1 || n==0) return 1;
    
    else return n*factorial(n-1);
}


int main()
{
    printf("Enter an positive integer: ");
    unsigned int n;
    scanf("%u",&n);
    printf("Factorial of %u = %u",n,factorial(n));

    
}