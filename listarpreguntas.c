#include <stdio.h>//Funciones basicas de entrada salida
#include <locale.h>//Para presentar caracteres en espa�ol
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

    printf("%-10s%-10s%-60s%-10s%-10s\n","Cuest","Id","Descripci�n","Opciones","Puntaje");

    while(fread(&pregunta,sizeof(struct Pregunta),1,f)){//Lee el archivo con el tama�o de la  estructura Pregunta
        if (strcmp(idCuestionario, pregunta.idCuestionario)==0){
            printf("%-10s%-10s%-60s%-10d%-10d\n",pregunta.idCuestionario,pregunta.idPregunta,pregunta.texto,pregunta.cantOpciones,pregunta.puntos);
        }
    }
    //Cierra el archivo
    fclose(f);
    system("pause");
    system("cls");

    return 0;
}
