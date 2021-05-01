#include <mysql/mysql.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Admin: name=Sebastian pss=1q2w3e4r5t
//User: name=Luis pss=1234

void Iniciar(MYSQL *conn, char *name, char *pss){
    char sql_statement[2048];
    _Bool user = 1;
    _Bool admin = 1;

    sprintf(sql_statement, "SELECT * FROM PF_admins WHERE Nombrea = '%s' AND Contrasenaa = '%s'", name, pss);
    if(mysql_query(conn, sql_statement) !=0){
        admin = 0;
        sprintf(sql_statement, "SELECT * FROM PF_usuarios WHERE Nombreu = '%s' AND Contrasenau = '%s'", name, pss);
        if(mysql_query(conn, sql_statement) !=0){
            user = 0;
            return;
        }
        user = 1;
    }
    if (admin){
        printf("Admin %s, signed in", name);
    }
    if (user){
        printf("User %s, signed in", name);
    }
}