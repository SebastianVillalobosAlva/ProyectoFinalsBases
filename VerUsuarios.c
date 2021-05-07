/***************************************************************
*  VerUsuarios - Despliega todos los usuarios registrados      *
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

void VerUsuarios(MYSQL *conU){
    /* Declaramos la variable de apretar un boton para continuar */
    char enter[5];

    /* Declaramos la variable del contador */
    unsigned int i;

    /* Declaramos la variables MYSQL para recibir los datos */
    MYSQL_RES *resUser;
    MYSQL_ROW rowUser;

    // sprintf(sql_statement,"SELECT * FROM PF_usuarios");

    /* Query para obtener todos los usuarios */
    printf("\nEntro a VerUsuarios\n");
    mysql_query(conU,"SELECT Nombreu, ApellidoPatu, ApellidoMatu FROM PF_usuarios");
    resUser = mysql_store_result(conU);

    /* Imprimir el resultado del query */
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
    /* Liberamos el resultado */
    mysql_free_result(resUser);

    /* Necesitamos apretar una tecla para continuar */
    printf("\nSelecciona una tecla y aprieta enter\n");
    scanf(" %s", enter);
}