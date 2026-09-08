#pragma once

#include "Recursos.h"

#include <string>
#include <vector>

enum class TipoProduccion
{
    Alimentos,
    Metalurgia,
    Herreria,
    Carpinteria,
    Textiles,
    Curtiduria,
    Ceramica,
    Construccion,
    Otros
};


struct Ingrediente
{
    std::string recurso;
    int cantidad;
};


struct Receta
{
    std::string nombre;

    TipoProduccion tipo;

    std::vector<Ingrediente> ingredientes;

    std::string resultado;

    int cantidadResultado;

    int tiempoProduccion;
};


// ========================================
// PRODUCCION
// ========================================

bool fabricar(
    Recursos& recursos,
    const Receta& receta
);


// ========================================
// RECETAS DE ALIMENTOS
// ========================================

Receta crearRecetaHarina();

Receta crearRecetaPan();

Receta crearRecetaCarneCocinada();

Receta crearRecetaCarneSalada();

Receta crearRecetaCarneAhumada();

Receta crearRecetaQueso();

Receta crearRecetaMantequilla();

Receta crearRecetaCerveza();


// ========================================
// METALURGIA
// ========================================

Receta crearRecetaBronce();

Receta crearRecetaAcero();


// ========================================
// CARPINTERIA
// ========================================

Receta crearRecetaMaderaTrabajada();

Receta crearRecetaMangos();


// ========================================
// TEXTILES
// ========================================

Receta crearRecetaHiloLino();

Receta crearRecetaHiloLana();

Receta crearRecetaTela();


// ========================================
// CURTIDURIA
// ========================================

Receta crearRecetaCuero();


// ========================================
// CERAMICA
// ========================================

Receta crearRecetaCeramica();


// ========================================
// CONSTRUCCION
// ========================================

Receta crearRecetaLadrillos();

Receta crearRecetaCal();


// ========================================
// INFORMACION
// ========================================

std::string obtenerNombreTipoProduccion(
    TipoProduccion tipo
);

void mostrarReceta(
    const Receta& receta
);