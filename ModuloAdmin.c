/***************************************************************
*  ModuloAdmin - Despliega los diferente procesos que el admin *
*                puede llevar a cabo                           *
*                                                              *
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
#include "VerUsuarios.c"
#include "VerPacientes.c"
#include "AgregarUsuario.c"
#include "BuscarUsuario.c"
#include "ModificarUsuario.c"
#include "ModificarPaciente.c"

void ModuloAdmin(MYSQL *conM, char *name, char *pss){
    system("clear");
    /* Declaramos la variable de opcion a elegir */
    int opcion = 0;

    /* Imprimimos las diferentes opciones que se pueden realizar */
    printf("\nEscoge la opcion que quieres realizar\n");
    printf("1) Ver usuarios\n");
    printf("2) Ver pacientes\n");
    printf("3) Agregar usuarios\n");
    printf("4) Buscar por usuario\n");
    printf("5) Modificar usuario\n");
    printf("6) Modificar paciente\n");
    printf("7) Salir del programa\n");

    /* Leemos la opcion a realizar */
    scanf("%i", &opcion);

    /* Hacemos un switch para las diferentes opciones */
    switch(opcion){
        case 1:
        printf("Escogiste la opcion 1\n");
        /* Llamamos a la funcion VerUsuarios */
        VerUsuarios(conM);
        break;

        case 2:
        printf("Escogiste la opcion 2\n");
        /* Llamamos a la funcion VerPacientes */
        VerPacientes(conM);
        break;

        case 3:
        printf("Escogiste la opcion 3\n");
        /* Llamamos a la funcion AgregarUsuario */
        AgregarUsuario(conM);
        break;

        case 4:
        printf("Escogiste la opcion 4\n");
        /* Llamamos a la funcion BuscarUsuario */
        BuscarUsuario(conM);
        break;

        case 5:
        printf("Escogiste la opcion 5\n");
        /* Llamamos a la funcion ModificarUsuario */
        ModificarUsuario(conM);
        break;

        case 6:
        printf("Escogiste la opcion 6\n");
        /* Llamamos a la funcion ModificarPaciente */
        ModificarPaciente(conM);
        break;

        /* Rompemos el switch y regresamos a la funcion anterior */
        case 7:
        return;
    }
    /* Hacemos esta funcion recursiva al volverse a llamar a si misma */
    ModuloAdmin(conM, name, pss);
}