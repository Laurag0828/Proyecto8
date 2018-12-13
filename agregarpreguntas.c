#include <stdio.h>//Funciones basicas de entrada salida
#include <locale.h>//Para presentar caracteres en español
#include <windows.h>//Para usar la funcion Sleep
#include "Preguntas.h"//Incluir el dato de tipo Pregunta
#include "Cuestionarios.h"//Incluir el dato de tipo cuestionario

int agregarPreguntas(char idCuestionario[10],char idUsuario[25]){

    FILE *fPregunta; //Apuntador para abrir archivos
    struct Pregunta pregunta; //Para manejo de la pregunta

    //Abre el archivo de preguntas para agregar
    fPregunta = fopen("Preguntas.txt","a");
    printf("-------------------------------------------------------\n");
    printf("Agregar pregunta al cuestionario %s\n",idCuestionario);
    printf("-------------------------------------------------------\n");
    fflush(stdout);
    //copia el id del cuestionario en la pregunta
    strcpy(pregunta.idCuestionario,idCuestionario);
    strcpy(pregunta.idUsuario,idUsuario);//copia el usuario
    fflush(stdin);
    //pedir datos al usuario actual
    printf("Ingrese el id de la pregunta-->");
    fflush(stdout);
    scanf("%s",pregunta.idPregunta);
    fflush(stdin);
    printf("Ingrese el texto de la pregunta-->");
    fflush(stdout);
    gets(pregunta.texto);
    fflush(stdin);
    printf("Ingrese la cantidad de opciones-->");
    fflush(stdout);
    scanf("%d",&pregunta.cantOpciones);
    fflush(stdin);
    printf("Ingrese cuantos puntos vale la pregunta-->");
    fflush(stdout);
    scanf("%d",&pregunta.puntos);
    fflush(stdin);
    //Escribir la pregunta en el archivo
    fwrite(&pregunta, sizeof(pregunta),1,fPregunta);
    fclose(fPregunta);
    fPregunta=NULL;

    system("cls");

    return 0;
}
