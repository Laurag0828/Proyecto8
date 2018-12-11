#include <stdio.h>//Funciones basicas de entrada salida
#include <locale.h>//Para presentar caracteres en español
#include <windows.h>//Para usar la funcion Sleep
#include "Preguntas.h"//Incluir el dato de tipo Pregunta
#include "Cuestionarios.h"//Incluir el dato de tipo cuestionario
#include "Opciones.h"//Incluir ek dato de tipo opcion

int agregarPreguntas(char idCuestionario[10]){

    FILE *f; //Apuntador para abrir archivos
    struct Cuestionario cuestionario; //Para manejo del cuestionario
    struct Pregunta pregunta; //Para manejo de la pregunta
    struct Opcion opcion; //Para manejo de la opcion
    int respuesta=2; //Variable para la respuesta del usuario, inicializa en No
    int i; //variable de control para la posicion en el archivo
    int encontrado=0; //variable de control para saber si se encuentra el cuestionario en el archivo

    //Abre el archivo en modo lectura y escritura
    f = fopen("Cuestionarios.txt","r+");
    printf("-------------------------------------------------------\n");
    printf("Activar un cuestionario\n");
    printf("-------------------------------------------------------\n");
    //pedir datos del cuestionario a buscar
    printf("Ingrese el id del cuestionario a activar-->");
    scanf("%s",idCuestionario);

    i=0; //Inicializa el contador de registros

    //Ciclo para buscar el cuestionario
    while(fread(&cuestionario,sizeof(struct Cuestionario),1,f)){//Lee el archivo con el tamaño de la  estructura Cuestionario
        if(strcmp(idCuestionario,cuestionario.idCuestionario)==0){
            //Si encuentra el cuestionario pregunta si va a activarlo
            do{
                printf("Desea activar este cuestionario? (1=Si, 2=No)-->");
                scanf("%d",&respuesta);
                fflush(stdin);
            } while(!(respuesta==1 || respuesta==2));//Repetir hasta que sea 1 o 2

            if(respuesta==1){
                cuestionario.activo=1;
                //Busca la posición del cuestionario en el archivo
                fseek(f,i*sizeof(cuestionario),SEEK_SET);
                //Escribe el cuestionario modificado en esa posición
                fwrite(&cuestionario,sizeof(cuestionario),1,f);
                printf("Cuestionario ahora está activo!\n");
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
