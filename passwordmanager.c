#include<stdio.h>
#include "passwordmanager.h"
void passwordManager(){
    printf("\n===== Password Manager =====\n");
    int passwordChoice;
    printf("1. Add Password\n");
    printf("2. View Password\n");
    printf("3. Update Password\n");
    printf("4. Delete Password\n");
    printf("5. Password Strength Checker\n");
    printf("6. Back\n");
    
    printf("Enter your password choice: ");
    scanf("%d", &passwordChoice);

        if (passwordChoice == 1)
        {
            addPassword() ;


        }
        else if (passwordChoice == 2)
        {
            viewPassword() ;

        }
        else if (passwordChoice == 3)
        {
            updatePassword() ;
        }
        else if (passwordChoice == 4)
        {
            deletePassword() ;
        }
        else if (passwordChoice == 5)
        {
            passwordStrengthChecker() ;
        }
        else if (passwordChoice == 6)
        {
            return ;

        }
        else
        {
            printf("Invalid choice!\n");
        }
    }
        void addPassword(){
             Password newPassword;
            printf("Enter Service Name: ");
            scanf("%s", newPassword.serviceName);

            printf("Enter Username/Email: ");
            scanf("%s", newPassword.username);

            printf("Enter Password: ");
            scanf("%s", newPassword.password);
            FILE *fp = fopen("passwords.dat", "ab");
            if (fp == NULL)
            {
                printf("Error opening file!\n");
                return;
            } 
            
            fwrite(&newPassword, sizeof(newPassword), 1, fp);

            fclose(fp);

            printf("Password saved successfully!\n");


        }

        void viewPassword(){
            FILE *fp = fopen("passwords.dat", "rb");
            if (fp == NULL)
            {
                printf("No saved passwords found!\n");
                return;
            }
            Password read ;
            while (fread(&read, sizeof(read), 1, fp) == 1){

            printf("\n==============================\n");
            printf("Service Name : %s\n", read.serviceName);
            printf("Username     : %s\n", read.username);
            printf("Password     : %s\n", read.password);
            printf("==============================\n");
            
           
        }
             fclose(fp);
    }
        void updatePassword()
        {
            FILE *fp = fopen("passwords.dat", "rb");
            FILE *temp = fopen("updatePasswords.dat", "wb");
            if(fp == NULL || temp == NULL)
            {
                printf("File error!\n");
                return;
            }
            char service[50];
            printf("Enter Service Name: ");
            scanf("%s", service);

            Password current;
            int found = 0;

            while (fread(&current, sizeof(current), 1, fp) == 1)
            {
                if (strcmp(current.serviceName, service) == 0)
                {
                    printf("Enter New Password: ");
                    scanf("%s", current.password);
                    found = 1;
                }

                fwrite(&current, sizeof(current), 1, temp);
            }

            fclose(fp);
            fclose(temp);
            if(found == 1)
            {
                remove("passwords.dat");
                rename("updatePasswords.dat", "passwords.dat");
                printf("Password updated successfully!\n");
            }
            else
            {
                remove("updatePasswords.dat");
                printf("Service not found!\n");

            }

        }

        void deletePassword()
        {

        }

        void passwordStrengthChecker()
        {

        }
        