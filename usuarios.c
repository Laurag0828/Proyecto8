#include <stdio.h>//Funciones basicas de entrada salida
#include <locale.h>//Para presentar caracteres en español
#include <windows.h>//Para usar la funcion Sleep, system
#include "Usuarios.h"//Incluir el dato de tipo Usuario
/***

Archivo fuente para el manejo de usuarios

***/


int manejoUsuarios(char id[25])
{
    //Variable para el control del menu de usuarios
    int opcionUsuarios;
    FILE *f; //Apuntador para abrir archivos
    struct Usuario usuario; //Para manejo de usuarios
    char idBuscar[20]; //Para buscar un usuario
    int i; //Contador para encontrar la posicion del usuario en el archivo
    int j; //variable de control para saber si se encuentra un usuario
    int k; //variable de control para saber la respuesta del usuario
    //Ciclo do...while para repetir el menu hasta que se selecciona 9 para salir al menu principal
    do{
        printf("-------------------------------------------------------\n");
        printf("Sistema de evaluaciones ISI - UCA - Manejo de usuarios\n");
        printf("%s %s\n","Usuario actual: ", id);
        printf("-------------------------------------------------------\n");
        printf("1. Agregar usuario\n");
        printf("2. Modificar usuario\n");
        printf("3. Anular usuario\n");
        printf("4. Listar usuarios\n");
        printf("9. Regresar a menú principal\n");

        printf("-------------------------------------------------------\n");
        printf("Su selección-->");
        scanf("%d",&opcionUsuarios);
        system("cls");

        switch(opcionUsuarios){
        case 1:
            //Abre el archivo para agregar
            f = fopen("Usuarios.txt","a");
            printf("-------------------------------------------------------\n");
            printf("Ingresando nuevo usuario\n");
            printf("-------------------------------------------------------\n");
            //pedir datos al usuario actual
            printf("Ingrese el id-->");
            scanf("%s",usuario.id);
            fflush(stdin);
            printf("Ingrese el nombre-->");
            gets(usuario.nombre);
            fflush(stdin);

            do{
                printf("Ingrese el rol (docente o estudiante)-->");
                scanf("%s",usuario.rol);
                fflush(stdin);
            }
            while(!(strcmp(usuario.rol,"docente")==0 || strcmp(usuario.rol,"estudiante")==0));//Pedir el rol hasta que escriban docente o estudiante

            printf("Ingrese la contraseña-->");
            scanf("%s",usuario.contrasenia);
            fflush(stdin);
            usuario.activo=1;//Usuario activo cuando se crea
            //Escribir al usuario en el archivo
            fwrite(&usuario, sizeof(usuario),1,f);
            fclose(f);
            printf("Registro guardado\n");
            Sleep(1000);
            system("cls");
            break;
        case 2:
            //Abre el archivo en modo lectura y escritura
            f = fopen("Usuarios.txt","r+");
            printf("-------------------------------------------------------\n");
            printf("Modificar un usuario\n");
            printf("-------------------------------------------------------\n");
            //pedir datos del usuario a buscar
            printf("Ingrese el id del usuario a buscar-->");
            scanf("%s",idBuscar);

            //Leer el contenido del archivo y busca el usuario por el id
            j=0; //Inicializa la variable de control que indica cuando se encuenta un usuario
            i=0; //Inicializa el contador a cero que es el inicio del archivo
            while(fread(&usuario,sizeof(struct Usuario),1,f)){//Lee el archivo con el tamaño de la  estructura Usuario
                if(strcmp(idBuscar,usuario.id)==0){
                    //Si encuentra el usuario presenta los datos en pantalla y pide los nuevos datos
                    printf("----Datos actuales almacenados----------------\n");
                    printf("%s %s\n","Id: ",usuario.id);
                    printf("%s %s\n","Nombre: ",usuario.nombre);
                    printf("%s %s\n","Rol: ",usuario.rol);
                    printf("%s %d\n","Activo: ",usuario.activo);
                    printf("----------------------------------------------\n");

                    printf("-------------------------------------------------------\n");
                    printf("Ingresando los nuevos datos del usuario\n");
                    printf("-------------------------------------------------------\n");

                    fflush(stdin);
                    printf("Ingrese el nuevo nombre-->");
                    gets(usuario.nombre);
                    fflush(stdin);

                    do{
                        printf("Ingrese el nuevo rol (docente o estudiante)-->");
                        scanf("%s",usuario.rol);
                        fflush(stdin);
                    } while(!(strcmp(usuario.rol,"docente")==0 || strcmp(usuario.rol,"estudiante")==0));//Pedir el rol hasta que escriban docente o estudiante

                    printf("Ingrese la nueva contraseña-->");
                    scanf("%s",usuario.contrasenia);
                    fflush(stdin);

                    do{
                        printf("Es usuario activo? (1=Si, 0=No)-->");
                        scanf("%d",&usuario.activo);
                        fflush(stdin);
                    } while(!(usuario.activo==1 || usuario.activo==0));//Repetir hasta que sea 1 o 0

                    //Busca la posición del usuario en el archivo
                    fseek(f,i*sizeof(usuario),SEEK_SET);
                    //Escribe el usuario en esa posición
                    fwrite(&usuario,sizeof(usuario),1,f);
                    printf("Registro modificado\n");
                    j++; //Si se encuentra un usuario se aumenta la variable de control en 1
                    break; //Finaliza la modificacion de usuario, termina el ciclo de busqueda
                }
                i++;//Si no lo encuentra aumenta el contador a un registro mas
            }
            if(j==0){//Si la variable de control esta en cero significa que no encontró al usuario en el archivo de usuarios
                printf("----El usuario %s no está registrado -----\n",idBuscar);
            }
            //Cerrar el archivo
            fclose(f);
            system("pause");
            system("cls");
            break;
        case 3:
            //Abre el archivo en modo lectura y escritura
            f = fopen("Usuarios.txt","r+");
            printf("-------------------------------------------------------\n");
            printf("Anular un usuario\n");
            printf("-------------------------------------------------------\n");
            //pedir datos del usuario a anular
            printf("Ingrese el id del usuario a anular-->");
            scanf("%s",idBuscar);

            //Leer el contenido del archivo y busca el usuario por el id
            j=0; //Inicializa la variable de control que indica cuando se encuenta un usuario
            i=0; //Inicializa el contador a cero que es el inicio del archivo
            k=0; //Inicializa la variable para la respuesta del usuario
            while(fread(&usuario,sizeof(struct Usuario),1,f)){//Lee el archivo con el tamaño de la  estructura Usuario
                if(strcmp(idBuscar,usuario.id)==0){
                    //Si encuentra el usuario presenta los datos en pantalla y pide los nuevos datos
                    printf("----Datos actuales almacenados----------------\n");
                    printf("%s %s\n","Id: ",usuario.id);
                    printf("%s %s\n","Nombre: ",usuario.nombre);
                    printf("%s %s\n","Rol: ",usuario.rol);
                    printf("%s %d\n","Activo: ",usuario.activo);
                    printf("----------------------------------------------\n");

                    do{
                        printf("Desea anular este usuario? (1=Si, 2=No)-->");
                        scanf("%d",&k);
                        fflush(stdin);
                    } while(!(k==1 || k==2));//Repetir hasta que sea 1 o 2

                    if(k==1){
                        usuario.activo=0;
                        //Busca la posición del usuario en el archivo
                        fseek(f,i*sizeof(usuario),SEEK_SET);
                        //Escribe el usuario en esa posición
                        fwrite(&usuario,sizeof(usuario),1,f);
                        printf("Usuario anulado\n");
                    }
                    j++; //Si se encuentra un usuario se aumenta la variable de control en 1
                    break; //Finaliza la modificacion de usuario, termina el ciclo de busqueda
                }
                i++;//Si no lo encuentra aumenta el contador a un registro mas
            }
            if(j==0){//Si la variable de control esta en cero significa que no encontró al usuario en el archivo de usuarios
                printf("----El usuario %s no está registrado -----\n",idBuscar);
            }
            //Cerrar el archivo
            fclose(f);
            system("pause");
            system("cls");
            break;
        case 4:
            //consulta todos los usuarios
            printf("-------------------------------------------------------------------\n");
            printf("Listado de usuarios en el Sistema de evaluaciones ISI - UCA\n");
            printf("-------------------------------------------------------------------\n");
            f = fopen("Usuarios.txt","r");
            printf("%-20s%-20s%-20s%10s\n","Id","Nombre","Rol","Activo");
            while(fread(&usuario,sizeof(struct Usuario),1,f)){//Lee el archivo con el tamaño de la  estructura Usuario
                printf("%-20s%-20s%-20s%10d\n",usuario.id,usuario.nombre,usuario.rol,usuario.activo);
            }
            fclose(f);
            system("pause");
            system("cls");
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

    }while(opcionUsuarios!=9);
    return 0;
}
