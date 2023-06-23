/*Write Source Code to Swap Two Numbers without temp variable.*/
#include "stdio.h"

int main()
{
  printf("Enter value of a: ");
  float a;
  scanf("%f",&a);


  printf("Enter value of b: ");
  float b;
  scanf("%f",&b);

  /*swap*/
  a = a + b;
  b = a - b;
  a = a - b;
  

  printf("After swapping, value of a = %.2f\n",a);
  printf("After swapping, value of b = %.2f",b);
}

