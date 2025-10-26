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
    int x;
    E_seperator();
    printf("\n \t\tResults & Publications\n");
    E_seperator();
    printf("[1] Party votes \n");
    printf("[2] Candidate votes \n");
    printf("[3] Seat Allocation \n");
    printf("\n\nEnter Your Choice -");
    printf("\n");
    E_seperator();
    scanf("%d", &x);

    switch(x) {
        case 1:
            display_party_results();
            break;
        case 2:
            display_candidate_results();
            break;
        case 3:
            display_seat_allocation();
            break;
        default:
            printf(" Invalid choice\n");
            pressEnterToContinue();
            system("cls");
            main_menu();
    }
    return 0;
}

// Display party results with separation by party
int display_party_results()
{
    FILE *fp_party, *fp_votes;
    char partyID[10], partyName[100], vpartyID[10], cvotes[10];
    int votes, totalVotes = 0;
    int partyCount = 0;

    system("cls");
    E_seperator();
    printf("\t  ELECTION RESULTS 2025 - PARTY VOTES\n");
    E_seperator();

    // First pass: calculate total votes
    fp_party = fopen(PARTY_FILE, "r");
    fp_votes = fopen("../data/party_votes.txt", "r");

    if (fp_party == NULL || fp_votes == NULL) {
        color(0x0c);
        printf(" Error: Cannot open files!\n");
        color(0x07);
        pressEnterToContinue();
        system("cls");
        main_menu();
        return 1;
    }

    while (fscanf(fp_votes, "%[^|]|%[^\n]\n", vpartyID, cvotes) == 2) {
        totalVotes += atoi(cvotes);
    }

    fclose(fp_votes);

    // Second pass: display results with percentages
    printf("\n %-10s %-25s %-10s %-12s\n", "Party ID", "Party Name", "Votes", "Percentage");
    printf(" %-10s %-25s %-10s %-12s\n", "----------", "-------------------------", "----------", "----------");

    fp_votes = fopen("../data/party_votes.txt", "r");

    while (fscanf(fp_party, "%[^|]|%[^\n]\n", partyID, partyName) == 2) {
        rewind(fp_votes);
        
        while (fscanf(fp_votes, "%[^|]|%[^\n]\n", vpartyID, cvotes) == 2) {
            if (strcmp(partyID, vpartyID) == 0) {
                int voteCount = atoi(cvotes);
                float percentage = totalVotes > 0 ? (voteCount * 100.0) / totalVotes : 0;
                
                printf(" %-10s %-25s %-10d %.2f%%\n", vpartyID, partyName, voteCount, percentage);
                partyCount++;
                break;
            }
        }
    }

    printf("\n");
    E_seperator();
    color(0x0b);
    printf(" TOTAL PARTIES: %d | TOTAL VOTES: %d\n", partyCount, totalVotes);
    color(0x07);
    E_seperator();

    fclose(fp_party);
    fclose(fp_votes);

    printf("\n");
    pressEnterToContinue();
    system("cls");
    main_menu();
    return 0;
}

// Display all candidate results without threshold
int display_candidate_results()
{
    struct Candidate {
        char id[10];
        char name[50];
        char party[10];
    } cand[100];

    int candCount = 0;
    FILE *fv, *fc;
    char line[200];
    char party[10], cid[10];
    int votes, totalVotes = 0;

    // Read candidate details
    fc = fopen(CANDIDATE_FILE, "r");
    if (fc == NULL) {
        color(0x0c);
        printf(" Error: Cannot open candidates file!\n");
        color(0x07);
        pressEnterToContinue();
        system("cls");
        main_menu();
        return 1;
    }

    while (fgets(line, sizeof(line), fc)) {
        sscanf(line, "%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^\n]",
               cand[candCount].id, cand[candCount].name, cand[candCount].party,
               NULL, NULL, NULL, NULL, NULL);
        candCount++;
    }
    fclose(fc);

    // First pass: calculate total votes
    fv = fopen("../data/candidate_votes.txt", "r");
    if (fv == NULL) {
        color(0x0c);
        printf(" Error: Cannot open candidate votes file!\n");
        color(0x07);
        pressEnterToContinue();
        system("cls");
        main_menu();
        return 1;
    }

    while (fscanf(fv, "%[^|]|%[^|]|%d\n", party, cid, &votes) == 3) {
        totalVotes += votes;
    }
    fclose(fv);

    // Second pass: display all candidates
    system("cls");
    E_seperator();
    printf("\t  ELECTION RESULTS 2025 - CANDIDATE VOTES\n");
    E_seperator();

    fv = fopen("../data/candidate_votes.txt", "r");

    printf("\n %-10s | %-25s | %-10s | %-12s\n", "Party", "Candidate Name", "Votes", "Percentage");
    printf(" %-10s | %-25s | %-10s | %-12s\n", 
           "----------", "-------------------------", "----------", "----------");

    int totalCandidates = 0;

    while (fscanf(fv, "%[^|]|%[^|]|%d\n", party, cid, &votes) == 3) {
        float percentage = totalVotes > 0 ? (votes * 100.0) / totalVotes : 0;

        for (int i = 0; i < candCount; i++) {
            if (strcmp(cid, cand[i].id) == 0) {
                printf(" %-10s | %-25s | %-10d | %.2f%%\n", 
                       party, cand[i].name, votes, percentage);
                totalCandidates++;
                break;
            }
        }
    }

    fclose(fv);

    printf("\n");
    E_seperator();
    color(0x0b);
    printf(" TOTAL CANDIDATES: %d | TOTAL VOTES: %d\n", totalCandidates, totalVotes);
    color(0x07);
    E_seperator();

    printf("\n");
    pressEnterToContinue();
    system("cls");
    main_menu();
    return 0;
}

// Display seat allocation based on party votes and available seats - District Wise
int display_seat_allocation()
{
    struct PartySeats {
        char partyID[10];
        char partyName[100];
        int votes;
    } parties[50];

    struct District {
        char districtID[10];
        char districtName[100];
        int availableSeats;
    } districts[50];

    FILE *fp_party, *fp_votes, *fp_district;
    char partyID[10], partyName[100], vpartyID[10], cvotes[10];
    int votes;
    int partyCount = 0, districtCount = 0;
    int totalVotes = 0, totalSeats = 0;

    system("cls");

    // Read districts and available seats
    fp_district = fopen(DISTRICT_FILE, "r");
    if (fp_district == NULL) {
        color(0x0c);
        printf(" Error: Cannot open district file!\n");
        color(0x07);
        pressEnterToContinue();
        system("cls");
        main_menu();
        return 1;
    }

    while (fscanf(fp_district, "%[^|]|%[^|]|%d\n", 
                  districts[districtCount].districtID, 
                  districts[districtCount].districtName, 
                  &districts[districtCount].availableSeats) == 3) {
        totalSeats += districts[districtCount].availableSeats;
        districtCount++;
    }
    fclose(fp_district);

    // Read party votes
    fp_party = fopen(PARTY_FILE, "r");
    fp_votes = fopen("../data/party_votes.txt", "r");

    if (fp_party == NULL || fp_votes == NULL) {
        color(0x0c);
        printf(" Error: Cannot open files!\n");
        color(0x07);
        pressEnterToContinue();
        system("cls");
        main_menu();
        return 1;
    }

    // Calculate total votes
    while (fscanf(fp_votes, "%[^|]|%[^\n]\n", vpartyID, cvotes) == 2) {
        totalVotes += atoi(cvotes);
    }
    fclose(fp_votes);

    // Read party details
    fp_votes = fopen("../data/party_votes.txt", "r");
    rewind(fp_party);

    while (fscanf(fp_party, "%[^|]|%[^\n]\n", partyID, partyName) == 2) {
        rewind(fp_votes);
        
        while (fscanf(fp_votes, "%[^|]|%[^\n]\n", vpartyID, cvotes) == 2) {
            if (strcmp(partyID, vpartyID) == 0) {
                votes = atoi(cvotes);
                
                strcpy(parties[partyCount].partyID, partyID);
                strcpy(parties[partyCount].partyName, partyName);
                parties[partyCount].votes = votes;
                
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

    int totalAllocatedAll = 0;

    // For each district
    for (int d = 0; d < districtCount; d++) {
        printf("\n");
        D_seperator();
        color(0x0e);
        printf(" DISTRICT: %s (%s) - Available Seats: %d\n", 
               districts[d].districtName, districts[d].districtID, districts[d].availableSeats);
        color(0x07);
        D_seperator();

        printf("\n %-10s | %-25s | %-10s | %-15s\n", 
               "Party ID", "Party Name", "Votes", "Allocated Seats");
        printf(" %-10s | %-25s | %-10s | %-15s\n", 
               "----------", "-------------------------", "----------", "---------------");

        int districtAllocated = 0;

        // Allocate seats for each party in this district
        for (int p = 0; p < partyCount; p++) {
            int seatsForParty = (parties[p].votes * districts[d].availableSeats) / totalVotes;
            printf(" %-10s | %-25s | %-10d | %-15d\n", 
                   parties[p].partyID, parties[p].partyName, 
                   parties[p].votes, seatsForParty);
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
    main_menu();
    return 0;
}

