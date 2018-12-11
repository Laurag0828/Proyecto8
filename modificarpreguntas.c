#include <stdio.h>//Funciones basicas de entrada salida
#include <locale.h>//Para presentar caracteres en español
#include <windows.h>//Para usar la funcion Sleep
#include "Preguntas.h"//Incluir el dato de tipo Pregunta



//Función modificar preguntas
int modificarPreguntas(char idCuestionario[10]){

    char idPregunta[20];
    int i; //Contador para encontrar la posicion de la pregunta en el archivo
    int encontrado; //variable de control para saber si se encuentra una pregunta
    FILE *f;
    struct Pregunta pregunta;
    int respuesta=2;//Variable para la respuesta


    //Abre el archivo en modo lectura y escritura
    f = fopen("Preguntas.txt","r+");
    printf("-------------------------------------------------------\n");
    printf("Modificar una pregunta\n");
    printf("-------------------------------------------------------\n");
    //pedir datos del usuario a buscar
    printf("Ingrese el id de la pregunta a buscar-->");
    scanf("%s",idPregunta);



    //Leer el contenido del archivo y busca el usuario por el id
    encontrado=0; //Inicializa la variable de control en preguntas aun no encontrado
    i=0; //Inicializa el contador a cero que es el inicio del archivo



    while(fread(&pregunta,sizeof(struct Pregunta),1,f)){//Lee el archivo con el tamaño de la  estructura Pregunta
        if(strcmp(idPregunta,pregunta.idPregunta)==0){
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
    system("pause");
    system("cls");
    return 0;
}

