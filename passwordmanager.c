#include<stdio.h>
#include "passwordmanager.h"
#include <string.h>


void passwordManager(){
    printf("\n===== Password Manager =====\n");
    int passwordChoice;
    printf("1. Add Password\n");
    printf("2. View Password\n");
    printf("3. Update Password\n");
    printf("4. Delete Password\n");
    printf("5. Search Password\n");
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
            searchPassword();
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
            FILE *fp = fopen("passwords.dat", "rb");
            FILE *temp = fopen("deletePasswords.dat", "wb");

            if (fp == NULL || temp == NULL)
            {
                printf("File error!\n");
                return;
            }

            char deleteService[50];

            printf("Enter Service Name to delete: ");
            scanf("%s", deleteService);

            Password deleteRecord;
            int found = 0;

        while (fread(&deleteRecord, sizeof(deleteRecord), 1, fp) == 1){

            if (strcmp(deleteRecord.serviceName, deleteService) == 0)
            {
                found = 1;
            }
            else
            {
                fwrite(&deleteRecord, sizeof(deleteRecord), 1, temp);
            }
        }
        fclose(fp);
        fclose(temp);

        if(found == 1)
        {
            remove("passwords.dat");
            rename("deletePasswords.dat", "passwords.dat");
            printf("Password deleted successfully!\n");

        }
        else
        {
            remove("deletePasswords.dat");
            printf("Service not found!\n");

        }

        }

        void searchPassword(){

            FILE *fp = fopen("passwords.dat", "rb");
                if (fp == NULL)
            {
                printf("No saved passwords found!\n");
                return;
            }
            char searchService[50];
            printf("Enter Service Name to search: ");
            scanf("%s", searchService); 
    
            Password searchRecord;
            int found = 0 ;

            while (fread(&searchRecord, sizeof(searchRecord), 1, fp) == 1){
                 if (strcmp(searchRecord.serviceName, searchService) == 0){

                    printf("\n==============================\n");
                    printf("Service Name : %s\n", searchRecord.serviceName);
                    printf("Username     : %s\n", searchRecord.username);
                    printf("Password     : %s\n", searchRecord.password);
                    printf("==============================\n");

                    found = 1;
                    break;
                 }
            }

            fclose(fp);

            if (found == 0)
            {
                printf("Service not found!\n");
            }

        }
    void sortPassword(){   
    FILE *fp = fopen("passwords.dat", "rb");

    if (fp == NULL)
    {
        printf("No saved passwords found!\n");
        return;
    }

    Password records[100];
    int count = 0;
    while (fread(&records[count], sizeof(records[count]), 1, fp) == 1)
    {
        count++;
    }

    fclose(fp);
    
    Password tempS;

    for( int i = 0 ; i < count ; i ++ ){
        for( int j = i ; j < count ; j ++){
            if (strcmp(records[i].serviceName, records[j].serviceName) > 0){

                tempS = records[i] ;
                records[i] = records[j] ;
                records[j] = tempS ;
                
            }
        }
    }

    fp = fopen("passwords.dat", "wb");

    for (int k = 0; k < count; k++)
    {
        fwrite(&records[k], sizeof(records[k]), 1, fp);
    }

    fclose(fp);
}

        