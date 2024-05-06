#ifndef LISTADEESTACION_H
#define LISTADEESTACION_H
#include <iostream>
#include "NodoEst.h"
using namespace std;
class ListaDeEstacion
{
public:
    //atributos
    NodoEst *prtNodoEst;
    ListaDeEstacion();
    ~ListaDeEstacion();

    //metodos
    void aggEstacion(NodoEst &est,const char *nombreAntes);
    void eiminarEstacion(NodoEst &est);
    bool tieneEstacion(Estacion e);
    void imprimirNombresEstaciones();
    bool estaVacia();

private:
    //atributos
    NodoEst *primerNodoEst,*ultimoNodoEst, *ptrNodoEst;
    static unsigned short nroEstaciones;

    //metodos
    NodoEst *buscarEstacion(const char *nombre);
};

#endif // LISTADEESTACION_H
