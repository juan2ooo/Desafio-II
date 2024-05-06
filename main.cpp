#include <iostream>
#include "ListaDeEstacion.h"
using namespace std;

int main()
{
    cout << "Hello World!" << endl;
    ListaDeEstacion l;
    l.aggEstacion("san antonio", nullptr);
    l.aggEstacion("exposiciones", nullptr);
    l.aggEstacion("industriales", nullptr);
    l.aggEstacion("el ayura", nullptr);
    l.aggEstacion("el poblado", "el ayura");
    l.imprimirNombresEstaciones();
    return 0;
}
