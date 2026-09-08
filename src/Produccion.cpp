#include "Produccion.h"

#include <iostream>


// ========================================
// FABRICAR
// ========================================

bool fabricar(
    Recursos& recursos,
    const Receta& receta
)
{
    // Primero comprobamos TODOS los ingredientes.

    for (const Ingrediente& ingrediente : receta.ingredientes)
    {
        if (recursos.obtener(ingrediente.recurso)
            < ingrediente.cantidad)
        {
            return false;
        }
    }


    // Si tenemos todo, consumimos los materiales.

    for (const Ingrediente& ingrediente : receta.ingredientes)
    {
        recursos.consumir(
            ingrediente.recurso,
            ingrediente.cantidad
        );
    }


    // Crear el producto.

    recursos.agregar(
        receta.resultado,
        receta.cantidadResultado
    );

    return true;
}


// ========================================
// HARINA
// ========================================

Receta crearRecetaHarina()
{
    Receta receta;

    receta.nombre = "Harina";
    receta.tipo = TipoProduccion::Alimentos;

    receta.ingredientes =
    {
        {"Trigo", 2}
    };

    receta.resultado = "Harina";
    receta.cantidadResultado = 1;

    receta.tiempoProduccion = 1;

    return receta;
}


// ========================================
// PAN
// ========================================

Receta crearRecetaPan()
{
    Receta receta;

    receta.nombre = "Pan";
    receta.tipo = TipoProduccion::Alimentos;

    receta.ingredientes =
    {
        {"Harina", 2},
        {"Sal", 1}
    };

    receta.resultado = "Pan";
    receta.cantidadResultado = 4;

    receta.tiempoProduccion = 2;

    return receta;
}


// ========================================
// CARNE COCINADA
// ========================================

Receta crearRecetaCarneCocinada()
{
    Receta receta;

    receta.nombre = "Carne cocinada";
    receta.tipo = TipoProduccion::Alimentos;

    receta.ingredientes =
    {
        {"Carne de Vaca", 1},
        {"Sal", 1}
    };

    receta.resultado = "Carne Cocinada";
    receta.cantidadResultado = 1;

    receta.tiempoProduccion = 1;

    return receta;
}


// ========================================
// CARNE SALADA
// ========================================

Receta crearRecetaCarneSalada()
{
    Receta receta;

    receta.nombre = "Carne salada";
    receta.tipo = TipoProduccion::Alimentos;

    receta.ingredientes =
    {
        {"Carne de Vaca", 1},
        {"Sal", 2}
    };

    receta.resultado = "Carne Salada";
    receta.cantidadResultado = 1;

    receta.tiempoProduccion = 2;

    return receta;
}


// ========================================
// CARNE AHUMADA
// ========================================

Receta crearRecetaCarneAhumada()
{
    Receta receta;

    receta.nombre = "Carne ahumada";
    receta.tipo = TipoProduccion::Alimentos;

    receta.ingredientes =
    {
        {"Carne de Cerdo", 1},
        {"Madera", 1}
    };

    receta.resultado = "Carne Ahumada";
    receta.cantidadResultado = 1;

    receta.tiempoProduccion = 3;

    return receta;
}


// ========================================
// QUESO
// ========================================

Receta crearRecetaQueso()
{
    Receta receta;

    receta.nombre = "Queso";
    receta.tipo = TipoProduccion::Alimentos;

    receta.ingredientes =
    {
        {"Leche", 3},
        {"Sal", 1}
    };

    receta.resultado = "Queso";
    receta.cantidadResultado = 1;

    receta.tiempoProduccion = 5;

    return receta;
}


// ========================================
// MANTEQUILLA
// ========================================

Receta crearRecetaMantequilla()
{
    Receta receta;

    receta.nombre = "Mantequilla";
    receta.tipo = TipoProduccion::Alimentos;

    receta.ingredientes =
    {
        {"Leche", 2}
    };

    receta.resultado = "Mantequilla";
    receta.cantidadResultado = 1;

    receta.tiempoProduccion = 2;

    return receta;
}


// ========================================
// CERVEZA
// ========================================

Receta crearRecetaCerveza()
{
    Receta receta;

    receta.nombre = "Cerveza";
    receta.tipo = TipoProduccion::Alimentos;

    receta.ingredientes =
    {
        {"Cebada", 3},
        {"Agua", 2}
    };

    receta.resultado = "Cerveza";
    receta.cantidadResultado = 2;

    receta.tiempoProduccion = 7;

    return receta;
}


// ========================================
// BRONCE
// ========================================

Receta crearRecetaBronce()
{
    Receta receta;

    receta.nombre = "Bronce";
    receta.tipo = TipoProduccion::Metalurgia;

    receta.ingredientes =
    {
        {"Cobre", 3},
        {"Estaño", 1}
    };

    receta.resultado = "Bronce";
    receta.cantidadResultado = 3;

    receta.tiempoProduccion = 4;

    return receta;
}


// ========================================
// ACERO
// ========================================

Receta crearRecetaAcero()
{
    Receta receta;

    receta.nombre = "Acero";
    receta.tipo = TipoProduccion::Metalurgia;

    receta.ingredientes =
    {
        {"Hierro", 2},
        {"Carbon", 1}
    };

    receta.resultado = "Acero";
    receta.cantidadResultado = 2;

    receta.tiempoProduccion = 5;

    return receta;
}


// ========================================
// MADERA TRABAJADA
// ========================================

Receta crearRecetaMaderaTrabajada()
{
    Receta receta;

    receta.nombre = "Madera trabajada";
    receta.tipo = TipoProduccion::Carpinteria;

    receta.ingredientes =
    {
        {"Madera", 2}
    };

    receta.resultado = "Madera Trabajada";
    receta.cantidadResultado = 1;

    receta.tiempoProduccion = 2;

    return receta;
}


// ========================================
// MANGOS
// ========================================

Receta crearRecetaMangos()
{
    Receta receta;

    receta.nombre = "Mangos de madera";
    receta.tipo = TipoProduccion::Carpinteria;

    receta.ingredientes =
    {
        {"Madera Trabajada", 1}
    };

    receta.resultado = "Mangos";
    receta.cantidadResultado = 2;

    receta.tiempoProduccion = 2;

    return receta;
}


// ========================================
// HILO DE LINO
// ========================================

Receta crearRecetaHiloLino()
{
    Receta receta;

    receta.nombre = "Hilo de lino";
    receta.tipo = TipoProduccion::Textiles;

    receta.ingredientes =
    {
        {"Lino", 2}
    };

    receta.resultado = "Hilo de Lino";
    receta.cantidadResultado = 3;

    receta.tiempoProduccion = 2;

    return receta;
}


// ========================================
// HILO DE LANA
// ========================================

Receta crearRecetaHiloLana()
{
    Receta receta;

    receta.nombre = "Hilo de lana";
    receta.tipo = TipoProduccion::Textiles;

    receta.ingredientes =
    {
        {"Lana", 2}
    };

    receta.resultado = "Hilo de Lana";
    receta.cantidadResultado = 3;

    receta.tiempoProduccion = 2;

    return receta;
}


// ========================================
// TELA
// ========================================

Receta crearRecetaTela()
{
    Receta receta;

    receta.nombre = "Tela";
    receta.tipo = TipoProduccion::Textiles;

    receta.ingredientes =
    {
        {"Hilo de Lino", 3}
    };

    receta.resultado = "Tela";
    receta.cantidadResultado = 2;

    receta.tiempoProduccion = 3;

    return receta;
}


// ========================================
// CUERO
// ========================================

Receta crearRecetaCuero()
{
    Receta receta;

    receta.nombre = "Cuero";
    receta.tipo = TipoProduccion::Curtiduria;

    receta.ingredientes =
    {
        {"Piel", 2},
        {"Sal", 1}
    };

    receta.resultado = "Cuero";
    receta.cantidadResultado = 1;

    receta.tiempoProduccion = 5;

    return receta;
}


// ========================================
// CERAMICA
// ========================================

Receta crearRecetaCeramica()
{
    Receta receta;

    receta.nombre = "Ceramica";
    receta.tipo = TipoProduccion::Ceramica;

    receta.ingredientes =
    {
        {"Arcilla", 2}
    };

    receta.resultado = "Ceramica";
    receta.cantidadResultado = 1;

    receta.tiempoProduccion = 3;

    return receta;
}


// ========================================
// LADRILLOS
// ========================================

Receta crearRecetaLadrillos()
{
    Receta receta;

    receta.nombre = "Ladrillos";
    receta.tipo = TipoProduccion::Construccion;

    receta.ingredientes =
    {
        {"Arcilla", 3}
    };

    receta.resultado = "Ladrillos";
    receta.cantidadResultado = 5;

    receta.tiempoProduccion = 4;

    return receta;
}


// ========================================
// CAL
// ========================================

Receta crearRecetaCal()
{
    Receta receta;

    receta.nombre = "Cal";
    receta.tipo = TipoProduccion::Construccion;

    receta.ingredientes =
    {
        {"Caliza", 2}
    };

    receta.resultado = "Cal";
    receta.cantidadResultado = 1;

    receta.tiempoProduccion = 4;

    return receta;
}


// ========================================
// NOMBRE TIPO
// ========================================

std::string obtenerNombreTipoProduccion(
    TipoProduccion tipo
)
{
    switch (tipo)
    {
        case TipoProduccion::Alimentos:
            return "Alimentos";

        case TipoProduccion::Metalurgia:
            return "Metalurgia";

        case TipoProduccion::Herreria:
            return "Herreria";

        case TipoProduccion::Carpinteria:
            return "Carpinteria";

        case TipoProduccion::Textiles:
            return "Textiles";

        case TipoProduccion::Curtiduria:
            return "Curtiduria";

        case TipoProduccion::Ceramica:
            return "Ceramica";

        case TipoProduccion::Construccion:
            return "Construccion";

        case TipoProduccion::Otros:
            return "Otros";
    }

    return "Desconocido";
}


// ========================================
// MOSTRAR RECETA
// ========================================

void mostrarReceta(
    const Receta& receta
)
{
    std::cout << "\n";
    std::cout << "========== RECETA ==========\n";

    std::cout << "Nombre: "
              << receta.nombre
              << "\n";

    std::cout << "Tipo: "
              << obtenerNombreTipoProduccion(receta.tipo)
              << "\n";

    std::cout << "Ingredientes:\n";

    for (const Ingrediente& ingrediente : receta.ingredientes)
    {
        std::cout
            << "  "
            << ingrediente.cantidad
            << "x "
            << ingrediente.recurso
            << "\n";
    }

    std::cout << "Resultado: "
              << receta.cantidadResultado
              << "x "
              << receta.resultado
              << "\n";

    std::cout << "Tiempo: "
              << receta.tiempoProduccion
              << "\n";

    std::cout << "============================\n";
}