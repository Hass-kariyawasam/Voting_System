#include<stdio.h>
#include<string.h>
#include "admin.h"
int ro(){
int i;
char un[20];
char pw[20];

        char username[] = "admin";
        char password[] = "1234";
        
 for(i=1;i<45;i++){
        printf("=");
        }

    printf("\n\t\33[0;31mReturning Officer Login\033[0m\n");

        for(i=1;i<45;i++){
        printf("=");
        }

printf("\nPlease Enter Your Credentials :");

printf("\nUsername  :");
scanf("%s",un);

printf("\nPassword  :");
scanf("%s",pw);
 getchar();
 printf("\n\n");
 
  for(i=1;i<45;i++){
        printf("-");
        }
        
        
 if (strcmp(un, username) == 0 && strcmp(pw, password) == 0) {
            printf("\nLogin Succesful!");
           
            }
 else {
            printf("\nLogin Failed...Wrong Username Or Password\n");
            return 0;

 }
 

  printf("\nPress Enter To Continue.............");
 getchar();

  rom();

return 0;
}
