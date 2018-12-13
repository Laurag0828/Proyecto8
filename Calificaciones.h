/******

Estructura calificacion para almacenar las calificaciones de los estudiantes en los cuestionarios



******/
#ifndef CALIFICACIONES_H_INCLUDED
#define CALIFICACIONES_H_INCLUDED

struct Calificacion
{
    char idCuestionario[10];//Cuestionario
    char idDocente[25];//Docente
    char idEstudiante[25];//Estudiante
    int puntosTotal; //puntos total del cuestionario
    int puntosObtenidos; //puntos obtenidos
    float porcentaje;//porcentaje

} ;

#endif // CALIFICACIONES_H_INCLUDED
