#include<stdio.h>
#include "register.h"
#include<string.h>
void registerUser()
{
    printf("-------- User Registration -------\n");
    User newUser;
     printf("Enter Full Name: ");
    scanf(" %[^\n]", newUser.fullName);
    printf("Enter Username: ");
    scanf("%s", newUser.username);
    int check = usernameExists(newUser.username);
    if (check == 1)
{
    printf("Username already exists!\n");
    return;
}

    printf("Enter Password: ");
    scanf("%s", newUser.password);

    printf("Enter Phone Number: ");
    scanf("%s", newUser.phone);
    printf("\nRegistration information collected successfully!\n");

    saveUser(newUser);

    printf("User saved successfully!\n");

    
}

void saveUser(User x)
{
    FILE *fp = fopen("users.dat", "ab");

    if (fp == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    fwrite(&x, sizeof(x), 1, fp);

    fclose(fp);
}

int usernameExists(char username[])
{
    FILE *fp = fopen("users.dat", "rb");

    if (fp == NULL)
    {
        return 0;
    }

    User temp;

    while (fread(&temp, sizeof(User), 1, fp) == 1)
    {
        if (strcmp(temp.username, username) == 0)
        {
            fclose(fp);
            return 1;
        }
    }

    fclose(fp);
    return 0;
}