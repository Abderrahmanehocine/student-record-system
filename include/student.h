#ifndef STUDENT_H
#define STUDENT_H

// include libraries
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// define constants
#define MAX_NAME_LENGTH 50
#define MAX_TOPIC_LENGTH 100

typedef struct{
    int id;
    char first_name[MAX_NAME_LENGTH];
    char last_name[MAX_NAME_LENGTH];
    char date_of_birth[100]; // format: DD-MM-YYYY
    int semester;
    char topic[MAX_TOPIC_LENGTH];
}Student;

// function declaration

int add_student();
int display_students();
int search_student(int id);
int update_student(int id);
int delete_student(int id);

#endif //STUDENT_H