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

// admin panel
int admin_panel()
{
    E_seperator();
    printf("\tADMIN CONTROL PANEL 2025\n");
    E_seperator();


    printf(" Polling Status: ");
    FILE *fp = fopen(presiding_file, "r");
    if (fp == NULL) {
        printf("Error opening file for presiding officers!\n");
        exit(1);
    }
    color(0x0a); // Green color for "Open"
    char status[10];
    fgets(status, sizeof(status), fp);
    fclose(fp);
    if (status[0] != '1' && status[0] != '0') {
        printf("Unknown\n");
    } else if ( status[0] == '1') {
        color(0x0a); // Green color for "Open"
        printf("Open\n");
    } else {
        color(0x0c); // Red color for "Closed"
        printf("Closed\n");
        
    }
    color(0x07); // Reset to default color
    D_seperator();
    
    printf("\n [1] Returning Officer (RO) \n");
    printf(" [2] Election Admin \n");
    printf(" [3] Presiding Officer (PO) \n");
    printf(" [4] Party Agent / Observer \n");
    printf(" [0] Back to Main Menu \n");

    D_seperator();
    printf(" Enter your choice: ");

    int choice;
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        system("cls");
        admin_loging("RETURNING"); // Call RO login
        break;
    case 2:
        system("cls");
        admin_loging("ELECTION"); // Call Election Admin panel
        break;
    case 3:
        system("cls");
        admin_loging("PRESIDING"); // Call PO panel
        break;
    case 4:
        system("cls");
        admin_loging("PARTY_ADMIN"); // Call Party Agent/Observer panel
        break;
    case 0:
        system("cls");
        main_menu(); // Return to main menu
        return 0;
    default:
        printf("Invalid choice. Please try again.\n");
        time_delay();
        system("cls");
        admin_panel();
        break;
    }

    return 0; // Return to admin panel
}

 