#ifndef REGISTER_H
#define REGISTER_H
typedef struct{
    char fullName[50];
    char username[30];
    char password[30];
    char phone[20];
}User ;

void registerUser();
int usernameExists(char username[]);
void saveUser( User user);

#endif