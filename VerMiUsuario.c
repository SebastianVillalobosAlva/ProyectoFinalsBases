/***************************************************************
*  VerMiUsuario - Permite ver todos los aspectos del usuario   *
*                 cuya sesión se encuentra abierta             *
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

void VerMiUsuario(MYSQL *conU, char *name, char *pss){
    char enter[5], sql_statement[5000];
    unsigned int i;
    int IDusuario;
    MYSQL_RES *resUser;
    MYSQL_ROW rowUser;

    sprintf(sql_statement,"SELECT IDusuario FROM PF_usuarios WHERE Nombre = '%s' AND Contrasenau = '%s'", name, pss);
    mysql_query(conU,sql_statement);
    resUser = mysql_store_result(conU);
    rowUser = mysql_fetch_row(resUser);
    IDusuario = atoi(rowUser[0]);
    mysql_free_result(resUser);

    sprintf(sql_statement,"SELECT Nombreu, ApellidoPatu, ApellidoMatu, FechaNacu, Emailu, Contrasenau FROM PF_usuarios WHERE IDusuario = '%i", IDusuario);
    printf("\nEntro a VerMiUsuario\n");
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