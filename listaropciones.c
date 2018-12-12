#include <stdio.h>//Funciones basicas de entrada salida
#include <locale.h>//Para presentar caracteres en español
#include <windows.h>//Para usar la funcion Sleep
#include "Opciones.h"//Incluir el dato de tipo Opcion

int listarOpciones(char idCuestionario[10],char descCuestionario[100],char idUsuario[25],char idPregunta[10]){

    FILE *f;
    struct Opcion opcion;

    f = fopen("Opciones.txt","a");

    //Descripicon de la pregunta

    printf("-------------------------------------------------------------------\n");
    printf("Listado de opciones en pregunta %s\n", idPregunta);
    printf("Cuestionario %s\n", descCuestionario);
    printf("Usuario: %s\n", idUsuario);
    printf("-------------------------------------------------------------------\n");

    printf("%-10s%-60s%-10s\n","Respuesta", "Texto" ,"Correcta");

    while(fread(&opcion,sizeof(struct Opcion),1,f)){//Lee el archivo con el tamaño de la  estructura Opcion
        if (strcmp(idCuestionario, opcion.idCuestionario)==0 && strcmp(idUsuario,opcion.idUsuario)==0 && strcmp(idPregunta,opcion.idPregunta)==0){
            printf("%-10d%-60s%-10d\n",opcion.respuesta,opcion.texto,opcion.correcta);
        }
    }
    //Cierra el archivo
    fclose(f);
    system("pause");
    system("cls");

    return 0;


    return 0;
}
