/*Write a C program to find the sum of 2 2x2 matrecies*/
#include "stdio.h"

int main()
{
    float mat1[2][2];
    float mat2[2][2];
    int i, j;

    printf("Enter the elements of the 1st matrix\n");
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            printf("Enter a%d%d: ", i + 1, j + 1);
            scanf("%f", &mat1[i][j]);
        }
    }

    printf("Enter the elements of the 2nd matrix\n");
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            printf("Enter b%d%d: ", i + 1, j + 1);
            scanf("%f", &mat2[i][j]);
           
        }
    }

    printf("Sum of matrix: \n");
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            printf("%.1f ", mat1[i][j] + mat2[i][j]);
        }
        printf("\n");
    }
}