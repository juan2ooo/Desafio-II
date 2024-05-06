#ifndef LINEA_H
#define LINEA_H
#include "ListaDeEstacion.h"

class Linea
{
public:
    char *nombre;
    Linea *siguiente;
    Linea(char *nombre);

private:
    ListaDeEstacion estaciones;
    static unsigned short nroEstaciones;

};

#endif // LINEA_H
