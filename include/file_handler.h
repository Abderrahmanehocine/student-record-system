#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H

#include "student.h"

int save_student_to_file(Student S);
int load_student_from_file(Student students[], int max_count);

#endif