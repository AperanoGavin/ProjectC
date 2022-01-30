#include<stdio.h>
#include<mysql/mysql.h>

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
    if(NULL  == mysql_real_connect(con,"localhost","root","",NULL, 0, NULL, 0)){
        printf("Failed to connect mysql ...\n");
        printf("Problem: %s\n",mysql_error(con));
        return;

    }
     printf("connected to  mysql ...\n");
     mysql_error(con);
}
