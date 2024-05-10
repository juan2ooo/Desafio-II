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

    if(sonIguales(primerNodoEst->estacion->nombre, nombreAntes)){ //si es al principio
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

        ultimoNodoEst ->anterior->estacion->sgte = ultimoNodoEst->estacion->ant;
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
        //cout << "No se encontro, Linea sin estaciones"<< endl;
        return nullptr;
    }

    ptrNodoEst = primerNodoEst;


    while(ptrNodoEst->siguiente != nullptr){
        if(sonIguales(ptrNodoEst->estacion->nombre, nombre)){
            return ptrNodoEst;
        }

        ptrNodoEst = ptrNodoEst->siguiente;
        //anterior = anterior->siguiente;
    }

    if(sonIguales(ptrNodoEst->estacion->nombre, nombre)){
        return ptrNodoEst;
    }

    return nullptr;
}

bool ListaDeEstacion::tieneEstacion(const char *e){
    return buscarEstacion(e) != nullptr;
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
        float tiempo = temp->estacion->sgte;

        cout << "ESTACION: "<< temp->estacion->nombre << endl << "  |  "<<endl<< "  |  "<<endl<< "  |  "<<endl;
        if(tiempo != 0){
            cout << endl<<endl;
            Tiempo::imprimirTiempo(tiempo);
            cout << endl<<endl;
        }else{
            cout <<"fin";
        }

        cout <<endl << "  |  "<<endl<< "  |  "<<endl<< "  |  "<<endl;
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


void ListaDeEstacion::eliminarEstacion(const char *s){

    if(primerNodoEst == nullptr){ //si esta vacia
        cout << "Elemento invalido, lista vacia";
        return;
    }

    if(primerNodoEst == ultimoNodoEst){
        NodoEst *temp = primerNodoEst;
        ultimoNodoEst = nullptr;
        primerNodoEst = nullptr;
        delete temp;
        return;
    }


    if(sonIguales(primerNodoEst->estacion ->nombre, s)){ //si es al principio
        //NodoEst *temp = primerNodoEst;
        primerNodoEst = primerNodoEst ->siguiente;
        delete (primerNodoEst ->anterior);
        primerNodoEst -> anterior = nullptr;
        nroEstaciones --;
        return;
    }


    if(sonIguales(ultimoNodoEst ->estacion ->nombre,s)){ //si es al final
        ultimoNodoEst = ultimoNodoEst ->anterior;
        delete (ultimoNodoEst ->siguiente);
        ultimoNodoEst ->siguiente = nullptr;
        nroEstaciones--;
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
    nroEstaciones--;

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


unsigned short ListaDeEstacion::getNroEst(){
    return nroEstaciones;
}


float ListaDeEstacion::calcularTiempoEst(const char* est1, const char *est2){
    if(primerNodoEst == nullptr){
        cout << "No hau datos en la lista" <<endl;
        return 0;
    }
    NodoEst *actual = buscarEstacion(est1);
    NodoEst *final = buscarEstacion(est2);
    float tiempo = 0;


    if(actual == nullptr || final == nullptr)return 0;

    while (actual != final) {
        // Imprimir el nombre de la estación
        //cout << temp->estacion->nombre << "----" << temp ->estacion ->sgte << "----";
        tiempo = tiempo + actual->estacion->sgte;
        actual = actual ->siguiente;
    }
    return tiempo;
}



