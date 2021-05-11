/***************************************************************
*  Iniciar - Inicia sesión en nuestro sistema (admin, usuario) *
*            Manda al modulo dependiendo el tipo de usuario    *
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
#include "ModuloAdmin.c"
#include "ModuloUsuario.c"

//Admin: name=Sebastian pss=1q2w3e4r5t
//User: name=Luis pss=1234

void Iniciar(MYSQL *conn, char *name, char *pss){
    /* Limpiamos la terminal */
    system("clear");

    /* Variables de MYSQL y queries */
    char sql_statement[100],sql_statement_u[100], enter[5];
    MYSQL_RES *resAdmin, *resUser;
    MYSQL_ROW rowAdmin, rowUser;

    /* Concatenamos el nombre y contraseña a nuestro query de administrador */
    sprintf(sql_statement,"SELECT * FROM PF_admins WHERE Nombrea='%s' AND Contrasenaa='%s'", name, pss);

    /* Realizamos el query y obtenemos el resultado */
    mysql_query(conn,sql_statement);
    resAdmin = mysql_store_result(conn);
    rowAdmin = mysql_fetch_row(resAdmin);

    /* Si existe el registro de administrador, iniciamos sesión*/
    if(rowAdmin != NULL){
        printf("Admin %s, signed in\n", rowAdmin[1]);
        mysql_free_result(resAdmin);
        scanf(" %s", enter);
        ModuloAdmin(conn, name, pss);
    }
    /* Si no existe el registro de administrador checamos si existe el registro de usuario */
    else{
        /* Concatenamos el nombre y contraseña a nuestro query de usuario */
        sprintf(sql_statement_u,"SELECT * FROM PF_usuarios WHERE Nombreu='%s' AND Contrasenau='%s'", name, pss);
        
        /* Realizamos el query y obtenemos el resultado */
        mysql_query(conn,sql_statement_u);
        resUser = mysql_store_result(conn);
        rowUser = mysql_fetch_row(resUser);
        
        /* Si existe el registro de usuario, iniciamos sesión*/
        if(rowUser != NULL){
        printf("User %s, signed in\n", rowUser[1]);
        mysql_free_result(resUser);
        scanf(" %s", enter);
        ModuloUsuario(conn, name, pss);
        }
    }
}