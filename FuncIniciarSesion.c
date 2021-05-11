/***************************************************************
*  IniciarSesion - Captura el nombre y contraseña del usuario. *
*                  Establece la conexión a MySQL               *
*                                                              *
*  Parámetros:                                                 *
*            No recibe ningún parametro                        *
*                                                              *
*  Valor de retorno:                                           *
*    No regresa algún valor                                    *
*                                                              *
***************************************************************/ 

#include <mysql/mysql.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "FuncIniciar.c"

void IniciarSesion(int intentos){
    /* Variables de MySQL para conectarnos a la base de datos 
    (servidor, usuario, password y base de datos)*/
    char *server = "localhost";
    char *user = "mp15lsm";
    char *passwd = "195573";
    char *db = "mp15lsm";

    //Variables de inicio de sesion (nombre, password)
    char nombre[25];
    char psswrd[30];

    char sql_statement[100],sql_statement_u[100], enter[5];
    MYSQL_RES *resAdmin, *resUser;
    MYSQL_ROW rowAdmin, rowUser;

    printf("Inicia Sesion");

    /* Obtenemos el input del nombre del usuario */
    printf("\n Usuario:");
    scanf("%s", nombre);

    /* Obtenemos el input de la contraseña del usuario */
    printf(" Contraseña:");
    scanf("%s", psswrd);
    
    /* Variables de MySQL */
    MYSQL *con;
    MYSQL *conRet;

    /* Iniciamos la conexion a MySQL */
    con = mysql_init(NULL);

    /* Nos conectamos al usuario de MySQL y a la base de datos */
    conRet = mysql_real_connect(con, server, user, passwd, db, 0, NULL, 0);

    /* Checar si se logró la conexión a la base de datos */
    if(conRet == NULL)
    {
        printf("The authentication failed with the following message:\n");
        printf("%s\n", mysql_error(conRet));
        exit(1);
    }
    printf("The connection is open\n");

    if (intentos < 3){
        sprintf(sql_statement,"SELECT * FROM PF_admins WHERE Nombrea='%s' AND Contrasenaa='%s'", nombre, psswrd);
        mysql_query(con,sql_statement);
        resAdmin = mysql_store_result(con);
        rowAdmin = mysql_fetch_row(resAdmin);

        /* Si existe el registro de administrador, iniciamos sesión*/
        if(rowAdmin != NULL){
            Iniciar(con, nombre, psswrd);
        }
        /* Si no existe el registro de administrador checamos si existe el registro de usuario */
        else{
            /* Concatenamos el nombre y contraseña a nuestro query de usuario */
            sprintf(sql_statement_u,"SELECT * FROM PF_usuarios WHERE Nombreu='%s' AND Contrasenau='%s'", nombre, psswrd);
            
            /* Realizamos el query y obtenemos el resultado */
            mysql_query(con,sql_statement_u);
            resUser = mysql_store_result(con);
            rowUser = mysql_fetch_row(resUser);
            
            /* Si existe el registro de usuario, iniciamos sesión*/
            if(rowUser != NULL){
                Iniciar(con, nombre, psswrd);
            }
            if(rowUser == NULL){
                printf("Te quedan %i intentos", intentos);
                intentos++;
                IniciarSesion(intentos);
            }
        }
    }
    /* Llamamos a la función Iniciar(), esta recibe el conector, 
    nombre y contraseña de la persona que quiere iniciar sesión */
    // Iniciar(con, nombre, psswrd);

    /* Cerramos el conector */
    mysql_close(con);
    printf("\nCon cerrado\n");
}