#include<stdio.h>
#include "admin.h"


int list(){
int i;
int choice;



 for(i=1;i<45;i++){
        printf("=");
        }

printf("\n    \33[0;31mACCEPT NOMINATION LIST – BY PARTY\033[0m\n");

        for(i=1;i<45;i++){
        printf("=");
        }


printf("\n\n\n\n\n\n\n\n\n");      
        for(i=1;i<45;i++){
        printf("-");
        }
printf("\nOptions:\n");

printf("[0] Back to RO Menu\n");

      for(i=1;i<45;i++){
        printf("-");
        }  
   printf("\n\nEnter Your Choice :");
   scanf("%d",&choice);
switch(choice){
        case 0:
            rom();
    
return 0;
}
}
