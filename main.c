#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include <curl/curl.h>
#include "./include/mysql.h"


#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KWHT  "\x1B[37m"
#define KNRM  "\x1B[0m"
#define KBLU  "\x1B[34m"



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
    char query1[2000];
    char query2[2000];
    char password1[50];
    MYSQL *conn;
    conn = mysql_init(NULL);
    MYSQL *conn1;
    MYSQL *conn2;
    conn2 = mysql_init(NULL);
    conn1 = mysql_init(NULL);
    FILE *fp;
    char opt;

    char opt2;
    int opt3;
    int opt4;
    int j;
    int id;
    struct user user;

    //for case 2(opt)
    char password2[50];
    char username[50];
    int nb;
    MYSQL_RES *result;
    MYSQL_RES *result1;
    MYSQL_RES *result2;
    MYSQL_ROW row;
    MYSQL_ROW row1;
    MYSQL_ROW row2;

    MYSQL_FIELD *field;


    CURL *curl;
    CURLcode curl_res;

    curl_global_init(CURL_GLOBAL_ALL);

    curl = curl_easy_init();


    do {

        //make menu
        printf("\n\t\t\t\t%s--------------------Welcome to Doctodog  --------------------",KNRM);
        printf("\nChoose your operation ");
        printf("\n1.Signup");
        printf("\n2.Login");
        printf("\n3.Website");
        printf("\n4.Exit");

        printf("\n\nYour choice:\t");
        scanf("%s", &opt);
        fgetc(stdin);
        system("clear");

        //use switch to enter in different menu
        switch (opt) {
            case '1':
                do {


                    printf("\n\t\t\t\t%s--------------------Signup --------------------",KNRM);
                    printf("\nChoose your operation ");
                    printf("\n1.Signup for Dog");
                    printf("\n2.Signup for Doctor");
                    printf("\n3.return");


                    printf("\n\nYour choice:\t");
                    scanf("%s", &opt2);
                    fgetc(stdin);




                switch (opt2) {
                    case '1':
                        printf("\n\t\t\t\t%s--------------------Signup for Dog--------------------",KNRM);

                        //for init conn use mysql_real_connect
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


                        if (!strcmp(user.password, password1)) {
                            printf("\n%syour password it's confirmed .\nuser register with success", KGRN);
                            generateUsername(user.email, user.username);
                            printf("\nYour username is :%s", user.username);

                            fp = fopen("usersDataTest.bin", "ab");
                            fwrite(&user, sizeof(struct user), 1, fp);
                            fclose(fp);


                        } else {
                            printf("\n\n\n/%spassword don't match try again\t", KRED);
                            mysql_close(conn);
                            break;
                        }

                        sprintf(query,
                                "INSERT INTO user(fullName,email,age,contact,country,city,cp,password,username)  VALUES('%s', '%s', '%d', '%lf', '%s', '%s', '%d', '%s', '%s');",
                                user.fullName, user.email, user.age, user.contact, user.country, user.city, user.cp,
                                user.password, user.username);
                        mysql_query(conn, query);
                        mysql_close(conn);



                        break;
                    case '2':

                        printf("\n\t\t\t\t%s--------------------Signup for Doctor--------------------",KNRM);
                        mysql_real_connect(conn, "localhost", "root", "", "projectC", 3306, NULL, 0);

                        printf("\nEnter first name:\t");
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

                        if (!strcmp(user.password, password1)) {
                            printf("\n%syour password it's confirmed .\nplease see your mail", KGRN);
                            printf("\nYour username is :%s", user.username);

                            fp = fopen("usersDataTest", "a+b");
                            fwrite(&user, sizeof(struct user), 1, fp);
                            fclose(fp);


                        } else {
                            printf("\n\n\n/%spassword don't match try again\t", KRED);
                            mysql_close(conn);
                            break;
                        }

                        sprintf(query,
                                "INSERT INTO user(firstName,lastName,email,age,contact,country,city,cp,password,username)  VALUES('%s', '%s', '%s', '%d', '%lf', '%s', '%s', '%d', '%s','%s');",
                                user.firstName, user.lastName, user.email, user.age, user.contact, user.country,
                                user.city, user.cp, user.password, user.username);

                        mysql_query(conn, query);
                        mysql_close(conn);

                        break;


                }
                } while (opt2 != '3');
                break;
            case '2':



                    mysql_real_connect(conn, "localhost", "root", "", "projectC", 3306, NULL, 0);

                    printf("\n\t\t\t\t%s--------------------Login  --------------------", KNRM);

                    printf("\n\nEnter your  Username:\t");
                    takeinput(username);
                    printf("\nEnter your  password:\t");
                    takeinput(password2);

                    sprintf(query, "SELECT *   FROM user  WHERE username='%s' AND password='%s'  ;", username,
                            password2);
                    mysql_query(conn, query);
                    MYSQL_RES *result = mysql_use_result(conn);



                    if ((row = mysql_fetch_row(result))) {

                        printf("", row);
                        printf("\n\n\t\t\t\t\t\t%s    connexion success %s", KGRN, row[1]);
                        system("clear");


                        if ((row[2] == NULL)) {
                            printf("\n\t\t\t\t%s--------------------Home page for Dog  --------------------", KNRM);
                            printf("\nChoose your operation ");
                            printf("\n1.Your Information");
                            printf("\n2.Doctor");
                            printf("\n3.Appointment");
                            printf("\n4.Return");


                            printf("\n\nYour choice:\t");
                            scanf("%d", &opt3);
                            system("clear");
                            fgetc(stdin);


                            switch (opt3) {
                                case 1:


                                    printf("\n\t\t\t\t%s--------------------Home page for Dog  --------------------",
                                           KNRM);

                                    printf("\n|fullname:\t\t %s\n", row[1]);
                                    printf("\n|Email:\t\t %s\n", row[6]);
                                    printf("\n|age:\t\t %s\n", row[7]);
                                    printf("\n|Contact :\t%s\n", row[8]);

                                    break;



                                case 2:

                                    mysql_free_result(result);


                                    mysql_real_connect(conn1, "localhost", "root", "", "projectC", 3306, NULL, 0);
                                    sprintf(query1,
                                            "SELECT id,fullName,contact,country,city,cp   FROM user where firstName IS NOT NULL ;");
                                    mysql_query(conn1, query1);
                                    MYSQL_RES *result1 = mysql_use_result(conn1);

                                    int num_fields = mysql_num_fields(result1);
                                    printf("%s\n\t\t|Id\t\t|Name\t\t|Contact\t|Country\t|City\t\t|Code postal\t\t \n", KBLU);

                                    while ((row1 = mysql_fetch_row(result1))) {
                                        for (int i = 0; i < num_fields; i++) {

                                            printf("%s""\t\t""%s", KNRM, row1[i] ? row1[i] : "NULL");


                                        }

                                        printf("\n");
                                    }
                                    //mysql_free_result(result1);
                                    //mysql_close(conn1);

                                    break;
                                case 3:
                                    mysql_free_result(result);

                                    mysql_real_connect(conn2, "localhost", "root", "", "projectC", 3306, NULL, 0);

                                    printf("\nPlease enter id of doctor for take appointment:");
                                    scanf("%d",&id);
                                    sprintf(query2, "SELECT fullName,email,contact FROM USER where id ='%d' ;", id);
                                    mysql_query(conn2, query2);
                                    MYSQL_RES *result2 = mysql_use_result(conn2);
                                   if((row2 = mysql_fetch_row(result2)) != NULL){
                                         printf("%s""\t\t""%s", KNRM, row2[1]);



                                    } else{

                                       printf("oups");
                                   }




                                    //mysql_free_result(result2);


                                    //mysql_close(conn2);
                                    break;
                                case 4:
                                    break;

                            }


                        } else {

                            printf("\n\t\t\t\t%s--------------------Home page for Doctor  --------------------", KNRM);
                            printf("\nChoose your operation ");
                            printf("\n1.Your Information");
                            printf("\n2.Customers(Dogs)");
                            printf("\n3.Return");


                            printf("\n\nYour choice:\t");
                            scanf("%d", &opt4);
                            system("clear");
                            fgetc(stdin);

                            switch (opt4) {

                                case 1:


                                    printf("\n\t\t\t\t%s--------------------Home page for Doctor  --------------------",
                                           KNRM);

                                    printf("\n|fullname:\t\t %s\n", row[1]);
                                    printf("\n|firstName:\t\t %s\n", row[2]);
                                    printf("\n|Email:\t\t %s\n", row[6]);
                                    printf("\n|age:\t\t %s\n", row[7]);
                                    printf("\n|Contact :\t%s\n", row[8]);
                                    break;

                                case 2:
                                    mysql_free_result(result);


                                    mysql_real_connect(conn1, "localhost", "root", "", "projectC", 3306, NULL, 0);
                                    sprintf(query1,
                                            "SELECT fullName,contact,country,city,cp   FROM user where firstName IS NULL ;");
                                    mysql_query(conn1, query1);
                                    MYSQL_RES *result1 = mysql_use_result(conn1);

                                    int num_fields = mysql_num_fields(result1);
                                    printf("%s\n\t\t|Name\t\t|Contact\t|Country\t|City\t\t|Code postal\t\t \n", KBLU);


                                    while ((row1 = mysql_fetch_row(result1))) {
                                        for (int i = 0; i < num_fields; i++) {

                                            printf("%s""\t\t""%s", KNRM, row1[i] ? row1[i] : "NULL");


                                        }

                                        printf("\n");
                                    }

                                    mysql_free_result(result1);
                                    mysql_close(conn1);
                                    break;


                            }

                        }


                    } else {
                        printf("\n %sPlease try again, password invalid", KRED);

                    }


                    mysql_close(conn);

                break;



            case '3':
                if (curl != NULL)
                {
                    curl_easy_setopt(curl, CURLOPT_URL, "http://localhost:8888/site3%203/index.php");
                    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1);
                    // Perform the request, curl_res will get the return code
                    curl_res = curl_easy_perform(curl);

                    // Check for errors

                    if(curl_res != CURLE_OK)
                        fprintf(stderr, "curl_easy_perform() failed: %s\n",
                                curl_easy_strerror(curl_res));

                    if(CURLE_OK == curl_res)
                    {
                        char *url;
                        curl_res = curl_easy_getinfo(curl, CURLINFO_EFFECTIVE_URL, &url);

                        if((CURLE_OK == curl_res) && url)
                            system("clear");
                            printf("\n\n\n\n\t\tConnexion with website to take appointment : %s\n", url);

                    }

                    // always cleanup
                    curl_easy_cleanup(curl);

                    // we're done with libcurl, so clean it up
                    curl_global_cleanup();

                }
                else
                {
                    printf("cURL error.\n");
                }

                break;
            default:
                printf("Sorry try again.");
                break;


        }

    } while (opt != '4');


    printf("\n\t\n\tBye bye :')");

    return 0;
}
