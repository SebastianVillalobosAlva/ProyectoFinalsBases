#include <mysql/mysql.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Admin: name=Sebastian pss=1q2w3e4r5t
//User: name=Luis pss=1234

void Iniciar(MYSQL *conn, char *name, char *pss){
    char sql_statement[100];
    int mysqlStatus = 0;
    unsigned int i = 0;
    unsigned int num_fields;
    MYSQL_RES *res;
    MYSQL_ROW row;
    MYSQL_FIELD *fields;

    sprintf(sql_statement,"SELECT * FROM PF_admins WHERE Nombrea='%s' AND Contrasenaa='%s'", name, pss);
    mysql_query(conn,sql_statement);
    res = mysql_store_result(conn);

    while((row = mysql_fetch_row(res))){
        i = 0;
        for(i=0; i<mysql_num_fields(res); i++){
            if(row[i] != NULL){
                printf("%s ", row[i]);
            }
        }
    }
}