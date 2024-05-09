#include "ListaDeEstacion.h"
unsigned short ListaDeEstacion::nroEstaciones = 0;


ListaDeEstacion::ListaDeEstacion() {
    primerNodoEst = nullptr;
    ultimoNodoEst = nullptr;
    //nroEstaciones = 0;
}

void ListaDeEstacion::aggEstacion(NodoEst &est, const char *nombreAntes){ //est nodo a insetar
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


    NodoEst *nodo = buscarEstacion(nombreAntes); //nuevo nodo con estacion antes de insertar
    NodoEst *p = &est; //estacion a insertar

    reajustarTiempos(nodo ->anterior ->estacion,nodo->estacion,true); //reajustar las estaciones de los extremos

    p ->estacion ->sgte = nodo ->estacion ->ant;
    p ->estacion ->ant = nodo ->estacion ->ant;

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

bool ListaDeEstacion::tieneEstacion(const char *e){
    return buscarEstacion(e) == nullptr;
}

void ListaDeEstacion::imprimirNombresEstaciones() {
    if(primerNodoEst == nullptr){
        cout << "No hau datos en la lista" <<endl;
        return;
    }
    NodoEst *temp = primerNodoEst;
    while (temp != nullptr) {
        // Imprimir el nombre de la estación
        //cout << temp->estacion->nombre << "----" << temp ->estacion ->sgte << "----";
        cout << temp->estacion->nombre << endl;
        // Moverse al siguiente nodo
        temp = temp->siguiente;
    }
}


ListaDeEstacion::~ListaDeEstacion(){
    if(primerNodoEst != nullptr){
        if(primerNodoEst ->siguiente != nullptr){
            NodoEst *temp = primerNodoEst ->siguiente;
            while (temp != nullptr) {
                //cout << "eliminado " << temp ->anterior->estacion->nombre<<endl;
                delete (temp ->anterior);
                temp = temp ->siguiente;
            }
            //cout << "eliminado " << ultimoNodoEst ->estacion ->nombre <<endl;
            delete ultimoNodoEst;
        }else{ //si solo hau un elemento
            delete primerNodoEst;
        }


    }
}


bool ListaDeEstacion::estaVacia(){
    return primerNodoEst == nullptr;
}



void ListaDeEstacion::reajustarTiempos(Estacion *e1, Estacion *e2, bool caso){  //e1 ---- e2

    if(caso){
        float tiempoNuevo = (e1 ->sgte)/2;
        e1 ->sgte = tiempoNuevo;
        e2 ->ant = tiempoNuevo;
    }else{
        float tiempoNuevo = (e1 ->sgte)*2;
        e1 ->sgte = tiempoNuevo;
        e2 ->ant = tiempoNuevo;
    }


}


void ListaDeEstacion::eiminarEstacion(const char *s){

    if(primerNodoEst == nullptr){ //si esta vacia
        cout << "Elemento invalido, lista vacia";
        return;
    }


    if(primerNodoEst->estacion ->nombre == s){ //si es al principio
        primerNodoEst = primerNodoEst ->siguiente;
        delete (primerNodoEst ->anterior);
        primerNodoEst -> anterior = nullptr;
        return;
    }


    if(ultimoNodoEst ->estacion ->nombre == s){ //si es al final
        ultimoNodoEst = ultimoNodoEst ->anterior;
        delete (ultimoNodoEst ->siguiente);
        ultimoNodoEst ->siguiente = nullptr;
        return;
    }

    NodoEst *est = buscarEstacion(s); //caso mas ineficiente
    if(est == nullptr){
        cout << "El elemento no existe en la lista";
        return;
    }
    est ->anterior->siguiente = est ->siguiente;
    est ->siguiente->anterior = est ->anterior;

    reajustarTiempos(est ->anterior->estacion,est->siguiente->estacion,false);

    delete est;

}


unsigned short ListaDeEstacion::getNroEstaciones(){
    return nroEstaciones;
}


NodoEst *ListaDeEstacion::getPrimer(){
    return primerNodoEst;
}

NodoEst *ListaDeEstacion::getUlt(){
    return ultimoNodoEst;
}
