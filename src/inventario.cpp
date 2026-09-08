#include "Inventario.h"

#include <iostream>

// ========================================
// AGREGAR OBJETO
// ========================================

void Inventario::agregarObjeto(const Objeto& objeto)
{
    objetos.push_back(objeto);
}

// ========================================
// ELIMINAR OBJETO
// ========================================

bool Inventario::eliminarObjeto(int id)
{
    for (auto it = objetos.begin(); it != objetos.end(); ++it)
    {
        if (it->id == id)
        {
            objetos.erase(it);
            return true;
        }
    }

    return false;
}

// ========================================
// BUSCAR OBJETO
// ========================================

Objeto* Inventario::buscarObjeto(int id)
{
    for (auto& objeto : objetos)
    {
        if (objeto.id == id)
        {
            return &objeto;
        }
    }

    return nullptr;
}

// ========================================
// AGREGAR RECURSO
// ========================================

void Inventario::agregarRecurso(
    const std::string& nombre,
    int cantidad
)
{
    if (cantidad <= 0)
    {
        return;
    }

    for (auto& recurso : recursos)
    {
        if (recurso.nombre == nombre)
        {
            recurso.cantidad += cantidad;
            return;
        }
    }

    RecursoInventario nuevo;

    nuevo.nombre = nombre;
    nuevo.cantidad = cantidad;

    recursos.push_back(nuevo);
}

// ========================================
// CONSUMIR RECURSO
// ========================================

bool Inventario::consumirRecurso(
    const std::string& nombre,
    int cantidad
)
{
    if (cantidad <= 0)
    {
        return false;
    }

    for (auto& recurso : recursos)
    {
        if (recurso.nombre == nombre)
        {
            if (recurso.cantidad < cantidad)
            {
                return false;
            }

            recurso.cantidad -= cantidad;

            return true;
        }
    }

    return false;
}

// ========================================
// OBTENER CANTIDAD
// ========================================

int Inventario::obtenerCantidadRecurso(
    const std::string& nombre
) const
{
    for (const auto& recurso : recursos)
    {
        if (recurso.nombre == nombre)
        {
            return recurso.cantidad;
        }
    }

    return 0;
}

// ========================================
// MOSTRAR INVENTARIO
// ========================================

void Inventario::mostrarInventario() const
{
    std::cout << "\n================================\n";
    std::cout << "INVENTARIO\n";
    std::cout << "================================\n";

    std::cout << "\nOBJETOS:\n";

    if (objetos.empty())
    {
        std::cout << "No hay objetos.\n";
    }
    else
    {
        for (const auto& objeto : objetos)
        {
            std::cout << "\nID: "
                      << objeto.id
                      << "\n";

            std::cout << "Nombre: "
                      << objeto.nombre
                      << "\n";

            std::cout << "Material: "
                      << objeto.material
                      << "\n";

            std::cout << "Calidad: "
                      << objeto.calidad
                      << "\n";

            std::cout << "Durabilidad: "
                      << objeto.durabilidad
                      << "\n";

            std::cout << "Firma: "
                      << objeto.firma
                      << "\n";
        }
    }

    std::cout << "\nRECURSOS:\n";

    if (recursos.empty())
    {
        std::cout << "No hay recursos.\n";
    }
    else
    {
        for (const auto& recurso : recursos)
        {
            std::cout << recurso.nombre
                      << " x"
                      << recurso.cantidad
                      << "\n";
        }
    }

    std::cout << "================================\n";
}

// ========================================
// CANTIDAD DE OBJETOS
// ========================================

int Inventario::obtenerCantidadObjetos() const
{
    return static_cast<int>(objetos.size());
}