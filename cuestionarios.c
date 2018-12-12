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

int manejoCuestionarios(char idUsuario[25])
{
    //Variable para el control del menu de cuestionarios
    int opcionCuestionarios;

    //Ciclo do...while para repetir el menu hasta que se selecciona 9 para salir al menu principal
    do{
        printf("---------------------------------------------------------------\n");
        printf("Sistema de evaluaciones ISI - UCA - Manejo de cuestionarios\n");
        printf("%s %s\n","Usuario actual: ", idUsuario);
        printf("---------------------------------------------------------------\n");
        printf("[1] Listar cuestionarios\n");
        printf("[2] Agregar cuestionario\n");
        printf("[3] Activar cuestionario\n");
        printf("[4] Desactivar cuestionario\n");
        printf("[5] Modificar cuestionario\n");
        printf("[6] Gestionar preguntas de un cuestionario\n");
        printf("[9] Regresar a menú principal\n");

        printf("-------------------------------------------------------\n");
        printf("Su selección-->");
        scanf("%d",&opcionCuestionarios);
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
            //Llama a la funcion para gestionar las preguntas de un cuestionario
            gestionarCuestionario(idUsuario);
            break;
        case 9:
            printf("Regresando a la pantalla principal...\n");
            Sleep(1000);
            system("cls");
            break;
        default:
            printf("Opción seleccionada es inválida!!!\n");
            Sleep(1000);
            system("cls");
            break;
        }

    }while(opcionCuestionarios!=9);
    return 0;
}
