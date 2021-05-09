#include <mysql/mysql.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void RegistrarConsulta(MYSQL *conU){
    char Nombre[25], email[30], sql_statement[5000], enter[5];
    int ID;
    printf("\nIngresa el nombre del paciente: ");
    scanf("%s", Nombre);
    printf("\nIngresa el email del paciente: ");
    scanf("%s", email);

    MYSQL_RES *resUser;
    MYSQL_ROW rowUser;

    sprintf(sql_statement,"SELECT IDpaciente FROM PF_pacientes WHERE Nombre = '%s' AND Email = '%s'", Nombre, email);
    // mysql_query(conU,"SELECT IDpaciente FROM PF_pacientes WHERE Nombre = 'Jaime' AND Email = 'jasamelu@gmail.com'");
    mysql_query(conU,sql_statement);
    resUser = mysql_store_result(conU);
    rowUser = mysql_fetch_row(resUser);
    printf("El ID es:");
    printf("%s", rowUser[0]);
    ID = atoi(rowUser[0]);
    printf("Numero de ID: %i", ID);
    mysql_free_result(resUser);
    printf("\nSelecciona una tecla y aprieta enter\n");
    scanf(" %s", enter);
}