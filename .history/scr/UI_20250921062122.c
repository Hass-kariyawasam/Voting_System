#include <stdio.h>
#include <string.h>
#include "custerm.h"

int main(); // Forward declaration of main

//main menu
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
           polling_login();
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

//admin panel
int admin_panel() {
    E_seperator();
    printf("\tADMIN CONTROL PANEL 2025\n");
    E_seperator();
    
    printf("\n [1] Returning Officer (RO) \n");
    printf(" [2] Election Admin \n");
    printf(" [3] Presiding Officer (PO) \n");
    printf(" [4] Party Agent / Observer \n");
    printf(" [0] Back to Main Menu \n");
    
    D_seperator();
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

//Presiding Officer (PO) panel
int UI_PO() {
    E_seperator();
    printf("\t\tPRESIDING OFFICER PANEL\n");
    E_seperator();
    printf("\n [1] Open Polling \n");
    printf(" [2] Close Polling \n");
    printf(" [0] Back to Admin Control Panel \n");
    D_seperator();
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

// PO functions
int PO_open_polling() {
    E_seperator();
    printf("\t\tOPEN POLLING\n");
    E_seperator();

    printf("\n Confirm action: Do you want to OPEN polling? \n");
    
    printf("\n [1] Yes Open Polling \n");
    printf(" [2] No Cancel and Return \n");

    D_seperator();
    printf(" Enter your choice: ");
    
    int choice;
    scanf("%d", &choice);
    
    switch (choice) {
        case 1:
           
            
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

int PO_close_polling() {
    E_seperator();
    printf("\t\tCLOSE POLLING\n");
    E_seperator();

    printf("\n Confirm action: Do you want to CLOSE polling? \n");
    
    printf("\n [1] Yes – Close Polling \n");
    printf(" [2] No  – Cancel and Return \n");

    D_seperator();
    printf(" Enter your choice: ");
    
    int choice;
    scanf("%d", &choice);
    
    switch (choice) {
        case 1:
            
           
            break;
        case 2:
            UI_PO(); 
            return 0;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
    }
    
     return 0; 
}




int polling_login() {
    E_seperator();
    printf("\tPOLLING LOGIN PORTAL\n");
    E_seperator();

    char NIC[50];
    char password[50];

    printf("\nEnter NIC Number: ");
    scanf("%49s", NIC);
    printf("Enter Password: ");
    scanf("%49s", password);
    D_seperator();
    printf("[System] Authenticating...\n");
    if (strlen(NIC) == 10 && strcmp(password, "VOTE2025") == 0) {
        printf("Login successful!\n");
        votting_casting();
        return 1; 
    } else {
        printf("Invalid NIC or Password. Please try again.\n");
        main_menu();
        return 0; 
    }
   

    return 0;
}



int votting_casting() {
    E_seperator();
    printf("\t\tVOTING CASTING PANEL\n");
    E_seperator();

    char district[10];
    char party_code[10];
    char candidate_codes[100];
    char confirm;

    printf("\nSelect Your District: ");
    scanf("%9s", district);
    D_seperator();
    
    printf("Available Parties: \n");
   

    D_seperator();
    
    printf("Enter Party Code: ");
    scanf("%9s", party_code);
    D_seperator();
    
    printf("Available Candidates in %s (District %s): \n", party_code, district);
   
    D_seperator();
    
    printf("You may vote for up to 3 candidates in this party. \n");
    printf("Enter Candidate Codes (separated by commas): ");
    scanf("%99s,%99s,%99s", candidate_codes);
    D_seperator();
    
    printf("Confirm Vote for: \n");
    
    
    
    printf("(Y/N): ");
    scanf(" %c", &confirm);

    D_seperator();
    printf("[System] Vote successfully cast!\n");
    printf("[System] Thank you for voting.\n");
    D_seperator();
    printf("Redirecting to Main Menu...\n");
    for (int i = 0; i <= 10; i++) {
            printf(".");
            for (int j = 0; j < 100000000; j++); // Inner delay loop
    }
}


int public_nomination_list() {
    E_seperator();
    printf("\t\tPUBLIC NOMINATION LIST  2025\n");
    E_seperator();

    printf("\nAvailable Parties: \n");
    printf("[1] P123 - Unity National Party \n");
    printf("[2] P456 - Peoples Freedom Front \n");
    printf("[3] P789 - National Peoples Alliance \n");
    printf("[0] Back to Main Menu \n");
    
    D_seperator();
    printf("Enter Party Code to View Candidates: ");
    
    char party_code[10];
    scanf("%9s", party_code);
    D_seperator();

    D_seperator();
    //Press [Enter] to return to Party Selection...
    printf("press [Enter] to return to Party Selection...");
    return 0;   
}
        
      
    

int election_results_menu() {
    E_seperator();
    printf("\t\tELECTION RESULTS MENU 2025\n");
    E_seperator();

    printf("\nAvailable Districts: \n");
    printf("[1] District-wise Results \n");
    printf("[2] Party Detail View \n");
    printf("[3] Rejected Party \n");
    printf("[0] Back to Main Menu \n");
    
    D_seperator();
    printf("Enter District Code to View Results: ");
    
    int choice;
    scanf("%d", &choice);
    
    switch (choice) {
        case 1:
           
            break;
        case 2:
           
            break;
        case 3:
           
            break;
        case 0:
            main_menu(); // Return to main menu
            return 0;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
    }
    
    return 0; // Return to election results menu
}

int election_results_district_view() {
    E_seperator();
    printf("\t\tELECTION RESULTS DISTRICT VIEW 2025\n");
    E_seperator();

    printf("\nAvailable Districts: \n");
    printf("[1] D001 - Colombo \n");
    printf("[2] D002 - Gampaha \n");
    printf("[3] D003 - Kandy \n");
    printf("[0] Back to Election Results Menu \n");
    
    D_seperator();
    printf("Enter District Code to View Results: ");
    
    char district_code[10];
    scanf("%9s", district_code);
    D_seperator();

    D_seperator();
    //Press [Enter] to return to District Selection...
    printf("press [Enter] to return to District Selection...");
    return 0;   
}


int NATIONAl_ELECTED(){
    E_seperator();
    printf("\tUNITY NATIONAL PARTY (P123) ELECTED MPs");
    E_seperator();

    printf("DISTRICT: Colombo (D001) = Seats Won: 6 ");
    printf("------------------------------------------------- \n");
    printf("Candidate Name      Candidate Code   Preference Votes   Status \n");
    printf("------------------------------------------------- \n");
    printf("Mr. A. Perera       C001             25,430             Elected \n");
    printf("Ms. B. Silva        C002             23,120             Elected \n");
    printf("Mr. R. Fernando     C003             19,870             Elected \n");
    printf("Ms. D. Kumari       C004             18,530             Elected \n");
    printf("Mr. L. Jayasinghe   C005             17,990             Elected \n");
    printf("Mr. K. Wickrama     C006             16,750             Elected \n");
    printf("------------------------------------------------- \n");
    printf("DISTRICT: Gampaha (D002) = Seats Won: 5 \n");
    printf("------------------------------------------------- \n");
    printf("Candidate Name      Candidate Code   Preference Votes   Status \n");
    printf("------------------------------------------------- \n");
    printf("Ms. S. Fernando     C021             22,300             Elected \n");
    printf("Mr. J. Silva        C022             21,880             Elected \n");
    printf("Mr. T. Perera       C023             19,670             Elected \n");
    printf("Mr. D. Bandara      C024             18,540             Elected \n");
    printf("Ms. W. Kumari       C025             16,930             Elected \n");
    printf("------------------------------------------------- \n");
    printf("Press [Enter] to return to Party Summary...");
    return 0;   
    
} 

int UI_election_admin(){
    E_seperator();
    printf("\t\tELECTION ADDMIN PANNEL\n");
    E_seperator();

    printf("[1] District Registration \n");
    printf("[2] Party Registration \n");
    printf("[3] Final Result Declaration \n");
    printf("[0] Back to Admin Control Panel\n");

    D_seperator();

    printf("Enter your choice: ");
    int choice;
    scanf("%d",&choice);

    switch(choice){
        case 1:
            //*********************************************************************** */
            break;
        
        case 2:
            //********************************************************************* */
            break;
        case 3:
            //******************************************************************** */
            break;

        case 4:
            //******************************************************************** */
            break;

        
        }



}     