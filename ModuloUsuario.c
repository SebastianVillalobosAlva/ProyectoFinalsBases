#include <mysql/mysql.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "AgregarPaciente.c"
#include "ModificarPropioUsuario.c"
#include "VerMiUsuario.c"

void ModuloUsuario(MYSQL *conU, char *name, char *pss){
    system("clear");
    int opcion = 0;
    printf("\nEscoge la opcion que quieres realizar\n");
    printf("1) Registrar paciente\n");
    printf("2) Historial clinico\n");
    printf("3) Checar consultas\n");
    printf("4) Checar diagnostico\n");
    printf("5) Modificar su usuario\n");
    printf("6) Ver mi usuario\n");
    printf("7) Salir del programa\n");
    scanf("%i", &opcion);

    switch(opcion){
        case 1:
        printf("Escogiste la opcion 1\n");
        AgregarPaciente(conU);
        break;

        case 2:
        printf("Escogiste la opcion 2\n");
        
        break;

        case 3:
        printf("Escogiste la opcion 3\n");
        
        break;

        case 4:
        printf("Escogiste la opcion 4\n");
        
        break;

        case 5:
        printf("Escogiste la opcion 5\n");
        ModificarPropioUsuario(conU, name, pss);
        break;

        case 6:
        printf("Escogiste la opcion 6\n");
        VerMiUsuario(conU, name, pss);
        break;

        case 7:
        return;
    }
    ModuloUsuario(conU, name, pss);
}