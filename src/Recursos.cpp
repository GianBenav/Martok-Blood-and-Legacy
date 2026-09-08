#include "Recursos.h"

#include <iostream>


Recursos::Recursos()
{
    // ========================================
    // MATERIALES BASICOS
    // ========================================

    cantidad["Madera"] = 0;
    cantidad["Piedra"] = 0;
    cantidad["Hierro"] = 0;
    cantidad["Carbon"] = 0;

    cantidad["Oro"] = 0;
    cantidad["Plata"] = 0;
    cantidad["Cobre"] = 0;
    cantidad["Estaño"] = 0;
    cantidad["Plomo"] = 0;
    cantidad["Zinc"] = 0;

    cantidad["Azufre"] = 0;
    cantidad["Sal"] = 0;
    cantidad["Arcilla"] = 0;

    cantidad["Caliza"] = 0;
    cantidad["Granito"] = 0;
    cantidad["Marmol"] = 0;
    cantidad["Obsidiana"] = 0;


    // ========================================
    // TIPOS DE MADERA
    // ========================================

    cantidad["Roble"] = 0;
    cantidad["Pino"] = 0;
    cantidad["Abeto"] = 0;
    cantidad["Haya"] = 0;
    cantidad["Abedul"] = 0;
    cantidad["Nogal"] = 0;
    cantidad["Arce"] = 0;
    cantidad["Fresno"] = 0;
    cantidad["Olmo"] = 0;
    cantidad["Cedro"] = 0;
    cantidad["Castaño"] = 0;
    cantidad["Sauce"] = 0;
    cantidad["Tejo"] = 0;


    // ========================================
    // CULTIVOS
    // ========================================

    cantidad["Trigo"] = 0;
    cantidad["Cebada"] = 0;
    cantidad["Centeno"] = 0;
    cantidad["Avena"] = 0;
    cantidad["Maiz"] = 0;
    cantidad["Arroz"] = 0;

    cantidad["Guisantes"] = 0;
    cantidad["Lentejas"] = 0;
    cantidad["Garbanzos"] = 0;
    cantidad["Habas"] = 0;
    cantidad["Frijoles"] = 0;

    cantidad["Patatas"] = 0;
    cantidad["Zanahorias"] = 0;
    cantidad["Nabos"] = 0;
    cantidad["Cebollas"] = 0;
    cantidad["Ajo"] = 0;

    cantidad["Repollo"] = 0;
    cantidad["Lechuga"] = 0;
    cantidad["Remolacha"] = 0;
    cantidad["Pepino"] = 0;
    cantidad["Calabaza"] = 0;


    // ========================================
    // FRUTAS
    // ========================================

    cantidad["Manzana"] = 0;
    cantidad["Pera"] = 0;
    cantidad["Ciruela"] = 0;
    cantidad["Cereza"] = 0;
    cantidad["Uva"] = 0;

    cantidad["Higo"] = 0;
    cantidad["Melocoton"] = 0;
    cantidad["Albaricoque"] = 0;
    cantidad["Granada"] = 0;

    cantidad["Mora"] = 0;
    cantidad["Frambuesa"] = 0;
    cantidad["Fresa"] = 0;


    // ========================================
    // CULTIVOS ESPECIALES
    // ========================================

    cantidad["Lino"] = 0;
    cantidad["Canamo"] = 0;
    cantidad["Algodon"] = 0;
    cantidad["Lupulo"] = 0;

    cantidad["Olivas"] = 0;

    cantidad["Hierbas Medicinales"] = 0;
    cantidad["Lavanda"] = 0;
    cantidad["Romero"] = 0;
    cantidad["Menta"] = 0;
    cantidad["Azafran"] = 0;


    // ========================================
    // PRODUCTOS PROCESADOS
    // ========================================

    cantidad["Harina"] = 0;
    cantidad["Pan"] = 0;

    cantidad["Tela"] = 0;
    cantidad["Ropa"] = 0;

    cantidad["Cuero"] = 0;

    cantidad["Bronce"] = 0;
    cantidad["Acero"] = 0;

    cantidad["Herramientas"] = 0;

    cantidad["Armas"] = 0;
    cantidad["Armaduras"] = 0;

    cantidad["Vino"] = 0;
    cantidad["Cerveza"] = 0;

    cantidad["Aceite"] = 0;

    cantidad["Ceramica"] = 0;


// ========================================
// ALIMENTOS DE ORIGEN ANIMAL
// ========================================

cantidad["Carne de Vaca"] = 0;
cantidad["Carne de Cerdo"] = 0;
cantidad["Carne de Oveja"] = 0;
cantidad["Carne de Cabra"] = 0;
cantidad["Carne de Caballo"] = 0;
cantidad["Carne de Pollo"] = 0;
cantidad["Carne de Pato"] = 0;
cantidad["Carne de Ganso"] = 0;

cantidad["Carne de Conejo"] = 0;
cantidad["Carne de Ciervo"] = 0;
cantidad["Carne de Jabali"] = 0;
cantidad["Carne de Alce"] = 0;
cantidad["Carne de Bisonte"] = 0;
cantidad["Carne de Oso"] = 0;

cantidad["Pescado"] = 0;
cantidad["Mariscos"] = 0;

cantidad["Huevos"] = 0;
cantidad["Leche"] = 0;
cantidad["Queso"] = 0;
cantidad["Mantequilla"] = 0;
cantidad["Miel"] = 0;
}


// ========================================
// AGREGAR RECURSO
// ========================================

void Recursos::agregar(
    const std::string& recurso,
    int cantidadAgregar
)
{
    cantidad[recurso] += cantidadAgregar;
}


// ========================================
// CONSUMIR RECURSO
// ========================================

bool Recursos::consumir(
    const std::string& recurso,
    int cantidadConsumir
)
{
    if (cantidad[recurso] < cantidadConsumir)
    {
        return false;
    }

    cantidad[recurso] -= cantidadConsumir;

    return true;
}


// ========================================
// OBTENER CANTIDAD
// ========================================

int Recursos::obtener(
    const std::string& recurso
) const
{
    auto encontrado = cantidad.find(recurso);

    if (encontrado == cantidad.end())
    {
        return 0;
    }

    return encontrado->second;
}


// ========================================
// MOSTRAR RECURSOS
// ========================================

void Recursos::mostrarRecursos() const
{
    std::cout << "\n";
    std::cout << "========== RECURSOS ==========\n";

    for (const auto& recurso : cantidad)
    {
        if (recurso.second > 0)
        {
            std::cout
                << recurso.first
                << ": "
                << recurso.second
                << "\n";
        }
    }

    std::cout << "==============================\n";
}