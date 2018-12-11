#include <stdio.h>//Funciones basicas de entrada salida
#include <locale.h>//Para presentar caracteres en español
#include <windows.h>//Para usar la funcion Sleep
#include "Cuestionarios.h"//Incluir el dato de tipo Cuestionario
#include "Preguntas.h"//Incluir el dato de tipo Pregunta
#include "Opciones.h"//Incluir el dato de tipo Opcion

int agregarCuestionario(){

    FILE *f; //Apuntador para abrir archivos
    struct Cuestionario cuestionario; //Para manejo del cuestionario
    struct Pregunta pregunta; //Para manejo de la pregunta
    struct Opcion opcion; //Para manejo de la opcion
    int i;//Ciclo para preguntas
    int j;//Ciclo para opciones
    int totalPuntos=0; //total de puntos de un cuestionario

    //Abre el archivo para agregar
    f = fopen("Cuestionarios.txt","a");


    printf("-------------------------------------------------------\n");
    printf("Ingresando nuevo cuestionario\n");
    printf("-------------------------------------------------------\n");
    //pedir datos al usuario actual
    printf("Ingrese el id del cuestionario-->");
    scanf("%s",cuestionario.idCuestionario);
    fflush(stdin);
    printf("Ingrese la descripción-->");
    gets(cuestionario.descripcion);
    fflush(stdin);
    printf("Ingrese la asignatura-->");
    gets(cuestionario.asignatura);
    fflush(stdin);
    printf("Ingrese la cantidad de preguntas-->");
    scanf("%d",&cuestionario.cantPreg);
    fflush(stdin);
    do{
        printf("Quiere dejar este cuestionario activo para responder? (1=Si, 0=No)-->");
        scanf("%d",&cuestionario.activo);
        fflush(stdin);
    } while(!(cuestionario.activo==1 || cuestionario.activo==0));//Repetir hasta que sea 1 o 0
    //Escribir al cuestionario en el archivo
    fwrite(&cuestionario, sizeof(cuestionario),1,f);
    fclose(f);
    printf("Registro guardado, ahora agregaremos las preguntas de este cuestionario\n");
    system("pause");
    system("cls");

    //Una vez guardado el cuestionario, agrega las preguntas

    //Ciclo para agragar las preguntas de este cuestionario
    for(i=1;i<=cuestionario.cantPreg;i++){
        //Abre el archivo de preguntas para agregar
        f = fopen("Preguntas.txt","a");
        printf("-------------------------------------------------------\n");
        printf("Pregunta número %d de %d\n",i,cuestionario.cantPreg);
        printf("Total de puntos %d\n",totalPuntos);
        printf("-------------------------------------------------------\n");
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
        fwrite(&pregunta, sizeof(pregunta),1,f);
        fclose(f);
        totalPuntos = totalPuntos + pregunta.puntos;
        printf("Registro guardado, ahora agregaremos las opciones de esta pregunta\n");
        system("pause");
        system("cls");

        //Una vez guardado el cuestionario, agrega las preguntas

        //Ciclo para agragar las opciones de esta pregunta
        for(j=1;j<=pregunta.cantOpciones;j++){
            //Abre el archivo de preguntas para agregar
            f = fopen("Opciones.txt","a");
            printf("-------------------------------------------------------\n");
            printf("Opción número %d de %d\n",j,pregunta.cantOpciones);
            printf("-------------------------------------------------------\n");
            //copia el id del cuestionario y de la pregunta en la opcion
            strcpy(opcion.idCuestionario,cuestionario.idCuestionario);
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
            } while(!(cuestionario.activo==1 || cuestionario.activo==0));//Repetir hasta que sea 1 o 0
            //Escribir la pregunta en el archivo
            fwrite(&opcion, sizeof(opcion),1,f);
            fclose(f);
            printf("Registro guardado\n");
            system("pause");
            system("cls");
        }
    }

    printf("Proceso completo!!!\n");
    Sleep(2000);
    system("cls");

    return 0;
}


int activarCuestionario(){

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

int desactivarCuestionario(){

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
    while(fread(&cuestionario,sizeof(struct Cuestionario),1,f)){//Lee el archivo con el tamaño de la  estructura Cuestionario
        if(strcmp(idCuestionario,cuestionario.idCuestionario)==0){
            //Si encuentra el cuestionario pregunta si va a desactivarlo
            do{
                printf("Desea desactivar este cuestionario? (1=Si, 2=No)-->");
                scanf("%d",&respuesta);
                fflush(stdin);
            } while(!(respuesta==1 || respuesta==2));//Repetir hasta que sea 1 o 2

            if(respuesta==1){
                cuestionario.activo=0;
                //Busca la posición del cuestionario en el archivo
                fseek(f,i*sizeof(cuestionario),SEEK_SET);
                //Escribe el cuestionario modificado en esa posición
                fwrite(&cuestionario,sizeof(cuestionario),1,f);
                printf("Cuestionario ahora está inactivo!\n");
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


int modificarCuestionario(){

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
    while(fread(&cuestionario,sizeof(struct Cuestionario),1,f)){//Lee el archivo con el tamaño de la  estructura Cuestionario
        if(strcmp(idCuestionario,cuestionario.idCuestionario)==0){
            //Si encuentra el cuestionario pregunta si va a desactivarlo
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


int listarCuestionario(){
    FILE *f; //Apuntador para abrir archivos
    struct Cuestionario cuestionario; //Para manejo del cuestionario
    //consulta todos los cuestionarios
    printf("-------------------------------------------------------------------\n");
    printf("Listado de cuestionarios en el Sistema de evaluaciones ISI - UCA\n");
    printf("-------------------------------------------------------------------\n");
    //Abre el archivo
    f = fopen("Cuestionarios.txt","r");
    printf("%-10s%-60s%-20s%10s%10s\n","Id","Descripcion","Asignatura","No. preguntas","Activo");
    while(fread(&cuestionario,sizeof(struct Cuestionario),1,f)){//Lee el archivo con el tamaño de la  estructura Cuestionario
        printf("%-10s%-60s%-20s%10d%10d\n",cuestionario.idCuestionario,cuestionario.descripcion,cuestionario.asignatura,cuestionario.cantPreg,cuestionario.activo);
    }
    //Cierra el archivo
    fclose(f);
    system("pause");
    system("cls");
    return 0;

}


