#include<stdio.h>
#include "securerecords.h"

void secureRecords(){

    int choice;
    while(1){

        printf("\n===== Secure Records =====\n");
        printf("1. Add Record\n");
        printf("2. View Records\n");
        printf("3. Update Record\n");
        printf("4. Delete Record\n");
        printf("5. Search Record\n");
        printf("6. Sort Records\n");
        printf("7. Back\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1){

            addRecord();
        }
        else if (choice == 2){

            viewRecord();
        }
        else if (choice == 3){

            updateRecord();
        }
        else if (choice == 4){

            deleteRecord();
        }
        else if (choice == 5){

            searchRecord();
        }
        else if (choice == 6){

            sortRecord();
        }
        else if (choice == 7){

            return;
        }
        else{
            printf("Invalid choice!\n");
        }


        void addRecord(){

        }

        void viewRecord(){

        }

        void updateRecord(){

        }

        void deleteRecord(){

        }

        void searchRecord(){

        }

        void sortRecord(){

        }

    }
}