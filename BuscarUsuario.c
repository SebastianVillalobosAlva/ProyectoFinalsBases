#include <mysql/mysql.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void BuscarUsuario(MYSQL *conU){
    char enter[5], sql_statement[2048], Nombre[40];
    unsigned int i;
    MYSQL_RES *resUser;
    MYSQL_ROW rowUser;
    printf("\nPon el nombre del usuario que quieres buscar:\n");
    printf("Nombre:");
    scanf(" %s", Nombre);

    sprintf(sql_statement,"SELECT Nombreu, ApellidoPatu, ApellidoMatu FROM PF_usuarios WHERE Nombreu = '%s'", Nombre);
    printf("\nEntro a BuscarUsuarios\n");
    mysql_query(conU,sql_statement);
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
    printf("\nSelecciona una tecla y aprieta enter\n");
    scanf(" %s", enter);
}