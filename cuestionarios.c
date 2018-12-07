#include <stdio.h>//Funciones basicas de entrada salida
#include <locale.h>//Para presentar caracteres en español
#include <windows.h>//Para usar la funcion Sleep
#include "Cuestionarios.h"//Incluir el dato de tipo Cuestionario
/***

Archivo fuente para el manejo de cuestionarios

***/

int manejoPreguntas(char id[25],char idCuestionario[10]); //Prototipo funcion manejo de preguntas

int manejoCuestionarios(char id[25])
{
    //Variable para el control del menu de cuestionarios
    int opcionCuestionarios;

    //Ciclo do...while para repetir el menu hasta que se selecciona 9 para salir al menu principal
    do{
        printf("---------------------------------------------------------------\n");
        printf("Sistema de evaluaciones ISI - UCA - Manejo de cuestionarios\n");
        printf("%s %s\n","Usuario actual: ", id);
        printf("---------------------------------------------------------------\n");
        printf("1. Agregar cuestionario\n");
        printf("2. Modificar cuestionario\n");
        printf("3. Gestionar preguntas de un cuestionario\n");
        printf("4. Desactivar cuestionario\n");
        printf("5. Listar cuestionarios\n");
        printf("9. Regresar a menú principal\n");

        printf("-------------------------------------------------------\n");
        printf("Su selección-->");
        scanf("%d",&opcionCuestionarios);
        system("cls");

        switch(opcionCuestionarios){
        case 1:
            //Agrega un cuestionario nuevo en el sistema
            break;
        case 2:
            //Modifica los datos del cuestionario

            break;
        case 3:
            //Llama a la funcion para gestionar las preguntas de un cuestionario
            manejoPreguntas(id,"0001");
            break;
        case 4:
            //Desactiva un cuestionario
            break;
        case 5:
            //Presenta una lista de todos los cuestionarios
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

    }while(opcionCuestionarios!=9);
    return 0;
}
