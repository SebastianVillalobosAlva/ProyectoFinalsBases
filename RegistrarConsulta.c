#include <mysql/mysql.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void RegistrarConsulta(MYSQL *conU, char *name, char *pss){
    char Nombre[25], email[30], descripcion[100], sql_query[10000], enter[5];
    int IDpaciente, IDusuario, IDmedicina, IDenfermedad, costo;
    unsigned int i;
    printf("\nIngresa el nombre del paciente: ");
    scanf("%s", Nombre);
    printf("Ingresa el email del paciente: ");
    scanf("%s", email);

    MYSQL_RES *resUser;
    MYSQL_ROW rowUser;

    /* Obtener ID del paciente */
    //jasamelu@gmail.com
    sprintf(sql_query,"SELECT IDpaciente FROM PF_pacientes WHERE Nombre = '%s' AND Email = '%s'", Nombre, email);
    mysql_query(conU,sql_query);
    resUser = mysql_store_result(conU);
    rowUser = mysql_fetch_row(resUser);
    IDpaciente = atoi(rowUser[0]);
    printf("\nNumero de IDpaciente: %i", IDpaciente);
    mysql_free_result(resUser);

    /* Obtener ID del usuario */
    sprintf(sql_query,"SELECT IDusuario FROM PF_usuarios WHERE Nombreu = '%s' AND Contrasenau = '%s'", name, pss);
    mysql_query(conU,sql_query);
    resUser = mysql_store_result(conU);
    rowUser = mysql_fetch_row(resUser);
    IDusuario = atoi(rowUser[0]);
    printf("\nNumero de IDusuario: %i\n\n", IDusuario);
    mysql_free_result(resUser);

    /* Obtener ID del medicamento */
    mysql_query(conU,"SELECT medicamento, IDmedicina FROM PF_meds");
    resUser = mysql_store_result(conU);
    printf("\n");

    while(rowUser = mysql_fetch_row(resUser)){
        i = 0;
        for(i=0; i < mysql_num_fields(resUser); i++){
            if(rowUser[i] != NULL){
                printf("%s", rowUser[i]);
                printf(" ");
            }
            else{
                printf(" \n");
            } 
        }
        printf("\n");
    }
    mysql_free_result(resUser);
    printf("\nEscoge la medicina (Numero): ");
    scanf(" %i", &IDmedicina);
    printf("\nEl IDmedicina es: %i\n\n", IDmedicina);

    /* Obtener ID de la enfermedad */
    mysql_query(conU,"SELECT enfermedad, IDenfermedad FROM PF_enfermedad");
    resUser = mysql_store_result(conU);
    printf("\n");

    while(rowUser = mysql_fetch_row(resUser)){
        i = 0;
        for(i=0; i < mysql_num_fields(resUser); i++){
            if(rowUser[i] != NULL){
                printf("%s", rowUser[i]);
                printf(" ");
            }
            else{
                printf(" \n");
            } 
        }
        printf("\n");
    }
    mysql_free_result(resUser);
    printf("\nEscoge la enfermedad (Numero): ");
    scanf(" %i", &IDenfermedad);
    printf("\nEl IDenfermedad es: %i\n", IDenfermedad);

    printf("Por favor ingrese la descripcion de la consulta:");
    scanf(" %[^\t\n]", descripcion);

    printf("Por favor ingrese el costo de la consulta: ");
    scanf("%i", &costo);
    // costo = atof(costo);

    sprintf(sql_query,"INSERT INTO PF_consultas (descripcionc, costo, IDpaciente, IDusuario, IDmedicina, IDenfermedad) VALUES ('%s','%i','%i','%i','%i','%i')", descripcion, costo,IDpaciente, IDusuario, IDmedicina, IDenfermedad);
    mysql_query(conU,sql_query);

    printf("\nSelecciona una tecla y aprieta enter\n");
    scanf(" %s", enter);
}