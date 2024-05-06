#ifndef LISTADEESTACION_H
#define LISTADEESTACION_H
#include "NodoEst.h"
//#include "Estacion.h"
class ListaDeEstacion
{
public:
    //atributos
    NodoEst *prtNodoEst;
    ListaDeEstacion();

    //metodos
    void aggEstacion(char *nombre);
    void eiminarEstacion(char *nombre);
    bool tieneEstacion(Estacion e);

private:
    //atributos
    NodoEst *primeraNodoEst,*ultimoNodoEst;
    static unsigned short nroEstaciones;

    //metodos
    void BuscarEstacion(char *nombre);
};

#endif // LISTADEESTACION_H
