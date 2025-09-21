#include <stdio.h>
#include <string.h>
#include "custerm.h"
int main(); // Forward declaration of main
int admin_loging(const char *user) {

    char username[50];
    char password[50];
    char pass[50];

    printf("==================================================\n");
    printf("\t\tELECTION ADMIN LOGIN\n");
    printf("==================================================\n");
    printf("\nPlease enter your credentials:\n\n");   
    printf("Username: ");
    scanf("%49s", username);
    printf("Password: ");
    scanf("%49s", password);
    printf("\n[System] Authenticating...\n");

    //time delay simulation
    for (int i = 0; i < 100000000; i++);
    // Generate expected password
    snprintf(pass, sizeof(pass), "%s123", user); // E.g., "ELECTION123"

    if (strcmp(username, user) == 0 && strcmp(password, pass) == 0) {
        printf("Login successful!\n");
        // time delay simulation
        for (int i = 0; i < 100000000; i++);
        main();
    } else {
        printf("Invalid credentials. Please try again.\n");
        // Handle invalid login
    }

    return 0;
}