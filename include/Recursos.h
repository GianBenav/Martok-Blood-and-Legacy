#pragma once

#include <map>
#include <string>

struct PropiedadesMaterial
{
    int dureza;
    int resistencia;
    int peso;
    int flexibilidad;
    int valor;
};

class Recursos
{
public:

    std::map<std::string, int> cantidad;

    Recursos();

    void agregar(const std::string& recurso, int cantidad);
    bool consumir(const std::string& recurso, int cantidad);

    int obtener(const std::string& recurso) const;

    PropiedadesMaterial obtenerPropiedades(
        const std::string& recurso
    ) const;

    void mostrarRecursos() const;
};