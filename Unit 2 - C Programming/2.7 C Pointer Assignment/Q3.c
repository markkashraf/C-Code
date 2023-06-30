#include <stdio.h>
#include <string.h>

int main()
{
printf("Enter a string: ");
char* str;
gets(str);    

int i;
for (i=strlen(str)-1; i>=0; i--)
{
    printf("%c", *(str+i));
}


}