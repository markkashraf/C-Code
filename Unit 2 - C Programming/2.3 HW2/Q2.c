/*C Program to Check vowel or not*/
#include "stdio.h"

int main()
{
    char c;
    printf("Enter an alphabet: ");
    scanf("%c",&c);

    if(c=='a'||c=='e'||c=='o'||c=='i'||c=='u'
     ||c=='A'||c=='E'||c=='O'||c=='I'||c=='U')
    {
        printf("%c is a vowel.",c);
    }
    else
    {
        printf("%c is a consonant.",c);
    }
}

