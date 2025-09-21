#include <stdio.h>
#include <string.h>
#include "custerm.h"

int main(); // Forward declaration of main


int main_menu() {
    E_seperator();
    printf("\tWelcome to Sri Lanka Parliament\n");
    printf("\t\tVoting System 2025\n");
    E_seperator();

    printf("[1] Admin Control Panel\n");
    printf("[2] Voter Registration\n");
    printf("[3] Candidate Registration\n");
    printf("[4] Vote Casting (Polling)\n");
    printf("[5] View Nominations List\n");
    printf("[6] Results & Publications\n");
    printf("[0] Exit System\n");

    printf("\n----------------------------------------------\n");
    printf("Enter your choice: ");
    
    int choice;
    scanf("%d", &choice);
    
    switch (choice) {
        case 1:
            admin_panel();
            break;
        case 2:
            
            break;
        case 3:
            
            break;
        case 4:
           
            break;
        case 5:
            
            break;
        case 6:
           
            break;
        case 0:
            printf("Exiting system...\n");
            return 0; // Exit the program
        default:
            printf("Invalid choice. Please try again.\n");
            break;
    }
    
    return 0; // Return to main menu
}

int admin_panel() {
    E_seperator();
    printf("\tADMIN CONTROL PANEL 2025\n");
    E_seperator();
    
    printf("\n [1] Returning Officer (RO) \n");
    printf(" [2] Election Admin \n");
    printf(" [3] Presiding Officer (PO) \n");
    printf(" [4] Party Agent / Observer \n");
    printf(" [0] Back to Main Menu \n");
    
    printf("\n------------------------------------------------- \n");
    printf(" Enter your choice: ");
    
    int choice;
    scanf("%d", &choice);
    
    switch (choice) {
        case 1:
            admin_loging("RETURNING"); // Call RO login
            break;
        case 2:
            admin_loging("ELECTION"); // Call Election Admin panel
            break;
        case 3:
            admin_loging("PRESIDING"); // Call PO panel
            break;
        case 4:
            admin_loging("PARTY_ADMIN"); // Call Party Agent/Observer panel
            break;
        case 0:
            main_menu(); // Return to main menu
            return 0;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
    }
    
    return 0; // Return to admin panel
}
int UI_PO() {
    E_seperator();
    printf("\t\tPRESIDING OFFICER PANEL\n");
    E_seperator();
    printf("\n [1] Open Polling \n");
    printf(" [2] Close Polling \n");
    printf(" [0] Back to Admin Control Panel \n");
    printf("\n------------------------------------------------- \n");
    printf(" Enter your choice: ");
    
    int choice;
    scanf("%d", &choice);
    
    switch (choice) {
        case 1:
            PO_open_polling();
            break;
        case 2:
          
            PO_close_polling();
            break;
        case 0:
            UI_PO(); 
            return 0;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
    }
    
    return 0;
}

int PO_open_polling() {
    E_seperator();
    printf("\t\tOPEN POLLING\n");
    E_seperator();

    printf("\n Confirm action: Do you want to OPEN polling? \n");
    
    printf("\n [1] Yes Open Polling \n");
    printf(" [2] No Cancel and Return \n");

    printf("\n------------------------------------------------- \n");
    printf(" Enter your choice: ");
    
    int choice;
    scanf("%d", &choice);
    
    switch (choice) {
        case 1:
            printf("Polling opened.\n");
            // Add functionality to open polling
            break;
        case 2:
            UI_PO(); // Return to PO panel
            return 0;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
    }
    
    
}

int PO_close_polling() {
    E_seperator();
    printf("\t\tCLOSE POLLING\n");
    E_seperator();

    printf("\n Confirm action: Do you want to CLOSE polling? \n");
    
    printf("\n [1] Yes – Close Polling \n");
    printf(" [2] No  – Cancel and Return \n");

    printf("\n------------------------------------------------- \n");
    printf(" Enter your choice: ");
    
    int choice;
    scanf("%d", &choice);
    
    switch (choice) {
        case 1:
            printf("Polling closed.\n");
            // Add functionality to close polling
            break;
        case 2:
            UI_PO(); // Return to PO panel
            return 0;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
    }
    
   
}

