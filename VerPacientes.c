#include <mysql/mysql.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void VerPacientes(MYSQL *conU){
    char enter[5];
    unsigned int i;
    MYSQL_RES *resPac;
    MYSQL_ROW rowPac;

    // sprintf(sql_statement,"SELECT * FROM PF_usuarios");
    printf("\nEntro a VerPacientes\n");
    mysql_query(conU,"SELECT Nombre, ApellidoPat, ApellidoMat FROM PF_pacientes");
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
    printf("\nSelecciona una tecla y aprieta enter\n");
    scanf(" %s", enter);
}