#include "./conio for mac and windows/myconio_mac.h"
#include<stdio.h>
#include<string.h>
#include <unistd.h>

struct user{
    char fullName[50];
    char email[50];
    char password[50];
    char username[50];
    char contact[50];
    char age[50];
};

void takeinput(char ch[50]){
    fgets(ch,50,stdin);
    ch[strlen(ch)-1] = 0;
}
void generateUsername(char email[50], char username[50]){
    //take first part on email
    for(int i=0;i<strlen(email) ; i++){
        if(email[i] = '@')break;
        else username[i]= email[i];
    }


}


int main(int argc, char **argv) {


    int opt;
    struct user user;

    printf("\n\t\t\t\t--------------------Welcom to Doctodog  --------------------");
    printf("\nChoose your operation ");
    printf("\n1.Signup");
    printf("\n2.Login");
    printf("\n2.Exit");

    printf("\n\nYour choice:\t");
    scanf("%d",&opt);
    fgetc(stdin);

    switch (opt) {
        case 1:
            printf("\nEnter full name of your dog:\t");
            takeinput(user.fullName);
            printf("\nEnter your email :\t");
            takeinput(user.email);
            printf("\nEnter  age of your dog :\t");
            takeinput(user.age);
            printf("\nEnter your contact :\t");
            takeinput(user.contact);
            printf("\nEnter your password :\t");
            takeinput(user.password);


    }


    return 0;
}
