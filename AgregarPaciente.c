/***************************************************************
*  AgregarPaciente - Nos permite agregar un paciente           *
*                    a la base de datos                        *
*                                                              *
*  Parámetros:                                                 *
*    MYSQL *conn - Conector de MYSQL                           *
*                                                              *
*                                                              *
*  Valor de retorno:                                           * 
*    No hay valor de retorno                                   *
*                                                              *
***************************************************************/

#include <mysql/mysql.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void AgregarPaciente(MYSQL *conU){
    char Nombre[40], ApellidoPat[40], ApellidoMat[40], FechaNac[40], Email[40];
    char sql_statement[2048], enter[10];

    printf("\nPor favor llena la informacion del usuario que quiere agregar:\n");
    printf("Nombre:");
    scanf("%s", Nombre);
    printf("Apellido Paterno:");
    scanf("%s", ApellidoPat);
    printf("Apellido Materno:");
    scanf("%s", ApellidoMat);
    printf("Fecha de Nacimiento (2020-01-01):");
    scanf("%s", FechaNac);
    printf("Emailu:");
    scanf("%s", Email);

    sprintf(sql_statement, "INSERT INTO PF_pacientes (Nombre, ApellidoPat, ApellidoMat, FechaNac, Email) VALUES('%s','%s','%s','%s','%s')", Nombre, ApellidoPat, ApellidoMat, FechaNac, Email);
    mysql_query(conU,sql_statement);
    return;
    // printf("\nSelecciona una tecla y aprieta enter\n");
    // scanf(" %s", enter);
}