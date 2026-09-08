#include "Objetos.h"
#include "Recursos.h"

#include <iostream>
#include <algorithm>
#include <random>

// ========================================
// GENERADOR DE NUMEROS ALEATORIOS
// ========================================

int variacionAleatoria(int minimo, int maximo)
{
    static std::random_device rd;
    static std::mt19937 generador(rd());

    std::uniform_int_distribution<int> distribucion(minimo, maximo);

    return distribucion(generador);
}


// ========================================
// CALCULAR CALIDAD DEL ARTESANO
// ========================================

int calcularCalidad(int habilidadArtesano)
{
    // La habilidad va de 0 a 100
    habilidadArtesano = std::clamp(habilidadArtesano, 0, 100);

    // Variación natural del trabajo
    int variacion = variacionAleatoria(-10, 10);

    int calidad = habilidadArtesano + variacion;

    // Limitar calidad entre 1 y 100
    calidad = std::clamp(calidad, 1, 100);

    return calidad;
}


// ========================================
// MODIFICADOR SEGUN CALIDAD
// ========================================

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


// ========================================
// CREAR ARMA
// ========================================

Objeto crearArma(
    int id,
    VarianteArma variante,
    const std::string& material,
    int habilidadArtesano,
    int artesanoID,
    const std::string& artesanoNombre
)
{
    Objeto objeto{};

    objeto.id = id;

    objeto.tipo = TipoObjeto::Espada;

    objeto.varianteArma = variante;
    objeto.varianteEscudo = VarianteEscudo::Ninguno;
    objeto.varianteArmadura = VarianteArmadura::Ninguna;

    objeto.material = material;

    objeto.artesanoID = artesanoID;
    objeto.artesanoNombre = artesanoNombre;
    objeto.firma = artesanoNombre;

    objeto.calidad = calcularCalidad(habilidadArtesano);

    // Estadísticas base
    int danoBase = 0;
    int defensaBase = 0;
    int durabilidadBase = 100;
    int pesoBase = 0;
    int velocidadBase = 0;
    int alcanceBase = 0;
    int penetracionBase = 0;

    // ========================================
    // ESPADAS
    // ========================================

    switch (variante)
    {
        case VarianteArma::EspadaCorta:
            objeto.tipo = TipoObjeto::Espada;
            objeto.nombre = "Espada corta";
            danoBase = 35;
            pesoBase = 2;
            velocidadBase = 90;
            alcanceBase = 45;
            penetracionBase = 35;
            break;

        case VarianteArma::EspadaLarga:
            objeto.tipo = TipoObjeto::Espada;
            objeto.nombre = "Espada larga";
            danoBase = 50;
            pesoBase = 3;
            velocidadBase = 75;
            alcanceBase = 70;
            penetracionBase = 50;
            break;

        case VarianteArma::EspadaBastarda:
            objeto.tipo = TipoObjeto::Espada;
            objeto.nombre = "Espada bastarda";
            danoBase = 60;
            pesoBase = 4;
            velocidadBase = 65;
            alcanceBase = 75;
            penetracionBase = 55;
            break;

        case VarianteArma::Mandoble:
            objeto.tipo = TipoObjeto::Espada;
            objeto.nombre = "Mandoble";
            danoBase = 80;
            pesoBase = 7;
            velocidadBase = 45;
            alcanceBase = 90;
            penetracionBase = 65;
            break;

        case VarianteArma::Estoque:
            objeto.tipo = TipoObjeto::Espada;
            objeto.nombre = "Estoque";
            danoBase = 45;
            pesoBase = 2;
            velocidadBase = 95;
            alcanceBase = 80;
            penetracionBase = 90;
            break;

        case VarianteArma::Sable:
            objeto.tipo = TipoObjeto::Espada;
            objeto.nombre = "Sable";
            danoBase = 48;
            pesoBase = 2;
            velocidadBase = 90;
            alcanceBase = 70;
            penetracionBase = 55;
            break;


        // ====================================
        // LANZAS
        // ====================================

        case VarianteArma::Lanza:
            objeto.tipo = TipoObjeto::Lanza;
            objeto.nombre = "Lanza";
            danoBase = 45;
            pesoBase = 3;
            velocidadBase = 70;
            alcanceBase = 95;
            penetracionBase = 65;
            break;

        case VarianteArma::Pica:
            objeto.tipo = TipoObjeto::Lanza;
            objeto.nombre = "Pica";
            danoBase = 55;
            pesoBase = 5;
            velocidadBase = 45;
            alcanceBase = 140;
            penetracionBase = 80;
            break;

        case VarianteArma::Jabalina:
            objeto.tipo = TipoObjeto::Lanza;
            objeto.nombre = "Jabalina";
            danoBase = 40;
            pesoBase = 2;
            velocidadBase = 80;
            alcanceBase = 110;
            penetracionBase = 75;
            break;

        case VarianteArma::Alabarda:
            objeto.tipo = TipoObjeto::Lanza;
            objeto.nombre = "Alabarda";
            danoBase = 75;
            pesoBase = 6;
            velocidadBase = 45;
            alcanceBase = 120;
            penetracionBase = 85;
            break;


        // ====================================
        // MAZAS
        // ====================================

        case VarianteArma::MazaLigera:
            objeto.tipo = TipoObjeto::Maza;
            objeto.nombre = "Maza ligera";
            danoBase = 45;
            pesoBase = 3;
            velocidadBase = 70;
            alcanceBase = 40;
            penetracionBase = 30;
            break;

        case VarianteArma::MazaPesada:
            objeto.tipo = TipoObjeto::Maza;
            objeto.nombre = "Maza pesada";
            danoBase = 70;
            pesoBase = 6;
            velocidadBase = 40;
            alcanceBase = 45;
            penetracionBase = 45;
            break;

        case VarianteArma::MazaConPuas:
            objeto.tipo = TipoObjeto::Maza;
            objeto.nombre = "Maza con puas";
            danoBase = 65;
            pesoBase = 5;
            velocidadBase = 50;
            alcanceBase = 45;
            penetracionBase = 70;
            break;

        case VarianteArma::Mayal:
            objeto.tipo = TipoObjeto::Maza;
            objeto.nombre = "Mayal";
            danoBase = 70;
            pesoBase = 5;
            velocidadBase = 55;
            alcanceBase = 60;
            penetracionBase = 65;
            break;


        // ====================================
        // HACHAS
        // ====================================

        case VarianteArma::HachaDeMano:
            objeto.tipo = TipoObjeto::Hacha;
            objeto.nombre = "Hacha de mano";
            danoBase = 45;
            pesoBase = 2;
            velocidadBase = 80;
            alcanceBase = 45;
            penetracionBase = 55;
            break;

        case VarianteArma::HachaDeBatalla:
            objeto.tipo = TipoObjeto::Hacha;
            objeto.nombre = "Hacha de batalla";
            danoBase = 65;
            pesoBase = 5;
            velocidadBase = 55;
            alcanceBase = 65;
            penetracionBase = 70;
            break;

        case VarianteArma::HachaDanesa:
            objeto.tipo = TipoObjeto::Hacha;
            objeto.nombre = "Hacha danesa";
            danoBase = 75;
            pesoBase = 6;
            velocidadBase = 45;
            alcanceBase = 90;
            penetracionBase = 80;
            break;

        case VarianteArma::HachaDeDosManos:
            objeto.tipo = TipoObjeto::Hacha;
            objeto.nombre = "Hacha de dos manos";
            danoBase = 85;
            pesoBase = 8;
            velocidadBase = 35;
            alcanceBase = 95;
            penetracionBase = 85;
            break;


        // ====================================
        // ARCOS
        // ====================================

        case VarianteArma::ArcoCorto:
            objeto.tipo = TipoObjeto::Arco;
            objeto.nombre = "Arco corto";
            danoBase = 35;
            pesoBase = 1;
            velocidadBase = 80;
            alcanceBase = 90;
            penetracionBase = 35;
            break;

        case VarianteArma::ArcoLargo:
            objeto.tipo = TipoObjeto::Arco;
            objeto.nombre = "Arco largo";
            danoBase = 55;
            pesoBase = 2;
            velocidadBase = 60;
            alcanceBase = 150;
            penetracionBase = 60;
            break;

        case VarianteArma::ArcoRecurvo:
            objeto.tipo = TipoObjeto::Arco;
            objeto.nombre = "Arco recurvo";
            danoBase = 60;
            pesoBase = 2;
            velocidadBase = 75;
            alcanceBase = 130;
            penetracionBase = 65;
            break;


        // ====================================
        // BALLESTAS
        // ====================================

        case VarianteArma::BallestaLigera:
            objeto.tipo = TipoObjeto::Ballesta;
            objeto.nombre = "Ballesta ligera";
            danoBase = 60;
            pesoBase = 4;
            velocidadBase = 35;
            alcanceBase = 120;
            penetracionBase = 70;
            break;

        case VarianteArma::BallestaPesada:
            objeto.tipo = TipoObjeto::Ballesta;
            objeto.nombre = "Ballesta pesada";
            danoBase = 80;
            pesoBase = 7;
            velocidadBase = 20;
            alcanceBase = 150;
            penetracionBase = 90;
            break;

        case VarianteArma::BallestaDeGuerra:
            objeto.tipo = TipoObjeto::Ballesta;
            objeto.nombre = "Ballesta de guerra";
            danoBase = 95;
            pesoBase = 9;
            velocidadBase = 15;
            alcanceBase = 160;
            penetracionBase = 100;
            break;


        // ====================================
        // DAGAS
        // ====================================

        case VarianteArma::Daga:
            objeto.tipo = TipoObjeto::Daga;
            objeto.nombre = "Daga";
            danoBase = 30;
            pesoBase = 1;
            velocidadBase = 100;
            alcanceBase = 25;
            penetracionBase = 50;
            break;

        case VarianteArma::Estilete:
            objeto.tipo = TipoObjeto::Daga;
            objeto.nombre = "Estilete";
            danoBase = 25;
            pesoBase = 1;
            velocidadBase = 105;
            alcanceBase = 30;
            penetracionBase = 95;
            break;


        // ====================================
        // MARTILLOS
        // ====================================

        case VarianteArma::MartilloDeGuerra:
            objeto.tipo = TipoObjeto::Martillo;
            objeto.nombre = "Martillo de guerra";
            danoBase = 65;
            pesoBase = 5;
            velocidadBase = 50;
            alcanceBase = 50;
            penetracionBase = 80;
            break;

        case VarianteArma::MartilloPesado:
            objeto.tipo = TipoObjeto::Martillo;
            objeto.nombre = "Martillo pesado";
            danoBase = 85;
            pesoBase = 8;
            velocidadBase = 30;
            alcanceBase = 55;
            penetracionBase = 90;
            break;

        default:
            objeto.nombre = "Arma desconocida";
            danoBase = 10;
            pesoBase = 2;
            velocidadBase = 50;
            alcanceBase = 30;
            penetracionBase = 10;
            break;
    }


    // ========================================
    // PROPIEDADES DEL MATERIAL
    // ========================================

    Recursos recursos;

    PropiedadesMaterial propiedades =
        recursos.obtenerPropiedades(material);


    // ========================================
    // APLICAR MATERIAL
    // ========================================

    double modificadorMaterial =
        (propiedades.dureza * 0.40 +
         propiedades.resistencia * 0.40 +
         propiedades.flexibilidad * 0.20) / 100.0;


    // ========================================
    // APLICAR CALIDAD DEL ARTESANO
    // ========================================

    double modificadorCalidad =
        obtenerMultiplicadorCalidad(objeto.calidad);


    // ========================================
    // ESTADISTICAS FINALES
    // ========================================

    objeto.daño =
        static_cast<int>(
            danoBase *
            modificadorMaterial *
            modificadorCalidad
        );

    objeto.durabilidad =
        static_cast<int>(
            durabilidadBase *
            (propiedades.resistencia / 100.0) *
            modificadorCalidad
        );

    objeto.peso =
        static_cast<int>(
            pesoBase *
            (propiedades.peso / 60.0)
        );

    if (objeto.peso < 1)
        objeto.peso = 1;

    objeto.velocidad =
        static_cast<int>(
            velocidadBase *
            (100.0 / (100.0 + objeto.peso * 4))
        );

    objeto.alcance = alcanceBase;

    objeto.penetracion =
        static_cast<int>(
            penetracionBase *
            (propiedades.dureza / 100.0) *
            modificadorCalidad
        );

    objeto.defensa = 0;
    objeto.bloqueo = 0;
    objeto.cobertura = 0;
    objeto.estabilidad = 0;

    objeto.valor =
        static_cast<int>(
            propiedades.valor *
            10 *
            modificadorCalidad
        );

    return objeto;
}


// ========================================
// CREAR ESCUDO
// ========================================

Objeto crearEscudo(
    int id,
    VarianteEscudo variante,
    const std::string& material,
    int habilidadArtesano,
    int artesanoID,
    const std::string& artesanoNombre
)
{
    Objeto objeto{};

    objeto.id = id;

    objeto.tipo = TipoObjeto::Escudo;

    objeto.varianteArma = VarianteArma::Ninguna;
    objeto.varianteEscudo = variante;
    objeto.varianteArmadura = VarianteArmadura::Ninguna;

    objeto.material = material;

    objeto.artesanoID = artesanoID;
    objeto.artesanoNombre = artesanoNombre;
    objeto.firma = artesanoNombre;

    objeto.calidad = calcularCalidad(habilidadArtesano);

    int defensaBase = 0;
    int bloqueoBase = 0;
    int coberturaBase = 0;
    int estabilidadBase = 0;
    int pesoBase = 0;

    switch (variante)
    {
        case VarianteEscudo::Broquel:
            objeto.nombre = "Broquel";
            defensaBase = 25;
            bloqueoBase = 65;
            coberturaBase = 20;
            estabilidadBase = 45;
            pesoBase = 1;
            break;

        case VarianteEscudo::EscudoRedondoPequeno:
            objeto.nombre = "Escudo redondo pequeño";
            defensaBase = 35;
            bloqueoBase = 70;
            coberturaBase = 35;
            estabilidadBase = 55;
            pesoBase = 2;
            break;

        case VarianteEscudo::EscudoRedondo:
            objeto.nombre = "Escudo redondo";
            defensaBase = 50;
            bloqueoBase = 80;
            coberturaBase = 55;
            estabilidadBase = 70;
            pesoBase = 4;
            break;

        case VarianteEscudo::EscudoRedondoGrande:
            objeto.nombre = "Escudo redondo grande";
            defensaBase = 65;
            bloqueoBase = 85;
            coberturaBase = 70;
            estabilidadBase = 80;
            pesoBase = 6;
            break;

        case VarianteEscudo::EscudoOvalado:
            objeto.nombre = "Escudo ovalado";
            defensaBase = 55;
            bloqueoBase = 82;
            coberturaBase = 65;
            estabilidadBase = 75;
            pesoBase = 5;
            break;

        case VarianteEscudo::EscudoOvaladoGrande:
            objeto.nombre = "Escudo ovalado grande";
            defensaBase = 65;
            bloqueoBase = 88;
            coberturaBase = 80;
            estabilidadBase = 82;
            pesoBase = 7;
            break;

        case VarianteEscudo::EscudoDeCometa:
            objeto.nombre = "Escudo de cometa";
            defensaBase = 60;
            bloqueoBase = 85;
            coberturaBase = 80;
            estabilidadBase = 78;
            pesoBase = 5;
            break;

        case VarianteEscudo::EscudoDeCometaGrande:
            objeto.nombre = "Escudo de cometa grande";
            defensaBase = 70;
            bloqueoBase = 90;
            coberturaBase = 90;
            estabilidadBase = 85;
            pesoBase = 7;
            break;

        case VarianteEscudo::EscudoAlargado:
            objeto.nombre = "Escudo alargado";
            defensaBase = 65;
            bloqueoBase = 88;
            coberturaBase = 85;
            estabilidadBase = 80;
            pesoBase = 6;
            break;

        case VarianteEscudo::EscudoAlargadoGrande:
            objeto.nombre = "Escudo alargado grande";
            defensaBase = 75;
            bloqueoBase = 92;
            coberturaBase = 95;
            estabilidadBase = 88;
            pesoBase = 8;
            break;

        case VarianteEscudo::EscudoRectangular:
            objeto.nombre = "Escudo rectangular";
            defensaBase = 60;
            bloqueoBase = 85;
            coberturaBase = 80;
            estabilidadBase = 82;
            pesoBase = 6;
            break;

        case VarianteEscudo::EscudoRectangularGrande:
            objeto.nombre = "Escudo rectangular grande";
            defensaBase = 75;
            bloqueoBase = 92;
            coberturaBase = 95;
            estabilidadBase = 90;
            pesoBase = 9;
            break;

        case VarianteEscudo::EscudoDeTorre:
            objeto.nombre = "Escudo de torre";
            defensaBase = 80;
            bloqueoBase = 95;
            coberturaBase = 100;
            estabilidadBase = 95;
            pesoBase = 12;
            break;

        case VarianteEscudo::EscudoDeTorreGrande:
            objeto.nombre = "Escudo de torre grande";
            defensaBase = 90;
            bloqueoBase = 98;
            coberturaBase = 100;
            estabilidadBase = 100;
            pesoBase = 16;
            break;

        case VarianteEscudo::EscudoHeraldico:
            objeto.nombre = "Escudo heráldico";
            defensaBase = 60;
            bloqueoBase = 85;
            coberturaBase = 80;
            estabilidadBase = 80;
            pesoBase = 6;
            break;

        case VarianteEscudo::EscudoDeGuerra:
            objeto.nombre = "Escudo de guerra";
            defensaBase = 80;
            bloqueoBase = 95;
            coberturaBase = 90;
            estabilidadBase = 95;
            pesoBase = 10;
            break;

        case VarianteEscudo::EscudoCeremonial:
            objeto.nombre = "Escudo ceremonial";
            defensaBase = 30;
            bloqueoBase = 50;
            coberturaBase = 45;
            estabilidadBase = 40;
            pesoBase = 4;
            break;

        default:
            objeto.nombre = "Escudo desconocido";
            defensaBase = 10;
            bloqueoBase = 10;
            coberturaBase = 10;
            estabilidadBase = 10;
            pesoBase = 3;
            break;
    }


    // ========================================
    // MATERIAL
    // ========================================

    Recursos recursos;

    PropiedadesMaterial propiedades =
        recursos.obtenerPropiedades(material);


    // ========================================
    // MODIFICADORES
    // ========================================

    double modificadorMaterial =
        (propiedades.resistencia * 0.50 +
         propiedades.dureza * 0.30 +
         propiedades.flexibilidad * 0.20) / 100.0;

    double modificadorCalidad =
        obtenerMultiplicadorCalidad(objeto.calidad);


    // ========================================
    // ESTADISTICAS FINALES
    // ========================================

    objeto.defensa =
        static_cast<int>(
            defensaBase *
            modificadorMaterial *
            modificadorCalidad
        );

    objeto.bloqueo =
        static_cast<int>(
            bloqueoBase *
            modificadorCalidad
        );

    objeto.cobertura =
        static_cast<int>(
            coberturaBase *
            modificadorCalidad
        );

    objeto.estabilidad =
        static_cast<int>(
            estabilidadBase *
            modificadorMaterial *
            modificadorCalidad
        );

    objeto.peso =
        static_cast<int>(
            pesoBase *
            (propiedades.peso / 60.0)
        );

    if (objeto.peso < 1)
        objeto.peso = 1;

    objeto.durabilidad =
        static_cast<int>(
            100 *
            (propiedades.resistencia / 100.0) *
            modificadorCalidad
        );

    objeto.daño = 0;
    objeto.velocidad = 0;
    objeto.alcance = 0;
    objeto.penetracion = 0;

    objeto.valor =
        static_cast<int>(
            propiedades.valor *
            12 *
            modificadorCalidad
        );

    return objeto;
}


// ========================================
// CREAR ARMADURA
// ========================================

Objeto crearArmadura(
    int id,
    VarianteArmadura variante,
    const std::string& material,
    int habilidadArtesano,
    int artesanoID,
    const std::string& artesanoNombre
)
{
    Objeto objeto{};

    objeto.id = id;

    objeto.tipo = TipoObjeto::Armadura;

    objeto.varianteArma = VarianteArma::Ninguna;
    objeto.varianteEscudo = VarianteEscudo::Ninguno;
    objeto.varianteArmadura = variante;

    objeto.material = material;

    objeto.artesanoID = artesanoID;
    objeto.artesanoNombre = artesanoNombre;
    objeto.firma = artesanoNombre;

    objeto.calidad = calcularCalidad(habilidadArtesano);

    int defensaBase = 0;
    int pesoBase = 0;
    int durabilidadBase = 100;


    switch (variante)
    {
        case VarianteArmadura::ArmaduraDeCuero:
            objeto.nombre = "Armadura de cuero";
            defensaBase = 30;
            pesoBase = 5;
            durabilidadBase = 80;
            break;

        case VarianteArmadura::ArmaduraDeCueroReforzado:
            objeto.nombre = "Armadura de cuero reforzado";
            defensaBase = 45;
            pesoBase = 8;
            durabilidadBase = 100;
            break;

        case VarianteArmadura::Gambeson:
            objeto.nombre = "Gambeson";
            defensaBase = 35;
            pesoBase = 6;
            durabilidadBase = 70;
            break;

        case VarianteArmadura::CotaDeMalla:
            objeto.nombre = "Cota de malla";
            defensaBase = 65;
            pesoBase = 12;
            durabilidadBase = 140;
            break;

        case VarianteArmadura::CotaDeMallaPesada:
            objeto.nombre = "Cota de malla pesada";
            defensaBase = 75;
            pesoBase = 16;
            durabilidadBase = 170;
            break;

        case VarianteArmadura::ArmaduraDeEscamas:
            objeto.nombre = "Armadura de escamas";
            defensaBase = 72;
            pesoBase = 14;
            durabilidadBase = 150;
            break;

        case VarianteArmadura::ArmaduraDePlacas:
            objeto.nombre = "Armadura de placas";
            defensaBase = 85;
            pesoBase = 20;
            durabilidadBase = 200;
            break;

        case VarianteArmadura::ArmaduraDePlacasPesada:
            objeto.nombre = "Armadura de placas pesada";
            defensaBase = 92;
            pesoBase = 28;
            durabilidadBase = 240;
            break;

        case VarianteArmadura::ArmaduraDeGuerra:
            objeto.nombre = "Armadura de guerra";
            defensaBase = 100;
            pesoBase = 32;
            durabilidadBase = 280;
            break;

        default:
            objeto.nombre = "Armadura desconocida";
            defensaBase = 10;
            pesoBase = 5;
            durabilidadBase = 50;
            break;
    }


    // ========================================
    // PROPIEDADES DEL MATERIAL
    // ========================================

    Recursos recursos;

    PropiedadesMaterial propiedades =
        recursos.obtenerPropiedades(material);


    // ========================================
    // MODIFICADORES
    // ========================================

    double modificadorMaterial =
        (propiedades.resistencia * 0.50 +
         propiedades.dureza * 0.40 +
         propiedades.flexibilidad * 0.10) / 100.0;

    double modificadorCalidad =
        obtenerMultiplicadorCalidad(objeto.calidad);


    // ========================================
    // ESTADISTICAS FINALES
    // ========================================

    objeto.defensa =
        static_cast<int>(
            defensaBase *
            modificadorMaterial *
            modificadorCalidad
        );

    objeto.durabilidad =
        static_cast<int>(
            durabilidadBase *
            (propiedades.resistencia / 100.0) *
            modificadorCalidad
        );

    objeto.peso =
        static_cast<int>(
            pesoBase *
            (propiedades.peso / 60.0)
        );

    if (objeto.peso < 1)
        objeto.peso = 1;

    objeto.daño = 0;
    objeto.velocidad = 0;
    objeto.alcance = 0;
    objeto.penetracion = 0;

    objeto.bloqueo = 0;
    objeto.cobertura = 0;
    objeto.estabilidad = 0;

    objeto.valor =
        static_cast<int>(
            propiedades.valor *
            15 *
            modificadorCalidad
        );

    return objeto;
}


// ========================================
// NOMBRE DE VARIANTE DE ARMA
// ========================================

std::string obtenerNombreVariante(
    VarianteArma variante
)
{
    switch (variante)
    {
        case VarianteArma::EspadaCorta:
            return "Espada corta";

        case VarianteArma::EspadaLarga:
            return "Espada larga";

        case VarianteArma::EspadaBastarda:
            return "Espada bastarda";

        case VarianteArma::Mandoble:
            return "Mandoble";

        case VarianteArma::Estoque:
            return "Estoque";

        case VarianteArma::Sable:
            return "Sable";

        case VarianteArma::Lanza:
            return "Lanza";

        case VarianteArma::Pica:
            return "Pica";

        case VarianteArma::Jabalina:
            return "Jabalina";

        case VarianteArma::Alabarda:
            return "Alabarda";

        case VarianteArma::MazaLigera:
            return "Maza ligera";

        case VarianteArma::MazaPesada:
            return "Maza pesada";

        case VarianteArma::MazaConPuas:
            return "Maza con puas";

        case VarianteArma::Mayal:
            return "Mayal";

        case VarianteArma::HachaDeMano:
            return "Hacha de mano";

        case VarianteArma::HachaDeBatalla:
            return "Hacha de batalla";

        case VarianteArma::HachaDanesa:
            return "Hacha danesa";

        case VarianteArma::HachaDeDosManos:
            return "Hacha de dos manos";

        case VarianteArma::ArcoCorto:
            return "Arco corto";

        case VarianteArma::ArcoLargo:
            return "Arco largo";

        case VarianteArma::ArcoRecurvo:
            return "Arco recurvo";

        case VarianteArma::BallestaLigera:
            return "Ballesta ligera";

        case VarianteArma::BallestaPesada:
            return "Ballesta pesada";

        case VarianteArma::BallestaDeGuerra:
            return "Ballesta de guerra";

        case VarianteArma::Daga:
            return "Daga";

        case VarianteArma::Estilete:
            return "Estilete";

        case VarianteArma::MartilloDeGuerra:
            return "Martillo de guerra";

        case VarianteArma::MartilloPesado:
            return "Martillo pesado";

        default:
            return "Ninguna";
    }
}


// ========================================
// NOMBRE DE VARIANTE DE ESCUDO
// ========================================

std::string obtenerNombreVarianteEscudo(
    VarianteEscudo variante
)
{
    switch (variante)
    {
        case VarianteEscudo::Broquel:
            return "Broquel";

        case VarianteEscudo::EscudoRedondoPequeno:
            return "Escudo redondo pequeño";

        case VarianteEscudo::EscudoRedondo:
            return "Escudo redondo";

        case VarianteEscudo::EscudoRedondoGrande:
            return "Escudo redondo grande";

        case VarianteEscudo::EscudoOvalado:
            return "Escudo ovalado";

        case VarianteEscudo::EscudoOvaladoGrande:
            return "Escudo ovalado grande";

        case VarianteEscudo::EscudoDeCometa:
            return "Escudo de cometa";

        case VarianteEscudo::EscudoDeCometaGrande:
            return "Escudo de cometa grande";

        case VarianteEscudo::EscudoAlargado:
            return "Escudo alargado";

        case VarianteEscudo::EscudoAlargadoGrande:
            return "Escudo alargado grande";

        case VarianteEscudo::EscudoRectangular:
            return "Escudo rectangular";

        case VarianteEscudo::EscudoRectangularGrande:
            return "Escudo rectangular grande";

        case VarianteEscudo::EscudoDeTorre:
            return "Escudo de torre";

        case VarianteEscudo::EscudoDeTorreGrande:
            return "Escudo de torre grande";

        case VarianteEscudo::EscudoHeraldico:
            return "Escudo heráldico";

        case VarianteEscudo::EscudoDeGuerra:
            return "Escudo de guerra";

        case VarianteEscudo::EscudoCeremonial:
            return "Escudo ceremonial";

        default:
            return "Ninguno";
    }
}


// ========================================
// NOMBRE DE ARMADURA
// ========================================

std::string obtenerNombreArmadura(
    VarianteArmadura variante
)
{
    switch (variante)
    {
        case VarianteArmadura::ArmaduraDeCuero:
            return "Armadura de cuero";

        case VarianteArmadura::ArmaduraDeCueroReforzado:
            return "Armadura de cuero reforzado";

        case VarianteArmadura::Gambeson:
            return "Gambeson";

        case VarianteArmadura::CotaDeMalla:
            return "Cota de malla";

        case VarianteArmadura::CotaDeMallaPesada:
            return "Cota de malla pesada";

        case VarianteArmadura::ArmaduraDeEscamas:
            return "Armadura de escamas";

        case VarianteArmadura::ArmaduraDePlacas:
            return "Armadura de placas";

        case VarianteArmadura::ArmaduraDePlacasPesada:
            return "Armadura de placas pesada";

        case VarianteArmadura::ArmaduraDeGuerra:
            return "Armadura de guerra";

        default:
            return "Ninguna";
    }
}


// ========================================
// MOSTRAR OBJETO
// ========================================

void mostrarObjeto(
    const Objeto& objeto
)
{
    std::cout << "\n";
    std::cout << "========== OBJETO ==========\n";

    std::cout << "ID: "
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
              << "/100\n";

    std::cout << "Daño: "
              << objeto.daño
              << "\n";

    std::cout << "Defensa: "
              << objeto.defensa
              << "\n";

    std::cout << "Durabilidad: "
              << objeto.durabilidad
              << "\n";

    std::cout << "Peso: "
              << objeto.peso
              << "\n";

    std::cout << "Velocidad: "
              << objeto.velocidad
              << "\n";

    std::cout << "Alcance: "
              << objeto.alcance
              << "\n";

    std::cout << "Penetracion: "
              << objeto.penetracion
              << "\n";

    std::cout << "Bloqueo: "
              << objeto.bloqueo
              << "\n";

    std::cout << "Cobertura: "
              << objeto.cobertura
              << "\n";

    std::cout << "Estabilidad: "
              << objeto.estabilidad
              << "\n";

    std::cout << "Valor: "
              << objeto.valor
              << "\n";

    std::cout << "Artesano: "
              << objeto.artesanoNombre
              << "\n";

    std::cout << "Firma: "
              << objeto.firma
              << "\n";

    std::cout << "============================\n";
}