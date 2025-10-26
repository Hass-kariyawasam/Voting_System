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
#define DISTRICT_FILE "../data/districts.txt"


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
            printf(" %-18s %-25s %-8s %-12s\n", "------------------", "-------------------------", "--------", "------------");
            
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
   int x;
   E_seperator();
   printf("\n \t\tResults & Publications\n");
   
    E_seperator();
    printf("[1] Party votes \n");
    printf("[2] Candidate votes \n");
    printf("[3] Seat Allocation \n");
    printf("[0] Back to Main Manu\n");
   
    printf("\n\nEnter Your Choise  : ");

    
    scanf("%d",&x);
    E_seperator();
    switch(x){
        case 1:


            // KTB
                FILE *fp_party, *fp_votes;
                char partyID[10], partyName[100], vpartyID[10], cvotes[10];
                int votes;
                int totalVotes = 0;
                system("cls");
                E_seperator();
                printf("\t  ELECTION RESULTS 2025\n");
                E_seperator();
                printf("\n %-10s %-25s %-10s\n", "Party ID", "Party Name", "Votes");
                printf(" %-10s %-25s %-10s\n", "----------", "-------------------------", "----------");
                fp_party = fopen(PARTY_FILE, "r");
                fp_votes = fopen("../data/party_votes.txt", "r");
            
                if (fp_party == NULL) {
                    color(0x0c);
                    printf(" Error: Cannot open parties file!\n");
                    color(0x07);
                    pressEnterToContinue();
                    system("cls");
                    main_menu();
                    return 1;
                }
                if (fp_votes == NULL) {
                    color(0x0c);
                    printf(" Error: Cannot open votes file!\n");
                    color(0x07);
                    pressEnterToContinue();
                    system("cls");
                    main_menu();
                    return 1;
                }
                while (fscanf(fp_party, "%[^|]|%[^\n]\n", partyID, partyName) == 2) {
                
                    char line[200];
                    while(fgets(line, sizeof(line), fp_votes)){
                        sscanf(line, "%[^|]|%[^\n]", vpartyID, cvotes);

                        if(strcmp(partyID, vpartyID)==0)
                        {
                            printf(" %-10s %-26s %d\n", vpartyID, partyName, atoi(cvotes));
                            break;
                        }
                    }
                }
                

            
                fclose(fp_votes);
                fclose(fp_party);
                printf("\n");
                E_seperator();
                
                printf("\n");
                pressEnterToContinue();
                system("cls");
                election_results_menu();


    case 2:
            //distplay candidate votes

            struct Candidate {
                char id[10];
                char name[50];
                char party[10];
            
            };

            int main(); {
                struct Candidate cand[100];
                int candCount = 0;
                FILE *fv;
                FILE *fc;
                char line[200];
                char party[10], cid[10];
                int votes;
            
                //Read candidate details
                fc = fopen("..\\data\\candidates.txt", "r");
                if (fc == NULL) {
                    printf("Cannot open candidates.txt\n");
                    return 1;
                }

                while (fgets(line, sizeof(line), fc)) {
            
                    char temp[10];
                    sscanf(line, "%[^|]|%*[^|]|%[^|]|%*[^|]|%*[^|]|%*[^|]|%*[^|]|%s",
                        cand[candCount].id, cand[candCount].name, cand[candCount].party);
                    candCount++;
                }
                fclose(fc);
            
                //Read votes and display
                fv = fopen("..\\data\\candidate_votes.txt", "r");
                if (fv == NULL) {
                    printf("Cannot open candidate_votes.txt\n");
                    return 1;
                }

            system("cls");
            E_seperator();
                printf("\t  ELECTION RESULTS 2025\n");
                E_seperator();
                 printf("\n %-10s %-25s %-10s\n", "Party ID", "Candidate", "Votes");
                printf(" %-10s %-25s %-10s\n", "----------", "-------------------------", "----------");
              

                while (fscanf(fv, "%[^|]|%[^|]|%d\n", party, cid, &votes) == 3) {
                    for (int i = 0; i < candCount; i++) {
                        if (strcmp(cid, cand[i].id) == 0) {
                            printf(" %-10s %-26s %d\n", party, cand[i].name, votes);
                            break;
                        }
                    }
                }

                fclose(fv);

                    printf("\n");
                pressEnterToContinue();
                system("cls");
                election_results_menu();
                return 0;
            }

    case 3:
        system("cls");
        display_seat_allocation();
        pressEnterToContinue();
        time_delay();
        election_results_menu();
        break;
    case 0:
        system("cls");
        main_menu();
        pressEnterToContinue();
        time_delay();
        election_results_menu();
  } 
  
  return 0;
    


}



// Display seat allocation based on party votes and available seats - District Wise
int display_seat_allocation()
{
    char partyIDs[50][10];
    char partyNames[50][100];
    int partyVotes[50];
    int partyCount = 0;

    char districtIDs[50][10];
    char districtNames[50][100];
    int availableSeats[50];
    int districtCount = 0;

    int totalVotes = 0, totalSeats = 0;
    int totalAllocatedAll = 0;

    system("cls");

    // Read districts and available seats
    FILE *fp = fopen(DISTRICT_FILE, "r");
    if (fp == NULL) {
        color(0x0c);
        printf(" Error: Cannot open district file!\n");
        color(0x07);
        pressEnterToContinue();
        system("cls");
        main_menu();
        return 1;
    }

    while (fscanf(fp, "%[^|]|%[^|]|%d\n", 
                  districtIDs[districtCount], 
                  districtNames[districtCount], 
                  &availableSeats[districtCount]) == 3) {
        totalSeats += availableSeats[districtCount];
        districtCount++;
    }
    fclose(fp);

    // Calculate total votes
    fp = fopen("../data/party_votes.txt", "r");
    if (fp == NULL) {
        color(0x0c);
        printf(" Error: Cannot open party votes file!\n");
        color(0x07);
        pressEnterToContinue();
        system("cls");
        main_menu();
        return 1;
    }

    char tempPartyID[10], tempVotes[10];
    while (fscanf(fp, "%[^|]|%[^\n]\n", tempPartyID, tempVotes) == 2) {
        totalVotes += atoi(tempVotes);
    }
    fclose(fp);

    // Read party details and votes
    FILE *fp_party = fopen(PARTY_FILE, "r");
    FILE *fp_votes = fopen("../data/party_votes.txt", "r");

    if (fp_party == NULL || fp_votes == NULL) {
        color(0x0c);
        printf(" Error: Cannot open files!\n");
        color(0x07);
        pressEnterToContinue();
        system("cls");
        election_results_menu();
        return 1;
    }

    char partyID[10], partyName[100], vpartyID[10], cvotes[10];
    int votes;

    while (fscanf(fp_party, "%[^|]|%[^\n]\n", partyID, partyName) == 2) {
        rewind(fp_votes);
        
        while (fscanf(fp_votes, "%[^|]|%[^\n]\n", vpartyID, cvotes) == 2) {
            if (strcmp(partyID, vpartyID) == 0) {
                votes = atoi(cvotes);
                
                strcpy(partyIDs[partyCount], partyID);
                strcpy(partyNames[partyCount], partyName);
                partyVotes[partyCount] = votes;
                
                partyCount++;
                break;
            }
        }
    }

    fclose(fp_party);
    fclose(fp_votes);

    // Display results district-wise
    E_seperator();
    printf("\t  SEAT ALLOCATION 2025 - DISTRICT WISE\n");
    E_seperator();

    // For each district
    for (int d = 0; d < districtCount; d++) {
        printf("\n");
        D_seperator();
        color(0x0e);
        printf(" DISTRICT: %s (%s) - Available Seats: %d\n", 
               districtNames[d], districtIDs[d], availableSeats[d]);
        color(0x07);
        D_seperator();

        printf("\n %-10s | %-25s | %-10s | %-15s\n", 
               "Party ID", "Party Name", "Votes", "Allocated Seats");
        printf(" %-10s | %-25s | %-10s | %-15s\n", 
               "----------", "-------------------------", "----------", "---------------");

        int districtAllocated = 0;

        // Allocate seats for each party in this district
        for (int p = 0; p < partyCount; p++) {
            int seatsForParty = (partyVotes[p] * availableSeats[d]) / totalVotes;
            printf(" %-10s | %-25s | %-10d | %-15d\n", 
                   partyIDs[p], partyNames[p], 
                   partyVotes[p], seatsForParty);
            districtAllocated += seatsForParty;
            totalAllocatedAll += seatsForParty;
        }

        printf("\n");
        color(0x0a);
        printf(" District Total Allocated: %d seats\n", districtAllocated);
        color(0x07);
    }

    printf("\n");
    E_seperator();
    color(0x0b);
    printf(" TOTAL AVAILABLE SEATS: %d | TOTAL ALLOCATED SEATS: %d\n", totalSeats, totalAllocatedAll);
    color(0x07);
    E_seperator();

    printf("\n");
    pressEnterToContinue();
    system("cls");
    election_results_menu();
    return 0;
}

    



      