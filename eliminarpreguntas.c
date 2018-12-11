#include <stdio.h>//Funciones basicas de entrada salida
#include <locale.h>//Para presentar caracteres en español
#include <windows.h>//Para usar la funcion Sleep
#include "Cuestionarios.h"
#include "Preguntas.h"

int eliminarPreguntas(char idCuestionario[10]){

    FILE *f; //Apuntador para abrir archivos
    struct Cuestionario cuestionario; //Para manejo del cuestionario
    struct Pregunta pregunta; //Para manejo de la pregunta
    char idPregunta[10];
    int respuesta=2; //Variable para la respuesta del usuario, inicializa en No
    int encontrado=0; //variable de control para saber si se encuentra la pregunta en el archivo

    //Abre el archivo en modo lectura y escritura
    f = fopen("Preguntas.txt","r+");
    printf("-------------------------------------------------------\n");
    printf("Eliminar una pregunta\n");
    printf("-------------------------------------------------------\n");
    //pedir datos de la pregunta a buscar
    printf("Ingrese el id de la pregunta a borrar-->");
    scanf("%s",idPregunta);

    //Ciclo para buscar el cuestionario
    while(fread(&pregunta,sizeof(struct Pregunta),1,f)){//Lee el archivo con el tamaño de la  estructura Pregunta
        if(strcmp(idPregunta,pregunta.idPregunta)==0){
            //Si encuentra la pregunta, pregunta si va a borrarla
            do{
                printf("\n\nId: %s", cuestionario.idCuestionario);
                printf("\nDescripción: %s", cuestionario.descripcion);
                printf("\nAsignatura: %s\n\n", cuestionario.asignatura);
                printf("Desea modificar este cuestionario? (1=Si, 2=No)-->");
                scanf("%d",&respuesta);
                fflush(stdin);
            } while(!(respuesta==1 || respuesta==2));//Repetir hasta que sea 1 o 2

            if(respuesta==1){
                printf("Ingrese la nueva descripción-->");
                gets(cuestionario.descripcion);
                fflush(stdin);
                printf("Ingrese la nueva asignatura-->");
                gets(cuestionario.asignatura);
                fflush(stdin);
                cuestionario.activo=0;
                //Busca la posición del cuestionario en el archivo
                fseek(f,i*sizeof(cuestionario),SEEK_SET);
                //Escribe el cuestionario modificado en esa posición
                fwrite(&cuestionario,sizeof(cuestionario),1,f);
                printf("Cuestionario modificado!\n");
            }
            else{
                printf("Acción cancelada!!!\n");
            }
            encontrado=1; //Si se encuentra un cuestionario se cambia la variable de control a encontrado
            break; //Finaliza la modificacion de cuestionario, termina el ciclo de busqueda
        }
        i++;//Si no lo encuentra aumenta la posicion a un registro mas
    }
    if(encontrado==0){//Si la variable de control esta en cero significa que no encontró el cuestionario en el archivo
        printf("----El cuestionario %s no está registrado -----\n",idCuestionario);
    }
    //Cerrar el archivo
    fclose(f);
    system("pause");
    system("cls");
    return 0;
}
