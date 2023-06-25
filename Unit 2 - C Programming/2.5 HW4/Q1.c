/*prime number between two intervals*/
#include <stdio.h>

void primeNumbers(int low, int high)
{
    int i,j;
    int flag = 0;

    for(i = low; i<=high; i++)
    {
        for(j = 2; j<i/2; j++)
        {
            if(i%j==0 && i!=1) 
            {   
                flag = 1;
                break;
            } 
        }

        if(flag==0) printf("%d ",i);
        
        else flag = 0;
        

    }
}


int main()
{
    int low,high;
    printf("Enter two numbers(intervals): ");
    scanf("%d%d",&low,&high);
    printf("Prime numbers between %d and %d are: ",low,high);
    primeNumbers(low,high);

    
}