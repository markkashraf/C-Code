/*C Program to fin the number of characters in a string*/
#include "stdio.h"

int main()
{
    printf("Enter a string: ");
    char arr[50];
    gets(arr);


    int i = 0;

    while (arr[i]!=0)
    {
        i++;
    }
    

    printf("Length of string: %d",i);
}