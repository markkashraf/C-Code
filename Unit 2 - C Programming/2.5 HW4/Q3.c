/*reverse a string using recursion*/
#include <stdio.h>
#include <string.h>



void reverseString(char str[], int n , int i)
{
    if(i==n)
    {
        return;
    }
    else
    {
        char temp = str[i];
        str[i] = str[n];
        str[n] = temp;
        reverseString(str,n-1,i+1);
    }
}



int main()
{
    char str[50];
    printf("Enter a sentence: ");
    gets(str);
    reverseString(str,strlen(str)-1,0);
    printf("\n%s",str);
    
}