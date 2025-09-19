#include <stdio.h>

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

int main() {
    num();
    printf("\tVOTER REGISTRATION\n");
    num();

    int nic, Age, pwd, D_code;
    char name[20], citizen[2];

    printf("\nEnter NIC Number:\t");
    scanf("%d", &nic);

    printf("\nEnter Full Name:\t");
    scanf(" %[^\n]", name);

    printf("\nEnter Age:\t");
    scanf("%d", &Age);

    printf("\nCitizenship (Y/N):\t");
    scanf(" %1s", citizen);

    printf("\nCreate Password:\t");
    scanf("%d", &pwd);

    printf("\nEnter District Code:\t");
    scanf("%d", &D_code);

    return 0;
}