#include <stdio.h>
#include <string.h>
#include "custom.h"
int main(); // Forward declaration of main


int admin_loging(const char *user) {

    char username[50];
    char password[50];
    char pass[50];
    char userid[50];

    snprintf(userid, sizeof(userid), "%s LOGIN PORTAL", user); // E.g., "ELECTION LOGIN PORTAL"

    E_seperator();  // Call to separator function
    printf("\t%s\n",userid);
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
        if (strcmp(user, "ELECTION") == 0) {
            UI_election_admin();
           
        } else if (strcmp(user, "RETURNING") == 0) {
            
                        
        } else if (strcmp(user, "PRESIDING") == 0) {
            UI_PO();

        } else if (strcmp(user, "PARTY_ADMIN") == 0){
            UI_party_admin();
        }  else {
            printf("ERRO Unknown user type.\n");
            admin_panel();
        }
        
        
        return 1; 

    } else {
        printf("Invalid credentials. Please try again.\n");
        
        printf("Redirecting to admin menu...\n");
        for (int i = 0; i <= 10; i++) {
            printf(".");
            for (int j = 0; j < 100000000; j++); // Inner delay loop

        }
        admin_panel();
         printf("\n");
    }

    return 0;
}