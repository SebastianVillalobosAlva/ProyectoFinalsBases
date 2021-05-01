#include <mysql/mysql.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Admin: name=Sebastian pss=1q2w3e4r5t
//User: name=Luis pss=1234

void Iniciar(MYSQL *conn, char *name, char *pss){
    char sql_statement[2048];
    _Bool user;
    _Bool admin = true;

    sprintf(sql_statement, "SELECT * FROM PF_admins WHERE Nombrea = '%s' AND Contrasenaa = '%s'", name, pss);
    if(mysql_query(conn, sql_statement) !=0){
        admin = false;
        sprintf(sql_statement, "SELECT * FROM PF_admins WHERE Nombrea = '%s' AND Contrasenaa = '%s'", name, pss);
        if(mysql_query(conn, sql_statement) !=0){
            user = false;
            return;
        }
        user = true;
    }
    if (admin){
        printf("Admin %s, signed in", name);
    }
    if (user){
        printf("User %s, signed in", name);
    }
}