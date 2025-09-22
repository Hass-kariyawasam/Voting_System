#include <stdio.h>
#include <string.h>
#include <stdlib.h> //screen clear
#include "custom.h"
#include <windows.h>
#define presiding_file "../admin/presiding_officers.txt"
#define voter_file "../data/voters.txt"
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

int polling_login()
{
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
    FILE *fp = fopen(voter_file, "r");
    if (fp == NULL) {
        printf("Error opening file for voters!\n");
        exit(1);
    }
    //get nic and password in voter file and check seperate by |
    /*200423201902|mahee|19|Y|12|36
200429801961|nvsh|20|y|123456|2*/
    char line[200];
    int found = 0;  
    char name[100];
    while (fgets(line, sizeof(line), fp)) {
        char file_nic[50];
        char file_password[50];
        
        // Split the line by '|'
        char *token = strtok(line, "|");
        if (token != NULL) {
            strcpy(file_nic, token);
            token = strtok(NULL, "|"); // Get name
            strcpy(name, token);
            token = strtok(NULL, "|"); // Skip age
            token = strtok(NULL, "|"); // Skip citizenship
            token = strtok(NULL, "|"); // Get password
            if (token != NULL) {
                strcpy(file_password, token);
                // Remove newline character from password if present
                file_password[strcspn(file_password, "\n")] = 0;
                // Compare NIC and password
                if (strcmp(NIC, file_nic) == 0 && strcmp(password, file_password) == 0) {
                    found = 1; // Match found
                    break;
                }
            }
        }
        
    }
    fclose(fp);
    if (found) {
        printf("Login successful!\n");
        time_delay();
        printf("Welcome, %s! Redirecting to Vote Casting Panel...\n", name);
        pressEnterToContinue();
        system("cls");
        votting_casting();
        return 1;
    }
    else
    {
        printf("Invalid NIC or Password. Please try again.\n");
        time_delay();
        system("cls");
        
        polling_login();
        return 0;
    }

    return 0;
}

int votting_casting()
{
    E_seperator();
    printf("\tVOTING CASTING PANEL\n");
    E_seperator();

    char district[10];
    char party_code[10];
    char candidate_codes1[100];
    char candidate_codes2[100];
    char candidate_codes3[100];
    char confirm;

    printf("\nSelect Your District code : ");
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
   


    printf("Enter 1st Candidate Code: ");
    scanf("%99s", candidate_codes1);

    printf("Enter 2nd Candidate Code: ");
    scanf("%99s", candidate_codes2);

    printf("Enter 3rd Candidate Code: ");
    scanf("%99s", candidate_codes3);
    D_seperator();
   
    printf("Candidate Codes 1 --> %s\n",candidate_codes1);
    printf("Candidate Codes 2 --> %s\n",candidate_codes2);
    printf("Candidate Codes 3 --> %s\n",candidate_codes3);
    D_seperator();

    printf("Confirm Vote for: \n");

    printf("(Y/N): ");
    scanf(" %c", &confirm);

    D_seperator();
    printf("[System] Vote successfully cast!\n");
    printf("[System] Thank you for voting.\n");
    D_seperator();
    printf("Redirecting to Main Menu...\n");
    
    pressEnterToContinue();
    time_delay();
    system("cls");
    main_menu();
}

int public_nomination_list()
{
    E_seperator();
    printf("\t\tPUBLIC NOMINATION LIST  2025\n");
    E_seperator();

    printf("\nAvailable Parties: \n");
    printf(" [1] P123 - Unity National Party \n");
    printf(" [2] P456 - Peoples Freedom Front \n");
    printf(" [3] P789 - National Peoples Alliance \n");
    printf(" [0] Back to Main Menu \n");

    D_seperator();
    printf("Enter Party Code to View Candidates: ");
    char party_code[10];
    scanf("%9s", party_code);

    D_seperator();

    D_seperator();
    printf("Redirecting to Main Menu...\n");
    time_delay();
    system("cls");
    main_menu();
}

int election_results_menu()
{
    E_seperator();
    printf("\tELECTION RESULTS MENU 2025\n");
    E_seperator();

    printf("\nAvailable Districts: \n");
    printf(" [1] District-wise Results \n");
    printf(" [2] Party Detail View \n");
    printf(" [0] Back to Main Menu \n");

    D_seperator();
    printf("Enter District Code to View Results: ");

    int choice;
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        system("cls");
        election_results_district_view();
        break;
    case 2:
        system("cls");
        election_results_party_view();
        break;
    
    case 0:
        system("cls");
        main_menu(); // Return to main menu

        
    default:
        
        printf("Invalid choice. Please try again.\n");
        time_delay();
        system("cls");
        election_results_menu();
        break;
    }

    return 0; 
}

int election_results_district_view()
{
    E_seperator();
    printf("\tELECTION RESULTS DISTRICT VIEW 2025\n");
    E_seperator();

    printf("\n Available Districts: \n");
    printf(" [1] D001 - Colombo \n");
    printf(" [2] D002 - Gampaha \n");
    printf(" [3] D003 - Kandy \n");
    printf(" [0] Back to Election Results Menu \n");

    D_seperator();
    printf("Enter District Code to View Results: ");

    char district_code[10];
    scanf("%9s", district_code);
    D_seperator();

    D_seperator();
    // Press [Enter] to return to District Selection...
    printf("press [Enter] to return to District Selection...\n");
    getchar();   // waits until ENTER is pressed
    time_delay();
    system("cls");
    election_results_menu();
    return 0;
}

int election_results_party_view()
{
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
    getchar();   // waits until ENTER is pressed
    time_delay();
    system("cls");
    election_results_menu();
    
    return 0;
}


// TG2082-party admin panel



