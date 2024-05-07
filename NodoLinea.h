#ifndef NODOLINEA_H
#define NODOLINEA_H
#include "Linea.h"
class NodoLinea
{
public:
    NodoLinea *siguiente;
    Linea *linea;
    NodoLinea(const char *nombreEst);
    ~NodoLinea();
};

#endif // NODOLINEA_H
