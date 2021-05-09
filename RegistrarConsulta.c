#include <mysql/mysql.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void RegistrarConsulta(MYSQL *conU){
    char Nombre[40], email[], sql_statement[5000];
    unsigned int i;
    printf("\nIngresa el nombre del paciente: ");
    scanf("%s", Nombre);
    printf("\nIngresa el email del paciente: ");
    scanf("%s", email);

    MYSQL_RES *resUser;
    MYSQL_ROW rowUser;

    sprintf(sql_statement,"SELECT IDpaciente FROM PF_pacientes WHERE Nombre = '%s' AND Email = '%s'", Nombre, email);
    mysql_query(conU,sql_statement);
    resUser = mysql_store_result(conU);
    
    while(rowUser = mysql_fetch_row(resUser)){
        i = 0;
        for(i=0; i < mysql_num_fields(resUser); i++){
            if(rowUser[i] != NULL){
                printf("%s", rowUser[i]);
                printf(" ");
                printf("\ni vale: %i", i);
            }
            else{
                printf(" \n");
            } 
        }
        printf("\n");
    }
}