/***************************************************************
*  ModificarUsuario - Nos permite modificar todos los aspectos *
*                     de un usuario                            *
*                                                              *
*  Parámetros:                                                 *
*    MYSQL *conn - Conector de MYSQL                           *
*                                                              *
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

void ModificarUsuario(MYSQL *conU){
    /* Declaramos la variables para agregar al usuario */
    char enter[5], sql_statement[2048], sql_statement2[2048];
    char Nombre[25], ApellidoPat[25], ApellidoMat[25], FechaNac[25], Email[30];
    char name[40], apellido1[40], pss[40];
    
    MYSQL_RES *resUser;
    MYSQL_ROW rowUser;

    /* Declaramos la variable del contador y opcion */
    int opcion, id;

    /* Ponemos las opciones de lo que se puede modificar */
    printf("\nEntro a Modificar Usuario\n");
    printf("\nDecide que deseas modificar del usuario, debes proporcionar el numero de registro\n");
    printf("1) Nombre\n");
    printf("2) Apellido Paterno\n");
    printf("3) Apellido Materno\n");
    printf("4) Fecha Nacimiento\n");
    printf("5) Email\n");

    /* Leemos el nombre y apellidos del usuario y lo que queremos cambiar */
    printf(" Nombre del usuario: ");
    scanf("%s", name);
    printf(" Apellido paterno del usuario: ");
    scanf("%s", apellido1);
    printf(" Contraseña del usuario: ");
    scanf("%s", pss);
    printf(" Dato a cambiar: ");
    scanf("%i", &opcion);

    sprintf(sql_statement2, "SELECT IDusuario FROM PF_usuarios WHERE Nombreu ='%s' AND ApellidoPatu = '%s' AND Contrasenau = '%s'", name, apellido1, pss);
    mysql_query(conU,sql_statement2);
    resUser = mysql_store_result(conU);
    rowUser = mysql_fetch_row(resUser);
    id = rowUser[0];
    printf("El ID del usuario es: ");
    printf("%i", id);
    mysql_free_result(resUser);

    switch(opcion){
        case 1:
        /* Leemos el nombre */
        printf("Escogiste la opcion 1\n");
        printf("Nombre:");
        scanf(" %s", Nombre);

        /* Llenamos el query con el nombre y lo ejecutamos */
        sprintf(sql_statement, "UPDATE PF_usuarios SET Nombreu = '%s' WHERE IDusuario = '%i'", Nombre, id);
        mysql_query(conU,sql_statement);
        break;

        case 2:
        /* Leemos el apellido paterno */
        printf("Escogiste la opcion 2\n");
        printf("Apellido Paterno:");
        scanf(" %s", ApellidoPat);

        /* Llenamos el query con el apellido paterno y lo ejecutamos */
        sprintf(sql_statement, "UPDATE PF_usuarios SET ApellidoPatu = '%s' WHERE IDusuario = '%i'" , ApellidoPat, id);
        mysql_query(conU,sql_statement);
        break;

        case 3:
        /* Leemos el apellido materno */
        printf("Escogiste la opcion 3\n");
        printf("Apellido Materno:");
        scanf(" %s", ApellidoMat);

        /* Llenamos el query con el apellido materno y lo ejecutamos */
        sprintf(sql_statement, "UPDATE PF_usuarios SET ApellidoMatu = '%s' WHERE IDusuario = '%i'" , ApellidoMat, id);
        mysql_query(conU,sql_statement);
        break;

        case 4:
        /* Leemos la fecha de nacimiento */
        printf("Escogiste la opcion 4\n");
        printf("Fecha de nacimiento:");
        scanf(" %s", FechaNac);

        /* Llenamos el query con la fecha de nacimiento y lo ejecutamos */
        sprintf(sql_statement, "UPDATE PF_usuarios SET FechaNacu = '%s' WHERE IDusuario = '%i'" , FechaNac, id);
        mysql_query(conU,sql_statement);
        break;

        case 5:
        /* Leemos el nombre */
        printf("Escogiste la opcion 5\n");
        printf("Email:");
        scanf(" %s", Email);

        /* Llenamos el query con el email y lo ejecutamos */
        sprintf(sql_statement, "UPDATE PF_usuarios SET Emailu = '%s' WHERE IDusuario = '%i'" , Email, id);
        mysql_query(conU,sql_statement);
        break;
    }
    
    /* Necesitamos apretar una tecla para continuar */
    printf("\nSelecciona una tecla y aprieta enter\n");
    scanf(" %s", enter);
}