#ifndef PROJECT_2_STUDENT_H
#define PROJECT_2_STUDENT_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

//macro to flush the stdin, stdout manually after use to prevent weird behavior.
#define DPRINTF(...)      {fflush(stdout); \
						  fflush(stdin); \
						  printf(__VA_ARGS__); \
						  fflush(stdout); \
						  fflush(stdin);}



// Student Information
typedef struct{
    char fname[50];
    char lname[50];
    int roll;
    float GPA;
    int courNum;
    int cid[10];
}Sinfo;


typedef struct{
    unsigned int size;
    unsigned int count;
    Sinfo* base;
    Sinfo* head;
    Sinfo* tail;
}Queue_t;

typedef enum{
    QUEUE_CLEAR,
    QUEUE_FULL,
    QUEUE_EMPTY,
    QUEUE_NULL
} Queue_Status;

typedef enum{
    FAILED,
    SUCCEDED
}File_Status;

// Prototypes
Queue_Status init();
Queue_Status add_student_manually();
File_Status add_student_file();         ////////
void find_by_roll_number();
void find_by_first_name();
void find_by_course();
void find_total();
void delete_by_roll();        //////
void update_by_roll();
void print_student_data();

#endif //PROJECT_2_STUDENT_H
