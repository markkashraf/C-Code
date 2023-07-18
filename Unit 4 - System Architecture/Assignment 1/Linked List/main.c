#include "stdio.h"
#include "stdlib.h"
#include "string.h"


 struct Sdata {
    int ID;
    char name[40];
    float height;
    };


 struct SStudent
{
   struct Sdata student;
   struct SStudent* PNextStudent;
};



 struct SStudent* gpFirstStudent = NULL;






void add_student()
{
	struct SStudent* pNewStudent;
	struct SStudent* pLastStudent;
	char temp_text[40];
	//List is empty
	if(gpFirstStudent==NULL)
	{
		//Create a new record
		pNewStudent = malloc(sizeof(struct SStudent));
		//Assign it to gpFirstStudent
		gpFirstStudent = pNewStudent;
	}
	else
	{
		//Navigate until reaching the tail
		pLastStudent = gpFirstStudent;
		while(pLastStudent->PNextStudent)

		pLastStudent = pLastStudent->PNextStudent;

		//create a new record
		pNewStudent = malloc(sizeof(struct SStudent));
		pLastStudent->PNextStudent = pNewStudent;
	}

	//Fill out the new record!
	printf("Enter the ID >\n");
	gets(temp_text);
	pNewStudent->student.ID = atoi(temp_text);
	printf("Enter the Name >\n");
	gets(pNewStudent->student.name);
	printf("Enter the height >\n");
	gets(temp_text);
	pNewStudent->student.height = atof(temp_text);

	//set the next pointer to null
	pNewStudent->PNextStudent = NULL;


}

int delete_student()
{
	int id;
	printf("Enter the ID of the student to be removed : ");
	scanf("%d",&id);

 struct SStudent* itr = gpFirstStudent, *old = NULL;

 while (itr)
 {
	if(itr->student.ID==id)
	{
		if(old) old->PNextStudent = itr->PNextStudent;
		else if(!itr->PNextStudent) old->PNextStudent = NULL;
		else gpFirstStudent = itr->PNextStudent;

		free(itr);
		printf("Student ID %d has been removed from the system.\n",id);
		return 1;
	}
	old = itr;
	itr = itr->PNextStudent;
 }


 printf("Student not found.\n");
 return 0;
 








}

void print_students()
{
	 struct SStudent* itr =  gpFirstStudent;
	 while(itr!=NULL)
	 {
		printf("---------------------------------------------------------------\n");
		printf("Student Name: %s\n",itr->student.name);
		printf("Student ID: %d\n",itr->student.ID);
		printf("Student Height: %.2f\n",itr->student.height);
		itr = itr->PNextStudent;
	 }
	 printf("---------------------------------------------------------------\n");
}

void delete_all()
{
	 struct SStudent* itr = gpFirstStudent,*temp;

	 while(itr!=NULL)
	 {
		temp = itr->PNextStudent;
		free(itr);
		itr = temp;
	 }
	 gpFirstStudent = NULL;
}

void get_nth()
{
	int i,n;
	printf("Please enter the index of the student.");
	scanf("%d",&n);
	struct SStudent* itr = gpFirstStudent;

	for(i=0; (i<n) && itr; i++)
	{
		itr = itr->PNextStudent;
	}
	if(itr)
	{
		printf("---------------------------------------------------------------\n");
		printf("Student Name: %s\n",itr->student.name);
		printf("Student ID: %d\n",itr->student.ID);
		printf("Student Height: %.2f\n",itr->student.height);
		printf("---------------------------------------------------------------\n");
	}
	else printf("index not found!\n");	
}

void get_length()
{
	
	int i;
	struct SStudent* itr =  gpFirstStudent;
	for(i=0; itr; i++) itr = itr->PNextStudent;
	printf("There are currently %d student/students in the system.\n",i);
	
}

void get_nth_from_end()
{
	int n,i;
	printf("please enter n :");
	scanf("%d",&n);

	struct SStudent* fast = gpFirstStudent, *slow = gpFirstStudent;
	for(i=0; (i<n) && fast; i++)
	{
		fast = fast->PNextStudent;
	}
	if(fast!=slow)
	{
			while (fast)
			{
				fast = fast->PNextStudent;
				slow = slow->PNextStudent;
			}
	}
	if(slow){
	printf("---------------------------------------------------------------\n");
	printf("Student Name: %s\n",slow->student.name);
	printf("Student ID: %d\n",slow->student.ID);
	printf("Student Height: %.2f\n",slow->student.height);
	printf("---------------------------------------------------------------\n");
	return;
	}


	

	
}



int main()
{
	setbuf(stdout, NULL);
	setbuf(stdin, NULL);
	char operation[40];

	while (1)
	{
		printf("********************************************************\n");
		printf("Choose an operation from the following:\n");
		printf("1.) Add a Student.\n");
		printf("2.) Delete a Student.\n");
		printf("3.) Print students information.\n");
		printf("4.) Delete all students.\n");
		printf("5.) Exit.\n");
		printf("6.) get nth student (indexed from 0).\n");
		printf("7.) get the number of students.\n");
		printf("8.) get the nth student from the end.\n");
		printf("********************************************************\n");

		gets(operation);

		switch (atoi(operation))
		{
		case 1:
			add_student();
			break;
		case 2:
			delete_student();
			break;
		case 3:
			print_students();
			break;
		case 4:
			delete_all();
			break;
		case 5:
			return 0;
		case 6:
			get_nth();
			break;
		case 7:
			get_length();
			break;
		case 8:
			get_nth_from_end();
			break;
		default:
			printf("\nWrong input!!\n");
			break;
		}
	}
	




    
}
