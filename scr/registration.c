#include <stdio.h>
#include <string.h>
#include <stdlib.h> //screen clear
#include "custom.h"
#define voter_file "../data/voters.txt"
#define candidate_file "../data/candidates.txt"
int main(); 

void voter_registration() {
    char nic[20];
    char Name[100];
    int age;
    char citizenship;
    char password[50], confirmPassword[50];
    char districtCode[10];

    char errornic[50] = ""; 
    char errorage[50] = ""; 
    char errorcitiy[50] = "";
    char errorpass[50] = "";  


    E_seperator();
    printf("\tVOTER REGISTRATION\n");
    E_seperator();
    
    // NIC
    printf("\n Enter NIC Number\t: ");
    scanf("%19s", nic);

    if (strlen(nic) != 12) {
        strcpy(errornic, "[Error] NIC must be exactly 12 digits!");
        
    }
    FILE *file = fopen(voter_file, "r");
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
    } else {
        printf("Error opening file for reading!\n");
        exit(1);
    }
  
    // Full Name
    printf(" Enter Full Name\t: ");
    scanf("%99s", Name);   
    
    

    // Age
    printf(" Enter Age\t\t: ");
    scanf("%d", &age);
    if (age < 18) {
        strcpy(errorage,"[Error] Age must be 18 or older!");
        
       
    }

   // Citizenship
    printf(" Citizenship (Y/N)\t: ");
    scanf(" %c", &citizenship);

    if (citizenship == 'y' || citizenship == 'Y') {
        // ok
    } else {
       
        strcpy(errorcitiy,"[Error] Citizenship must be 'Y' to register!");
        
    }

    D_seperator();
    // Password
    printf(" Create Password\t: ");
    scanf("%49s", password);

    printf(" Confirm Password\t: ");
    scanf("%49s", confirmPassword);

    if (strcmp(password, confirmPassword) != 0) {
       
        strcat(errorpass, "[Error] Passwords do not match!");
        
    }
    D_seperator();
    // District Code
    printf(" Enter District Code\t: ");
    scanf("%9s", districtCode);

    FILE *fp = fopen(voter_file, "a");
    if (fp == NULL) {
        printf(" Error opening file for voters!\n");
        exit(1);
    }
    D_seperator();
    color(0x0c); //RED
    //error handling
    if (strlen(errornic) != 0 || strlen(errorage) != 0 || strlen(errorcitiy) != 0 || strlen(errorpass) != 0){
        // There are errors
       
        if (strlen(errornic) != 0) {
            printf("%s\n",errornic);
        }
        if (strlen(errorage) != 0) {
            printf("%s\n",errorage);
        }
        if (strlen(errorcitiy) != 0) {
            printf("%s\n",errorcitiy);
        }
        if (strlen(errorpass) != 0) {
            printf("%s\n",errorpass);
        }
        color(0x07); //RESET
        printf("-------------------------------------------------\n");
        printf("Registration failed due to above errors.\n");
        printf("Please try again.\n");
        printf("Redirecting to Main Menu...\n");
        
        pressEnterToContinue();
        time_delay();   
        system("cls");
        main_menu();
    }
    else{
         color(0x07); //RESET
    
    fprintf(fp, "%s|%s|%d|%c|%s|%s\n", nic, Name, age, citizenship, password, districtCode);
    fclose(fp);


    
    // Final success
    printf("-------------------------------------------------\n");
    printf("[System] Saving voter record...\n");
    printf("[System] Registration successful!\n");
    printf("-------------------------------------------------\n");
    printf("Redirecting to Main Menu...\n");
    
    pressEnterToContinue();
    time_delay();
    system("cls");
    
    main_menu();
    }
}

void candidate_registration(){

    E_seperator();
    printf("\tCANDIDATE REGISTRATION\n");
    E_seperator();
    
    char nic[20], Name[100], districtCode[10], password[50], confirmPassword[50], partyCode[10];
    char citizenship;
    int age;
    int nextID = 1;   // default if file empty
   
    
    char errornic[50] = ""; 
    char errorage[50] = ""; 
    char errorcitiy[50] = "";
    char errorpass[50] = "";  

    // ---------- NIC ----------
    printf(" Enter NIC Number\t: ");
    scanf("%19s", nic);
    if (strlen(nic) != 12) {
        strcpy(errornic, "[Error] NIC must be exactly 12 digits!");
    }

    // ---------- Find nextID and check duplicate NIC ----------
    FILE *file = fopen(candidate_file, "r");
    if (file != NULL) {
        char line[256];
        int currentID;
        char existingNIC[20];

        while (fgets(line, sizeof(line), file)) {
            // Read ID and NIC from the line
            if (sscanf(line, "%d|%19[^|]", &currentID, existingNIC) == 2) {
                if (currentID >= nextID)
                    nextID = currentID + 1;        // track highest ID
                if (strcmp(existingNIC, nic) == 0)
                    strcpy(errornic, "[Error] NIC already registered!");
            }
        }
        fclose(file);
    }
    // Full Name
    printf(" Enter Full Name\t: ");
    scanf(" %99[^\n]", Name);    // allow spaces
    
    

    // Age
    printf(" Enter Age\t\t: ");
    scanf("%d", &age);
    if (age < 18) {
        strcpy(errorage, "[Error] Age must be 18 or older!");
        
    }

   // Citizenship
    printf(" Citizenship (Y/N)\t: ");
    scanf(" %c", &citizenship);

    if (citizenship == 'y' || citizenship == 'Y') {
        // ok
    } else {
       
        strcpy(errorcitiy, "[Error] Citizenship must be 'Y' to register!");
        
    }

    D_seperator();
    // Password
    printf(" Create Password\t: ");
    scanf("%49s", password);

    printf(" Confirm Password\t: ");
    scanf("%49s", confirmPassword);

    if (strcmp(password, confirmPassword) != 0) {
       
        strcat(errorpass, "[Error] Passwords do not match!");
        
    }
    D_seperator();

     // ---------- District & Party ----------
    printf(" Enter District Code\t: ");
    scanf("%9s", districtCode);
    printf(" Enter Party Code\t: ");
    scanf("%9s", partyCode);


    D_seperator();

    color(0x0c); //RED
    //error handling
    if (strlen(errornic) != 0 || strlen(errorage) != 0 || strlen(errorcitiy) != 0 || strlen(errorpass) != 0){
        // There are errors
       
        if (strlen(errornic) != 0) {
            printf("%s\n", errornic);
        }
        if (strlen(errorage) != 0) {
            printf("%s\n", errorage);
        }
        if (strlen(errorcitiy) != 0) {
            printf("%s\n", errorcitiy);
        }
        if (strlen(errorpass) != 0) {
            printf("%s\n", errorpass);
        }
        color(0x07); //RESET
        D_seperator();
        printf("Registration failed due to above errors.\n");
        printf("Please try again.\n");
        printf("Redirecting to Main Menu...\n");
        
        pressEnterToContinue();
        time_delay();   
        system("cls");
        main_menu();
    }
    else{
    color(0x07); //RESET    
        
    // ---------- Save to file ----------
    FILE *fp = fopen(candidate_file, "a");
    if (!fp) { perror("File error"); exit(1); }

    fprintf(fp, "%d|%s|%s|%d|%c|%s|%s|%s\n",
            nextID, nic, Name, age, citizenship,
            password, districtCode, partyCode);
    fclose(fp);

    // Final success
    D_seperator();
    printf("[System] Saving candidate record...\n");
    printf("[System] Registration successful!\n");
    D_seperator();
    printf("Redirecting to Main Menu...\n");
    
    pressEnterToContinue();
    time_delay();
    system("cls");
    
    main_menu();
    }
}