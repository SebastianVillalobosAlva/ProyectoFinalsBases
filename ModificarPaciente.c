#include <mysql/mysql.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void ModificarPaciente(MYSQL *conU){
    char enter[5], sql_statement[2048], Nombre[25], ApellidoPat[25], ApellidoMat[25], FechaNac[25], Email[30];
    int opcion, id;

    printf("\nEntro a Modificar Paciente\n");
    printf("\nDecide que deseas modificar del paciente, debes proporcionar el numero de registro\n");
    printf("1) Nombre\n");
    printf("2) Apellido Paterno\n");
    printf("3) Apellido Materno\n");
    printf("4) Fecha Nacimiento\n");
    printf("5) Email\n");
    printf(" Numero de registro (ID): ");
    scanf("%i", &id);
    printf(" Dato a cambiar: ");
    scanf("%i", &opcion);
    switch(opcion){
        case 1:
        printf("Escogiste la opcion 1\n");
        printf("Nombre:");
        scanf(" %s", Nombre);
        sprintf(sql_statement, "UPDATE PF_pacientes SET Nombre = '%s' WHERE IDpaciente = '%i'", Nombre, id);
        mysql_query(conU,sql_statement);
        break;

        case 2:
        printf("Escogiste la opcion 2\n");
        printf("Apellido Paterno:");
        scanf(" %s", ApellidoPat);
        sprintf(sql_statement, "UPDATE PF_pacientes SET ApellidoPat = '%s' WHERE IDpaciente = '%i'" , ApellidoPat, id);
        mysql_query(conU,sql_statement);
        break;

        case 3:
        printf("Escogiste la opcion 3\n");
        printf("Apellido Materno:");
        scanf(" %s", ApellidoMat);
        sprintf(sql_statement, "UPDATE PF_pacientes SET ApellidoMat = '%s' WHERE IDpaciente = '%i'" , ApellidoMat, id);
        mysql_query(conU,sql_statement);
        break;

        case 4:
        printf("Escogiste la opcion 4\n");
        printf("Fecha de nacimiento:");
        scanf(" %s", FechaNac);
        sprintf(sql_statement, "UPDATE PF_pacientes SET FechaNac = '%s' WHERE IDpaciente = '%i'" , FechaNac, id);
        mysql_query(conU,sql_statement);
        break;

        case 5:
        printf("Escogiste la opcion 5\n");
        printf("Email:");
        scanf(" %s", Email);
        sprintf(sql_statement, "UPDATE PF_pacientes SET Emailu = '%s' WHERE IDpaciente = '%i'" , Email, id);
        mysql_query(conU,sql_statement);
        break;
    }
    
    printf("\nSelecciona una tecla y aprieta enter\n");
    scanf(" %s", enter);
}