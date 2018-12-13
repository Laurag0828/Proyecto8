#include <stdio.h>//Funciones basicas de entrada salida
#include <locale.h>//Para presentar caracteres en español
#include <windows.h>//Para usar la funcion Sleep
#include "Cuestionarios.h"//Incluir el dato de tipo Cuestionario
/***

Archivo fuente para seleccionar el cuestionario

***/

int iniciarCuestionario(char idEstudiante[25], char idDocente[25], char idCuestionario[25]);//prototipo de funcion

int seleccionarCuestionario(char idEstudiante[25], char idDocente[25]){

    FILE *f; //Apuntador para abrir archivos
    struct Cuestionario cuestionario; //Para manejo del cuestionario
    char idCuestionario[10];

    int encontrado = 0;

    //consulta todos los cuestionarios
    system("cls");
    printf("-------------------------------------------------------------------\n");
    printf("Sistema de evaluaciones ISI - UCA\n");
    printf("Listado de cuestionarios activos del docente %s\n",idDocente);
    printf("%s %s\n","Usuario actual: ", idEstudiante);
    printf("-------------------------------------------------------------------\n");
    //Abre el archivo
    f = fopen("Cuestionarios.txt","r");
    printf("%-10s%-60s%-20s%10s%10s\n","Id","Descripcion","Asignatura","No. preguntas","Activo");
    while(fread(&cuestionario,sizeof(struct Cuestionario),1,f)){//Lee el archivo con el tamaño de la  estructura Cuestionario
        if(strcmp(idDocente,cuestionario.idUsuario)==0 && cuestionario.activo==1){
            printf("%-10s%-60s%-20s%10d%10d\n",cuestionario.idCuestionario,cuestionario.descripcion,cuestionario.asignatura,cuestionario.cantPreg,cuestionario.activo);
        }
    }
    //Cierra el archivo
    fclose(f);

    printf("\nFavor seleccione el id del cuestionario-->");
    scanf("%s",idCuestionario);

    f = fopen("Cuestionarios.txt","r");
    encontrado=0; //Inicializa la variable de control en preguntas aun no encontrado
    while(fread(&cuestionario,sizeof(struct Cuestionario),1,f)){//Lee el archivo con el tamaño de la  estructura Cuestionario
        if(strcmp(idCuestionario,cuestionario.idCuestionario)==0 ){
            encontrado=1;
            iniciarCuestionario(idEstudiante,idDocente,idCuestionario);
        }
    }
    fclose(f);

    if(encontrado==0){//Si la variable de control esta en cero significa que no encontró
        printf("----El cuestionario %s no está registrado -----\n",idCuestionario);
        system("pause");
    }

    system("cls");
    return 0;

}
