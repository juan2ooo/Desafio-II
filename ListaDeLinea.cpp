#include "ListaDeLinea.h"

ListaDeLinea::ListaDeLinea() {

    primerNodoLinea = nullptr;
}



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


void ListaDeLinea::imprimirNombresLineas() {
    NodoLinea *actual = primerNodoLinea;
    while (actual != nullptr) {
        cout << actual->linea->nombre << endl; // Suponiendo que el atributo se llama 'nombre'
        actual = actual->siguiente;
    }
}


//void ListaDeLinea::aggEstTrasferencia(const char *nombre, Linea *l1, const char *estAntes1, Linea *l2, const char *estAntes2){

//}


const char *ListaDeLinea::nombreEstTransf(const char *nombre, Linea *l1){
    short min = 20;
    short i = 0;
    char *nombreTransferencia = new char[min];

    while(nombre[i] != '\0'){
        if(i > min - 2){ //si necesito mas memoria, redimensionar
            min = min + 10;
            char *temp = new char[min];
            short j = 0;

            while(nombreTransferencia[j] != '\0'){
                temp[j] = nombreTransferencia[j];
            }
            temp[j] = '\0';
        }


        nombreTransferencia[i] = nombre[i];
        i++;
    }

    //short min = 20;
    short tam = i;
    i = 0;
    while(l1 ->nombre[i] != '\0'){
        char *temp;
        char *nombreTransferencia;


        tam = tam + i;
        nombreTransferencia[i] = l1 ->nombre[i];
        nombreTransferencia[tam] = '\0';
        i++;
    }
    //const char *nombreTransferencia1 = &nombreTransferencia[0];
    return &nombreTransferencia[0];

}


const char *ListaDeLinea::redimensionar(const char *nombre){
    short min = 20;
    short i = 0;
    char *nombreTransferencia = new char[min];
    //si necesito mas memoria, redimensionar
        min = min + 10;
        temp = new char[min];
        short j = 0;

        while(nombreTransferencia[j] != '\0'){
            temp[j] = nombreTransferencia[j];
        }
        temp[j] = '\0';
        delete[] nombreTransferencia;
        nombreTransferencia = temp;

}


