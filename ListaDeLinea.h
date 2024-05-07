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
    void aggEstTrasferencia(const char *nombre, Linea *l1, const char *estAntes1, Linea *l2, const char *estAntes2);
    const char *nombreEstTransf(const char *nombre, Linea *l1);
    const char *redimensionar(const char *nombre);
private:
    NodoLinea *primerNodoLinea;
    static unsigned short nroLinea;
    //void BuscarLinea(char *nombre);
    bool sePuedeEliminar(NodoLinea &l);
    NodoLinea *buscar(const char *s);
    NodoLinea *ptrNodoLinea;
};

#endif // LISTADELINEA_H
