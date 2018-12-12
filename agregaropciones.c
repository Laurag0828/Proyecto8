#include <stdio.h>//Funciones basicas de entrada salida
#include <locale.h>//Para presentar caracteres en español
#include <windows.h>//Para usar la funcion Sleep
#include "Preguntas.h"//Incluir el dato de tipo Pregunta
#include "Opciones.h"//Incluir ek dato de tipo opcion


int agregarOpciones(char idCuestionario[10],char descCuestionario[100],char idUsuario[25],char idPregunta[10],char descPregunta[10]){

    FILE *f; //Apuntador para abrir archivos
    int i; //Contador para encontrar la posicion de la pregunta en el archivo
    struct Opcion opcion; //Para manejo de la opcion
    struct Pregunta pregunta; //Para manejo de preguntas

    int encontrado; //variable de control para saber si se encuentra una pregunta
    int respuesta=2;//Variable para la respuesta

    f = fopen("Opciones.txt","a");
    printf("-------------------------------------------------------\n");
    printf("Agregar opciones de una pregunta\n");
    printf("Cuestionario %s\n", descCuestionario);
    printf("Pregunta %s\n", descPregunta);
    printf("-------------------------------------------------------\n");
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
    printf("%s %s %s",idCuestionario,idPregunta,idUsuario);

    //Leer el contenido del archivo y busca el usuario por el id
    encontrado=0; //Inicializa la variable de control en preguntas aun no encontrado
    i=0; //Inicializa el contador a cero que es el inicio del archivo



    while(fread(&pregunta,sizeof(struct Pregunta),1,f)){//Lee el archivo con el tamaño de la  estructura Pregunta
        if(strcmp(idPregunta,pregunta.idPregunta)==0 && strcmp(idCuestionario, pregunta.idCuestionario)==0 && strcmp(idUsuario,pregunta.idUsuario)==0){
           do{
                printf("\n\nId: %s", pregunta.idPregunta);
                printf("\nDescripción: %s\n\n", pregunta.texto);
                printf("Desea modificar esta pregunta? (1=Si, 2=No)-->");
                scanf("%d",&respuesta);
                fflush(stdin);
            } while(!(respuesta==1 || respuesta==2));//Repetir hasta que sea 1 o 2

            if(respuesta==1){
                printf("Ingrese el nuevo texto de la pregunta-->");
                gets(pregunta.texto);
                fflush(stdin);
                printf("Ingrese cuantos puntos vale la pregunta-->");
                scanf("%d",&pregunta.puntos);
                fflush(stdin);
                //Busca la posición del pregunta en el archivo
                fseek(f,i*sizeof(pregunta),SEEK_SET);
                //Escribe el pregunta modificado en esa posición
                fwrite(&pregunta,sizeof(pregunta),1,f);
                printf("Registro modificado!\n");
            }
            else{
                printf("Acción cancelada!!!\n");
            }
            encontrado=1; //Si se encuentra una pregunta se cambia la variable de control a encontrado
            break; //Finaliza la modificacion de la pregunta, termina el ciclo de busqueda
        }
        i++;//Si no lo encuentra aumenta la posicion a un registro mas
    }

    if(encontrado==0){//Si la variable de control esta en cero significa que no encontró el cuestionario en el archivo
        printf("----La pregunta %s no está registrada -----\n",idPregunta);
    }
    //Cerrar el archivo
    fclose(f);

    printf("Registro guardado\n");
    system("pause");
    system("cls");



    return 0;
}
