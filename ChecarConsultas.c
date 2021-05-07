/***************************************************************
*  ModuloAdmin - Despliega los diferente procesos que el user  *
*                puede llevar a cabo                           *
*                                                              *
*  Parámetros:                                                 *
*    MYSQL *conn - Conector de MYSQL                           *
*    char *name - Nombre del usuario                           *
*    char *pss - Contraseña del usuario                        *
*                                                              *
*  Valor de retorno:                                           * 
*    No hay valor de retorno                                   *
*                                                              *
***************************************************************/

#include <mysql/mysql.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void ChecarConsultas(MYSQL *conU){
    char enter[5], sql_statement[2048], Nombre[40], ApellidoPat[40];
    unsigned int i;
    int opcion = 0;
    MYSQL_RES *resUser;
    MYSQL_ROW rowUser;
    
    printf("\nEntro a ChecarConsultas\n");
    printf("Por favor ingresa el nombre y apellido paterno del usuario\n");
    printf(" Nombre: ");
    scanf("%s", Nombre);
    printf(" Apellido Paterno: ");
    scanf("%s", ApellidoPat);

    sprintf(sql_statement, "SELECT * FROM PF_consultas LEFT JOIN PF_usuarios USING (IDusuario) WHERE Nombreu = '%s' AND ApellidoPatu = '%s';", Nombre, ApellidoPat);

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
