/***************************************************************
*  ModuloAdmin - Despliega los diferente procesos que el user  *
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
#include "AgregarPaciente.c"
#include "ModificarPropioUsuario.c"
#include "VerMiUsuario.c"
#include "BuscarPaciente.c"
#include "HistorialClinico.c"
#include "ChecarConsultas.c"
#include "ChecarDiagnostico.c"

void ModuloUsuario(MYSQL *conU, char *name, char *pss){
    system("clear");
    /* Declaramos la variable de opcion a elegir */
    int opcion = 0;

    /* Imprimimos las diferentes opciones que se pueden realizar */
    printf("\nEscoge la opcion que quieres realizar\n");
    printf("1) Registrar paciente\n");
    printf("2) Historial clinico de paciente\n"); //PF_meds //Todo se saca de consultas
    printf("3) Checar consultas por usuario\n"); //PF_consultas
    printf("4) Checar consultas por diagnostico\n"); //PF_diags
    printf("5) Modificar su usuario\n");
    printf("6) Ver mi usuario\n");
    printf("7) Buscar paciente\n");
    printf("8) Salir del programa\n");

    /* Leemos la opcion a realizar */
    scanf("%i", &opcion);

    /* Hacemos un switch para las diferentes opciones */
    switch(opcion){
        case 1:
        printf("Escogiste la opcion 1\n");
        /* Llamamos a la funcion AgregarPaciente */
        AgregarPaciente(conU);
        break;

        case 2:
        printf("Escogiste la opcion 2\n");
        /* Llamamos a la funcion HistorialClinico */
        HistorialClinico(conU);   
        break;

        case 3:
        printf("Escogiste la opcion 3\n");
        /* Llamamos a la funcion ChecarConsultas */
        ChecarConsultas(conU);
        break;

        case 4:
        printf("Escogiste la opcion 4\n");
        /* Llamamos a la funcion ChecarDiagnostico */
        ChecarDiagnostico(conU);
        break;

        case 5:
        printf("Escogiste la opcion 5\n");
        /* Llamamos a la funcion ModificarPropioUsuario */
        ModificarPropioUsuario(conU, name, pss);
        break;

        case 6:
        printf("Escogiste la opcion 6\n");
        /* Llamamos a la funcion VerMiUsuario */
        VerMiUsuario(conU, name, pss);
        break;

        case 7:
        printf("Escogiste la opcion 7\n");
        /* Llamamos a la funcion BuscarPaciente */
        BuscarPaciente(conU, name);
        break;

        /* Rompemos el switch y regresamos a la funcion anterior */
        case 8:
        return;
    }
    /* Hacemos esta funcion recursiva al volverse a llamar a si misma */
    ModuloUsuario(conU, name, pss);
}