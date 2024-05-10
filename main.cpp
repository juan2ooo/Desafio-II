#include <iostream>
#include "ListaDeLinea.h"
//#include <windows.h>
#include "utilidades.h"

using namespace std;
void leerEntrada(const char *&resultado);
const char* copiarCadena(const char* cadena);
//bool sonIgualesm(const char *cadena1, const char *cadena2);

short contarCaracteresEnBuffer();
ListaDeLinea *l = nullptr;
int main()
{
    bool ban = 1;
    while (ban) {

        cout << "1. agg linea" << endl;
        cout << "2. rm linea" << endl;
        cout << "3. consultar linea" << endl;

        cout << "Seleccione una opcion: ";

        short r =1;
        cin >> r;
        cin.ignore();

        system("cls");

        switch (r) {
        case 1:
        {

            if (l == nullptr){
                l = new ListaDeLinea();
            }


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
            if (l == nullptr){
                l = new ListaDeLinea();
            }

            if(l->getNrolineas() == 0){
                cout << "No hay estaciones para eliminar";
                continue;
            }

            l->imprimirNombresLineas();
            cout <<endl<<endl;
            cout << "Nombre de la linea: ";
            const char *nombre;

            leerEntrada(nombre);
            cout << nombre << endl;

            //ListaDeLinea l;
            NodoLinea *nodoEliminar = l ->buscar(nombre);
            l->eliminarLinea(nodoEliminar->linea->nombre);
            int a;
            break;
        }
        case 3:
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

                    cout << "estacion seleccionada: " << lineaSeleccionada->linea->nombre<<endl;

                    cout << "1. agg estacion" << endl;
                    cout << "2. rm estacion" << endl;
                    cout << "3. consultar estacion" << endl;

                    cout << "Seleccione una opcion: ";

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
                            cout << "Por favor, escriba el nombre de su proxima estacion.\nNota:Esta estacion se insertara antes de la que ingrese o cero para insertar al final\n"<<"Ingrese una opcion: ";
                            const char *antes12;
                            //cin.ignore();
                            leerEntrada(antes12);
                            if(!sonIguales(antes12,"0")){
                                if(lineaSeleccionada->linea->estaciones.tieneEstacion(antes12)){
                                    cout << "Estacion no existe"<<endl;
                                    break;
                                }
                            }

                            if(sonIguales(antes12,lineaSeleccionada->linea->estaciones.getPrimer()->estacion->nombre)){
                                //si se inseta al principio
                                NodoEst *est = new NodoEst(nombre);
                                float sgte;
                                cout << "Ingrese el tiempo a la proxima estacion: ";
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

                        case 3:{
                            cout << endl << "Mapa estaciones: " << endl;
                            lineaSeleccionada->linea->estaciones.imprimirNombresEstaciones();
                            cout << endl << endl;
                            break;
                        }
                        default:
                            break;
                        }
                    //lineaSeleccionada ->linea ->estaciones;
                }
            }


            break;


        default:
            cout << "SALIENDO...";
            ban = false;
            break;
        }
        //return 0;

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

