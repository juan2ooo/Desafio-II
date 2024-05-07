#ifndef LISTADEESTACION_H
#define LISTADEESTACION_H
#include <iostream>
#include "NodoEst.h"
#include "Estacion.h"
using namespace std;
class ListaDeEstacion
{
public:
    //atributos
    NodoEst *prtNodoEst;
    ListaDeEstacion();
    ~ListaDeEstacion();

    //metodos
    void aggEstacion(NodoEst &est,const char *nombreAntes); //solo ajusta los tiempor cuando se ingresan a estaciones intermedias
    void eiminarEstacion(const char *s);
    bool tieneEstacion(Estacion e);
    void imprimirNombresEstaciones();
    bool estaVacia();
    unsigned short getNroEstaciones();


private:
    //atributos
    NodoEst *primerNodoEst,*ultimoNodoEst, *ptrNodoEst;
    static unsigned short nroEstaciones;

    //metodos
    NodoEst *buscarEstacion(const char *nombre);
    void reajustarTiempos(Estacion *e1, Estacion *e2, bool caso);
};

#endif // LISTADEESTACION_H
