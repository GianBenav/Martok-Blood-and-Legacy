#include "Tiempo.h"

#include <sstream>

// ========================================
// CONSTRUCTOR
// ========================================

Tiempo::Tiempo()
{
    dia = 1;
    mes = 1;
    anio = 1178;

    horasRealesAcumuladas = 0.0;
}

// ========================================
// AVANZAR TIEMPO REAL
// ========================================

void Tiempo::avanzarHorasReales(double horas)
{
    if (horas <= 0)
    {
        return;
    }

    horasRealesAcumuladas += horas;

    /*
        REGLA DEL JUEGO:

        1 hora real = 15 días de juego

        6 horas reales = 90 días = 1 estación

        24 horas reales = 360 días = 1 año
    */

    while (horasRealesAcumuladas >= 1.0)
    {
        avanzarDias(15);

        horasRealesAcumuladas -= 1.0;
    }
}

// ========================================
// AVANZAR UN DIA
// ========================================

void Tiempo::avanzarDia()
{
    dia++;

    if (dia > 30)
    {
        dia = 1;
        mes++;
    }

    if (mes > 12)
    {
        mes = 1;
        anio++;
    }
}

// ========================================
// AVANZAR VARIOS DIAS
// ========================================

void Tiempo::avanzarDias(int cantidad)
{
    if (cantidad <= 0)
    {
        return;
    }

    for (int i = 0; i < cantidad; i++)
    {
        avanzarDia();
    }
}

// ========================================
// OBTENER ESTACION
// ========================================

Estacion Tiempo::obtenerEstacion() const
{
    if (mes >= 1 && mes <= 3)
    {
        return Estacion::Primavera;
    }

    if (mes >= 4 && mes <= 6)
    {
        return Estacion::Verano;
    }

    if (mes >= 7 && mes <= 9)
    {
        return Estacion::Otono;
    }

    return Estacion::Invierno;
}

// ========================================
// NOMBRE DE LA ESTACION
// ========================================

std::string Tiempo::obtenerNombreEstacion() const
{
    switch (obtenerEstacion())
    {
        case Estacion::Primavera:
            return "Primavera";

        case Estacion::Verano:
            return "Verano";

        case Estacion::Otono:
            return "Otono";

        case Estacion::Invierno:
            return "Invierno";
    }

    return "Desconocida";
}

// ========================================
// OBTENER FECHA
// ========================================

std::string Tiempo::obtenerFecha() const
{
    std::stringstream fecha;

    fecha << dia << "/" << mes << "/" << anio;

    return fecha.str();
}

// ========================================
// HORAS REALES
// ========================================

double Tiempo::obtenerHorasReales() const
{
    return horasRealesAcumuladas;
}