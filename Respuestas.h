/******

Estructura respuesta para almacenar las respuestas a las preguntas en los cuestionarios



******/
#ifndef RESPUESTAS_H_INCLUDED
#define RESPUESTAS_H_INCLUDED

struct Respuesta
{
    char idCuestionario[10];//Cuestionario
    char idPregunta[10];//Pregunta
    char idDocente[10];//Docente de el cuestionario
    char idEstudiante[10];//Estudiante que contesta
    int respuesta; //respuesta elegida por el usuario
    int correcta; //Indica si la opcion es la respuesta correcta a la pregunta 1 es Si 0 es No
    int puntos; //Puntos que ganó en esta pregunta
} ;

#endif // RESPUESTAS_H_INCLUDED
