#pragma once

#include <string>

// ========================================
// SEXO
// ========================================

enum class Sexo
{
    Hombre,
    Mujer
};

// ========================================
// ESTADO DE SALUD
// ========================================

enum class EstadoSalud
{
    Saludable,
    Herido,
    Enfermo,
    GravementeHerido,
    Moribundo,
    Muerto
};

// ========================================
// PERSONAJE
// ========================================

struct Personaje
{
    // IDENTIDAD
    int id;
    std::string nombre;
    std::string apellido;

    Sexo sexo;

    int edad;

    // FAMILIA
    int padreID;
    int madreID;
    int conyugeID;

    // SALUD
    int salud;
    int saludMaxima;
    EstadoSalud estadoSalud;

    // CARACTERISTICAS
    int fuerza;
    int velocidad;
    int resistencia;
    int inteligencia;
    int carisma;

    // EXPERIENCIA
    int experiencia;

    // ECONOMIA
    int dinero;

    // ESTADO
    bool vivo;

    // PROFESION
    std::string profesion;

    // POSICION SOCIAL
    int prestigio;
    int reputacion;

    // FERTILIDAD
    int fertilidad;

    // MILITAR
    int experienciaMilitar;

    // ID de la familia/casa
    int familiaID;
};

// ========================================
// CREAR PERSONAJE
// ========================================

Personaje crearPersonaje(
    int id,
    const std::string& nombre,
    const std::string& apellido,
    Sexo sexo,
    int edad
);

// ========================================
// EDAD
// ========================================

void envejecer(Personaje& personaje);

// ========================================
// EXPERIENCIA
// ========================================

void ganarExperiencia(
    Personaje& personaje,
    int cantidad
);

// ========================================
// SALUD
// ========================================

void recibirDanio(
    Personaje& personaje,
    int cantidad
);

void curar(
    Personaje& personaje,
    int cantidad
);

// ========================================
// FERTILIDAD
// ========================================

void actualizarFertilidad(
    Personaje& personaje
);

// ========================================
// MOSTRAR
// ========================================

void mostrarPersonaje(
    const Personaje& personaje
);