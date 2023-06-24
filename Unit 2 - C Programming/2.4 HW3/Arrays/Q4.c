#include "stdio.h"

int main()
{
    int n, loc , num;


    printf("Enter no of elements : ");
    scanf("%d",&n);
    printf("\n");

    int arr[n+1];
    int i;
    for(i = 0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }

    printf("\nEnter the element to be inserted : ");
    scanf("%d",&num);


    printf("\nEnter the location : ");
    scanf("%d",&loc);

    printf("\n");


    for(i = n; i>=loc-1;i--)
    {
        arr[i] = arr[i-1];
    }

    arr[loc-1] = num;

     for(i = 0; i<=n; i++)
    {
        printf("%d ",arr[i]);
    }











}