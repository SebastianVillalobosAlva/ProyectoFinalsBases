#include <mysql/mysql.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void VerUsuarios(MYSQL *conU){
    unsigned int i;
    MYSQL_RES *resUser;
    MYSQL_ROW rowUser;

    // sprintf(sql_statement,"SELECT * FROM PF_usuarios");
    printf("\nEntro a VerUsuarios\n");
    mysql_query(conU,"SELECT Nombreu, ApellidoPatu, ApellidoMatu FROM PF_usuarios");
    resUser = mysql_store_result(conU);

    while(rowUser = mysql_fetch_row(resUser)){
        i = 0;
        for(i=0; i < mysql_num_fields(resUser); i++){
            if(rowUser[i] != NULL){
                printf("%s", rowUser[i]);
                printf(" ");
            }
            else{
                printf(" \n");
            } 
        }
        printf("\n");
    }
    mysql_free_result(resUser);
    getch();
}