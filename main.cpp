#include <iostream>

using namespace std;
void leerEntrada(const char *&resultado);
<<<<<<< HEAD
short contarCaracteresEnBuffer();
=======

>>>>>>> a24674a3c3fb5a47dc98faadba3e5988707b8fd1
int main()
{
    cout << "1. agg linea" << endl;
    cout << "2. rm linea" << endl;
    cout << "3. consultar linea" << endl;

    cout << "Seleccione una opcion" << endl;
<<<<<<< HEAD
    short r;
=======
    char r;
>>>>>>> a24674a3c3fb5a47dc98faadba3e5988707b8fd1
    cin >> r;

    switch (r) {
    case 1:
        cout << "Nombre de la linea: ";
        const char *nombre;
<<<<<<< HEAD
        leerEntrada(nombre);
        cout << nombre;
        delete[] nombre;

        break;

    case 2:
        break;

    case 3:
        break;

=======
        cin >> nombre;
        break;

    case 2:
        break;

    case 3:
        break;

>>>>>>> a24674a3c3fb5a47dc98faadba3e5988707b8fd1
    default:
        cout << "Seleccione una opcion valida";
        break;
    }
    return 0;
}


void leerEntrada(const char *&resultado) {
<<<<<<< HEAD
    const short MAX_LENGTH = 100;
    char *entrada = new char[MAX_LENGTH]; // Asignar memoria dinámica
=======
    const int MAX_LENGTH = 100;
    char entrada[MAX_LENGTH];
    std::cout << "Ingrese una cadena: ";
>>>>>>> a24674a3c3fb5a47dc98faadba3e5988707b8fd1
    std::cin.getline(entrada, MAX_LENGTH);

    // Almacenar el resultado en una variable const char *
    resultado = entrada;
}
<<<<<<< HEAD

short contarCaracteresEnBuffer() {
    std::cin.seekg(0, std::ios::beg);
    short count = std::cin.gcount();
    std::cin.clear();
    //std::cin.seekg(0, std::ios::beg);
    return count;
}
=======
>>>>>>> a24674a3c3fb5a47dc98faadba3e5988707b8fd1
