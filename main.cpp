#include <iostream>
#include "ListaDeLinea.h"
//#include <windows.h>

using namespace std;
void leerEntrada(const char *&resultado);
const char* copiarCadena(const char* cadena);

short contarCaracteresEnBuffer();
ListaDeLinea *l = nullptr;
int main()
{
    bool ban = 1;
    while (ban) {

        cout << "1. agg linea" << endl;
        cout << "2. rm linea" << endl;
        cout << "3. consultar linea" << endl;

        cout << "Seleccione una opcion" << endl;

        short r =1;
        cin >> r;

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
            cout << nombre << endl;

            l->aggLinea(*new NodoLinea(nombre));

            //delete[] nombre; //se deberia encargar el destructor
        }
        break;

        case 2:
        {
            if (l == nullptr){
                l = new ListaDeLinea();
            }
            cout << "Nombre de la linea: ";
            const char *nombre;

            leerEntrada(nombre);
            cout << nombre << endl;

            //ListaDeLinea l;
            l->eliminarLinea(*new NodoLinea(nombre));
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
            l->imprimirNombresLineas();

            if(a == 's'){
                cout << "Ingrese una linea: "<<endl;
                const char * r;
                leerEntrada(r);
                NodoLinea *lineaSeleccionada = l->buscar(r); //memoria dinamica asignada

                if(lineaSeleccionada == nullptr){
                    cout << "Linea no existe";
                    break;
                }
                bool ban1 = true;


                while(ban1){
                    system("cls");
                    cout << "1. agg estacion" << endl;
                    cout << "2. rm estacion" << endl;
                    cout << "3. consultar estacion" << endl;

                    cout << "Seleccione una opcion" << endl;

                    short i;
                    cin >> i;

                    switch (i) {
                        case 1:{
                        const char *nombre;
                        system("cls");
                        cout << "Ingrese el nombre de la estacion: ";
                        leerEntrada(nombre);
                        NodoEst *estacionAgg = new NodoEst(nombre);
                        //si va a ser la primera estacion a agg:
                        if(lineaSeleccionada ->linea ->estaciones.estaVacia()){

                            //const char *primerEstacion = lineaSeleccionada ->linea->estaciones.getPrimer()->estacion->nombre;
                            lineaSeleccionada ->linea->estaciones.aggEstacion(*estacionAgg,nullptr);
                        }else{
                            const char *antes12;
                            lineaSeleccionada ->linea->estaciones.imprimirNombresEstaciones();
                            cout << "Por favor, escriba el nombre de la proxima estacion. Esta estacion se insertara antes de la que ingrese.";
                            leerEntrada(antes12);


                            if(lineaSeleccionada->linea->estaciones.tieneEstacion(antes12)){
                                cout << "Estacion no existe";
                                break;
                            }


                            if(antes12 == lineaSeleccionada->linea->estaciones.getPrimer()->estacion->nombre){
                                //si se inseta al principio
                                NodoEst *est = new NodoEst(nombre);
                                float sgte;
                                cout << "Ingrese el tiempo a la proxima estacion";
                                cin >> sgte;
                                est ->estacion ->sgte = sgte;
                                lineaSeleccionada ->linea->estaciones.aggEstacion(*est,antes12);
                            }else if(antes12 == lineaSeleccionada->linea->estaciones.getUlt()->estacion->nombre){
                                //si es al final
                                NodoEst *est = new NodoEst(nombre);
                                float ant;
                                cout << "Ingrese el tiempo a la proxima estacion";
                                cin >> ant;
                                est ->estacion ->ant = ant;
                                lineaSeleccionada ->linea->estaciones.aggEstacion(*est,antes12);

                            }else{
                                //si es en la mitad de dos estaciones
                                NodoEst *est = new NodoEst(nombre);

                                lineaSeleccionada ->linea->estaciones.aggEstacion(*est,antes12);
                            }
                        }

                        }

                            break;
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
    char *entrada = new char[MAX_LENGTH]; // Asignar memoria dinámica
    cin.seekg(0, std::ios::beg);
    cin.ignore();
    cin.getline(entrada, MAX_LENGTH);

    // Almacenar el resultado en una variable const char *
    resultado = copiarCadena(entrada);
    //cout << &(*entrada) << endl;
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
