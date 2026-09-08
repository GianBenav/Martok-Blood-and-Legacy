#pragma once

#include "Objetos.h"

#include <string>
#include <vector>

struct RecursoInventario
{
    std::string nombre;
    int cantidad;
};

class Inventario
{
public:

    // Objetos individuales
    std::vector<Objeto> objetos;

    // Recursos que pueden acumularse
    std::vector<RecursoInventario> recursos;

    // ==============================
    // OBJETOS
    // ==============================

    void agregarObjeto(const Objeto& objeto);

    bool eliminarObjeto(int id);

    Objeto* buscarObjeto(int id);

    // ==============================
    // RECURSOS
    // ==============================

    void agregarRecurso(
        const std::string& nombre,
        int cantidad
    );

    bool consumirRecurso(
        const std::string& nombre,
        int cantidad
    );

    int obtenerCantidadRecurso(
        const std::string& nombre
    ) const;

    // ==============================
    // INFORMACION
    // ==============================

    void mostrarInventario() const;

    int obtenerCantidadObjetos() const;
};