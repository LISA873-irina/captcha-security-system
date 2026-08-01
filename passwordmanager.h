#ifndef PASSWORDMANAGER_H
#define PASSWORDMANAGER_H

void passwordManager();
void addPassword();
void viewPassword();
void updatePassword();
void deletePassword();
void passwordStrengthChecker();
typedef struct
{
    char serviceName[50];
    char username[50];
    char password[50];

} Password;

#endif