/******

Estructura cuestionario para almacenar datos de los cuestionarios



******/
#ifndef CUESTIONARIOS_H_INCLUDED
#define CUESTIONARIOS_H_INCLUDED
struct Cuestionario
{
    char idCuestionario[10];
    char descripcion[500];
    char asignatura[20];
    int cantPreg;//Cantidad de preguntas en este cuestionario
    int activo; //Indica si el cuestionario esta activo 1 es Si 0 es No
    char idUsuario[25];//de que usuario es este cuestionario
} ;

#endif // CUESTIONARIOS_H_INCLUDED
