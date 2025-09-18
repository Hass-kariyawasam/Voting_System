#include <stdio.h>

//funtions declaration
int UI_main_menu();
int UI_admin_menu();
int admin_loging();
int admin_panel();
int UI_RO();
int UI_PO();
int voter();
int voter_registation();
int election_admin();
int party_admin();
int voter_login();
int registration();
int counting_PR_dis_();


int main() {
    // Your code here
  
    return 0;
}

int main_menu(){

    printf("\nWELCOME TO SRI LANKA PARLIAMENT VOTING SYSTEM 2025");
   
    int number;
        printf("\n[1] Admin Control Panel\n");
        printf("[2] Voter Registration\n");
        printf("[3] Candidate Registration\n");
        printf("[4] Vote Casting (Polling)\n");
        printf("[5] View Nominations List\n");
        
    	printf("[6] Results & Publications\n");
        printf("[0] Exit System\n");
        printf("\nenter your choice:");
        scanf(" %d",&number);
    
        switch (number)
        {
            case 0:
                 printf("Exit System\n");
                
                 break;
            case 1:
                adimin_menu();
                 break;
                 

        }
    	
}


int adimin_menu(){

    printf("ADMIN CONTROL PANEL - 2025\n");
    	 
    	 int choice;
    	     printf("\n[0]Back to main menu\n");
    	     printf("\n[1]Returing Officer RO)\n");
    	     printf("\n[2]Election Admin \n");
    	     printf("\n[3] Presiding Officer (PO) \n");
    	     printf("\n[4] Party Agent / Observer\n");
    	     printf("[5] Counting (District Level)n\n");
    	     
    	     
        printf("\nenter your choice:");
        scanf(" %d",&choice);
    
        switch (choice)
        {
            case 0:
            printf("Exit System\n");
            main_menu();
            
            break;
            case 1:
        }
    	 


}