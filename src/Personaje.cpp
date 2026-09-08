#include "Personaje.h"

#include <iostream>
#include <algorithm>

// ========================================
// CREAR PERSONAJE
// ========================================

Personaje crearPersonaje(
    int id,
    const std::string& nombre,
    const std::string& apellido,
    Sexo sexo,
    int edad
)
{
    Personaje personaje;

    personaje.id = id;

    personaje.nombre = nombre;
    personaje.apellido = apellido;

    personaje.sexo = sexo;
    personaje.edad = edad;

    // FAMILIA

    personaje.padreID = -1;
    personaje.madreID = -1;
    personaje.conyugeID = -1;

    // SALUD

    personaje.saludMaxima = 100;
    personaje.salud = 100;

    personaje.estadoSalud = EstadoSalud::Saludable;

    // CARACTERISTICAS

    personaje.fuerza = 50;
    personaje.velocidad = 50;
    personaje.resistencia = 50;
    personaje.inteligencia = 50;
    personaje.carisma = 50;

    // EXPERIENCIA

    personaje.experiencia = 0;

    // ECONOMIA

    personaje.dinero = 0;

    // ESTADO

    personaje.vivo = true;

    // PROFESION

    personaje.profesion = "Sin profesion";

    // POSICION SOCIAL

    personaje.prestigio = 0;
    personaje.reputacion = 0;

    // FERTILIDAD

    personaje.fertilidad = 0;
    actualizarFertilidad(personaje);

    // MILITAR

    personaje.experienciaMilitar = 0;

    // FAMILIA

    personaje.familiaID = -1;

    return personaje;
}

// ========================================
// ENVEJECER
// ========================================

void envejecer(Personaje& personaje)
{
    if (!personaje.vivo)
    {
        return;
    }

    personaje.edad++;

    actualizarFertilidad(personaje);

    /*
        En el futuro aquí podremos añadir:

        - enfermedades por edad
        - pérdida de fuerza
        - pérdida de velocidad
        - pérdida de resistencia
        - canas
        - arrugas
        - muerte natural
        - cambios de personalidad
    */
}

// ========================================
// EXPERIENCIA
// ========================================

void ganarExperiencia(
    Personaje& personaje,
    int cantidad
)
{
    if (!personaje.vivo)
    {
        return;
    }

    if (cantidad <= 0)
    {
        return;
    }

    personaje.experiencia += cantidad;
}

// ========================================
// RECIBIR DAÑO
// ========================================

void recibirDanio(
    Personaje& personaje,
    int cantidad
)
{
    if (!personaje.vivo)
    {
        return;
    }

    if (cantidad <= 0)
    {
        return;
    }

    personaje.salud -= cantidad;

    if (personaje.salud <= 0)
    {
        personaje.salud = 0;

        personaje.estadoSalud = EstadoSalud::Muerto;
        personaje.vivo = false;

        return;
    }

    if (personaje.salud <= 20)
    {
        personaje.estadoSalud = EstadoSalud::Moribundo;
    }
    else if (personaje.salud <= 40)
    {
        personaje.estadoSalud = EstadoSalud::GravementeHerido;
    }
    else if (personaje.salud <= 70)
    {
        personaje.estadoSalud = EstadoSalud::Herido;
    }
    else
    {
        personaje.estadoSalud = EstadoSalud::Saludable;
    }
}

// ========================================
// CURAR
// ========================================

void curar(
    Personaje& personaje,
    int cantidad
)
{
    if (!personaje.vivo)
    {
        return;
    }

    if (cantidad <= 0)
    {
        return;
    }

    personaje.salud += cantidad;

    if (personaje.salud > personaje.saludMaxima)
    {
        personaje.salud = personaje.saludMaxima;
    }

    if (personaje.salud > 70)
    {
        personaje.estadoSalud = EstadoSalud::Saludable;
    }
    else if (personaje.salud > 40)
    {
        personaje.estadoSalud = EstadoSalud::Herido;
    }
    else if (personaje.salud > 20)
    {
        personaje.estadoSalud = EstadoSalud::GravementeHerido;
    }
    else
    {
        personaje.estadoSalud = EstadoSalud::Moribundo;
    }
}

// ========================================
// FERTILIDAD
// ========================================

void actualizarFertilidad(
    Personaje& personaje
)
{
    if (personaje.sexo == Sexo::Mujer)
    {
        if (personaje.edad < 16 || personaje.edad > 45)
        {
            personaje.fertilidad = 0;
        }
        else
        {
            personaje.fertilidad = 100;

            // Disminución gradual después de los 35
            if (personaje.edad > 35)
            {
                personaje.fertilidad =
                    100 - ((personaje.edad - 35) * 10);

                if (personaje.fertilidad < 0)
                {
                    personaje.fertilidad = 0;
                }
            }
        }
    }
    else
    {
        if (personaje.edad < 16 || personaje.edad > 80)
        {
            personaje.fertilidad = 0;
        }
        else if (personaje.edad <= 65)
        {
            personaje.fertilidad = 100;
        }
        else
        {
            personaje.fertilidad =
                100 - ((personaje.edad - 65) * 7);

            if (personaje.fertilidad < 0)
            {
                personaje.fertilidad = 0;
            }
        }
    }
}

// ========================================
// MOSTRAR PERSONAJE
// ========================================

void mostrarPersonaje(
    const Personaje& personaje
)
{
    std::cout << "\n==============================\n";
    std::cout << "PERSONAJE\n";
    std::cout << "==============================\n";

    std::cout << "ID: "
              << personaje.id
              << "\n";

    std::cout << "Nombre: "
              << personaje.nombre
              << " "
              << personaje.apellido
              << "\n";

    std::cout << "Edad: "
              << personaje.edad
              << "\n";

    std::cout << "Salud: "
              << personaje.salud
              << "/"
              << personaje.saludMaxima
              << "\n";

    std::cout << "Fuerza: "
              << personaje.fuerza
              << "\n";

    std::cout << "Velocidad: "
              << personaje.velocidad
              << "\n";

    std::cout << "Resistencia: "
              << personaje.resistencia
              << "\n";

    std::cout << "Inteligencia: "
              << personaje.inteligencia
              << "\n";

    std::cout << "Carisma: "
              << personaje.carisma
              << "\n";

    std::cout << "Experiencia: "
              << personaje.experiencia
              << "\n";

    std::cout << "Dinero: "
              << personaje.dinero
              << "\n";

    std::cout << "Profesion: "
              << personaje.profesion
              << "\n";

    std::cout << "Prestigio: "
              << personaje.prestigio
              << "\n";

    std::cout << "Reputacion: "
              << personaje.reputacion
              << "\n";

    std::cout << "Fertilidad: "
              << personaje.fertilidad
              << "\n";

    std::cout << "Vivo: "
              << (personaje.vivo ? "Si" : "No")
              << "\n";

    std::cout << "==============================\n";
}