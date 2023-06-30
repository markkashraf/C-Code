#include <stdio.h>

int main()
{
    char c = 'A';
    char* pc = &c;

    int i;

    for(i=0; i<26; i++)
    {
        printf("%c ",*pc+i);
    }



}