#include <stdio.h>//Funciones basicas de entrada salida
#include <locale.h>//Para presentar caracteres en español
#include <windows.h>//Para usar la funcion Sleep
#include "Cuestionarios.h"//Incluir el dato de tipo Cuestionario
/***

Archivo fuente para registrar respuestas de los estudiantes

***/

int responderCuestionario(char id[25]){

    char idCuestionario[10];

    printf("--------------------------------------------------------------\n");
    printf("Sistema de evaluaciones ISI - UCA - Responder un cuestionario \n");
    printf("--------------------------------------------------------------\n\n");

    printf("Cuestionarios disponibles: \n");
    printf("Id      Descripcion             Asignatura      Preguntas      \n");
    printf("0001    Evaluacion unidad I     Matematicas             9     \n");
    printf("0002    Unidad III y IV         Reflexión               5     \n\n\n");


    printf("Favor ingrese el id del cuestionario que va a contestar-->");
    scanf("%s",idCuestionario);
    system("cls");

    return 0;

}
