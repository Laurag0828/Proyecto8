#include <stdio.h>//Funciones basicas de entrada salida
#include <locale.h>//Para presentar caracteres en español
#include <windows.h>//Para usar la funcion Sleep
#include "Preguntas.h"//Incluir el dato de tipo Pregunta
#include "Cuestionarios.h"//Incluir el dato de tipo cuestionario
#include "Opciones.h"//Incluir ek dato de tipo opcion

int agregarPreguntas(char idCuestionario[10]){

    FILE *f; //Apuntador para abrir archivos
    FILE *f2; //Apuntador para abrir archivos
    struct Cuestionario cuestionario; //Para manejo del cuestionario
    struct Pregunta pregunta; //Para manejo de la pregunta
    struct Opcion opcion; //Para manejo de la opcion
    int j;//Variable contador
    int i; //variable de control para la posicion en el archivo

    //Abre el archivo en modo lectura y escritura
    printf("-------------------------------------------------------\n");
    printf("Agregar una nueva pregunta\n");
    printf("-------------------------------------------------------\n");
    //pedir datos del cuestionario a buscar

    //Abre el archivo de preguntas para agregar
    f2 = fopen("Preguntas.txt","r+");
    //copia el id del cuestionario en la pregunta
    strcpy(pregunta.idCuestionario,cuestionario.idCuestionario);
    //pedir datos al usuario actual
    printf("Ingrese el id de la pregunta-->");
    scanf("%s",pregunta.idPregunta);
    fflush(stdin);
    printf("Ingrese el texto de la pregunta-->");
    gets(pregunta.texto);
    fflush(stdin);
    printf("Ingrese la cantidad de opciones-->");
    scanf("%d",&pregunta.cantOpciones);
    fflush(stdin);
    printf("Ingrese cuantos puntos vale la pregunta-->");
    scanf("%d",&pregunta.puntos);
    fflush(stdin);
    //Escribir la pregunta en el archivo
    fwrite(&pregunta, sizeof(pregunta),1,f2);
    fclose(f2);
    printf("Registro guardado, ahora agregaremos las opciones de esta pregunta\n");
    system("pause");
    system("cls");

    for(j=1;j<=pregunta.cantOpciones;j++){

        f2 = fopen("Opciones.txt","r+");
        //copia el id del cuestionario y de la pregunta en la opcion
        strcpy(opcion.idCuestionario,idCuestionario);
        strcpy(opcion.idPregunta,pregunta.idPregunta);
        //pedir datos al usuario actual
        printf("Ingrese el caracter de la opción-->");
        scanf("%c",&opcion.opcion);
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
        fwrite(&opcion, sizeof(opcion),1,f2);
        fclose(f2);
        printf("Registro guardado\n");
        system("pause");
        system("cls");

    }

    f = fopen("Cuestionarios.txt","r+");

    i=0;
    while(fread(&cuestionario,sizeof(struct Cuestionario),1,f)){
        if(strcmp(idCuestionario,cuestionario.idCuestionario)==0){

            fseek(f,i*sizeof(cuestionario),SEEK_SET);
            //Escribe el cuestionario modificado en esa posición
            fwrite(&cuestionario,sizeof(cuestionario),1,f);
            printf("Cuestionario modificado!\n");
            break;
        }
        i++;
    }

    return 0;
}
