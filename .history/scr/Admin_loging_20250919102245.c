#include <stdio.h>
#include <string.h>

int admin_loging(const char *user) {
    char username[50];
    char password[50];
    char pass[50];

    printf("==================================================\n");
    printf("\t\t\tELECTION ADMIN LOGIN\n");
    printf("==================================================\n");
    printf("\nPlease enter your credentials:\n\n");   
    printf("Username: ");
    scanf("%49s", username);
    printf("Password: ");
    scanf("%49s", password);
    printf("\n[System] Authenticating...\n");

    // Generate expected password
    snprintf(pass, sizeof(pass), "%s123", user); // E.g., "ELECTION123"

    if (strcmp(username, user) == 0 && strcmp(password, pass) == 0) {
        printf("Login successful!\n");
        scanf("%*c"); // Clear input buffer
    } else {
        printf("Invalid credentials. Please try again.\n");
        // Handle invalid login
    }

    return 0;
}