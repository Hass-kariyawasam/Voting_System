#include <stdio.h>

int admin_loging(char user[]) {
    /*  ================================================= 
                     ELECTION ADMIN LOGIN 
        ================================================= 
 
        Please enter your credentials: 
 
        Username: ea2025 
        Password: ******** 
 
        [System] Authenticating... 
        [System] Login successful! 
        ------------------------------------------------- 
        Redirecting to Election Admin Panel...*/
    char username[50];
    char password[50];
    printf("==================================================\n");
    printf("\t\t\tELECTION ADMIN LOGIN\n");
    printf("==================================================\n");
    printf("\nPlease enter your credentials:\n\n");   
    printf("Username: ");
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", password);
    printf("\n[System] Authenticating...\n");
    
    char pass[50] = user[25]+"123"; //ELECTION123

    if (username == user && password == pass ) {
        printf("Login successful!\n");
       
    } else {
        printf("Invalid credentials. Please try again.\n");
        // Handle invalid login
    }

    return 0;
}
