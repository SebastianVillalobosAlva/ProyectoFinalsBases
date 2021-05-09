#include <mysql/mysql.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void RegistrarConsulta(MYSQL *conU, char *name, char *pss){
    char Nombre[25], email[30], sql_statement[5000], enter[5];
    int IDpaciente, IDusuario;
    printf("\nIngresa el nombre del paciente: ");
    scanf("%s", Nombre);
    printf("\nIngresa el email del paciente: ");
    scanf("%s", email);

    MYSQL_RES *resUser;
    MYSQL_ROW rowUser;

    /* Obtener ID del paciente */
    //jasamelu@gmail.com
    sprintf(sql_statement,"SELECT IDpaciente FROM PF_pacientes WHERE Nombre = '%s' AND Email = '%s'", Nombre, email);
    // mysql_query(conU,"SELECT IDpaciente FROM PF_pacientes WHERE Nombre = 'Jaime' AND Email = 'jasamelu@gmail.com'");
    mysql_query(conU,sql_statement);
    resUser = mysql_store_result(conU);
    rowUser = mysql_fetch_row(resUser);
    IDpaciente = atoi(rowUser[0]);
    printf("Numero de ID: %i", IDpaciente);
    mysql_free_result(resUser);

    /* Obtener ID del usuario */
    sprintf(sql_statement,"SELECT IDusuario FROM PF_usuarios WHERE Nombreu = '%s' AND Contrasenau = '%s'", name, pss);
    mysql_query(conU,sql_statement);
    resUser = mysql_store_result(conU);
    rowUser = mysql_fetch_row(resUser);
    IDusuario = atoi(rowUser[0]);
    printf("Numero de ID: %i", IDusuario);
    mysql_free_result(resUser);


    printf("\nSelecciona una tecla y aprieta enter\n");
    scanf(" %s", enter);
}