/*reverse a string*/
#include "stdio.h"
#include "string.h"

int main()
{
    printf("Enter the string : ");
    char str[50];
    gets(str);
    int i;
    printf("Reverse string is : ");
    for(i = strlen(str)-1; i>=0; i--)
    {
        printf("%c",str[i]);
    }


}