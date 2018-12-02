/******

Estructura usuario para almacenar datos del usuario



******/
#ifndef USUARIOS_H_INCLUDED
#define USUARIOS_H_INCLUDED

struct Usuario
{
    char id[25];
    char nombre[50];
    char rol[15];
    char contrasenia[30]; //
    int activo; //Indica si el usuario esta activo 1 es Si 0 es No
} ;

#endif // USUARIOS_H_INCLUDED
