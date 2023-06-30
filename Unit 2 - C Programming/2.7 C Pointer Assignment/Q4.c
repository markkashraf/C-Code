#include <stdio.h>
#include <string.h>

int main()
{
printf("Input the number of elements to store in the array (max 15): ");
int n;
int arr[15];
scanf("%d",&n);

int i;

for(i=0; i<n; i++)
{
    printf("element - %d : ",i+1);
    scanf("%d",&arr[i]);
}

printf("The elements of the array in reverse order \n");

for(i=n-1; i>=0; i--)
{
    printf("element - %d : %d",i+1, *(arr+i));
    printf("\n");
    
}


}