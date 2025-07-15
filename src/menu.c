#include "../include/menu.h"

void clear_screen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Menu loop
void menu() {
    int choice;
    do {
        clear_screen();
        printf("========== Student Record Management ==========\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student by ID\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("0. Exit\n");
        printf("===============================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if (add_student()) {
                    printf("❌ Failed to add student.\n");
                } else {
                    printf("✅ Student added successfully.\n");
                }
                break;

            case 2:
                display_students();
                break;

            case 3: {
                int id;
                printf("Enter student ID to search: ");
                scanf("%d", &id);
                search_student(id);
                break;
            }
            
            case 4: {
                int id;
                printf("Enter student ID to update: ");
                scanf("%d", &id);
                int result = update_student(id);
                if (result == 0)
                    printf("✅ Update completed.\n");
                else
                    printf("❌ Update failed.\n");
                break;
            }

            case 5: {
                int id;
                printf("Enter student ID to delete: ");
                scanf("%d", &id);
                if (delete_student(id)) {
                    printf("❌ Failed to delete student.\n");
                } else {
                    printf("✅ Student deleted successfully.\n");
                }
                break;
            }


            case 0:
                printf("👋 Exiting program...\n");
                break;

            default:
                printf("⚠️ Invalid choice. Try again.\n");
        }

        if (choice != 0) {
            printf("\nPress Enter to continue...");
            while (getchar() != '\n'); // clear buffer
            getchar();
        }

    } while(choice != 0);
}
