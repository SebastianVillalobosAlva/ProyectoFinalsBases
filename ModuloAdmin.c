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
    int opcion = 0;
    printf("\nEscoge la opcion que quieres realizar\n");
    printf("1) Ver usuarios\n");
    printf("2) Ver pacientes\n");
    printf("3) Agregar usuarios\n");
    printf("4) Buscar por usuario\n");
    printf("5) Modificar usuario\n");
    printf("6) Modificar paciente\n");
    printf("7) Salir del programa");
    scanf("%i", &opcion);

    switch(opcion){
        case 1:
        printf("Escogiste la opcion 1\n");
        VerUsuarios(conM);
        break;

        case 2:
        printf("Escogiste la opcion 2\n");
        VerPacientes(conM);
        break;

        case 3:
        printf("Escogiste la opcion 3\n");
        AgregarUsuario(conM);
        break;

        case 4:
        printf("Escogiste la opcion 4\n");
        BuscarUsuario(conM);
        break;

        case 5:
        printf("Escogiste la opcion 5\n");
        ModificarUsuario(conM);
        break;

        case 6:
        printf("Escogiste la opcion 6\n");
        ModificarPaciente(conM);
        break;

        case 7:
        return;
    }
    ModuloAdmin(conM, name, pss);
}