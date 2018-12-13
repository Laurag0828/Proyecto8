#include <stdio.h>//Funciones basicas de entrada salida
#include <locale.h>//Para presentar caracteres en español
#include <windows.h>//Para usar la funcion Sleep
#include "Preguntas.h"//Incluir el dato de tipo Pregunta
#include "Cuestionarios.h"//Incluir el dato de tipo cuestionario

int agregarPreguntas(char idCuestionario[10],char descCuestionario[100],char idUsuario[25]){

    FILE *fPregunta; //Apuntador para abrir archivos
    FILE *fCuestionario; //Apuntador para abrir archivos
    struct Cuestionario cuestionario; //Para manejo del cuestionario
    struct Pregunta pregunta; //Para manejo de la pregunta
    int i;//Ciclo para cuestionarios

    //Abre el archivo de preguntas para agregar
    fPregunta = fopen("Preguntas.txt","a");
    printf("-------------------------------------------------------\n");
    printf("Agregar pregunta al cuestionario %s\n",descCuestionario);
    printf("-------------------------------------------------------\n");
    fflush(stdout);
    //copia el id del cuestionario en la pregunta
    strcpy(pregunta.idCuestionario,idCuestionario);
    strcpy(pregunta.idUsuario,idUsuario);//copia el usuario
    fflush(stdin);
    //pedir datos al usuario actual
    printf("Ingrese el id de la pregunta-->");
    fflush(stdout);
    scanf("%s",pregunta.idPregunta);
    fflush(stdin);
    printf("Ingrese el texto de la pregunta-->");
    fflush(stdout);
    gets(pregunta.texto);
    fflush(stdin);
    //printf("Ingrese la cantidad de opciones-->");
    //scanf("%d",&pregunta.cantOpciones);
    //fflush(stdin);
    pregunta.cantOpciones=0;
    printf("Ingrese cuantos puntos vale la pregunta-->");
    fflush(stdout);
    scanf("%d",&pregunta.puntos);
    fflush(stdin);
    //Escribir la pregunta en el archivo
    fwrite(&pregunta, sizeof(pregunta),1,fPregunta);
    fclose(fPregunta);
    fPregunta=NULL;

    //Abre el archivo en modo lectura y escritura
    fCuestionario = fopen("Cuestionarios.txt","r+");


    i=0; //Inicializa el contador de registros

    //Ciclo para buscar el cuestionario
    while(fread(&cuestionario,sizeof(struct Cuestionario),1,fCuestionario)){//Lee el archivo con el tamaño de la  estructura Cuestionario
        if(strcmp(idCuestionario,cuestionario.idCuestionario)==0 && strcmp(idUsuario,cuestionario.idUsuario)==0){
            strcpy(cuestionario.idCuestionario,idCuestionario);
            strcpy(cuestionario.descripcion,descCuestionario);
            strcpy(cuestionario.idUsuario,idUsuario);
            cuestionario.cantPreg = cuestionario.cantPreg + 1;
            //Busca la posición del cuestionario en el archivo
            fseek(fCuestionario,i*sizeof(cuestionario),SEEK_SET);
            //Escribe el cuestionario modificado en esa posición
            fwrite(&cuestionario,sizeof(cuestionario),1,fCuestionario);
            break; //Finaliza la modificacion de cuestionario, termina el ciclo de busqueda
        }
        i++;//Si no lo encuentra aumenta la posicion a un registro mas
    }
    //Cerrar el archivo
    fclose(fCuestionario);
    fCuestionario=NULL;

    printf("Registro guardado, para agregar las opciones de esta pregunta, vaya al menú 'Gestionar opciones de una pregunta'\n");
    printf("y luego seleccione 'Agregar opción'\n");
    fflush(stdout);
    system("pause");
    system("cls");

    return 0;
}
