#include <stdio.h>//Funciones basicas de entrada salida
#include <locale.h>//Para presentar caracteres en español
#include <windows.h>//Para usar la funcion Sleep
#include "Cuestionarios.h"//Incluir el dato de tipo Cuestionario
#include "Preguntas.h"
#include "Opciones.h"
#include "Respuestas.h"
#include "Calificaciones.h"

int iniciarCuestionario(char idEstudiante[25], char idDocente[25], char idCuestionario[25]){

    FILE *fCuestionario; //Apuntador para abrir archivos de cuestionarios
    FILE *fPreguntas; //Apuntador para abrir archivos de preguntas
    FILE *fOpciones; //Apuntador para abrir archivos de preguntas
    FILE *fRespuestas; //Apuntador para abrir archivos de respuestas
    FILE *fCalificaciones; //Apuntador para abrir archivos de calificaciones
    struct Cuestionario cuestionario; //Para manejo del cuestionario
    struct Pregunta pregunta; //Para manejo de las preguntas
    struct Opcion opcion; //Para manejo de las preguntas
    struct Respuesta respuesta;
    struct Calificacion calificacion;

    int contadorPreguntas=0; //Contador de preguntas
    int respuestaUsuario = 0;//variable donde se almacenará la respuesta del usuario
    int respuestaCorrecta = 0;//variable donde se almacenará la respuesta que es correcta
    int ok=0; //indica que se almacenó un numero

    int totalPuntosAcumulados=0; //Puntos acumulados por el estudiante
    int totalPuntosCuestionario=0; //Puntos totales del cuestionario

    float porcentaje=0;



    //Abre el archivo en modo lectura
    fCuestionario = fopen("Cuestionarios.txt","r");

    while(fread(&cuestionario,sizeof(struct Cuestionario),1,fCuestionario)){//Lee el archivo con el tamaño de la  estructura Cuestionario
        if(strcmp(idDocente,cuestionario.idUsuario)==0 && strcmp(idCuestionario,cuestionario.idCuestionario)==0){
            printf("Cuestionario '%s' está cargado...\n",cuestionario.descripcion);
            system("cls");
            break;
        }
    }
    fclose(fCuestionario);
    fCuestionario=NULL;

    fPreguntas = fopen("Preguntas.txt","r");
    while(fread(&pregunta,sizeof(struct Pregunta),1,fPreguntas)){//Lee el archivo con el tamaño de la  estructura Pregunta
        if (strcmp(idCuestionario, pregunta.idCuestionario)==0 && strcmp(idDocente,pregunta.idUsuario)==0){
            totalPuntosCuestionario = totalPuntosCuestionario + pregunta.puntos;
            contadorPreguntas++;
            do{
                printf("-------------------------------------------------------------------\n");
                printf("Respondiendo el cuestionario %s\n", cuestionario.descripcion);
                printf("-------------------------------------------------------------------\n");
                printf("-------------------------------------------------------------------\n");
                printf("Pregunta %d de %d por %d puntos\n",contadorPreguntas,cuestionario.cantPreg, pregunta.puntos);
                printf("-------------------------------------------------------------------\n");
                printf("-------------------------------------------------------------------\n");
                printf("%s \n",pregunta.texto);
                printf("-------------------------------------------------------------------\n");

                fOpciones = fopen("Opciones.txt","r");
                printf("-------------------------------------------------------------------\n");
                printf("Elegir entre las siguientes opciones:\n");
                printf("-------------------------------------------------------------------\n");

                while(fread(&opcion,sizeof(struct Opcion),1,fOpciones)){//Lee el archivo con el tamaño de la  estructura Opcion
                    if (strcmp(idCuestionario, opcion.idCuestionario)==0 && strcmp(idDocente,opcion.idUsuario)==0 && strcmp(pregunta.idPregunta,opcion.idPregunta)==0){
                        printf("%d..........%-60s\n",opcion.respuesta,opcion.texto);
                        if(opcion.correcta==1){
                            respuestaCorrecta = opcion.respuesta;
                        }
                    }
                }
                //Cierra el archivo
                fclose(fOpciones);
                fOpciones=NULL;

                do{
                    printf("\n------------------------\n");
                    printf("\nSu respuesta-->");
                    fflush(stdout);
                    ok=scanf("%d",&respuestaUsuario);
                    if(!ok){
                        printf("Respuesta inválida\n");
                    }
                    fflush(stdin);
                } while(!ok);

                if(!(respuestaUsuario>=1 && respuestaUsuario <=pregunta.cantOpciones)){
                    printf("Respuesta inválida\n");
                    system("pause");
                    system("cls");
                }
                else{
                    printf("Usted seleccionó la respuesta %d \n",respuestaUsuario);
                    //Abre el archivo de respuestas
                    fRespuestas = fopen("Respuestas.txt","a");
                    strcpy(respuesta.idCuestionario,idCuestionario);
                    strcpy(respuesta.idPregunta,pregunta.idPregunta);
                    strcpy(respuesta.idDocente,idDocente);
                    strcpy(respuesta.idEstudiante,idEstudiante);
                    respuesta.respuesta=respuestaUsuario;

                    if(respuestaUsuario==respuestaCorrecta){
                        respuesta.correcta =1;
                        respuesta.puntos = pregunta.puntos;
                        totalPuntosAcumulados = totalPuntosAcumulados + pregunta.puntos;
                    }
                    else{
                        respuesta.correcta =0;
                        respuesta.puntos = 0;
                    }
                    fwrite(&respuesta, sizeof(respuesta),1,fRespuestas);
                    fclose(fRespuestas);
                    fRespuestas=NULL;
                }
            }while(!(respuestaUsuario>=1 && respuestaUsuario <=pregunta.cantOpciones));//mientras no este en el rango


            system("pause");
            system("cls");
        }
    }
    //Cierra el archivo
    fclose(fPreguntas);
    fPreguntas=NULL;

    porcentaje = (float)(totalPuntosAcumulados*100)/totalPuntosCuestionario;

    printf("-------------------------------------------------------------------\n");
    printf("Sus resultados:\n");
    printf("-------------------------------------------------------------------\n");
    printf("-------------------------------------------------------------------\n");
    printf("Total de puntos obtenidos %d de %d\n",totalPuntosAcumulados, totalPuntosCuestionario);
    printf("-------------------------------------------------------------------\n");
    printf("-------------------------------------------------------------------\n");
    printf("Porcentaje %.2f\n", porcentaje);
    printf("-------------------------------------------------------------------\n");
    printf("-------------------------------------------------------------------\n");
    printf("Sus respuestas fueron:\n");
    printf("-------------------------------------------------------------------\n");
    printf("%-15s%-15s%-15s%-15s%-15s\n","Cues","Preg","Su respuesta","Correcta", "Puntos");
    fRespuestas = fopen("Respuestas.txt","r");
    while(fread(&respuesta,sizeof(struct Respuesta),1,fRespuestas)){
        if (strcmp(idCuestionario, respuesta.idCuestionario)==0 && strcmp(idDocente,respuesta.idDocente)==0 && strcmp(idEstudiante,respuesta.idEstudiante)==0){
            printf("%-15s%-15s%-15d%-15d%-15d\n",respuesta.idCuestionario,respuesta.idPregunta,respuesta.respuesta,respuesta.correcta,respuesta.puntos);
        }
    }
    fclose(fRespuestas);
    fRespuestas=NULL;
    //Agrega la calificacion en el archivo
    fCalificaciones = fopen("Calificaciones.txt","a");
    strcpy(calificacion.idCuestionario,idCuestionario);
    strcpy(calificacion.idDocente,idDocente);
    strcpy(calificacion.idEstudiante,idEstudiante);
    calificacion.puntosTotal = totalPuntosCuestionario;
    calificacion.puntosObtenidos = totalPuntosCuestionario;
    calificacion.porcentaje = porcentaje;
    //Escribir la calificacion en el archivo
    fwrite(&calificacion, sizeof(calificacion),1,fCalificaciones);
    //Cierra el archivo
    fclose(fCalificaciones);
    fCalificaciones = NULL;

    system("pause");
    return 0;
}
