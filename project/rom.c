#include<stdio.h>
#include "admin.h"
int rom(){
int i;
int choice;
        for(i=1;i<45;i++){
        printf("=");
        }

printf("\n    \33[0;31mRETURNING OFFICER (RO) CONTROL PANEL\033[0m\n");

        for(i=1;i<45;i++){
        printf("=");
        }
 printf("\n[1] Accept Nomination List\n[2] District Result Generation\n[3] Nomination Review & Approval \n[4] Resalt View and Publication \n[0] Back to Admin Panel\n");       
        for(i=1;i<45;i++){
        printf("-");
        }
        
                            printf("\nEnter Your Choice   :");
                            scanf("%d",&choice);
                            switch(choice){
                                case 1:
                                    list();
                                    break;
                                case 2:
                                    results();
                                    break;
                                case 3:
                                    review();
                                    break;
                                case 4:
                                    publication();
                                    break;
                                case 0:
                                    admin();
                                    break;
                                
                            }   
 
return 0;
}

