#include "./conio for mac and windows/myconio_mac.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "./include/mysql.h"
#include <errno.h>
#include <unistd.h>
#include <pthread.h>

#define ENTER 13
#define TAB 9
#define BCKSPC 8


struct user{
    char fullName[50];
    char firstName[50];
    char lastName[50];
    char email[50];
    char password[50];
    char username[50];
    char contact[50];
    char age[50];
    char city[50];
    char country[50];
    char cp[50];
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

void takepassword(char pwd[50]){
    int i;
    char ch;
    while(1){
        ch = getch();
        if(ch == ENTER || ch == TAB){
            pwd[i] = '\0';
            break;
        }else if(ch == BCKSPC){
            if(i>0){
                i--;
                printf("\b \b");
            }

        }else{
            pwd[i++] = ch;
            printf("* \b");
        }
    }
}

int main(int argc, char **argv) {

    char query[2000];
    char query1[2000];

    MYSQL *conn;
    conn = mysql_init(NULL);
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

    switch(opt){
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
                    mysql_real_connect(conn, "localhost", "root", "", "projectC", 3306, NULL, 0);
                    printf("\nEnter full name of your dog:\t");
                    takeinput(user.fullName);



                    printf("Enter your email :\t");
                    takeinput(user.email);

                    printf("Enter  age of your dog :\t");
                    takeinput(user.age);

                    printf("Enter your contact :\t");
                    takeinput(user.contact);


                    printf("Enter your country :\t");
                    takeinput(user.country);

                    printf("Enter your city :\t");
                    takeinput(user.city);

                    printf("Enter your postal code  :\t");
                    takeinput(user.cp);

                    printf("Enter your password :\t");
                    takeinput(user.password);

                    sprintf(query, "INSERT INTO user(fullName,email,age,contact,country,city,cp,password)  VALUES('%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s');",user.fullName, user.email, user.age, user.contact, user.country, user.city, user.cp, user.password);
                    mysql_query(conn, query);
                    mysql_close(conn);

                    break;
                case 2:
                    mysql_real_connect(conn, "localhost", "root", "", "projectC", 3306, NULL, 0);

                    printf("Enter first name:\t");
                    takeinput(user.firstName);
                    printf("Enter last name:\t");
                    takeinput(user.lastName);
                    printf("Enter your email :\t");
                    takeinput(user.email);
                    printf("Enter  age :\t");
                    takeinput(user.age);
                    printf("Enter your contact :\t");
                    takeinput(user.contact);
                    printf("Enter your country :\t");
                    takeinput(user.country);
                    printf("Enter your city :\t");
                    takeinput(user.city);
                    printf("Enter your postal code  :\t");
                    takeinput(user.cp);
                    printf("Enter your password :\t");
                    takeinput(user.password);

                    sprintf(query, "INSERT INTO user(firstName,lastName,email,age,contact,country,city,cp,password)  VALUES('%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s');",user.firstName,user.lastName, user.email, user.age, user.contact, user.country, user.city, user.cp, user.password);
                    mysql_query(conn, query);
                    mysql_close(conn);
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