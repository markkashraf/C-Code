/*C Program to fin the freq of characters in a string*/

#include "stdio.h"

int main()
{
    char str[60];
    char c;
    int count = 0;

    printf("Enter a string: ");
    gets(str);


    printf("\nEnter a character to find frequency: ");
    scanf("%c",&c);


    int i;
    for(i = 0; i<60; i++)
    {
        if(str[i]==c) 
        count++;
    }

    printf("\nFrequency of %c = %d",c,count);



}