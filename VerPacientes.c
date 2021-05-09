/***************************************************************
*  VerPacientes - Despliega todos los pacientes registrados    *
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

void VerPacientes(MYSQL *conU){
    /* Declaramos la variable de apretar un boton para continuar */
    char enter[5];

    /* Declaramos la variable del contador */
    unsigned int i;

    /* Declaramos la variables MYSQL para recibir los datos */
    MYSQL_RES *resPac;
    MYSQL_ROW rowPac;

    // sprintf(sql_statement,"SELECT * FROM PF_usuarios");
    /* Query para obtener todos los pacientes */
    printf("\nEntro a VerPacientes\n");
    mysql_query(conU,"SELECT Nombre, ApellidoPat, ApellidoMat, Email FROM PF_pacientes");
    resPac = mysql_store_result(conU);

    /* Imprimir el resultado del query */
    while(rowPac = mysql_fetch_row(resPac)){
        i = 0;
        for(i=0; i < mysql_num_fields(resPac); i++){
            if(rowPac[i] != NULL){
                printf("%s", rowPac[i]);
                printf(" ");
            }
            else{
                printf(" \n");
            } 
        }
        printf("\n");
    }
    /* Liberamos el resultado */
    mysql_free_result(resPac);

    /* Necesitamos apretar una tecla para continuar */
    printf("\nSelecciona una tecla y aprieta enter\n");
    scanf(" %s", enter);
}