#include <stdio.h>
#include <string.h>
#include "passwordstrengthchecker.h"

void passwordStrengthChecker(){

    char password[31] ;
    printf("Enter Password: ");
    scanf("%s", password);

    int score = 0;
    int upper = 0;
    int lower = 0;
    int digit = 0;
    int special = 0;
    int space = 0;

    for(int i = 0; password[i] != '\0'; i++){

        if (password[i] >= 'A' && password[i] <= 'Z')
        {
            upper = 1;
        }

        if (password[i] >= 'a' && password[i] <= 'z')
        {
            lower = 1;
        }

        if (password[i] >= '0' && password[i] <= '9')
        {
            digit = 1;
        }
        if ((password[i] >= 33 && password[i] <= 47) ||
        (password[i] >= 58 && password[i] <= 64) ||
        (password[i] >= 91 && password[i] <= 96) ||
        (password[i] >= 123 && password[i] <= 126))
        {
            special = 1;
        }

        score = upper + lower + digit + special;

        if (strlen(password) >= 8 && strlen(password) <= 30)
        {
            score++;
        }

        if (score <= 2)
        {
            printf("Password Strength: Weak\n");
        }
        else if (score == 3 || score == 4)
        {
            printf("Password Strength: Medium\n");
        }
        else
        {
            printf("Password Strength: Strong\n");
        }
    }

}