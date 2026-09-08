#include "Objetos.h"
#include "Recursos.h"

#include <iostream>
#include <algorithm>
#include <random>

// ============================================================
// FUNCIONES AUXILIARES
// ============================================================

int variacionAleatoria(int minimo, int maximo)
{
    static std::random_device rd;
    static std::mt19937 gen(rd());

    std::uniform_int_distribution<int> distribucion(minimo, maximo);
    return distribucion(gen);
}

// ------------------------------------------------------------

int calcularCalidad(int habilidadArtesano)
{
    int calidad = habilidadArtesano + variacionAleatoria(-10, 10);

    return std::clamp(calidad, 1, 100);
}

// ------------------------------------------------------------

double obtenerMultiplicadorCalidad(int calidad)
{
    if (calidad <= 20)
        return 0.70;

    if (calidad <= 40)
        return 0.85;

    if (calidad <= 60)
        return 1.00;

    if (calidad <= 80)
        return 1.15;

    if (calidad <= 95)
        return 1.30;

    return 1.45;
}

// ------------------------------------------------------------

double obtenerMultiplicadorMaterial(
    const PropiedadesMaterial& propiedades)
{
    return
        (propiedades.dureza * 0.40 +
         propiedades.resistencia * 0.40 +
         propiedades.flexibilidad * 0.20) / 100.0;
}

// ------------------------------------------------------------

Objeto crearObjetoBase(
    int id,
    const std::string& material,
    int habilidadArtesano,
    int artesanoID,
    const std::string& artesanoNombre)
{
    Objeto objeto{};

    objeto.id = id;
    objeto.material = material;

    objeto.tipo = TipoObjeto::Espada;

    objeto.varianteArma = VarianteArma::Ninguna;
    objeto.varianteEscudo = VarianteEscudo::Ninguno;
    objeto.varianteArmadura = VarianteArmadura::Ninguna;
    objeto.varianteRopa = VarianteRopa::Ninguna;
    objeto.varianteJoya = VarianteJoya::Ninguna;

    objeto.calidad = calcularCalidad(habilidadArtesano);

    objeto.defensa = 0;
    objeto.defensaCorte = 0;
    objeto.defensaPerforacion = 0;
    objeto.defensaGolpe = 0;
    objeto.defensaProyectiles = 0;

    objeto.fuerza = 0;
    objeto.velocidad = 0;
    objeto.resistencia = 0;
    objeto.percepcion = 0;
    objeto.inteligencia = 0;
    objeto.carisma = 0;
    objeto.sigilo = 0;

    objeto.resistenciaFrio = 0;
    objeto.resistenciaCalor = 0;
    objeto.resistenciaAgua = 0;
    objeto.resistenciaEnfermedades = 0;

    objeto.daño = 0;
    objeto.precision = 0;
    objeto.alcance = 0;
    objeto.penetracion = 0;
    objeto.bloqueo = 0;
    objeto.cobertura = 0;
    objeto.estabilidad = 0;

    objeto.agricultura = 0;
    objeto.herreria = 0;
    objeto.carpinteria = 0;
    objeto.mineria = 0;
    objeto.canteria = 0;
    objeto.caza = 0;
    objeto.pesca = 0;
    objeto.comercio = 0;
    objeto.medicina = 0;
    objeto.exploracion = 0;
    objeto.cocina = 0;
    objeto.costura = 0;

    objeto.durabilidad = 0;
    objeto.peso = 0;

    objeto.valor = 0;

    // NUEVO: PRESTIGIO
    objeto.prestigio = 0;

    objeto.artesanoID = artesanoID;
    objeto.artesanoNombre = artesanoNombre;

    objeto.firma =
        "Creado por " + artesanoNombre +
        " #" + std::to_string(artesanoID);

    return objeto;
}

// ------------------------------------------------------------
// Calcula prestigio según calidad.
// prestigioBase representa la importancia social del objeto.
// ------------------------------------------------------------

int calcularPrestigio(
    int prestigioBase,
    int calidad,
    int valorMaterial)
{
    double multiplicador = 0.5 + (calidad / 100.0);

    int prestigioMaterial = valorMaterial / 10;

    int resultado = static_cast<int>(
        (prestigioBase + prestigioMaterial) *
        multiplicador
    );

    return std::max(0, resultado);
}

// ============================================================
// ARMAS
// ============================================================

Objeto crearArma(
    int id,
    VarianteArma variante,
    const std::string& material,
    int habilidadArtesano,
    int artesanoID,
    const std::string& artesanoNombre)
{
    Recursos recursos;

    Objeto objeto = crearObjetoBase(
        id,
        material,
        habilidadArtesano,
        artesanoID,
        artesanoNombre
    );

    objeto.tipo = TipoObjeto::Espada;
    objeto.varianteArma = variante;

    PropiedadesMaterial propiedades =
        recursos.obtenerPropiedades(material);

    double multiplicadorMaterial =
        obtenerMultiplicadorMaterial(propiedades);

    double multiplicadorCalidad =
        obtenerMultiplicadorCalidad(objeto.calidad);

    int danoBase = 0;
    int pesoBase = 0;
    int velocidadBase = 0;
    int alcanceBase = 0;
    int penetracionBase = 0;
    int prestigioBase = 2;

    switch (variante)
    {
        // ----------------------------------------------------
        // ESPADAS
        // ----------------------------------------------------

        case VarianteArma::EspadaCorta:
            objeto.nombre = "Espada Corta";
            danoBase = 25;
            pesoBase = 30;
            velocidadBase = 80;
            alcanceBase = 35;
            penetracionBase = 20;
            prestigioBase = 5;
            objeto.tipo = TipoObjeto::Espada;
            break;

        case VarianteArma::EspadaLarga:
            objeto.nombre = "Espada Larga";
            danoBase = 35;
            pesoBase = 40;
            velocidadBase = 65;
            alcanceBase = 50;
            penetracionBase = 30;
            prestigioBase = 8;
            objeto.tipo = TipoObjeto::Espada;
            break;

        case VarianteArma::EspadaBastarda:
            objeto.nombre = "Espada Bastarda";
            danoBase = 42;
            pesoBase = 48;
            velocidadBase = 60;
            alcanceBase = 55;
            penetracionBase = 35;
            prestigioBase = 10;
            objeto.tipo = TipoObjeto::Espada;
            break;

        case VarianteArma::Mandoble:
            objeto.nombre = "Mandoble";
            danoBase = 60;
            pesoBase = 70;
            velocidadBase = 40;
            alcanceBase = 70;
            penetracionBase = 45;
            prestigioBase = 14;
            objeto.tipo = TipoObjeto::Espada;
            break;

        case VarianteArma::Estoque:
            objeto.nombre = "Estoque";
            danoBase = 28;
            pesoBase = 25;
            velocidadBase = 90;
            alcanceBase = 55;
            penetracionBase = 60;
            prestigioBase = 9;
            objeto.tipo = TipoObjeto::Espada;
            break;

        case VarianteArma::Sable:
            objeto.nombre = "Sable";
            danoBase = 32;
            pesoBase = 30;
            velocidadBase = 85;
            alcanceBase = 50;
            penetracionBase = 25;
            prestigioBase = 9;
            objeto.tipo = TipoObjeto::Espada;
            break;

        // ----------------------------------------------------
        // LANZAS
        // ----------------------------------------------------

        case VarianteArma::LanzaSimple:
            objeto.nombre = "Lanza Simple";
            danoBase = 30;
            pesoBase = 28;
            velocidadBase = 70;
            alcanceBase = 85;
            penetracionBase = 45;
            prestigioBase = 4;
            objeto.tipo = TipoObjeto::Lanza;
            break;

        case VarianteArma::Pica:
            objeto.nombre = "Pica";
            danoBase = 38;
            pesoBase = 35;
            velocidadBase = 55;
            alcanceBase = 100;
            penetracionBase = 60;
            prestigioBase = 7;
            objeto.tipo = TipoObjeto::Lanza;
            break;

        case VarianteArma::Jabalina:
            objeto.nombre = "Jabalina";
            danoBase = 32;
            pesoBase = 15;
            velocidadBase = 85;
            alcanceBase = 65;
            penetracionBase = 50;
            prestigioBase = 6;
            objeto.tipo = TipoObjeto::Lanza;
            break;

        case VarianteArma::Alabarda:
            objeto.nombre = "Alabarda";
            danoBase = 55;
            pesoBase = 65;
            velocidadBase = 45;
            alcanceBase = 90;
            penetracionBase = 65;
            prestigioBase = 15;
            objeto.tipo = TipoObjeto::Lanza;
            break;

        // ----------------------------------------------------
        // MAZAS
        // ----------------------------------------------------

        case VarianteArma::MazaLigera:
            objeto.nombre = "Maza Ligera";
            danoBase = 30;
            pesoBase = 30;
            velocidadBase = 65;
            alcanceBase = 30;
            penetracionBase = 10;
            prestigioBase = 4;
            objeto.tipo = TipoObjeto::Maza;
            break;

        case VarianteArma::MazaPesada:
            objeto.nombre = "Maza Pesada";
            danoBase = 55;
            pesoBase = 60;
            velocidadBase = 40;
            alcanceBase = 35;
            penetracionBase = 25;
            prestigioBase = 9;
            objeto.tipo = TipoObjeto::Maza;
            break;

        case VarianteArma::MazaConPuas:
            objeto.nombre = "Maza con Púas";
            danoBase = 50;
            pesoBase = 50;
            velocidadBase = 45;
            alcanceBase = 35;
            penetracionBase = 40;
            prestigioBase = 10;
            objeto.tipo = TipoObjeto::Maza;
            break;

        case VarianteArma::Mayal:
            objeto.nombre = "Mayal";
            danoBase = 48;
            pesoBase = 45;
            velocidadBase = 50;
            alcanceBase = 45;
            penetracionBase = 30;
            prestigioBase = 10;
            objeto.tipo = TipoObjeto::Maza;
            break;

        // ----------------------------------------------------
        // HACHAS
        // ----------------------------------------------------

        case VarianteArma::HachaDeMano:
            objeto.nombre = "Hacha de Mano";
            danoBase = 32;
            pesoBase = 35;
            velocidadBase = 65;
            alcanceBase = 30;
            penetracionBase = 25;
            prestigioBase = 4;
            objeto.tipo = TipoObjeto::Hacha;
            break;

        case VarianteArma::HachaDeBatalla:
            objeto.nombre = "Hacha de Batalla";
            danoBase = 48;
            pesoBase = 50;
            velocidadBase = 50;
            alcanceBase = 45;
            penetracionBase = 35;
            prestigioBase = 9;
            objeto.tipo = TipoObjeto::Hacha;
            break;

        case VarianteArma::HachaDanesa:
            objeto.nombre = "Hacha Danesa";
            danoBase = 55;
            pesoBase = 55;
            velocidadBase = 45;
            alcanceBase = 55;
            penetracionBase = 40;
            prestigioBase = 11;
            objeto.tipo = TipoObjeto::Hacha;
            break;

        case VarianteArma::HachaDeDosManos:
            objeto.nombre = "Hacha de Dos Manos";
            danoBase = 65;
            pesoBase = 75;
            velocidadBase = 35;
            alcanceBase = 60;
            penetracionBase = 45;
            prestigioBase = 14;
            objeto.tipo = TipoObjeto::Hacha;
            break;

        // ----------------------------------------------------
        // ARCOS
        // ----------------------------------------------------

        case VarianteArma::ArcoCorto:
            objeto.nombre = "Arco Corto";
            danoBase = 25;
            pesoBase = 12;
            velocidadBase = 75;
            alcanceBase = 70;
            penetracionBase = 25;
            prestigioBase = 5;
            objeto.tipo = TipoObjeto::Arco;
            break;

        case VarianteArma::ArcoLargo:
            objeto.nombre = "Arco Largo";
            danoBase = 38;
            pesoBase = 18;
            velocidadBase = 60;
            alcanceBase = 100;
            penetracionBase = 40;
            prestigioBase = 10;
            objeto.tipo = TipoObjeto::Arco;
            break;

        case VarianteArma::ArcoRecurvo:
            objeto.nombre = "Arco Recurvo";
            danoBase = 35;
            pesoBase = 16;
            velocidadBase = 75;
            alcanceBase = 90;
            penetracionBase = 35;
            prestigioBase = 11;
            objeto.tipo = TipoObjeto::Arco;
            break;

        // ----------------------------------------------------
        // BALLESTAS
        // ----------------------------------------------------

        case VarianteArma::BallestaLigera:
            objeto.nombre = "Ballesta Ligera";
            danoBase = 40;
            pesoBase = 30;
            velocidadBase = 40;
            alcanceBase = 90;
            penetracionBase = 55;
            prestigioBase = 8;
            objeto.tipo = TipoObjeto::Ballesta;
            break;

        case VarianteArma::BallestaPesada:
            objeto.nombre = "Ballesta Pesada";
            danoBase = 60;
            pesoBase = 50;
            velocidadBase = 25;
            alcanceBase = 110;
            penetracionBase = 75;
            prestigioBase = 14;
            objeto.tipo = TipoObjeto::Ballesta;
            break;

        case VarianteArma::BallestaDeGuerra:
            objeto.nombre = "Ballesta de Guerra";
            danoBase = 70;
            pesoBase = 60;
            velocidadBase = 20;
            alcanceBase = 120;
            penetracionBase = 85;
            prestigioBase = 18;
            objeto.tipo = TipoObjeto::Ballesta;
            break;

        // ----------------------------------------------------
        // DAGAS
        // ----------------------------------------------------

        case VarianteArma::Daga:
            objeto.nombre = "Daga";
            danoBase = 20;
            pesoBase = 10;
            velocidadBase = 95;
            alcanceBase = 20;
            penetracionBase = 50;
            prestigioBase = 3;
            objeto.tipo = TipoObjeto::Daga;
            break;

        case VarianteArma::Estilete:
            objeto.nombre = "Estilete";
            danoBase = 18;
            pesoBase = 8;
            velocidadBase = 100;
            alcanceBase = 20;
            penetracionBase = 80;
            prestigioBase = 8;
            objeto.tipo = TipoObjeto::Daga;
            break;

        // ----------------------------------------------------
        // MARTILLOS
        // ----------------------------------------------------

        case VarianteArma::MartilloDeGuerra:
            objeto.nombre = "Martillo de Guerra";
            danoBase = 55;
            pesoBase = 55;
            velocidadBase = 40;
            alcanceBase = 40;
            penetracionBase = 45;
            prestigioBase = 11;
            objeto.tipo = TipoObjeto::Martillo;
            break;

        case VarianteArma::MartilloPesado:
            objeto.nombre = "Martillo Pesado";
            danoBase = 70;
            pesoBase = 80;
            velocidadBase = 30;
            alcanceBase = 40;
            penetracionBase = 55;
            prestigioBase = 15;
            objeto.tipo = TipoObjeto::Martillo;
            break;

        case VarianteArma::Ninguna:
        default:
            objeto.nombre = "Arma";
            danoBase = 10;
            pesoBase = 20;
            velocidadBase = 50;
            alcanceBase = 30;
            penetracionBase = 10;
            break;
    }

    objeto.daño = static_cast<int>(
        danoBase *
        multiplicadorMaterial *
        multiplicadorCalidad
    );

    objeto.peso = std::max(
        1,
        static_cast<int>(
            pesoBase *
            (propiedades.peso / 60.0)
        )
    );

    objeto.velocidad = std::max(
        1,
        static_cast<int>(
            velocidadBase -
            objeto.peso * 0.25
        )
    );

    objeto.alcance = static_cast<int>(
        alcanceBase *
        (0.8 + propiedades.flexibilidad / 500.0)
    );

    objeto.penetracion = static_cast<int>(
        penetracionBase *
        (propiedades.dureza / 100.0) *
        multiplicadorCalidad
    );

    objeto.precision =
        std::clamp(
            40 +
            propiedades.flexibilidad / 3 +
            objeto.calidad / 4,
            1,
            100
        );

    objeto.estabilidad =
        std::clamp(
            propiedades.resistencia / 2 +
            objeto.calidad / 3,
            1,
            100
        );

    objeto.durabilidad = std::max(
        10,
        static_cast<int>(
            propiedades.resistencia *
            2.0 *
            multiplicadorCalidad
        )
    );

    objeto.valor = std::max(
        1,
        static_cast<int>(
            propiedades.valor *
            (1.0 + objeto.calidad / 100.0) +
            objeto.daño * 2
        )
    );

    objeto.prestigio =
        calcularPrestigio(
            prestigioBase,
            objeto.calidad,
            propiedades.valor
        );

    return objeto;
}

// ============================================================
// ESCUDOS
// ============================================================

Objeto crearEscudo(
    int id,
    VarianteEscudo variante,
    const std::string& material,
    int habilidadArtesano,
    int artesanoID,
    const std::string& artesanoNombre)
{
    Recursos recursos;

    Objeto objeto = crearObjetoBase(
        id,
        material,
        habilidadArtesano,
        artesanoID,
        artesanoNombre
    );

    objeto.tipo = TipoObjeto::Escudo;
    objeto.varianteEscudo = variante;

    PropiedadesMaterial propiedades =
        recursos.obtenerPropiedades(material);

    double multiplicadorCalidad =
        obtenerMultiplicadorCalidad(objeto.calidad);

    int defensaBase = 25;
    int bloqueoBase = 30;
    int coberturaBase = 20;
    int pesoBase = 35;
    int estabilidadBase = 30;
    int prestigioBase = 3;

    switch (variante)
    {
        case VarianteEscudo::Broquel:
            objeto.nombre = "Broquel";
            defensaBase = 20;
            bloqueoBase = 45;
            coberturaBase = 10;
            pesoBase = 15;
            estabilidadBase = 40;
            prestigioBase = 4;
            break;

        case VarianteEscudo::EscudoRedondoPequeno:
            objeto.nombre = "Escudo Redondo Pequeño";
            defensaBase = 25;
            bloqueoBase = 50;
            coberturaBase = 20;
            pesoBase = 25;
            estabilidadBase = 45;
            prestigioBase = 5;
            break;

        case VarianteEscudo::EscudoRedondo:
            objeto.nombre = "Escudo Redondo";
            defensaBase = 35;
            bloqueoBase = 55;
            coberturaBase = 35;
            pesoBase = 35;
            estabilidadBase = 55;
            prestigioBase = 6;
            break;

        case VarianteEscudo::EscudoRedondoGrande:
            objeto.nombre = "Escudo Redondo Grande";
            defensaBase = 45;
            bloqueoBase = 60;
            coberturaBase = 50;
            pesoBase = 50;
            estabilidadBase = 65;
            prestigioBase = 9;
            break;

        case VarianteEscudo::EscudoOvalado:
            objeto.nombre = "Escudo Ovalado";
            defensaBase = 40;
            bloqueoBase = 60;
            coberturaBase = 45;
            pesoBase = 45;
            estabilidadBase = 60;
            prestigioBase = 8;
            break;

        case VarianteEscudo::EscudoOvaladoGrande:
            objeto.nombre = "Escudo Ovalado Grande";
            defensaBase = 50;
            bloqueoBase = 65;
            coberturaBase = 60;
            pesoBase = 55;
            estabilidadBase = 70;
            prestigioBase = 10;
            break;

        case VarianteEscudo::EscudoDeCometa:
            objeto.nombre = "Escudo de Cometa";
            defensaBase = 45;
            bloqueoBase = 60;
            coberturaBase = 55;
            pesoBase = 50;
            estabilidadBase = 65;
            prestigioBase = 10;
            break;

        case VarianteEscudo::EscudoDeCometaGrande:
            objeto.nombre = "Escudo de Cometa Grande";
            defensaBase = 55;
            bloqueoBase = 65;
            coberturaBase = 70;
            pesoBase = 65;
            estabilidadBase = 75;
            prestigioBase = 12;
            break;

        case VarianteEscudo::EscudoAlargado:
            objeto.nombre = "Escudo Alargado";
            defensaBase = 45;
            bloqueoBase = 65;
            coberturaBase = 60;
            pesoBase = 55;
            estabilidadBase = 65;
            prestigioBase = 9;
            break;

        case VarianteEscudo::EscudoAlargadoGrande:
            objeto.nombre = "Escudo Alargado Grande";
            defensaBase = 55;
            bloqueoBase = 70;
            coberturaBase = 75;
            pesoBase = 70;
            estabilidadBase = 75;
            prestigioBase = 12;
            break;

        case VarianteEscudo::EscudoRectangular:
            objeto.nombre = "Escudo Rectangular";
            defensaBase = 50;
            bloqueoBase = 65;
            coberturaBase = 65;
            pesoBase = 60;
            estabilidadBase = 70;
            prestigioBase = 10;
            break;

        case VarianteEscudo::EscudoRectangularGrande:
            objeto.nombre = "Escudo Rectangular Grande";
            defensaBase = 60;
            bloqueoBase = 70;
            coberturaBase = 80;
            pesoBase = 75;
            estabilidadBase = 80;
            prestigioBase = 13;
            break;

        case VarianteEscudo::EscudoDeTorre:
            objeto.nombre = "Escudo de Torre";
            defensaBase = 65;
            bloqueoBase = 75;
            coberturaBase = 85;
            pesoBase = 90;
            estabilidadBase = 85;
            prestigioBase = 15;
            break;

        case VarianteEscudo::EscudoDeTorreGrande:
            objeto.nombre = "Escudo de Torre Grande";
            defensaBase = 75;
            bloqueoBase = 80;
            coberturaBase = 95;
            pesoBase = 110;
            estabilidadBase = 90;
            prestigioBase = 18;
            break;

        case VarianteEscudo::EscudoHeraldico:
            objeto.nombre = "Escudo Heráldico";
            defensaBase = 50;
            bloqueoBase = 65;
            coberturaBase = 65;
            pesoBase = 55;
            estabilidadBase = 70;
            prestigioBase = 20;
            objeto.carisma = 5;
            break;

        case VarianteEscudo::EscudoDeGuerra:
            objeto.nombre = "Escudo de Guerra";
            defensaBase = 65;
            bloqueoBase = 75;
            coberturaBase = 75;
            pesoBase = 70;
            estabilidadBase = 85;
            prestigioBase = 20;
            objeto.resistencia = 5;
            break;

        case VarianteEscudo::EscudoCeremonial:
            objeto.nombre = "Escudo Ceremonial";
            defensaBase = 25;
            bloqueoBase = 35;
            coberturaBase = 30;
            pesoBase = 30;
            estabilidadBase = 40;
            prestigioBase = 30;
            objeto.carisma = 10;
            break;

        case VarianteEscudo::Ninguno:
        default:
            objeto.nombre = "Escudo";
            break;
    }

    objeto.defensa = static_cast<int>(
        defensaBase *
        (propiedades.dureza / 100.0) *
        multiplicadorCalidad
    );

    objeto.defensaCorte = static_cast<int>(
        objeto.defensa *
        0.90
    );

    objeto.defensaPerforacion = static_cast<int>(
        objeto.defensa *
        0.75
    );

    objeto.defensaGolpe = static_cast<int>(
        objeto.defensa *
        1.10
    );

    objeto.defensaProyectiles = static_cast<int>(
        coberturaBase *
        multiplicadorCalidad
    );

    objeto.bloqueo = static_cast<int>(
        bloqueoBase *
        multiplicadorCalidad
    );

    objeto.cobertura = static_cast<int>(
        coberturaBase *
        multiplicadorCalidad
    );

    objeto.estabilidad = static_cast<int>(
        estabilidadBase *
        (propiedades.resistencia / 100.0) *
        multiplicadorCalidad
    );

    objeto.peso = std::max(
        1,
        static_cast<int>(
            pesoBase *
            (propiedades.peso / 60.0)
        )
    );

    objeto.durabilidad = std::max(
        10,
        static_cast<int>(
            propiedades.resistencia *
            2.5 *
            multiplicadorCalidad
        )
    );

    objeto.valor = std::max(
        1,
        static_cast<int>(
            propiedades.valor *
            (1.0 + objeto.calidad / 100.0) +
            objeto.defensa * 2
        )
    );

    objeto.prestigio =
        calcularPrestigio(
            prestigioBase,
            objeto.calidad,
            propiedades.valor
        );

    return objeto;
}

// ============================================================
// ARMADURAS
// ============================================================

Objeto crearArmadura(
    int id,
    VarianteArmadura variante,
    const std::string& material,
    int habilidadArtesano,
    int artesanoID,
    const std::string& artesanoNombre)
{
    Recursos recursos;

    Objeto objeto = crearObjetoBase(
        id,
        material,
        habilidadArtesano,
        artesanoID,
        artesanoNombre
    );

    objeto.tipo = TipoObjeto::Armadura;
    objeto.varianteArmadura = variante;

    PropiedadesMaterial propiedades =
        recursos.obtenerPropiedades(material);

    double multiplicadorCalidad =
        obtenerMultiplicadorCalidad(objeto.calidad);

    int defensaBase = 25;
    int pesoBase = 40;
    int prestigioBase = 5;

    switch (variante)
    {
        case VarianteArmadura::ArmaduraDeCuero:
            objeto.nombre = "Armadura de Cuero";
            defensaBase = 25;
            pesoBase = 30;
            prestigioBase = 5;
            objeto.sigilo += 5;
            break;

        case VarianteArmadura::ArmaduraDeCueroReforzado:
            objeto.nombre = "Armadura de Cuero Reforzado";
            defensaBase = 35;
            pesoBase = 40;
            prestigioBase = 7;
            break;

        case VarianteArmadura::Gambeson:
            objeto.nombre = "Gambesón";
            defensaBase = 30;
            pesoBase = 35;
            prestigioBase = 6;
            objeto.resistenciaFrio = 20;
            break;

        case VarianteArmadura::CotaDeMalla:
            objeto.nombre = "Cota de Malla";
            defensaBase = 50;
            pesoBase = 55;
            prestigioBase = 12;
            break;

        case VarianteArmadura::CotaDeMallaPesada:
            objeto.nombre = "Cota de Malla Pesada";
            defensaBase = 60;
            pesoBase = 70;
            prestigioBase = 15;
            break;

        case VarianteArmadura::ArmaduraDeEscamas:
            objeto.nombre = "Armadura de Escamas";
            defensaBase = 65;
            pesoBase = 65;
            prestigioBase = 16;
            break;

        case VarianteArmadura::ArmaduraDePlacas:
            objeto.nombre = "Armadura de Placas";
            defensaBase = 80;
            pesoBase = 80;
            prestigioBase = 22;
            break;

        case VarianteArmadura::ArmaduraDePlacasPesada:
            objeto.nombre = "Armadura de Placas Pesada";
            defensaBase = 90;
            pesoBase = 100;
            prestigioBase = 27;
            break;

        case VarianteArmadura::ArmaduraDeGuerra:
            objeto.nombre = "Armadura de Guerra";
            defensaBase = 100;
            pesoBase = 115;
            prestigioBase = 35;
            objeto.resistencia = 10;
            break;

        case VarianteArmadura::Ninguna:
        default:
            objeto.nombre = "Armadura";
            break;
    }

    objeto.defensa = static_cast<int>(
        defensaBase *
        (propiedades.dureza / 100.0) *
        multiplicadorCalidad
    );

    objeto.defensaCorte = static_cast<int>(
        objeto.defensa *
        1.00
    );

    objeto.defensaPerforacion = static_cast<int>(
        objeto.defensa *
        0.85
    );

    objeto.defensaGolpe = static_cast<int>(
        objeto.defensa *
        0.90
    );

    objeto.defensaProyectiles = static_cast<int>(
        objeto.defensa *
        0.80
    );

    objeto.peso = std::max(
        1,
        static_cast<int>(
            pesoBase *
            (propiedades.peso / 60.0)
        )
    );

    objeto.resistencia +=
        static_cast<int>(
            propiedades.resistencia / 10
        );

    objeto.resistenciaFrio += 10;
    objeto.resistenciaAgua += 5;

    objeto.velocidad = -objeto.peso / 5;

    objeto.durabilidad = std::max(
        10,
        static_cast<int>(
            propiedades.resistencia *
            3.0 *
            multiplicadorCalidad
        )
    );

    objeto.valor = std::max(
        1,
        static_cast<int>(
            propiedades.valor *
            (1.0 + objeto.calidad / 100.0) +
            objeto.defensa * 3
        )
    );

    objeto.prestigio =
        calcularPrestigio(
            prestigioBase,
            objeto.calidad,
            propiedades.valor
        );

    return objeto;
}

// ============================================================
// ROPA
// ============================================================

Objeto crearRopa(
    int id,
    VarianteRopa variante,
    const std::string& material,
    int habilidadArtesano,
    int artesanoID,
    const std::string& artesanoNombre)
{
    Recursos recursos;

    Objeto objeto = crearObjetoBase(
        id,
        material,
        habilidadArtesano,
        artesanoID,
        artesanoNombre
    );

    objeto.varianteRopa = variante;
    objeto.tipo = TipoObjeto::Camisa;

    PropiedadesMaterial propiedades =
        recursos.obtenerPropiedades(material);

    double multiplicadorCalidad =
        obtenerMultiplicadorCalidad(objeto.calidad);

    int defensaBase = 5;
    int pesoBase = 10;
    int prestigioBase = 1;

    // ========================================================
    // CAMISAS
    // ========================================================

    switch (variante)
    {
        case VarianteRopa::CamisaSimple:
            objeto.nombre = "Camisa Simple";
            objeto.tipo = TipoObjeto::Camisa;
            defensaBase = 5;
            pesoBase = 8;
            break;

        case VarianteRopa::CamisaDeTrabajo:
            objeto.nombre = "Camisa de Trabajo";
            objeto.tipo = TipoObjeto::Camisa;
            defensaBase = 8;
            objeto.agricultura = 2;
            objeto.resistencia = 2;
            break;

        case VarianteRopa::CamisaElegante:
            objeto.nombre = "Camisa Elegante";
            objeto.tipo = TipoObjeto::Camisa;
            defensaBase = 5;
            objeto.carisma = 5;
            prestigioBase = 8;
            break;

        case VarianteRopa::CamisaMilitar:
            objeto.nombre = "Camisa Militar";
            objeto.tipo = TipoObjeto::Camisa;
            defensaBase = 12;
            objeto.resistencia = 3;
            objeto.exploracion = 2;
            prestigioBase = 6;
            break;

        // ====================================================
        // CAMISON
        // ====================================================

        case VarianteRopa::CamisonSimple:
            objeto.nombre = "Camison Simple";
            objeto.tipo = TipoObjeto::Camison;
            defensaBase = 3;
            pesoBase = 8;
            break;

        case VarianteRopa::CamisonDeInvierno:
            objeto.nombre = "Camison de Invierno";
            objeto.tipo = TipoObjeto::Camison;
            defensaBase = 6;
            pesoBase = 15;
            objeto.resistenciaFrio = 25;
            break;

        case VarianteRopa::CamisonMilitar:
            objeto.nombre = "Camison Militar";
            objeto.tipo = TipoObjeto::Camison;
            defensaBase = 10;
            objeto.resistenciaFrio = 10;
            objeto.resistencia = 2;
            prestigioBase = 5;
            break;

        // ====================================================
        // PANTALONES
        // ====================================================

        case VarianteRopa::PantalonesSimples:
            objeto.nombre = "Pantalones Simples";
            objeto.tipo = TipoObjeto::Pantalones;
            defensaBase = 5;
            pesoBase = 12;
            break;

        case VarianteRopa::PantalonesDeTrabajo:
            objeto.nombre = "Pantalones de Trabajo";
            objeto.tipo = TipoObjeto::Pantalones;
            defensaBase = 10;
            objeto.resistencia = 4;
            objeto.agricultura = 3;
            objeto.mineria = 2;
            break;

        case VarianteRopa::PantalonesDeCazador:
            objeto.nombre = "Pantalones de Cazador";
            objeto.tipo = TipoObjeto::Pantalones;
            defensaBase = 8;
            objeto.caza = 6;
            objeto.sigilo = 5;
            objeto.exploracion = 4;
            break;

        case VarianteRopa::PantalonesMilitares:
            objeto.nombre = "Pantalones Militares";
            objeto.tipo = TipoObjeto::Pantalones;
            defensaBase = 15;
            objeto.resistencia = 5;
            prestigioBase = 7;
            break;

        // ====================================================
        // CALZONES
        // ====================================================

        case VarianteRopa::CalzonesSimples:
            objeto.nombre = "Calzones Simples";
            objeto.tipo = TipoObjeto::Calzones;
            defensaBase = 2;
            pesoBase = 5;
            break;

        case VarianteRopa::CalzonesDeTrabajo:
            objeto.nombre = "Calzones de Trabajo";
            objeto.tipo = TipoObjeto::Calzones;
            defensaBase = 4;
            objeto.resistencia = 2;
            break;

        case VarianteRopa::CalzonesMilitares:
            objeto.nombre = "Calzones Militares";
            objeto.tipo = TipoObjeto::Calzones;
            defensaBase = 7;
            objeto.resistencia = 2;
            prestigioBase = 4;
            break;

        // ====================================================
        // TUNICAS
        // ====================================================

        case VarianteRopa::TunicaSimple:
            objeto.nombre = "Tunica Simple";
            objeto.tipo = TipoObjeto::Tunica;
            defensaBase = 6;
            pesoBase = 15;
            break;

        case VarianteRopa::TunicaReligiosa:
            objeto.nombre = "Tunica Religiosa";
            objeto.tipo = TipoObjeto::Tunica;
            defensaBase = 6;
            objeto.carisma = 5;
            objeto.medicina = 1;
            prestigioBase = 12;
            break;

        case VarianteRopa::TunicaNoble:
            objeto.nombre = "Tunica Noble";
            objeto.tipo = TipoObjeto::Tunica;
            defensaBase = 8;
            objeto.carisma = 12;
            objeto.inteligencia = 4;
            prestigioBase = 25;
            break;

        case VarianteRopa::TunicaMilitar:
            objeto.nombre = "Tunica Militar";
            objeto.tipo = TipoObjeto::Tunica;
            defensaBase = 12;
            objeto.resistencia = 4;
            objeto.experienciaMilitar; // No se modifica personaje aquí
            prestigioBase = 9;
            break;

        // ====================================================
        // CAPAS
        // ====================================================

        case VarianteRopa::CapaSimple:
            objeto.nombre = "Capa Simple";
            objeto.tipo = TipoObjeto::Capa;
            defensaBase = 5;
            pesoBase = 12;
            break;

        case VarianteRopa::CapaDeViaje:
            objeto.nombre = "Capa de Viaje";
            objeto.tipo = TipoObjeto::Capa;
            defensaBase = 7;
            objeto.exploracion = 6;
            objeto.resistenciaFrio = 12;
            objeto.resistenciaAgua = 10;
            break;

        case VarianteRopa::CapaNoble:
            objeto.nombre = "Capa Noble";
            objeto.tipo = TipoObjeto::Capa;
            defensaBase = 8;
            objeto.carisma = 10;
            objeto.prestigio; // Se calcula abajo
            prestigioBase = 30;
            break;

        case VarianteRopa::CapaMilitar:
            objeto.nombre = "Capa Militar";
            objeto.tipo = TipoObjeto::Capa;
            defensaBase = 10;
            objeto.resistenciaFrio = 15;
            objeto.exploracion = 3;
            prestigioBase = 10;
            break;

        // ====================================================
        // VESTIDOS
        // ====================================================

        case VarianteRopa::VestidoSimple:
            objeto.nombre = "Vestido Simple";
            objeto.tipo = TipoObjeto::Vestido;
            defensaBase = 4;
            pesoBase = 12;
            break;

        case VarianteRopa::VestidoElegante:
            objeto.nombre = "Vestido Elegante";
            objeto.tipo = TipoObjeto::Vestido;
            defensaBase = 5;
            objeto.carisma = 10;
            prestigioBase = 15;
            break;

        case VarianteRopa::VestidoNoble:
            objeto.nombre = "Vestido Noble";
            objeto.tipo = TipoObjeto::Vestido;
            defensaBase = 7;
            objeto.carisma = 18;
            objeto.inteligencia = 3;
            prestigioBase = 35;
            break;

        case VarianteRopa::VestidoMilitar:
            objeto.nombre = "Vestido Militar";
            objeto.tipo = TipoObjeto::Vestido;
            defensaBase = 10;
            objeto.resistencia = 4;
            prestigioBase = 10;
            break;

        // ====================================================
        // FALDAS
        // ====================================================

        case VarianteRopa::FaldaSimple:
            objeto.nombre = "Falda Simple";
            objeto.tipo = TipoObjeto::Falda;
            defensaBase = 4;
            pesoBase = 10;
            break;

        case VarianteRopa::FaldaDeTrabajo:
            objeto.nombre = "Falda de Trabajo";
            objeto.tipo = TipoObjeto::Falda;
            defensaBase = 7;
            objeto.agricultura = 3;
            objeto.resistencia = 3;
            break;

        case VarianteRopa::FaldaNoble:
            objeto.nombre = "Falda Noble";
            objeto.tipo = TipoObjeto::Falda;
            defensaBase = 6;
            objeto.carisma = 14;
            prestigioBase = 28;
            break;

        case VarianteRopa::FaldaMilitar:
            objeto.nombre = "Falda Militar";
            objeto.tipo = TipoObjeto::Falda;
            defensaBase = 10;
            objeto.resistencia = 4;
            prestigioBase = 9;
            break;

        // ====================================================
        // ABRIGOS
        // ====================================================

        case VarianteRopa::AbrigoSimple:
            objeto.nombre = "Abrigo Simple";
            objeto.tipo = TipoObjeto::Abrigo;
            defensaBase = 8;
            pesoBase = 20;
            objeto.resistenciaFrio = 15;
            break;

        case VarianteRopa::AbrigoDeInvierno:
            objeto.nombre = "Abrigo de Invierno";
            objeto.tipo = TipoObjeto::Abrigo;
            defensaBase = 12;
            pesoBase = 30;
            objeto.resistenciaFrio = 35;
            break;

        case VarianteRopa::AbrigoMilitar:
            objeto.nombre = "Abrigo Militar";
            objeto.tipo = TipoObjeto::Abrigo;
            defensaBase = 15;
            pesoBase = 30;
            objeto.resistenciaFrio = 25;
            objeto.resistencia = 4;
            prestigioBase = 12;
            break;

        // ====================================================
        // PIELES
        // ====================================================

        case VarianteRopa::AbrigoDePielDeLobo:
            objeto.nombre = "Abrigo de Piel de Lobo";
            objeto.tipo = TipoObjeto::AbrigoDePieles;
            defensaBase = 15;
            pesoBase = 30;
            objeto.resistenciaFrio = 45;
            objeto.percepcion = 4;
            objeto.caza = 4;
            prestigioBase = 12;
            break;

        case VarianteRopa::AbrigoDePielDeOso:
            objeto.nombre = "Abrigo de Piel de Oso";
            objeto.tipo = TipoObjeto::AbrigoDePieles;
            defensaBase = 25;
            pesoBase = 50;
            objeto.resistenciaFrio = 65;
            objeto.fuerza = 5;
            objeto.resistencia = 6;
            prestigioBase = 25;
            break;

        case VarianteRopa::AbrigoDePielDeCiervo:
            objeto.nombre = "Abrigo de Piel de Ciervo";
            objeto.tipo = TipoObjeto::AbrigoDePieles;
            defensaBase = 12;
            pesoBase = 25;
            objeto.resistenciaFrio = 40;
            objeto.percepcion = 3;
            objeto.caza = 5;
            prestigioBase = 10;
            break;

        case VarianteRopa::AbrigoDePielDeZorro:
            objeto.nombre = "Abrigo de Piel de Zorro";
            objeto.tipo = TipoObjeto::AbrigoDePieles;
            defensaBase = 10;
            pesoBase = 20;
            objeto.resistenciaFrio = 35;
            objeto.sigilo = 6;
            objeto.caza = 4;
            prestigioBase = 13;
            break;

        case VarianteRopa::AbrigoDePielDeOveja:
            objeto.nombre = "Abrigo de Piel de Oveja";
            objeto.tipo = TipoObjeto::AbrigoDePieles;
            defensaBase = 12;
            pesoBase = 25;
            objeto.resistenciaFrio = 50;
            objeto.resistencia = 3;
            break;

        case VarianteRopa::AbrigoDePielDeAlce:
            objeto.nombre = "Abrigo de Piel de Alce";
            objeto.tipo = TipoObjeto::AbrigoDePieles;
            defensaBase = 20;
            pesoBase = 40;
            objeto.resistenciaFrio = 60;
            objeto.resistencia = 5;
            objeto.caza = 5;
            prestigioBase = 20;
            break;

        case VarianteRopa::AbrigoDePielMilitar:
            objeto.nombre = "Abrigo de Piel Militar";
            objeto.tipo = TipoObjeto::AbrigoDePieles;
            defensaBase = 22;
            pesoBase = 45;
            objeto.resistenciaFrio = 60;
            objeto.resistencia = 7;
            prestigioBase = 25;
            break;

        // ====================================================
        // GUANTES
        // ====================================================

        case VarianteRopa::GuantesSimples:
            objeto.nombre = "Guantes Simples";
            objeto.tipo = TipoObjeto::Guantes;
            defensaBase = 3;
            pesoBase = 5;
            break;

        case VarianteRopa::GuantesDeTrabajo:
            objeto.nombre = "Guantes de Trabajo";
            objeto.tipo = TipoObjeto::Guantes;
            defensaBase = 7;
            objeto.herreria = 2;
            objeto.carpinteria = 2;
            objeto.mineria = 2;
            objeto.resistencia = 2;
            break;

        case VarianteRopa::GuantesDeCuero:
            objeto.nombre = "Guantes de Cuero";
            objeto.tipo = TipoObjeto::Guantes;
            defensaBase = 8;
            objeto.herreria = 2;
            objeto.caza = 2;
            break;

        case VarianteRopa::GuantesDeInvierno:
            objeto.nombre = "Guantes de Invierno";
            objeto.tipo = TipoObjeto::Guantes;
            defensaBase = 6;
            objeto.resistenciaFrio = 30;
            break;

        case VarianteRopa::GuantesMilitares:
            objeto.nombre = "Guantes Militares";
            objeto.tipo = TipoObjeto::Guantes;
            defensaBase = 12;
            objeto.resistencia = 3;
            prestigioBase = 6;
            break;

        // ====================================================
        // BRAZALES
        // ====================================================

        case VarianteRopa::BrazalesDeCuero:
            objeto.nombre = "Brazales de Cuero";
            objeto.tipo = TipoObjeto::Brazales;
            defensaBase = 12;
            pesoBase = 10;
            objeto.caza = 2;
            break;

        case VarianteRopa::BrazalesReforzados:
            objeto.nombre = "Brazales Reforzados";
            objeto.tipo = TipoObjeto::Brazales;
            defensaBase = 20;
            pesoBase = 18;
            objeto.resistencia = 3;
            break;

        case VarianteRopa::BrazalesDeTrabajo:
            objeto.nombre = "Brazales de Trabajo";
            objeto.tipo = TipoObjeto::Brazales;
            defensaBase = 15;
            objeto.herreria = 3;
            objeto.carpinteria = 3;
            objeto.mineria = 3;
            break;

        case VarianteRopa::BrazalesMilitares:
            objeto.nombre = "Brazales Militares";
            objeto.tipo = TipoObjeto::Brazales;
            defensaBase = 25;
            objeto.resistencia = 5;
            prestigioBase = 8;
            break;

        // ====================================================
        // GREBAS
        // ====================================================

        case VarianteRopa::GrebasDeCuero:
            objeto.nombre = "Grebas de Cuero";
            objeto.tipo = TipoObjeto::Grebas;
            defensaBase = 12;
            pesoBase = 12;
            objeto.sigilo = 2;
            break;

        case VarianteRopa::GrebasReforzadas:
            objeto.nombre = "Grebas Reforzadas";
            objeto.tipo = TipoObjeto::Grebas;
            defensaBase = 20;
            pesoBase = 20;
            objeto.resistencia = 3;
            break;

        case VarianteRopa::GrebasMilitares:
            objeto.nombre = "Grebas Militares";
            objeto.tipo = TipoObjeto::Grebas;
            defensaBase = 28;
            pesoBase = 25;
            objeto.resistencia = 5;
            prestigioBase = 9;
            break;

        // ====================================================
        // ZAPATOS
        // ====================================================

        case VarianteRopa::ZapatosSimples:
            objeto.nombre = "Zapatos Simples";
            objeto.tipo = TipoObjeto::Zapatos;
            defensaBase = 3;
            pesoBase = 8;
            break;

        case VarianteRopa::ZapatosDeTrabajo:
            objeto.nombre = "Zapatos de Trabajo";
            objeto.tipo = TipoObjeto::Zapatos;
            defensaBase = 6;
            objeto.resistencia = 3;
            objeto.agricultura = 2;
            break;

        case VarianteRopa::ZapatosElegantes:
            objeto.nombre = "Zapatos Elegantes";
            objeto.tipo = TipoObjeto::Zapatos;
            defensaBase = 4;
            objeto.carisma = 5;
            prestigioBase = 8;
            break;

        case VarianteRopa::ZapatosMilitares:
            objeto.nombre = "Zapatos Militares";
            objeto.tipo = TipoObjeto::Zapatos;
            defensaBase = 10;
            objeto.resistencia = 4;
            prestigioBase = 6;
            break;

        // ====================================================
        // BOTAS
        // ====================================================

        case VarianteRopa::BotasSimples:
            objeto.nombre = "Botas Simples";
            objeto.tipo = TipoObjeto::Botas;
            defensaBase = 6;
            pesoBase = 12;
            break;

        case VarianteRopa::BotasDeTrabajo:
            objeto.nombre = "Botas de Trabajo";
            objeto.tipo = TipoObjeto::Botas;
            defensaBase = 10;
            objeto.resistencia = 5;
            objeto.mineria = 2;
            objeto.agricultura = 2;
            break;

        case VarianteRopa::BotasDeCazador:
            objeto.nombre = "Botas de Cazador";
            objeto.tipo = TipoObjeto::Botas;
            defensaBase = 8;
            objeto.caza = 6;
            objeto.sigilo = 5;
            objeto.exploracion = 5;
            break;

        case VarianteRopa::BotasDeInvierno:
            objeto.nombre = "Botas de Invierno";
            objeto.tipo = TipoObjeto::Botas;
            defensaBase = 10;
            objeto.resistenciaFrio = 30;
            break;

        case VarianteRopa::BotasMilitares:
            objeto.nombre = "Botas Militares";
            objeto.tipo = TipoObjeto::Botas;
            defensaBase = 15;
            objeto.resistencia = 6;
            objeto.exploracion = 2;
            prestigioBase = 8;
            break;

        // ====================================================
        // SOMBREROS
        // ====================================================

        case VarianteRopa::SombreroSimple:
            objeto.nombre = "Sombrero Simple";
            objeto.tipo = TipoObjeto::Sombrero;
            defensaBase = 3;
            pesoBase = 6;
            break;

        case VarianteRopa::SombreroDeCampesino:
            objeto.nombre = "Sombrero de Campesino";
            objeto.tipo = TipoObjeto::Sombrero;
            defensaBase = 4;
            objeto.agricultura = 5;
            objeto.resistenciaCalor = 10;
            break;

        case VarianteRopa::SombreroElegante:
            objeto.nombre = "Sombrero Elegante";
            objeto.tipo = TipoObjeto::Sombrero;
            defensaBase = 3;
            objeto.carisma = 7;
            prestigioBase = 10;
            break;

        case VarianteRopa::SombreroDeViaje:
            objeto.nombre = "Sombrero de Viaje";
            objeto.tipo = TipoObjeto::Sombrero;
            defensaBase = 4;
            objeto.exploracion = 4;
            objeto.resistenciaCalor = 12;
            break;

        case VarianteRopa::SombreroMilitar:
            objeto.nombre = "Sombrero Militar";
            objeto.tipo = TipoObjeto::Sombrero;
            defensaBase = 8;
            objeto.resistencia = 2;
            prestigioBase = 8;
            break;

        // ====================================================
        // GORROS
        // ====================================================

        case VarianteRopa::GorroSimple:
            objeto.nombre = "Gorro Simple";
            objeto.tipo = TipoObjeto::Gorro;
            defensaBase = 3;
            pesoBase = 6;
            break;

        case VarianteRopa::GorroDeInvierno:
            objeto.nombre = "Gorro de Invierno";
            objeto.tipo = TipoObjeto::Gorro;
            defensaBase = 5;
            objeto.resistenciaFrio = 30;
            break;

        case VarianteRopa::GorroDeTrabajo:
            objeto.nombre = "Gorro de Trabajo";
            objeto.tipo = TipoObjeto::Gorro;
            defensaBase = 6;
            objeto.resistencia = 2;
            break;

        case VarianteRopa::GorroMilitar:
            objeto.nombre = "Gorro Militar";
            objeto.tipo = TipoObjeto::Gorro;
            defensaBase = 8;
            objeto.resistencia = 2;
            prestigioBase = 7;
            break;

        // ====================================================
        // CAPUCHAS
        // ====================================================

        case VarianteRopa::CapuchaSimple:
            objeto.nombre = "Capucha Simple";
            objeto.tipo = TipoObjeto::Capucha;
            defensaBase = 4;
            pesoBase = 8;
            break;

        case VarianteRopa::CapuchaDeCazador:
            objeto.nombre = "Capucha de Cazador";
            objeto.tipo = TipoObjeto::Capucha;
            defensaBase = 5;
            objeto.caza = 6;
            objeto.sigilo = 7;
            objeto.percepcion = 4;
            break;

        case VarianteRopa::CapuchaDeViaje:
            objeto.nombre = "Capucha de Viaje";
            objeto.tipo = TipoObjeto::Capucha;
            defensaBase = 5;
            objeto.exploracion = 6;
            objeto.resistenciaFrio = 15;
            break;

        case VarianteRopa::CapuchaMilitar:
            objeto.nombre = "Capucha Militar";
            objeto.tipo = TipoObjeto::Capucha;
            defensaBase = 10;
            objeto.resistencia = 3;
            objeto.sigilo = 2;
            prestigioBase = 8;
            break;

        // ====================================================
        // DELANTALES
        // ====================================================

        case VarianteRopa::DelantalDeHerrero:
            objeto.nombre = "Delantal de Herrero";
            objeto.tipo = TipoObjeto::Delantal;
            defensaBase = 18;
            pesoBase = 20;
            objeto.herreria = 10;
            objeto.resistenciaCalor = 30;
            prestigioBase = 6;
            break;

        case VarianteRopa::DelantalDeCarpintero:
            objeto.nombre = "Delantal de Carpintero";
            objeto.tipo = TipoObjeto::Delantal;
            defensaBase = 15;
            objeto.carpinteria = 10;
            objeto.resistencia = 3;
            break;

        case VarianteRopa::DelantalDeCocinero:
            objeto.nombre = "Delantal de Cocinero";
            objeto.tipo = TipoObjeto::Delantal;
            defensaBase = 8;
            objeto.cocina = 10;
            objeto.resistenciaCalor = 25;
            break;

        case VarianteRopa::DelantalDeArtesano:
            objeto.nombre = "Delantal de Artesano";
            objeto.tipo = TipoObjeto::Delantal;
            defensaBase = 12;
            objeto.costura = 5;
            objeto.herreria = 4;
            objeto.carpinteria = 4;
            break;

        // ====================================================
        // PROFESIONES
        // ====================================================

        case VarianteRopa::RopaDeCampesino:
            objeto.nombre = "Ropa de Campesino";
            defensaBase = 8;
            objeto.agricultura = 10;
            objeto.resistencia = 5;
            objeto.resistenciaCalor = 10;
            break;

        case VarianteRopa::RopaDeGranjero:
            objeto.nombre = "Ropa de Granjero";
            defensaBase = 10;
            objeto.agricultura = 12;
            objeto.resistencia = 7;
            break;

        case VarianteRopa::RopaDeCriador:
            objeto.nombre = "Ropa de Criador";
            defensaBase = 9;
            objeto.agricultura = 7;
            objeto.percepcion = 6;
            objeto.resistencia = 5;
            break;

        case VarianteRopa::RopaDeLenador:
            objeto.nombre = "Ropa de Leñador";
            defensaBase = 15;
            objeto.fuerza = 5;
            objeto.resistencia = 10;
            objeto.carpinteria = 4;
            break;

        case VarianteRopa::RopaDeMinero:
            objeto.nombre = "Ropa de Minero";
            defensaBase = 18;
            objeto.mineria = 12;
            objeto.resistencia = 8;
            objeto.resistenciaEnfermedades = 3;
            break;

        case VarianteRopa::RopaDeCantero:
            objeto.nombre = "Ropa de Cantero";
            defensaBase = 16;
            objeto.canteria = 12;
            objeto.fuerza = 5;
            objeto.resistencia = 8;
            break;

        case VarianteRopa::RopaDeCazador:
            objeto.nombre = "Ropa de Cazador";
            defensaBase = 12;
            objeto.caza = 15;
            objeto.percepcion = 8;
            objeto.sigilo = 8;
            objeto.exploracion = 8;
            break;

        case VarianteRopa::RopaDePescador:
            objeto.nombre = "Ropa de Pescador";
            defensaBase = 10;
            objeto.pesca = 15;
            objeto.resistenciaAgua = 35;
            objeto.resistencia = 5;
            break;

        case VarianteRopa::RopaDeHerrero:
            objeto.nombre = "Ropa de Herrero";
            defensaBase = 18;
            objeto.herreria = 15;
            objeto.resistenciaCalor = 40;
            objeto.fuerza = 4;
            break;

        case VarianteRopa::RopaDeCarpintero:
            objeto.nombre = "Ropa de Carpintero";
            defensaBase = 14;
            objeto.carpinteria = 15;
            objeto.resistencia = 6;
            break;

        case VarianteRopa::RopaDeAlbanil:
            objeto.nombre = "Ropa de Albañil";
            defensaBase = 18;
            objeto.canteria = 7;
            objeto.resistencia = 12;
            objeto.fuerza = 4;
            break;

        case VarianteRopa::RopaDeArtesano:
            objeto.nombre = "Ropa de Artesano";
            defensaBase = 10;
            objeto.costura = 8;
            objeto.herreria = 5;
            objeto.carpinteria = 5;
            break;

        case VarianteRopa::RopaDeAlfarero:
            objeto.nombre = "Ropa de Alfarero";
            defensaBase = 10;
            objeto.canteria = 3;
            objeto.costura = 5;
            objeto.resistenciaCalor = 15;
            break;

        case VarianteRopa::RopaDeSastre:
            objeto.nombre = "Ropa de Sastre";
            defensaBase = 8;
            objeto.costura = 18;
            objeto.carisma = 4;
            break;

        case VarianteRopa::RopaDeCurtidor:
            objeto.nombre = "Ropa de Curtidor";
            defensaBase = 15;
            objeto.resistenciaEnfermedades = 5;
            objeto.costura = 8;
            break;

        case VarianteRopa::RopaDeComerciante:
            objeto.nombre = "Ropa de Comerciante";
            defensaBase = 7;
            objeto.comercio = 15;
            objeto.carisma = 8;
            prestigioBase = 8;
            break;

        case VarianteRopa::RopaDeMercader:
            objeto.nombre = "Ropa de Mercader";
            defensaBase = 8;
            objeto.comercio = 20;
            objeto.carisma = 12;
            prestigioBase = 15;
            break;

        case VarianteRopa::RopaDeCocinero:
            objeto.nombre = "Ropa de Cocinero";
            defensaBase = 8;
            objeto.cocina = 15;
            objeto.resistenciaCalor = 35;
            break;

        case VarianteRopa::RopaDeMedico:
            objeto.nombre = "Ropa de Medico";
            defensaBase = 6;
            objeto.medicina = 18;
            objeto.inteligencia = 5;
            objeto.resistenciaEnfermedades = 10;
            prestigioBase = 12;
            break;

        case VarianteRopa::RopaDeEscriba:
            objeto.nombre = "Ropa de Escriba";
            defensaBase = 5;
            objeto.inteligencia = 8;
            objeto.costura = 4;
            prestigioBase = 10;
            break;

        case VarianteRopa::RopaDeSacerdote:
            objeto.nombre = "Ropa de Sacerdote";
            defensaBase = 6;
            objeto.carisma = 12;
            objeto.inteligencia = 5;
            prestigioBase = 20;
            break;

        // ====================================================
        // MILITARES
        // ====================================================

        case VarianteRopa::RopaDeSoldado:
            objeto.nombre = "Ropa de Soldado";
            defensaBase = 14;
            objeto.resistencia = 8;
            objeto.fuerza = 2;
            prestigioBase = 7;
            break;

        case VarianteRopa::RopaDeArquero:
            objeto.nombre = "Ropa de Arquero";
            defensaBase = 10;
            objeto.percepcion = 10;
            objeto.precision = 5;
            objeto.exploracion = 5;
            prestigioBase = 8;
            break;

        case VarianteRopa::RopaDeLancero:
            objeto.nombre = "Ropa de Lancero";
            defensaBase = 14;
            objeto.resistencia = 7;
            objeto.fuerza = 4;
            prestigioBase = 8;
            break;

        case VarianteRopa::RopaDeCaballero:
            objeto.nombre = "Ropa de Caballero";
            defensaBase = 20;
            objeto.fuerza = 5;
            objeto.resistencia = 8;
            objeto.carisma = 8;
            prestigioBase = 25;
            break;

        case VarianteRopa::RopaDeGuardia:
            objeto.nombre = "Ropa de Guardia";
            defensaBase = 18;
            objeto.percepcion = 7;
            objeto.resistencia = 8;
            prestigioBase = 15;
            break;

        case VarianteRopa::RopaDeExplorador:
            objeto.nombre = "Ropa de Explorador";
            defensaBase = 10;
            objeto.percepcion = 12;
            objeto.sigilo = 10;
            objeto.exploracion = 18;
            objeto.caza = 5;
            break;

        case VarianteRopa::RopaDeIngeniero:
            objeto.nombre = "Ropa de Ingeniero";
            defensaBase = 12;
            objeto.inteligencia = 8;
            objeto.canteria = 5;
            objeto.carpinteria = 5;
            objeto.exploracion = 4;
            prestigioBase = 15;
            break;

        case VarianteRopa::Ninguna:
        default:
            objeto.nombre = "Ropa";
            break;
    }

    // ========================================================
    // EFECTOS DEL MATERIAL
    // ========================================================

    objeto.defensa = static_cast<int>(
        defensaBase *
        (propiedades.resistencia / 100.0) *
        multiplicadorCalidad
    );

    objeto.defensaCorte = static_cast<int>(
        objeto.defensa *
        0.80
    );

    objeto.defensaPerforacion = static_cast<int>(
        objeto.defensa *
        0.50
    );

    objeto.defensaGolpe = static_cast<int>(
        objeto.defensa *
        0.70
    );

    objeto.defensaProyectiles = static_cast<int>(
        objeto.defensa *
        0.60
    );

    objeto.peso = std::max(
        1,
        static_cast<int>(
            pesoBase *
            (propiedades.peso / 60.0)
        )
    );

    objeto.durabilidad = std::max(
        5,
        static_cast<int>(
            propiedades.resistencia *
            1.5 *
            multiplicadorCalidad
        )
    );

    objeto.valor = std::max(
        1,
        static_cast<int>(
            propiedades.valor *
            (1.0 + objeto.calidad / 100.0) +
            objeto.defensa
        )
    );

    objeto.prestigio =
        calcularPrestigio(
            prestigioBase,
            objeto.calidad,
            propiedades.valor
        );

    return objeto;
}

// ============================================================
// JOYERIA
// ============================================================

Objeto crearJoya(
    int id,
    VarianteJoya variante,
    const std::string& material,
    int habilidadArtesano,
    int artesanoID,
    const std::string& artesanoNombre)
{
    Recursos recursos;

    Objeto objeto = crearObjetoBase(
        id,
        material,
        habilidadArtesano,
        artesanoID,
        artesanoNombre
    );

    objeto.varianteJoya = variante;

    PropiedadesMaterial propiedades =
        recursos.obtenerPropiedades(material);

    double multiplicadorCalidad =
        obtenerMultiplicadorCalidad(objeto.calidad);

    int defensaBase = 1;
    int pesoBase = 2;
    int prestigioBase = 2;

    switch (variante)
    {
        // ====================================================
        // ANILLOS
        // ====================================================

        case VarianteJoya::AnilloDeHierro:
            objeto.nombre = "Anillo de Hierro";
            objeto.tipo = TipoObjeto::Anillo;
            defensaBase = 1;
            pesoBase = 2;
            prestigioBase = 2;
            objeto.resistencia = 1;
            break;

        case VarianteJoya::AnilloDeCobre:
            objeto.nombre = "Anillo de Cobre";
            objeto.tipo = TipoObjeto::Anillo;
            defensaBase = 1;
            pesoBase = 2;
            prestigioBase = 4;
            objeto.resistenciaEnfermedades = 1;
            break;

        case VarianteJoya::AnilloDeBronce:
            objeto.nombre = "Anillo de Bronce";
            objeto.tipo = TipoObjeto::Anillo;
            defensaBase = 2;
            pesoBase = 2;
            prestigioBase = 6;
            objeto.resistencia = 2;
            break;

        case VarianteJoya::AnilloDePlata:
            objeto.nombre = "Anillo de Plata";
            objeto.tipo = TipoObjeto::Anillo;
            defensaBase = 2;
            pesoBase = 2;
            prestigioBase = 12;
            objeto.carisma = 5;
            objeto.resistenciaEnfermedades = 3;
            break;

        case VarianteJoya::AnilloDeOro:
            objeto.nombre = "Anillo de Oro";
            objeto.tipo = TipoObjeto::Anillo;
            defensaBase = 2;
            pesoBase = 3;
            prestigioBase = 18;
            objeto.carisma = 8;
            break;

        case VarianteJoya::AnilloDeFamilia:
            objeto.nombre = "Anillo de Familia";
            objeto.tipo = TipoObjeto::Anillo;
            defensaBase = 3;
            pesoBase = 3;
            prestigioBase = 30;
            objeto.carisma = 10;
            objeto.inteligencia = 3;
            break;

        case VarianteJoya::AnilloDeNobleza:
            objeto.nombre = "Anillo de Nobleza";
            objeto.tipo = TipoObjeto::Anillo;
            defensaBase = 3;
            pesoBase = 3;
            prestigioBase = 45;
            objeto.carisma = 15;
            break;

        // ====================================================
        // COLLARES
        // ====================================================

        case VarianteJoya::CollarSimple:
            objeto.nombre = "Collar Simple";
            objeto.tipo = TipoObjeto::Collar;
            defensaBase = 1;
            pesoBase = 3;
            prestigioBase = 2;
            break;

        case VarianteJoya::CollarDeCuero:
            objeto.nombre = "Collar de Cuero";
            objeto.tipo = TipoObjeto::Collar;
            defensaBase = 2;
            pesoBase = 4;
            prestigioBase = 3;
            objeto.resistencia = 2;
            break;

        case VarianteJoya::CollarDePlata:
            objeto.nombre = "Collar de Plata";
            objeto.tipo = TipoObjeto::Collar;
            defensaBase = 2;
            pesoBase = 5;
            prestigioBase = 15;
            objeto.carisma = 7;
            break;

        case VarianteJoya::CollarDeOro:
            objeto.nombre = "Collar de Oro";
            objeto.tipo = TipoObjeto::Collar;
            defensaBase = 3;
            pesoBase = 6;
            prestigioBase = 25;
            objeto.carisma = 12;
            break;

        case VarianteJoya::CollarDePerlas:
            objeto.nombre = "Collar de Perlas";
            objeto.tipo = TipoObjeto::Collar;
            defensaBase = 2;
            pesoBase = 5;
            prestigioBase = 30;
            objeto.carisma = 18;
            break;

        case VarianteJoya::CollarDeFamilia:
            objeto.nombre = "Collar de Familia";
            objeto.tipo = TipoObjeto::Collar;
            defensaBase = 3;
            pesoBase = 5;
            prestigioBase = 40;
            objeto.carisma = 15;
            objeto.inteligencia = 4;
            break;

        // ====================================================
        // AMULETOS
        // ====================================================

        case VarianteJoya::AmuletoSimple:
            objeto.nombre = "Amuleto Simple";
            objeto.tipo = TipoObjeto::Amuleto;
            defensaBase = 2;
            pesoBase = 3;
            prestigioBase = 4;
            break;

        case VarianteJoya::AmuletoReligioso:
            objeto.nombre = "Amuleto Religioso";
            objeto.tipo = TipoObjeto::Amuleto;
            defensaBase = 3;
            pesoBase = 3;
            prestigioBase = 15;
            objeto.carisma = 5;
            objeto.resistenciaEnfermedades = 5;
            break;

        case VarianteJoya::AmuletoDeGuerra:
            objeto.nombre = "Amuleto de Guerra";
            objeto.tipo = TipoObjeto::Amuleto;
            defensaBase = 5;
            pesoBase = 4;
            prestigioBase = 20;
            objeto.fuerza = 5;
            objeto.resistencia = 5;
            break;

        case VarianteJoya::AmuletoDeFamilia:
            objeto.nombre = "Amuleto de Familia";
            objeto.tipo = TipoObjeto::Amuleto;
            defensaBase = 3;
            pesoBase = 3;
            prestigioBase = 35;
            objeto.carisma = 10;
            objeto.resistenciaEnfermedades = 3;
            break;

        case VarianteJoya::Ninguna:
        default:
            objeto.nombre = "Joya";
            objeto.tipo = TipoObjeto::Anillo;
            break;
    }

    // ========================================================
    // JOYERIA: LOS METALES PRECIOSOS AUMENTAN VALOR/PRESTIGIO
    // ========================================================

    objeto.defensa = static_cast<int>(
        defensaBase *
        multiplicadorCalidad
    );

    objeto.durabilidad = std::max(
        5,
        static_cast<int>(
            propiedades.resistencia *
            multiplicadorCalidad
        )
    );

    objeto.peso = std::max(
        1,
        static_cast<int>(
            pesoBase *
            (propiedades.peso / 80.0)
        )
    );

    objeto.valor = std::max(
        1,
        static_cast<int>(
            propiedades.valor *
            2.0 *
            multiplicadorCalidad
        )
    );

    objeto.prestigio =
        calcularPrestigio(
            prestigioBase,
            objeto.calidad,
            propiedades.valor
        );

    return objeto;
}

// ============================================================
// NOMBRE DE VARIANTE DE ARMA
// ============================================================

std::string obtenerNombreVariante(VarianteArma variante)
{
    switch (variante)
    {
        case VarianteArma::EspadaCorta:
            return "Espada Corta";

        case VarianteArma::EspadaLarga:
            return "Espada Larga";

        case VarianteArma::EspadaBastarda:
            return "Espada Bastarda";

        case VarianteArma::Mandoble:
            return "Mandoble";

        case VarianteArma::Estoque:
            return "Estoque";

        case VarianteArma::Sable:
            return "Sable";

        case VarianteArma::LanzaSimple:
            return "Lanza Simple";

        case VarianteArma::Pica:
            return "Pica";

        case VarianteArma::Jabalina:
            return "Jabalina";

        case VarianteArma::Alabarda:
            return "Alabarda";

        case VarianteArma::MazaLigera:
            return "Maza Ligera";

        case VarianteArma::MazaPesada:
            return "Maza Pesada";

        case VarianteArma::MazaConPuas:
            return "Maza con Púas";

        case VarianteArma::Mayal:
            return "Mayal";

        case VarianteArma::HachaDeMano:
            return "Hacha de Mano";

        case VarianteArma::HachaDeBatalla:
            return "Hacha de Batalla";

        case VarianteArma::HachaDanesa:
            return "Hacha Danesa";

        case VarianteArma::HachaDeDosManos:
            return "Hacha de Dos Manos";

        case VarianteArma::ArcoCorto:
            return "Arco Corto";

        case VarianteArma::ArcoLargo:
            return "Arco Largo";

        case VarianteArma::ArcoRecurvo:
            return "Arco Recurvo";

        case VarianteArma::BallestaLigera:
            return "Ballesta Ligera";

        case VarianteArma::BallestaPesada:
            return "Ballesta Pesada";

        case VarianteArma::BallestaDeGuerra:
            return "Ballesta de Guerra";

        case VarianteArma::Daga:
            return "Daga";

        case VarianteArma::Estilete:
            return "Estilete";

        case VarianteArma::MartilloDeGuerra:
            return "Martillo de Guerra";

        case VarianteArma::MartilloPesado:
            return "Martillo Pesado";

        case VarianteArma::Ninguna:
        default:
            return "Ninguna";
    }
}

// ============================================================
// NOMBRE DE ESCUDO
// ============================================================

std::string obtenerNombreVarianteEscudo(VarianteEscudo variante)
{
    switch (variante)
    {
        case VarianteEscudo::Broquel:
            return "Broquel";

        case VarianteEscudo::EscudoRedondoPequeno:
            return "Escudo Redondo Pequeño";

        case VarianteEscudo::EscudoRedondo:
            return "Escudo Redondo";

        case VarianteEscudo::EscudoRedondoGrande:
            return "Escudo Redondo Grande";

        case VarianteEscudo::EscudoOvalado:
            return "Escudo Ovalado";

        case VarianteEscudo::EscudoOvaladoGrande:
            return "Escudo Ovalado Grande";

        case VarianteEscudo::EscudoDeCometa:
            return "Escudo de Cometa";

        case VarianteEscudo::EscudoDeCometaGrande:
            return "Escudo de Cometa Grande";

        case VarianteEscudo::EscudoAlargado:
            return "Escudo Alargado";

        case VarianteEscudo::EscudoAlargadoGrande:
            return "Escudo Alargado Grande";

        case VarianteEscudo::EscudoRectangular:
            return "Escudo Rectangular";

        case VarianteEscudo::EscudoRectangularGrande:
            return "Escudo Rectangular Grande";

        case VarianteEscudo::EscudoDeTorre:
            return "Escudo de Torre";

        case VarianteEscudo::EscudoDeTorreGrande:
            return "Escudo de Torre Grande";

        case VarianteEscudo::EscudoHeraldico:
            return "Escudo Heraldico";

        case VarianteEscudo::EscudoDeGuerra:
            return "Escudo de Guerra";

        case VarianteEscudo::EscudoCeremonial:
            return "Escudo Ceremonial";

        case VarianteEscudo::Ninguno:
        default:
            return "Ninguno";
    }
}

// ============================================================
// NOMBRE DE ARMADURA
// ============================================================

std::string obtenerNombreArmadura(VarianteArmadura variante)
{
    switch (variante)
    {
        case VarianteArmadura::ArmaduraDeCuero:
            return "Armadura de Cuero";

        case VarianteArmadura::ArmaduraDeCueroReforzado:
            return "Armadura de Cuero Reforzado";

        case VarianteArmadura::Gambeson:
            return "Gambeson";

        case VarianteArmadura::CotaDeMalla:
            return "Cota de Malla";

        case VarianteArmadura::CotaDeMallaPesada:
            return "Cota de Malla Pesada";

        case VarianteArmadura::ArmaduraDeEscamas:
            return "Armadura de Escamas";

        case VarianteArmadura::ArmaduraDePlacas:
            return "Armadura de Placas";

        case VarianteArmadura::ArmaduraDePlacasPesada:
            return "Armadura de Placas Pesada";

        case VarianteArmadura::ArmaduraDeGuerra:
            return "Armadura de Guerra";

        case VarianteArmadura::Ninguna:
        default:
            return "Ninguna";
    }
}

// ============================================================
// NOMBRE DE ROPA
// ============================================================

std::string obtenerNombreRopa(VarianteRopa variante)
{
    switch (variante)
    {
        case VarianteRopa::CamisaSimple:
            return "Camisa Simple";
        case VarianteRopa::CamisaDeTrabajo:
            return "Camisa de Trabajo";
        case VarianteRopa::CamisaElegante:
            return "Camisa Elegante";
        case VarianteRopa::CamisaMilitar:
            return "Camisa Militar";

        case VarianteRopa::CamisonSimple:
            return "Camison Simple";
        case VarianteRopa::CamisonDeInvierno:
            return "Camison de Invierno";
        case VarianteRopa::CamisonMilitar:
            return "Camison Militar";

        case VarianteRopa::PantalonesSimples:
            return "Pantalones Simples";
        case VarianteRopa::PantalonesDeTrabajo:
            return "Pantalones de Trabajo";
        case VarianteRopa::PantalonesDeCazador:
            return "Pantalones de Cazador";
        case VarianteRopa::PantalonesMilitares:
            return "Pantalones Militares";

        case VarianteRopa::CalzonesSimples:
            return "Calzones Simples";
        case VarianteRopa::CalzonesDeTrabajo:
            return "Calzones de Trabajo";
        case VarianteRopa::CalzonesMilitares:
            return "Calzones Militares";

        case VarianteRopa::TunicaSimple:
            return "Tunica Simple";
        case VarianteRopa::TunicaReligiosa:
            return "Tunica Religiosa";
        case VarianteRopa::TunicaNoble:
            return "Tunica Noble";
        case VarianteRopa::TunicaMilitar:
            return "Tunica Militar";

        case VarianteRopa::CapaSimple:
            return "Capa Simple";
        case VarianteRopa::CapaDeViaje:
            return "Capa de Viaje";
        case VarianteRopa::CapaNoble:
            return "Capa Noble";
        case VarianteRopa::CapaMilitar:
            return "Capa Militar";

        case VarianteRopa::VestidoSimple:
            return "Vestido Simple";
        case VarianteRopa::VestidoElegante:
            return "Vestido Elegante";
        case VarianteRopa::VestidoNoble:
            return "Vestido Noble";
        case VarianteRopa::VestidoMilitar:
            return "Vestido Militar";

        case VarianteRopa::FaldaSimple:
            return "Falda Simple";
        case VarianteRopa::FaldaDeTrabajo:
            return "Falda de Trabajo";
        case VarianteRopa::FaldaNoble:
            return "Falda Noble";
        case VarianteRopa::FaldaMilitar:
            return "Falda Militar";

        case VarianteRopa::AbrigoSimple:
            return "Abrigo Simple";
        case VarianteRopa::AbrigoDeInvierno:
            return "Abrigo de Invierno";
        case VarianteRopa::AbrigoMilitar:
            return "Abrigo Militar";

        case VarianteRopa::AbrigoDePielDeLobo:
            return "Abrigo de Piel de Lobo";
        case VarianteRopa::AbrigoDePielDeOso:
            return "Abrigo de Piel de Oso";
        case VarianteRopa::AbrigoDePielDeCiervo:
            return "Abrigo de Piel de Ciervo";
        case VarianteRopa::AbrigoDePielDeZorro:
            return "Abrigo de Piel de Zorro";
        case VarianteRopa::AbrigoDePielDeOveja:
            return "Abrigo de Piel de Oveja";
        case VarianteRopa::AbrigoDePielDeAlce:
            return "Abrigo de Piel de Alce";
        case VarianteRopa::AbrigoDePielMilitar:
            return "Abrigo de Piel Militar";

        case VarianteRopa::GuantesSimples:
            return "Guantes Simples";
        case VarianteRopa::GuantesDeTrabajo:
            return "Guantes de Trabajo";
        case VarianteRopa::GuantesDeCuero:
            return "Guantes de Cuero";
        case VarianteRopa::GuantesDeInvierno:
            return "Guantes de Invierno";
        case VarianteRopa::GuantesMilitares:
            return "Guantes Militares";

        case VarianteRopa::BrazalesDeCuero:
            return "Brazales de Cuero";
        case VarianteRopa::BrazalesReforzados:
            return "Brazales Reforzados";
        case VarianteRopa::BrazalesDeTrabajo:
            return "Brazales de Trabajo";
        case VarianteRopa::BrazalesMilitares:
            return "Brazales Militares";

        case VarianteRopa::GrebasDeCuero:
            return "Grebas de Cuero";
        case VarianteRopa::GrebasReforzadas:
            return "Grebas Reforzadas";
        case VarianteRopa::GrebasMilitares:
            return "Grebas Militares";

        case VarianteRopa::ZapatosSimples:
            return "Zapatos Simples";
        case VarianteRopa::ZapatosDeTrabajo:
            return "Zapatos de Trabajo";
        case VarianteRopa::ZapatosElegantes:
            return "Zapatos Elegantes";
        case VarianteRopa::ZapatosMilitares:
            return "Zapatos Militares";

        case VarianteRopa::BotasSimples:
            return "Botas Simples";
        case VarianteRopa::BotasDeTrabajo:
            return "Botas de Trabajo";
        case VarianteRopa::BotasDeCazador:
            return "Botas de Cazador";
        case VarianteRopa::BotasDeInvierno:
            return "Botas de Invierno";
        case VarianteRopa::BotasMilitares:
            return "Botas Militares";

        case VarianteRopa::SombreroSimple:
            return "Sombrero Simple";
        case VarianteRopa::SombreroDeCampesino:
            return "Sombrero de Campesino";
        case VarianteRopa::SombreroElegante:
            return "Sombrero Elegante";
        case VarianteRopa::SombreroDeViaje:
            return "Sombrero de Viaje";
        case VarianteRopa::SombreroMilitar:
            return "Sombrero Militar";

        case VarianteRopa::GorroSimple:
            return "Gorro Simple";
        case VarianteRopa::GorroDeInvierno:
            return "Gorro de Invierno";
        case VarianteRopa::GorroDeTrabajo:
            return "Gorro de Trabajo";
        case VarianteRopa::GorroMilitar:
            return "Gorro Militar";

        case VarianteRopa::CapuchaSimple:
            return "Capucha Simple";
        case VarianteRopa::CapuchaDeCazador:
            return "Capucha de Cazador";
        case VarianteRopa::CapuchaDeViaje:
            return "Capucha de Viaje";
        case VarianteRopa::CapuchaMilitar:
            return "Capucha Militar";

        case VarianteRopa::DelantalDeHerrero:
            return "Delantal de Herrero";
        case VarianteRopa::DelantalDeCarpintero:
            return "Delantal de Carpintero";
        case VarianteRopa::DelantalDeCocinero:
            return "Delantal de Cocinero";
        case VarianteRopa::DelantalDeArtesano:
            return "Delantal de Artesano";

        case VarianteRopa::RopaDeCampesino:
            return "Ropa de Campesino";
        case VarianteRopa::RopaDeGranjero:
            return "Ropa de Granjero";
        case VarianteRopa::RopaDeCriador:
            return "Ropa de Criador";

        case VarianteRopa::RopaDeLenador:
            return "Ropa de Lenador";
        case VarianteRopa::RopaDeMinero:
            return "Ropa de Minero";
        case VarianteRopa::RopaDeCantero:
            return "Ropa de Cantero";
        case VarianteRopa::RopaDeCazador:
            return "Ropa de Cazador";
        case VarianteRopa::RopaDePescador:
            return "Ropa de Pescador";

        case VarianteRopa::RopaDeHerrero:
            return "Ropa de Herrero";
        case VarianteRopa::RopaDeCarpintero:
            return "Ropa de Carpintero";
        case VarianteRopa::RopaDeAlbanil:
            return "Ropa de Albanil";
        case VarianteRopa::RopaDeArtesano:
            return "Ropa de Artesano";
        case VarianteRopa::RopaDeAlfarero:
            return "Ropa de Alfarero";
        case VarianteRopa::RopaDeSastre:
            return "Ropa de Sastre";
        case VarianteRopa::RopaDeCurtidor:
            return "Ropa de Curtidor";

        case VarianteRopa::RopaDeComerciante:
            return "Ropa de Comerciante";
        case VarianteRopa::RopaDeMercader:
            return "Ropa de Mercader";

        case VarianteRopa::RopaDeCocinero:
            return "Ropa de Cocinero";
        case VarianteRopa::RopaDeMedico:
            return "Ropa de Medico";
        case VarianteRopa::RopaDeEscriba:
            return "Ropa de Escriba";
        case VarianteRopa::RopaDeSacerdote:
            return "Ropa de Sacerdote";

        case VarianteRopa::RopaDeSoldado:
            return "Ropa de Soldado";
        case VarianteRopa::RopaDeArquero:
            return "Ropa de Arquero";
        case VarianteRopa::RopaDeLancero:
            return "Ropa de Lancero";
        case VarianteRopa::RopaDeCaballero:
            return "Ropa de Caballero";
        case VarianteRopa::RopaDeGuardia:
            return "Ropa de Guardia";
        case VarianteRopa::RopaDeExplorador:
            return "Ropa de Explorador";
        case VarianteRopa::RopaDeIngeniero:
            return "Ropa de Ingeniero";

        case VarianteRopa::Ninguna:
        default:
            return "Ninguna";
    }
}

// ============================================================
// NOMBRE DE JOYA
// ============================================================

std::string obtenerNombreJoya(VarianteJoya variante)
{
    switch (variante)
    {
        case VarianteJoya::AnilloDeHierro:
            return "Anillo de Hierro";

        case VarianteJoya::AnilloDeCobre:
            return "Anillo de Cobre";

        case VarianteJoya::AnilloDeBronce:
            return "Anillo de Bronce";

        case VarianteJoya::AnilloDePlata:
            return "Anillo de Plata";

        case VarianteJoya::AnilloDeOro:
            return "Anillo de Oro";

        case VarianteJoya::AnilloDeFamilia:
            return "Anillo de Familia";

        case VarianteJoya::AnilloDeNobleza:
            return "Anillo de Nobleza";

        case VarianteJoya::CollarSimple:
            return "Collar Simple";

        case VarianteJoya::CollarDeCuero:
            return "Collar de Cuero";

        case VarianteJoya::CollarDePlata:
            return "Collar de Plata";

        case VarianteJoya::CollarDeOro:
            return "Collar de Oro";

        case VarianteJoya::CollarDePerlas:
            return "Collar de Perlas";

        case VarianteJoya::CollarDeFamilia:
            return "Collar de Familia";

        case VarianteJoya::AmuletoSimple:
            return "Amuleto Simple";

        case VarianteJoya::AmuletoReligioso:
            return "Amuleto Religioso";

        case VarianteJoya::AmuletoDeGuerra:
            return "Amuleto de Guerra";

        case VarianteJoya::AmuletoDeFamilia:
            return "Amuleto de Familia";

        case VarianteJoya::Ninguna:
        default:
            return "Ninguna";
    }
}

// ============================================================
// MOSTRAR OBJETO
// ============================================================

void mostrarObjeto(const Objeto& objeto)
{
    std::cout << "\n========================================\n";
    std::cout << "              OBJETO\n";
    std::cout << "========================================\n";

    std::cout << "ID: " << objeto.id << "\n";
    std::cout << "Nombre: " << objeto.nombre << "\n";
    std::cout << "Material: " << objeto.material << "\n";
    std::cout << "Calidad: " << objeto.calidad << "/100\n";

    std::cout << "\n--- DEFENSA ---\n";

    if (objeto.defensa != 0)
        std::cout << "Defensa: " << objeto.defensa << "\n";

    if (objeto.defensaCorte != 0)
        std::cout << "Defensa contra corte: "
                  << objeto.defensaCorte << "\n";

    if (objeto.defensaPerforacion != 0)
        std::cout << "Defensa contra perforacion: "
                  << objeto.defensaPerforacion << "\n";

    if (objeto.defensaGolpe != 0)
        std::cout << "Defensa contra golpe: "
                  << objeto.defensaGolpe << "\n";

    if (objeto.defensaProyectiles != 0)
        std::cout << "Defensa contra proyectiles: "
                  << objeto.defensaProyectiles << "\n";

    std::cout << "\n--- ATRIBUTOS ---\n";

    if (objeto.fuerza != 0)
        std::cout << "Fuerza: " << objeto.fuerza << "\n";

    if (objeto.velocidad != 0)
        std::cout << "Velocidad: " << objeto.velocidad << "\n";

    if (objeto.resistencia != 0)
        std::cout << "Resistencia: " << objeto.resistencia << "\n";

    if (objeto.percepcion != 0)
        std::cout << "Percepcion: " << objeto.percepcion << "\n";

    if (objeto.inteligencia != 0)
        std::cout << "Inteligencia: " << objeto.inteligencia << "\n";

    if (objeto.carisma != 0)
        std::cout << "Carisma: " << objeto.carisma << "\n";

    if (objeto.sigilo != 0)
        std::cout << "Sigilo: " << objeto.sigilo << "\n";

    std::cout << "\n--- SUPERVIVENCIA ---\n";

    if (objeto.resistenciaFrio != 0)
        std::cout << "Resistencia al frio: "
                  << objeto.resistenciaFrio << "\n";

    if (objeto.resistenciaCalor != 0)
        std::cout << "Resistencia al calor: "
                  << objeto.resistenciaCalor << "\n";

    if (objeto.resistenciaAgua != 0)
        std::cout << "Resistencia al agua: "
                  << objeto.resistenciaAgua << "\n";

    if (objeto.resistenciaEnfermedades != 0)
        std::cout << "Resistencia a enfermedades: "
                  << objeto.resistenciaEnfermedades << "\n";

    std::cout << "\n--- COMBATE ---\n";

    if (objeto.daño != 0)
        std::cout << "Daño: " << objeto.daño << "\n";

    if (objeto.precision != 0)
        std::cout << "Precision: " << objeto.precision << "\n";

    if (objeto.alcance != 0)
        std::cout << "Alcance: " << objeto.alcance << "\n";

    if (objeto.penetracion != 0)
        std::cout << "Penetracion: " << objeto.penetracion << "\n";

    if (objeto.bloqueo != 0)
        std::cout << "Bloqueo: " << objeto.bloqueo << "\n";

    if (objeto.cobertura != 0)
        std::cout << "Cobertura: " << objeto.cobertura << "\n";

    if (objeto.estabilidad != 0)
        std::cout << "Estabilidad: " << objeto.estabilidad << "\n";

    std::cout << "\n--- PROFESIONES ---\n";

    if (objeto.agricultura != 0)
        std::cout << "Agricultura: +" << objeto.agricultura << "\n";

    if (objeto.herreria != 0)
        std::cout << "Herreria: +" << objeto.herreria << "\n";

    if (objeto.carpinteria != 0)
        std::cout << "Carpinteria: +" << objeto.carpinteria << "\n";

    if (objeto.mineria != 0)
        std::cout << "Mineria: +" << objeto.mineria << "\n";

    if (objeto.canteria != 0)
        std::cout << "Canteria: +" << objeto.canteria << "\n";

    if (objeto.caza != 0)
        std::cout << "Caza: +" << objeto.caza << "\n";

    if (objeto.pesca != 0)
        std::cout << "Pesca: +" << objeto.pesca << "\n";

    if (objeto.comercio != 0)
        std::cout << "Comercio: +" << objeto.comercio << "\n";

    if (objeto.medicina != 0)
        std::cout << "Medicina: +" << objeto.medicina << "\n";

    if (objeto.exploracion != 0)
        std::cout << "Exploracion: +" << objeto.exploracion << "\n";

    if (objeto.cocina != 0)
        std::cout << "Cocina: +" << objeto.cocina << "\n";

    if (objeto.costura != 0)
        std::cout << "Costura: +" << objeto.costura << "\n";

    std::cout << "\n--- FISICO ---\n";

    std::cout << "Durabilidad: "
              << objeto.durabilidad << "\n";

    std::cout << "Peso: "
              << objeto.peso << "\n";

    std::cout << "\n--- ECONOMIA ---\n";

    std::cout << "Valor: "
              << objeto.valor << "\n";

    std::cout << "Prestigio: "
              << objeto.prestigio << "\n";

    std::cout << "\n--- ARTESANO ---\n";

    std::cout << "ID del artesano: "
              << objeto.artesanoID << "\n";

    std::cout << "Artesano: "
              << objeto.artesanoNombre << "\n";

    std::cout << "Firma: "
              << objeto.firma << "\n";

    std::cout << "========================================\n";
}