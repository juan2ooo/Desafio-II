#ifndef LISTADELINEA_H
#define LISTADELINEA_H
#include "NodoLinea.h"

class ListaDeLinea
{
public:
    ListaDeLinea();
    void aggLinea(NodoLinea &l);
    void eliminarLinea(NodoLinea &l);
    bool petenece(Linea &l);
    void imprimirNombresLineas();

private:
    NodoLinea *primerNodoLinea;
    static unsigned short nroLinea;
    //void BuscarLinea(char *nombre);
    bool sePuedeEliminar(NodoLinea &l);
    NodoLinea *buscar(const char *s);
    NodoLinea *ptrNodoLinea;
};

#endif // LISTADELINEA_H
