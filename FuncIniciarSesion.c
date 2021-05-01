#include <mysql/mysql.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "FuncIniciar.c"

void IniciarSesion(){
    // Variables de MySQL
    char *server = "localhost";
    char *user = "mp15lsm";
    char *passwd = "195573";
    char *db = "mp15lsm";

    //Variables de inicio de sesion
    char nombre[25];
    char psswrd[30];

    printf("\nInicia Sesion");

    printf("\n Usuario:");
    scanf(" %s", nombre);

    printf(" Contraseña:");
    scanf(" %s", psswrd);
    
    MYSQL *con;
    con = mysql_init(NULL);

    if(mysql_real_connect(con, server, user, passwd, db, 0, NULL, 0) == NULL)
    {
        printf("The authentication failed with the following message:\n");
        printf("%s\n", mysql_error(con));
        exit(1);
    }
    printf("The connection is open\n");
    
    Iniciar(con, nombre, psswrd);
    mysql_close(con);
}