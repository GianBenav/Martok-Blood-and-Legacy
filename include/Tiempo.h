#pragma once

#include <string>

enum class Estacion
{
    Primavera,
    Verano,
    Otono,
    Invierno
};

class Tiempo
{
public:

    // Calendario del juego
    int dia;
    int mes;
    int anio;

    // Horas reales acumuladas
    double horasRealesAcumuladas;

    Tiempo();

    // Avanza el tiempo según horas del mundo real
    void avanzarHorasReales(double horas);

    // Avanza días dentro del juego
    void avanzarDia();
    void avanzarDias(int cantidad);

    // Información del calendario
    Estacion obtenerEstacion() const;
    std::string obtenerNombreEstacion() const;
    std::string obtenerFecha() const;

    // Obtener cuánto tiempo real ha pasado
    double obtenerHorasReales() const;
};