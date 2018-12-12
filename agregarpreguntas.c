#include <stdio.h>//Funciones basicas de entrada salida
#include <locale.h>//Para presentar caracteres en español
#include <windows.h>//Para usar la funcion Sleep
#include "Preguntas.h"//Incluir el dato de tipo Pregunta
#include "Cuestionarios.h"//Incluir el dato de tipo cuestionario
#include "Opciones.h"//Incluir ek dato de tipo opcion

int agregarPreguntas(char idCuestionario[10],char descCuestionario[100],char idUsuario[25]){

    FILE *f; //Apuntador para abrir archivos
    struct Cuestionario cuestionario; //Para manejo del cuestionario
    struct Pregunta pregunta; //Para manejo de la pregunta
    struct Opcion opcion; //Para manejo de la opcion
    int i;//Ciclo para cuestionarios
    int j;//Variable ciclo de opciones

    //Abre el archivo de preguntas para agregar
    f = fopen("Preguntas.txt","a");
    printf("-------------------------------------------------------\n");
    printf("Agregar pregunta al cuestionario %s\n",descCuestionario);
    printf("-------------------------------------------------------\n");
    //copia el id del cuestionario en la pregunta
    strcpy(pregunta.idCuestionario,idCuestionario);
    strcpy(pregunta.idUsuario,idUsuario);//copia el usuario
    fflush(stdin);
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
    fwrite(&pregunta, sizeof(pregunta),1,f);
    fclose(f);
    printf("Registro guardado, ahora agregaremos las opciones de esta pregunta\n");
    system("pause");
    system("cls");

    //Una vez guardada la pregunta, agrega las opciones

    //Ciclo para agragar las opciones de esta pregunta
    for(j=1;j<=pregunta.cantOpciones;j++){
        //Abre el archivo de preguntas para agregar
        f = fopen("Opciones.txt","a");
        printf("-------------------------------------------------------\n");
        printf("Cuestionario %s\n",descCuestionario);
        printf("Pregunta %s\n",pregunta.idPregunta);
        printf("Opción número %d de %d\n",j,pregunta.cantOpciones);
        printf("-------------------------------------------------------\n");
        //copia el id del cuestionario, usuario y de la pregunta en la opcion
        strcpy(opcion.idCuestionario,idCuestionario);
        strcpy(opcion.idPregunta,pregunta.idPregunta);
        strcpy(opcion.idUsuario,idUsuario);//copia el usuario

        fflush(stdin);
        //pedir datos al usuario actual
        opcion.respuesta=j;
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
        printf("Registro guardado\n");
        system("pause");
        system("cls");
    }

    //Abre el archivo en modo lectura y escritura
    f = fopen("Cuestionarios.txt","r+");


    i=0; //Inicializa el contador de registros

    //Ciclo para buscar el cuestionario
    while(fread(&cuestionario,sizeof(struct Cuestionario),1,f)){//Lee el archivo con el tamaño de la  estructura Cuestionario
        if(strcmp(idCuestionario,cuestionario.idCuestionario)==0 && strcmp(idUsuario,cuestionario.idUsuario)==0){
            printf("Ingrese la nueva descripción-->");
            cuestionario.cantPreg = cuestionario.cantPreg + 1;
            //Busca la posición del cuestionario en el archivo
            fseek(f,i*sizeof(cuestionario),SEEK_SET);
            //Escribe el cuestionario modificado en esa posición
            fwrite(&cuestionario,sizeof(cuestionario),1,f);
            printf("Cuestionario modificado!\n");
            break; //Finaliza la modificacion de cuestionario, termina el ciclo de busqueda
        }
        i++;//Si no lo encuentra aumenta la posicion a un registro mas
    }
    //Cerrar el archivo
    fclose(f);

    return 0;
}
