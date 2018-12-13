#include <stdio.h>//Funciones basicas de entrada salida
#include <locale.h>//Para presentar caracteres en español
#include <windows.h>//Para usar la funcion Sleep
#include "Cuestionarios.h"//Incluir el dato de tipo Cuestionario

int manejoPreguntas(char idUsuario[25],char idCuestionario[10],char descCuestionario[100]); //Prototipo funcion manejo de preguntas

int agregarCuestionario(char idUsuario[25]){

    FILE *fAgregar; //Apuntador para abrir archivos
    struct Cuestionario cuestionario; //Para manejo del cuestionario

    //Abre el archivo para agregar
    fAgregar = fopen("Cuestionarios.txt","a");


    printf("-------------------------------------------------------\n");
    printf("Ingresando nuevo cuestionario\n");
    printf("-------------------------------------------------------\n");
    fflush(stdout);
    strcpy(cuestionario.idUsuario,idUsuario);//copia el usuario
    //pedir datos al usuario actual
    printf("Ingrese el id del cuestionario-->");
    fflush(stdout);
    scanf("%s",cuestionario.idCuestionario);
    fflush(stdin);
    printf("Ingrese la descripción-->");
    fflush(stdout);
    gets(cuestionario.descripcion);
    fflush(stdin);
    printf("Ingrese la asignatura-->");
    fflush(stdout);
    gets(cuestionario.asignatura);
    fflush(stdin);
    cuestionario.cantPreg=0;
    do{
        printf("Quiere dejar este cuestionario activo para responder? (1=Si, 0=No)-->");
        fflush(stdout);
        scanf("%d",&cuestionario.activo);
        fflush(stdin);
    } while(!(cuestionario.activo==1 || cuestionario.activo==0));//Repetir hasta que sea 1 o 0
    //Escribir al cuestionario en el archivo
    fwrite(&cuestionario, sizeof(cuestionario),1,fAgregar);
    fclose(fAgregar);
    fAgregar=NULL;
    printf("Registro guardado, para agregar las preguntas de este cuestionario, vaya al menú 'Gestionar preguntas de un cuestionario'\n");
    printf("y luego seleccione 'Agregar pregunta'\n");
    fflush(stdout);
    system("pause");
    system("cls");

    return 0;
}


int activarCuestionario(char idUsuario[25]){

    FILE *fActivar; //Apuntador para abrir archivos
    FILE *fActivarTemp; //Apuntador para abrir archivos
    struct Cuestionario cuestionario; //Para manejo del cuestionario
    char idCuestionario[10];
    int respuesta=2; //Variable para la respuesta del usuario, inicializa en No
    int encontrado=0; //variable de control para saber si se encuentra el cuestionario en el archivo

    remove("Temporal.txt");

    //Abre el archivo en modo lectura y escritura
    fActivar = fopen("Cuestionarios.txt","r");
    fActivarTemp = fopen("Temporal.txt","a");
    printf("-------------------------------------------------------\n");
    printf("Activar un cuestionario\n");
    printf("-------------------------------------------------------\n");
    fflush(stdout);
    //pedir datos del cuestionario a buscar
    printf("Ingrese el id del cuestionario a activar-->");
    fflush(stdout);
    scanf("%s",idCuestionario);
    fflush(stdin);

    //Ciclo para buscar el cuestionario
    while(fread(&cuestionario,sizeof(struct Cuestionario),1,fActivar)){//Lee el archivo con el tamaño de la  estructura Cuestionario
        if(strcmp(idCuestionario,cuestionario.idCuestionario)==0 && strcmp(idUsuario,cuestionario.idUsuario)==0){
            //Si encuentra el cuestionario pregunta si va a activarlo
            do{
                printf("Desea activar este cuestionario? (1=Si, 2=No)-->");
                fflush(stdout);
                scanf("%d",&respuesta);
                fflush(stdin);
            } while(!(respuesta==1 || respuesta==2));//Repetir hasta que sea 1 o 2

            if(respuesta==1){
                cuestionario.activo=1;
                //Escribe el cuestionario modificado en esa posición
                fwrite(&cuestionario,sizeof(cuestionario),1,fActivarTemp);
                printf("Cuestionario ahora está activo!\n");
                fflush(stdout);
            }
            else{
                fwrite(&cuestionario,sizeof(cuestionario),1,fActivarTemp);
                printf("Acción cancelada!!!\n");
                fflush(stdout);
            }
            encontrado=1; //Si se encuentra un cuestionario se cambia la variable de control a encontrado
        }
        else{
            fwrite(&cuestionario,sizeof(cuestionario),1,fActivarTemp);
        }
    }
    if(encontrado==0){//Si la variable de control esta en cero significa que no encontró el cuestionario en el archivo
        printf("----El cuestionario %s no está registrado -----\n",idCuestionario);
        fflush(stdout);
    }
    //Cerrar el archivo
    fclose(fActivarTemp);
    fActivarTemp = NULL;
    fclose(fActivar);
    fActivar = NULL;

    remove("Cuestionarios.txt");
    rename("Temporal.txt","Cuestionarios.txt");
    system("pause");
    system("cls");
    return 0;
}

int desactivarCuestionario(char idUsuario[25]){

    FILE *fDesActivar; //Apuntador para abrir archivos
    FILE *fDesActivarTemp; //Apuntador para abrir archivos
    struct Cuestionario cuestionario; //Para manejo del cuestionario
    char idCuestionario[10];
    int respuesta=2; //Variable para la respuesta del usuario, inicializa en No
    int encontrado=0; //variable de control para saber si se encuentra el cuestionario en el archivo

    remove("Temporal.txt");

    //Abre el archivo en modo lectura y escritura
    fDesActivar = fopen("Cuestionarios.txt","r");
    fDesActivarTemp = fopen("Temporal.txt","a");
    printf("-------------------------------------------------------\n");
    printf("Desactivar un cuestionario\n");
    printf("-------------------------------------------------------\n");
    fflush(stdout);
    //pedir datos del cuestionario a buscar
    printf("Ingrese el id del cuestionario a desactivar-->");
    fflush(stdout);
    scanf("%s",idCuestionario);
    fflush(stdin);

    //Ciclo para buscar el cuestionario
    while(fread(&cuestionario,sizeof(struct Cuestionario),1,fDesActivar)){//Lee el archivo con el tamaño de la  estructura Cuestionario
        if(strcmp(idCuestionario,cuestionario.idCuestionario)==0 && strcmp(idUsuario,cuestionario.idUsuario)==0){
            //Si encuentra el cuestionario pregunta si va a activarlo
            do{
                printf("Desea activar este cuestionario? (1=Si, 2=No)-->");
                fflush(stdout);
                scanf("%d",&respuesta);
                fflush(stdin);
            } while(!(respuesta==1 || respuesta==2));//Repetir hasta que sea 1 o 2

            if(respuesta==1){
                cuestionario.activo=0;
                //Escribe el cuestionario modificado en esa posición
                fwrite(&cuestionario,sizeof(cuestionario),1,fDesActivarTemp);
                printf("Cuestionario ahora está inactivo!\n");
                fflush(stdout);
            }
            else{
                fwrite(&cuestionario,sizeof(cuestionario),1,fDesActivarTemp);
                printf("Acción cancelada!!!\n");
                fflush(stdout);
            }
            encontrado=1; //Si se encuentra un cuestionario se cambia la variable de control a encontrado
        }
        else{
            fwrite(&cuestionario,sizeof(cuestionario),1,fDesActivarTemp);
        }
    }
    if(encontrado==0){//Si la variable de control esta en cero significa que no encontró el cuestionario en el archivo
        printf("----El cuestionario %s no está registrado -----\n",idCuestionario);
        fflush(stdout);
    }
    //Cerrar el archivo
    fclose(fDesActivarTemp);
    fDesActivarTemp = NULL;
    fclose(fDesActivar);
    fDesActivar = NULL;

    remove("Cuestionarios.txt");
    rename("Temporal.txt","Cuestionarios.txt");
    system("pause");
    system("cls");
    return 0;
}


int modificarCuestionario(char idUsuario[25]){

    FILE *fModificar; //Apuntador para abrir archivos
    FILE *fModificarTemp; //Apuntador para abrir archivos
    struct Cuestionario cuestionario; //Para manejo del cuestionario
    char idCuestionario[10];
    int respuesta=2; //Variable para la respuesta del usuario, inicializa en No
    int encontrado=0; //variable de control para saber si se encuentra el cuestionario en el archivo

    remove("Temporal.txt");

    //Abre el archivo en modo lectura y escritura
    fModificar = fopen("Cuestionarios.txt","r");
    fModificarTemp = fopen("Temporal.txt","a");
    printf("-------------------------------------------------------\n");
    printf("Modificar un cuestionario\n");
    printf("-------------------------------------------------------\n");
    fflush(stdout);
    //pedir datos del cuestionario a buscar
    printf("Ingrese el id del cuestionario a modificar-->");
    fflush(stdout);
    scanf("%s",idCuestionario);
    fflush(stdin);

    //Ciclo para buscar el cuestionario
    while(fread(&cuestionario,sizeof(struct Cuestionario),1,fModificar)){//Lee el archivo con el tamaño de la  estructura Cuestionario
        if(strcmp(idCuestionario,cuestionario.idCuestionario)==0 && strcmp(idUsuario,cuestionario.idUsuario)==0){
            //Si encuentra el cuestionario pregunta si va a desactivarlo
            do{
                printf("\n\nId: %s", cuestionario.idCuestionario);
                printf("\nDescripción: %s", cuestionario.descripcion);
                printf("\nAsignatura: %s\n\n", cuestionario.asignatura);
                printf("Desea modificar este cuestionario? (1=Si, 2=No)-->");
                fflush(stdout);
                scanf("%d",&respuesta);
                fflush(stdin);
            } while(!(respuesta==1 || respuesta==2));//Repetir hasta que sea 1 o 2

            if(respuesta==1){
                printf("Ingrese la nueva descripción-->");
                fflush(stdout);
                gets(cuestionario.descripcion);
                fflush(stdin);
                printf("Ingrese la nueva asignatura-->");
                fflush(stdout);
                gets(cuestionario.asignatura);
                fflush(stdin);
                //Escribe el cuestionario modificado en esa posición
                fwrite(&cuestionario,sizeof(cuestionario),1,fModificarTemp);
                printf("Cuestionario modificado!\n");
                fflush(stdout);
            }
            else{
                fwrite(&cuestionario,sizeof(cuestionario),1,fModificarTemp);
                printf("Acción cancelada!!!\n");
                fflush(stdout);
            }
            encontrado=1; //Si se encuentra un cuestionario se cambia la variable de control a encontrado
        }
        else{
            fwrite(&cuestionario,sizeof(cuestionario),1,fModificarTemp);
        }
    }
    if(encontrado==0){//Si la variable de control esta en cero significa que no encontró el cuestionario en el archivo
        printf("----El cuestionario %s no está registrado -----\n",idCuestionario);
        fflush(stdout);
    }
    //Cerrar el archivo
    fclose(fModificar);
    fModificar=NULL;
    remove("Cuestionarios.txt");
    rename("Temporal.txt","Cuestionarios.txt");
    system("pause");
    system("cls");
    return 0;
}


int gestionarCuestionario(char idUsuario[25]){

    FILE *fGestionar; //Apuntador para abrir archivos
    struct Cuestionario cuestionario; //Para manejo del cuestionario
    char idCuestionario[10];
    int i; //variable de control para la posicion en el archivo
    int respuesta=2; //Variable para la respuesta del usuario, inicializa en No
    int encontrado=0; //variable de control para saber si se encuentra el cuestionario en el archivo

    //Abre el archivo en modo lectura y escritura
    fGestionar = fopen("Cuestionarios.txt","r");
    printf("-------------------------------------------------------\n");
    printf("Gestionar un cuestionario\n");
    printf("-------------------------------------------------------\n");
    fflush(stdout);
    //pedir datos del cuestionario a buscar
    printf("Ingrese el id del cuestionario a gestionar-->");
    fflush(stdout);
    scanf("%s",idCuestionario);
    fflush(stdin);

    i=0; //Inicializa el contador de registros

    //Ciclo para buscar el cuestionario
    while(fread(&cuestionario,sizeof(struct Cuestionario),1,fGestionar)){//Lee el archivo con el tamaño de la  estructura Cuestionario
        if(strcmp(idCuestionario,cuestionario.idCuestionario)==0 && strcmp(idUsuario,cuestionario.idUsuario)==0){
            //Si encuentra el cuestionario pregunta si va a desactivarlo
            do{
                printf("Desea gestionar este cuestionario? (1=Si, 2=No)-->");
                fflush(stdout);
                scanf("%d",&respuesta);
                fflush(stdin);
            } while(!(respuesta==1 || respuesta==2));//Repetir hasta que sea 1 o 2

            if(respuesta==1){
                system("cls");
                manejoPreguntas(idUsuario,cuestionario.idCuestionario,cuestionario.descripcion);
            }
            else{
                printf("Acción cancelada!!!\n");
                fflush(stdout);
            }
            encontrado=1; //Si se encuentra un cuestionario se cambia la variable de control a encontrado
            break; //Finaliza la modificacion de cuestionario, termina el ciclo de busqueda
        }
        i++;//Si no lo encuentra aumenta la posicion a un registro mas
    }
    if(encontrado==0){//Si la variable de control esta en cero significa que no encontró el cuestionario en el archivo
        printf("----El cuestionario %s no está registrado -----\n",idCuestionario);
        fflush(stdout);
        system("pause");
    }
    //Cerrar el archivo
    fclose(fGestionar);
    fGestionar=NULL;
    system("cls");
    return 0;
}


int listarCuestionario(char idUsuario[25]){
    FILE *fListar; //Apuntador para abrir archivos
    struct Cuestionario cuestionario; //Para manejo del cuestionario
    //consulta todos los cuestionarios
    printf("-------------------------------------------------------------------\n");
    printf("Listado de cuestionarios en el Sistema de evaluaciones ISI - UCA\n");
    printf("-------------------------------------------------------------------\n");
    fflush(stdout);
    //Abre el archivo
    fListar = fopen("Cuestionarios.txt","r");
    printf("%-10s%-60s%-20s%10s%10s\n","Id","Descripcion","Asignatura","No. preguntas","Activo");
    fflush(stdout);
    while(fread(&cuestionario,sizeof(struct Cuestionario),1,fListar)){//Lee el archivo con el tamaño de la  estructura Cuestionario
        if(strcmp(idUsuario,cuestionario.idUsuario)==0){
            printf("%-10s%-60s%-20s%10d%10d\n",cuestionario.idCuestionario,cuestionario.descripcion,cuestionario.asignatura,cuestionario.cantPreg,cuestionario.activo);
            fflush(stdout);
        }
    }
    //Cierra el archivo
    fclose(fListar);
    fListar=NULL;
    system("pause");
    fflush(stdout);
    system("cls");
    return 0;

}


