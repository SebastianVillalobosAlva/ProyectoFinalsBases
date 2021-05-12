/***************************************************************
*  ChecarDiagnostio - Despliega a todos los usuarios que       *
*                     comparten un diagnostico                 *
*                                                              *
*  Parámetros:                                                 *
*    MYSQL *conn - Conector de MYSQL                           *
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

void ChecarDiagnostico(MYSQL *conU){
    char enter[5], sql_statement[4056];
    int opcion = 0;
    unsigned int i;
    MYSQL_RES *resUser, *resUser2;
    MYSQL_ROW rowUser, rowUser2;

    printf("\nEntro a ChecarDiagnostico\n");

    mysql_query(conU,"SELECT IDenfermedad, enfermedad FROM PF_enfermedad");
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

    printf("Por favor ingresa el numero diagnostico que quieres buscar\n");
    printf(" ID enfermedad: ");
    scanf("%i", &opcion);

    sprintf(sql_statement,"SELECT Nombre, ApellidoPat, ApellidoMat FROM PF_consultas LEFT JOIN PF_pacientes USING(IDpaciente) LEFT JOIN PF_enfermedad USING(IDenfermedad) WHERE IDenfermedad = '%i' GROUP BY IDpaciente", opcion);

    mysql_query(conU,sql_statement);
    resUser2 = mysql_store_result(conU);

    while(rowUser2 = mysql_fetch_row(resUser2)){
        i = 0;
        for(i=0; i < mysql_num_fields(resUser2); i++){
            if(rowUser2[i] != NULL){
                printf("%s", rowUser2[i]);
                printf(" ");
            }
            else{
                printf(" \n");
            } 
        }
        printf("\n");
    }

    mysql_free_result(resUser2);
    printf("\nSelecciona una tecla y aprieta enter\n");
    scanf(" %s", enter);
}