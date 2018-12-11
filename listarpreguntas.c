#include <stdio.h>//Funciones basicas de entrada salida
#include <locale.h>//Para presentar caracteres en español
#include <windows.h>//Para usar la funcion Sleep
#include "Preguntas.h"//Incluir el dato de tipo Pregunta
#include "Cuestionarios.h"



int listarPreguntas(char idCuestionario[10])
{
    FILE *f;
    struct Pregunta Pregunta;

    f = fopen("Preguntas.txt","r");

    printf("-------------------------------------------------------------------\n");
    printf("Listado de preguntas en el cuestionario %i", Pregunta.idCuestionario);
    printf("-------------------------------------------------------------------\n");

    printf("%-10s%-60s%-20s%10s%10s\n","Id","Descripcion","Cantidad Opciones","Puntaje");

    while(fread(&Pregunta,sizeof(struct Pregunta),1,f)){//Lee el archivo con el tamaño de la  estructura Pregunta
        printf("%-10s%-60s%-20s%10d%10d\n",Pregunta.idPregunta,Pregunta.texto,Pregunta.cantOpciones,Pregunta.puntos);
    }
    //Cierra el archivo
    fclose(f);
    system("pause");
    system("cls");
    return 0;
}
