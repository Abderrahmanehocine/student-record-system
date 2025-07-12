#include <stdio.h>
#include "file_handler.h"

int save_student_to_file(Student s) {
    FILE *file = fopen("students.txt", "a");
    if (!file) {
        printf("Error: Unable to open file for writing.\n");
        return 1;
    }

    fprintf(file, "%d,%s,%s,%s,%d,%s\n",
            s.id, s.first_name, s.last_name, s.date_of_birth, s.semester, s.topic);

    fclose(file);
    return 0;
}
