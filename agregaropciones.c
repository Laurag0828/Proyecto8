#include <stdio.h>//Funciones basicas de entrada salida
#include <locale.h>//Para presentar caracteres en español
#include <windows.h>//Para usar la funcion Sleep
#include "Preguntas.h"//Incluir el dato de tipo Pregunta
#include "Opciones.h"//Incluir ek dato de tipo opcion


int agregarOpciones(char idCuestionario[10],char descCuestionario[100],char idUsuario[25],char idPregunta[10],char descPregunta[10]){

    FILE *fOpciones; //Apuntador para abrir archivos
    FILE *fPreguntas; //Apuntador para abrir archivos
    int i; //Contador para encontrar la posicion de la pregunta en el archivo
    struct Opcion opcion; //Para manejo de la opcion
    struct Pregunta pregunta; //Para manejo de preguntas

    fOpciones = fopen("Opciones.txt","a");
    printf("-------------------------------------------------------\n");
    printf("Agregar opciones de una pregunta\n");
    printf("Cuestionario %s\n", descCuestionario);
    printf("Pregunta %s\n", descPregunta);
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

    fPreguntas = fopen("Preguntas.txt","r+");

    i=0; //Inicializa el contador a cero que es el inicio del archivo

    while(fread(&pregunta,sizeof(struct Pregunta),1,fPreguntas)){//Lee el archivo con el tamaño de la  estructura Pregunta
        if(strcmp(idPregunta,pregunta.idPregunta)==0 && strcmp(idCuestionario, pregunta.idCuestionario)==0 && strcmp(idUsuario,pregunta.idUsuario)==0){
            strcpy(pregunta.idCuestionario,idCuestionario);
            strcpy(pregunta.idPregunta,idPregunta);
            strcpy(pregunta.idUsuario,idUsuario);
            pregunta.cantOpciones = pregunta.cantOpciones +1;
            fseek(fPreguntas,i*sizeof(pregunta),SEEK_SET);
            //Escribe el pregunta modificado en esa posición
            fwrite(&pregunta,sizeof(pregunta),1,fPreguntas);
            printf("Registro modificado!\n");
            fflush(stdout);
            break; //Finaliza la modificacion de la pregunta, termina el ciclo de busqueda
        }
        i++;//Si no lo encuentra aumenta la posicion a un registro mas
    }
    //Cerrar el archivo
    fclose(fPreguntas);
    fPreguntas=NULL;

    printf("Registro guardado\n");
    fflush(stdout);
    system("pause");
    system("cls");

    return 0;
}
