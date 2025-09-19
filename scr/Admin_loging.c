#include <stdio.h>
#include <string.h>
#include "custerm.h"
int main(); // Forward declaration of main
int admin_loging(const char *user) {

    char username[50];
    char password[50];
    char pass[50];
    char userid[50];

    snprintf(userid, sizeof(userid), "%s LOGIN PORTAL", user); // E.g., "ELECTION LOGIN PORTAL"

    E_seperator();  // Call to separator function
    printf("\t\t%s\n",userid);
    E_seperator(); // Call to separator function

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
        // time delay simulation
        printf("initializing");
       
        // Simple delay loop
        for (int i = 0; i <= 10; i++) {
            printf(".");
            for (int j = 0; j < 100000000; j++); // Inner delay loop
        }
        
        printf("\n");
        
        main();
        return 1; // Successful login

    } else {
        printf("Invalid credentials. Please try again.\n");
        // Handle invalid login
    }

    return 0;
}