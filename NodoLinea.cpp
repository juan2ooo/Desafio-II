#include "NodoLinea.h"

NodoLinea::NodoLinea(const char *nombreEst) {
    linea = new Linea(nombreEst);
}


NodoLinea::~NodoLinea(){
    delete linea;
}
