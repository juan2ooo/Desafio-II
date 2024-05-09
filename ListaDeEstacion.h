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
    bool tieneEstacion(const char *e);
    void imprimirNombresEstaciones();
    bool estaVacia();
    unsigned short getNroEstaciones();
    NodoEst *buscarEstacion(const char *nombre);
    NodoEst *getPrimer();
    NodoEst *getUlt();


private:
    //atributos
    NodoEst *ultimoNodoEst,*primerNodoEst, *ptrNodoEst;
    static unsigned short nroEstaciones;

    //metodos

    void reajustarTiempos(Estacion *e1, Estacion *e2, bool caso);
};

#endif // LISTADEESTACION_H
