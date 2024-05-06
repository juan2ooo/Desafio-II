#ifndef LISTADELINEA_H
#define LISTADELINEA_H
#include "NodoLinea.h"
class ListaDeLinea
{
public:
    ListaDeLinea();
    NodoLinea *primerNodoLinea, *ultimaNodoLinea, *ptr;
    void aggLinea(char *nombre);
    void eliminarLinea(char *nombre);
    bool petenece(Linea l);
private:
    static unsigned short nroLinea;
    void BuscarLinea(char *nombre);
};

#endif // LISTADELINEA_H
