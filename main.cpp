#include <iostream>
#include "ListaDeLinea.h"
#include "Tiempo.h"
#include "utilidades.h"


using namespace std;
void leerEntrada(const char *&resultado);
const char* copiarCadena(const char* cadena);
//bool sonIgualesm(const char *cadena1, const char *cadena2);

short contarCaracteresEnBuffer();
ListaDeLinea *l = new ListaDeLinea();
int main()
{
    bool ban = 1;
    while (ban) {

        //l = new ListaDeLinea();


        cout << "1. agg linea" << endl;
        cout << "2. rm linea" << endl;
        cout << "3. consultar linea" << endl;
        cout << "4. agg est de trasferencia" << endl;
        cout << "5. Cantidad de estaciones: "<<endl<<endl;
        cout << "Cantidad de lineas: " <<  l->getNrolineas()<< endl<< endl;


        cout << "Seleccione una opcion: ";

        short r =1;
        cin >> r;
        cin.ignore();

        system("cls");

        switch (r) {
        case 1:
        {


            cout << "Nombre de la linea: ";
            const char *nombre;

            leerEntrada(nombre);

            if(l->petenece(nombre)){
                cout << "esa linea ya existe"<<endl<<endl;
                break;
            }

            //cout << nombre << endl;

            l->aggLinea(*new NodoLinea(nombre));
            cout << "Estacion agg con exito" <<endl << endl;

            //delete[] nombre; //se deberia encargar el destructor
        }
        break;

        case 2:
        {


            if(l->getNrolineas() == 0){
                cout << "No hay estaciones para eliminar"<<endl <<endl;
                continue;
            }

            l->imprimirNombresLineas();
            cout <<endl<<endl;
            cout << "Nombre de la linea: ";
            const char *nombre;

            leerEntrada(nombre);
            cout << nombre << endl;

            //ListaDeLinea l;
            //NodoLinea *nodoEliminar = l ->buscar(nombre);
            l->eliminarLinea(nombre);
            int a;
            break;
        }
        case 3:{
            if(l == nullptr){
                cout << "No hay lineas"<<endl<<endl;
                break;
            }


            char a;
            cout << endl << endl << "Desea realizar operaciones con las linea? (s/n)? "<<endl;
            cin >> a;
            cin.ignore();
            system("cls");
            cout << "Estaciones disponibles: " << endl;
            l->imprimirNombresLineas();
            cout << endl << endl;

            if(a == 's'){
                cout << "Ingrese una linea: "<<endl;
                const char * r;
                leerEntrada(r);
                NodoLinea *lineaSeleccionada = l->buscar(r); //memoria dinamica asignada

                if(lineaSeleccionada == nullptr){
                    cout << "Linea no existe"<<endl << endl;
                    break;
                }
                bool ban1 = true;
                system("cls");
                while(ban1){

                    cout << "Linea seleccionada: " << lineaSeleccionada->linea->nombre<<endl;

                    cout << "1. agg estacion" << endl;
                    cout << "2. rm estacion" << endl;
                    cout << "3. consultar estacion" << endl;
                    cout << "4. Tiempo estimado de llegada"<<endl;
                    cout << "Numero de estaciones: " << lineaSeleccionada ->linea->estaciones.getNroEstaciones();
                    cout << endl << endl;

                    cout << "Seleccione una opcion (0 para salir): ";

                    short i;
                    cin >> i;
                    cin.ignore();

                    switch (i) {
                        case 1:{

                        const char *nombre;
                        system("cls");
                        cout << "Ingrese el nombre de la estacion: ";
                        leerEntrada(nombre);
                        //cin.ignore();

                        if(lineaSeleccionada->linea->estaciones.tieneEstacion(nombre)){
                            cout << "Estacion ya existe" << endl;
                            continue;
                        }

                        NodoEst *estacionAgg = new NodoEst(nombre);
                        //si va a ser la primera estacion a agg:
                        if(lineaSeleccionada ->linea ->estaciones.estaVacia()){

                            //const char *primerEstacion = lineaSeleccionada ->linea->estaciones.getPrimer()->estacion->nombre;
                            lineaSeleccionada ->linea->estaciones.aggEstacion(*estacionAgg,nullptr);
                            cout << "estacion agg correctamente" << endl << endl;
                        }else{
                            system("cls");
                            cout << "mapa de estaciones:" <<endl<<endl;
                            lineaSeleccionada ->linea->estaciones.imprimirNombresEstaciones();

                            cout <<endl;
                            cout << "Estacion a agragar: " << nombre << " <---> ?" <<endl<<endl;
                            cout << "Por favor, escriba el nombre de una estacion ya existente, esta sera la proxima estacion de la que quiere agg"<<endl;
                            cout << "Nota:Esta estacion se insertara antes de la que ingrese o cero para insertar al final\n\n" << "Ingrese una opcion:";
                            const char *antes12;
                            //cin.ignore();
                            leerEntrada(antes12);
                            if(!sonIguales(antes12,"0")){
                                if(!lineaSeleccionada->linea->estaciones.tieneEstacion(antes12)){
                                    cout << "Estacion no existe"<<endl;
                                    break;
                                }
                            }

                            if(sonIguales(antes12,lineaSeleccionada->linea->estaciones.getPrimer()->estacion->nombre)){
                                //si se inseta al principio
                                NodoEst *est = new NodoEst(nombre);
                                float sgte;
                                cout << endl << "Ingrese el tiempo a la proxima estacion: ";
                                cin >> sgte;
                                cin.ignore();
                                est ->estacion ->sgte = sgte;
                                lineaSeleccionada ->linea->estaciones.aggEstacion(*est,antes12);
                                cout << "estacion agg correctamente" << endl << endl;
                            }else if(sonIguales(antes12, "0")){
                                //si es al final
                                NodoEst *est = new NodoEst(nombre);
                                float ant;
                                cout << "Ingrese el tiempo a la estacion anterior: ";
                                cin >> ant;
                                cin.ignore();
                                est ->estacion ->ant = ant;
                                lineaSeleccionada ->linea->estaciones.aggEstacion(*est,nullptr);
                                cout << "estacion agg correctamente" << endl << endl;

                            }else{
                                //si es en la mitad de dos estaciones
                                NodoEst *est = new NodoEst(nombre);

                                lineaSeleccionada ->linea->estaciones.aggEstacion(*est,antes12);
                                cout << "estacion agg correctamente" << endl << endl;
                            }
                        }

                            break;

                        }


                        case 2:{
                            lineaSeleccionada->linea->estaciones.imprimirNombresEstaciones();
                            cout << endl << endl;
                            cout << "Ingrese el nombre de la estacion a eliminar: " <<endl;
                            const char *nombre;
                            leerEntrada(nombre);
                            NodoEst *estEliminar = lineaSeleccionada->linea->estaciones.buscarEstacion(nombre);

                            if(estEliminar == nullptr){
                                cout <<"No existe esa estacion"<<endl<<endl;
                                break;
                            }

                            lineaSeleccionada->linea->estaciones.eliminarEstacion(nombre);
                            cout << "Estacion eliminada con exito"<<endl <<endl;
                            break;
                        }

                        case 3:{
                            cout << endl << "Mapa estaciones: " << endl<<endl;
                            lineaSeleccionada->linea->estaciones.imprimirNombresEstaciones();
                            cout << endl << endl;
                            break;
                        }


                        case 4:{
                            int h,m,s;
                            cout <<"Ingrese hora: ";
                            cin >> h;
                            cin.ignore();

                            cout << endl << "Ingrese minutos: ";
                            cin >> m;
                            cin.ignore();

                            cout << endl << "Ingrese segundos: ";
                            cin >> s;
                            cin.ignore();
                            cout << endl<<endl;
                            Tiempo *t = new Tiempo(h,m,s);


                            cout << "Mapa de estaciones: "<<endl;
                            lineaSeleccionada->linea->estaciones.imprimirNombresEstaciones();

                            cout << endl<<endl;
                            const char *est1;
                            cout << "ingrese est1: ";
                            leerEntrada(est1);


                            const char *est2;
                            cout << "ingrese est2: ";
                            leerEntrada(est2);

                            float tiempo = lineaSeleccionada ->linea->estaciones.calcularTiempoEst(est1,est2);
                            t->horaDeLlegada(tiempo);
                            cout << endl<<endl;
                            break;

                        }

                        default:
                            if(i == 0)ban1=false;
                            continue;
                            //break;
                        }
                    //lineaSeleccionada ->linea ->estaciones;
                }
            }


            break;
        }

        case 4:{

            if(l->getNrolineas() == 0){
                cout << "no hay lineas"<<endl<<endl;
                continue;
            }
            cout << "Estaciones disponibles:"<<endl<<endl;
            l->imprimirNombresLineas();
            const char *linea1;
            const char *linea2;
            cout << "Ingrese linea 1: ";
            leerEntrada(linea1);
            cout << endl;

            cout << "Ingrese linea 2: ";
            leerEntrada(linea2);

            if (sonIguales(linea2,linea1)){
                cout << "No se puede hacer trasferencia consigo mismo"<<endl<<endl;
                continue;
            }


            NodoLinea *l1 = l->buscar(linea1);
            if(l1 == nullptr){
                cout << "no existe"<<endl<<endl;
                delete[] linea1;
                continue;
            }

            if(l1->linea->estaciones.getNroEstaciones() == 0){
                cout << "No hay estaciones porfavor agrege"<<endl<<endl;
                continue;
            }

            cout<<endl<<endl<<"mapa de estaciones de " << l1->linea->nombre << endl;
            l1->linea->estaciones.imprimirNombresEstaciones();
            cout<<endl<<endl;

            const char *est1;
            cout << "Ingrese una estacion: ";
            leerEntrada(est1);
            NodoEst *ptrEst1 = l1->linea->estaciones.buscarEstacion(est1);

            if(ptrEst1 == nullptr){
                cout << "no existe estacion"<<endl;
                continue;
            }

            cout << endl<<endl;


            //ahora para 2

            NodoLinea *l2 = l->buscar(linea2);
            if(l2 == nullptr){
                cout << "no existe"<<endl;
                delete[] linea2;
                continue;
            }
            if(l2->linea->estaciones.getNroEstaciones() == 0){
                cout << "No hay estaciones porfavor agrege";
                continue;
            }

            cout<<endl<<endl<<"mapa de estaciones de " << l1->linea->nombre << endl;
            l2->linea->estaciones.imprimirNombresEstaciones();
            cout<<endl<<endl;

            const char *est2;
            cout << "Ingrese una estacion: ";
            leerEntrada(est2);
            NodoEst *ptrEst2 = l2->linea->estaciones.buscarEstacion(est2);

            if(ptrEst2 == nullptr){
                cout << "no existe estacion"<<endl;
                continue;
            }
            cout<<endl<<"Ingrese nuevo nombre en comun para la estacion de trasferencia: ";
            const char *nuevo;
            leerEntrada(nuevo);

            l->aggEstTrasferencia(l1->linea,ptrEst1,l2->linea,ptrEst2,nuevo);

            cout <<endl << "Cambios realizados con exito, consulte nuevamente estaciones"<<endl<<endl;
            break;
        }
        case 5:{
            cout << "Cantidad de est: " <<  l->calculoEst()<< endl<< endl;
            break;
        }

        default:
            cout << "SALIENDO...";
            ban = false;
            break;
        }
    }
}


void leerEntrada(const char *&resultado) {

    const short MAX_LENGTH = 100;
    char *entrada = new char[MAX_LENGTH];

    cin.getline(entrada, MAX_LENGTH);

    resultado = copiarCadena(entrada);

    delete [] entrada;
}


short contarCaracteresEnBuffer() {
    cin.seekg(0, std::ios::beg);
    short count = cin.gcount();
    cin.clear();
    //std::cin.seekg(0, std::ios::beg);
    return count;
}

const char* copiarCadena(const char* cadena) {
    //cout << &(*cadena) << endl;
    // Calcular la longitud de la cadena de entrada
    short longitud = contarCaracteresEnBuffer();

    // Crear un nuevo array para almacenar la copia de la cadena
    char* copia = new char[longitud + 1]; // +1 para el carácter nulo final

    // Copiar los caracteres de la cadena original a la copia
    for (int i = 0; i <= longitud; ++i) {
        copia[i] = cadena[i];
    }
    //delete[] cadena;
    return copia;
}

