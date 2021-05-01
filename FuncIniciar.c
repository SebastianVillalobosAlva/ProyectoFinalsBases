#include <mysql/mysql.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Admin: name=Sebastian pss=1q2w3e4r5t
//User: name=Luis pss=1234

void Iniciar(MYSQL *conn, char *name, char *pss){
    char sql_statement_admin[2048], sql_statement_user[2040];
    int user;
    int admin;

    printf("\nIniciando sesión");

    sprintf(sql_statement_admin, "SELECT * FROM PF_admins WHERE Nombrea = '%s' AND Contrasenaa = '%s'", name, pss);
    if(mysql_query(conn, sql_statement_admin) != 0){
        admin = 0;
        sprintf(sql_statement_user, "SELECT * FROM PF_usuarios WHERE Nombreu = '%s' AND Contrasenau = '%s'", name, pss);
        if(mysql_query(conn, sql_statement_user) != 0){
            user = 0;
            printf("\n Nadie inició sesión");
            return;
        }
        user = 1;
        printf("User %s, signed in\n", name);
        return;
    }
    admin = 1;
    if (admin == 1){
        printf("Admin %s, signed in\n", name);
    }
}