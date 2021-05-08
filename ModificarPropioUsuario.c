/***************************************************************
*  ModificarPropioUsuario - Permite cambiar cualquier aspecto  *
*                           del usuario cuya sesión se         *
*                           encuentra abierta                  *
*  Parámetros:                                                 *
*    MYSQL *conn - Conector de MYSQL                           *
*    char *name - Nombre del usuario                           *
*    char *pss - Contraseña del usuario                        *
*                                                              *
*  Valor de retorno:                                           * 
*    No hay valor de retorno                                   *
*                                                              *
***************************************************************/ 

#include <mysql/mysql.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void ModificarPropioUsuario(MYSQL *conU, char *name, char *pss){
    char enter[5], sql_statement[2048], Nombre[25], ApellidoPat[25], ApellidoMat[25], FechaNac[25], Email[30];
    int opcion, id;

    printf("\nEntro a Modificar Usuario\n");
    printf("\nDecide que deseas modificar de su usuario\n");
    printf("1) Nombre\n");
    printf("2) Apellido Paterno\n");
    printf("3) Apellido Materno\n");
    printf("4) Fecha Nacimiento\n");
    printf("5) Email\n");
    printf(" Dato a cambiar: ");
    scanf("%i", &opcion);

    switch(opcion){
        case 1:
        printf("Escogiste la opcion 1\n");
        printf("Nombre:");
        scanf(" %s", Nombre);
        sprintf(sql_statement, "UPDATE PF_usuarios SET Nombreu = '%s' WHERE Nombreu = '%s' AND Contrasenau = '%s'", Nombre, name, pss);
        mysql_query(conU,sql_statement);
        break;

        case 2:
        printf("Escogiste la opcion 2\n");
        printf("Apellido Paterno:");
        scanf(" %s", ApellidoPat);
        sprintf(sql_statement, "UPDATE PF_usuarios SET ApellidoPatu = '%s' WHERE Nombreu = '%s' AND Contrasenau = '%s'" , ApellidoPat, name, pss);
        mysql_query(conU,sql_statement);
        break;

        case 3:
        printf("Escogiste la opcion 3\n");
        printf("Apellido Materno:");
        scanf(" %s", ApellidoMat);
        sprintf(sql_statement, "UPDATE PF_usuarios SET ApellidoMatu = '%s'  WHERE Nombreu = '%s' AND Contrasenau = '%s'" , ApellidoMat, name, pss);
        mysql_query(conU,sql_statement);
        break;

        case 4:
        printf("Escogiste la opcion 4\n");
        printf("Fecha de nacimiento:");
        scanf(" %s", FechaNac);
        sprintf(sql_statement, "UPDATE PF_usuarios SET FechaNacu = '%s'  WHERE Nombreu = '%s' AND Contrasenau = '%s'" , FechaNac, name, pss);
        mysql_query(conU,sql_statement);
        break;

        case 5:
        printf("Escogiste la opcion 5\n");
        printf("Email:");
        scanf(" %s", Email);
        sprintf(sql_statement, "UPDATE PF_usuarios SET Emailu = '%s'  WHERE Nombreu = '%s' AND Contrasenau = '%s'" , Email, name, pss);
        mysql_query(conU,sql_statement);
        break;
    }
    
    printf("\nSelecciona una tecla y aprieta enter\n");
    scanf(" %s", enter);
}