#include <stdio.h>
#include <string.h>

#define MAX_USERNAME_LENGTH 50
#define MAX_PASSWORD_LENGTH 50

void registerUser() {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter a username (max %d characters): ", MAX_USERNAME_LENGTH);
    scanf("%s", username);

    printf("Enter a password (max %d characters): ", MAX_PASSWORD_LENGTH);
    scanf("%s", password);

    // Save the username and password to a file (for demonstration purposes)
    FILE *file = fopen("text.txt", "a");
    if (file != NULL) {
        fprintf(file, "%s %s\n", username, password);
        fclose(file);
        printf("User registered successfully.\n");
        printf("Username: %s\n", username);
        printf("Password: %s\n", password);
    } else {
        printf("Error: Unable to open file for writing.\n");
    }
}

void loginUser() {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    int found = 0;

    printf("Enter your username: ");
    scanf("%s", username);

    printf("Enter your password: ");
    scanf("%s", password);

    // Check if the provided username and password match any stored credentials
    FILE *file = fopen("text.txt", "r");
    if (file != NULL) {
        char storedUsername[MAX_USERNAME_LENGTH];
        char storedPassword[MAX_PASSWORD_LENGTH];

        while (fscanf(file, "%s %s", storedUsername, storedPassword) != EOF) {
            if (strcmp(username, storedUsername) == 0 && strcmp(password, storedPassword) == 0) {
                printf("Login successful. Welcome, %s!\n", username);
                found = 1;
                break;
            }
        }

        fclose(file);

        if (!found) {
            printf("Invalid username or password. Please try again.\n");
        }
    } else {
        printf("Error: Unable to open file for reading.\n");
    }
}

int main() {
    int choice;

    while (1) {
        printf("1. Register\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                printf("Visit Us Again.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
