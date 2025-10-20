
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
#define DISTRICT_FILE "../data/district.txt"


int main(); 

int poling_Asccss(){
    FILE *fp1 = fopen(presiding_file, "r");
    if (fp1 == NULL) {
        printf(" [Error] opening file for presiding officers!\n");
        exit(1);
    }
   
    char status[10];
    fgets(status, sizeof(status), fp1);
    fclose(fp1);
    if (status[0] != '1' && status[0] != '0') {
        system("cls");
        color(0x0c);
        printf("Unknown\n");
        color(0x07);
        pressEnterToContinue();
        system("cls");
        main_menu();

    } else if ( status[0] == '1') {
        system("cls");
        polling_login();
    } else {
        system("cls");
        //redireting screen
        color(0x0c);
        printf("Pooling is not open yet...\n");
        color(0x07);
        pressEnterToContinue();
        system("cls");
        main_menu();
        
        
    }

}
char polling_login()
{
    E_seperator();
    printf("\tPOLLING LOGIN PORTAL\n");
    E_seperator();

    char NIC[15];
    char password[50];

    printf("\n Enter NIC Number\t: ");
    scanf("%49s", NIC);
    printf(" Enter Password\t\t: ");
    scanf("%49s", password);
    D_seperator();
   

    A_delay();
    D_seperator();
    
    FILE *fp = fopen(voter_file, "r");
    if (fp == NULL) {
        printf("Error opening file for voters!\n");
        exit(1);
    }
    
    char line[200];
    int found = 0;  
    char name[100];
    while (fgets(line, sizeof(line), fp)) {
        char file_nic[50];
        char file_password[50];
        
        // Split the line by '|'
        char *token = strtok(line, "|");
        if (token != NULL) {
            strcpy(file_nic, token);
            token = strtok(NULL, "|"); // Get name
            strcpy(name, token);
            token = strtok(NULL, "|"); // Skip age
            token = strtok(NULL, "|"); // Skip citizenship
            token = strtok(NULL, "|"); // Get password
            if (token != NULL) {
                strcpy(file_password, token);
                // Remove newline character from password if present
                file_password[strcspn(file_password, "\n")] = 0;
                // Compare NIC and password
                if (strcmp(NIC, file_nic) == 0 && strcmp(password, file_password) == 0) {
                    found = 1; // Match found
                   
                    break;
                }
            }
        }
        
    }
    fclose(fp);
    if (found) {
        color(0x0a); //GREEN
        printf("Login successful!");
         
        printf("\nWelcome, %s! Redirecting to Vote Casting Panel...\n", name);
        color(0x07);
        D_seperator();
        pressEnterToContinue();
        system("cls");
        votting_casting(NIC);
    }
    else
    {   
        
        color(0x0c);
        printf("Invalid NIC or Password. Please try again.\n");
        color(0x07);
        D_seperator();
        pressEnterToContinue();
        time_delay();
        system("cls");
        
        main_menu();
        return 0;
    }

    return 0;
}

int votting_casting(char *logged_in_nic)
{   
   

    E_seperator();
    printf("\tVOTING CASTING PANEL\n");
    E_seperator();

    char district[10];
    char party_code[10];
    char candidate_codes1[100];
    char candidate_codes2[100];
    char candidate_codes3[100];
    char confirm;
    char error_district_code[50] = "";
    char user_NIC[55];

   
   strcpy(user_NIC, logged_in_nic);

    FILE *fpCheck = fopen(POOLING_FILE, "r");
    if (fpCheck != NULL) {
    char line_check[300];
    
    while (fgets(line_check, sizeof(line_check), fpCheck)) {
        char stored_nic[55];
        
        // Skip first 5 fields, read only the 6th field (NIC)
        // Format: district|party|cand1|cand2|cand3|NIC|
        int result = sscanf(line_check, "%*[^|]|%*[^|]|%*[^|]|%*[^|]|%*[^|]|%[^|]|", stored_nic);
        
        if (result == 1) {  // Successfully read NIC
            stored_nic[strcspn(stored_nic, "\r\n ")] = 0;  // Clean whitespace
            
            if (strcmp(user_NIC, stored_nic) == 0) {
                fclose(fpCheck);
                system("cls");
                color(0x0c);
                E_seperator();
                printf("\tALREADY VOTED!\n");
                E_seperator();
                printf("\n You have already cast your vote.\n");
                printf(" Each voter can only vote once.\n");
                color(0x07);
                D_seperator();
                pressEnterToContinue();
                system("cls");
                main_menu();
                return 0;
            }
        }
    }
    fclose(fpCheck);
}
    color(0x0a);
    printf(" [System] Lodding Your Data\n");
    time_delay();
    color(0x07);
    printf("\n");
    D_seperator();

    char line[200];
    int found = 0;  
    char name[100];
    char file_nic[50];
    char file_distric_code[50];

    FILE *fp = fopen(voter_file, "r");
    if (fp != NULL){
        
        while (fgets(line, sizeof(line), fp)) {
           

            char *token = strtok(line, "|");
            if (token != NULL) {
                strcpy(file_nic, token);
                token = strtok(NULL, "|"); // Get name
                strcpy(name, token);
                token = strtok(NULL, "|"); // Skip age
                token = strtok(NULL, "|"); // Skip citizenship
                token = strtok(NULL, "|"); // Get password
                token = strtok(NULL, "\n"); // Get districcode
                if (token != NULL) {
                    strcpy(file_distric_code, token);
                    
                    file_distric_code[strcspn(file_distric_code, "\n")] = 0;
                    
                    if (strcmp(user_NIC, file_nic) == 0) {
                        found = 1; // Match found
                    
                        break;
                    }
                }
            }
            

        }
    }
    fclose(fp);
    printf("\n NIC  is  \t\t: %s",user_NIC);
    printf("\n Name  is  \t\t: %s",name);
    printf("\n District code is  \t: %s\n",file_distric_code);
    
    D_seperator();

    printf(" Available Parties \n");
    D_seperator();

    color(0x06);
    printf("  Code\t| Name\n");
    printf("--------------------\n");
    FILE *fp1 = fopen(PARTY_FILE, "r");
    if (fp1 == NULL) {
        printf("Error opening file for districts!\n");
        exit(1);
    }
    
    char line3[200];
    while (fgets(line3, sizeof(line3), fp1)) {
        char *token = strtok(line3, "|");
        if (token != NULL) {
            printf("  %s\t", token); // party Code
            strcpy(party_code, token);
            token = strtok(NULL, "|");
        }
        if (token != NULL) {
            printf("| %s", token); //  Name
            
        }
    
       
    }
    color(0x07);
    fclose(fp1);
    D_seperator();

    printf(" Enter Party Code: ");
    scanf("%9s", party_code);
    D_seperator();

    printf(" Available Candidates in %s (District %s) \n", party_code, file_distric_code);

    color(0x06);
    printf("\n    District\t|   Party\t| Candidate\t|  Name\n");
    printf("    code\t|   code\t| Code\t\t|\n");
    printf("------------------------------------------------------\n");

    FILE *fp5 = fopen(CANDIDATE_FILE, "r");
    if (fp5 == NULL) {
        printf("Error opening file for candidates!\n");
        exit(1);
    }

    char line5[200];

    while (fgets(line5, sizeof(line5), fp5)) {
        char f_candi_code[20];
        char f_nic[50];
        char f_name[100];
        char f_age[10];
        char f_citizenship[10];
        char f_password[50];
        char f_district_code[20];
        char f_party_code[20];
        
        // Parse: CandidateCode|NIC|Name|Age|Citizenship|Password|District|Party
        sscanf(line5, "%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^\n]",
            f_candi_code, f_nic, f_name, f_age, f_citizenship, 
            f_password, f_district_code, f_party_code);
        
        // Remove trailing whitespace
        f_party_code[strcspn(f_party_code, "\r\n ")] = 0;
        f_district_code[strcspn(f_district_code, "\r\n ")] = 0;
        
        // Check if matches user's district and selected party
        if (strcmp(f_district_code, file_distric_code) == 0 && 
            strcmp(f_party_code, party_code) == 0) {
            printf("    %s\t|   %s\t\t|    %s\t\t|  %-20s\n", f_district_code, f_party_code, f_candi_code, f_name);
        }
    }

    color(0x07);
    fclose(fp5);

    D_seperator();

    printf(" You may vote for up to 3 candidates in this party \n");
   
    printf(" Enter 1st Candidate Code: ");
    scanf("%99s", candidate_codes1);

    printf(" Enter 2nd Candidate Code: ");
    scanf("%99s", candidate_codes2);

    printf(" Enter 3rd Candidate Code: ");
    scanf("%99s", candidate_codes3);
    D_seperator();

    FILE *fp3 = fopen(CANDIDATE_FILE, "r");
    if (fp3 == NULL) {
        printf("Error opening file for districts!\n");
        exit(1);
    }

    char line2[200];

    while (fgets(line2, sizeof(line2), fp3)) {
        char *fields[20];
        char f_candi_code[20] ="";
        char *token;
        int count = 0;

        // Tokenize by |
        token = strtok(line, "|");
        while (token != NULL && count < 20) {
            fields[count++] = token;
            token = strtok(NULL, "|");
        }

        /*-----------------------------------------------------------------------------------------------------------------------------------------------------------
        මෙකනින් නැවැත්තුවේ check කරන්න candidate cods ටික*/
        if (count >= 7) {
            
            char *f_candi_code    = fields[0];
        }
        if ((strcmp(f_candi_code, candidate_codes1) == 0) && (strcmp(f_candi_code, candidate_codes2)) && (strcmp(f_candi_code, candidate_codes3))){

        }
    }

    printf(" Candidate Codes 1 --> %s\n",candidate_codes1);
    printf(" Candidate Codes 2 --> %s\n",candidate_codes2);
    printf(" Candidate Codes 3 --> %s\n",candidate_codes3);
    D_seperator();

    printf(" Confirm Vote for: \n");

    printf(" (Y/N): ");
    scanf(" %c", &confirm);

        if(confirm == 'Y'|| confirm == 'y' ){
            FILE *fp1 = fopen(POOLING_FILE,"a");
            if(fp1 == NULL){
                printf("File Error");
                exit(1);
            }
           
            // Save with NIC first for easy checking
            fprintf(fp1, "%s|%s|%s|%s|%s|%s|\n", district, party_code, candidate_codes1, candidate_codes2, candidate_codes3,user_NIC);
        fclose(fp1);

            fclose(fp1);

            printf("%s|%s|%s|%s|%s|\n",district,party_code,candidate_codes1,candidate_codes2,candidate_codes3);
        

            D_seperator();
            color(0x0a);

            printf("[System] Vote successfully cast!\n");
            printf("[System] Thank you for voting.\n");
            color(0x07);
            D_seperator();
        }else {
            printf("[System] Vote is not submitted\n");
            D_seperator();
        }


    
    
    printf(" Redirecting to Main Menu...\n");
    
    pressEnterToContinue();
    time_delay();
    system("cls");
    main_menu();
    
    

    
}
