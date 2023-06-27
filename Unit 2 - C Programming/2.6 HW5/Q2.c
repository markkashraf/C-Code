#include "stdio.h"

struct distance
{
   float feet;
   float inch;
};

void addDistances(struct distance s1, struct distance s2)
{
   float inchSum = s1.inch + s2.inch; 
   float feetSum = (int)inchSum/12 + s1.feet + s2.feet;

      while (inchSum >= 12.0) {
      inchSum = inchSum - 12.0;
      ++feetSum;
   }

   printf("Sum of distances=%.1f' -%.1f\"",feetSum,inchSum);
  
}


int main()
{
    struct distance s1,s2;
    printf("Enter information for 1st distance: \n\n");
    printf("Enter feet: ");
    scanf("%f",&s1.feet);
    printf("Enter inch: ");
    scanf("%f",&s1.inch);
    printf("Enter information for 2nd distance: \n\n");
    printf("Enter feet: ");
    scanf("%f",&s2.feet);
    printf("Enter inch: ");
    scanf("%f",&s2.inch);
    addDistances(s1,s2);

    
    

 
}






