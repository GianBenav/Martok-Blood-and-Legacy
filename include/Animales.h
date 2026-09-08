#pragma once

#include <string>

enum class EspecieAnimal
{
    // =========================
    // CANIDOS
    // =========================

    Lobo,
    Zorro,

    Perro,
    PerroCampesino,
    PerroPastor,
    PerroCaza,
    PerroGuardian,
    Mastin,
    Lebrel,
    PerroGuerra,
    PerroRastreador,

    PerroLobo,

    // =========================
    // EQUINOS
    // =========================

    Caballo,
    CaballoGuerra,
    CaballoLigero,
    CaballoPesado,
    CaballoCarga,
    CaballoTiro,
    CaballoCarreras,

    Burro,
    Mula,

    // =========================
    // GANADO
    // =========================

    Vaca,
    Toro,
    Buey,
    Bufalo,
    Oveja,
    Cabra,
    Cerdo,

    // =========================
    // AVES DOMESTICAS
    // =========================

    Gallina,
    Gallo,
    Pato,
    Ganso,
    Pavo,
    Paloma,

    // =========================
    // ANIMALES SALVAJES
    // =========================

    Oso,
    Ciervo,
    Jabali,
    Conejo,
    Liebre,
    Alce,
    Bisonte,
    CabraMontesa,
    Lince,
    Tejon,
    Nutria,
    Castor,

    // =========================
    // AVES SALVAJES
    // =========================

    Aguila,
    Halcon,
    Buho,
    Cuervo,
    Cisne,
    Garza
};


// ========================================
// ANIMAL
// ========================================

struct Animal
{
    int id;

    std::string nombre;

    EspecieAnimal especie;

    int edad;

    int salud;
    int fuerza;
    int velocidad;
    int resistencia;

    int agresividad;
    int lealtad;
    int entrenamiento;

    int dueñoID;

    bool domesticado;
    bool compañeroDeGuerra;
    bool vivo;
};


// ========================================
// FUNCIONES
// ========================================

std::string obtenerNombreEspecie(EspecieAnimal especie);

Animal crearAnimal(
    int id,
    const std::string& nombre,
    EspecieAnimal especie,
    int edad
);

void aumentarVinculo(Animal& animal, int cantidad);

void entrenarAnimal(Animal& animal, int cantidad);

int obtenerPoderAnimal(const Animal& animal);

bool puedeSerCompaneroDeGuerra(const Animal& animal);

void mostrarAnimal(const Animal& animal);