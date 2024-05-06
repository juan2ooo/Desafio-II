#include "ListaDeEstacion.h"

ListaDeEstacion::ListaDeEstacion() {
    primerNodoEst = nullptr;
    ultimoNodoEst = nullptr;
}

void ListaDeEstacion::aggEstacion(NodoEst &est, const char *nombreAntes){
    //segundo parametro para insertar el dato antes de ese, por defecto ingresa al final(se ingresa ptr en ese caso)
    if(primerNodoEst == nullptr){ //si esta vacia
        primerNodoEst = &est;
        ultimoNodoEst = primerNodoEst;
        primerNodoEst ->siguiente = nullptr;
        primerNodoEst ->anterior = nullptr;
        nroEstaciones ++;
        return;
    }

    if(primerNodoEst->estacion->nombre == nombreAntes){ //si es al principio
        NodoEst *p = &est;
        p ->siguiente = primerNodoEst;        
        p ->anterior = nullptr;
        primerNodoEst ->anterior = p;

        primerNodoEst = p;
        nroEstaciones ++;
        return;
    }

    if(nombreAntes == nullptr){ //si es al final
        NodoEst *p = &est;
        p ->anterior = ultimoNodoEst;
        p->siguiente = nullptr;
        ultimoNodoEst ->siguiente = p;

        ultimoNodoEst = p;
        nroEstaciones ++;
        return;
    }


    NodoEst *nodo = buscarEstacion(nombreAntes);
    NodoEst *p = &est;
    p ->anterior = nodo ->anterior;
    p ->siguiente = nodo;
    nodo ->anterior ->siguiente = p;
    nodo ->anterior = p;
    nroEstaciones ++;
}

NodoEst *ListaDeEstacion::buscarEstacion(const char *nombre){
    if(primerNodoEst == nullptr){
        cout << "No se encontro, Linea sin estaciones"<< endl;
        return nullptr;
    }

    //NodoEst *anterior = primerNodoEst;
    ptrNodoEst = primerNodoEst->siguiente;

    while(ptrNodoEst != nullptr){
        if(ptrNodoEst->estacion->nombre == nombre){
            return ptrNodoEst;
        }

        ptrNodoEst = ptrNodoEst->siguiente;
        //anterior = anterior->siguiente;
    }
    return nullptr;
}

bool ListaDeEstacion::tieneEstacion(Estacion e){
    return buscarEstacion(e.nombre) == nullptr;
}

void ListaDeEstacion::imprimirNombresEstaciones() {
    if(primerNodoEst == nullptr){
        cout << "No hau datos en la lista" <<endl;
        return;
    }
    NodoEst *temp = primerNodoEst;
    while (temp != nullptr) {
        // Imprimir el nombre de la estación
        cout << temp->estacion->nombre << endl;
        // Moverse al siguiente nodo
        temp = temp->siguiente;
    }
}


ListaDeEstacion::~ListaDeEstacion(){
    NodoEst *temp = primerNodoEst ->siguiente;
    while (temp != nullptr) {
        //cout << "eliminado " << temp ->anterior->estacion->nombre<<endl;
        delete (temp ->anterior);
        temp = temp ->siguiente;
    }
    //cout << "eliminado " << ultimoNodoEst ->estacion ->nombre <<endl;
    delete ultimoNodoEst;
}


bool ListaDeEstacion::estaVacia(){
    return primerNodoEst == nullptr;
}
