#include <stdio.h>//Funciones basicas de entrada salida
#include <locale.h>//Para presentar caracteres en español
#include <windows.h>//Para usar la funcion Sleep
#include "Preguntas.h"//Incluir el dato de tipo Cuestionario


int modificarPreguntas(char idPregunta[10],char idCuestionario[10],char idUsuario[25]){

    FILE *fModificar; //Apuntador para abrir archivos
    FILE *fModificarTemp; //Apuntador para abrir archivos
    struct Pregunta pregunta; //Para manejo del pregunta
    int respuesta=2; //Variable para la respuesta del usuario, inicializa en No
    int encontrado=0; //variable de control para saber si se encuentra el cuestionario en el archivo

    remove("Temporal.txt");

    //Abre el archivo en modo lectura y escritura
    fModificar = fopen("Preguntas.txt","r");
    fModificarTemp = fopen("Temporal.txt","a");
    printf("-------------------------------------------------------\n");
    printf("Modificar una pregunta\n");
    printf("Cuestionario: %s\n",idCuestionario);
    printf("-------------------------------------------------------\n");
    fflush(stdout);

    //Ciclo para buscar el pregunta
    while(fread(&pregunta,sizeof(struct Pregunta),1,fModificar)){//Lee el archivo con el tamaño de la  estructura Pregunta
        if(strcmp(idPregunta,pregunta.idPregunta)==0  && strcmp(idCuestionario,pregunta.idCuestionario)==0 && strcmp(idUsuario,pregunta.idUsuario)==0){
            //Si encuentra el cuestionario pregunta si va a desactivarlo
            do{
                printf("\n\nId: %s", pregunta.idPregunta);
                printf("\nTexto: %s", pregunta.texto);
                printf("\nPuntos: %d\n\n", pregunta.puntos);
                printf("Desea modificar esta pregunta? (1=Si, 2=No)-->");
                fflush(stdout);
                scanf("%d",&respuesta);
                fflush(stdin);
            } while(!(respuesta==1 || respuesta==2));//Repetir hasta que sea 1 o 2

            if(respuesta==1){
                printf("Ingrese el nuevo texto-->");
                fflush(stdout);
                gets(pregunta.texto);
                fflush(stdin);
                printf("Ingrese la cantidad de opciones-->");
                fflush(stdout);
                scanf("%d",&pregunta.cantOpciones);
                fflush(stdin);
                printf("Ingrese cuantos puntos vale la pregunta-->");
                fflush(stdout);
                scanf("%d",&pregunta.puntos);
                fflush(stdin);
                fwrite(&pregunta,sizeof(pregunta),1,fModificarTemp);
                printf("Pregunta modificada!\n");
                fflush(stdout);
            }
            else{
                fwrite(&pregunta,sizeof(pregunta),1,fModificarTemp);
                printf("Acción cancelada!!!\n");
                fflush(stdout);
            }
            encontrado=1; //Si se encuentra un cuestionario se cambia la variable de control a encontrado
        }
        else{
            fwrite(&pregunta,sizeof(pregunta),1,fModificarTemp);
        }
    }
    if(encontrado==0){//Si la variable de control esta en cero significa que no encontró el cuestionario en el archivo
        printf("----La pregunta %s no está registrado -----\n",idPregunta);
        fflush(stdout);
    }
    //Cerrar el archivo
    fclose(fModificar);
    fModificar=NULL;
    fclose(fModificarTemp);
    fModificarTemp=NULL;
    remove("Preguntas.txt");
    rename("Temporal.txt","Preguntas.txt");
    system("pause");
    system("cls");
    return 0;
}




