#include <stdio.h>//Funciones basicas de entrada salida
#include <locale.h>//Para presentar caracteres en español
#include <windows.h>//Para usar la funcion Sleep
/***

Archivo fuente para el manejo de cuestionarios

***/

int agregarCuestionario(char idUsuario[25]); //Prototipo de funcion para crear cuestionarios
int activarCuestionario(char idUsuario[25]); //Prototipo de funcion para activar Cuestionarios
int desactivarCuestionario(char idUsuario[25]); //Prototipo de funcion para desactivar Cuestionarios
int modificarCuestionario(char idUsuario[25]); //Prototipo de funcion para modificar Cuestionarios
int gestionarCuestionario(char idUsuario[25]); //Prototipo de funcion para llamar a la gestion del cuestionario
int listarCuestionario(char idUsuario[25]); //Prototipo de funcion para listar cuestionariosactivarCuestionario


int listarPreguntas(char idCuestionario[10],char idUsuario[25]);
int agregarPreguntas(char idCuestionario[10],char idUsuario[25]);
int modificarPreguntas(char idPregunta[10], char idCuestionario[10],char idUsuario[25]);

int listarOpciones(char idCuestionario[10],char idUsuario[25],char idPregunta[10]);
int agregarOpciones(char idCuestionario[10],char idUsuario[25],char idPregunta[10]);


int manejoCuestionarios(char idUsuario[25])
{
    //Variable para el control del menu de cuestionarios
    int opcionCuestionarios;

    char idCuestionario[10];
    char idPregunta[10];

    //Ciclo do...while para repetir el menu hasta que se selecciona 9 para salir al menu principal
    do{
        printf("---------------------------------------------------------------\n");
        printf("Sistema de evaluaciones ISI - UCA - Manejo de cuestionarios\n");
        printf("%s %s\n","Usuario actual: ", idUsuario);
        printf("---------------------------------------------------------------\n");
        fflush(stdout);
        printf("[1] Listar cuestionarios\n");
        printf("[2] Agregar cuestionario\n");
        printf("[3] Activar cuestionario\n");
        printf("[4] Desactivar cuestionario\n");
        printf("[5] Modificar cuestionario\n");
        printf("[6] Listar pregutas de un cuestionario\n");
        printf("[7] Agregar pregunta\n");
        printf("[8] Modificar pregunta\n");
        printf("[9] Listar opciones de una pregunta\n");
        printf("[10] Agregar opción\n");
        printf("[11] Modificar opción\n");
        printf("[0] Regresar a menú principal\n");
        printf("-------------------------------------------------------\n");
        fflush(stdout);
        printf("Su selección-->");
        fflush(stdout);
        scanf("%d",&opcionCuestionarios);
        fflush(stdin);
        system("cls");

        switch(opcionCuestionarios){
        case 1:
            //Presenta una lista de todos los cuestionarios
            listarCuestionario(idUsuario);
            break;
        case 2:
            //Agrega un cuestionario nuevo en el sistema
            agregarCuestionario(idUsuario);
            break;
        case 3:
            //Activar un cuestionario
            activarCuestionario(idUsuario);
            break;
        case 4:
            //Desactivar un cuestionario
            desactivarCuestionario(idUsuario);
            break;
        case 5:
            //Modificar un cuestionario
            modificarCuestionario(idUsuario);
            break;
        case 6:
            //Presenta una lista de todos los preguntas en este cuestionario
            printf("Ingrese el id del cuestionario-->");
            fflush(stdout);
            scanf("%s",idCuestionario);
            fflush(stdin);
            listarPreguntas(idCuestionario,idUsuario);
            break;
        case 7:
            printf("Agregar pregunta\n");
            printf("Ingrese el id del cuestionario-->");
            fflush(stdout);
            scanf("%s",idCuestionario);
            fflush(stdin);
            agregarPreguntas(idCuestionario,idUsuario);
            break;
        case 8:
            printf("Ingrese el id del cuestionario-->");
            fflush(stdout);
            scanf("%s",idCuestionario);
            fflush(stdin);
            printf("Ingrese el id de la pregunta-->");
            fflush(stdout);
            scanf("%s",idPregunta);
            fflush(stdin);
            modificarPreguntas(idPregunta,idCuestionario,idUsuario);
            break;
        case 9:
            printf("Ingrese el id del cuestionario-->");
            fflush(stdout);
            scanf("%s",idCuestionario);
            fflush(stdin);
            printf("Ingrese el id de la pregunta-->");
            fflush(stdout);
            scanf("%s",idPregunta);
            fflush(stdin);
            //Presenta una lista de todos los opciones en esta pregunta
            listarOpciones(idCuestionario,idUsuario,idPregunta);
            break;
        case 10:
            printf("Ingrese el id del cuestionario-->");
            fflush(stdout);
            scanf("%s",idCuestionario);
            fflush(stdin);
            printf("Ingrese el id de la pregunta-->");
            fflush(stdout);
            scanf("%s",idPregunta);
            fflush(stdin);
            //Agrega una opcion nueva en la pregunta
            agregarOpciones(idCuestionario,idUsuario,idPregunta);
            break;
        case 0:
            printf("Regresando a la pantalla principal...\n");
            fflush(stdout);
            Sleep(1000);
            system("cls");
            break;
        default:
            printf("Opción seleccionada es inválida!!!\n");
            fflush(stdout);
            Sleep(1000);
            system("cls");
            break;
        }

    }while(opcionCuestionarios!=9);
    return 0;
}
