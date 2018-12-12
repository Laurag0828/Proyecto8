#include <stdio.h>//Funciones basicas de entrada salida
#include <locale.h>//Para presentar caracteres en español
#include <windows.h>//Para usar la funcion Sleep
#include "Usuarios.h"//Incluir el dato de tipo Cuestionario
/***

Archivo fuente para registrar respuestas de los estudiantes

***/

int responderCuestionario(char idUsuario[25]){

    FILE *f;
    struct Usuario usuario;
    char idDocente[25];


    printf("--------------------------------------------------------------\n");
    printf("Sistema de evaluaciones ISI - UCA - Responder un cuestionario \n");
    printf("%s %s\n","Usuario actual: ", idUsuario);
    printf("--------------------------------------------------------------\n\n");

    //consulta todos los usuarios que son docentes
    printf("-------------------------------------------------------------------\n");
    printf("Listado de docentes activos en el Sistema de evaluaciones ISI - UCA\n");
    printf("-------------------------------------------------------------------\n");
    f = fopen("Usuarios.txt","r");
    printf("%-20s%-20s%-20s\n","Id","Nombre","Rol");
    while(fread(&usuario,sizeof(struct Usuario),1,f)){//Lee el archivo con el tamaño de la  estructura Usuario
        if (strcmp("docente", usuario.rol)==0 && usuario.activo==1){
            printf("%-20s%-20s%-20s\n",usuario.id,usuario.nombre,usuario.rol);
        }
    }
    fclose(f);


    printf("\nFavor ingrese el id del docente del cuestionario-->");
    scanf("%s",idDocente);

    f = fopen("Usuarios.txt","r");
    printf("%-20s%-20s%-20s\n","Id","Nombre","Rol");
    while(fread(&usuario,sizeof(struct Usuario),1,f)){//Lee el archivo con el tamaño de la  estructura Usuario
        if (strcmp("docente", usuario.rol)==0 && usuario.activo==1){
            printf("%-20s%-20s%-20s\n",usuario.id,usuario.nombre,usuario.rol);
        }
    }
    fclose(f);

    return 0;

}
