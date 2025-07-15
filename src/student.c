#include "../include/student.h"
#include "../include/file_handler.h"

int is_valid_id(int id){
    return id < 0; // return 1 if invalid
}

int is_valid_name(const char *name){
    if (name == NULL || strlen(name) < 2)
        return 1; // invalid

    for (int i = 0; name[i] != '\0'; i++) {
        if (!isalpha(name[i]))
            return 1; // invalid if any char is not a letter
    }

    return 0; // valid
}

int is_valid_date_of_birth(const char *dob) {
    if (dob == NULL || strlen(dob) != 10)
        return 1;

    // Check the format DD-MM-YYYY (positions 2 and 5 must be '-')
    if (dob[2] != '-' || dob[5] != '-')
        return 1;

    // Extract day, month, year substrings
    char day_str[3], month_str[3], year_str[5];

    strncpy(day_str, dob, 2);
    day_str[2] = '\0';

    strncpy(month_str, dob + 3, 2);
    month_str[2] = '\0';

    strncpy(year_str, dob + 6, 4);
    year_str[4] = '\0';

    // Check if all characters are digits
    for (int i = 0; i < 2; i++) {
        if (!isdigit(day_str[i]) || !isdigit(month_str[i]))
            return 1;
    }
    for (int i = 0; i < 4; i++) {
        if (!isdigit(year_str[i]))
            return 1;
    }

    // Convert to integers
    int day = atoi(day_str);
    int month = atoi(month_str);
    int year = atoi(year_str);

    // Logical validation
    if (day < 1 || day > 31 || month < 1 || month > 12 || year < 1900 || year > 2025)
        return 1;

    return 0; // valid
}

int is_valid_semester(int semester){
    return !(semester >= 1 && semester <= 5);
}

int is_valid_topic(const char *topic) {
    if (topic == NULL || strlen(topic) < 3)
        return 1; // invalid if null or too short

    for (int i = 0; topic[i] != '\0'; i++) {
        if (!isalnum(topic[i]) && topic[i] != ' ' && topic[i] != '-') {
            return 1; // invalid if it contains anything except letters, digits, space, or dash
        }
    }

    return 0; // valid
}


int add_student(){
    Student S;

    int id;
    printf("\nEnter student id: ");
    scanf("%d",&id);
    if(is_valid_id(id)){
        printf("Please enter a valid id number\n");
        return 1;
    }
    S.id = id;

    char first_name[MAX_NAME_LENGTH];
    printf("Enter student fisrt name: ");
    scanf("%s", first_name);
    if(is_valid_name(first_name)){
        printf("Please enter a valid first name\n");
        return 1;
    }
    strcpy(S.first_name, first_name);

    char last_name[MAX_NAME_LENGTH];
    printf("Enter student last name: ");
    scanf("%s", last_name);
    if(is_valid_name(last_name)){
        printf("Please enter a valid last name\n");
        return 1;
    }
    strcpy(S.last_name, last_name);

    char date_of_birth[100];
    printf("Enter student date of birth(Format: DD-MM-YYYY): ");
    scanf("%s", date_of_birth);
    if(is_valid_date_of_birth(date_of_birth)){
        printf("Please enter a valid date of birth\n");
        return 1;
    }
    strcpy(S.date_of_birth, date_of_birth);

    int semester;
    printf("Enter student semester: ");
    scanf("%d", &semester);
    if( is_valid_semester(semester)){
        printf("Please enter a valid semester\n");
        return 1;
    }
    S.semester = semester;

    char topic[MAX_TOPIC_LENGTH];
    topic[strcspn(topic, "\n")] = '\0';  // remove newline
    printf("Enter student topic: ");
    while (getchar() != '\n');
    fgets(topic, sizeof(topic), stdin);
    topic[strcspn(topic, "\n")] = '\0';
    if(is_valid_topic(topic)){
        printf("Please enter a valid topic\n");
        return 1;
    }
    strcpy(S.topic, topic);

    return save_student_to_file(S);
}

int display_students() {
    Student students[100];
    int count = load_student_from_file(students, 100);

    if (count <= 0) {
        printf("⚠️ No student records found or failed to load.\n");
        return 1;
    }

    printf("\n=========== All Student Records ===========\n");
    printf("%-5s %-15s %-15s %-12s %-8s %-20s\n", "ID", "First Name", "Last Name", "DOB", "Semester", "Topic");
    printf("---------------------------------------------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("%-5d %-15s %-15s %-12s %-8d %-20s\n",
               students[i].id,
               students[i].first_name,
               students[i].last_name,
               students[i].date_of_birth,
               students[i].semester,
               students[i].topic);
    }

    return 0;
}

int search_student(int id) {
    Student students[100];
    int count = load_student_from_file(students, 100);

    if (count <= 0) {
        printf("⚠️ No student records found or failed to load.\n");
        return 1;
    }

    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            printf("\n✅ Student Found:\n");
            printf("ID         : %d\n", students[i].id);
            printf("First Name : %s\n", students[i].first_name);
            printf("Last Name  : %s\n", students[i].last_name);
            printf("Birth Date : %s\n", students[i].date_of_birth);
            printf("Semester   : %d\n", students[i].semester);
            printf("Topic      : %s\n", students[i].topic);
            return 0;
        }
    }

    printf("❌ No student found with ID %d\n", id);
    return 1;
}

int update_student(int id) {
    Student students[100];
    int count = load_student_from_file(students, 100);
    if (count <= 0) {
        printf("❌ No students found.\n");
        return 1;
    }

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            found = 1;

            int choice;
            do {
                printf("\n--- Current Student Data ---\n");
                printf("1. First Name: %s\n", students[i].first_name);
                printf("2. Last Name: %s\n", students[i].last_name);
                printf("3. Date of Birth: %s\n", students[i].date_of_birth);
                printf("4. Semester: %d\n", students[i].semester);
                printf("5. Topic: %s\n", students[i].topic);
                printf("0. Save and Exit\n");

                printf("Choose a field to update: ");
                scanf("%d", &choice);
                getchar(); // clear buffer

                switch (choice) {
                    case 1: {
                        char fname[MAX_NAME_LENGTH];
                        printf("New First Name: ");
                        scanf("%s", fname);
                        if (is_valid_name(fname)) {
                            printf("❌ Invalid name.\n");
                        } else {
                            strcpy(students[i].first_name, fname);
                            printf("✅ First name updated.\n");
                        }
                        break;
                    }

                    case 2: {
                        char lname[MAX_NAME_LENGTH];
                        printf("New Last Name: ");
                        scanf("%s", lname);
                        if (is_valid_name(lname)) {
                            printf("❌ Invalid name.\n");
                        } else {
                            strcpy(students[i].last_name, lname);
                            printf("✅ Last name updated.\n");
                        }
                        break;
                    }

                    case 3: {
                        char dob[100];
                        printf("New Date of Birth (DD-MM-YYYY): ");
                        scanf("%s", dob);
                        if (is_valid_date_of_birth(dob)) {
                            printf("❌ Invalid date.\n");
                        } else {
                            strcpy(students[i].date_of_birth, dob);
                            printf("✅ Date of birth updated.\n");
                        }
                        break;
                    }

                    case 4: {
                        int sem;
                        printf("New Semester (1-5): ");
                        scanf("%d", &sem);
                        if (is_valid_semester(sem)) {
                            printf("❌ Invalid semester.\n");
                        } else {
                            students[i].semester = sem;
                            printf("✅ Semester updated.\n");
                        }
                        break;
                    }

                    case 5: {
                        char topic[MAX_TOPIC_LENGTH];
                        printf("New Topic: ");
                        fgets(topic, sizeof(topic), stdin);
                        topic[strcspn(topic, "\n")] = '\0'; // remove newline

                        if (is_valid_topic(topic)) {
                            printf("❌ Invalid topic.\n");
                        } else {
                            strcpy(students[i].topic, topic);
                            printf("✅ Topic updated.\n");
                        }
                        break;
                    }

                    case 0: {
                        char confirm;
                        printf("Are you sure you want to save the changes? (y/n): ");
                        scanf(" %c", &confirm);
                        if (confirm == 'y' || confirm == 'Y') {
                            // Save all students back to the file
                            FILE *file = fopen("data/students.txt", "w");
                            if (!file) {
                                printf("❌ Error saving data.\n");
                                return 1;
                            }
                        
                            for (int j = 0; j < count; j++) {
                                fprintf(file, "%d,%s,%s,%s,%d,%s\n",
                                        students[j].id,
                                        students[j].first_name,
                                        students[j].last_name,
                                        students[j].date_of_birth,
                                        students[j].semester,
                                        students[j].topic);
                            }
                        
                            fclose(file);
                            printf("✅ Student updated successfully.\n");
                        } else {
                            printf("❌ Changes discarded.\n");
                        }
                        break;
                    }


                    default:
                        printf("⚠️ Invalid choice.\n");
                    }

            } while (choice != 0);

            // Save all students back to the file
            FILE *file = fopen("data/students.txt", "w");
            if (!file) {
                printf("❌ Error saving data.\n");
                return 1;
            }

            for (int j = 0; j < count; j++) {
                fprintf(file, "%d,%s,%s,%s,%d,%s\n",
                        students[j].id,
                        students[j].first_name,
                        students[j].last_name,
                        students[j].date_of_birth,
                        students[j].semester,
                        students[j].topic);
            }

            fclose(file);
            printf("✅ Student updated successfully.\n");
            return 0;
        }
    }

    if (!found) {
        printf("❌ Student with ID %d not found.\n", id);
        return 1;
    }

    return 0;
}
