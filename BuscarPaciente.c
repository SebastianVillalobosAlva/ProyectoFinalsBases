/***************************************************************
*  BuscarPaciente - Nos permite buscar un paciente por su      *
*                   nombre, apellido materno, paterno, fecha   *
*                   de consulta. Al mismo tiempo, estas        *
*                   busquedas se guardan en la base de datos   *
*  Parámetros:                                                 *
*    MYSQL *conn - Conector de MYSQL                           *
*    char *name - Nombre del usuario                           *
*    c                                                         *
*                                                              *
*  Valor de retorno:                                           * 
*    No hay valor de retorno                                   *
*                                                              *
***************************************************************/ 

#include <mysql/mysql.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void BuscarPaciente(MYSQL *conU, char *name){
    char enter[5], sql_query[4056], sql_query_2[4056], sql_query_3[5000];
    char FechaNac[40], ApellidoPat[40], ApellidoMat[40], FechaConI[40], FechaConF[40], enfermedad[40];
    unsigned int i;
    int opcion = 0;
    MYSQL_RES *resPac;
    MYSQL_ROW rowPac;

    printf("\nEntro a BuscarPaciente\n");
    printf("\nDecide como quieres buscar al usuario\n");
    printf("1) Fecha de Nacimiento\n");
    printf("2) Apellido Paterno\n");
    printf("3) Apellido Materno\n");
    printf("4) Periodo de fechas de consulta\n");
    printf("5) Padecimiento\n");
    printf(" Forma de buscar: ");
    scanf("%i", &opcion);

    switch(opcion){
        case 1:
        printf(" FechaNac (2020-01-01): ");
        scanf("%s", FechaNac);
        sprintf(sql_query,"SELECT Nombre, ApellidoPat, ApellidoMat, FechaNac FROM PF_pacientes WHERE FechaNac = '%s'", FechaNac);
        mysql_query(conU,sql_query);
        resPac = mysql_store_result(conU);

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
        sprintf(sql_query_2, "Se busco al paciente con fecha de nacimiento %s", FechaNac);
        sprintf(sql_query_3, "INSERT INTO PF_registrobus (registro, NombreU) VALUES ('%s', '%s')", sql_query_2, name);
        mysql_query(conU,sql_query_3);
        break;

        case 2:
        printf(" Apellido Paterno: ");
        scanf("%s", ApellidoPat);
        sprintf(sql_query,"SELECT Nombre, ApellidoPat, ApellidoMat, FechaNac FROM PF_pacientes WHERE ApellidoPat = '%s'", ApellidoPat);
        mysql_query(conU,sql_query);
        resPac = mysql_store_result(conU);

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
        sprintf(sql_query_2, "Se busco al paciente con el apellido paterno %s", ApellidoPat);
        sprintf(sql_query_3, "INSERT INTO PF_registrobus (registro, NombreU) VALUES ('%s', '%s')", sql_query_2, name);
        mysql_query(conU,sql_query_3);
        break;

        case 3:
        printf(" Apellido Materno: ");
        scanf("%s", ApellidoMat);
        sprintf(sql_query,"SELECT Nombre, ApellidoPat, ApellidoMat, FechaNac FROM PF_pacientes WHERE ApellidoMat = '%s'", ApellidoMat);
        mysql_query(conU,sql_query);
        resPac = mysql_store_result(conU);

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
        sprintf(sql_query_2, "Se busco al paciente con el apellido materno %s", ApellidoMat);
        sprintf(sql_query_3, "INSERT INTO PF_registrobus (registro, NombreU) VALUES ('%s', '%s')", sql_query_2, name);
        mysql_query(conU,sql_query_3);
        break;

        case 4:
        printf(" Fecha inicial de consulta: ");
        scanf("%s", FechaConI);
        printf(" Fecha final de consulta: ");
        scanf("%s", FechaConF);
        sprintf(sql_query,"SELECT Nombre, ApellidoPat, ApellidoMat, fechacons FROM PF_consultas LEFT JOIN PF_pacientes USING (IDpaciente) WHERE fechacons BETWEEN '%s' AND '%s'", FechaConI, FechaConF);
        mysql_query(conU,sql_query);
        resPac = mysql_store_result(conU);

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
        sprintf(sql_query_2, "Se busco al paciente con fecha inicial %s y fecha final %s de consulta", FechaConI, FechaConF);
        sprintf(sql_query_3, "INSERT INTO PF_registrobus (registro, NombreU) VALUES ('%s', '%s')", sql_query_2, name);
        mysql_query(conU,sql_query_3);
        break;

        case 5:
        printf("Que padecimiento quieres buscar: \n");
        mysql_query(conU,"SELECT enfermedad FROM PF_enfermedad");
        resPac = mysql_store_result(conU);

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
        mysql_free_result(resPac);
        printf("\nEnfermedad: \n");
        scanf("%s", enfermedad);
        sprintf(sql_query,"SELECT Nombre, ApellidoPat, ApellidoMat FROM PF_consultas LEFT JOIN PF_pacientes USING(IDpaciente) LEFT JOIN PF_enfermedad USING(IDenfermedad) WHERE enfermedad = '%s' GROUP BY IDpaciente", enfermedad);
        mysql_query(conU,sql_query);
        resPac = mysql_store_result(conU);

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
        sprintf(sql_query_2, "Se busco a los pacientes con la enfermedad '%s'", enfermedad);
        sprintf(sql_query_3, "INSERT INTO PF_registrobus (registro, NombreU) VALUES ('%s', '%s')", sql_query_2, name);
        mysql_query(conU,sql_query_3);
        break;
    }
    mysql_free_result(resPac);

    printf("\nSelecciona una tecla y aprieta enter\n");
    scanf(" %s", enter);
}