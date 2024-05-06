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
    //bool getEstavacia();
    bool estaVacia();
private:
    //atributos
    ListaDeEstacion estaciones;


};

#endif // LINEA_H
