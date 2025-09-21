#include <stdio.h>
#include <string.h>
#include "custom.h"

int main(); // Forward declaration of main


int E_seperator() {
    printf("==================================================\n");
    return 0;
}

int D_seperator(){
    printf("-------------------------------------------------\n");
    return 0;
}
int time_delay(){
 printf("Initializing");
    for (int i = 0; i <= 10; i++)
    {
        printf(".");
        for (int j = 0; j < 30000000; j++)
            ; // Inner delay loop
    }
}
int long_delay(){
 printf("Initializing");
    for (int i = 0; i <= 10; i++)
    {
        printf(".");
        for (int j = 0; j < 100000000; j++)
            ; // Inner delay loop
    }
}
#include <stdio.h>

// Function to wait for Enter key
void pressEnterToContinue() {
    printf("Press Enter to continue...");
    // Clear input buffer if needed
    int c;
    while ((c = getchar()) != '\n' && c != EOF);  // Clear any leftover input
    getchar();  // Wait for Enter
}
