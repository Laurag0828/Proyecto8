#include <stdio.h>//Funciones basicas de entrada salida
#include <locale.h>//Para presentar caracteres en español
#include <windows.h>//Para usar la funcion Sleep
#include "Calificaciones.h"//Incluir el dato de tipo Calificacion
/***

Archivo fuente para el manejo de reportes

***/
int listarNotasCuestionario(char idUsuario[25],char idCuestionario[25]);
int listarMisNotas(char idUsuario[25]);

int manejoReportes(char id[25])
{
    //Variable para el control del menu de reportes
    int opcionReportes;

    char idCuestionario[10];
    char idEstudiante[10];

    //Ciclo do...while para repetir el menu hasta que se selecciona 9 para salir al menu principal
    do{
        printf("---------------------------------------------------------------\n");
        printf("Sistema de evaluaciones ISI - UCA - Reporte de calificaciones\n");
        printf("%s %s\n","Usuario actual: ", id);
        printf("---------------------------------------------------------------\n");
        fflush(stdout);
        printf("[1] Presentar resultados de un cuestionario\n");
        printf("[2] Historial de un estudiante\n");
        printf("[0] Regresar a menú principal\n");
        printf("-------------------------------------------------------\n");
        fflush(stdout);
        printf("Su selección-->");
        fflush(stdout);
        scanf("%d",&opcionReportes);
        fflush(stdin);
        system("cls");

        switch(opcionReportes){
        case 1:
            //Presentar resultados de un cuestionario
            printf("Presentar resultados de un cuestionario\n");
            printf("Ingrese el id del cuestionario-->");
            fflush(stdout);
            scanf("%s",idCuestionario);
            fflush(stdin);
            listarNotasCuestionario(id,idCuestionario);
            break;
        case 2:
            //Historial de un estudiante
            printf("Presentar Historial de un estudiante\n");
            printf("Ingrese el id del estudiante-->");
            fflush(stdout);
            scanf("%s",idEstudiante);
            fflush(stdin);
            listarMisNotas(idEstudiante);
            break;
        case 3:
            //Historial de un estudiante
            break;
        case 4:
            //Promedio por cuestionarios
            break;
        case 0:
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
