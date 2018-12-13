#include <stdio.h>//Funciones basicas de entrada salida
#include <locale.h>//Para presentar caracteres en espa�ol
#include <windows.h>//Para usar la funcion Sleep
#include "Preguntas.h"//Incluir el dato de tipo Pregunta



//Funci�n modificar preguntas
int modificarPreguntas(char idCuestionario[10],char descCuestionario[100],char idUsuario[25]){

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
    printf("Cuestionario %s\n", descCuestionario);
    printf("-------------------------------------------------------\n");
    fflush(stdout);
    //pedir datos del usuario a buscar
    printf("Ingrese el id de la pregunta a buscar-->");
    fflush(stdout);
    scanf("%s",idPregunta);
    fflush(stdin);

    //Leer el contenido del archivo y busca el usuario por el id
    encontrado=0; //Inicializa la variable de control en preguntas aun no encontrado
    i=0; //Inicializa el contador a cero que es el inicio del archivo



    while(fread(&pregunta,sizeof(struct Pregunta),1,f)){//Lee el archivo con el tama�o de la  estructura Pregunta
        if(strcmp(idPregunta,pregunta.idPregunta)==0 && strcmp(idCuestionario, pregunta.idCuestionario)==0 && strcmp(idUsuario,pregunta.idUsuario)==0){
           do{
                printf("\n\nId: %s", pregunta.idPregunta);
                printf("\nDescripci�n: %s\n\n", pregunta.texto);
                printf("Desea modificar esta pregunta? (1=Si, 2=No)-->");
                fflush(stdout);
                scanf("%d",&respuesta);
                fflush(stdin);
            } while(!(respuesta==1 || respuesta==2));//Repetir hasta que sea 1 o 2

            if(respuesta==1){
                printf("Ingrese el nuevo texto de la pregunta-->");
                fflush(stdout);
                gets(pregunta.texto);
                fflush(stdin);
                printf("Ingrese cuantos puntos vale la pregunta-->");
                fflush(stdout);
                scanf("%d",&pregunta.puntos);
                fflush(stdin);
                //Busca la posici�n del pregunta en el archivo
                fseek(f,i*sizeof(pregunta),SEEK_SET);
                //Escribe el pregunta modificado en esa posici�n
                fwrite(&pregunta,sizeof(pregunta),1,f);
                printf("Registro modificado!\n");
                fflush(stdout);
            }
            else{
                printf("Acci�n cancelada!!!\n");
                fflush(stdout);
            }
            encontrado=1; //Si se encuentra una pregunta se cambia la variable de control a encontrado
            break; //Finaliza la modificacion de la pregunta, termina el ciclo de busqueda
        }
        i++;//Si no lo encuentra aumenta la posicion a un registro mas
    }

    if(encontrado==0){//Si la variable de control esta en cero significa que no encontr� el cuestionario en el archivo
        printf("----La pregunta %s no est� registrada -----\n",idPregunta);
        fflush(stdout);
    }
    //Cerrar el archivo
    fclose(f);
    system("pause");
    system("cls");
    return 0;
}

