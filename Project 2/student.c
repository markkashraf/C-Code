#include "stdio.h"
#include "student.h"

extern struct sinfo st[55];

static start, end, size;

FILE *fptr = NULL;

void add_student_file()
{
    printf("Please Enter File Name: ");
    char fileName[50];
    gets(fileName);

    fptr = fopen(fileName, "r");
    
    // Store the content of the file
    char myString[100];

    // If the file exist
    if (fptr != NULL)
    {

        // Read the content and print it
        while (fgets(myString, 100, fptr))
        {
            printf("%s", myString);
        }
    }
}

void add_student_manually()
{
}

void find_by_roll()
{
}

void find_by_fname()
{
}

void find_by_cname()
{
}

void get_number_of_students()
{
}
void delete_student()
{
}

void update_student()
{
}

void show_all_students()
{
}
