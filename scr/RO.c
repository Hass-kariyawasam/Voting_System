#include <stdio.h>
#include <string.h>
#include <stdlib.h> //screen clear.
#include <windows.h> 
#include "custom.h"

//file handling declarations
#define DISTRICT_FILE "../data/districts.txt"
#define PARTY_FILE "../data/parties.txt"
#define presiding_file "../admin/presiding_officers.txt"
int main(); 



int UI_returning_officer(){
    E_seperator();
    printf("\tRETURNING OFFICER (RO) CONTROL PANEL\n");
    E_seperator();

    printf("\n [1] Accept Nomination List \n");
    printf(" [2] District Result Generation  \n");
    printf(" [3] Nomination Review & Approval \n");
    printf(" [4] Result View and Publication  \n");
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
        district_result_generation();
        break;
    case 3:
        system("cls");
        review_nomination_list();
        break;
  
    case 0:
        system("cls");
        admin_panel(); 
        return 0;
    default:
        
        printf("Invalid choice. Please try again.\n");
        time_delay();
        system("cls");
        UI_returning_officer();
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
            
            UI_returning_officer();
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

int district_result_generation(){
    E_seperator();
    printf("\tDISTRICT RESULT GENERATION\n");
    E_seperator();

    printf(" [1] Generate Results for Colombo (D001) \n");
    printf(" [2] Generate Results for Gampaha (D002) \n");
    printf(" [3] Generate Results for Kandy (D003) \n");
    printf(" [0] Back to RO Menu \n");

    D_seperator();
    printf("Enter your choice: ");
    int choice;
    scanf("%d",&choice);
    switch (choice){
        case 1:
            system("cls");
            printf("Generating results for Colombo (D001)...\n");
            long_delay();
            printf("Results generated successfully!\n");
            pressEnterToContinue();
            system("cls");
            district_result_generation();
            break;
        case 2:
            system("cls");
            printf("Generating results for Gampaha (D002)...\n");
            long_delay();
            printf("Results generated successfully!\n");
            pressEnterToContinue();
            system("cls");
            district_result_generation();
            break;
        case 3:
            system("cls");
            printf("Generating results for Kandy (D003)...\n");
            long_delay();
            printf("Results generated successfully!\n");
            pressEnterToContinue();
            system("cls");
            district_result_generation();
            break;
        case 0:
            system("cls");
            UI_returning_officer();
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            pressEnterToContinue();
            time_delay();
            system("cls");
            district_result_generation();
            break;

    }
    return 0;
}

int review_nomination_list(){
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
            UI_returning_officer();
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            pressEnterToContinue();
            time_delay();
            system("cls");
            review_nomination_list();
            break;

    }
    return 0;
}
