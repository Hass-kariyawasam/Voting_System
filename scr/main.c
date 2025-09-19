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


int main () {
      
    void num();
    printf("\n\tPARTY ADMIN LOGIN\n\t");
    void num();
    printf("\nPlease enter your credentials:");


                       int Username,Password; 
                        printf("\nUsername:");
                        scanf("%d",&Username);
                        printf("Password: ");
                        scanf("%d", &Password);


                              if (Username == 5615) {

                                     if (Password == 12345) {
                                     printf("Login Successful!\n");
                                     void number();


                                     void num();
                                     printf("\n\tPARTY ADMIN CONTROL PANEL\n\t");
                                     void num();
                                    
                                     int choice;
                                     printf("\n[1] Submit Nomination List\n");
                                     printf("[2] Logout\n");
                                     printf("Enter your choice:");
                                     scanf("%d",&choice);


                                      switch (choice)
                                      {
                                      case 1:
                                      printf("Submit Nomination List");
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

