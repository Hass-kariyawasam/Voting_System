#include <stdio.h>
#include <string.h>
#include <stdlib.h> //screen clear.
#include <windows.h> 
#include "custom.h"

//file handling declarations
#define DISTRICT_FILE "../data/districts.txt"
#define PARTY_FILE "../data/parties.txt"
#define presiding_file "../admin/presiding_officers.txt"
int main(); 


//Election Admin panel
int UI_election_admin(){
    E_seperator();
    printf("\tELECTION ADDMIN PANNEL\n");
    E_seperator();

    printf("\n [1] District Registration \n");
    printf(" [2] Party Registration \n");
   
    printf(" [0] Back to Admin Control Panel\n");

    D_seperator();

    printf("Enter your choice: ");
    int choice;

    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        system("cls");
        district_registration();
        break;

    case 2:
        system("cls");
        party_registration();
        break;
   
    case 0:
        
        system("cls");

        admin_panel();
        break;
    }
}



 int district_registration(){
    E_seperator();
    printf("\t\tDistrict Registration\n");
    E_seperator();

    printf("\n [1] Add New District \n");
    printf(" [2] Display All Districts \n");
    printf(" [0] Back to Election Admin Panel \n");

    D_seperator();
    printf("Enter your choice: ");
    int choice;
    scanf("%d",&choice);

        switch (choice){
            case 1:
                system("cls");
               add_new_district();
                break;
            case 2:
                system("cls");
               display_all_districts();
                break;
            case 0:
                system("cls");
                UI_election_admin();
            
            default:
            printf("Invalid choice. Please try again.\n");
            break;

        }
    return 0;
 }
char add_district() {

    char district_name[20];
    char district_code[10];
    char district_seat[10];
    char add_more;

    printf("Enter District Name\t: ");
    scanf("%s", district_name);
    printf("Enter District Code\t: ");
    scanf("%s", district_code);
    printf("Enter number of seats\t: ");
    scanf("%s", district_seat);

    FILE *fp = fopen(DISTRICT_FILE, "a"); 
    if (fp == NULL) {
        printf("Error opening file for districts!\n");
        exit(1);
    }

    fprintf(fp, "%s|%s|%s\n", district_code, district_name, district_seat);
    fclose(fp);

    printf("-------------------------------------------------\n");
    printf("[System] New district '%s' with code '%s' added successfully!\n", district_name, district_code);
    printf("Add another district? (Y/N): ");
    scanf(" %c", &add_more);
    return add_more;
}

 int add_new_district(){
    E_seperator();
    printf("\t\tAdd New District\n");
    E_seperator();

    char add_more;

    do {
        add_more = add_district();
        
    } while (add_more == 'Y' || add_more == 'y');

   
    
    D_seperator();

    system("cls");
    time_delay();
    pressEnterToContinue();
    district_registration();
 
 }

 int display_all_districts(){
    E_seperator();
    printf("\t\tAll Registered Districts\n");
    E_seperator();

    printf("\n  Code\t| Name\t\t| Seats\n");
    printf("---------------------------------------\n");


    FILE *fp = fopen(DISTRICT_FILE, "r");
    if (fp == NULL) {
        printf("Error opening file for districts!\n");
        exit(1);
    }

    char line[200];
    while (fgets(line, sizeof(line), fp)) {
        char *token = strtok(line, "|");
        if (token != NULL) {
            printf("  %s\t", token); // District Code
            token = strtok(NULL, "|");
        }
        if (token != NULL) {
            printf("| %-9s\t", token); // District Name
            token = strtok(NULL, "|");
        }
        if (token != NULL) {
            printf("| %s", token); // Number of Seats
        }
        
    }
    fclose(fp);
   printf("---------------------------------------\n");
    
    pressEnterToContinue();
    system("cls");
    district_registration();


 }      

char add_party(){

    char party_name[20];
    char party_code[10];
    char add_more;

    printf("Enter Party Name\t: ");
    scanf("%s", party_name);
    printf("Enter Party Code\t: ");
    scanf("%s", party_code);
   

    FILE *fp = fopen(PARTY_FILE, "a"); 
    if (fp == NULL) {
        printf("Error opening file for party!\n");
        exit(1);
    }

    fprintf(fp, "%s|%s\n", party_code, party_name);
    fclose(fp);

    printf("-------------------------------------------------\n");
    printf("[System] New party '%s' with code '%s' added successfully!\n", party_name, party_code);
    printf("Add another party? (Y/N): ");
    scanf(" %c", &add_more);
    return add_more;
}

int party_registration(){
    E_seperator();
    printf("\t\tParty Registration\n");
    E_seperator();

    char add_more;

    do {
        add_more = add_party();
        
    } while (add_more == 'Y' || add_more == 'y');



        printf("-------------------------------------------------\n");
        printf(" Options: \n");
        printf(" [0] Back to Election Admin Menu \n");
    printf("-------------------------------------------------\n");

     printf("Enter your choice: ");
    int choice;
    scanf("%d",&choice);

        switch (choice){
            
            case 0:
                system("cls");
                UI_election_admin();
            
            default:
            printf("Invalid choice. Please try again.\n");
            printf("Redirecting to Party Registration Menu...\n");
           
            system("cls");
            time_delay();
            pressEnterToContinue();
            party_registration();
            break;

        }
    
    return 0;

}
int display_registerd_parties(){
    E_seperator();
    printf("\t\tAll Registered Parties\n");
    E_seperator();
    printf("-------------------------------------------------\n");

    //need to add registered parties from database
return 0;  
}   

