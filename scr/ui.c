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

//Presiding Officer (PO) panel
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

// PO functions
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

    printf("\n------------------------------------------------- \n");
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
    printf("-------------------------------------------------\n");
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
    printf("-------------------------------------------------\n");
    
    printf("Available Parties: \n");
   

    printf("-------------------------------------------------\n");
    
    printf("Enter Party Code: ");
    scanf("%9s", party_code);
    printf("-------------------------------------------------\n");
    
    printf("Available Candidates in %s (District %s): \n", party_code, district);
   
    printf("-------------------------------------------------\n");
    
    printf("You may vote for up to 3 candidates in this party. \n");
    printf("Enter Candidate Codes (separated by commas): ");
    scanf("%99s,%99s,%99s", candidate_codes);
    printf("-------------------------------------------------\n");
    
    printf("Confirm Vote for: \n");
    
    
    
    printf("(Y/N): ");
    scanf(" %c", &confirm);

    printf("-------------------------------------------------\n");
    printf("[System] Vote successfully cast!\n");
    printf("[System] Thank you for voting.\n");
    printf("-------------------------------------------------\n");
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
    
    printf("\n------------------------------------------------- \n");
    printf("Enter Party Code to View Candidates: ");
    
    char party_code[10];
    scanf("%9s", party_code);
    printf("-------------------------------------------------\n");

    printf("-------------------------------------------------\n");
    //Press [Enter] to return to Party Selection...
    printf("press [Enter] to return to Party Selection...");
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
             district_registration();
            break;
        
        case 2:
            party_registration(); 
            break;
        case 3:
            final_result_declaration();
            break;

        case 4:
            UI_election_admin();
            break;


        }
    return 0;
}


 int district_registration(){
    E_seperator();
    printf("\t\tDostrict Registration\n");
    E_seperator();

    printf("[1] Add New District \n");
    printf("[2] Display All Districts \n");
    printf("[0] Back to Election Admin Panel \n");

    D_seperator();
    printf("Enter your choice: ");
    int choice;
    scanf("%d",&choice);

        switch (choice){
            case 1:
               add_new_district();
                break;
            case 2:
               display_all_districts();
                break;
            case 0:
                UI_election_admin();
            
            default:
            printf("Invalid choice. Please try again.\n");
            break;

        }
    return 0;
 }

 int add_new_district(){
    E_seperator();
    printf("\t\tAdd New District\n");
    E_seperator();

    char district_name[20];
    char district_code[10];

    printf("Enter District Name: ");
    scanf("%s", district_name);
    printf("Enter District Code: ");
    scanf("%s", district_code);

    printf("-------------------------------------------------\n");
    printf("[System] New district '%s' with code '%s' added successfully!\n", district_name, district_code);
    printf("-------------------------------------------------\n");

 printf("Enter your choice: ");
    int choice;
    scanf("%d",&choice);

        switch (choice){
        
            case 0:
                district_registration();
            
            default:
            printf("Invalid choice. Please try again.\n");
            break;

        }


    return 0;

 }

 int display_all_districts(){
    E_seperator();
    printf("\t\tAll Registered Districts\n");
    E_seperator();
    printf("-------------------------------------------------\n");

    //need to add registered districts from database


 }      

int party_registration(){
    E_seperator();
    printf("\t\tParty Registration\n");
    E_seperator();

    char party_name[50];
    char party_code[10];

    printf("Enter Party Name: ");
    scanf("%s", party_name);
    printf("Enter Party Code: ");
    scanf("%s", party_code);

    printf("-------------------------------------------------\n");
    printf("[System] New party '%s' with code '%s' registered successfully!\n", party_name, party_code);
    printf("-------------------------------------------------\n");

     printf("Enter your choice: ");
    int choice;
    scanf("%d",&choice);

        switch (choice){
            
            case 0:
                district_registration();
            
            default:
            printf("Invalid choice. Please try again.\n");
            break;

        }
    
    return 0;

}
int display_registerd_parties(){
    E_seperator();
    printf("\t\tAll Registered Parties\n");
    E_seperator();
    printf("-------------------------------------------------\n");

    //need to add registered parties from database
return 0;  
}   
 int final_result_declaration(){
    E_seperator();
    printf("\t\tFinal Result Declaration\n");
    E_seperator();

    printf("[1] Collect District Results \n");
    printf("[2] Generate Final Result Summary \n");
    printf("[0] Back to Election Admin Panel \n");

    D_seperator();
    printf("Enter your choice: ");
    int choice;
    scanf("%d",&choice);

        switch (choice){
            case 1:
               //*******************COLLECT DISTRICT RESULT**************************************************** 
                break;
            case 2:
               //********************enerate Final Result Summary*************************************************** 
                break;
            case 0:
                UI_election_admin();
            
            default:
            printf("Invalid choice. Please try again.\n");
            break;

        }
    return 0;  
 }  

