#ifndef LISTADELINEA_H
#define LISTADELINEA_H
#include "NodoLinea.h"
#include "utilidades.h"


class ListaDeLinea
{
public:
    ListaDeLinea();
    void aggLinea(NodoLinea &l);
    void eliminarLinea(NodoLinea &l);
    bool petenece(Linea &l);
    void imprimirNombresLineas();
    void aggEstTrasferencia(Linea *l1, const char *estAntes1, Linea *l2, const char *estAntes2);
    const char *nombreEstTransf(const char *nombre, Linea *l1);
    char *redimensionar(char *nombre, short &tam);
    NodoLinea *buscar(const char *s);
private:
    NodoLinea *primerNodoLinea;
    static unsigned short nroLinea;
    //void BuscarLinea(char *nombre);
    bool sePuedeEliminar(NodoLinea &l);

    NodoLinea *ptrNodoLinea;
};

#endif // LISTADELINEA_H
