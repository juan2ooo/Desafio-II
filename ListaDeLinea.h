#ifndef LISTADELINEA_H
#define LISTADELINEA_H
#include "NodoLinea.h"
#include "utilidades.h"


class ListaDeLinea
{
public:
    ListaDeLinea();

    void aggLinea(NodoLinea &l);
    void eliminarLinea(const char *l);
    bool petenece(const char *l);
    void imprimirNombresLineas();
    void aggEstTrasferencia(Linea *l1, NodoEst *est1, Linea *l2, NodoEst *est2,const char *nuevoNombre);
    const char *nombreEstTransf(const char *nombre, Linea *l1);
    char *redimensionar(char *nombre, short &tam);
    NodoLinea *buscar(const char *s);
    static unsigned short getNrolineas();
    float calculoEst();
private:
    NodoLinea *primerNodoLinea;
    static unsigned short nroLinea;
    //void BuscarLinea(char *nombre);
    NodoLinea *buscarAnt(const char *s);
    bool sePuedeEliminar(NodoLinea &l);

    NodoLinea *ptrNodoLinea;
};

#endif // LISTADELINEA_H
