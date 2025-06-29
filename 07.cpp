// C program that simulates a Role-Based Access Control System

#include <stdio.h>
#include <string.h>

// Define maximum users
#define MAX_USERS 3

// Structure for a user
struct User {
    char username[20];
    char password[20];
    char role[10];  // e.g., Admin, Guest, Student
};

// Predefined users
struct User users[MAX_USERS] = {
    {"admin", "admin123", "Admin"},
    {"guest", "guest123", "Guest"},
    {"student", "stud123", "Student"}
};

// Function to simulate access privileges
void grantAccess(const char *role) {
    printf("\nAccess Granted as %s\n", role);

    if (strcmp(role, "Admin") == 0) {
        printf("Permissions:\n");
        printf(" - View System Settings\n");
        printf(" - Modify Users\n");
        printf(" - Access All Logs\n");
    } else if (strcmp(role, "Guest") == 0) {
        printf("Permissions:\n");
        printf(" - View Public Resources\n");
    } else if (strcmp(role, "Student") == 0) {
        printf("Permissions:\n");
        printf(" - View Own Records\n");
        printf(" - Submit Assignments\n");
    } else {
        printf("Unknown role. No permissions.\n");
    }
}

// Main authentication function
int authenticate(char *inputUser, char *inputPass) {
    for (int i = 0; i < MAX_USERS; i++) {
        if (strcmp(users[i].username, inputUser) == 0 &&
            strcmp(users[i].password, inputPass) == 0) {
            grantAccess(users[i].role);
            return 1;
        }
    }
    return 0;
}

int main() {
    char username[20], password[20];
    int attempts = 0, success = 0;

    printf("===== Role-Based Access Control System =====\n");

    while (attempts < 3 && !success) {
        printf("\nEnter Username: ");
        scanf("%s", username);

        printf("Enter Password: ");
        scanf("%s", password);

        success = authenticate(username, password);

        if (!success) {
            printf("Invalid credentials. Try again.\n");
            attempts++;
        }
    }

    if (!success) {
        printf("\nAccess Denied. Too many failed attempts.\n");
    } else {
        printf("You are logged in successfully.\n");
    }

    return 0;
}


// ===== Role-Based Access Control System =====

// Enter Username: admin
// Enter Password: admin123

// Access Granted as Admin
// Permissions:
//  - View System Settings
//  - Modify Users
//  - Access All Logs
// You are logged in successfully.
