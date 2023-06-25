/*power of a number using recursion*/
#include <stdio.h>

int power(int a, int b)
{
    if(b==0)
    {
        return 1;
    }
    else if(b==1)
    {
        return a;
    }
    else 
    {
        return a*power(a,b-1);
    }
}


int main()
{
    int a,b;
    printf("Enter base number: ");
    scanf("%d",&a);

    printf("Enter power number(positive integer : ");
    scanf("%d",&b);
    

    printf("%d^%d = %d",a,b,power(a,b));
    
}