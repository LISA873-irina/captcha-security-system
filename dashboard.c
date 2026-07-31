#include <stdio.h>
#include "dashboard.h"
void dashboard(){
    printf("\n===== SecureVault Dashboard =====\n");
    int choice;

    while (1)
    {
        printf("\n===== SecureVault Dashboard =====\n");
        printf("1. Password Manager\n");
        printf("2. Secure Records\n");
        printf("3. Logout\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);
        if (choice == 1)
    {
    passwordManager();
    }
    else if (choice == 2)
    {
    secureRecords();
    }
    else if (choice == 3)
    {
    printf("\nLogged out successfully!\n");
    break;
    }
    else
    {
    printf("\nInvalid choice!\n");
    }

    }
}