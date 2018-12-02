#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <windows.h>
#include "Usuarios.h"

int main()
{
    setlocale(LC_ALL, "");
    struct Usuario usuarioLogeado; //Para usuario en el sistema
    struct Usuario usuario; //Para manejo de usuarios
    char idUsuario[25];
    char contrasenia[25];
    int i; //variable de control

    printf("-------------------------------------------------------\n");
    printf("Sistema de evaluaciones ISI - UCA - Ingreso de usuario \n");
    printf("-------------------------------------------------------\n");

    FILE *f; //Apuntador para abrir archivos
    if(fopen("Usuarios.txt","r")==NULL){
        //Si el archivo no existe crea un archivo nuevo y agrega un usuario por defecto
        f=fopen("Usuarios.txt","a");
        struct Usuario usuarioTemp = {"0000666","Docente","docente","elsner123",1};
        fwrite(&usuarioTemp, sizeof(usuarioTemp),1,f);
        fclose(f);
    }

    f=fopen("Usuarios.txt","r");

    printf("Ingrese su id de usuario:");
    scanf("%s",idUsuario);
    i=0;
    while(fread(&usuarioLogeado,sizeof(struct Usuario),1,f)){//Lee el archivo con el tamaño de la  estructura Usuario
        if(strcmp(idUsuario,usuarioLogeado.id)==0){
            do{
                printf("Ingrese su contraseña:");
                scanf("%s",contrasenia);
                if(strcmp(contrasenia,usuarioLogeado.contrasenia)==0){
                    printf("Cargando...");
                    Sleep(1000);
                    system("cls");
                    int opcionPrincipal;
                    do{
                        printf("-------------------------------------------------------\n");
                        printf("Sistema de evaluaciones ISI - UCA - Página principal \n");
                        printf("-------------------------------------------------------\n");
                        if(strcmp(usuarioLogeado.rol,"docente")==0){
                            printf("1.Manejo de cuestionarios\n");
                            printf("2.Ingresar estudiantes\n");
                        }
                        if(strcmp(usuarioLogeado.rol,"estudiante")==0){
                            printf("3.Responder un cuestionario\n");
                        }
                        printf("9.Salir del sistema\n");
                        printf("-------------------------------------------------------\n");
                        printf("Su seleccion-->");
                        scanf("%d",&opcionPrincipal);
                        system("cls");
                        switch(opcionPrincipal){
                            case 1:
                                if(strcmp(usuarioLogeado.rol,"docente")==0){
                                    printf("Lo permite");
                                }
                                else{
                                    printf("No lo permite y manda un mensaje");
                                }
                                break;
                            case 2:
                                f = fopen("Usuarios.txt","a");
                                printf("-Ingresando nuevo usuario-");
                                printf("Ingrese el id-->");
                                scanf("%s",usuario.id);
                                printf("Ingrese el nombre-->");
                                scanf("%s",usuario.nombre);
                                printf("Ingrese el rol-->");
                                scanf("%s",usuario.rol);
                                printf("Ingrese la contraseña-->");
                                scanf("%s",usuario.contrasenia);
                                printf("Activo?-->");
                                scanf("%d",&usuario.activo);
                                //Escribir
                                fwrite(&usuario, sizeof(usuario),1,f);
                                fclose(f);
                                printf("Registro guardado\n");
                                break;
                            case 9:
                                printf("Saliendo del sistema......\n");
                                Sleep(1000);
                                break;
                            default:
                                printf("Opcion seleccionada es invalida!!!\n");
                                break;
                        }
                    }
                    while(opcionPrincipal!=9);
                    break;
                }else{
                    printf("----Contraseña incorrecta!-----\n");
                    printf("para terminar presione CTRL + C \n\n");
                }
            }
            while(1);
            i++;
        }
    }
    if(i==0){
        printf("----El usuario %s no está registrado -----\n",idUsuario);
    }


    return 0;
}
