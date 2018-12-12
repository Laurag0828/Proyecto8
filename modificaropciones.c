#include <stdio.h>//Funciones basicas de entrada salida
#include <locale.h>//Para presentar caracteres en español
#include <windows.h>//Para usar la funcion Sleep
#include "Opciones.h"//Incluir los datos de las opciones

int modificarOpciones(char idCuestionario[10],char descCuestionario[100],char idUsuario[25],char idPregunta[10],char descPregunta[10]){

int idOpcion;
struct Opcion opcion;
int i; //Contador para encontrar la posicion de la pregunta en el archivo
int encontrado; //variable de control para saber si se encuentra una pregunta
int respuesta=2;//Variable para la respuesta
FILE *f;

 //Abre el archivo en modo lectura y escritura
    f = fopen("Opciones.txt","r+");
    printf("-------------------------------------------------------\n");
    printf("Modificar opciones de una pregunta\n");
    printf("Cuestionario %s\n", descCuestionario);
    printf("Pregunta %s\n", descPregunta);
    printf("-------------------------------------------------------\n");
    //pedir datos del usuario a buscar
    printf("Ingrese el id de la opción a buscar-->");
    scanf("%d",&idOpcion);

    //Leer el contenido del archivo y busca el usuario por el id
    encontrado=0;//Inicializa la variable de control en preguntas aun no encontrado
    i=0;         //Inicializa el contador a cero que es el inicio del archivo


     while(fread(&opcion,sizeof(struct Opcion),1,f)){  //Lee el archivo con el tamaño de la  estructura opcion

        if(idOpcion==opcion.respuesta && strcmp(idPregunta,opcion.idPregunta)==0 && strcmp(idCuestionario,opcion.idCuestionario)==0 && strcmp(idUsuario,opcion.idUsuario)==0){
           do{
                printf("\n\nrespuesta: %d", opcion.respuesta);
                printf("\ntexto: %s\n\n", opcion.texto);
                printf("Desea modificar esta opción? (1=Si, 2=No)-->");
                scanf("%d",&respuesta);
                fflush(stdin);
            } while(!(respuesta==1 || respuesta==2));//Repetir hasta que sea 1 o 2

            if(respuesta==1){
                printf("Ingrese el nuevo texto de la opción-->");
                gets(opcion.texto);
                fflush(stdin);
                do{
                   printf("Es esta la opción correcta de la pregunta? (1=Si, 0=No)-->");
                   scanf("%d",&opcion.correcta);
                   fflush(stdin);
                } while(!(opcion.correcta==1 || opcion.correcta==0));//Repetir hasta que sea 1 o 0
                //Busca la posición del opcion en el archivo
                fseek(f,i*sizeof(opcion),SEEK_SET);
                //Escribe el opcion modificado en esa posición
                fwrite(&opcion,sizeof(opcion),1,f);
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

    if(encontrado==0){//Si la variable de control esta en cero significa que no encontró la opcion en el archivo
        printf("----La opcion %d no está registrada -----\n",idOpcion);
    }
    //Cerrar el archivo
    fclose(f);
    system("pause");
    system("cls");



    return 0;
}
