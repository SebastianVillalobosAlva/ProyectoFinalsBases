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
    char enter[5], sql_query[5000], sql_query2[5000];
    char Nombre[25], ApellidoPat[25], ApellidoMat[25], FechaNac[25], Email[30], Contrasenau[30];
    char name[40], apellido1[40], pss[40], email[40];
    
    MYSQL_RES *resUser;
    MYSQL_ROW rowUser;

    /* Declaramos la variable del contador y opcion */
    int opcion;

    /* Ponemos las opciones de lo que se puede modificar */
    printf("\nEntro a Modificar Usuario\n");
    printf("\nDecide que deseas modificar del usuario, debes proporcionar el numero de registro\n");
    printf("1) Nombre\n");
    printf("2) Apellido Paterno\n");
    printf("3) Apellido Materno\n");
    printf("4) Fecha Nacimiento\n");
    printf("5) Email\n");
    printf("6) Contraseña\n");

    /* Leemos el nombre y apellidos del usuario y lo que queremos cambiar */
    printf(" Nombre del usuario: ");
    scanf("%s", name);
    printf(" Apellido paterno del usuario: ");
    scanf("%s", apellido1);
    printf(" Email del usuario: ");
    scanf("%s", email);
    printf(" Contraseña del usuario: ");
    scanf("%s", pss);
    printf(" Dato a cambiar: ");
    scanf("%i", &opcion);

    switch(opcion){
        case 1:
        /* Leemos el nombre */
        printf("Escogiste la opcion 1\n");
        printf("Nombre:");
        scanf("%s", Nombre);

        /* Llenamos el query con el nombre y lo ejecutamos */
        sprintf(sql_query, "UPDATE PF_usuarios SET Nombreu = '%s' WHERE Nombreu = '%s' AND ApellidoPatu = '%s' AND Contrasenau = '%s' AND Emailu = '%s' ", Nombre, name, apellido1, pss, email);
        mysql_query(conU,sql_query);
        break;

        case 2:
        /* Leemos el apellido paterno */
        printf("Escogiste la opcion 2\n");
        printf("Apellido Paterno:");
        scanf("%s", ApellidoPat);

        /* Llenamos el query con el apellido paterno y lo ejecutamos */
        sprintf(sql_query, "UPDATE PF_usuarios SET ApellidoPatu = '%s' WHERE Nombreu = '%s' AND ApellidoPatu = '%s' AND Contrasenau = '%s' AND Emailu ='%s'" , ApellidoPat, name, apellido1, pss, email);
        mysql_query(conU,sql_query);
        break;

        case 3:
        /* Leemos el apellido materno */
        printf("Escogiste la opcion 3\n");
        printf("Apellido Materno:");
        scanf("%s", ApellidoMat);

        /* Llenamos el query con el apellido materno y lo ejecutamos */
        sprintf(sql_query, "UPDATE PF_usuarios SET ApellidoMatu = '%s' WHERE Nombreu = '%s' AND ApellidoPatu = '%s' AND Contrasenau = '%s' AND Emailu ='%s'" , ApellidoMat, name, apellido1, pss, email);
        mysql_query(conU,sql_query);
        break;

        case 4:
        /* Leemos la fecha de nacimiento */
        printf("Escogiste la opcion 4\n");
        printf("Fecha de nacimiento:");
        scanf("%s", FechaNac);

        /* Llenamos el query con la fecha de nacimiento y lo ejecutamos */
        sprintf(sql_query, "UPDATE PF_usuarios SET FechaNacu = '%s' WHERE Nombreu = '%s' AND ApellidoPatu = '%s' AND Contrasenau = '%s' AND Emailu ='%s'" , FechaNac, name, apellido1, pss, email);
        mysql_query(conU,sql_query);
        break;

        case 5:
        /* Leemos el nombre */
        printf("Escogiste la opcion 5\n");
        printf("Email:");
        scanf("%s", Email);

        /* Llenamos el query con el email y lo ejecutamos */
        sprintf(sql_query, "UPDATE PF_usuarios SET Emailu = '%s' WHERE Nombreu = '%s' AND ApellidoPatu = '%s' AND Contrasenau = '%s' AND Emailu ='%s'" , Email, name, apellido1, pss, email);
        mysql_query(conU,sql_query);
        break;

        case 6:
        printf("Escogiste la opcion 6\n");
        printf("Contraseña:");
        scanf("%s", Contrasenau);

        sprintf(sql_query, "UPDATE PF_usuarios SET Contrasenau = '%s' WHERE Nombreu = '%s' AND ApellidoPatu = '%s' AND Contrasenau = '%s' AND Emailu ='%s'" , Contrasenau, name, apellido1, pss, email);
        mysql_query(conU,sql_query);
        break;
    }
    
    /* Necesitamos apretar una tecla para continuar */
    printf("\nSelecciona una tecla y aprieta enter\n");
    scanf(" %s", enter);
}