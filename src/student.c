#include "include/student.h"

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
        if (!isalnum(topic[i]) && topic[i] != ' ' && topic[i] != '-')
            return 1; // invalid if contains disallowed characters
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