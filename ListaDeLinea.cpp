#include "ListaDeLinea.h"
bool sonIguales(const char *cadena1, const char *cadena2);
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

    if(primerNodoLinea == nullptr) return nullptr;
    ptrNodoLinea = primerNodoLinea;

    //NodoLinea *ant = primerNodoLinea;
    while(ptrNodoLinea ->siguiente != nullptr){

        if(sonIguales( ptrNodoLinea->linea->nombre, s)){
            return ptrNodoLinea;
        }
        ptrNodoLinea = ptrNodoLinea ->siguiente;
    }

    if(sonIguales( ptrNodoLinea->linea->nombre, s)){
        return ptrNodoLinea;
    }
    return nullptr;
}

void ListaDeLinea::eliminarLinea(const char *l){ // elimina al siguiente de este
    if(primerNodoLinea == nullptr){
        cout << "no se puede eliminar, lista vacia" << endl;
        return;
    }

    if(sonIguales(primerNodoLinea->linea->nombre,l)){
        NodoLinea *temp = primerNodoLinea;
        primerNodoLinea = primerNodoLinea->siguiente;

        delete temp;
        return;
    }


    NodoLinea *nodoEliminarAnt = buscarAnt(l); //ANTERIOR o nullptr si es el ultimo


    if(sePuedeEliminar(*nodoEliminarAnt->siguiente)){

        if(nodoEliminarAnt == nullptr){
            cout << "no pertenece";
            return;
        }
        NodoLinea *temp = nodoEliminarAnt ->siguiente;
        nodoEliminarAnt->siguiente = nodoEliminarAnt->siguiente->siguiente;
        delete (temp);


    }else{
        cout << "No se completo la operacion, no se puede eliminar lineas con estaciones"<<endl;
    }
}

bool ListaDeLinea::petenece(const char *l){
    if(primerNodoLinea == nullptr) return false;
    return (buscar(l) != nullptr);
}


void ListaDeLinea::imprimirNombresLineas() {
    NodoLinea *actual = primerNodoLinea;
    while (actual != nullptr) {
        cout << actual->linea->nombre << endl; // Suponiendo que el atributo se llama 'nombre'
        actual = actual->siguiente;
    }
}


void ListaDeLinea::aggEstTrasferencia(Linea *l1, const char *est1, Linea *l2, const char *est2){

    //una vez con los nombres
    if(l1 ->estaVacia() | l2 ->estaVacia()){
        cout << "No hay estaciones, no se puede agregar est de transferencia";
        return;
    }

    const char *nombreL1 = nombreEstTransf(est1,l1);
    const char *nombreL2 = nombreEstTransf(est2,l2);

    l1 ->estaciones.buscarEstacion(est1)->estacion->nombre = nombreL1;
    l2 ->estaciones.buscarEstacion(est2)->estacion->nombre = nombreL2;

    delete[] nombreL1;
    delete[] nombreL2;
}


const char *ListaDeLinea::nombreEstTransf(const char *nombre, Linea *l1){

    short i = 0, tam = 20;
    char *nombreTransferencia = new char[tam];

    while(nombre[i] != '\0'){
        if(i > tam-3){ //si necesito mas memoria, redimensionar es -2 pero -3 pues quero guarfar -
            nombreTransferencia = redimensionar(nombreTransferencia,tam);
        }

        nombreTransferencia[i] = nombre[i];
        i++;
    }

    //short min = 20;

    nombreTransferencia[i] = '-';
    //tam = i;
    short j = 0;
    while(l1 ->nombre[j] != '\0'){
        if(i > tam-3){ //si necesito mas memoria, redimensionar es -2 pero -3 pues quero guarfar -
            nombreTransferencia = redimensionar(nombreTransferencia,tam);
        }
        nombreTransferencia[i+1] = l1 ->nombre[j]; //poner i experimento interesante

        j++;
        i++;
    }
    nombreTransferencia[i+1] = '\0';
    //const char *nombreTransferencia1 = &nombreTransferencia[0];
    return nombreTransferencia;

}


char *ListaDeLinea::redimensionar(char *nombre, short &tam){
    short i = 0;
    char adicional = 10;
    char *nombreRedimension = new char[tam + adicional];

    // Copiar el contenido de 'nombre' a 'nombreRedimension'
    while (nombre[i] != '\0') {
        nombreRedimension[i] = nombre[i];
        i++;
    }
    nombreRedimension[i] = '\0'; // Asegurar que el nuevo nombre termina con '\0'

    // Liberar la memoria del nombre original
    nombre[tam-1] = '\0';
    delete[] nombre; //no se tiene que usar pues nobre se crea en el stack

    // Actualizar el tamaño
    tam += adicional;

    return nombreRedimension;
}


NodoLinea *ListaDeLinea::buscarAnt(const char *s){

    if(primerNodoLinea == nullptr) return nullptr;

    //if(sonIguales(primerNodoLinea ->linea->nombre,s))return nullptr;

    ptrNodoLinea = primerNodoLinea ->siguiente;
    NodoLinea *ant = primerNodoLinea;

    //NodoLinea *ant = primerNodoLinea;
    while(ptrNodoLinea!= nullptr){
        if(sonIguales( ptrNodoLinea->linea->nombre, s)){
            return ant;
        }
        ptrNodoLinea = ptrNodoLinea ->siguiente;
        ant = ant ->siguiente;
    }

    //if(sonIguales(ptrNodoLinea->linea->nombre, s)){
        return ant;

    return nullptr;
}

short ListaDeLinea::getNrolineas(){
    return nroLinea;
}
