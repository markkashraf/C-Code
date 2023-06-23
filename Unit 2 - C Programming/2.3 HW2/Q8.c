/*C Program to Check factorial of a number*/
#include "stdio.h"

int main()
{
    printf("Enter operator either + or - or * or divide: ");
    char c;
    scanf("%c", &c);

    printf("Enter two operands: ");
    float a, b;
    scanf("%f%f", &a, &b);

    switch (c)
    {
    case '-':
        printf("%.1f - %.1f = %.1f", a, b, a - b);
        break;
    case '+':
        printf("%.1f + %.1f = %.1f", a, b, a + b);
        break;
    case '*':
        printf("%.1f * %.1f = %.1f", a, b, a * b);
        break;
    case '/':
        if (b != 0)
            printf("%.1f - %.1f = %.1f", a, b, a / b);
        else
            printf("Error: division by zero.");
        break;
    default:
        printf("Error: invalid operator.");
        break;
    }
}
