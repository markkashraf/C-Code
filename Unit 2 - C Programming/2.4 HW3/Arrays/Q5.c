/*search for an element in an array*/

#include "stdio.h"

int main()
{
    int n;

    printf("Enter no of elements : ");

    scanf("%d",&n);

    int arr[n];

    int i;
    for(i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }

    int k;
    printf("Enter the element to be searched : ");
    scanf("%d",&k);

    for (i = 0; i < n; i++)
    {
        if(arr[i]==k)
        {
            printf("Number found at the location = %d",i+1);
            break;
        }
        if(i==n-1)
        {
            printf("Element not found");
        }
    }
    



}