#include <stdio.h>//Funciones basicas de entrada salida
#include <locale.h>//Para presentar caracteres en español
#include <windows.h>//Para usar la funcion Sleep
#include "Preguntas.h"//Incluir el dato de tipo Pregunta



//Función modificar preguntas
int modificarPreguntas(char idCuestionario[10]){
char idBuscar[20];
int i; //Contador para encontrar la posicion de la pregunta en el archivo
int encontrado; //variable de control para saber si se encuentra una pregunta
FILE *f;
struct Pregunta pregunta;


//Abre el archivo en modo lectura y escritura
f = fopen("Preguntas.txt","r+");
printf("-------------------------------------------------------\n");
printf("Modificar una pregunta\n");
printf("-------------------------------------------------------\n");
//pedir datos del usuario a buscar
printf("Ingrese el id de la pregunta a buscar-->");
scanf("%s",idBuscar);



//Leer el contenido del archivo y busca el usuario por el id
encontrado=0; //Inicializa la variable de control en preguntas aun no encontrado
i=0; //Inicializa el contador a cero que es el inicio del archivo



while(fread(&pregunta,sizeof(struct Pregunta),1,f)){//Lee el archivo con el tamaño de la  estructura Pregunta
    if(strcmp(idBuscar,pregunta.idPregunta)==0){

       do{
                printf("\n\nId: %s", pregunta.idPregunta);
                printf("\nDescripción: %s", pregunta.texto);
                printf("Desea modificar este cuestionario? (1=Si, 2=No)-->");
                scanf("%d",&respuesta);
                fflush(stdin);
            } while(!(respuesta==1 || respuesta==2));//Repetir hasta que sea 1 o 2

    }
}

return 0;
}
