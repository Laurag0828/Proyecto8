/******

Estructura calificacion para almacenar las calificaciones de los estudiantes en los cuestionarios



******/
#ifndef CALIFICACIONES_H_INCLUDED
#define CALIFICACIONES_H_INCLUDED

struct Calificacion
{
    char idCuestionario[10];//Cuestionario
    char idUsuario[10];//Usuario que contesta
    int calificacion; //Calificacion obtenida
} ;

#endif // CALIFICACIONES_H_INCLUDED
