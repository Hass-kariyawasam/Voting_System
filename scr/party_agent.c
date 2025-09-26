#include <stdio.h>
#include <string.h>
#include <stdlib.h> //screen clear.
#include <windows.h> 
#include "custom.h"

//file handling declarations
#define P_NOMINATION_FILE "../data/nomination_list/P_nomination.txt"
#define PARTY_FILE "../data/parties.txt"
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
    char party_code[20];
    
    printf("\n Registerd Partys");
    color(0x06);
    printf("\n  Code\t| Name\n");
    printf("--------------------\n");
    FILE *fp = fopen(PARTY_FILE, "r");
    if (fp == NULL) {
        printf("Error opening file for districts!\n");
        exit(1);
    }
    
    char line[200];
    while (fgets(line, sizeof(line), fp)) {
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
    fclose(fp);
    color(0x07);
    int code;
    char nic[20];
    char Name[100];
    int age;
    char districtCode[10];
    char errornic[50] = ""; 
    char errorage[50] = "";
    

    printf("\n Enter party code\t: ");
    scanf("%d", &code);
    
    printf(" Enter District Code\t: ");
    scanf("%9s", districtCode);
    D_seperator();
    printf(" Enter Canditade Data\n");
    D_seperator();
    printf(" Enter NIC Number\t: ");
    scanf("%19s", nic);

    if (strlen(nic) != 12) {
        strcpy(errornic, "[Error] NIC must be exactly 12 digits!");
        
    }
     FILE *file = fopen(P_NOMINATION_FILE, "r");
    if (file != NULL) {
        char line[256];
        while (fgets(line, sizeof(line), file)) {
            char existingNIC[20];
            sscanf(line, "%19[^|]", existingNIC);
            if (strcmp(existingNIC, nic) == 0) {
                strcpy(errornic, "[Error] NIC already registered!");
                break;
            }
        }
        fclose(file);
    }

    // Full Name
    printf(" Enter Full Name\t: ");
    scanf("%99s", Name);   // will stop at first space

    // Age
    printf(" Enter Age\t\t: ");
    scanf("%d", &age);
    if (age < 18) {
        strcpy(errorage, "[Error] Age must be 18 or older!");
        
    }
    //-----------------------------------------------------------------------------
    D_seperator();
    color(0x0c); //RED
    //error handling
    if (strlen(errornic) != 0 || strlen(errorage) != 0){
        // There are errors
       
        if (strlen(errornic) != 0) {
            printf("%s\n", errornic);
        }
        if (strlen(errorage) != 0) {
            printf("%s\n", errorage);
        }
        
        color(0x07); //RESET
        D_seperator();
        printf("Registration failed due to above errors.\n");
        printf("Please try again.\n");
        printf("Redirecting to Main Menu...\n");
        
        pressEnterToContinue();
        time_delay();   
        system("cls");
        UI_party_admin();
    }
    else{
    color(0x07); //RESET
    FILE *fp = fopen(P_NOMINATION_FILE, "a");
    if (fp == NULL) {
        printf("Error opening file for candidates!\n");
        exit(1);
    }   

    fprintf(fp, "%s|%s|%d|%s|\n", nic, Name, age, districtCode);
    fclose(fp);
    // Final success
    
    color(0x0a);
    printf("[System] Saving candidate record...\n");
    printf("[System] Registration successful!\n");
    color(0x07); //RESET
    D_seperator();
    printf("Redirecting to Main Menu...\n");
    
    pressEnterToContinue();
    time_delay();
    system("cls");
    
    UI_party_admin();
    }

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
