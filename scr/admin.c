#include <stdio.h>
#include <string.h>
#include <stdlib.h> //screen clear
#include "custom.h"

int main(); 

// main menu
int main_menu(){

    E_seperator();
    printf("\tWelcome to Sri Lanka Parliament\n");
    printf("\t\tVoting System 2025\n");
    E_seperator();

    printf(" [1] Admin Control Panel\n");
    printf(" [2] Voter Registration\n");
    printf(" [3] Candidate Registration\n");
    printf(" [4] Vote Casting (Polling)\n");
    printf(" [5] View Nominations List\n");
    printf(" [6] Results & Publications\n");
    printf(" [0] Exit System\n");

    printf("\n----------------------------------------------\n");
    printf("Enter your choice: ");

    int choice;
    scanf("%d", &choice);

    switch (choice){
    case 1:
        system("cls");
        admin_panel();

        break;
    case 2:
        system("cls");
        voter_registration();
        break;
    case 3:
        system("cls");
        candidate_registration();
         break;
    case 4:
        system("cls");
        polling_login();
        break;
    case 5:
        system("cls");
        public_nomination_list();
        break;
    case 6:
        system("cls");
        election_results_menu();
        break;
    case 0:
        system("cls");
        printf("Exiting system...\n");
        return 0; // Exit the program
    default:
        
        printf("Invalid choice. Please try again.\n");
        time_delay();
        system("cls");
        main_menu();
        break;
    }

    return 0; // Return to main menu 
}

// admin panel
int admin_panel()
{
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

    switch (choice)
    {
    case 1:
        system("cls");
        admin_loging("RETURNING"); // Call RO login
        break;
    case 2:
        system("cls");
        admin_loging("ELECTION"); // Call Election Admin panel
        break;
    case 3:
        system("cls");
        admin_loging("PRESIDING"); // Call PO panel
        break;
    case 4:
        system("cls");
        admin_loging("PARTY_ADMIN"); // Call Party Agent/Observer panel
        break;
    case 0:
        system("cls");
        main_menu(); // Return to main menu
        return 0;
    default:
        printf("Invalid choice. Please try again.\n");
        time_delay();
        system("cls");
        admin_panel();
        break;
    }

    return 0; // Return to admin panel
}

// Presiding Officer (PO) panel
int UI_PO()
{
    E_seperator();
    printf("\tPRESIDING OFFICER PANEL\n");
    E_seperator();
    printf("\n [1] Open Polling \n");
    printf(" [2] Close Polling \n");
    printf(" [0] Back to Admin Control Panel \n");
    D_seperator();
    printf(" Enter your choice: ");
    
    int choice;
    scanf("%d", &choice);
    D_seperator();

    switch (choice)
    {
    case 1:
        system("cls");
        PO_open_polling();
        break;
    case 2:
        system("cls");
        PO_close_polling();
        break;
    case 0:
        system("cls");
        admin_panel(); 
        return 0;
    default:
        printf("Invalid choice. Please try again.\n");
        time_delay();
        system("cls");
        UI_PO();
        break;
    }

    return 0;
}

// PO functions
int PO_open_polling()
{
    E_seperator();
    printf("\tOPEN POLLING\n");
    E_seperator();

    printf("\n Confirm action: Do you want to OPEN polling? \n");

    printf("\n [1] Yes Open Polling \n");
    printf(" [0] No Cancel and Return \n");

    D_seperator();
    printf(" Enter your choice: ");

    int choice;
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        system("cls");
        break;
    case 0:
        system("cls");
        UI_PO(); // Return to PO panel
        return 0;
    default:
        printf("Invalid choice. Please try again.\n");
        time_delay();
        system("cls");
        PO_open_polling();
        break;
    }

    return 0;
}

int PO_close_polling()
{
    E_seperator();
    printf("\t\tCLOSE POLLING\n");
    E_seperator();

    printf("\n Confirm action: Do you want to CLOSE polling? \n");

    printf("\n [1] Yes Close Polling \n");
    printf(" [0] No  Cancel and Return \n");

    D_seperator();
    printf(" Enter your choice: ");

    int choice;
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        system("cls");
        break;
    case 0:
        system("cls");
        UI_PO();
        return 0;
    default:
        printf("Invalid choice. Please try again.\n");
        time_delay();
        system("cls");
        PO_close_polling();
        break;
    }

    return 0;
}
//Election Admin panel

int UI_election_admin(){
    E_seperator();
    printf("\tELECTION ADDMIN PANNEL\n");
    E_seperator();

    printf(" [1] District Registration \n");
    printf(" [2] Party Registration \n");
    printf(" [3] Final Result Declaration \n");
    printf(" [0] Back to Admin Control Panel\n");

    D_seperator();

    printf("Enter your choice: ");
    int choice;

    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        system("cls");
        district_registration();
        break;

    case 2:
        system("cls");
        party_registration();
        break;
    case 3:
        system("cls");
        final_result_declaration();
        break;

    case 0:
        
        system("cls");

        admin_panel();
        break;
    }
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
                system("cls");
               add_new_district();
                break;
            case 2:
                system("cls");
               display_all_districts();
                break;
            case 0:
                system("cls");
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
    printf("Options: \n");
    printf(" [0] Back \n");
    printf("Enter your choice: ");
    int choice;
    scanf("%d",&choice);

    switch (choice){
        
        case 0:
            system("cls");
            district_registration();
            break;
        default:
            
            printf("Invalid choice. Please try again.\n");
            printf("Redirecting to Party Registration Menu...\n");
            
            system("cls");
            time_delay();
            pressEnterToContinue();
            break;

        }


    return 0;

 }

 int display_all_districts(){
    E_seperator();
    printf("\t\tAll Registered Districts\n");
    E_seperator();
    printf("-------------------------------------------------\n");
    pressEnterToContinue();
    system("cls");
    district_registration();

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
                system("cls");
                district_registration();
            
            default:
            printf("Invalid choice. Please try again.\n");
            printf("Redirecting to Party Registration Menu...\n");
           
            system("cls");
             time_delay();
            pressEnterToContinue();
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
              pressEnterToContinue();
              system("cls");
               UI_election_admin();
                break;
            case 2:
               pressEnterToContinue();
               system("cls");
               UI_election_admin();
                break;
            case 0:
                system("cls");
                UI_election_admin();
            
            default:
            printf("Invalid choice. Please try again.\n");
            break;

        }
    return 0;  
 }  


 
int UI_party_admin()
{
    E_seperator();
    printf("\tPARTY ADMIN PANEL\n");
    E_seperator();

    int choice;
    printf("\n [1] SUBMIT NOMINATION LISTt\n");
    printf(" [0] Logout\n");
    D_seperator();

    printf("Enter your choice:");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        system("cls");
        submit_nomination();
        break;

    case 0:
        system("cls");
        admin_panel();
        break;
    default:

        printf("invalid input");
        time_delay();
        system("cls");
        admin_panel();
    }
}

int submit_nomination(){

    E_seperator();
    printf("SUBMIT NOMINATION LIST\n");
    E_seperator();

    int code;
    char name[20];

    printf("\nEnter party code: \t");
    scanf("%d", &code);
    printf("Enter party name: \t");
    scanf(" %s", name);
    D_seperator();

    printf("Confirm Submission? (Y/N): ");
    scanf(" %*c");
    printf("\nSaving Nomination list...");
    printf("\nNomination list  successfully submitted to Ron");
    D_seperator();
    printf("Redirecting to Party Admin Menu...\n");
    getchar();   // waits until ENTER is pressed
    long_delay();
    system("cls");
    
    
    UI_party_admin();
    return 0;
}


int returnig_officer(){
    E_seperator();
    printf("\tRETURNING OFFICER (RO) CONTROL PANEL\n");
    E_seperator();

    printf(" [1] Accept Nomination List \n");
    printf(" [2] District Result Generation  \n");
    printf(" [3] Nomination Review & Approval \n");
    printf(" [4] Resalt View and Publication  \n");
    printf(" [0] Back to Admin Panel \n");

    D_seperator();
    printf("Enter your choice: ");
    int choice;
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        system("cls");
        accept_nomination_list();
        break;
    case 2:
        system("cls");
        Public_nomination_list();
        break;
    case 3:
        system("cls");
        review();
        break;
    
    case 0:
        system("cls");
        admin_panel(); 
        return 0;
    default:
        
        printf("Invalid choice. Please try again.\n");
        time_delay();
        system("cls");
        returnig_officer();
        break;
    }

    return 0; // Return to RO panel
}

int accept_nomination_list(){
    E_seperator();
    printf("\tACCEPT NOMINATION LIST BY PARTY\n");
    E_seperator();
    
    // Display the nomination list
    printf(" [ Party: United People’s Party (UPP) ] \n");
    printf("   - Candidate 01: A. Perera (Colombo) \n");
    printf("   - Candidate 02: S. Silva (Colombo) \n");
    printf("   - Candidate 03: K. Fernando (Colombo) \n");


    printf("------------------------------------------------- \n");
    printf("Options: \n");
    printf("[0] Back to RO Menu \n");
    printf("------------------------------------------------- \n");
    printf("Enter your choice: \n");
    int choice;
    scanf("%d",&choice);
    switch (choice){
        case 0:
            system("cls");
            returnig_officer();
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            pressEnterToContinue();
            time_delay();
            system("cls");
            accept_nomination_list();
            break;

    }
    return 0;
}

int Public_nomination_list(){
    E_seperator();
    printf("\tVIEW NOMINATION LIST\n");
    E_seperator();

    printf(" [ Party: United People’s Party (UPP) ] \n");
    printf("   - Candidate 01: A. Perera (Colombo) \n");
    printf("   - Candidate 02: S. Silva (Colombo) \n");
    printf("   - Candidate 03: K. Fernando (Colombo) \n");

    printf("------------------------------------------------- \n");
    printf("Options: \n");
    printf("[0] Back to Main Menu \n");
    printf("------------------------------------------------- \n");
    printf("Enter your choice: \n");
    int choice;
    scanf("%d",&choice);
    switch (choice){
        case 0:
            system("cls");
            returnig_officer();
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            pressEnterToContinue();
            time_delay();
            system("cls");
            Public_nomination_list();
            break;

    }
    return 0;
}


int review(){
    E_seperator();
    printf("\tNOMINATION REVIEW & APPROVAL\n");
    E_seperator();

    printf(" [1] United People’s Party (UPP)      -> 12 Candidates \n");
    printf(" [2] National People’s Power (NPP)    -> 10 Candidates \n");
    printf(" [3] Freedom Alliance (FA)            -> 08 Candidates \n");
    printf(" [4] Democratic Front (DF)            -> 07 Candidates \n");

    printf("------------------------------------------------- \n");
    printf("Options: \n");
    printf("Select a Party [1-4] \n");
    printf("[0] Back to RO Menu \n");
    printf("------------------------------------------------- \n");
    printf("Enter your choice: \n");
    int choice;
    scanf("%d",&choice);
    switch (choice){
        case 0:
            system("cls");
            returnig_officer();
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            pressEnterToContinue();
            time_delay();
            system("cls");
            review();
            break;

    }
    return 0;
}
