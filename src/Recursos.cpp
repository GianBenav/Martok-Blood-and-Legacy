#include "Recursos.h"
#include <iostream>

void Recursos::mostrarRecursos() const
{
    std::cout << "\n========== RECURSOS ==========\n";

    std::cout << "Madera: " << madera << "\n";
    std::cout << "Piedra: " << piedra << "\n";
    std::cout << "Hierro: " << hierro << "\n";
    std::cout << "Carbon: " << carbon << "\n";

    std::cout << "Oro: " << oro << "\n";
    std::cout << "Plata: " << plata << "\n";

    std::cout << "Comida: " << comida << "\n";
    std::cout << "Trigo: " << trigo << "\n";

    std::cout << "Cuero: " << cuero << "\n";
    std::cout << "Arcilla: " << arcilla << "\n";
}