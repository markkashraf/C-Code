
#include "student.h"

#define SIZE 60


Sinfo students[SIZE];

Queue_t *Queue = NULL;

int CoursesNum;

Queue_Status init()
{
    // initialize memory for the queue
    Queue = malloc(sizeof(Queue_t));

    if(Queue == NULL)
        return QUEUE_NULL;
    // initialize the queue by making it point to the array
    Queue->base = students;
    Queue->head = students;
    Queue->tail = students;
    Queue->size = SIZE;
    Queue->count = 0;

    return QUEUE_CLEAR;
}

Queue_Status add_student_manually()
{
    char temp_text[40];
    // Check if the Queue isn't full
    if(Queue->count == Queue->size)
    {
        DPRINTF("Queue is full! Please remove some elements.\n");
        return QUEUE_FULL;
    }

    //Fill student info
    Sinfo student;
    DPRINTF("\nEnter first name > ");
    gets(student.fname);
    DPRINTF("\nEnter last name > ");
    gets(student.lname);
    DPRINTF("\nEnter roll number > ");
    gets(temp_text);
    student.roll = atoi(temp_text);
    DPRINTF("\nEnter GPA > ");
    gets(temp_text);
    student.GPA = atof(temp_text);
    DPRINTF("\nEnter number of courses > ");
    scanf("%d",&CoursesNum);
    DPRINTF("\nEnter courses ID (NUMBERS ONLY)> ");
    int i;
    for(i=0;i<CoursesNum;i++) scanf("%d",&student.cid[i]);

    //put the student on the head
    *(Queue->head) = student;
    Queue->count++;

    // Circular Queue

    if(Queue->head == (Queue->base + (Queue->size * sizeof(Sinfo)))) Queue->head = Queue->base;
    else Queue->head++;

    return QUEUE_CLEAR;
}

void find_by_roll_number()
{
    int roll ,counter=0;
    DPRINTF("Enter roll number > ");
    scanf("%d",&roll);
    int i = 0;
    while(i <= Queue->count)
    {
        if(students[i].roll == roll)
        {
            counter++;
            DPRINTF("==========================================\n");
            DPRINTF("Roll number : %d",students[i].roll);
            DPRINTF("\nFirst name : %s",students[i].fname);
            DPRINTF("\nLast name : %s",students[i].lname);
            DPRINTF("\nGPA : %f",students[i].GPA);
            int j;
            DPRINTF("\nCourses ID : ");
            for(j=0;j<CoursesNum;j++){
                DPRINTF("%d ",students[i].cid[j]);
            }
            DPRINTF("\n=========================================\n");
        }
        i++;
    }
    if(counter == 0)
    DPRINTF("Error! Roll number %d does not exist\n",roll);

}


void find_by_first_name()
{
    int counter=0;
    char first[50];
    DPRINTF("Enter first name > ");
    gets(first);
    int i = 0;
    while(i <= Queue->count)
    {
        if(!stricmp(first,students[i].fname))
        {
            counter++;
            DPRINTF("\n=========================================\n");
            DPRINTF("Roll number : %d",students[i].roll);
            DPRINTF("\nFirst name : %s",students[i].fname);
            DPRINTF("\nLast name : %s",students[i].lname);
            DPRINTF("\nGPA : %f",students[i].GPA);
            int j;
            DPRINTF("\nCourses ID : ");
            for(j=0;j<CoursesNum;j++){
                DPRINTF("%d ",students[i].cid[j]);
            }
            DPRINTF("\n=========================================\n");
        }
        i++;
    }
    if(counter == 0)
    DPRINTF("Error! no first name matching (%s) is found.\n",first);
}


void find_by_course()
{
    int ID,counter=0;
    DPRINTF("Enter course ID > ");
    scanf("%d",&ID);
    int i = 0, j = 0;
    while(i <= Queue->count)
    {
        for(j=0;j<CoursesNum;j++){
            if(ID == students[i].cid[j]){
                counter++;
                DPRINTF("\n=========================================\n");
                DPRINTF("Roll number : %d",students[i].roll);
                DPRINTF("\nFirst name : %s",students[i].fname);
                DPRINTF("\nLast name : %s",students[i].lname);
                DPRINTF("\nGPA : %f",students[i].GPA);
                DPRINTF("\n=========================================\n");
            }
        }
        i++;
    }
    if(counter == 0)
    DPRINTF("Error! no course with ID %d is found.\n",ID);
}

void find_total()
{
    DPRINTF("Total Number of students : %d\n", Queue->count);
    DPRINTF("You can add up to %d students\n",SIZE);
    DPRINTF("You can add %d more students\n",SIZE - (Queue->count));
}


void update_by_roll()
{
    int counter=0;
    int k;
    char option[3];
    int roll;
    DPRINTF("Enter roll number > ");
    scanf("%d",&roll);
    int i = 0;
    while(i <= Queue->count)
    {
        if(roll == students[i].roll)
        {
            counter++;
            DPRINTF("Valid Options\n");
            DPRINTF("1. First Name\n");
            DPRINTF("2. Last Name\n");
            DPRINTF("3. GPA\n");
            DPRINTF("4. Courses ID\n");
            DPRINTF("Enter Option to edit :");
            gets(option);
            switch(atoi(option)){
                case 1:
                    gets(students[i].fname);
                    break;
                case 2:
                    gets(students[i].lname);
                    break;
                case 3:
                    scanf("%f",&students[i].GPA);
                    break;
                case 4:
                    for(k=0;k<CoursesNum;k++)
                        scanf("%d",&students[i].cid[k]);
                    break;
            }

            DPRINTF("\n=========================================\n");
            DPRINTF("Roll number : %d",students[i].roll);
            DPRINTF("\nFirst name : %s",students[i].fname);
            DPRINTF("\nLast name : %s",students[i].lname);
            DPRINTF("\nGPA : %f",students[i].GPA);
            int j;
            DPRINTF("\nCourses ID : ");
            for(j=0;j<CoursesNum;j++){
                DPRINTF("%d ",students[i].cid[j]);
            }
            DPRINTF("\n=========================================\n");
        }
        i++;
    }
    if(counter == 0)
    DPRINTF("Error! Roll number %d does not exist.\n",roll);

}

void print_student_data()
{
    int i = 0;
    while(i < Queue->count)
    {
        DPRINTF("\n=========================================\n");
        DPRINTF("Roll number : %d",students[i].roll);
        DPRINTF("\nFirst name : %s",students[i].fname);
        DPRINTF("\nLast name : %s",students[i].lname);
        DPRINTF("\nGPA : %f",students[i].GPA);
        int j;
        DPRINTF("\nCourses ID : ");
        for(j=0;j<CoursesNum;j++){
            DPRINTF("%d ",students[i].cid[j]);
        }
        DPRINTF("\n=========================================\n");
        i++;
    }
}

void delete_by_roll()
{
    int roll,counter=0;
    DPRINTF("Enter roll number > ");
    scanf("%d",&roll);
    int i = 0;
    while(i <= Queue->count)
    {
        if(students[i].roll == roll)
        {
            int k;
            for(k=i; k < Queue->count - 1; k++)
            {
                students[i] = students[i+1];   // Shifting left from the index to the last element
            }
            Queue->count--;
            counter++;
            DPRINTF("\n=========================================\n");
            DPRINTF("Student deleted successfully.");
            DPRINTF("\n=========================================\n");
        }
        i++;
    }
    if(counter == 0)
    DPRINTF("Error! roll number  %d does not exist.\n",roll);
}




File_Status add_student_file()
{
    FILE *fp = fopen("test.txt", "r");
    if (fp == NULL) {
        printf("Failed to open file\n");
        return FAILED;
    }

    Sinfo student[55];
    int num_students = 0;

    while (fscanf(fp, "%s %s %d %f %d", student[num_students].fname, student[num_students].lname, &student[num_students].roll, &student[num_students].GPA, &student[num_students].courNum) == 5) {
        for (int i = 0; i < student[num_students].courNum; i++) {
            fscanf(fp, "%d", &student[num_students].cid[i]);
        }

        *(Queue->head) = student[num_students];
        Queue->count++;

        // Circular Queue
        if(Queue->head == (Queue->base + (Queue->size * sizeof(Sinfo))))
            Queue->head = Queue->base;
        else
            Queue->head++;

        num_students++;
    }

    fclose(fp);

    // Print out the data to verify it was read correctly
    for (int i = 0; i < num_students; i++) {
        DPRINTF("%s %s %d %f %d ", student[i].fname, student[i].lname, student[i].roll, student[i].GPA, student[i].courNum);
        for (int j = 0; j < student[i].courNum; j++) {
            DPRINTF("%d ", student[i].cid[j]);
        }
        DPRINTF("\n");
    }


    return SUCCEDED;
}