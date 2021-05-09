#include <mysql/mysql.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void RegistrarConsulta(MYSQL *conU){
    char Nombre[40], email[40], sql_statement[5000];
    unsigned int i;
    printf("\nIngresa el nombre del paciente: ");
    scanf("%s", Nombre);
    printf("\nIngresa el email del paciente: ");
    scanf("%s", email);

    MYSQL_RES *resUser;
    MYSQL_ROW rowUser;

    sprintf(sql_statement,"SELECT IDpaciente FROM PF_pacientes WHERE Nombre = '%s' AND Email = '%s'", Nombre, email);
    mysql_query(conU,sql_statement);
    resUser = mysql_store_result(conU);
    rowUser = mysql_fetch_row(resUser);
    printf("%s", rowUser[0]);
    printf("%s", rowUser[0]);
    mysql_free_result(resUser);
}