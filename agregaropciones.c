#include <stdio.h>//Funciones basicas de entrada salida
#include <locale.h>//Para presentar caracteres en español
#include <windows.h>//Para usar la funcion Sleep
#include "Preguntas.h"//Incluir el dato de tipo Pregunta
#include "Opciones.h"//Incluir ek dato de tipo opcion


int agregarOpciones(char idCuestionario[10],char idUsuario[25],char idPregunta[10]){

    FILE *fOpciones; //Apuntador para abrir archivos
    FILE *fPreguntas; //Apuntador para abrir archivos
    int i; //Contador para encontrar la posicion de la pregunta en el archivo
    int encontrado; //variable de control para saber si se encuentra una pregunta
    struct Opcion opcion; //Para manejo de la opcion
    struct Pregunta pregunta; //Para manejo de preguntas

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

    fPreguntas = fopen("Preguntas.txt","r+");

    //Leer el contenido del archivo y busca
    encontrado=0; //Inicializa la variable de control en preguntas aun no encontrado
    i=0; //Inicializa el contador a cero que es el inicio del archivo

    int respuesta=2;//Variable para la respuesta



    while(fread(&pregunta,sizeof(struct Pregunta),1,fPreguntas)){//Lee el archivo con el tamaño de la  estructura Pregunta
        if(strcmp(idPregunta,pregunta.idPregunta)==0 && strcmp(idCuestionario, pregunta.idCuestionario)==0 && strcmp(idUsuario,pregunta.idUsuario)==0){

            printf("\n\nId: %s", pregunta.idPregunta);
            printf("\nDescripción: %s\n\n", pregunta.texto);
            printf("Desea modificar esta pregunta? (1=Si, 2=No)-->");
            fflush(stdout);
            scanf("%d",&respuesta);
            fflush(stdin);

            printf("Ingrese el nuevo texto de la pregunta-->");
            fflush(stdout);
            gets(pregunta.texto);
            fflush(stdin);
            printf("Ingrese cuantos puntos vale la pregunta-->");
            fflush(stdout);
            scanf("%d",&pregunta.puntos);
            fflush(stdin);
            pregunta.cantOpciones = pregunta.cantOpciones + 1;
            //Busca la posición del pregunta en el archivo
            fseek(fPreguntas,i*sizeof(pregunta),SEEK_SET);
            //Escribe el pregunta modificado en esa posición
            fwrite(&pregunta,sizeof(pregunta),1,fPreguntas);
            printf("Registro modificado!\n");
            fflush(stdout);


            encontrado=1; //Si se encuentra una pregunta se cambia la variable de control a encontrado
            break; //Finaliza la modificacion de la pregunta, termina el ciclo de busqueda
        }
        i++;//Si no lo encuentra aumenta la posicion a un registro mas
    }

    if(encontrado==0){//Si la variable de control esta en cero significa que no encontró el cuestionario en el archivo
        printf("----La pregunta %s no está registrada -----\n",idPregunta);
        fflush(stdout);
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
