#ifndef LINEA_H
#define LINEA_H
#include "ListaDeEstacion.h"

class Linea
{
public:
    //atributos
    const char *nombre;
    ListaDeEstacion estaciones;
    //metodos
    Linea(const char *nombre);
    //bool getEstavacia();
    bool estaVacia();

//private:
    //atributos



};

#endif // LINEA_H
