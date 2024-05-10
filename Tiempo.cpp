#include "Tiempo.h"

Tiempo::Tiempo(int h, int m, int s) {
    hora = h;
    minuto = m;
    segundo = s;
}


void Tiempo::horaDeLlegada(float horas) {
    int totalSegundos = hora * 3600 + minuto * 60 + segundo + horas * 3600;
    int horaLlegada = totalSegundos / 3600 % 24;
    int minutoLlegada = (totalSegundos / 60) % 60;
    int segundoLlegada = totalSegundos % 60;

    cout << "Hora de llegada: " << horaLlegada << ":" << minutoLlegada << ":" << segundoLlegada << std::endl;
}
