#include "Recursos.h"
#include <iostream>

Recursos::Recursos()
{
    // =========================
    // MATERIALES
    // =========================

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

    // =========================
    // MADERAS
    // =========================

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
    cantidad["Castano"] = 0;
    cantidad["Sauce"] = 0;
    cantidad["Tejo"] = 0;
    cantidad["Caoba"] = 0;

    // =========================
    // CULTIVOS
    // =========================

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

    // =========================
    // FRUTAS
    // =========================

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

    // =========================
    // PLANTAS Y CULTIVOS ESPECIALES
    // =========================

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

    // =========================
    // RECURSOS ANIMALES
    // =========================

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

    // =========================
    // RECURSOS IMPORTANTES
    // =========================

    cantidad["Agua"] = 0;
    cantidad["Piel"] = 0;
    cantidad["Lana"] = 0;

    // =========================
    // MATERIALES PROCESADOS
    // =========================

    cantidad["Harina"] = 0;
    cantidad["Pan"] = 0;

    cantidad["Carne Cocinada"] = 0;
    cantidad["Carne Salada"] = 0;
    cantidad["Carne Ahumada"] = 0;

    cantidad["Cerveza"] = 0;
    cantidad["Vino"] = 0;

    cantidad["Bronce"] = 0;
    cantidad["Acero"] = 0;

    cantidad["Madera Trabajada"] = 0;
    cantidad["Mangos"] = 0;

    cantidad["Hilo de Lino"] = 0;
    cantidad["Hilo de Lana"] = 0;
    cantidad["Tela"] = 0;

    cantidad["Cuero"] = 0;

    cantidad["Ceramica"] = 0;
    cantidad["Ladrillos"] = 0;
    cantidad["Cal"] = 0;
}


void Recursos::agregar(
    const std::string& recurso,
    int cantidadAgregar
)
{
    cantidad[recurso] += cantidadAgregar;
}


bool Recursos::consumir(
    const std::string& recurso,
    int cantidadConsumir
)
{
    if (cantidad[recurso] < cantidadConsumir)
        return false;

    cantidad[recurso] -= cantidadConsumir;

    return true;
}


int Recursos::obtener(
    const std::string& recurso
) const
{
    auto encontrado = cantidad.find(recurso);

    if (encontrado == cantidad.end())
        return 0;

    return encontrado->second;
}


PropiedadesMaterial Recursos::obtenerPropiedades(
    const std::string& recurso
) const
{
    // =========================
    // MADERAS
    // =========================

    if (recurso == "Roble")
        return {75, 80, 65, 40, 70};

    if (recurso == "Pino")
        return {40, 45, 35, 70, 35};

    if (recurso == "Abeto")
        return {45, 50, 35, 65, 40};

    if (recurso == "Haya")
        return {70, 75, 60, 45, 65};

    if (recurso == "Abedul")
        return {55, 60, 45, 60, 50};

    if (recurso == "Nogal")
        return {80, 75, 65, 40, 85};

    if (recurso == "Arce")
        return {75, 80, 60, 45, 75};

    if (recurso == "Fresno")
        return {70, 85, 55, 65, 70};

    if (recurso == "Olmo")
        return {65, 80, 60, 55, 65};

    if (recurso == "Cedro")
        return {50, 50, 35, 60, 70};

    if (recurso == "Castano")
        return {65, 70, 55, 50, 60};

    if (recurso == "Sauce")
        return {30, 35, 30, 85, 30};

    if (recurso == "Tejo")
        return {90, 85, 60, 70, 100};

    if (recurso == "Caoba")
        return {85, 85, 65, 45, 100};


    // =========================
    // METALES
    // =========================

    if (recurso == "Hierro")
        return {80, 85, 75, 20, 60};

    if (recurso == "Cobre")
        return {45, 50, 85, 50, 65};

    if (recurso == "Bronce")
        return {70, 75, 80, 30, 75};

    if (recurso == "Acero")
        return {95, 100, 75, 25, 90};

    if (recurso == "Plata")
        return {40, 45, 100, 35, 100};

    if (recurso == "Oro")
        return {35, 40, 100, 30, 100};

    if (recurso == "Estaño")
        return {25, 30, 90, 40, 40};

    if (recurso == "Plomo")
        return {20, 25, 120, 20, 30};

    if (recurso == "Zinc")
        return {35, 40, 85, 35, 45};


    // =========================
    // PIEDRAS
    // =========================

    if (recurso == "Granito")
        return {90, 95, 100, 5, 70};

    if (recurso == "Marmol")
        return {65, 70, 95, 10, 90};

    if (recurso == "Obsidiana")
        return {100, 60, 80, 5, 100};


    // =========================
    // CUERO
    // =========================

    if (recurso == "Cuero")
        return {55, 65, 45, 75, 60};


    // =========================
    // VALORES POR DEFECTO
    // =========================

    return {10, 10, 10, 10, 1};
}


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