#include <mysql/mysql.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void BuscarPaciente(MYSQL *conU){
    char enter[5], sql_statement[4056], FechaNac[40], ApellidoPat[40], ApellidoMat[40], FechaConI[40], FechaConF[40];
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
    printf(" Forma de buscar: ");
    scanf("%i", &opcion);

    switch(opcion){
        case 1:
        printf(" FechaNac (2020-01-01): ");
        scanf("%s", FechaNac);
        sprintf(sql_statement,"SELECT Nombre, ApellidoPat, ApellidoMat, FechaNac FROM PF_pacientes WHERE FechaNac = '%s'", FechaNac);
        mysql_query(conU,sql_statement);
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
        break;

        case 2:
        printf(" Apellido Paterno: ");
        scanf("%s", ApellidoPat);
        sprintf(sql_statement,"SELECT Nombre, ApellidoPat, ApellidoMat, FechaNac FROM PF_pacientes WHERE ApellidoPat = '%s'", ApellidoPat);
        mysql_query(conU,sql_statement);
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
        break;

        case 3:
        printf(" Apellido Materno: ");
        scanf("%s", ApellidoMat);
        sprintf(sql_statement,"SELECT Nombre, ApellidoPat, ApellidoMat, FechaNac FROM PF_pacientes WHERE ApellidoMat = '%s'", ApellidoMat);
        mysql_query(conU,sql_statement);
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
        break;

        case 4:
        printf(" Fecha inicial de consulta: ");
        scanf("%s", FechaConI);
        printf(" Fecha final de consulta: ");
        scanf("%s", FechaConF);
        sprintf(sql_statement,"SELECT Nombre, ApellidoPat, ApellidoMat, fechacons FROM PF_consultas LEFT JOIN PF_pacientes USING (IDpaciente) WHERE fechacons BETWEEN '%s' AND '%s'", FechaConI, FechaConF);
        mysql_query(conU,sql_statement);
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
        break;
    }
    mysql_free_result(resPac);
    printf("\nSelecciona una tecla y aprieta enter\n");
    scanf(" %s", enter);
}