#include "./conio for mac and windows/myconio_mac.h"
#include<stdio.h>
#include<string.h>
#include <unistd.h>

#define ENTER 13
#define TAB 9
#define BCKSPC 8

struct user{
    char fullName[50];
    char email[50];
    char password[50];
    char username[50];
    char contact[50];
    char age[50];
    char adresse[200];
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

void takepassword(char password[50]){
    int i;
    char ch;
    while(1){
        ch = getch();
        if (ch == ENTER || ch == TAB){
            password[i]='\0';
            break;
        } else if(ch == BCKSPC){
            if(i<0){
                i--;
                printf("\b \b");
            }

        }else{
            password[i++] = ch;
            printf("* \b");
        }
    }
}


int main(int argc, char **argv) {


    int opt;
    int opt2;
    struct user user;

    printf("\n\t\t\t\t--------------------Welcom to Doctodog  --------------------");
    printf("\nChoose your operation ");
    printf("\n1.Signup");
    printf("\n2.Login");
    printf("\n3.Exit");

    printf("\n\nYour choice:\t");
    scanf("%d",&opt);
    fgetc(stdin);

    switch (opt) {
        case 1:

            printf("\n\t\t\t\t--------------------Signup --------------------");
            printf("\nChoose your operation ");
            printf("\n1.Signup for Dog");
            printf("\n2.Signup for Doctor");
            printf("\n3.Exit");

            printf("\n\nYour choice:\t");
            scanf("%d",&opt2);
            fgetc(stdin);

            switch(opt2){
                case 1:
                    printf("\nEnter full name of your dog:\t");
                    takeinput(user.fullName);
                    printf("Enter your email :\t");
                    takeinput(user.email);
                    printf("Enter  age of your dog :\t");
                    takeinput(user.age);
                    printf("Enter your contact :\t");
                    takeinput(user.contact);
                    printf("Enter your adresse :\t");
                    takeinput(user.adresse);
                    printf("Enter your password :\t");
                    takepassword(user.password);
                    break;
                case 2:

                    printf("Enter full name:\t");
                    takeinput(user.fullName);
                    printf("Enter your email :\t");
                    takeinput(user.email);
                    printf("Enter  age :\t");
                    takeinput(user.age);
                    printf("Enter your contact :\t");
                    takeinput(user.contact);
                    printf("Enter your adresse :\t");
                    takeinput(user.adresse);
                    printf("Enter your password :\t");
                    takepassword(user.password);
                    break;

                case 3:
                    break;
            }

        case 2:
            break;
        case 3:
            break;


    }


    return 0;
}
