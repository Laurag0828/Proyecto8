#include <stdio.h>//Funciones basicas de entrada salida
#include <locale.h>//Para presentar caracteres en español
#include <windows.h>//Para usar la funcion Sleep
#include "Preguntas.h"//Incluir el dato de tipo Pregunta
#include "Cuestionarios.h"//Incluir el dato de tipo Cuestionario



int listarPreguntas(char idCuestionario[10])
{
    FILE *f;
    struct Pregunta pregunta;

    f = fopen("Preguntas.txt","r");

    printf("-------------------------------------------------------------------\n");
    printf("Listado de preguntas en el cuestionario %s\n", idCuestionario);
    printf("-------------------------------------------------------------------\n");

    printf("%-10s%-60s%-20s%10s\n","Id","Descripción","Cantidad Opciones","Puntaje");



    while(fread(&pregunta,sizeof(struct Pregunta),1,f)){//Lee el archivo con el tamaño de la  estructura Pregunta
        printf("%-10s%-60s%10d%10d\n",pregunta.idPregunta,pregunta.texto,pregunta.cantOpciones,pregunta.puntos);
    }
    //Cierra el archivo
    fclose(f);
    system("pause");
    system("cls");

    return 0;


    /*FILE *f; //Apuntador para abrir archivos
    struct Cuestionario cuestionario; //Para manejo del cuestionario
    //consulta todos los cuestionarios
    printf("-------------------------------------------------------------------\n");
    printf("Listado de cuestionarios en el Sistema de evaluaciones ISI - UCA\n");
    printf("-------------------------------------------------------------------\n");
    //Abre el archivo

    f = fopen("Cuestionarios.txt","r");
    printf("%-10s%-60s%-20s%10s%10s\n","Id","Descripcion","Asignatura","No. preguntas","Activo");
    while(fread(&cuestionario,sizeof(struct Cuestionario),1,f)){//Lee el archivo con el tamaño de la  estructura Cuestionario
        printf("%-10s%-60s%-20s%10d%10d\n",cuestionario.idCuestionario,cuestionario.descripcion,cuestionario.asignatura,cuestionario.cantPreg,cuestionario.activo);
    }
    //Cierra el archivo
    fclose(f);
    system("pause");
    system("cls");
    return 0;*/
}
