#include <stdio.h>
#include <string.h>
#include <stdlib.h> //screen clear.
#include <windows.h> 
#include "custom.h"

//file handling declarations
#define DISTRICT_FILE "../data/districts.txt"
#define PARTY_FILE "../data/parties.txt"
#define presiding_file "../admin/presiding_officers.txt"


int UI_returning_officer(){
    E_seperator();
    printf("\tRETURNING OFFICER (RO) CONTROL PANEL\n");
    E_seperator();

   
    printf(" [1] Candidate Calculate  \n");
    printf(" [2] Party Resalt Generation \n");
    printf(" [0] Back to Admin Panel \n");

    D_seperator();
    printf("Enter your choice: ");
    int choice;
    scanf("%d", &choice);

    switch (choice){
    
    case 1:
        system("cls");
        candidate_calculate();
        break;
    case 2:
        system("cls");
        printf(" Calculateing....\n");
        party_calculate();

        break;
  
    case 0:
        system("cls");
        admin_panel(); 
        return 0;
    default:
        
        printf("Invalid choice. Please try again.\n");
        time_delay();
        system("cls");
        UI_returning_officer();
        break;
    }

    return 0; // Return to RO panel
}

