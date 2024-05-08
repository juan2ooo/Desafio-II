#include <iostream>

using namespace std;
void leerEntrada(const char *&resultado);
short contarCaracteresEnBuffer();
int main()
{
    cout << "1. agg linea" << endl;
    cout << "2. rm linea" << endl;
    cout << "3. consultar linea" << endl;

    cout << "Seleccione una opcion" << endl;
    short r;
    cin >> r;

    switch (r) {
    case 1:
        cout << "Nombre de la linea: ";
        const char *nombre;
        leerEntrada(nombre);
        cout << nombre;
        delete[] nombre;

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
    const short MAX_LENGTH = 100;
    char *entrada = new char[MAX_LENGTH]; // Asignar memoria dinámica
    std::cin.getline(entrada, MAX_LENGTH);

    // Almacenar el resultado en una variable const char *
    resultado = entrada;
}

short contarCaracteresEnBuffer() {
    std::cin.seekg(0, std::ios::beg);
    short count = std::cin.gcount();
    std::cin.clear();
    //std::cin.seekg(0, std::ios::beg);
    return count;
}
