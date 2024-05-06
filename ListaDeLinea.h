#ifndef LISTADELINEA_H
#define LISTADELINEA_H
#include "NodoLinea.h"
class ListaDeLinea
{
public:
    ListaDeLinea();
    NodoLinea *ptrNodoLinea;
    void aggLinea(char *nombre);
    void eliminarLinea(char *nombre);
    bool petenece(Linea l);
private:
    NodoLinea *primerNodoLinea, *ultimaNodoLinea;
    static unsigned short nroLinea;
    void BuscarLinea(char *nombre);
};

#endif // LISTADELINEA_H
