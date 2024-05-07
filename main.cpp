#include <iostream>
#include "ListaDeEstacion.h"
#include "NodoEst.h"
#include "Linea.h"

using namespace std;

int main()
{
    //cout << "Hello World!" << endl;
    ListaDeEstacion l;
    //l.aggEstacion(*new NodoEst("san antonio"),nullptr);
    //l.aggEstacion(*new NodoEst("parque berrio"),nullptr);
    //l.aggEstacion(*new NodoEst("prado"),nullptr);
    //l.aggEstacion(*new NodoEst("hospital"),nullptr);

    //l.imprimirNombresEstaciones();

    //l.eiminarEstacion("parque berrio1");

    //cout << endl << endl;
    //l.imprimirNombresEstaciones();


    Linea linea("linea a");
    linea.estaciones.aggEstacion(*new NodoEst("san antonio"),nullptr);
    linea.estaciones.aggEstacion(*new NodoEst("parque berrio"),nullptr);
    linea.estaciones.aggEstacion(*new NodoEst("prado"),nullptr);
    linea.estaciones.aggEstacion(*new NodoEst("hospital"),nullptr);


    Linea linea1("linea b");
    linea1.estaciones.aggEstacion(*new NodoEst("san antonio"),nullptr);
    linea1.estaciones.aggEstacion(*new NodoEst("exposiciones"),nullptr);
    linea1.estaciones.aggEstacion(*new NodoEst("tricentenario"),nullptr);
    linea1.estaciones.aggEstacion(*new NodoEst("udea"),nullptr);


    Linea linea2("linea c");
    linea2.estaciones.aggEstacion(*new NodoEst("niquia"),nullptr);
    linea2.estaciones.aggEstacion(*new NodoEst("miraflores"),nullptr);
    linea2.estaciones.aggEstacion(*new NodoEst("san jose"),nullptr);
    linea2.estaciones.aggEstacion(*new NodoEst("envigado"),nullptr);

    cout << linea.nombre << ":"<< endl;
    linea.estaciones.imprimirNombresEstaciones();

    cout << endl;

    cout << linea1.nombre << ":"<< endl;
    linea1.estaciones.imprimirNombresEstaciones();

    cout << endl;


    cout << linea2.nombre << ":"<< endl;
    linea2.estaciones.imprimirNombresEstaciones();



    //cout << "numero de estaciones: " << l.getNroEstaciones()<<endl;
    return 0;
}
