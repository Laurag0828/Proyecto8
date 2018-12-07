#include <stdio.h>//Funciones basicas de entrada salida
#include <locale.h>//Para presentar caracteres en espa�ol
#include <windows.h>//Para usar la funcion Sleep
#include "Opciones.h"//Incluir el dato de tipo Opcion
/***

Archivo fuente para el manejo de opciones

***/


int manejoOpciones(char id[25],char idCuestionario[10],char idPregunta[10])
{
    //Variable para el control del menu de opciones
    int opcionOpciones;

    //Ciclo do...while para repetir el menu hasta que se selecciona 9 para salir al menu de preguntas
    do{
        printf("---------------------------------------------------------------\n");
        printf("Sistema de evaluaciones ISI - UCA - Manejo de opciones\n");
        printf("%s %s\n","Cuestionario actual: ", idCuestionario);
        printf("%s %s\n","Pregunta actual: ", idPregunta);
        printf("%s %s\n","Usuario actual: ", id);
        printf("---------------------------------------------------------------\n");
        printf("1. Agregar opci�n\n");
        printf("2. Modificar opci�n\n");
        printf("3. Desactivar opci�n\n");
        printf("4. Listar opciones de esta pregunta\n");
        printf("9. Regresar a men� preguntas\n");

        printf("-------------------------------------------------------\n");
        printf("Su selecci�n-->");
        scanf("%d",&opcionOpciones);
        system("cls");

        switch(opcionOpciones){
        case 1:
            //Agrega una opcion nueva en la pregunta
            break;
        case 2:
            //Modifica los datos de la opcion

            break;
        case 3:
            //Desactiva una opcion
            break;
        case 4:
            //Presenta una lista de todos los opciones en esta pregunta
            break;
        case 9:
            printf("Regresando a la pantalla de preguntas...\n");
            Sleep(1000);
            system("cls");
            break;
        default:
            printf("Opci�n seleccionada es inv�lida!!!\n");
            Sleep(1000);
            system("cls");
            break;
        }

    }while(opcionOpciones!=9);
    return 0;
}
