#include <stdio.h>
#include <string.h>
#include <stdlib.h> //screen clear
#include "custom.h"
#include <windows.h>

int main(); 

int admin_loging(const char user[20]) {

    char username[50];
    char password[50];
    char pass[50];
    char userid[50];

    snprintf(userid, sizeof(userid), "%s LOGIN PORTAL", user); // E.g., "ELECTION LOGIN PORTAL"

    E_seperator();  // Call to separator function
    printf("\t%s\n",userid);
    E_seperator(); // Call to separator function

    printf("\n Please enter your credentials \n");   
    D_seperator();
    printf(" Username : ");
    scanf("%49s", username);
    printf(" Password : ");
    scanf("%49s", password);
    D_seperator();

    
    A_delay();
    D_seperator();
    // Generate password
    snprintf(pass, sizeof(pass), "%s123", user); // E.g.,, "ELECTION123"


    if (strcmp(username, user) == 0 && strcmp(password, pass) == 0) {
        color(0x0a); 
        printf(" Login successful!\n");
        color(0x07); 
        D_seperator();
            
        
        printf("\n");
        if (strcmp(user, "ELECTION") == 0) {
            pressEnterToContinue();
            system("cls");
            UI_election_admin();
           
        } else if (strcmp(user, "RETURNING") == 0) {
            pressEnterToContinue();
            system("cls");
            UI_returning_officer();
            
        } else if (strcmp(user, "PRESIDING") == 0) {
            pressEnterToContinue();
            system("cls");
            UI_PO();

        } else if (strcmp(user, "PARTY_ADMIN") == 0){
            pressEnterToContinue();
            system("cls");
            UI_party_admin();
        }  else {
            printf("Error Unknown user type.\n");
            pressEnterToContinue();
            time_delay();
            system("cls");
            admin_panel();
        }
        
        
        return 1; 

    } else {
        color(0x0c);
        printf(" Invalid credentials. Please try again.\n");
        color(0x07);
        printf(" Redirecting to admin menu...\n");
        pressEnterToContinue();
        system("cls");
        admin_panel();
      
    }

    return 0;
}