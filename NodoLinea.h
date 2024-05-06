#ifndef NODOLINEA_H
#define NODOLINEA_H
#include "Linea.h"
class NodoLinea
{
public:
    NodoLinea *siguiente;
    Linea *linea;
    NodoLinea(char *nombreEst);
};

#endif // NODOLINEA_H
