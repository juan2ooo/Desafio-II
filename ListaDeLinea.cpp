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

NodoLinea *ListaDeLinea::buscar(const char *s){
    ptrNodoLinea = primerNodoLinea->siguiente;
    NodoLinea *ant = primerNodoLinea;
    while(ptrNodoLinea != nullptr){
        ptrNodoLinea = ptrNodoLinea ->siguiente;
        ant = ant->siguiente;
        if(ptrNodoLinea->linea->nombre == s){
            return ant;
        }
    }
    return nullptr;
}

void ListaDeLinea::eliminarLinea(NodoLinea &l){ // elimina al siguiente de este
    if(primerNodoLinea == nullptr){
        cout << "no se puede eliminar, lista vacia" << endl;
    }
    if(sePuedeEliminar(l)){

        if(&l == primerNodoLinea){ //si es el primer nodo
            delete &l;
        }else{
            l.siguiente = l.siguiente->siguiente;
            delete (l.siguiente);
        }

    }else{
        cout << "No se completo la operacion, no se puede eliminar lineas con estaciones"<<endl;
    }
}

bool ListaDeLinea::petenece(Linea &l){
    return (buscar(l.nombre) == nullptr);
}


