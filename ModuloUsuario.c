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

void ModuloUsuario(MYSQL *conU, char *name, char *pss){
    system("clear");
    int opcion = 0;
    printf("\nEscoge la opcion que quieres realizar\n");
    printf("1) Registrar paciente\n");
    printf("2) Historial clinico de paciente\n"); //PF_meds //Todo se saca de consultas
    printf("3) Checar consultas por usuario\n"); //PF_consultas
    printf("4) Checar consultas por diagnostico\n"); //PF_diags
    printf("5) Modificar su usuario\n");
    printf("6) Ver mi usuario\n");
    printf("7) Buscar paciente\n");
    printf("8) Salir del programa\n");
    scanf("%i", &opcion);

    switch(opcion){
        case 1:
        printf("Escogiste la opcion 1\n");
        AgregarPaciente(conU);
        break;

        case 2:
        printf("Escogiste la opcion 2\n");
        HistorialClinico(conU);   
        break;

        case 3:
        printf("Escogiste la opcion 3\n");
        ChecarConsultas(conU);
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
        printf("Escogiste la opcion 7\n");
        BuscarPaciente(conU);
        break;

        case 8:
        return;
    }
    ModuloUsuario(conU, name, pss);
}