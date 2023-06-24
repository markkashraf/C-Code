/*find the avg of array*/

#include "stdio.h"

int main()
{
    float sum = 0,avg;
    int i;
    int n;

    printf("Enter the numbers of data: ");
    scanf("%d",&n);

    float arr[n];

    for(i=0; i<n; i++)
    {
        printf("%d. Enter number: ",i+1);
        scanf("%f",&arr[i]);
    }

    for(i=0; i<n; i++)
    {
        sum+=arr[i];
    }

    avg = sum/n;

    printf("Average = %.2f",avg);



}