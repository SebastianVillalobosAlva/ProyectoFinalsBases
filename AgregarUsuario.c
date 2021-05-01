#include <mysql/mysql.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void AgregarUsuario(MYSQL *conU){
    char Nombreu[40], ApellidoPatu[40], ApellidoMatu[40], Puesto[40], FechaNacu[40], Emailu[40], Contrasenau[40];
    char sql_statement[2048], enter[10];

    printf("\nPor favor llena la informacion del usuario que quiere agregar:\n");
    printf("Nombre:");
    scanf("%s", Nombreu);
    printf("Apellido Paterno:");
    scanf("%s", ApellidoPatu);
    printf("Apellido Materno:");
    scanf("%s", ApellidoMatu);
    printf("Puesto:");
    scanf("%s", Puesto);
    printf("Fecha de Nacimiento (2020-01-01):");
    scanf("%s", FechaNacu);
    printf("Emailu:");
    scanf("%s", Emailu);
    printf("Contaseña:");
    scanf("%s", Contrasenau);

    sprintf(sql_statement, "INSERT INTO PF_usuarios (Nombreu, ApellidoPatu, ApellidoMatu, puesto, FechaNacu, Emailu, Contrasenau) VALUES('%s','%s','%s','%s','%s','%s','%s')", Nombreu, ApellidoPatu, ApellidoMatu, Puesto, FechaNacu, Emailu, Contrasenau );
    mysql_query(conU,sql_statement);
    return;
    // printf("\nSelecciona una tecla y aprieta enter\n");
    // scanf(" %s", enter);
}