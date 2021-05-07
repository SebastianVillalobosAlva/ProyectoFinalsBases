/***************************************************************
*  BuscarUsuario - Busca un usuario por apellido y nombre      *
*                                                              *
*                                                              *
*  Parámetros:                                                 *
*    MYSQL *conn - Conector de MYSQL                           *
*                                                              *
*                                                              *
*                                                              *
*  Valor de retorno:                                           * 
*    No hay valor de retorno                                   *
*                                                              *
***************************************************************/

#include <mysql/mysql.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void BuscarUsuario(MYSQL *conU, char *name){
    /* Declaramos la variables para buscar al usuario y donde vamos a guardar el query */
    char enter[5], sql_statement[2048], sql_statement_2[2046], Nombre[40], ApellidoPat[40];

    /* Declaramos la variable del contador y opcion */
    unsigned int i;
    int opcion = 0;

    /* Declaramos la variables MYSQL para recibir los datos */
    MYSQL_RES *resUser;
    MYSQL_ROW rowUser;

    /* Ponemos las opciones de forma de buscar */
    printf("\nEntro a BuscarUsuarios\n");
    printf("\nDecide como quieres buscar al usuario\n");
    printf("1) Nombre\n");
    printf("2) Apellido Paterno\n");
    printf("3) Nombre y Apellido Paterno\n");
    printf(" Forma de buscar: ");

    /* Leemos la variable de opcion */
    scanf("%i", &opcion);

    switch(opcion){
        case 1:
        /* Leemos el nombre */
        printf(" Nombre: ");
        scanf("%s", Nombre);

        /* Llenamos el query con el nombre */
        sprintf(sql_statement,"SELECT Nombreu, ApellidoPatu, ApellidoMatu FROM PF_usuarios WHERE Nombreu = '%s'", Nombre);
        mysql_query(conU,sql_statement);
        resUser = mysql_store_result(conU);

        /* Obtenemos el resultado */
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
        /* Leemos el apellido paterno */
        printf(" Apellido Paterno: ");
        scanf("%s", ApellidoPat);

        /* Llenamos el query con el apellido paterno */
        sprintf(sql_statement,"SELECT Nombreu, ApellidoPatu, ApellidoMatu FROM PF_usuarios WHERE ApellidoPatu = '%s'", ApellidoPat);
        mysql_query(conU,sql_statement);
        resUser = mysql_store_result(conU);

        /* Obtenemos el resultado */
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
        /* Leemos el nombre y el apellido paterno */
        printf(" Nombre: ");
        scanf("%s", Nombre);
        printf(" Apellido Paterno: ");
        scanf("%s", ApellidoPat);

        /* Llenamos el query con el nombre y apellido paterno */
        sprintf(sql_statement,"SELECT Nombreu, ApellidoPatu, ApellidoMatu FROM PF_usuarios WHERE Nombreu = '%s' AND ApellidoPatu='%s'", Nombre, ApellidoPat);
        mysql_query(conU,sql_statement);
        resUser = mysql_store_result(conU);

        /* Obtenemos el resultado */
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
    /* Liberamos el resultado */
    mysql_free_result(resUser);

    sprintf(sql_statement_2,"INSERT INTO PF_registrobus (registro, NombreU) VALUES ('%s', '%s')", "Hola", name);
    mysql_query(conU,sql_statement_2);

    /* Necesitamos apretar una tecla para continuar */
    printf("\nSelecciona una tecla y aprieta enter\n");
    scanf(" %s", enter);
}