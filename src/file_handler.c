#include <stdio.h>
#include "file_handler.h"

int save_student_to_file(Student S) {
    FILE *file = fopen("students.txt", "a");
    if (!file) {
        printf("Error: Unable to open file for writing.\n");
        return 1;
    }

    fprintf(file, "%d,%s,%s,%s,%d,%s\n",
            S.id, S.first_name, S.last_name, S.date_of_birth, S.semester, S.topic);

    fclose(file);
    return 0;
}
