#include <mysql/mysql.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void VerUsuarios(MYSQL *conU){
    // char sql_statement[100];
    unsigned int i;
    MYSQL_RES *resUser;
    MYSQL_ROW rowUser;

    // sprintf(sql_statement,"SELECT * FROM PF_usuarios");
    printf("\nEntro a VerUsuarios");
    mysql_query(conU,"SELECT * FROM PF_usuarios");
    resUser = mysql_store_result(conU);

    while(rowUser = mysql_fetch_row(resUser)){
        i = 0;
        for(i=0; i < mysql_num_fields(resUser); i++){
            if(rowUser[i] != NULL){
                printf("%s", rowUser[i]);
            }
            else{
                printf(" \n");
            } 
        }
        // fputc("\n", stdout);
    }
    mysql_free_result(resUser);
}