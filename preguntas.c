#include <stdio.h>//Funciones basicas de entrada salida
#include <locale.h>//Para presentar caracteres en español
#include <windows.h>//Para usar la funcion Sleep
/***

Archivo fuente para el manejo de preguntas

***/

//Prototipos de funciones
int listarPreguntas(char idCuestionario[10],char descCuestionario[100],char idUsuario[25]);
int agregarPreguntas(char idCuestionario[10],char descCuestionario[100],char idUsuario[25]);
int modificarPreguntas(char idCuestionario[10],char descCuestionario[100],char idUsuario[25]);

int manejoOpciones(char idUsuario[25],char idCuestionario[10],char descCuestionario[100], char idPregunta[10]); //Prototipo funcion manejo de opciones

int manejoPreguntas(char idUsuario[25],char idCuestionario[10],char descCuestionario[100])
{
    //Variable para el control del menu de preguntas
    int opcionPreguntas;
    //Variable para pedir id de preguntas
    char idPregunta[10];

    //Ciclo do...while para repetir el menu hasta que se selecciona 9 para salir al menu de cuestionario
    do{
        printf("---------------------------------------------------------------\n");
        printf("Sistema de evaluaciones ISI - UCA - Manejo de preguntas\n");
        printf("%s %s\n","Cuestionario actual: ", descCuestionario);
        printf("%s %s\n","Usuario actual: ", idUsuario);
        printf("---------------------------------------------------------------\n");
        printf("[1] Listar preguntas de este cuestionario\n");
        printf("[2] Agregar pregunta\n");
        printf("[3] Modificar pregunta\n");
        printf("[4] Gestionar opciones de una pregunta\n");
        printf("[9] Regresar a menú cuestionarios\n");

        printf("-------------------------------------------------------\n");
        printf("Su selección-->");
        scanf("%d",&opcionPreguntas);
        system("cls");

        switch(opcionPreguntas){
        case 1:
            //Presenta una lista de todos los preguntas en este cuestionario
            listarPreguntas(idCuestionario,descCuestionario,idUsuario);
            break;
        case 2:
            //Agrega un pregunta nueva en el cuestionario
            agregarPreguntas(idCuestionario,descCuestionario,idUsuario);
            break;
        case 3:
            //Modifica los datos de la pregunta
            modificarPreguntas(idCuestionario,descCuestionario,idUsuario);
            break;
        case 4:
            //Llama a la funcion para gestionar las opciones de una pregunta
            printf("Ingrese la pregunta que va a gestionar-->");
            scanf("%s",idPregunta);
            manejoOpciones(idUsuario,idCuestionario,descCuestionario,idPregunta);
            break;
        case 9:
            printf("Regresando a la pantalla de cuestionarios...\n");
            Sleep(1000);
            system("cls");
            break;
        default:
            printf("Opción seleccionada es inválida!!!\n");
            Sleep(1000);
            system("cls");
            break;
        }

    }while(opcionPreguntas!=9);
    return 0;
}
