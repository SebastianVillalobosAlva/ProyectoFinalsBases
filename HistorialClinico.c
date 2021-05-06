#include <mysql/mysql.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void HistorialClinico(MYSQL *conU){
    char enter[5], sql_statement[2048], Nombre[40], ApellidoPat[40];
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

    sprintf(sql_statement, "SELECT * FROM PF_consultas LEFT JOIN PF_pacientes USING (IDpaciente) WHERE Nombre = '%s' AND ApellidoPat = '%s'", Nombre, ApellidoPat);

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
}