#include <iostream>

using namespace std;
void leerEntrada(const char *&resultado);

int main()
{
    cout << "1. agg linea" << endl;
    cout << "2. rm linea" << endl;
    cout << "3. consultar linea" << endl;

    cout << "Seleccione una opcion" << endl;
    char r;
    cin >> r;

    switch (r) {
    case 1:
        cout << "Nombre de la linea: ";
        const char *nombre;
        cin >> nombre;
        break;

    case 2:
        break;

    case 3:
        break;

    default:
        cout << "Seleccione una opcion valida";
        break;
    }
    return 0;
}


void leerEntrada(const char *&resultado) {
    const int MAX_LENGTH = 100;
    char entrada[MAX_LENGTH];
    std::cout << "Ingrese una cadena: ";
    std::cin.getline(entrada, MAX_LENGTH);

    // Almacenar el resultado en una variable const char *
    resultado = entrada;
}
