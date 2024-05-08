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
                cout << "No hay lineas";
            }

            l->imprimirNombresLineas();
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

    cin.ignore();
    cin.getline(entrada, MAX_LENGTH);

    // Almacenar el resultado en una variable const char *
    //cout << &entrada;
    resultado = copiarCadena(entrada);
    cout << &(*entrada) << endl;
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
    cout << &(*cadena) << endl;
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
