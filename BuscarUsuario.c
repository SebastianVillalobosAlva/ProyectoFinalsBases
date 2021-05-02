#include <mysql/mysql.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void BuscarUsuario(MYSQL *conU){
    char enter[5], sql_statement[2048], Nombre[40], ApellidoPat[40];
    unsigned int i;
    int opcion = 0;
    MYSQL_RES *resUser;
    MYSQL_ROW rowUser;

    printf("\nEntro a BuscarUsuarios\n");
    printf("\nDecide como quieres buscar al usuario\n");
    printf("1) Nombre\n");
    printf("2) Apellido Paterno\n");
    printf("3) Nombre y Apellido Paterno\n");
    printf(" Forma de buscar: ");
    scanf("%i", &opcion);

    switch(opcion){
        case 1:
        sprintf(sql_statement,"SELECT Nombreu, ApellidoPatu, ApellidoMatu FROM PF_usuarios WHERE Nombreu = '%s'", Nombre);
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
        break;

        case 2:
        sprintf(sql_statement,"SELECT Nombreu, ApellidoPatu, ApellidoMatu FROM PF_usuarios WHERE ApellidoPatu = '%s'", ApellidoPat);
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
        break;

        case 3:
        sprintf(sql_statement,"SELECT Nombreu, ApellidoPatu, ApellidoMatu FROM PF_usuarios WHERE Nombreu = '%s' AND ApellidoPatu='%s'", Nombre, ApellidoPat);
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
        break;
    }
    mysql_free_result(resUser);
    printf("\nSelecciona una tecla y aprieta enter\n");
    scanf(" %s", enter);
}