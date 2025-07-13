#include <stdio.h>
#include "file_handler.h"

int save_student_to_file(Student S) {
    FILE *file = fopen("data/students.txt", "a");
    if (!file) {
        printf("Error: Unable to open file for writing.\n");
        return 1;
    }

    fprintf(file, "%d,%s,%s,%s,%d,%s\n",
            S.id, S.first_name, S.last_name, S.date_of_birth, S.semester, S.topic);

    fclose(file);
    return 0;
}

int load_student_from_file(Student students[], int max_count) {
    FILE *file = fopen("data/students.txt", "r");
    if (!file) {
        printf("⚠️ Unable to open students.txt for reading.\n");
        return -1;
    }

    int count = 0;
    while (count < max_count && fscanf(file, "%d,%49[^,],%49[^,],%99[^,],%d,%99[^\n]\n",
               &students[count].id,
               students[count].first_name,
               students[count].last_name,
               students[count].date_of_birth,
               &students[count].semester,
               students[count].topic) == 6) {
        count++;
    }

    fclose(file);
    return count;
}
