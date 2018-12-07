/******

Estructura opcion para almacenar datos de las opciones en las preguntas



******/
#ifndef OPCIONES_H_INCLUDED
#define OPCIONES_H_INCLUDED

struct Opcion
{
    char idCuestionario[10];
    char idPregunta[10];
    char opcion; //caracter que se almacenara como respuesta
    char texto[500]; //Texto que se presenta en pantalla
    int correcta; //Indica si la opcion es la respuesta correcta a la pregunta 1 es Si 0 es No
} ;


#endif // OPCIONES_H_INCLUDED
