#ifndef NODOEST_H
#define NODOEST_H
#include "Estacion.h"
class NodoEst
{
public:
    NodoEst *siguiente, *anterior;
    NodoEst(const char *nombreEstacion);
    Estacion *estacion;
    ~NodoEst();
};

#endif // NODOEST_H
