#include <mysql/mysql.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Admin: name=Sebastian pss=1q2w3e4r5t
//User: name=Luis pss=1234

void Iniciar(MYSQL *conn, char *name, char *pss){
    char sql_statement[100];
    int mysqlStatus = 0;
    MYSQL_RES *mysqlResult = NULL;
    MYSQL_ROW mysqlRow;
	MYSQL_FIELD *mysqlFields;
	my_ulonglong numRows;
	unsigned int numFields;
    sprintf(sql_statement,"SELECT * FROM PF_admins WHERE Nombrea='%s' AND Contrasenaa='%s'", name, pss);

     mysqlStatus = mysql_query(conn, sql_statement);

     if (mysqlStatus){
        exit(1);
     }
    else{
    mysqlResult = mysql_store_result(conn);
    }

    while(mysqlRow = mysql_fetch_row(mysqlResult)) // row pointer in the result set
    {
	    for(int ii=0; ii < numFields; ii++)
	        {
	            printf("%s\t", mysqlRow[ii] ? mysqlRow[ii] : "NULL");  // Not NULL then print
	        }
	            printf("\n");
	}


}