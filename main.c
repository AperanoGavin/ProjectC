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
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"


struct user{
    char fullName[50];
    char firstName[50];
    char lastName[50];
    char email[50];
    char password[50];
    char username[50];
    char city[50];
    char country[50];
    int cp;
    double contact;
    int age;
};

void takeinput(char ch[50]){
    fflush(stdin);
    fgets(ch,50,stdin);
    ch[strlen(ch)-1] = 0;
}
void takeinputDb(double *db){
    fflush(stdin);
    scanf("%lf",db);
}
void takeinputIt(int *It){
    fflush(stdin);
    scanf("%d",It);
}

char generateUsername(char email[50], char username[50]){
    //take first part on email
    for(int i=0;i<strlen(email) ; i++){
        if(email[i] == '@')break;
        else username[i]= email[i];
    }

}



int main(int argc, char **argv) {

    char query[2000];
    char password1[50];
    MYSQL *conn;
    conn = mysql_init(NULL);
    FILE *fp;
    int opt;
    int opt2;
    struct user user;

    //for case 2(opt)
    char password2[50];
    char username[50];
    struct user userCon;
    int nb;
    MYSQL_RES *result;
    MYSQL_ROW row;



    printf("\n\t\t\t\t--------------------Welcome to Doctodog  --------------------");
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


                    printf("Enter  age :\t");
                    takeinputIt(&(user.age));//int



                    printf("Enter your contact :\t");
                    takeinputDb(&(user.contact));//double


                    printf("Enter your country :\t");
                    takeinput(user.country);

                    printf("Enter your city :\t");
                    takeinput(user.city);

                    printf("Enter your postal code  :\t");
                    takeinputIt(&(user.cp));//int

                    printf("Enter your password :\t");
                    takeinput(user.password);

                    printf("Confirme your password :\t");
                    takeinput(password1);


                    if(!strcmp(user.password,password1)){
                        printf("\n%syour password it's confirmed .\nuser register with succes",KGRN);
                        generateUsername(user.email, user.username);
                        printf("\nYour username is :%s",user.username);

                        fp= fopen("usersDataTest", "a+b");
                        fwrite(&user,sizeof (struct user),1,fp);

                        fclose(fp);


                    }else{
                        printf("\n\n\n/%spassword don't match try again\t", KRED);
                        mysql_close(conn);
                        break;
                    }

                    sprintf(query, "INSERT INTO user(fullName,email,age,contact,country,city,cp,password,username)  VALUES('%s', '%s', '%d', '%lf', '%s', '%s', '%d', '%s', '%s');",user.fullName, user.email, user.age, user.contact, user.country, user.city, user.cp, user.password,user.username);
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
                    takeinputIt(&(user.age));//int
                    printf("Enter your contact :\t");
                    takeinputDb(&(user.contact));//boub
                    printf("Enter your country :\t");
                    takeinput(user.country);
                    printf("Enter your city :\t");
                    takeinput(user.city);
                    printf("Enter your postal code  :\t");
                    takeinputIt(&(user.cp));//int
                    printf("Enter your password :\t");
                    takeinput(user.password);
                    printf("Confirme your password :\t");
                    takeinput(password1);

                    if(!strcmp(user.password,password1)){
                        printf("\n%syour password it's confirmed .\nplease see your mail",KGRN);
                        printf("\nYour username is :%s",user.username);

                        fp= fopen("usersDataTest", "a+b");
                        fwrite(&user,sizeof (struct user),1,fp);
                        fclose(fp);


                    }else{
                        printf("\n\n\n/%spassword don't match try again\t", KRED);
                        mysql_close(conn);
                        break;
                    }

                    sprintf(query, "INSERT INTO user(firstName,lastName,email,age,contact,country,city,cp,password,username)  VALUES('%s', '%s', '%s', '%d', '%lf', '%s', '%s', '%d', '%s','%s');",user.firstName,user.lastName, user.email, user.age, user.contact, user.country, user.city, user.cp, user.password,user.username);

                    mysql_query(conn, query);
                    mysql_close(conn);
                    break;

                case 3:
                    break;
            }
            break;
        case 2:
            mysql_real_connect(conn, "localhost", "root", "", "projectC", 3306, NULL, 0);

            printf("\nEnter your  Username:\t");
            takeinput(username);
            printf("\nEnter your  password:\t");
            takeinput(password2);
            sprintf(query, "SELECT username, password   FROM user  WHERE username='%s' AND password='%s'  ;",username,password2);
            mysql_query(conn, query);
            MYSQL_RES *result = mysql_use_result(conn);


            if((row = mysql_fetch_row (result))){

                printf("",row);
                printf("\n %sconnexion succes",KGRN);

                fp= fopen("usersDataTest", "rb");
                struct user temp;
                if (fp == NULL)
                    return -1;
                while(fread(&temp, sizeof(struct user), 1, fp), !feof(fp)){





                printf("\n\t\t\t\t\t\tWelcome %s",user.fullName);
                printf("\n\n|Full Name:\t%s",user.fullName);
                printf("\n|Email:\t\t%s",user.email);
                printf("\n|Username:\t%s",user.username);
                printf("\n|Contact no.:\t%lf",user.contact);
                }
                fclose(fp);

            }else{
                printf("\n %sPlease try again",KRED);
            }




            mysql_close(conn);


            break;
        case 3:
            break;


    }


    return 0;
}
