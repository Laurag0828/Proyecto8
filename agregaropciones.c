#include <stdio.h>//Funciones basicas de entrada salida
#include <locale.h>//Para presentar caracteres en español
#include <windows.h>//Para usar la funcion Sleep
#include "Preguntas.h"//Incluir el dato de tipo Pregunta
#include "Opciones.h"//Incluir ek dato de tipo opcion


int agregarOpciones(char idCuestionario[10],char idUsuario[25],char idPregunta[10]){

    FILE *fOpciones; //Apuntador para abrir archivos
    struct Opcion opcion; //Para manejo de la opcion

    fOpciones = fopen("Opciones.txt","a");
    printf("-------------------------------------------------------\n");
    printf("Agregar opciones de una pregunta\n");
    printf("Cuestionario %s\n", idCuestionario);
    printf("Pregunta %s\n", idPregunta);
    printf("-------------------------------------------------------\n");
    fflush(stdout);
    //copia el id del cuestionario y de la pregunta en la opcion
    strcpy(opcion.idCuestionario,idCuestionario);
    strcpy(opcion.idPregunta,idPregunta);
    strcpy(opcion.idUsuario,idUsuario);//copia el usuario

    //pedir datos al usuario actual
    printf("Ingrese el numero de la respuesta-->");
    fflush(stdout);
    scanf("%d",&opcion.respuesta);
    fflush(stdin);

    printf("Ingrese el texto de la opción-->");
    fflush(stdout);
    gets(opcion.texto);
    fflush(stdin);
    do{
        printf("Es esta la opción correcta de la pregunta? (1=Si, 0=No)-->");
        fflush(stdout);
        scanf("%d",&opcion.correcta);
        fflush(stdin);
    } while(!(opcion.correcta==1 || opcion.correcta==0));//Repetir hasta que sea 1 o 0
    //Escribir la pregunta en el archivo
    fwrite(&opcion, sizeof(opcion),1,fOpciones);
    fclose(fOpciones);
    fOpciones=NULL;


    printf("Registro guardado\n");
    fflush(stdout);
    system("pause");
    system("cls");

    return 0;
}
