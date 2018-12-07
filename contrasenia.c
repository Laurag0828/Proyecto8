#include <stdio.h>//Funciones basicas de entrada salida
#include <locale.h>//Para presentar caracteres en espa�ol
#include <windows.h>//Para usar la funcion Sleep, system
#include "Usuarios.h"//Incluir el dato de tipo Usuario
/***

Archivo fuente para cambiar contrase�a

***/


int cambiarContrasenia(char id[25])
{
    FILE *f; //Apuntador para abrir archivos
    struct Usuario usuario; //Para manejo de usuarios
    int i; //Contador para encontrar la posicion del usuario en el archivo
    //Abre el archivo en modo lectura y escritura
    f = fopen("Usuarios.txt","r+");
    printf("-------------------------------------------------------\n");
    printf("Cambiar contrase�a\n");
    printf("-------------------------------------------------------\n");


    //Leer el contenido del archivo y busca el usuario por el id
    i=0; //Inicializa el contador a cero que es el inicio del archivo
    while(fread(&usuario,sizeof(struct Usuario),1,f)){//Lee el archivo con el tama�o de la  estructura Usuario
        if(strcmp(id,usuario.id)==0){
            fflush(stdin);
            printf("Ingrese la nueva contrase�a-->");
            scanf("%s",usuario.contrasenia);
            fflush(stdin);
            //Busca la posici�n del usuario en el archivo
            fseek(f,i*sizeof(usuario),SEEK_SET);
            //Escribe el usuario en esa posici�n
            fwrite(&usuario,sizeof(usuario),1,f);
            printf("Contrase�a modificada....\n");
            break; //Finaliza la modificacion de usuario, termina el ciclo de busqueda
        }
        i++;//Si no lo encuentra aumenta el contador a un registro mas
    }
    //Cerrar el archivo
    fclose(f);
    system("pause");
    system("cls");
    return 0;
}
