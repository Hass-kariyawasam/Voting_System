#include <stdio.h>
#include <string.h>
#include <stdlib.h> //screen clear
#include "custom.h"
#include <windows.h>

#define presiding_file "../admin/presiding_officers.txt"
#define voter_file "../data/voters.txt"
#define CANDIDATE_FILE "../data/candidates.txt"
#define PARTY_FILE "../data/parties.txt"
#define CANDI
int main(); 


// main menu
int main_menu(){

    E_seperator();
    printf("\tWelcome to Sri Lanka Parliament\n");
    printf("\t\tVoting System 2025\n");
    E_seperator();

    printf("\n [1] Admin Control Panel\n");
    printf(" [2] Voter Registration\n");
    printf(" [3] Candidate Registration\n");
    printf(" [4] Vote Casting (Polling)\n");
    printf(" [5] View Nominations List\n");
    printf(" [6] Results & Publications\n");
    printf(" [0] Exit System\n");

    printf("\n----------------------------------------------\n");
    printf(" Enter your choice: ");

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
        poling_Asccss();
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
        printf(" Exiting system...\n");
        return 0; // Exit the program
    default:
        
        printf(" Invalid choice. Please try again.\n");
        time_delay();
        system("cls");
        main_menu();
        break;
    }

    return 0; // Return to main menu 
}
int poling_Asccss(){
    FILE *fp1 = fopen(presiding_file, "r");
    if (fp1 == NULL) {
        printf("Error opening file for presiding officers!\n");
        exit(1);
    }
   
    char status[10];
    fgets(status, sizeof(status), fp1);
    fclose(fp1);
    if (status[0] != '1' && status[0] != '0') {
        system("cls");
        color(0x0c);
        printf("Unknown\n");
        color(0x07);
        pressEnterToContinue();
        system("cls");
        main_menu();

    } else if ( status[0] == '1') {
        system("cls");
        polling_login();
    } else {
        system("cls");
        //redireting screen
        color(0x0c);
        printf("Pooling is not open yet...\n");
        color(0x07);
        pressEnterToContinue();
        system("cls");
        main_menu();
        
        
    }

}
int polling_login()
{
    E_seperator();
    printf("\tPOLLING LOGIN PORTAL\n");
    E_seperator();

    char NIC[50];
    char password[50];

    printf("\n Enter NIC Number\t: ");
    scanf("%49s", NIC);
    printf(" Enter Password\t\t: ");
    scanf("%49s", password);
    D_seperator();
   

    A_delay();
    D_seperator();
    
    FILE *fp = fopen(voter_file, "r");
    if (fp == NULL) {
        printf("Error opening file for voters!\n");
        exit(1);
    }
    
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
        color(0x0a); //GREEN
        printf("Login successful!");
        
        printf("\nWelcome, %s! Redirecting to Vote Casting Panel...\n", name);
        color(0x07);
        D_seperator();
        pressEnterToContinue();
        system("cls");
        votting_casting();
        return 1;
    }
    else
    {   
        
        color(0x0c);
        printf("Invalid NIC or Password. Please try again.\n");
        color(0x07);
        D_seperator();
        pressEnterToContinue();
        time_delay();
        system("cls");
        
        main_menu();
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
 
    

    printf("\n Select Your District code : ");
    scanf("%9s", district);
    D_seperator();

    printf(" Available Parties \n");

    color(0x06);
    printf("\n  Code\t| Name\n");
    printf("--------------------\n");
    FILE *fp1 = fopen(PARTY_FILE, "r");
    if (fp1 == NULL) {
        printf("Error opening file for districts!\n");
        exit(1);
    }
    
    char line[200];
    while (fgets(line, sizeof(line), fp1)) {
        char *token = strtok(line, "|");
        if (token != NULL) {
            printf("  %s\t", token); // party Code
            strcpy(party_code, token);
            token = strtok(NULL, "|");
        }
        if (token != NULL) {
            printf("| %s", token); //  Name
            
        }
    
       
    }
    color(0x07);
    fclose(fp1);
    D_seperator();
    printf(" Enter Party Code: ");
    scanf("%9s", party_code);
    D_seperator();

    printf(" Available Candidates in %s (District %s) \n", party_code, district);
    
    color(0x06);
    printf("\n    District\t| Party\t | Candidate\t|  Name\n");
    printf("    code\t| code\t | Code\t\t|\n");
    printf("------------------------------------------------------\n");

    FILE *fp2 = fopen(CANDIDATE_FILE, "r");
    if (fp2 == NULL) {
        printf("Error opening file for districts!\n");
        exit(1);
    }
    
    char line1[200];

    while (fgets(line, sizeof(line), fp2)) {
        char *fields[20];
        char f_district_code[20] = "";
        char f_party_code[20] = "";
        char f_candi_code[20] ="";
        char *token;
        int count = 0;

        // Tokenize by |
        token = strtok(line, "|");
        while (token != NULL && count < 20) {
            fields[count++] = token;
            token = strtok(NULL, "|");
        }

        
        if (count >= 7) {
            char *f_district_code = fields[count - 2]; 
            char *f_party_code    = fields[count - 1];
            char *f_candi_code    = fields[0];
            char *name     = fields[2];         

            // remove trailing newline from last field
            f_party_code[strcspn(f_party_code, "\r\n")] = 0;
            if (strcmp(f_district_code, district) == 0 && strcmp(f_party_code, party_code) == 0){
                printf("       %s \t|   %s\t |     %s\t|  %-20s\n", f_district_code,  f_party_code,f_candi_code,name);
            }
        }
    }
    
    color(0x07);
    fclose(fp2);
    D_seperator();

    printf(" You may vote for up to 3 candidates in this party \n");
   


    printf(" Enter 1st Candidate Code: ");
    scanf("%99s", candidate_codes1);

    printf(" Enter 2nd Candidate Code: ");
    scanf("%99s", candidate_codes2);

    printf(" Enter 3rd Candidate Code: ");
    scanf("%99s", candidate_codes3);
    D_seperator();

    FILE *fp3 = fopen(CANDIDATE_FILE, "r");
    if (fp2 == NULL) {
        printf("Error opening file for districts!\n");
        exit(1);
    }

    char line2[200];

    while (fgets(line2, sizeof(line2), fp3)) {
        char *fields[20];
        char f_candi_code[20] ="";
        char *token;
        int count = 0;

        // Tokenize by |
        token = strtok(line, "|");
        while (token != NULL && count < 20) {
            fields[count++] = token;
            token = strtok(NULL, "|");
        }

        /*-----------------------------------------------------------------------------------------------------------------------------------------------------------
        මෙකනින් නැවැත්තුවේ check කරන්න candidate cods ටික*/
        if (count >= 7) {
            
            char *f_candi_code    = fields[0];
        }
        if ((strcmp(f_candi_code, candidate_codes1) == 0) && (strcmp(f_candi_code, candidate_codes2)) && (strcmp(f_candi_code, candidate_codes3))){

        }
    }

    printf(" Candidate Codes 1 --> %s\n",candidate_codes1);
    printf(" Candidate Codes 2 --> %s\n",candidate_codes2);
    printf(" Candidate Codes 3 --> %s\n",candidate_codes3);
    D_seperator();

    printf(" Confirm Vote for: \n");

    printf(" (Y/N): ");
    scanf(" %c", &confirm);

    D_seperator();
    color(0x0a);
    printf("[System] Vote successfully cast!\n");
    printf("[System] Thank you for voting.\n");
    color(0x07);
    D_seperator();
    printf(" Redirecting to Main Menu...\n");
    
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



