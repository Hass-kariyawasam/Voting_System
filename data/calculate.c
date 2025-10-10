#include <stdio.h>

#define POLLING_FILE "pooling.txt"
#define POLLING_VOTS_FILE "party_votes.txt"

int main(){
    FILE *fp = fopen(POLLING_FILE,"r");
    FILE *fp1 = fopen(POLLING_VOTS_FILE,"a");
    if(fp != NULL){
        char line[255];
        char party_code[15];
        char ca1[15];
        char ca2[15];
        char ca3[15];
        int num;

        while (fgets(line, sizeof(line), fp)) {
          

                char *token = strtok(line, "|");
                token = strtok(NULL, "|"); 
                strcpy(party_code, token);

                token = strtok(NULL, "|"); 
                strcpy(ca1, token);

                token = strtok(NULL, "|"); 
                strcpy(ca2, token);

                token = strtok(NULL, "|");
                strcpy(ca3, token);

                char line2[99];

                while (fgets(line2, sizeof(line2),fp1))
                {
                    char exparty_code[50] ="";
                    int num;
                    char *token = strtok(line, "|");
                    strcpy(exparty_code, token);
                    token = strtok(NULL, "|");
                    strcpy(num, token);

                    if(strlen(exparty_code) == 0){
                        if(strcmp(exparty_code,party_code) == 0){
                            if(strlen(ca1) == 0)
                                num++;

                        }
                    }
                }
                
                if (){
                    strcpy(file_distric_code, token);
                    
                    file_distric_code[strcspn(file_distric_code, "\n")] = 0;
                    
                    if (strcmp(user_NIC, file_nic) == 0) {
                        found = 1; // Match found
                    
                        break;
                    }
                }
            
        }    

        
    }
    fclose(fp);
    
    return 0;
}