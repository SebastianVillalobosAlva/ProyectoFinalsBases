#include <mysql/mysql.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ModuloAdmin.c"
#include "ModuloUsuario.c"

//Admin: name=Sebastian pss=1q2w3e4r5t
//User: name=Luis pss=1234

void Iniciar(MYSQL *conn, char *name, char *pss){
    system("clear");
    char sql_statement[100],sql_statement_u[100], enter[5];
    MYSQL_RES *resAdmin, *resUser;
    MYSQL_ROW rowAdmin, rowUser;

    sprintf(sql_statement,"SELECT * FROM PF_admins WHERE Nombrea='%s' AND Contrasenaa='%s'", name, pss);
    mysql_query(conn,sql_statement);
    resAdmin = mysql_store_result(conn);
    rowAdmin = mysql_fetch_row(resAdmin);

    if(rowAdmin != NULL){
        printf("Admin %s, signed in\n", rowAdmin[1]);
        mysql_free_result(resAdmin);
        scanf(" %s", enter);
        ModuloAdmin(conn, name, pss);
    }
    else{
        sprintf(sql_statement_u,"SELECT * FROM PF_usuarios WHERE Nombreu='%s' AND Contrasenau='%s'", name, pss);
        mysql_query(conn,sql_statement_u);
        resUser = mysql_store_result(conn);
        rowUser = mysql_fetch_row(resUser);
        
         if(rowUser != NULL){
        printf("User %s, signed in", rowUser[1]);
        mysql_free_result(resUser);
        scanf(" %s", enter);
        ModuloUsuario(conn, name, pss);
        }
    }

}