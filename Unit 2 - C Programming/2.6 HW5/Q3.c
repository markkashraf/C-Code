#include "stdio.h"





struct imaginary
{
    float real;
    float img;
};

struct imaginary addImg(struct imaginary n1,struct imaginary n2)
{
    struct imaginary result = {n1.real+n2.real,n1.img+n2.img};
    return result;
}

int main()
{
    struct imaginary n1,n2;
    printf("For 1st complex number\n");

    printf("enter real part: ");
    scanf("%f",&n1.real);
    printf("enter imaginary part: ");
    scanf("%f",&n1.img);


    printf("For 2nd complex number\n");

    printf("enter real part: ");
    scanf("%f",&n2.real);
    printf("enter imaginary part: ");
    scanf("%f",&n2.img);


    struct imaginary result = addImg(n1,n2);

    printf("%.1f + %.1fi",result.real,result.img);





 
}






