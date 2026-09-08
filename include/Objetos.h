#pragma once

#include <string>

// ========================================
// TIPOS DE OBJETOS
// ========================================

enum class TipoObjeto
{
    // ARMAS
    Espada,
    Lanza,
    Maza,
    Hacha,
    Daga,
    Martillo,
    Arco,
    Ballesta,

    // ESCUDOS
    Escudo,

    // ARMADURAS
    Armadura,
    Casco,
    Pechera,
    Guantes,
    Grebas,
    Botas,
    ArmaduraCompleta,

    // ROPA
    Camisa,
    Pantalones,
    Tunica,
    Capa,
    Vestido,
    BotasRopa,

    // HERRAMIENTAS
    HachaTrabajo,
    Pico,
    MartilloTrabajo,
    Azada,
    Pala,
    Sierra
};


// ========================================
// VARIANTES DE ARMAS
// ========================================

enum class VarianteArma
{
    Ninguna,

    // ESPADAS
    EspadaCorta,
    EspadaLarga,
    EspadaBastarda,
    Mandoble,
    Estoque,
    Sable,

    // LANZAS
    Lanza,
    Pica,
    Jabalina,
    Alabarda,

    // MAZAS
    MazaLigera,
    MazaPesada,
    MazaConPuas,
    Mayal,

    // HACHAS
    HachaDeMano,
    HachaDeBatalla,
    HachaDanesa,
    HachaDeDosManos,

    // ARCOS
    ArcoCorto,
    ArcoLargo,
    ArcoRecurvo,

    // BALLESTAS
    BallestaLigera,
    BallestaPesada,
    BallestaDeGuerra,

    // DAGAS
    Daga,
    Estilete,

    // MARTILLOS
    MartilloDeGuerra,
    MartilloPesado
};


// ========================================
// VARIANTES DE ESCUDOS
// ========================================

enum class VarianteEscudo
{
    Ninguno,

    // PEQUEÑOS
    Broquel,
    EscudoRedondoPequeno,

    // REDONDOS
    EscudoRedondo,
    EscudoRedondoGrande,

    // OVALADOS
    EscudoOvalado,
    EscudoOvaladoGrande,

    // DE COMETA
    EscudoDeCometa,
    EscudoDeCometaGrande,

    // ALARGADOS
    EscudoAlargado,
    EscudoAlargadoGrande,

    // RECTANGULARES
    EscudoRectangular,
    EscudoRectangularGrande,

    // DE TORRE
    EscudoDeTorre,
    EscudoDeTorreGrande,

    // ESPECIALES
    EscudoHeraldico,
    EscudoDeGuerra,
    EscudoCeremonial
};


// ========================================
// VARIANTES DE ARMADURA
// ========================================

enum class VarianteArmadura
{
    Ninguna,

    // CUERO
    ArmaduraDeCuero,
    ArmaduraDeCueroReforzado,

    // ACOLCHADA
    Gambeson,

    // MALLA
    CotaDeMalla,
    CotaDeMallaPesada,

    // ESCAMAS
    ArmaduraDeEscamas,

    // PLACAS
    ArmaduraDePlacas,
    ArmaduraDePlacasPesada,

    // ESPECIALES
    ArmaduraDeGuerra
};


// ========================================
// OBJETO
// ========================================

struct Objeto
{
    // IDENTIDAD
    int id;
    std::string nombre;

    // CLASIFICACIÓN
    TipoObjeto tipo;

    VarianteArma varianteArma;
    VarianteEscudo varianteEscudo;
    VarianteArmadura varianteArmadura;

    // MATERIAL
    std::string material;

    // CALIDAD
    int calidad;

    // ESTADÍSTICAS GENERALES
    int daño;
    int defensa;
    int durabilidad;
    int peso;

    // ESTADÍSTICAS DE COMBATE
    int velocidad;
    int alcance;
    int penetracion;

    // ESTADÍSTICAS DE ESCUDO
    int bloqueo;
    int cobertura;
    int estabilidad;

    // VALOR ECONÓMICO
    int valor;

    // ========================================
    // INFORMACIÓN DEL ARTESANO
    // ========================================

    int artesanoID;

    std::string artesanoNombre;

    // Firma permanente del creador
    std::string firma;
};


// ========================================
// FUNCIONES
// ========================================

// CREAR ARMAS
Objeto crearArma(
    int id,
    VarianteArma variante,
    const std::string& material,
    int habilidadArtesano,
    int artesanoID,
    const std::string& artesanoNombre
);


// CREAR ESCUDOS
Objeto crearEscudo(
    int id,
    VarianteEscudo variante,
    const std::string& material,
    int habilidadArtesano,
    int artesanoID,
    const std::string& artesanoNombre
);


// CREAR ARMADURAS
Objeto crearArmadura(
    int id,
    VarianteArmadura variante,
    const std::string& material,
    int habilidadArtesano,
    int artesanoID,
    const std::string& artesanoNombre
);


// NOMBRES
std::string obtenerNombreVariante(
    VarianteArma variante
);

std::string obtenerNombreVarianteEscudo(
    VarianteEscudo variante
);

std::string obtenerNombreArmadura(
    VarianteArmadura variante
);


// MOSTRAR OBJETO
void mostrarObjeto(
    const Objeto& objeto
);