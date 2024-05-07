#include "Linea.h"

Linea::Linea(const char *nombreEst) {
    nombre = nombreEst;
}


bool Linea::estaVacia(){
    return estaciones.estaVacia();
}

