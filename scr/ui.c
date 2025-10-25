#include <stdio.h>
#include <string.h> 
#include <stdlib.h> //screen clear
#include "custom.h" //cuserm file
#include <windows.h> //color

//file handling declarations
#define presiding_file "../admin/presiding_officers.txt"
#define voter_file "../data/voters.txt"
#define CANDIDATE_FILE "../data/candidates.txt"
#define PARTY_FILE "../data/parties.txt"
#define POOLING_FILE "../data/pooling.txt"
#define DISTRICT_FILE "../data/district.txt"


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

    D_seperator();
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
        return 0; // Exit
    default:
        
        printf(" Invalid choice. Please try again.\n");
        time_delay();
        system("cls");
        main_menu();
        break;
    }

    return 0; // Return to main menu 
}

int public_nomination_list()
{
        FILE *fp4;
        char partyID[10], partyName[100];
        char candidateID[20], name[50], districtID[10];
        int age;
        char filename[100];
        int count;
        int totalParties = 0;
        int totalCandidates = 0;

        system("cls");

        // Simple Header
        E_seperator();
        printf("\t  PARTY NOMINATIONS LIST 2025\n");
        E_seperator();
        printf("\n");

        // Open party file
        fp4 = fopen(PARTY_FILE, "r");
        if (fp4 == NULL) {
            color(0x0c);
            printf(" Error: Cannot open parties file!\n");
            color(0x07);
            pressEnterToContinue();
            system("cls");
            main_menu();
            return 1;
        }

        // Read each party
        while (fscanf(fp4, "%[^|]|%[^\n]\n", partyID, partyName) == 2) {
            totalParties++;
            
            // Party Header
            printf("\n");
            D_seperator();
            color(0x0e);
            printf(" PARTY: %s (%s)\n", partyName, partyID);
            color(0x07);
            D_seperator();
            
            // Try to open nomination file
            sprintf(filename, "../data/nomination_list/PA_%s_nomination.txt", partyID);
            FILE *nomFile = fopen(filename, "r");
            
            if (nomFile == NULL) {
                color(0x0c);
                printf(" No candidates found\n");
                color(0x07);
                continue;
            }
            
            // Simple Table Header
            printf("\n %-18s %-25s %-8s %-12s\n", 
                    "Candidate ID", "Name", "Age", "District");
            printf(" %-18s %-25s %-8s %-12s\n", 
                    "------------------", "-------------------------", "--------", "------------");
            
            count = 0;
            
            // Display candidates
            while (fscanf(nomFile, "%[^|]|%[^|]|%d|%[^|]|\n", 
                            candidateID, name, &age, districtID) == 4) {
                
                printf(" %-18s %-25s %-8d %-12s\n", 
                        candidateID, name, age, districtID);
                count++;
                totalCandidates++;
            }
            
            printf("\n");
            color(0x0a);
            printf(" Total: %d candidates\n", count);
            color(0x07);
            
            fclose(nomFile);
        }

        fclose(fp4);

        // Summary
        printf("\n");
        E_seperator();
        color(0x0b);
        printf(" SUMMARY: %d Parties | %d Total Candidates\n", totalParties, totalCandidates);
        color(0x07);
        E_seperator();

        printf("\n");
        pressEnterToContinue();
        system("cls");
        main_menu();

        return 0;
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







