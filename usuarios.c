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
    int encontrado; //variable de control para saber si se encuentra un usuario
    int respuesta; //variable de control para saber la respuesta del usuario
    //Ciclo do...while para repetir el menu hasta que se selecciona 9 para salir al menu principal
    do{
        printf("-------------------------------------------------------\n");
        printf("Sistema de evaluaciones ISI - UCA - Manejo de usuarios\n");
        printf("%s %s\n","Usuario actual: ", id);
        printf("-------------------------------------------------------\n");
        fflush(stdout);
        printf("[1] Agregar usuario\n");
        printf("[2] Modificar usuario\n");
        printf("[3] Anular usuario\n");
        printf("[4] Activar usuario\n");
        printf("[5] Listar usuarios\n");
        printf("[6] Buscar un usuario\n");
        printf("[9] Regresar a menú principal\n");
        printf("-------------------------------------------------------\n");
        fflush(stdout);
        printf("Su selección-->");
        fflush(stdout);
        scanf("%d",&opcionUsuarios);
        fflush(stdin);
        system("cls");

        switch(opcionUsuarios){
        case 1:
            //Abre el archivo para agregar
            f = fopen("Usuarios.txt","a");
            printf("-------------------------------------------------------\n");
            printf("Ingresando nuevo usuario\n");
            printf("-------------------------------------------------------\n");
            fflush(stdout);
            //pedir datos al usuario actual
            printf("Ingrese el id-->");
            fflush(stdout);
            scanf("%s",usuario.id);
            fflush(stdin);
            printf("Ingrese el nombre-->");
            fflush(stdout);
            gets(usuario.nombre);
            fflush(stdin);

            do{
                printf("Ingrese el rol (docente o estudiante)-->");
                fflush(stdout);
                scanf("%s",usuario.rol);
                fflush(stdin);
            }
            while(!(strcmp(usuario.rol,"docente")==0 || strcmp(usuario.rol,"estudiante")==0));//Pedir el rol hasta que escriban docente o estudiante

            printf("Ingrese la contraseña-->");
            fflush(stdout);
            scanf("%s",usuario.contrasenia);
            fflush(stdin);
            usuario.activo=1;//Usuario activo cuando se crea
            //Escribir al usuario en el archivo
            fwrite(&usuario, sizeof(usuario),1,f);
            fclose(f);
            printf("Registro guardado\n");
            fflush(stdout);
            Sleep(1000);
            system("cls");
            break;
        case 2:
            //Abre el archivo en modo lectura y escritura
            f = fopen("Usuarios.txt","r+");
            printf("-------------------------------------------------------\n");
            printf("Modificar un usuario\n");
            printf("-------------------------------------------------------\n");
            fflush(stdout);
            //pedir datos del usuario a buscar
            printf("Ingrese el id del usuario a buscar-->");
            fflush(stdout);
            scanf("%s",idBuscar);
            fflush(stdin);

            //Leer el contenido del archivo y busca el usuario por el id
            encontrado=0; //Inicializa la variable de control en usuario aun no encontrado
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
                    fflush(stdout);

                    printf("-------------------------------------------------------\n");
                    printf("Ingresando los nuevos datos del usuario\n");
                    printf("-------------------------------------------------------\n");
                    fflush(stdout);

                    fflush(stdin);
                    printf("Ingrese el nuevo nombre-->");
                    fflush(stdout);
                    gets(usuario.nombre);
                    fflush(stdin);

                    do{
                        printf("Ingrese el nuevo rol (docente o estudiante)-->");
                        fflush(stdout);
                        scanf("%s",usuario.rol);
                        fflush(stdin);
                    } while(!(strcmp(usuario.rol,"docente")==0 || strcmp(usuario.rol,"estudiante")==0));//Pedir el rol hasta que escriban docente o estudiante

                    printf("Ingrese la nueva contraseña-->");
                    fflush(stdout);
                    scanf("%s",usuario.contrasenia);
                    fflush(stdin);

                    //Busca la posición del usuario en el archivo
                    fseek(f,i*sizeof(usuario),SEEK_SET);
                    //Escribe el usuario en esa posición
                    fwrite(&usuario,sizeof(usuario),1,f);
                    printf("Registro modificado\n");
                    fflush(stdout);
                    encontrado = 1; //Si se encuentra un usuario la variable de control se cambia a encontrado
                    break; //Finaliza la modificacion de usuario, termina el ciclo de busqueda
                }
                i++;//Si no lo encuentra aumenta el contador a un registro mas
            }
            if(encontrado==0){//Si la variable de control esta en cero significa que no encontró al usuario en el archivo de usuarios
                printf("----El usuario %s no está registrado -----\n",idBuscar);
                fflush(stdout);
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
            fflush(stdout);
            //pedir datos del usuario a anular
            printf("Ingrese el id del usuario a anular-->");
            fflush(stdout);
            scanf("%s",idBuscar);
            fflush(stdin);

            //Leer el contenido del archivo y busca el usuario por el id
            encontrado=0; //Inicializa la variable de control en no encontrado
            i=0; //Inicializa el contador a cero que es el inicio del archivo
            respuesta=2; //Inicializa la variable para la respuesta del usuario en No
            while(fread(&usuario,sizeof(struct Usuario),1,f)){//Lee el archivo con el tamaño de la  estructura Usuario
                if(strcmp(idBuscar,usuario.id)==0){
                    //Si encuentra el usuario presenta los datos en pantalla y pregunta si va a anular el registro
                    printf("----Datos actuales almacenados----------------\n");
                    printf("%s %s\n","Id: ",usuario.id);
                    printf("%s %s\n","Nombre: ",usuario.nombre);
                    printf("%s %s\n","Rol: ",usuario.rol);
                    printf("%s %d\n","Activo: ",usuario.activo);
                    printf("----------------------------------------------\n");
                    fflush(stdout);

                    do{
                        printf("Desea anular este usuario? (1=Si, 2=No)-->");
                        fflush(stdout);
                        scanf("%d",&respuesta);
                        fflush(stdin);
                    } while(!(respuesta==1 || respuesta==2));//Repetir hasta que sea 1 o 2

                    if(respuesta==1){
                        usuario.activo=0;
                        //Busca la posición del usuario en el archivo
                        fseek(f,i*sizeof(usuario),SEEK_SET);
                        //Escribe el usuario en esa posición
                        fwrite(&usuario,sizeof(usuario),1,f);
                        printf("Usuario anulado!\n");
                        fflush(stdout);
                    }
                    encontrado=1; //Si se encuentra un usuario se cambia la variable de control a encontrado
                    break; //Finaliza la modificacion de usuario, termina el ciclo de busqueda
                }
                i++;//Si no lo encuentra aumenta el contador a un registro mas
            }
            if(encontrado==0){//Si la variable de control esta en cero significa que no encontró al usuario en el archivo de usuarios
                printf("----El usuario %s no está registrado -----\n",idBuscar);
                fflush(stdout);
            }
            //Cerrar el archivo
            fclose(f);
            system("pause");
            system("cls");
            break;
        case 4:
            //Abre el archivo en modo lectura y escritura
            f = fopen("Usuarios.txt","r+");
            printf("-------------------------------------------------------\n");
            printf("Activar un usuario\n");
            printf("-------------------------------------------------------\n");
            fflush(stdout);
            //pedir datos del usuario a activar
            printf("Ingrese el id del usuario a activar-->");
            fflush(stdout);
            scanf("%s",idBuscar);
            fflush(stdin);

            //Leer el contenido del archivo y busca el usuario por el id
            encontrado=0; //Inicializa la variable de control en no encontrado
            i=0; //Inicializa el contador a cero que es el inicio del archivo
            respuesta=2; //Inicializa la variable para la respuesta del usuario en No
            while(fread(&usuario,sizeof(struct Usuario),1,f)){//Lee el archivo con el tamaño de la  estructura Usuario
                if(strcmp(idBuscar,usuario.id)==0){
                    //Si encuentra el usuario presenta los datos en pantalla y pregunta si va a activar el registro
                    printf("----Datos actuales almacenados----------------\n");
                    printf("%s %s\n","Id: ",usuario.id);
                    printf("%s %s\n","Nombre: ",usuario.nombre);
                    printf("%s %s\n","Rol: ",usuario.rol);
                    printf("%s %d\n","Activo: ",usuario.activo);
                    printf("----------------------------------------------\n");
                    fflush(stdout);

                    do{
                        printf("Desea activar este usuario? (1=Si, 2=No)-->");
                        fflush(stdout);
                        scanf("%d",&respuesta);
                        fflush(stdin);
                    } while(!(respuesta==1 || respuesta==2));//Repetir hasta que sea 1 o 2

                    if(respuesta==1){
                        usuario.activo=1;
                        //Busca la posición del usuario en el archivo
                        fseek(f,i*sizeof(usuario),SEEK_SET);
                        //Escribe el usuario en esa posición
                        fwrite(&usuario,sizeof(usuario),1,f);
                        printf("Usuario activado!\n");
                        fflush(stdout);
                    }
                    encontrado=1; //Si se encuentra un usuario se cambia la variable de control a encontrado
                    break; //Finaliza la modificacion de usuario, termina el ciclo de busqueda
                }
                i++;//Si no lo encuentra aumenta el contador a un registro mas
            }
            if(encontrado==0){//Si la variable de control esta en cero significa que no encontró al usuario en el archivo de usuarios
                printf("----El usuario %s no está registrado -----\n",idBuscar);
                fflush(stdout);
            }
            //Cerrar el archivo
            fclose(f);
            system("pause");
            system("cls");
            break;
        case 5:
            //consulta todos los usuarios
            printf("-------------------------------------------------------------------\n");
            printf("Listado de usuarios en el Sistema de evaluaciones ISI - UCA\n");
            printf("-------------------------------------------------------------------\n");
            fflush(stdout);
            f = fopen("Usuarios.txt","r");
            printf("%-20s%-20s%-20s%10s\n","Id","Nombre","Rol","Activo");
            fflush(stdout);
            while(fread(&usuario,sizeof(struct Usuario),1,f)){//Lee el archivo con el tamaño de la  estructura Usuario
                printf("%-20s%-20s%-20s%10d\n",usuario.id,usuario.nombre,usuario.rol,usuario.activo);
                fflush(stdout);
            }
            fclose(f);
            system("pause");
            system("cls");
            break;
        case 6:
            //Abre el archivo en modo lectura
            f = fopen("Usuarios.txt","r");
            printf("-------------------------------------------------------\n");
            printf("Datos de un usuario\n");
            printf("-------------------------------------------------------\n");
            fflush(stdout);
            //pedir datos del usuario a buscar
            printf("Ingrese el id del usuario a buscar-->");
            fflush(stdout);
            scanf("%s",idBuscar);
            fflush(stdin);

            //Leer el contenido del archivo y busca el usuario por el id
            encontrado=0; //Inicializa la variable de control en usuario aun no encontrado
            while(fread(&usuario,sizeof(struct Usuario),1,f)){//Lee el archivo con el tamaño de la  estructura Usuario
                if(strcmp(idBuscar,usuario.id)==0){
                    //Si encuentra el usuario presenta los datos en pantalla y pide los nuevos datos
                    printf("----Datos actuales almacenados----------------\n");
                    printf("%s %s\n","Id: ",usuario.id);
                    printf("%s %s\n","Nombre: ",usuario.nombre);
                    printf("%s %s\n","Rol: ",usuario.rol);
                    printf("%s %d\n","Activo: ",usuario.activo);
                    printf("----------------------------------------------\n");
                    fflush(stdout);
                    encontrado = 1; //Si se encuentra un usuario la variable de control se cambia a encontrado
                    break; //Finaliza la modificacion de usuario, termina el ciclo de busqueda
                }
            }
            if(encontrado==0){//Si la variable de control esta en cero significa que no encontró al usuario en el archivo de usuarios
                printf("----El usuario %s no está registrado -----\n",idBuscar);
                fflush(stdout);
            }
            //Cerrar el archivo
            fclose(f);
            system("pause");
            system("cls");
            break;
        case 9:
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

    }while(opcionUsuarios!=9);
    return 0;
}
