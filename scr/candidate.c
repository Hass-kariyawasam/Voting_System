#include <stdio.h>

void num() {
    for (int i = 1; i <= 55; i++) {
        printf("=");
    }
    printf("\n");
}

void number() {
    for (int i = 1; i <= 55; i++) {
        printf("-");
    }
    printf("\n");
}

int main() {
    num();
    printf("\tVOTER REGISTRATION\n");
    num();

    int nic, Age, pwd, D_code,P_code;
    char name[20], citizen[2];

    printf("\nEnter NIC Number:\t");
    scanf("%d", &nic);

    printf("\nEnter Candidate Name:\t");
    scanf(" %[^\n]", name);

    printf("\nEnter Age:\t");
    scanf("%d", &Age);
    if (Age>18){
       

        printf("\nCitizenship (Y/N):\t");
        scanf(" %1s", citizen);
        if (citizen[0] != 'N' && citizen[0] != 'N'){
               

                    printf("\nCreate Password:\t");
                    scanf("%d", &pwd);

                     printf("\nEnter District Code:\t");
                     scanf("%d", &D_code);

                      printf("\nEnter Party Code:\t");
                      scanf("%d", &P_code);
                      number();
                    }

               } else {
         printf("you are not eligible to vote");}
         number();
    
     } else {
         printf("you are not eligible to vote");}
         number();
    
    
    return 0;
}
