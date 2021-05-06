/****************************************************
* Main - Programa que nos va a permitir acceso a    *
*        nuestro sistema de bases de datos          *
*                                                   *
* Autores: Rafael Sebastian Villalobos Alva         *
*          Jaime Sanchez Mejorada Lupi              *
*          Javier Bettinger                         *
*                                                   *
* Propósito: Main del proyecto final de bases de    *
*            datos, el cual nos lleva a iniciar     *
*            sesión                                 *
*                                                   *
* Uso:                                              *
* Correr el sistema de bases de datos               *
*****************************************************/ 

//#include <mysql/mysql.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "FuncIniciarSesion.c"

int main(void){
    /* Borramos todo el contenido que hay en la terminal */
    system("clear");

    /* Llamamos a la función IniciarSesion() */
    IniciarSesion();
    return 0;
}