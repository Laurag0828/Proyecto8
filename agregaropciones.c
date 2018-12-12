#include <stdio.h>//Funciones basicas de entrada salida
#include <locale.h>//Para presentar caracteres en español
#include <windows.h>//Para usar la funcion Sleep
#include "Preguntas.h"//Incluir el dato de tipo Pregunta
#include "Cuestionarios.h"//Incluir el dato de tipo cuestionario
#include "Opciones.h"//Incluir ek dato de tipo opcion


int agregarOpciones(char idCuestionario[10],char descCuestionario[100],char idUsuario[25],char idPregunta[10]){

    FILE *f; //Apuntador para abrir archivos
    int i; //Contador para encontrar la posicion de la pregunta en el archivo
    struct Opcion opcion; //Para manejo de la opcion
    struct Pregunta pregunta; //Para manejo de preguntas

    f = fopen("Opciones.txt","a");
    //copia el id del cuestionario y de la pregunta en la opcion
    strcpy(opcion.idCuestionario,idCuestionario);
    strcpy(opcion.idPregunta,idPregunta);
    strcpy(opcion.idUsuario,idUsuario);//copia el usuario

    //pedir datos al usuario actual
    printf("Ingrese el numero de la respuesta-->");
    scanf("%d",&opcion.respuesta);
    fflush(stdout);
    fflush(stdin);

    printf("Ingrese el texto de la opción-->");
    gets(opcion.texto);
    fflush(stdin);
    do{
        printf("Es esta la opción correcta de la pregunta? (1=Si, 0=No)-->");
        scanf("%d",&opcion.correcta);
        fflush(stdin);
    } while(!(opcion.correcta==1 || opcion.correcta==0));//Repetir hasta que sea 1 o 0
    //Escribir la pregunta en el archivo
    fwrite(&opcion, sizeof(opcion),1,f);
    fclose(f);

    f = fopen("Preguntas.txt","r+");

    i=0; //Inicializa el contador a cero que es el inicio del archivo

    while(fread(&pregunta,sizeof(struct Pregunta),1,f)){
        if(strcmp(idPregunta,pregunta.idPregunta)==0 && strcmp(idCuestionario, pregunta.idCuestionario)==0 && strcmp(idUsuario,pregunta.idUsuario)==0){
            //Busca la posición del pregunta en el archivo
            fseek(f,i*sizeof(pregunta),SEEK_SET);
            //Escribe el pregunta modificado en esa posición
            fwrite(&pregunta,sizeof(pregunta),1,f);
        }
        i++;
        break;
    }
    fclose(f);

    printf("Registro guardado\n");
    system("pause");
    system("cls");



    return 0;
}
