#ifndef LISTADELINEA_H
#define LISTADELINEA_H
#include "NodoLinea.h"

class ListaDeLinea
{
public:
    ListaDeLinea();
    NodoLinea *ptrNodoLinea;
    void aggLinea(NodoLinea &l);
    void eliminarLinea(NodoLinea &l);
    bool petenece(Linea l);
private:
    NodoLinea *primerNodoLinea, *ultimoNodoLinea;
    static unsigned short nroLinea;
    void BuscarLinea(char *nombre);
    bool sePuedeEliminar(NodoLinea &l);
};

#endif // LISTADELINEA_H
