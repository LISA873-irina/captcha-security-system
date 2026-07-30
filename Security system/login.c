#include <stdio.h>
#include <string.h>
#include "register.h"
#include "login.h"

void loginUser(){
    printf("-------- Login --------\n");
    char username[30];
    char password[30];
    printf("Enter Username: ");
    scanf("%s", username);

    printf("Enter Password: ");
    scanf("%s", password);
    FILE *fp = fopen("users.dat", "rb");
    if (fp == NULL)
    {
    printf("No registered users found!\n");
    return;
    }

    User temp;
    int found = 0;
    while (fread(&temp, sizeof(temp), 1, fp) == 1){
    if (strcmp(temp.username, username) == 0 &&
    strcmp(temp.password, password) == 0)
    {
    found = 1;
    break;
    }
    }
    fclose(fp);
    if (found == 1)
    {
    printf("Login successful!\n");
    }
    else
    {
    printf("Invalid username or password!\n");
    }
}