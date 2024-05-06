#include "ListaDeLinea.h"

ListaDeLinea::ListaDeLinea() {}



void ListaDeLinea::aggLinea(NodoLinea &l) { //este metodo inseta datos al final
    if (primerNodoLinea == nullptr) { //si esta vacio
        primerNodoLinea = &l;
        l.siguiente = nullptr;
    } else {
        l.siguiente = primerNodoLinea;
        primerNodoLinea = &l;
    }
}

bool ListaDeLinea::sePuedeEliminar(NodoLinea &l){return l.linea->estaVacia();}


