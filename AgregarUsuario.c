#include <mysql/mysql.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void AgregarUsuario(MYSQL *conU){
    char Nombreu[25], ApellidoPatu[25], ApellidoMatu[25], Puesto[25], FechaNacu[15], Emailu[30], Contrasenau[30];
    char sql_statement[150], enter[5];

    printf("\nPor favor llena la informacion del usuario que quiere agregar:\n");
    printf("\n Nombre:");
    scanf(" %s", Nombreu);
    printf("\n Apellido Paterno:");
    scanf(" %s", ApellidoPatu);
    printf("\n Apellido Materno:");
    scanf(" %s", ApellidoMatu);
    printf("\n Puesto:");
    scanf(" %s", Puesto);
    printf("\n Fecha de Nacimiento (2020-01-01):");
    scanf(" %s", FechaNacu);
    printf("\n Emailu:");
    scanf(" %s", Emailu);
    printf("\n Contaseña:");
    scanf(" %s", Contrasenau);

    sprintf(sql_statement, "INSERT INTO PF_usuarios (Nombreu, ApellidoPatu, ApellidoMatu, puesto, FechaNacu, Emailu, Contrasenau) VALUES('%s','%s','%s','%s','%s','%s','%s')", Nombreu, ApellidoPatu, ApellidoMatu, Puesto, FechaNacu, Emailu, Contrasenau );
    mysql_query(conU,sql_statement);
    printf("\nSelecciona una tecla y aprieta enter\n");
    scanf(" %s", enter);
}