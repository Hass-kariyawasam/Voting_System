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

void num();
void number();
int main () {
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
    
       
      
    num();
    printf("\n\tPARTY ADMIN LOGIN\n\t");
    num();
    printf("\nPlease enter your credentials:");


                       int Username;
                       int Password; 
                        printf("\nUsername:\t");
                        scanf("%d",&Username);
                        printf("Password:\t");
                        scanf("%d", &Password);


                              if (Username == 5615) {

                                     if (Password == 12345) {
                                     printf("Login Successful!\n");
                                      number();


                                    num();
                                     printf("\n\tPARTY ADMIN CONTROL PANEL\n\t");
                                    num();
                                    
                                     int choice;
                                     printf("\n[1] SUBMIT NOMINATION LISTt\n");
                                     printf("[2] Logout\n");
                                     number();

                                     printf("Enter your choice:");
                                     scanf("%d",&choice);


                                      switch (choice)
                                      {
                                      case 1:
                                      num();
                                      printf("\n\tSUBMIT NOMINATION LIST\n\t");
                                      num();
                                                int code;
                                                char name[20];

                                                printf("\nEnter party code:\t");
                                                scanf("%d",& code);
                                                printf("Enter party name:\t");
                                                scanf(" %c", & name);
                                               number();


                                                int C_code,D_code,N_num,DOB;
                                                char C_name[50],answer[2];

                                                printf("\nEnter candidate name:\t");
                                                scanf(" \n%c",C_name);
                                                printf("\nEnter candidate code:\t");
                                                scanf("\n%d",&C_code);
                                                printf("\nEnter district  code:\t");
                                                scanf("\n%d",&D_code);
                                                printf("\nEnter NIC Number:\t");
                                                scanf("\n%d",&N_num);
                                                printf("\nEnter Date Of Birth:\t");
                                                scanf("\n%d",&DOB);
                                                number();
                                                printf("\nAdd another candidate?  (Y/N):");
                                                scanf(" %c",answer);
                                              
                                                



                                              

                                      

                                      break;
                                      case 2:
                                      printf("Logout");
                                      

                                      break;
                                      default:
                                      printf("invalid input");

                                     }

                                     } else {
                                     printf("Invalid Password\n");
                                   }
                              } else {
                                printf("Invalid Username\n");
                              }

   
                            
 return 0;
}

