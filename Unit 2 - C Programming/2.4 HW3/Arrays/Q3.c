/*find the transpose of a matrix and display it*/

#include "stdio.h"

int main()
{
    printf("Enter rows and column of matrix: ");
    int x,y;

    scanf("%d%d",&x,&y);

    int mat[x][y];

    printf("Enter elements of matrix: \n");
    int i,j;
    for(i=0; i<x; i++)
    {
        for(j=0; j<y; j++)
        {
            printf("Enter element a%d%d: ",i+1,j+1);
            scanf("%d",&mat[i][j]);
        }
    }


    printf("Entered Matrix: \n");
    for(i=0; i<x; i++)
    {
        for(j=0; j<y; j++)
        {
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }


     printf("Transposed Matrix: \n");
    for(i=0; i<y; i++)
    {
        for(j=0; j<x; j++)
        {
            printf("%d ",mat[j][i]);
        }
        printf("\n");
    }


    

}