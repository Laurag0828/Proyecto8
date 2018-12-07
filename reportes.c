#include <stdio.h>//Funciones basicas de entrada salida
#include <locale.h>//Para presentar caracteres en español
#include <windows.h>//Para usar la funcion Sleep
#include "Calificaciones.h"//Incluir el dato de tipo Calificacion
/***

Archivo fuente para el manejo de reportes

***/


int manejoReportes(char id[25])
{
    //Variable para el control del menu de reportes
    int opcionReportes;

    //Ciclo do...while para repetir el menu hasta que se selecciona 9 para salir al menu principal
    do{
        printf("---------------------------------------------------------------\n");
        printf("Sistema de evaluaciones ISI - UCA - Reporte de calificaciones\n");
        printf("%s %s\n","Usuario actual: ", id);
        printf("---------------------------------------------------------------\n");
        printf("1. Presentar resultados de un cuestionario\n");
        printf("2. Presentar resumen por cuestionario\n");
        printf("3. Historial de un estudiante\n");
        printf("4. Promedio por cuestionarios\n");
        printf("9. Regresar a menú preguntas\n");

        printf("-------------------------------------------------------\n");
        printf("Su selección-->");
        scanf("%d",&opcionReportes);
        system("cls");

        switch(opcionReportes){
        case 1:
            //Presentar resultados de un cuestionario
            break;
        case 2:
            //Presentar resumen por cuestionario

            break;
        case 3:
            //Historial de un estudiante
            break;
        case 4:
            //Promedio por cuestionarios
            break;
        case 9:
            printf("Regresando a la pantalla principal...\n");
            Sleep(1000);
            system("cls");
            break;
        default:
            printf("Opción seleccionada es inválida!!!\n");
            Sleep(1000);
            system("cls");
            break;
        }

    }while(opcionReportes!=9);
    return 0;
}
