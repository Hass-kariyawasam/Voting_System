#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PARTIES 100
#define LINE_SIZE 256

int main() {
    FILE *fp_out1 = fopen("party_votes.txt", "w"); //erraas all data
    fprintf(fp_out1,"");
    fclose(fp_out1);

    FILE *fp_poll = fopen("pooling.txt", "r");
    FILE *fp_votes = fopen("party_votes.txt", "r");

    if (fp_poll == NULL || fp_votes == NULL) {
        printf("Error opening files.\n");
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
    FILE *fp_out = fopen("party_votes.txt", "w");
    if (fp_out == NULL) {
        printf("Error writing file.\n");
        return 1;
    }

    for (int i = 0; i < party_count; i++) {
        fprintf(fp_out, "%s|%d|\n", party_codes[i], party_votes[i]);
    }
    fclose(fp_out);

    printf("Updated party votes saved.\n");
    return 0;
}
