#ifndef TIEMPO_H
#define TIEMPO_H
#include <iostream>

using namespace std;

class Tiempo {
private:
    int hora;
    int minuto;
    int segundo;

public:
    // Constructor que obligatoriamente recibe hora, minuto y segundo
    Tiempo(int h, int m, int s);
    void horaDeLlegada( float horas);
    static void imprimirTiempo(float horasDecimal);

};

#endif // TIEMPO_H
