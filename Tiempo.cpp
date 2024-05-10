#include "Tiempo.h"

Tiempo::Tiempo(int h, int m, int s) {
    hora = h;
    minuto = m;
    segundo = s;
}


void Tiempo::horaDeLlegada(float horas) {
    int totalSegundos = hora * 3600 + minuto * 60 + segundo + horas * 3600;
    int dias = totalSegundos / 86400; // Calcula cuántos días han pasado
    totalSegundos %= 86400; // Resta los segundos correspondientes a los días

    int horaLlegada = totalSegundos / 3600;
    int minutoLlegada = (totalSegundos % 3600) / 60;
    int segundoLlegada = totalSegundos % 60;

    // Ajustar la hora de llegada si ha pasado más de un día
    horaLlegada %= 24;

    std::cout << "Dias: " << dias << ", Hora de llegada: " << horaLlegada << ":" << minutoLlegada << ":" << segundoLlegada << std::endl;
}


void Tiempo::imprimirTiempo(float horasDecimal) {
    int horas = static_cast<int>(horasDecimal); // Parte entera de las horas
    int minutos = static_cast<int>((horasDecimal - horas) * 60); // Convertir la parte decimal a minutos

    std::cout << horas << " horas " << minutos << " minutos";
}
