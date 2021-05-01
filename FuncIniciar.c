#include <mysql/mysql.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void Iniciar(MYSQL *conn, char *name, char *pss){
    char sql_statement[2048];

    sprintf(sql_statement, "SELECT * FROM PF_admins WHERE Nombrea = '%s' AND Contrasenaa = '%s'", name, pss);
    if(mysql_query(conn, sql_statement) !=0){
        printf("Query failed  with the following message:\n");
        printf("%s\n", mysql_error(conn));
        exit(1);
    }

    printf("User %s signed in\n", name);
}