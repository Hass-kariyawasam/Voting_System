#include <stdio.h>
#include <string.h>
#include <stdlib.h> //screen clear.
#include <windows.h> 
#include "custom.h"

//file handling declarations
#define PARTY_FILE "../data/parties.txt"
#define DISTRICT_FILE "../data/districts.txt"
int main(); 



int UI_party_admin()
{
    E_seperator();
    printf("\tPARTY ADMIN PANEL\n");
    E_seperator();

    int choice;
    printf("\n [1] SUBMIT NOMINATION LISTt\n");
    printf(" [0] Logout\n");
    D_seperator();

    printf(" Enter your choice: ");
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
    printf("\tSUBMIT NOMINATION LIST\n");
    E_seperator();

    char pcode[20];
    
    printf("\n Registerd Partys");
    color(0x06);
    printf("\n  Code\t| Name\n");
    printf("--------------------\n");
    FILE *fp = fopen(PARTY_FILE, "r");
    if (fp == NULL) {
        printf(" Error opening file for districts!\n");
        exit(1);
    }
    
    char line[200];
    while (fgets(line, sizeof(line), fp)) {
        char *token = strtok(line, "|");
        if (token != NULL) {
            printf("  %s\t", token); // party Code
            strcpy(pcode, token);
            token = strtok(NULL, "-");
        }
        if (token != NULL) {
            printf("| %s", token); //  Name
            
        }
    
        
    }
    fclose(fp);

    color(0x07); //nomal color
    char party_code[50];
    char districtCode[10];
    char error_partycode[50] = "";
    char error_discode[50] = "";



    printf("\n Enter party code\t: ");
    scanf("%s", party_code);

    // file location creat 
    char location[100];
    sprintf(location, "../data/nomination_list/PA_%s_nomination.txt", party_code);
    #define P_NOMINATION_FILE location

    // check entered party code exists
    FILE *file = fopen(PARTY_FILE, "r");
    if (file != NULL) {
        char line[256];
        int found = 0;  // flag to check if party code exists
        
        while (fgets(line, sizeof(line), file)) {
            char existingpartycode[20];
            sscanf(line, "%10[^|]", existingpartycode);
            
            if (strcmp(existingpartycode, party_code) == 0) {
                found = 1;  
                break;     
            }
        }
        fclose(file);
        
       
        if (!found) {
            strcpy(error_partycode, " [Error] Entered party code is not registered!");
        }
    }

    printf(" Enter District Code\t: ");
    scanf("%9s", districtCode);

    // check disrick code all raday exxite
    FILE *fp1 = fopen(DISTRICT_FILE, "r");  
    if (fp1 != NULL) {
        char line[256];
        int found_district = 0;  
        
        while (fgets(line, sizeof(line), fp1)) {
            char existingdiscode[20];
            sscanf(line, "%[^|]", existingdiscode);
            
            if (strcmp(existingdiscode, districtCode) == 0) {
                found_district = 1;  
                break;
            }
        }
        fclose(fp1); 
        
       
        if (!found_district) {
            strcpy(error_discode, " [Error] Entered district code is not registered!");
        }
    }

   
    if (strlen(error_partycode) != 0 || strlen(error_discode) != 0) {
        D_seperator();
        color(0x0c); 
        
        if (strlen(error_discode) != 0) {
            printf("%s\n", error_discode);
        }
        if (strlen(error_partycode) != 0) {
            printf("%s\n", error_partycode);
        }
        
        color(0x07); 
        D_seperator();
        printf(" Registration failed due to above errors.\n");
        printf(" Please try again.\n");
        printf(" Redirecting to Main Menu...\n");
        
        pressEnterToContinue();
        time_delay();   
        system("cls");
        UI_party_admin();
        return 0;
    }

  
    char addAnother = 'Y';
    int candidateCount = 0;
    
    while (addAnother == 'Y' || addAnother == 'y') {
        char nic[20];
        char Name[100];
        int age;
        char errornic[50] = ""; 
        char errorage[50] = "";
        
        D_seperator();
        printf(" \nEnter Candidate Data (Candidate #%d)\n", candidateCount + 1);
        D_seperator();
        
        printf(" Enter NIC Number\t: ");
        scanf("%19s", nic);
        
        
        if (strlen(nic) != 12) {
            strcpy(errornic, " [Error] NIC must be exactly 12 digits!");
        }
       
        FILE *fp2 = fopen(P_NOMINATION_FILE, "r");
        if (fp2 != NULL) {
            char line[256];
            while (fgets(line, sizeof(line), fp2)) {
                char existingNIC[20];
                sscanf(line, "%19[^|]", existingNIC);
                if (strcmp(existingNIC, nic) == 0) {
                    strcpy(errornic, " [Error] NIC already registered!");
                    break;
                }
            }
            fclose(fp2);
        }

       
        printf(" Enter Full Name\t: ");
        scanf(" %99[^\n]", Name);  // Read full line including spaces

       
        printf(" Enter Age\t\t: ");
        scanf("%d", &age);
        if (age < 18) {
            strcpy(errorage, "[Error] Age must be 18 or older!");
        }
        
       
        D_seperator();
        
       
        if (strlen(errornic) != 0 || strlen(errorage) != 0) {
            color(0x0c); 
            
            if (strlen(errornic) != 0) {
                printf("%s\n", errornic);
            }
            if (strlen(errorage) != 0) {
                printf("%s\n", errorage);
            }
            
            color(0x07); 
            D_seperator();
            printf(" Candidate registration failed due to above errors.\n");
            printf(" Please try again for this candidate.\n");
            D_seperator();
        }
        else {
           
            FILE *fp3 = fopen(P_NOMINATION_FILE, "a");
            if (fp3 == NULL) {
                printf("Error opening file for candidates!\n");
                exit(1);
            }   

            fprintf(fp3, "%s|%s|%d|%s|\n", nic, Name, age, districtCode);
            fclose(fp3);
            
            candidateCount++;
            
            color(0x0a);
            printf(" [System] Saving candidate record...\n");
            printf(" [System] Candidate #%d registered successfully!\n", candidateCount);
            color(0x07);
            D_seperator();
        }
        
      
        printf(" Do you want to add another candidate? (Y/N): ");
        scanf(" %c", &addAnother);
        
        if (addAnother != 'Y' && addAnother != 'y') {
            break;
        }
    }
    
   
    D_seperator();
    color(0x0a);
    printf("\n Total candidates registered: %d\n", candidateCount);
    color(0x07);
    D_seperator();
    
    printf(" Redirecting to Party Admin Menu...\n");
    pressEnterToContinue();
    time_delay();
    system("cls");
    
    UI_party_admin();
    return 0;
}