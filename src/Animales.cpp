#include "Animales.h"

#include <iostream>


// ========================================
// NOMBRE DE LA ESPECIE
// ========================================

std::string obtenerNombreEspecie(EspecieAnimal especie)
{
    switch (especie)
    {
        // CANIDOS

        case EspecieAnimal::Lobo:
            return "Lobo";

        case EspecieAnimal::Zorro:
            return "Zorro";

        case EspecieAnimal::Perro:
            return "Perro";

        case EspecieAnimal::PerroCampesino:
            return "Perro campesino";

        case EspecieAnimal::PerroPastor:
            return "Perro pastor";

        case EspecieAnimal::PerroCaza:
            return "Perro de caza";

        case EspecieAnimal::PerroGuardian:
            return "Perro guardian";

        case EspecieAnimal::Mastin:
            return "Mastin";

        case EspecieAnimal::Lebrel:
            return "Lebrel";

        case EspecieAnimal::PerroGuerra:
            return "Perro de guerra";

        case EspecieAnimal::PerroRastreador:
            return "Perro rastreador";

        case EspecieAnimal::PerroLobo:
            return "Perro-lobo";


        // EQUINOS

        case EspecieAnimal::Caballo:
            return "Caballo";

        case EspecieAnimal::CaballoGuerra:
            return "Caballo de guerra";

        case EspecieAnimal::CaballoLigero:
            return "Caballo ligero";

        case EspecieAnimal::CaballoPesado:
            return "Caballo pesado";

        case EspecieAnimal::CaballoCarga:
            return "Caballo de carga";

        case EspecieAnimal::CaballoTiro:
            return "Caballo de tiro";

        case EspecieAnimal::CaballoCarreras:
            return "Caballo de carreras";

        case EspecieAnimal::Burro:
            return "Burro";

        case EspecieAnimal::Mula:
            return "Mula";


        // GANADO

        case EspecieAnimal::Vaca:
            return "Vaca";

        case EspecieAnimal::Toro:
            return "Toro";

        case EspecieAnimal::Buey:
            return "Buey";

        case EspecieAnimal::Bufalo:
            return "Bufalo";

        case EspecieAnimal::Oveja:
            return "Oveja";

        case EspecieAnimal::Cabra:
            return "Cabra";

        case EspecieAnimal::Cerdo:
            return "Cerdo";


        // AVES DOMESTICAS

        case EspecieAnimal::Gallina:
            return "Gallina";

        case EspecieAnimal::Gallo:
            return "Gallo";

        case EspecieAnimal::Pato:
            return "Pato";

        case EspecieAnimal::Ganso:
            return "Ganso";

        case EspecieAnimal::Pavo:
            return "Pavo";

        case EspecieAnimal::Paloma:
            return "Paloma";


        // SALVAJES

        case EspecieAnimal::Oso:
            return "Oso";

        case EspecieAnimal::Ciervo:
            return "Ciervo";

        case EspecieAnimal::Jabali:
            return "Jabali";

        case EspecieAnimal::Conejo:
            return "Conejo";

        case EspecieAnimal::Liebre:
            return "Liebre";

        case EspecieAnimal::Alce:
            return "Alce";

        case EspecieAnimal::Bisonte:
            return "Bisonte";

        case EspecieAnimal::CabraMontesa:
            return "Cabra montesa";

        case EspecieAnimal::Lince:
            return "Lince";

        case EspecieAnimal::Tejon:
            return "Tejon";

        case EspecieAnimal::Nutria:
            return "Nutria";

        case EspecieAnimal::Castor:
            return "Castor";


        // AVES SALVAJES

        case EspecieAnimal::Aguila:
            return "Aguila";

        case EspecieAnimal::Halcon:
            return "Halcon";

        case EspecieAnimal::Buho:
            return "Buho";

        case EspecieAnimal::Cuervo:
            return "Cuervo";

        case EspecieAnimal::Cisne:
            return "Cisne";

        case EspecieAnimal::Garza:
            return "Garza";
    }

    return "Desconocido";
}


// ========================================
// CREAR ANIMAL
// ========================================

Animal crearAnimal(
    int id,
    const std::string& nombre,
    EspecieAnimal especie,
    int edad
)
{
    Animal animal;

    animal.id = id;
    animal.nombre = nombre;
    animal.especie = especie;
    animal.edad = edad;

    animal.salud = 100;
    animal.fuerza = 50;
    animal.velocidad = 50;
    animal.resistencia = 50;

    animal.agresividad = 20;
    animal.lealtad = 0;
    animal.entrenamiento = 0;

    animal.dueñoID = -1;

    animal.domesticado = false;
    animal.compañeroDeGuerra = false;
    animal.vivo = true;

    return animal;
}


// ========================================
// AUMENTAR VINCULO
// ========================================

void aumentarVinculo(Animal& animal, int cantidad)
{
    animal.lealtad += cantidad;

    if (animal.lealtad > 100)
        animal.lealtad = 100;

    if (animal.lealtad < 0)
        animal.lealtad = 0;
}


// ========================================
// ENTRENAMIENTO
// ========================================

void entrenarAnimal(Animal& animal, int cantidad)
{
    animal.entrenamiento += cantidad;

    if (animal.entrenamiento > 100)
        animal.entrenamiento = 100;

    if (animal.entrenamiento < 0)
        animal.entrenamiento = 0;
}


// ========================================
// PODER DEL ANIMAL
// ========================================

int obtenerPoderAnimal(const Animal& animal)
{
    return
        animal.fuerza +
        animal.velocidad +
        animal.resistencia +
        animal.entrenamiento +
        animal.lealtad;
}


// ========================================
// COMPAÑERO DE GUERRA
// ========================================

bool puedeSerCompaneroDeGuerra(const Animal& animal)
{
    if (!animal.vivo)
        return false;

    if (!animal.domesticado)
        return false;

    if (animal.entrenamiento < 40)
        return false;

    if (animal.lealtad < 50)
        return false;

    return true;
}


// ========================================
// MOSTRAR ANIMAL
// ========================================

void mostrarAnimal(const Animal& animal)
{
    std::cout << "\n===== ANIMAL =====\n";

    std::cout << "ID: "
              << animal.id << "\n";

    std::cout << "Nombre: "
              << animal.nombre << "\n";

    std::cout << "Especie: "
              << obtenerNombreEspecie(animal.especie)
              << "\n";

    std::cout << "Edad: "
              << animal.edad << "\n";

    std::cout << "Salud: "
              << animal.salud << "\n";

    std::cout << "Fuerza: "
              << animal.fuerza << "\n";

    std::cout << "Velocidad: "
              << animal.velocidad << "\n";

    std::cout << "Resistencia: "
              << animal.resistencia << "\n";

    std::cout << "Agresividad: "
              << animal.agresividad << "\n";

    std::cout << "Lealtad: "
              << animal.lealtad << "\n";

    std::cout << "Entrenamiento: "
              << animal.entrenamiento << "\n";

    std::cout << "Domesticado: "
              << (animal.domesticado ? "Si" : "No")
              << "\n";

    std::cout << "Companero de guerra: "
              << (animal.compañeroDeGuerra ? "Si" : "No")
              << "\n";

    std::cout << "==================\n";
}