#include <stdio.h>//Funciones basicas de entrada salida
#include <locale.h>//Para presentar caracteres en español
#include <windows.h>//Para usar la funcion Sleep
#include "Opciones.h"//Incluir el dato de tipo Cuestionario


int modificarOpciones(char idCuestionario[10],char idPregunta[10],int idOpcion, char idUsuario[25]){

    FILE *fModificar; //Apuntador para abrir archivos
    FILE *fModificarTemp; //Apuntador para abrir archivos
    struct Opcion opcion; //Para manejo del opcion
    int respuesta=2; //Variable para la respuesta del usuario, inicializa en No
    int encontrado=0; //variable de control para saber si se encuentra el cuestionario en el archivo

    remove("Temporal.txt");

    //Abre el archivo en modo lectura y escritura
    fModificar = fopen("Opciones.txt","r");
    fModificarTemp = fopen("Temporal.txt","a");
    printf("-------------------------------------------------------\n");
    printf("Modificar una opción\n");
    printf("Cuestionario: %s\n",idCuestionario);
    printf("Pregunta: %s\n",idPregunta);
    printf("-------------------------------------------------------\n");
    fflush(stdout);

    //Ciclo para buscar el opcion
    while(fread(&opcion,sizeof(struct Opcion),1,fModificar)){//Lee el archivo con el tamaño de la  estructura Opcion
        if(idOpcion==opcion.respuesta  && strcmp(idCuestionario,opcion.idCuestionario)==0 && strcmp(idPregunta,opcion.idPregunta)==0 && strcmp(idUsuario,opcion.idUsuario)==0){
            //Si encuentra el cuestionario opcion si va a desactivarlo
            do{
                printf("\n\nRespuesta: %d", opcion.respuesta);
                printf("\nTexto: %s", opcion.texto);
                printf("\nCorrecta: %d\n\n", opcion.correcta);
                printf("Desea modificar esta opcion? (1=Si, 2=No)-->");
                fflush(stdout);
                scanf("%d",&respuesta);
                fflush(stdin);
            } while(!(respuesta==1 || respuesta==2));//Repetir hasta que sea 1 o 2

            if(respuesta==1){
                printf("Ingrese el nuevo texto-->");
                fflush(stdout);
                gets(opcion.texto);
                fflush(stdin);
                do{
                   printf("Es esta la opción correcta de la pregunta? (1=Si, 0=No)-->");
                   scanf("%d",&opcion.correcta);
                   fflush(stdin);
                } while(!(opcion.correcta==1 || opcion.correcta==0));//Repetir hasta que sea 1 o 0
                fwrite(&opcion,sizeof(opcion),1,fModificarTemp);
                printf("Opcion modificada!\n");
                fflush(stdout);
            }
            else{
                fwrite(&opcion,sizeof(opcion),1,fModificarTemp);
                printf("Acción cancelada!!!\n");
                fflush(stdout);
            }
            encontrado=1; //Si se encuentra un cuestionario se cambia la variable de control a encontrado
        }
        else{
            fwrite(&opcion,sizeof(opcion),1,fModificarTemp);
        }
    }
    if(encontrado==0){//Si la variable de control esta en cero significa que no encontró el cuestionario en el archivo
        printf("----La opcion %d no está registrado -----\n",idOpcion);
        fflush(stdout);
    }
    //Cerrar el archivo
    fclose(fModificar);
    fModificar=NULL;
    fclose(fModificarTemp);
    fModificarTemp=NULL;
    remove("Opciones.txt");
    rename("Temporal.txt","Opciones.txt");
    system("pause");
    system("cls");
    return 0;
}




