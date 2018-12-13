#include <stdio.h>//Funciones basicas de entrada salida
#include <locale.h>//Para presentar caracteres en español
#include <windows.h>//Para usar la funcion Sleep
#include "Calificaciones.h"//Incluir el dato de tipo Calificacion



int listarMisNotas(char idUsuario[25])
{
    FILE *f;
    struct Calificacion calificacion;

    f = fopen("Calificaciones.txt","r");

    printf("-------------------------------------------------------------------\n");
    printf("Listado de mis notas %s\n", idUsuario);
    printf("-------------------------------------------------------------------\n");
    fflush(stdout);

    printf("%-25s%-10s%-10s%-10s%-10s\n","Doc","Cues","Puntaje","Total","Porcentaje");
    fflush(stdout);

    while(fread(&calificacion,sizeof(struct Calificacion),1,f)){//Lee el archivo con el tamaño de la  estructura Pregunta
        if (strcmp(idUsuario, calificacion.idEstudiante)==0){
            printf("%-25s%-10s%-10d%-10d%-10.2f\n",calificacion.idDocente,calificacion.idCuestionario, calificacion.puntosObtenidos,calificacion.puntosTotal,calificacion.porcentaje);
            fflush(stdout);
        }
    }
    //Cierra el archivo
    fclose(f);
    system("pause");
    system("cls");

    return 0;
}
