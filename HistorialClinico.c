/***************************************************************
*  HistorialClinico - Despliega el historial clinico de un     *
*                     paciente en especifico                   *
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

void HistorialClinico(MYSQL *conU){
    char enter[5], sql_statement[2048], Nombre[40], ApellidoPat[40], Email[40];
    unsigned int i;
    int opcion = 0;
    MYSQL_RES *resUser;
    MYSQL_ROW rowUser;
    
    printf("\nEntro a HistorialClinico\n");
    printf("Por favor ingresa el nombre y apellido paterno del paciente\n");
    printf(" Nombre: ");
    scanf("%s", Nombre);
    printf(" Apellido Paterno: ");
    scanf("%s", ApellidoPat);
    printf(" Email: ");
    scanf("%s", Email);

    sprintf(sql_statement, "SELECT descripcionc, fechacons FROM PF_consultas LEFT JOIN PF_pacientes USING (IDpaciente) WHERE Nombre = '%s' AND ApellidoPat = '%s' AND Email='%s'", Nombre, ApellidoPat, Email);

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