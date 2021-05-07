#include <mysql/mysql.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void Analisis(MYSQL *conU){
    unsigned int i;
    int opcion;
    char enter[5], Nombre[40], ApellidoPat[40], ApellidoMat[40], sql_statement[2048];

    MYSQL_RES *resUser;
    MYSQL_ROW rowUser;

    printf("\nEntraste a análisis");
    printf("\nEscoge al análisis que quieres revisar");
    printf("\n1)Enfermedad que mas afecta");
    printf("\n2)Pacientes que mas consultas tienen");
    printf("\n3)Historial de vacunacion de los pacientes");
    
    scanf("%i", &opcion);

    switch(opcion){
        case 1:
        mysql_query(conU, "SELECT COUNT(IDenfermedad),enfermedad FROM PF_consultas LEFT JOIN PF_enfermedad USING(IDenfermedad) GROUP BY IDenfermedad ORDER BY COUNT(IDenfermedad)DESC LIMIT 1");
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
        mysql_query(conU, "SELECT Nombre,ApellidoPat,ApellidoMat, COUNT(IDpaciente) FROM PF_consultas LEFT JOIN PF_pacientes USING(IDpaciente) GROUP BY IDpaciente ORDER BY COUNT(IDpaciente) DESC LIMIT 1");
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
        printf("\nNombre: ");
        scanf("%s", Nombre);
        printf("\nApellido Paterno: ");
        scanf("%s", ApellidoPat);
        printf("\nApellido Materno: ");
        scanf("%s", ApellidoMat);

        sprintf(sql_statement,"SELECT Vacunas,Fechava FROM PF_pacientes LEFT JOIN PF_pava USING(IDpaciente) LEFT JOIN PF_vacunas USING(IDvacunas) WHERE Nombre = '%s' AND ApellidoPat = '%s' AND ApellidoMat = '%s", Nombre, ApellidoPat, ApellidoMat);
        mysql_query(conU, "SELECT Nombre,ApellidoPat,ApellidoMat, COUNT(IDpaciente) FROM PF_consultas LEFT JOIN PF_pacientes USING(IDpaciente) GROUP BY IDpaciente ORDER BY COUNT(IDpaciente) DESC LIMIT 1");
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
    mysql_free_result(resUser);

    /* Necesitamos apretar una tecla para continuar */
    printf("\nSelecciona una tecla y aprieta enter\n");
    scanf(" %s", enter);
}