#include<stdio.h>
#include "admin.h"
int admin(){
int i;
int choice;

printf("\n\n\n");
 for(i=1;i<45;i++){
        printf("=");
        }

printf("\n\t\33[0;31mAdmin Control Panel - 2025\033[0m\n");

        for(i=1;i<45;i++){
        printf("=");
        }
printf("\n[1] Returning Officer (RO)\n[2] Election Admin\n[3] Presiding Officer (PO)\n[4] Party Agent / Observer\n[0] Back to Main Menu\n");

        for(i=1;i<45;i++){
        printf("-");
        }
printf("\nEnter Your Choice   :");
scanf("%d",&choice);
switch(choice){
    case 1:
        ro();
        break;
}
return 0;
}

