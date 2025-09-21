#include<stdio.h>
#include "admin.h"
    int main(){
    int i;
    int choice;
        for(i=1;i<55;i++){
        printf("=");
        }

    printf("\n\t\33[0;31mWelcome to Sri Lanka Parliment\n\t\tVoting System 2025\033[0m\n");

        for(i=1;i<55;i++){
        printf("=");
        }

printf("\n[1] Admin Control Panel\n[2] Voter Registration\n[3] Candidate Registration\n[4] Vote Casting(pooling)\n[5] View Nominations List\n[6] Results & Publications\n[0] Exit System\n\n");

        for(i=1;i<55;i++){
        printf("-");
        }

printf("\nEnter Your Choice   :");
scanf("%d",&choice);
switch(choice){
    case 1:
        admin();
        break;
}   
return 0;
}
