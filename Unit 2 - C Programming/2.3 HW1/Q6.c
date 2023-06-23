/*Write Source Code to Swap Two Numbers*/
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
  float temp;
  temp = a;
  a = b;
  b = temp;

  printf("After swapping, value of a = %.2f\n",a);
  printf("After swapping, value of b = %.2f",b);
}

