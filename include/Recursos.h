#pragma once

#include <map>
#include <string>

class Recursos
{
public:

    std::map<std::string, int> cantidad;

    Recursos();

    void agregar(const std::string& recurso, int cantidad);
    bool consumir(const std::string& recurso, int cantidad);

    int obtener(const std::string& recurso) const;

    void mostrarRecursos() const;
};