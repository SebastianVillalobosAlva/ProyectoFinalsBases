#include <mysql/mysql.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Admin: name=Sebastian pss=1q2w3e4r5t
//User: name=Luis pss=1234

void Iniciar(MYSQL *conn, char *name, char *pss){
    char sql_statement_admin[2048]; //, sql_statement_user[2048];
    printf("\nIniciando sesión\n");

    sprintf(sql_statement_admin, "SELECT IDadmin FROM PF_admins WHERE Nombrea = '%s' AND Contrasenaa = '%s'", name, pss);
    printf("%s\n", sql_statement_admin);
    printf("\nAdmin query:");
    mysql_query(conn, sql_statement_admin);
    printf("%i\n", mysql_query(conn, sql_statement_admin));
}