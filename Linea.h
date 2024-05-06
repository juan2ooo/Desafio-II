#ifndef LINEA_H
#define LINEA_H
#include "ListaDeEstacion.h"

class Linea
{
public:
    //atributos
    char *nombre;
    //metodos
    Linea(char *nombre);

private:
    //atributos
    ListaDeEstacion estaciones;


};

#endif // LINEA_H
