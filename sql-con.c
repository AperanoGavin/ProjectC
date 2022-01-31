#include "./conio for mac and windows/myconio_mac.h"
#include<stdio.h>
#include<string.h>
#include "./include/mysql.h"


void main(){
   MYSQL *con = NULL;
   printf("initializing mysql ..\n");
   con = mysql_init(NULL);
   if(NULL == con){
   printf("Failed to initialize mysql ...\n");
   printf("Problem: %s\n",mysql_error(con));
   return;
 }
   printf("attempting to connect \n");
    if(NULL  == mysql_real_connect(con,"localhost","root","","projectC", 3306, NULL, 0)){
        printf("Failed to connect mysql ...\n");
        printf("Problem: %s\n",mysql_error(con));
        return;

    }
     printf("connected to  mysql ...\n");
     mysql_error(con);
}

