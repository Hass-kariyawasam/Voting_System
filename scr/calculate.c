#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "custom.h" //cuserm file

#define MAX_PARTIES 100
#define LINE_SIZE 256
#define MAX_PARTIES 100
#define MAX_CANDIDATES 1000
#define PARTY_VORTS_FILE "../data/party_votes.txt"
#define POLLLING_FILE "../data/pooling.txt"
#define POLING_FILE "../data/pooling.txt"
#define CANDIDATE_VOTES_FILE "../data/candidate_votes.txt"

int party_calculate() {
    FILE *fp_out1 = fopen(PARTY_VORTS_FILE, "w"); //erraas all data
    fprintf(fp_out1,"");
    fclose(fp_out1);

    FILE *fp_poll = fopen(POLLLING_FILE, "r");
    FILE *fp_votes = fopen(PARTY_VORTS_FILE, "r");

    if (fp_poll == NULL || fp_votes == NULL) {
        printf(" [System] Error opening files.\n");
        return 1;
    }

    char party_codes[MAX_PARTIES][10];
    int party_votes[MAX_PARTIES];
    int party_count = 0;

    
    char line[256];
    while (fgets(line, sizeof(line), fp_votes)) {

        char *token = strtok(line, "|");
        
        if (token == NULL) continue;
        strcpy(party_codes[party_count], token);

        token = strtok(NULL, "|");
        if (token == NULL) continue; //
        party_votes[party_count] = atoi(token); //

        party_count++;
    }
    fclose(fp_votes); 

    
    while (fgets(line, sizeof(line), fp_poll)) {
        char *token = strtok(line, "|"); // skip district
        token = strtok(NULL, "|");       // party code
        if (token == NULL) continue;

        char current_party[10];
        strcpy(current_party, token);

        // Read 3 candidates
        char *ca1 = strtok(NULL, "|");
        char *ca2 = strtok(NULL, "|");
        char *ca3 = strtok(NULL, "|");

        int valid = 0;
        if (ca1 && strcmp(ca1, "-") != 0){
            valid++;
        }
        if (ca2 && strcmp(ca2, "-") != 0){ 
            valid++;
        }
        if (ca3 && strcmp(ca3, "-") != 0){
            valid++;
        }

        
        int found = 0;
        for (int i = 0; i < party_count; i++) {
            if (strcmp(party_codes[i], current_party) == 0) {
                party_votes[i] += valid;
                found = 1;
                break;
            }
        }

        // If not found, add new party
        if (!found && party_count < MAX_PARTIES) {
            strcpy(party_codes[party_count], current_party);
            party_votes[party_count] = valid;
            party_count++;
        }
    }
    fclose(fp_poll); // Done reading polling

    // --- Write updated votes ---
    FILE *fp_out = fopen(PARTY_VORTS_FILE, "w");
    if (fp_out == NULL) {
        printf(" [System] Error writing file.\n");
        return 1;
    }

    for (int i = 0; i < party_count; i++) {
        fprintf(fp_out, "%s|%d|\n", party_codes[i], party_votes[i]);
    }
    fclose(fp_out);

    color(0x0a);
    printf(" [System] Updated party votes saved.\n\n");
    color(0x07);
    pressEnterToContinue();
    A_delay();
    system("cls");
    UI_returning_officer();

}
int candidate_calculate() {
    // --- Step 1: Clear old data ---
    FILE *fp_out1 = fopen(CANDIDATE_VOTES_FILE, "w");
    if (fp_out1 == NULL) {
        printf(" [System] Error clearing candidate votes file.\n");
        return 1;
    }
    fprintf(fp_out1, "");
    fclose(fp_out1);

    // --- Step 2: Open polling file ---
    FILE *fp_poll = fopen(POLLLING_FILE, "r");
    if (fp_poll == NULL) {
        printf(" [System] Error opening polling file.\n");
        return 1;
    }

    // --- Step 3: Data structures ---
    char party_codes[MAX_CANDIDATES][10];
    char candidate_numbers[MAX_CANDIDATES][10];
    int candidate_votes[MAX_CANDIDATES];
    int candidate_count = 0;

    char line[256];

    // --- Step 4: Process each line of polling.txt ---
    while (fgets(line, sizeof(line), fp_poll)) {
        char *token = strtok(line, "|"); // skip district (D001)
        if (token == NULL) continue;

        token = strtok(NULL, "|"); // party code (P001)
        if (token == NULL) continue;
        char current_party[10];
        strcpy(current_party, token);

        // Read next 3 candidate numbers
        char *ca1 = strtok(NULL, "|");
        char *ca2 = strtok(NULL, "|");
        char *ca3 = strtok(NULL, "|");

        // Store in an array for easy looping
        char *candidates[3] = {ca1, ca2, ca3};

        // --- Step 5: Count votes for each candidate ---
        for (int j = 0; j < 3; j++) {
            if (candidates[j] && strcmp(candidates[j], "-") != 0) {
                char current_candidate[10];
                strcpy(current_candidate, candidates[j]);

                int found = 0;
                for (int i = 0; i < candidate_count; i++) {
                    if (strcmp(party_codes[i], current_party) == 0 &&
                        strcmp(candidate_numbers[i], current_candidate) == 0) {
                        candidate_votes[i]++;
                        found = 1;
                        break;
                    }
                }

                // If not found, add new entry
                if (!found && candidate_count < MAX_CANDIDATES) {
                    strcpy(party_codes[candidate_count], current_party);
                    strcpy(candidate_numbers[candidate_count], current_candidate);
                    candidate_votes[candidate_count] = 1;
                    candidate_count++;
                }
            }
        }
    }
    fclose(fp_poll);

    // --- Step 6: Write candidate votes file ---
    FILE *fp_out = fopen(CANDIDATE_VOTES_FILE, "w");
    if (fp_out == NULL) {
        printf(" [System] Error writing candidate votes file.\n");
        return 1;
    }

    for (int i = 0; i < candidate_count; i++) {
        fprintf(fp_out, "%s|%s|%d|\n",
                party_codes[i],
                candidate_numbers[i],
                candidate_votes[i]);
    }
    fclose(fp_out);

    // --- Step 7: System output (same style as your code) ---
    color(0x0a);
    printf(" [System] Updated candidate votes saved.\n\n");
    color(0x07);
    pressEnterToContinue();
    A_delay();
    system("cls");
    UI_returning_officer();

    return 0;
}