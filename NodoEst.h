#ifndef NODOEST_H
#define NODOEST_H
#include "Estacion.h"
class NodoEst
{
public:
    NodoEst *siguiente, *anterior;

    NodoEst(char *nombreEstacion);
    Estacion *estacion;
};

#endif // NODOEST_H
