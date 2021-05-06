#include <mysql/mysql.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void ChecarDiagnostico(MYSQL *conU){
    char enter[5], sql_statement[2048];
    int opcion = 0;
    unsigned int i;
    int opcion = 0;
    MYSQL_RES *resUser;
    MYSQL_ROW rowUser;

    printf("\nEntro a ChecarDiagnostico\n");

    mysql_query(conU,"SELECT IDdiagnostico, diagnostico  FROM PF_diags");
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
    printf(" ID diagnostico: ");
    scanf("%i", &opcion);

    sprintf(sql_statement, "SELECT * FROM PF_consultas LEFT JOIN PF_usuarios USING (IDusuario) WHERE IDdiagnostico = '%i", opcion);

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