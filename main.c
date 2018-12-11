#include <stdio.h>//Funciones basicas de entrada salida
#include <locale.h>//Para presentar caracteres en espa�ol
#include <windows.h>//Para usar la funcion Sleep
#include "Usuarios.h"//Incluir el dato de tipo Usuario

int manejoUsuarios(char id[25]); //Prototipo funcion manejo de usuarios
int manejoCuestionarios(char id[25]); //Prototipo funcion manejo de cuestionarios
int responderCuestionario(char id[25]); //Prototipo funcion para responder cuestionarios
int manejoReportes(char id[25]); //Prototipo funcion para presentar menu de reportes
int cambiarContrasenia(char id[25]); //Prototipo funcion para cambiar contrase�a



/*Programa principal, maneja el menu principal del sistema*/
int main()
{
    setlocale(LC_ALL, ""); //Permite presentar caracteres en espa�ol
    struct Usuario usuarioLogeado; //Para usuario en el sistema
    char idUsuario[25];//Para buscar el usuario
    char contrasenia[25];//Para validar la contrase�a
    int encontrado=0; //variable de control para mostrar mensaje que no se encontr� usuario registrado inicializado en 0 para no encontrado
    printf("-------------------------------------------------------\n");
    printf("Sistema de evaluaciones ISI - UCA - Ingreso de usuario \n");
    printf("-------------------------------------------------------\n");

    FILE *f; //Apuntador para abrir archivos
    if(fopen("Usuarios.txt","r")==NULL){
        //Si el archivo no existe crea un archivo nuevo y agrega un usuario por defecto
        f=fopen("Usuarios.txt","a");
        printf("Se ha creado un nuevo archivo....\n");
        struct Usuario usuarioTemp = {"0000123","Docente","docente","123",1};//Crea el usuario por defecto
        fwrite(&usuarioTemp, sizeof(usuarioTemp),1,f);//Lo escribe en el archivo
        fclose(f);//Cierra el archivo
    }

    f=fopen("Usuarios.txt","r");//Abre el archivo de usuarios para buscar el usuario que va a ingresar

    /*Pide el id al usuario*/
    printf("Ingrese su id de usuario:");
    scanf("%s",idUsuario);


    while(fread(&usuarioLogeado,sizeof(struct Usuario),1,f)){//Lee el archivo con el tama�o de la  estructura Usuario
        if(strcmp(idUsuario,usuarioLogeado.id)==0){
            //Si encuentra el id del usuario la variable de control la pone en 1 que es encontrado
            encontrado=1;
            if(usuarioLogeado.activo==1){
                do{
                    printf("Ingrese su contrase�a:");//Pide la contrase�a
                    scanf("%s",contrasenia);
                    if(strcmp(contrasenia,usuarioLogeado.contrasenia)==0){
                        //Si la contrase�a coincide con la almacenada presenta el men� principal
                        printf("Cargando...");
                        Sleep(1000);
                        system("cls");
                        int opcionPrincipal;

                        /*Presenta el men� principal del sistema */
                        do{
                            printf("-------------------------------------------------------\n");
                            printf("Sistema de evaluaciones ISI - UCA - Men� principal \n");
                            printf("%s %s\n","Usuario actual: ", usuarioLogeado.id);
                            printf("-------------------------------------------------------\n");
                            //Eval�a si el usuario ingresado es docente y presenta las opciones del docente
                            if(strcmp(usuarioLogeado.rol,"docente")==0){
                                printf("[1] Manejo de cuestionarios\n");
                                printf("[2] Manejo de usuarios\n");
                                printf("[3] Reportes\n");
                            }
                            //Eval�a si el usuario ingresado es estudiante y presenta las opciones del estudiante
                            if(strcmp(usuarioLogeado.rol,"estudiante")==0){
                                printf("[4] Responder un cuestionario\n");
                            }
                            //Opciones para todos los usuarios
                            printf("[5] Cambiar mi contrase�a\n");
                            printf("[9] Salir del sistema\n");
                            printf("-------------------------------------------------------\n");

                            printf("Su selecci�n-->");
                            scanf("%d",&opcionPrincipal);
                            system("cls");

                            switch(opcionPrincipal){
                                case 1:
                                    //Mira si tiene permiso
                                    if(strcmp(usuarioLogeado.rol,"docente")==0){
                                        //Llama al manejo de cuestionarios pasando el id del usuario como argumento
                                        manejoCuestionarios(usuarioLogeado.id);
                                    }
                                    else{
                                        printf("No tiene permiso para esta opci�n!...");
                                        system("pause");
                                        system("cls");
                                    }
                                    break;
                                case 2:
                                    //Mira si tiene permiso
                                    if(strcmp(usuarioLogeado.rol,"docente")==0){
                                        //Llama al manejo de usuarios pasando el id del usuario como argumento
                                        manejoUsuarios(usuarioLogeado.id);
                                    }
                                    else{
                                        printf("No tiene permiso para esta opci�n!...");
                                        system("pause");
                                        system("cls");
                                    }
                                    break;
                                case 3:
                                    //Mira si tiene permiso
                                    if(strcmp(usuarioLogeado.rol,"docente")==0){
                                        //Llama a la funcion de responder cuestionarios con el id como argumento
                                        manejoReportes(usuarioLogeado.id);
                                    }
                                    else{
                                        printf("No tiene permiso para esta opci�n!...");
                                        system("pause");
                                        system("cls");
                                    }
                                    break;
                                case 4:
                                    //Mira si tiene permiso
                                    if(strcmp(usuarioLogeado.rol,"estudiante")==0){
                                        //Llama a la funcion de responder cuestionarios con el id como argumento
                                        responderCuestionario(usuarioLogeado.id);
                                    }
                                    else{
                                        printf("No tiene permiso para esta opci�n!...");
                                        system("pause");
                                        system("cls");
                                    }
                                    break;
                                case 5:
                                    cambiarContrasenia(usuarioLogeado.id);
                                    break;
                                case 9:
                                    //Sale del sistema (evaluacion en el while)
                                    printf("Saliendo del sistema......\n");
                                    break;
                                default:
                                    //Cualquier otra opci�n es inv�lida
                                    printf("Opci�n seleccionada es inv�lida!!!\n");
                                    Sleep(1000);
                                    system("cls");
                                    break;
                            }
                        }
                        while(opcionPrincipal!=9);
                        break;
                    }else{
                        //Si no coincide la contrase�a la pide nuevamente
                        printf("----Contrase�a incorrecta! Ingrese contrase�a nuevamente...-----\n");
                        printf("para salir presione CTRL + C \n\n");
                    }
                }
                while(1);//Repite ciclo para pedir contrase�a de forma permanente
            }
            else{
                printf("----El usuario %s no est� activo -----\n",idUsuario);
            }
        }
    }
    if(encontrado==0){//Si la variable de control esta en cero significa que no encontr� al usuario en el archivo de usuarios
        printf("----El usuario %s no est� registrado -----\n",idUsuario);
    }

    //termina el programa
    return 0;
}
