#include <stdio.h>//Funciones basicas de entrada salida
#include <locale.h>//Para presentar caracteres en espa�ol
#include <windows.h>//Para usar la funcion Sleep
#include "Cuestionarios.h"//Incluir el dato de tipo Cuestionario

int manejoPreguntas(char idUsuario[25],char idCuestionario[10],char descCuestionario[100]); //Prototipo funcion manejo de preguntas

int agregarCuestionario(char idUsuario[25]){

    FILE *f; //Apuntador para abrir archivos
    struct Cuestionario cuestionario; //Para manejo del cuestionario

    //Abre el archivo para agregar
    f = fopen("Cuestionarios.txt","a");


    printf("-------------------------------------------------------\n");
    printf("Ingresando nuevo cuestionario\n");
    printf("-------------------------------------------------------\n");
    strcpy(cuestionario.idUsuario,idUsuario);//copia el usuario
    //pedir datos al usuario actual
    printf("Ingrese el id del cuestionario-->");
    scanf("%s",cuestionario.idCuestionario);
    fflush(stdin);
    printf("Ingrese la descripci�n-->");
    gets(cuestionario.descripcion);
    fflush(stdin);
    printf("Ingrese la asignatura-->");
    gets(cuestionario.asignatura);
    fflush(stdin);
    cuestionario.cantPreg=0;
    do{
        printf("Quiere dejar este cuestionario activo para responder? (1=Si, 0=No)-->");
        scanf("%d",&cuestionario.activo);
        fflush(stdin);
    } while(!(cuestionario.activo==1 || cuestionario.activo==0));//Repetir hasta que sea 1 o 0
    //Escribir al cuestionario en el archivo
    fwrite(&cuestionario, sizeof(cuestionario),1,f);
    fclose(f);
    printf("Registro guardado, para agregar las preguntas de este cuestionario, vaya al men� 'Gestionar preguntas de un cuestionario'\n");
    printf("y luego seleccione 'Agregar pregunta'\n");
    system("pause");
    system("cls");

    return 0;
}


int activarCuestionario(char idUsuario[25]){

    FILE *f; //Apuntador para abrir archivos
    struct Cuestionario cuestionario; //Para manejo del cuestionario
    char idCuestionario[10];
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
    while(fread(&cuestionario,sizeof(struct Cuestionario),1,f)){//Lee el archivo con el tama�o de la  estructura Cuestionario
        if(strcmp(idCuestionario,cuestionario.idCuestionario)==0 && strcmp(idUsuario,cuestionario.idUsuario)==0){
            //Si encuentra el cuestionario pregunta si va a activarlo
            do{
                printf("Desea activar este cuestionario? (1=Si, 2=No)-->");
                scanf("%d",&respuesta);
                fflush(stdin);
            } while(!(respuesta==1 || respuesta==2));//Repetir hasta que sea 1 o 2

            if(respuesta==1){
                cuestionario.activo=1;
                //Busca la posici�n del cuestionario en el archivo
                fseek(f,i*sizeof(cuestionario),SEEK_SET);
                //Escribe el cuestionario modificado en esa posici�n
                fwrite(&cuestionario,sizeof(cuestionario),1,f);
                printf("Cuestionario ahora est� activo!\n");
            }
            else{
                printf("Acci�n cancelada!!!\n");
            }
            encontrado=1; //Si se encuentra un cuestionario se cambia la variable de control a encontrado
            break; //Finaliza la modificacion de cuestionario, termina el ciclo de busqueda
        }
        i++;//Si no lo encuentra aumenta la posicion a un registro mas
    }
    if(encontrado==0){//Si la variable de control esta en cero significa que no encontr� el cuestionario en el archivo
        printf("----El cuestionario %s no est� registrado -----\n",idCuestionario);
    }
    //Cerrar el archivo
    fclose(f);
    system("pause");
    system("cls");
    return 0;
}

int desactivarCuestionario(char idUsuario[25]){

    FILE *f; //Apuntador para abrir archivos
    struct Cuestionario cuestionario; //Para manejo del cuestionario
    char idCuestionario[10];
    int respuesta=2; //Variable para la respuesta del usuario, inicializa en No
    int i; //variable de control para la posicion en el archivo
    int encontrado=0; //variable de control para saber si se encuentra el cuestionario en el archivo

    //Abre el archivo en modo lectura y escritura
    f = fopen("Cuestionarios.txt","r+");
    printf("-------------------------------------------------------\n");
    printf("Desactivar un cuestionario\n");
    printf("-------------------------------------------------------\n");
    //pedir datos del cuestionario a buscar
    printf("Ingrese el id del cuestionario a desactivar-->");
    scanf("%s",idCuestionario);

    i=0; //Inicializa el contador de registros

    //Ciclo para buscar el cuestionario
    while(fread(&cuestionario,sizeof(struct Cuestionario),1,f)){//Lee el archivo con el tama�o de la  estructura Cuestionario
        if(strcmp(idCuestionario,cuestionario.idCuestionario)==0 && strcmp(idUsuario,cuestionario.idUsuario)==0){
            //Si encuentra el cuestionario pregunta si va a desactivarlo
            do{
                printf("Desea desactivar este cuestionario? (1=Si, 2=No)-->");
                scanf("%d",&respuesta);
                fflush(stdin);
            } while(!(respuesta==1 || respuesta==2));//Repetir hasta que sea 1 o 2

            if(respuesta==1){
                cuestionario.activo=0;
                //Busca la posici�n del cuestionario en el archivo
                fseek(f,i*sizeof(cuestionario),SEEK_SET);
                //Escribe el cuestionario modificado en esa posici�n
                fwrite(&cuestionario,sizeof(cuestionario),1,f);
                printf("Cuestionario ahora est� inactivo!\n");
            }
            else{
                printf("Acci�n cancelada!!!\n");
            }
            encontrado=1; //Si se encuentra un cuestionario se cambia la variable de control a encontrado
            break; //Finaliza la modificacion de cuestionario, termina el ciclo de busqueda
        }
        i++;//Si no lo encuentra aumenta la posicion a un registro mas
    }
    if(encontrado==0){//Si la variable de control esta en cero significa que no encontr� el cuestionario en el archivo
        printf("----El cuestionario %s no est� registrado -----\n",idCuestionario);
    }
    //Cerrar el archivo
    fclose(f);
    system("pause");
    system("cls");
    return 0;
}


int modificarCuestionario(char idUsuario[25]){

    FILE *f; //Apuntador para abrir archivos
    struct Cuestionario cuestionario; //Para manejo del cuestionario
    char idCuestionario[10];
    int respuesta=2; //Variable para la respuesta del usuario, inicializa en No
    int i; //variable de control para la posicion en el archivo
    int encontrado=0; //variable de control para saber si se encuentra el cuestionario en el archivo

    //Abre el archivo en modo lectura y escritura
    f = fopen("Cuestionarios.txt","r+");
    printf("-------------------------------------------------------\n");
    printf("Modificar un cuestionario\n");
    printf("-------------------------------------------------------\n");
    //pedir datos del cuestionario a buscar
    printf("Ingrese el id del cuestionario a modificar-->");
    scanf("%s",idCuestionario);

    i=0; //Inicializa el contador de registros

    //Ciclo para buscar el cuestionario
    while(fread(&cuestionario,sizeof(struct Cuestionario),1,f)){//Lee el archivo con el tama�o de la  estructura Cuestionario
        if(strcmp(idCuestionario,cuestionario.idCuestionario)==0 && strcmp(idUsuario,cuestionario.idUsuario)==0){
            //Si encuentra el cuestionario pregunta si va a desactivarlo
            do{
                printf("\n\nId: %s", cuestionario.idCuestionario);
                printf("\nDescripci�n: %s", cuestionario.descripcion);
                printf("\nAsignatura: %s\n\n", cuestionario.asignatura);
                printf("Desea modificar este cuestionario? (1=Si, 2=No)-->");
                scanf("%d",&respuesta);
                fflush(stdin);
            } while(!(respuesta==1 || respuesta==2));//Repetir hasta que sea 1 o 2

            if(respuesta==1){
                printf("Ingrese la nueva descripci�n-->");
                gets(cuestionario.descripcion);
                fflush(stdin);
                printf("Ingrese la nueva asignatura-->");
                gets(cuestionario.asignatura);
                fflush(stdin);
                cuestionario.activo=0;
                //Busca la posici�n del cuestionario en el archivo
                fseek(f,i*sizeof(cuestionario),SEEK_SET);
                //Escribe el cuestionario modificado en esa posici�n
                fwrite(&cuestionario,sizeof(cuestionario),1,f);
                printf("Cuestionario modificado!\n");
            }
            else{
                printf("Acci�n cancelada!!!\n");
            }
            encontrado=1; //Si se encuentra un cuestionario se cambia la variable de control a encontrado
            break; //Finaliza la modificacion de cuestionario, termina el ciclo de busqueda
        }
        i++;//Si no lo encuentra aumenta la posicion a un registro mas
    }
    if(encontrado==0){//Si la variable de control esta en cero significa que no encontr� el cuestionario en el archivo
        printf("----El cuestionario %s no est� registrado -----\n",idCuestionario);
    }
    //Cerrar el archivo
    fclose(f);
    system("pause");
    system("cls");
    return 0;
}


int gestionarCuestionario(char idUsuario[25]){

    FILE *f; //Apuntador para abrir archivos
    struct Cuestionario cuestionario; //Para manejo del cuestionario
    char idCuestionario[10];
    int i; //variable de control para la posicion en el archivo
    int respuesta=2; //Variable para la respuesta del usuario, inicializa en No
    int encontrado=0; //variable de control para saber si se encuentra el cuestionario en el archivo

    //Abre el archivo en modo lectura y escritura
    f = fopen("Cuestionarios.txt","r+");
    printf("-------------------------------------------------------\n");
    printf("Gestionar un cuestionario\n");
    printf("-------------------------------------------------------\n");
    //pedir datos del cuestionario a buscar
    printf("Ingrese el id del cuestionario a gestionar-->");
    scanf("%s",idCuestionario);

    i=0; //Inicializa el contador de registros

    //Ciclo para buscar el cuestionario
    while(fread(&cuestionario,sizeof(struct Cuestionario),1,f)){//Lee el archivo con el tama�o de la  estructura Cuestionario
        if(strcmp(idCuestionario,cuestionario.idCuestionario)==0 && strcmp(idUsuario,cuestionario.idUsuario)==0){
            //Si encuentra el cuestionario pregunta si va a desactivarlo
            do{
                printf("Desea gestionar este cuestionario? (1=Si, 2=No)-->");
                scanf("%d",&respuesta);
                fflush(stdin);
            } while(!(respuesta==1 || respuesta==2));//Repetir hasta que sea 1 o 2

            if(respuesta==1){
                system("cls");
                manejoPreguntas(idUsuario,cuestionario.idCuestionario,cuestionario.descripcion);
            }
            else{
                printf("Acci�n cancelada!!!\n");
            }
            encontrado=1; //Si se encuentra un cuestionario se cambia la variable de control a encontrado
            break; //Finaliza la modificacion de cuestionario, termina el ciclo de busqueda
        }
        i++;//Si no lo encuentra aumenta la posicion a un registro mas
    }
    if(encontrado==0){//Si la variable de control esta en cero significa que no encontr� el cuestionario en el archivo
        printf("----El cuestionario %s no est� registrado -----\n",idCuestionario);
        system("pause");
    }
    //Cerrar el archivo
    fclose(f);
    system("cls");
    return 0;
}


int listarCuestionario(char idUsuario[25]){
    FILE *f; //Apuntador para abrir archivos
    struct Cuestionario cuestionario; //Para manejo del cuestionario
    //consulta todos los cuestionarios
    printf("-------------------------------------------------------------------\n");
    printf("Listado de cuestionarios en el Sistema de evaluaciones ISI - UCA\n");
    printf("-------------------------------------------------------------------\n");
    //Abre el archivo
    f = fopen("Cuestionarios.txt","r");
    printf("%-10s%-60s%-20s%10s%10s\n","Id","Descripcion","Asignatura","No. preguntas","Activo");
    while(fread(&cuestionario,sizeof(struct Cuestionario),1,f)){//Lee el archivo con el tama�o de la  estructura Cuestionario
        if(strcmp(idUsuario,cuestionario.idUsuario)==0){
            printf("%-10s%-60s%-20s%10d%10d\n",cuestionario.idCuestionario,cuestionario.descripcion,cuestionario.asignatura,cuestionario.cantPreg,cuestionario.activo);
        }
    }
    //Cierra el archivo
    fclose(f);
    system("pause");
    system("cls");
    return 0;

}


