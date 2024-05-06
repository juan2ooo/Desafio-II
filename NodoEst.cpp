#include "NodoEst.h"
#include "Estacion.h"
NodoEst::NodoEst(const char *nombreEstacion) {
    estacion = new Estacion(nombreEstacion);
}

NodoEst::~NodoEst(){
    if(estacion != nullptr){
       delete estacion;
    }
}
