#include <iostream>
#include "ListaDeEstacion.h"
#include "NodoEst.h"

using namespace std;

int main()
{
    //cout << "Hello World!" << endl;
    ListaDeEstacion l;
    l.aggEstacion(*new NodoEst("san antonio"),nullptr);
    l.aggEstacion(*new NodoEst("parque berrio"),nullptr);
    l.aggEstacion(*new NodoEst("prado"),nullptr);
    l.aggEstacion(*new NodoEst("hospital"),nullptr);

    l.imprimirNombresEstaciones();

    l.eiminarEstacion("parque berrio1");

    cout << endl << endl;
    l.imprimirNombresEstaciones();

    cout << "numero de estaciones: " << l.getNroEstaciones()<<endl;
    return 0;
}
