#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include "custerm.h"

int main(); // Forward declaration of main

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
            printf("Polling opened.\n");
            // Add functionality to open polling
            break;
        case 2:
            printf("Polling closed.\n");
            // Add functionality to close polling
            break;
        case 0:
            main(); // Return to main menu
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
    
    printf("\n [1] Yes – Open Polling \n");
    printf(" [2] No  – Cancel and Return \n");

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
    
    return 0;
}
/*================================================= 
                 OPEN POLLING 
================================================= 
 
 Confirm action: Do you want to OPEN polling? 
 
 [1] Yes – Open Polling 
 [2] No  – Cancel and Return 
 
------------------------------------------------- 
 Enter your choice: _*/

