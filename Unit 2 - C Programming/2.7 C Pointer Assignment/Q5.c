#include <stdio.h>
#include <string.h>


struct employee
{
    char* name;
    int id;
};


int main()
{

    struct employee s1 = {"Alex",1002};
    struct employee s2 = {"Mark",1234};

    struct employee* arr[] = {&s1,&s2};
    int i;
     for(i=0; i<2; i++)
     {
        printf("\nEmployee name : %s", arr[i]->name);
        printf("\nEmployee ID : %d\n", arr[i]->id);

     }


}