#include <stdio.h>//Funciones basicas de entrada salida
#include <locale.h>//Para presentar caracteres en español
#include <windows.h>//Para usar la funcion Sleep
#include "Preguntas.h"//Incluir el dato de tipo Opcion
/***

Archivo fuente para el manejo de opciones

***/

int listarOpciones(char idCuestionario[10],char descCuestionario[100],char idUsuario[25],char idPregunta[10],char descPregunta[100]);
int agregarOpciones(char idCuestionario[10],char descCuestionario[100],char idUsuario[25],char idPregunta[10],char descPregunta[100]);
int modificarOpciones(char idCuestionario[10],char descCuestionario[100],char idUsuario[25],char idPregunta[10],char descPregunta[100]);

int manejoOpciones(char idUsuario[25],char idCuestionario[10],char descCuestionario[100],char idPregunta[10])
{
    //Variable para el control del menu de opciones
    int opcionOpciones;
    FILE *f;
    int encontrado=0;
    struct Pregunta pregunta;
    //Abre el archivo en modo lectura y escritura
    f = fopen("Preguntas.txt","r");
    while(fread(&pregunta,sizeof(struct Pregunta),1,f)){//Lee el archivo con el tamaño de la  estructura Pregunta
        if(strcmp(idPregunta,pregunta.idPregunta)==0 && strcmp(idCuestionario, pregunta.idCuestionario)==0 && strcmp(idUsuario,pregunta.idUsuario)==0){
            encontrado=1; //Si se encuentra una pregunta se cambia la variable de control a encontrado
            break; //Finaliza la modificacion de la pregunta, termina el ciclo de busqueda
        }
    }
    //cerrar el archivo
    fclose(f);

    if(encontrado==0){//Si la variable de control esta en cero significa que no encontró el cuestionario en el archivo
        printf("----La pregunta %s no está registrada -----\n",idPregunta);
        system("pause");
        system("cls");
        return 0;
    }


    //Ciclo do...while para repetir el menu hasta que se selecciona 9 para salir al menu de preguntas
    do{
        printf("---------------------------------------------------------------\n");
        printf("Sistema de evaluaciones ISI - UCA - Manejo de opciones\n");
        printf("%s %s\n","Cuestionario actual: ", descCuestionario);
        printf("%s %s\n","Pregunta actual: ", pregunta.texto);
        printf("%s %s\n","Usuario actual: ", idUsuario);
        printf("---------------------------------------------------------------\n");
        printf("[1] Listar opciones de esta pregunta\n");
        printf("[2] Agregar opción\n");
        printf("[3] Modificar opción\n");
        printf("[9] Regresar a menú preguntas\n");

        printf("-------------------------------------------------------\n");
        printf("Su selección-->");
        scanf("%d",&opcionOpciones);
        system("cls");

        switch(opcionOpciones){
        case 1:
            //Presenta una lista de todos los opciones en esta pregunta
            listarOpciones(idCuestionario,descCuestionario,idUsuario,idPregunta,pregunta.texto);
            break;
        case 2:
            //Agrega una opcion nueva en la pregunta
            agregarOpciones(idCuestionario,descCuestionario,idUsuario,idPregunta,pregunta.texto);
            break;
        case 3:
            //Modifica los datos de la opcion
            modificarOpciones(idCuestionario,descCuestionario,idUsuario,idPregunta,pregunta.texto);
            break;
        case 9:
            printf("Regresando a la pantalla de preguntas...\n");
            Sleep(1000);
            system("cls");
            break;
        default:
            printf("Opción seleccionada es inválida!!!\n");
            Sleep(1000);
            system("cls");
            break;
        }

    }while(opcionOpciones!=9);
    return 0;
}
