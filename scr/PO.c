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


// Presiding Officer (PO) panel
int UI_PO()
{
    E_seperator();
    printf("\tPRESIDING OFFICER PANEL\n");
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
  

    printf("\n [1] Open Polling \n");
    printf(" [2] Close Polling \n");
    printf(" [0] Back to Admin Control Panel \n");
    D_seperator();
    printf(" Enter your choice: ");
    
    int choice;
    scanf("%d", &choice);
    D_seperator();

    switch (choice)
    {
    case 1:
        system("cls");
        PO_open_polling();
        break;
    case 2:
        system("cls");
        PO_close_polling();
        break;
    case 0:
        system("cls");
        admin_panel(); 
        return 0;
    default:
        printf("Invalid choice. Please try again.\n");
        time_delay();
        system("cls");
        UI_PO();
        break;
    }

    return 0;
}

// PO functions
int PO_open_polling()
{
    E_seperator();
    printf("\tOPEN POLLING\n");
    E_seperator();
    printf(" Polling Status: ");
    FILE *fp1 = fopen(presiding_file, "r");
    if (fp1 == NULL) {
        printf("Error opening file for presiding officers!\n");
        exit(1);
    }
    color(0x0a); // Green color for "Open"
    char status[10];
    fgets(status, sizeof(status), fp1);
    fclose(fp1);
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
    
    printf("\n Confirm action: Do you want to OPEN polling? \n");
    
    printf("\n [1] Yes Open Polling \n");
    printf(" [0] No Cancel and Return \n");

    D_seperator();
    printf(" Enter your choice: ");

    int choice;
    scanf("%d", &choice);
    FILE *fp = fopen(presiding_file, "w");
    if (fp == NULL) {
        printf("Error opening file for presiding officers!\n");
        exit(1);
    }
    switch (choice)
    {
    case 1:
        fprintf(fp, "1\n");
        fclose(fp);
        time_delay();
        system("cls");
        UI_PO();        
        break;
    case 0:
        if (status[0] != '1' && status[0] != '0') {
            fprintf(fp,"Unknown\n");
            
        } else if ( status[0] == '1') {
            fprintf(fp,"1\n");
        } else {
            fprintf(fp,"0\n");
            
        }
        fclose(fp);
        system("cls");
        UI_PO(); // Return to PO panel
        return 0;
    default:
        printf("Invalid choice. Please try again.\n");
        time_delay();
        system("cls");
        PO_open_polling();
        break;
    }

    return 0;
}

int PO_close_polling()
{
    E_seperator();
    printf("\t\tCLOSE POLLING\n");
    E_seperator();

    printf(" Polling Status: ");
    FILE *fp1 = fopen(presiding_file, "r");
    if (fp1 == NULL) {
        printf("Error opening file for presiding officers!\n");
        exit(1);
    }
    color(0x0a); // Green color for "Open"
    char status[10];
    fgets(status, sizeof(status), fp1);
    fclose(fp1);
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
    
    printf("\n Confirm action: Do you want to CLOSE polling? \n");

    printf("\n [1] Yes Close Polling \n");
    printf(" [0] No  Cancel and Return \n");

    D_seperator();
    printf(" Enter your choice: ");

    int choice;
    scanf("%d", &choice);
    FILE *fp = fopen(presiding_file, "w");
    if (fp == NULL) {
        printf("Error opening file for presiding officers!\n");
        exit(1);
    }
    switch (choice)
    {
    case 1:
        fprintf(fp, "0\n");
        fclose(fp);
        time_delay();
        system("cls");
        UI_PO(); 
        break;
    case 0:
        if (status[0] != '1' && status[0] != '0') {
            fprintf(fp,"Unknown\n");
            
        } else if ( status[0] == '1') {
            fprintf(fp,"1\n");
        } else {
            fprintf(fp,"0\n");
            
        }
        fclose(fp);
        system("cls");
        UI_PO();
        return 0;
    default:
        printf("Invalid choice. Please try again.\n");
        time_delay();
        system("cls");
        PO_close_polling();
        break;
    }

    return 0;
}