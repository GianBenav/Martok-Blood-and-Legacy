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

    std::uniform_int_distribution<int> distribucion(
        minimo,
        maximo
    );

    return distribucion(generador);
}


// ========================================
// CALCULAR CALIDAD
// ========================================

int calcularCalidad(int habilidadArtesano)
{
    habilidadArtesano =
        std::clamp(habilidadArtesano, 0, 100);

    int variacion =
        variacionAleatoria(-10, 10);

    int calidad =
        habilidadArtesano + variacion;

    return std::clamp(calidad, 1, 100);
}


// ========================================
// MODIFICADOR DE CALIDAD
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
// CREAR OBJETO BASE
// ========================================

Objeto crearObjetoBase()
{
    Objeto objeto{};

    objeto.id = 0;
    objeto.nombre = "";

    objeto.tipo = TipoObjeto::Camisa;

    objeto.varianteArma = VarianteArma::Ninguna;
    objeto.varianteEscudo = VarianteEscudo::Ninguno;
    objeto.varianteArmadura = VarianteArmadura::Ninguna;
    objeto.varianteRopa = VarianteRopa::Ninguna;
    objeto.varianteJoya = VarianteJoya::Ninguna;

    objeto.material = "";

    objeto.calidad = 1;

    // DEFENSA
    objeto.defensa = 0;
    objeto.defensaCorte = 0;
    objeto.defensaPerforacion = 0;
    objeto.defensaGolpe = 0;
    objeto.defensaProyectiles = 0;

    // ATRIBUTOS
    objeto.fuerza = 0;
    objeto.velocidad = 0;
    objeto.resistencia = 0;
    objeto.percepcion = 0;
    objeto.inteligencia = 0;
    objeto.carisma = 0;
    objeto.prestigio = 0;
    objeto.sigilo = 0;

    // SUPERVIVENCIA
    objeto.resistenciaFrio = 0;
    objeto.resistenciaCalor = 0;
    objeto.resistenciaAgua = 0;
    objeto.resistenciaEnfermedades = 0;

    // COMBATE
    objeto.daño = 0;
    objeto.precision = 0;
    objeto.alcance = 0;
    objeto.penetracion = 0;
    objeto.bloqueo = 0;
    objeto.cobertura = 0;
    objeto.estabilidad = 0;

    // PROFESIONES
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

    // FISICAS
    objeto.durabilidad = 0;
    objeto.peso = 0;

    // ECONOMIA
    objeto.valor = 0;

    // ARTESANO
    objeto.artesanoID = -1;
    objeto.artesanoNombre = "";
    objeto.firma = "";

    return objeto;
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
    Objeto objeto = crearObjetoBase();

    objeto.id = id;
    objeto.varianteArma = variante;
    objeto.material = material;

    objeto.artesanoID = artesanoID;
    objeto.artesanoNombre = artesanoNombre;
    objeto.firma = artesanoNombre;

    objeto.calidad =
        calcularCalidad(habilidadArtesano);

    int danoBase = 0;
    int pesoBase = 1;
    int velocidadBase = 50;
    int alcanceBase = 30;
    int penetracionBase = 10;

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

        case VarianteArma::LanzaSimple:
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
            objeto.tipo = TipoObjeto::Espada;
            objeto.nombre = "Arma desconocida";
            break;
    }

    Recursos recursos;

    PropiedadesMaterial propiedades =
        recursos.obtenerPropiedades(material);

    double modificadorMaterial =
        (
            propiedades.dureza * 0.40 +
            propiedades.resistencia * 0.40 +
            propiedades.flexibilidad * 0.20
        ) / 100.0;

    double modificadorCalidad =
        obtenerMultiplicadorCalidad(objeto.calidad);

    objeto.daño =
        static_cast<int>(
            danoBase *
            modificadorMaterial *
            modificadorCalidad
        );

    objeto.durabilidad =
        static_cast<int>(
            100 *
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

    objeto.valor =
        static_cast<int>(
            propiedades.valor *
            10 *
            modificadorCalidad
        );

    // Un arma de gran calidad empieza a tener prestigio
    objeto.prestigio =
        std::max(0, (objeto.calidad - 70) / 3);

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
    Objeto objeto = crearObjetoBase();

    objeto.id = id;
    objeto.tipo = TipoObjeto::Escudo;

    objeto.varianteEscudo = variante;
    objeto.material = material;

    objeto.artesanoID = artesanoID;
    objeto.artesanoNombre = artesanoNombre;
    objeto.firma = artesanoNombre;

    objeto.calidad =
        calcularCalidad(habilidadArtesano);

    int defensaBase = 30;
    int bloqueoBase = 50;
    int coberturaBase = 40;
    int estabilidadBase = 40;
    int pesoBase = 4;

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
            objeto.nombre = "Escudo heraldico";
            defensaBase = 60;
            bloqueoBase = 85;
            coberturaBase = 80;
            estabilidadBase = 80;
            pesoBase = 6;
            objeto.prestigio = 10;
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
            objeto.prestigio = 20;
            objeto.carisma = 5;
            break;

        default:
            objeto.nombre = "Escudo desconocido";
            break;
    }

    Recursos recursos;

    PropiedadesMaterial propiedades =
        recursos.obtenerPropiedades(material);

    double modificadorMaterial =
        (
            propiedades.resistencia * 0.50 +
            propiedades.dureza * 0.30 +
            propiedades.flexibilidad * 0.20
        ) / 100.0;

    double modificadorCalidad =
        obtenerMultiplicadorCalidad(objeto.calidad);

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

    objeto.valor =
        static_cast<int>(
            propiedades.valor *
            12 *
            modificadorCalidad
        );

    objeto.prestigio +=
        std::max(0, (objeto.calidad - 80) / 2);

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
    Objeto objeto = crearObjetoBase();

    objeto.id = id;
    objeto.tipo = TipoObjeto::Armadura;

    objeto.varianteArmadura = variante;
    objeto.material = material;

    objeto.artesanoID = artesanoID;
    objeto.artesanoNombre = artesanoNombre;
    objeto.firma = artesanoNombre;

    objeto.calidad =
        calcularCalidad(habilidadArtesano);

    int defensaBase = 20;
    int pesoBase = 5;
    int durabilidadBase = 70;

    switch (variante)
    {
        case VarianteArmadura::ArmaduraDeCuero:
            objeto.nombre = "Armadura de cuero";
            defensaBase = 30;
            pesoBase = 5;
            durabilidadBase = 80;
            objeto.sigilo = 3;
            break;

        case VarianteArmadura::ArmaduraDeCueroReforzado:
            objeto.nombre = "Armadura de cuero reforzado";
            defensaBase = 45;
            pesoBase = 8;
            durabilidadBase = 100;
            objeto.sigilo = 1;
            break;

        case VarianteArmadura::Gambeson:
            objeto.nombre = "Gambeson";
            defensaBase = 35;
            pesoBase = 6;
            durabilidadBase = 70;
            objeto.resistencia = 5;
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
            objeto.sigilo = -10;
            break;

        case VarianteArmadura::ArmaduraDePlacasPesada:
            objeto.nombre = "Armadura de placas pesada";
            defensaBase = 92;
            pesoBase = 28;
            durabilidadBase = 240;
            objeto.sigilo = -15;
            break;

        case VarianteArmadura::ArmaduraDeGuerra:
            objeto.nombre = "Armadura de guerra";
            defensaBase = 100;
            pesoBase = 32;
            durabilidadBase = 280;
            objeto.sigilo = -20;
            objeto.prestigio = 15;
            break;

        default:
            objeto.nombre = "Armadura desconocida";
            break;
    }

    Recursos recursos;

    PropiedadesMaterial propiedades =
        recursos.obtenerPropiedades(material);

    double modificadorMaterial =
        (
            propiedades.resistencia * 0.50 +
            propiedades.dureza * 0.40 +
            propiedades.flexibilidad * 0.10
        ) / 100.0;

    double modificadorCalidad =
        obtenerMultiplicadorCalidad(objeto.calidad);

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

    objeto.valor =
        static_cast<int>(
            propiedades.valor *
            15 *
            modificadorCalidad
        );

    objeto.prestigio +=
        std::max(0, (objeto.calidad - 75) / 2);

    return objeto;
}


// ========================================
// CREAR ROPA
// ========================================

Objeto crearRopa(
    int id,
    VarianteRopa variante,
    const std::string& material,
    int habilidadArtesano,
    int artesanoID,
    const std::string& artesanoNombre
)
{
    Objeto objeto = crearObjetoBase();

    objeto.id = id;
    objeto.varianteRopa = variante;
    objeto.material = material;

    objeto.artesanoID = artesanoID;
    objeto.artesanoNombre = artesanoNombre;
    objeto.firma = artesanoNombre;

    objeto.calidad =
        calcularCalidad(habilidadArtesano);

    Recursos recursos;

    PropiedadesMaterial propiedades =
        recursos.obtenerPropiedades(material);

    double calidad =
        obtenerMultiplicadorCalidad(objeto.calidad);

    // ========================================
    // ROPA BASICA
    // ========================================

    switch (variante)
    {
        case VarianteRopa::CamisaSimple:
            objeto.tipo = TipoObjeto::Camisa;
            objeto.nombre = "Camisa simple";
            objeto.defensa = 3;
            objeto.resistenciaFrio = 2;
            objeto.costura = 2;
            break;

        case VarianteRopa::CamisaDeTrabajo:
            objeto.tipo = TipoObjeto::Camisa;
            objeto.nombre = "Camisa de trabajo";
            objeto.defensa = 6;
            objeto.resistencia = 2;
            objeto.costura = 4;
            break;

        case VarianteRopa::CamisaElegante:
            objeto.tipo = TipoObjeto::Camisa;
            objeto.nombre = "Camisa elegante";
            objeto.carisma = 5;
            objeto.prestigio = 3;
            objeto.costura = 6;
            break;

        case VarianteRopa::CamisaMilitar:
            objeto.tipo = TipoObjeto::Camisa;
            objeto.nombre = "Camisa militar";
            objeto.defensa = 8;
            objeto.resistencia = 3;
            break;


        case VarianteRopa::CamisonSimple:
            objeto.tipo = TipoObjeto::Camison;
            objeto.nombre = "Camison simple";
            objeto.resistenciaFrio = 3;
            objeto.defensa = 2;
            break;

        case VarianteRopa::CamisonDeInvierno:
            objeto.tipo = TipoObjeto::Camison;
            objeto.nombre = "Camison de invierno";
            objeto.defensa = 5;
            objeto.resistenciaFrio = 15;
            break;

        case VarianteRopa::CamisonMilitar:
            objeto.tipo = TipoObjeto::Camison;
            objeto.nombre = "Camison militar";
            objeto.defensa = 7;
            objeto.resistenciaFrio = 5;
            break;


        case VarianteRopa::PantalonesSimples:
            objeto.tipo = TipoObjeto::Pantalones;
            objeto.nombre = "Pantalones simples";
            objeto.defensa = 3;
            objeto.sigilo = 1;
            break;

        case VarianteRopa::PantalonesDeTrabajo:
            objeto.tipo = TipoObjeto::Pantalones;
            objeto.nombre = "Pantalones de trabajo";
            objeto.defensa = 7;
            objeto.resistencia = 3;
            objeto.agricultura = 2;
            break;

        case VarianteRopa::PantalonesDeCazador:
            objeto.tipo = TipoObjeto::Pantalones;
            objeto.nombre = "Pantalones de cazador";
            objeto.sigilo = 7;
            objeto.caza = 5;
            objeto.exploracion = 3;
            break;

        case VarianteRopa::PantalonesMilitares:
            objeto.tipo = TipoObjeto::Pantalones;
            objeto.nombre = "Pantalones militares";
            objeto.defensa = 10;
            objeto.resistencia = 5;
            break;


        case VarianteRopa::CalzonesSimples:
            objeto.tipo = TipoObjeto::Calzones;
            objeto.nombre = "Calzones simples";
            objeto.defensa = 1;
            break;

        case VarianteRopa::CalzonesDeTrabajo:
            objeto.tipo = TipoObjeto::Calzones;
            objeto.nombre = "Calzones de trabajo";
            objeto.defensa = 3;
            objeto.resistencia = 2;
            break;

        case VarianteRopa::CalzonesMilitares:
            objeto.tipo = TipoObjeto::Calzones;
            objeto.nombre = "Calzones militares";
            objeto.defensa = 5;
            break;


        case VarianteRopa::TunicaSimple:
            objeto.tipo = TipoObjeto::Tunica;
            objeto.nombre = "Tunica simple";
            objeto.defensa = 4;
            objeto.resistenciaFrio = 5;
            break;

        case VarianteRopa::TunicaReligiosa:
            objeto.tipo = TipoObjeto::Tunica;
            objeto.nombre = "Tunica religiosa";
            objeto.carisma = 4;
            objeto.prestigio = 8;
            objeto.resistenciaEnfermedades = 1;
            break;

        case VarianteRopa::TunicaNoble:
            objeto.tipo = TipoObjeto::Tunica;
            objeto.nombre = "Tunica noble";
            objeto.carisma = 12;
            objeto.prestigio = 20;
            break;

        case VarianteRopa::TunicaMilitar:
            objeto.tipo = TipoObjeto::Tunica;
            objeto.nombre = "Tunica militar";
            objeto.defensa = 8;
            objeto.resistencia = 4;
            break;


        case VarianteRopa::CapaSimple:
            objeto.tipo = TipoObjeto::Capa;
            objeto.nombre = "Capa simple";
            objeto.defensa = 3;
            objeto.resistenciaFrio = 8;
            break;

        case VarianteRopa::CapaDeViaje:
            objeto.tipo = TipoObjeto::Capa;
            objeto.nombre = "Capa de viaje";
            objeto.resistenciaFrio = 10;
            objeto.resistenciaAgua = 8;
            objeto.exploracion = 5;
            break;

        case VarianteRopa::CapaNoble:
            objeto.tipo = TipoObjeto::Capa;
            objeto.nombre = "Capa noble";
            objeto.carisma = 10;
            objeto.prestigio = 20;
            break;

        case VarianteRopa::CapaMilitar:
            objeto.tipo = TipoObjeto::Capa;
            objeto.nombre = "Capa militar";
            objeto.defensa = 7;
            objeto.resistenciaFrio = 10;
            break;


        case VarianteRopa::VestidoSimple:
            objeto.tipo = TipoObjeto::Vestido;
            objeto.nombre = "Vestido simple";
            objeto.defensa = 3;
            break;

        case VarianteRopa::VestidoElegante:
            objeto.tipo = TipoObjeto::Vestido;
            objeto.nombre = "Vestido elegante";
            objeto.carisma = 10;
            objeto.prestigio = 10;
            break;

        case VarianteRopa::VestidoNoble:
            objeto.tipo = TipoObjeto::Vestido;
            objeto.nombre = "Vestido noble";
            objeto.carisma = 15;
            objeto.prestigio = 25;
            break;

        case VarianteRopa::VestidoMilitar:
            objeto.tipo = TipoObjeto::Vestido;
            objeto.nombre = "Vestido militar";
            objeto.defensa = 7;
            objeto.resistencia = 3;
            break;


        case VarianteRopa::FaldaSimple:
            objeto.tipo = TipoObjeto::Falda;
            objeto.nombre = "Falda simple";
            objeto.defensa = 2;
            break;

        case VarianteRopa::FaldaDeTrabajo:
            objeto.tipo = TipoObjeto::Falda;
            objeto.nombre = "Falda de trabajo";
            objeto.defensa = 5;
            objeto.resistencia = 3;
            break;

        case VarianteRopa::FaldaNoble:
            objeto.tipo = TipoObjeto::Falda;
            objeto.nombre = "Falda noble";
            objeto.carisma = 10;
            objeto.prestigio = 15;
            break;

        case VarianteRopa::FaldaMilitar:
            objeto.tipo = TipoObjeto::Falda;
            objeto.nombre = "Falda militar";
            objeto.defensa = 7;
            objeto.resistencia = 3;
            break;


        // ====================================
        // ABRIGOS
        // ====================================

        case VarianteRopa::AbrigoSimple:
            objeto.tipo = TipoObjeto::Abrigo;
            objeto.nombre = "Abrigo simple";
            objeto.defensa = 7;
            objeto.resistenciaFrio = 15;
            break;

        case VarianteRopa::AbrigoDeInvierno:
            objeto.tipo = TipoObjeto::Abrigo;
            objeto.nombre = "Abrigo de invierno";
            objeto.defensa = 12;
            objeto.resistenciaFrio = 30;
            break;

        case VarianteRopa::AbrigoMilitar:
            objeto.tipo = TipoObjeto::Abrigo;
            objeto.nombre = "Abrigo militar";
            objeto.defensa = 15;
            objeto.resistenciaFrio = 20;
            objeto.resistencia = 4;
            break;


        case VarianteRopa::AbrigoDePielDeLobo:
            objeto.tipo = TipoObjeto::AbrigoDePieles;
            objeto.nombre = "Abrigo de piel de lobo";
            objeto.defensa = 12;
            objeto.resistenciaFrio = 35;
            objeto.sigilo = 4;
            objeto.caza = 3;
            break;

        case VarianteRopa::AbrigoDePielDeOso:
            objeto.tipo = TipoObjeto::AbrigoDePieles;
            objeto.nombre = "Abrigo de piel de oso";
            objeto.defensa = 20;
            objeto.resistenciaFrio = 50;
            objeto.fuerza = 3;
            break;

        case VarianteRopa::AbrigoDePielDeCiervo:
            objeto.tipo = TipoObjeto::AbrigoDePieles;
            objeto.nombre = "Abrigo de piel de ciervo";
            objeto.defensa = 10;
            objeto.resistenciaFrio = 30;
            objeto.exploracion = 4;
            break;

        case VarianteRopa::AbrigoDePielDeZorro:
            objeto.tipo = TipoObjeto::AbrigoDePieles;
            objeto.nombre = "Abrigo de piel de zorro";
            objeto.defensa = 9;
            objeto.resistenciaFrio = 28;
            objeto.sigilo = 8;
            break;

        case VarianteRopa::AbrigoDePielDeOveja:
            objeto.tipo = TipoObjeto::AbrigoDePieles;
            objeto.nombre = "Abrigo de piel de oveja";
            objeto.defensa = 10;
            objeto.resistenciaFrio = 35;
            break;

        case VarianteRopa::AbrigoDePielDeAlce:
            objeto.tipo = TipoObjeto::AbrigoDePieles;
            objeto.nombre = "Abrigo de piel de alce";
            objeto.defensa = 18;
            objeto.resistenciaFrio = 45;
            objeto.resistencia = 3;
            break;

        case VarianteRopa::AbrigoDePielMilitar:
            objeto.tipo = TipoObjeto::AbrigoDePieles;
            objeto.nombre = "Abrigo de piel militar";
            objeto.defensa = 22;
            objeto.resistenciaFrio = 45;
            objeto.resistencia = 6;
            break;


        // ====================================
        // GUANTES Y BRAZALES
        // ====================================

        case VarianteRopa::GuantesSimples:
            objeto.tipo = TipoObjeto::Guantes;
            objeto.nombre = "Guantes simples";
            objeto.defensa = 2;
            break;

        case VarianteRopa::GuantesDeTrabajo:
            objeto.tipo = TipoObjeto::Guantes;
            objeto.nombre = "Guantes de trabajo";
            objeto.defensa = 5;
            objeto.herreria = 2;
            objeto.carpinteria = 2;
            break;

        case VarianteRopa::GuantesDeCuero:
            objeto.tipo = TipoObjeto::Guantes;
            objeto.nombre = "Guantes de cuero";
            objeto.defensa = 7;
            objeto.herreria = 2;
            break;

        case VarianteRopa::GuantesDeInvierno:
            objeto.tipo = TipoObjeto::Guantes;
            objeto.nombre = "Guantes de invierno";
            objeto.defensa = 5;
            objeto.resistenciaFrio = 15;
            break;

        case VarianteRopa::GuantesMilitares:
            objeto.tipo = TipoObjeto::Guantes;
            objeto.nombre = "Guantes militares";
            objeto.defensa = 10;
            objeto.fuerza = 2;
            break;


        case VarianteRopa::BrazalesDeCuero:
            objeto.tipo = TipoObjeto::Brazales;
            objeto.nombre = "Brazales de cuero";
            objeto.defensa = 8;
            break;

        case VarianteRopa::BrazalesReforzados:
            objeto.tipo = TipoObjeto::Brazales;
            objeto.nombre = "Brazales reforzados";
            objeto.defensa = 15;
            objeto.defensaCorte = 12;
            break;

        case VarianteRopa::BrazalesDeTrabajo:
            objeto.tipo = TipoObjeto::Brazales;
            objeto.nombre = "Brazales de trabajo";
            objeto.defensa = 10;
            objeto.herreria = 3;
            objeto.carpinteria = 3;
            break;

        case VarianteRopa::BrazalesMilitares:
            objeto.tipo = TipoObjeto::Brazales;
            objeto.nombre = "Brazales militares";
            objeto.defensa = 18;
            objeto.defensaCorte = 15;
            objeto.fuerza = 2;
            break;


        // ====================================
        // GREBAS
        // ====================================

        case VarianteRopa::GrebasDeCuero:
            objeto.tipo = TipoObjeto::Grebas;
            objeto.nombre = "Grebas de cuero";
            objeto.defensa = 8;
            break;

        case VarianteRopa::GrebasReforzadas:
            objeto.tipo = TipoObjeto::Grebas;
            objeto.nombre = "Grebas reforzadas";
            objeto.defensa = 15;
            break;

        case VarianteRopa::GrebasMilitares:
            objeto.tipo = TipoObjeto::Grebas;
            objeto.nombre = "Grebas militares";
            objeto.defensa = 20;
            objeto.resistencia = 3;
            break;


        // ====================================
        // BOTAS
        // ====================================

        case VarianteRopa::BotasSimples:
            objeto.tipo = TipoObjeto::Botas;
            objeto.nombre = "Botas simples";
            objeto.defensa = 4;
            objeto.velocidad = 2;
            break;

        case VarianteRopa::BotasDeTrabajo:
            objeto.tipo = TipoObjeto::Botas;
            objeto.nombre = "Botas de trabajo";
            objeto.defensa = 8;
            objeto.resistencia = 3;
            break;

        case VarianteRopa::BotasDeCazador:
            objeto.tipo = TipoObjeto::Botas;
            objeto.nombre = "Botas de cazador";
            objeto.sigilo = 5;
            objeto.caza = 3;
            objeto.exploracion = 3;
            break;

        case VarianteRopa::BotasDeInvierno:
            objeto.tipo = TipoObjeto::Botas;
            objeto.nombre = "Botas de invierno";
            objeto.defensa = 8;
            objeto.resistenciaFrio = 20;
            break;

        case VarianteRopa::BotasMilitares:
            objeto.tipo = TipoObjeto::Botas;
            objeto.nombre = "Botas militares";
            objeto.defensa = 12;
            objeto.velocidad = 4;
            objeto.resistencia = 4;
            break;


        // ====================================
        // ZAPATOS
        // ====================================

        case VarianteRopa::ZapatosSimples:
            objeto.tipo = TipoObjeto::Zapatos;
            objeto.nombre = "Zapatos simples";
            objeto.velocidad = 2;
            break;

        case VarianteRopa::ZapatosDeTrabajo:
            objeto.tipo = TipoObjeto::Zapatos;
            objeto.nombre = "Zapatos de trabajo";
            objeto.resistencia = 2;
            break;

        case VarianteRopa::ZapatosElegantes:
            objeto.tipo = TipoObjeto::Zapatos;
            objeto.nombre = "Zapatos elegantes";
            objeto.carisma = 5;
            objeto.prestigio = 4;
            break;

        case VarianteRopa::ZapatosMilitares:
            objeto.tipo = TipoObjeto::Zapatos;
            objeto.nombre = "Zapatos militares";
            objeto.defensa = 5;
            objeto.velocidad = 3;
            break;


        // ====================================
        // CABEZA
        // ====================================

        case VarianteRopa::SombreroSimple:
            objeto.tipo = TipoObjeto::Sombrero;
            objeto.nombre = "Sombrero simple";
            objeto.percepcion = 2;
            break;

        case VarianteRopa::SombreroDeCampesino:
            objeto.tipo = TipoObjeto::Sombrero;
            objeto.nombre = "Sombrero de campesino";
            objeto.percepcion = 3;
            objeto.agricultura = 3;
            break;

        case VarianteRopa::SombreroElegante:
            objeto.tipo = TipoObjeto::Sombrero;
            objeto.nombre = "Sombrero elegante";
            objeto.carisma = 7;
            objeto.prestigio = 8;
            break;

        case VarianteRopa::SombreroDeViaje:
            objeto.tipo = TipoObjeto::Sombrero;
            objeto.nombre = "Sombrero de viaje";
            objeto.percepcion = 5;
            objeto.exploracion = 3;
            break;

        case VarianteRopa::SombreroMilitar:
            objeto.tipo = TipoObjeto::Sombrero;
            objeto.nombre = "Sombrero militar";
            objeto.percepcion = 4;
            objeto.prestigio = 5;
            break;


        case VarianteRopa::GorroSimple:
            objeto.tipo = TipoObjeto::Gorro;
            objeto.nombre = "Gorro simple";
            objeto.resistenciaFrio = 5;
            break;

        case VarianteRopa::GorroDeInvierno:
            objeto.tipo = TipoObjeto::Gorro;
            objeto.nombre = "Gorro de invierno";
            objeto.resistenciaFrio = 20;
            break;

        case VarianteRopa::GorroDeTrabajo:
            objeto.tipo = TipoObjeto::Gorro;
            objeto.nombre = "Gorro de trabajo";
            objeto.defensa = 3;
            objeto.resistencia = 2;
            break;

        case VarianteRopa::GorroMilitar:
            objeto.tipo = TipoObjeto::Gorro;
            objeto.nombre = "Gorro militar";
            objeto.defensa = 5;
            objeto.prestigio = 3;
            break;


        case VarianteRopa::CapuchaSimple:
            objeto.tipo = TipoObjeto::Capucha;
            objeto.nombre = "Capucha simple";
            objeto.sigilo = 3;
            break;

        case VarianteRopa::CapuchaDeCazador:
            objeto.tipo = TipoObjeto::Capucha;
            objeto.nombre = "Capucha de cazador";
            objeto.sigilo = 10;
            objeto.caza = 5;
            objeto.exploracion = 4;
            break;

        case VarianteRopa::CapuchaDeViaje:
            objeto.tipo = TipoObjeto::Capucha;
            objeto.nombre = "Capucha de viaje";
            objeto.sigilo = 6;
            objeto.exploracion = 6;
            objeto.resistenciaFrio = 10;
            break;

        case VarianteRopa::CapuchaMilitar:
            objeto.tipo = TipoObjeto::Capucha;
            objeto.nombre = "Capucha militar";
            objeto.defensa = 7;
            objeto.sigilo = 3;
            break;


        // ====================================
        // DELANTALES
        // ====================================

        case VarianteRopa::DelantalDeHerrero:
            objeto.tipo = TipoObjeto::Delantal;
            objeto.nombre = "Delantal de herrero";
            objeto.defensa = 10;
            objeto.resistenciaCalor = 25;
            objeto.herreria = 8;
            break;

        case VarianteRopa::DelantalDeCarpintero:
            objeto.tipo = TipoObjeto::Delantal;
            objeto.nombre = "Delantal de carpintero";
            objeto.defensa = 8;
            objeto.carpinteria = 8;
            break;

        case VarianteRopa::DelantalDeCocinero:
            objeto.tipo = TipoObjeto::Delantal;
            objeto.nombre = "Delantal de cocinero";
            objeto.defensa = 5;
            objeto.resistenciaCalor = 15;
            objeto.cocina = 8;
            break;

        case VarianteRopa::DelantalDeArtesano:
            objeto.tipo = TipoObjeto::Delantal;
            objeto.nombre = "Delantal de artesano";
            objeto.defensa = 6;
            objeto.costura = 5;
            break;


        // ====================================
        // PROFESIONES
        // ====================================

        case VarianteRopa::RopaDeCampesino:
            objeto.tipo = TipoObjeto::Camisa;
            objeto.nombre = "Ropa de campesino";
            objeto.defensa = 5;
            objeto.agricultura = 8;
            break;

        case VarianteRopa::RopaDeGranjero:
            objeto.tipo = TipoObjeto::Camisa;
            objeto.nombre = "Ropa de granjero";
            objeto.defensa = 7;
            objeto.agricultura = 10;
            objeto.resistencia = 3;
            break;

        case VarianteRopa::RopaDeCriador:
            objeto.tipo = TipoObjeto::Camisa;
            objeto.nombre = "Ropa de criador";
            objeto.defensa = 6;
            objeto.agricultura = 6;
            objeto.resistencia = 4;
            break;

        case VarianteRopa::RopaDeLenador:
            objeto.tipo = TipoObjeto::Camisa;
            objeto.nombre = "Ropa de leñador";
            objeto.defensa = 12;
            objeto.fuerza = 5;
            objeto.resistencia = 7;
            break;

        case VarianteRopa::RopaDeMinero:
            objeto.tipo = TipoObjeto::Camisa;
            objeto.nombre = "Ropa de minero";
            objeto.defensa = 15;
            objeto.mineria = 10;
            objeto.resistencia = 5;
            break;

        case VarianteRopa::RopaDeCantero:
            objeto.tipo = TipoObjeto::Camisa;
            objeto.nombre = "Ropa de cantero";
            objeto.defensa = 13;
            objeto.canteria = 10;
            objeto.fuerza = 4;
            break;

        case VarianteRopa::RopaDeCazador:
            objeto.tipo = TipoObjeto::Camisa;
            objeto.nombre = "Ropa de cazador";
            objeto.defensa = 8;
            objeto.caza = 12;
            objeto.sigilo = 8;
            objeto.percepcion = 5;
            break;

        case VarianteRopa::RopaDePescador:
            objeto.tipo = TipoObjeto::Camisa;
            objeto.nombre = "Ropa de pescador";
            objeto.defensa = 7;
            objeto.pesca = 12;
            objeto.resistenciaAgua = 15;
            break;

        case VarianteRopa::RopaDeHerrero:
            objeto.tipo = TipoObjeto::Delantal;
            objeto.nombre = "Ropa de herrero";
            objeto.defensa = 12;
            objeto.herreria = 12;
            objeto.resistenciaCalor = 30;
            break;

        case VarianteRopa::RopaDeCarpintero:
            objeto.tipo = TipoObjeto::Delantal;
            objeto.nombre = "Ropa de carpintero";
            objeto.defensa = 8;
            objeto.carpinteria = 12;
            break;

        case VarianteRopa::RopaDeAlbanil:
            objeto.tipo = TipoObjeto::Delantal;
            objeto.nombre = "Ropa de albañil";
            objeto.defensa = 12;
            objeto.canteria = 6;
            objeto.resistencia = 5;
            break;

        case VarianteRopa::RopaDeArtesano:
            objeto.tipo = TipoObjeto::Delantal;
            objeto.nombre = "Ropa de artesano";
            objeto.defensa = 6;
            objeto.costura = 10;
            break;

        case VarianteRopa::RopaDeAlfarero:
            objeto.tipo = TipoObjeto::Delantal;
            objeto.nombre = "Ropa de alfarero";
            objeto.defensa = 5;
            objeto.costura = 5;
            break;

        case VarianteRopa::RopaDeSastre:
            objeto.tipo = TipoObjeto::Camisa;
            objeto.nombre = "Ropa de sastre";
            objeto.carisma = 5;
            objeto.costura = 15;
            break;

        case VarianteRopa::RopaDeCurtidor:
            objeto.tipo = TipoObjeto::Delantal;
            objeto.nombre = "Ropa de curtidor";
            objeto.defensa = 10;
            objeto.resistenciaEnfermedades = 5;
            break;

        case VarianteRopa::RopaDeComerciante:
            objeto.tipo = TipoObjeto::Camisa;
            objeto.nombre = "Ropa de comerciante";
            objeto.carisma = 8;
            objeto.comercio = 10;
            objeto.prestigio = 5;
            break;

        case VarianteRopa::RopaDeMercader:
            objeto.tipo = TipoObjeto::Camisa;
            objeto.nombre = "Ropa de mercader";
            objeto.carisma = 12;
            objeto.comercio = 15;
            objeto.prestigio = 10;
            break;

        case VarianteRopa::RopaDeCocinero:
            objeto.tipo = TipoObjeto::Delantal;
            objeto.nombre = "Ropa de cocinero";
            objeto.resistenciaCalor = 20;
            objeto.cocina = 12;
            break;

        case VarianteRopa::RopaDeMedico:
            objeto.tipo = TipoObjeto::Tunica;
            objeto.nombre = "Ropa de medico";
            objeto.medicina = 15;
            objeto.resistenciaEnfermedades = 8;
            objeto.carisma = 3;
            break;

        case VarianteRopa::RopaDeEscriba:
            objeto.tipo = TipoObjeto::Tunica;
            objeto.nombre = "Ropa de escriba";
            objeto.inteligencia = 5;
            objeto.carisma = 3;
            break;

        case VarianteRopa::RopaDeSacerdote:
            objeto.tipo = TipoObjeto::Tunica;
            objeto.nombre = "Ropa de sacerdote";
            objeto.carisma = 10;
            objeto.prestigio = 15;
            break;

        case VarianteRopa::RopaDeSoldado:
            objeto.tipo = TipoObjeto::Camisa;
            objeto.nombre = "Ropa de soldado";
            objeto.defensa = 10;
            objeto.resistencia = 5;
            break;

        case VarianteRopa::RopaDeArquero:
            objeto.tipo = TipoObjeto::Camisa;
            objeto.nombre = "Ropa de arquero";
            objeto.defensa = 8;
            objeto.precision = 8;
            objeto.percepcion = 5;
            break;

        case VarianteRopa::RopaDeLancero:
            objeto.tipo = TipoObjeto::Camisa;
            objeto.nombre = "Ropa de lancero";
            objeto.defensa = 12;
            objeto.fuerza = 4;
            break;

        case VarianteRopa::RopaDeCaballero:
            objeto.tipo = TipoObjeto::Camisa;
            objeto.nombre = "Ropa de caballero";
            objeto.defensa = 15;
            objeto.carisma = 8;
            objeto.prestigio = 20;
            break;

        case VarianteRopa::RopaDeGuardia:
            objeto.tipo = TipoObjeto::Camisa;
            objeto.nombre = "Ropa de guardia";
            objeto.defensa = 14;
            objeto.resistencia = 5;
            break;

        case VarianteRopa::RopaDeExplorador:
            objeto.tipo = TipoObjeto::Camisa;
            objeto.nombre = "Ropa de explorador";
            objeto.defensa = 7;
            objeto.percepcion = 10;
            objeto.sigilo = 10;
            objeto.exploracion = 15;
            break;

        case VarianteRopa::RopaDeIngeniero:
            objeto.tipo = TipoObjeto::Camisa;
            objeto.nombre = "Ropa de ingeniero";
            objeto.defensa = 10;
            objeto.inteligencia = 8;
            objeto.canteria = 5;
            break;

        default:
            objeto.tipo = TipoObjeto::Camisa;
            objeto.nombre = "Ropa desconocida";
            break;
    }

    // ========================================
    // MATERIAL Y CALIDAD
    // ========================================

    double modificadorMaterial =
        (
            propiedades.resistencia * 0.35 +
            propiedades.flexibilidad * 0.40 +
            propiedades.dureza * 0.25
        ) / 100.0;

    objeto.defensa =
        static_cast<int>(
            objeto.defensa *
            modificadorMaterial *
            calidad
        );

    objeto.durabilidad =
        static_cast<int>(
            60 *
            (propiedades.resistencia / 100.0) *
            calidad
        );

    objeto.peso =
        std::max(
            1,
            static_cast<int>(
                propiedades.peso / 25.0
            )
        );

    objeto.valor =
        static_cast<int>(
            propiedades.valor *
            5 *
            calidad
        );

    // La ropa de gran calidad puede aumentar prestigio
    objeto.prestigio +=
        std::max(0, (objeto.calidad - 75) / 2);

    return objeto;
}


// ========================================
// CREAR JOYA
// ========================================

Objeto crearJoya(
    int id,
    VarianteJoya variante,
    const std::string& material,
    int habilidadArtesano,
    int artesanoID,
    const std::string& artesanoNombre
)
{
    Objeto objeto = crearObjetoBase();

    objeto.id = id;
    objeto.varianteJoya = variante;
    objeto.material = material;

    objeto.artesanoID = artesanoID;
    objeto.artesanoNombre = artesanoNombre;
    objeto.firma = artesanoNombre;

    objeto.calidad =
        calcularCalidad(habilidadArtesano);

    Recursos recursos;

    PropiedadesMaterial propiedades =
        recursos.obtenerPropiedades(material);

    double calidad =
        obtenerMultiplicadorCalidad(objeto.calidad);

    objeto.tipo = TipoObjeto::Anillo;

    switch (variante)
    {
        // ====================================
        // ANILLOS
        // ====================================

        case VarianteJoya::AnilloDeHierro:
            objeto.tipo = TipoObjeto::Anillo;
            objeto.nombre = "Anillo de hierro";
            objeto.defensa = 2;
            objeto.fuerza = 1;
            break;

        case VarianteJoya::AnilloDeCobre:
            objeto.tipo = TipoObjeto::Anillo;
            objeto.nombre = "Anillo de cobre";
            objeto.percepcion = 2;
            break;

        case VarianteJoya::AnilloDeBronce:
            objeto.tipo = TipoObjeto::Anillo;
            objeto.nombre = "Anillo de bronce";
            objeto.defensa = 3;
            objeto.resistencia = 2;
            break;

        case VarianteJoya::AnilloDePlata:
            objeto.tipo = TipoObjeto::Anillo;
            objeto.nombre = "Anillo de plata";
            objeto.carisma = 8;
            objeto.prestigio = 10;
            break;

        case VarianteJoya::AnilloDeOro:
            objeto.tipo = TipoObjeto::Anillo;
            objeto.nombre = "Anillo de oro";
            objeto.carisma = 12;
            objeto.prestigio = 20;
            break;

        case VarianteJoya::AnilloDeFamilia:
            objeto.tipo = TipoObjeto::Anillo;
            objeto.nombre = "Anillo de familia";
            objeto.carisma = 10;
            objeto.prestigio = 25;
            break;

        case VarianteJoya::AnilloDeNobleza:
            objeto.tipo = TipoObjeto::Anillo;
            objeto.nombre = "Anillo de nobleza";
            objeto.carisma = 20;
            objeto.prestigio = 40;
            break;


        // ====================================
        // COLLARES
        // ====================================

        case VarianteJoya::CollarSimple:
            objeto.tipo = TipoObjeto::Collar;
            objeto.nombre = "Collar simple";
            objeto.carisma = 3;
            break;

        case VarianteJoya::CollarDeCuero:
            objeto.tipo = TipoObjeto::Collar;
            objeto.nombre = "Collar de cuero";
            objeto.defensa = 2;
            objeto.resistencia = 1;
            break;

        case VarianteJoya::CollarDePlata:
            objeto.tipo = TipoObjeto::Collar;
            objeto.nombre = "Collar de plata";
            objeto.carisma = 10;
            objeto.prestigio = 15;
            break;

        case VarianteJoya::CollarDeOro:
            objeto.tipo = TipoObjeto::Collar;
            objeto.nombre = "Collar de oro";
            objeto.carisma = 15;
            objeto.prestigio = 30;
            break;

        case VarianteJoya::CollarDePerlas:
            objeto.tipo = TipoObjeto::Collar;
            objeto.nombre = "Collar de perlas";
            objeto.carisma = 18;
            objeto.prestigio = 35;
            break;

        case VarianteJoya::CollarDeFamilia:
            objeto.tipo = TipoObjeto::Collar;
            objeto.nombre = "Collar de familia";
            objeto.carisma = 12;
            objeto.prestigio = 30;
            break;


        // ====================================
        // AMULETOS
        // ====================================

        case VarianteJoya::AmuletoSimple:
            objeto.tipo = TipoObjeto::Amuleto;
            objeto.nombre = "Amuleto simple";
            objeto.resistenciaEnfermedades = 3;
            break;

        case VarianteJoya::AmuletoReligioso:
            objeto.tipo = TipoObjeto::Amuleto;
            objeto.nombre = "Amuleto religioso";
            objeto.carisma = 5;
            objeto.prestigio = 10;
            objeto.resistenciaEnfermedades = 5;
            break;

        case VarianteJoya::AmuletoDeGuerra:
            objeto.tipo = TipoObjeto::Amuleto;
            objeto.nombre = "Amuleto de guerra";
            objeto.fuerza = 3;
            objeto.resistencia = 5;
            objeto.prestigio = 10;
            break;

        case VarianteJoya::AmuletoDeFamilia:
            objeto.tipo = TipoObjeto::Amuleto;
            objeto.nombre = "Amuleto de familia";
            objeto.carisma = 8;
            objeto.prestigio = 25;
            break;

        default:
            objeto.nombre = "Joya desconocida";
            break;
    }

    // ========================================
    // MATERIAL
    // ========================================

    objeto.valor =
        static_cast<int>(
            propiedades.valor *
            20 *
            calidad
        );

    objeto.durabilidad =
        static_cast<int>(
            40 *
            calidad
        );

    objeto.peso =
        std::max(
            1,
            static_cast<int>(
                propiedades.peso / 100.0
            )
        );

    // Las joyas de gran calidad son más prestigiosas
    objeto.prestigio +=
        std::max(0, (objeto.calidad - 70) / 2);

    return objeto;
}


// ========================================
// NOMBRE DE ARMA
// ========================================

std::string obtenerNombreVariante(
    VarianteArma variante
)
{
    switch (variante)
    {
        case VarianteArma::EspadaCorta: return "Espada corta";
        case VarianteArma::EspadaLarga: return "Espada larga";
        case VarianteArma::EspadaBastarda: return "Espada bastarda";
        case VarianteArma::Mandoble: return "Mandoble";
        case VarianteArma::Estoque: return "Estoque";
        case VarianteArma::Sable: return "Sable";

        case VarianteArma::LanzaSimple: return "Lanza";
        case VarianteArma::Pica: return "Pica";
        case VarianteArma::Jabalina: return "Jabalina";
        case VarianteArma::Alabarda: return "Alabarda";

        case VarianteArma::MazaLigera: return "Maza ligera";
        case VarianteArma::MazaPesada: return "Maza pesada";
        case VarianteArma::MazaConPuas: return "Maza con puas";
        case VarianteArma::Mayal: return "Mayal";

        case VarianteArma::HachaDeMano: return "Hacha de mano";
        case VarianteArma::HachaDeBatalla: return "Hacha de batalla";
        case VarianteArma::HachaDanesa: return "Hacha danesa";
        case VarianteArma::HachaDeDosManos: return "Hacha de dos manos";

        case VarianteArma::ArcoCorto: return "Arco corto";
        case VarianteArma::ArcoLargo: return "Arco largo";
        case VarianteArma::ArcoRecurvo: return "Arco recurvo";

        case VarianteArma::BallestaLigera: return "Ballesta ligera";
        case VarianteArma::BallestaPesada: return "Ballesta pesada";
        case VarianteArma::BallestaDeGuerra: return "Ballesta de guerra";

        case VarianteArma::Daga: return "Daga";
        case VarianteArma::Estilete: return "Estilete";

        case VarianteArma::MartilloDeGuerra: return "Martillo de guerra";
        case VarianteArma::MartilloPesado: return "Martillo pesado";

        default:
            return "Ninguna";
    }
}


// ========================================
// NOMBRE DE ESCUDO
// ========================================

std::string obtenerNombreVarianteEscudo(
    VarianteEscudo variante
)
{
    switch (variante)
    {
        case VarianteEscudo::Broquel: return "Broquel";
        case VarianteEscudo::EscudoRedondoPequeno: return "Escudo redondo pequeño";
        case VarianteEscudo::EscudoRedondo: return "Escudo redondo";
        case VarianteEscudo::EscudoRedondoGrande: return "Escudo redondo grande";
        case VarianteEscudo::EscudoOvalado: return "Escudo ovalado";
        case VarianteEscudo::EscudoOvaladoGrande: return "Escudo ovalado grande";
        case VarianteEscudo::EscudoDeCometa: return "Escudo de cometa";
        case VarianteEscudo::EscudoDeCometaGrande: return "Escudo de cometa grande";
        case VarianteEscudo::EscudoAlargado: return "Escudo alargado";
        case VarianteEscudo::EscudoAlargadoGrande: return "Escudo alargado grande";
        case VarianteEscudo::EscudoRectangular: return "Escudo rectangular";
        case VarianteEscudo::EscudoRectangularGrande: return "Escudo rectangular grande";
        case VarianteEscudo::EscudoDeTorre: return "Escudo de torre";
        case VarianteEscudo::EscudoDeTorreGrande: return "Escudo de torre grande";
        case VarianteEscudo::EscudoHeraldico: return "Escudo heraldico";
        case VarianteEscudo::EscudoDeGuerra: return "Escudo de guerra";
        case VarianteEscudo::EscudoCeremonial: return "Escudo ceremonial";

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
// NOMBRE DE ROPA
// ========================================

std::string obtenerNombreRopa(
    VarianteRopa variante
)
{
    switch (variante)
    {
        case VarianteRopa::CamisaSimple: return "Camisa simple";
        case VarianteRopa::CamisaDeTrabajo: return "Camisa de trabajo";
        case VarianteRopa::CamisaElegante: return "Camisa elegante";
        case VarianteRopa::CamisaMilitar: return "Camisa militar";

        case VarianteRopa::CamisonSimple: return "Camison simple";
        case VarianteRopa::CamisonDeInvierno: return "Camison de invierno";
        case VarianteRopa::CamisonMilitar: return "Camison militar";

        case VarianteRopa::PantalonesSimples: return "Pantalones simples";
        case VarianteRopa::PantalonesDeTrabajo: return "Pantalones de trabajo";
        case VarianteRopa::PantalonesDeCazador: return "Pantalones de cazador";
        case VarianteRopa::PantalonesMilitares: return "Pantalones militares";

        case VarianteRopa::CalzonesSimples: return "Calzones simples";
        case VarianteRopa::CalzonesDeTrabajo: return "Calzones de trabajo";
        case VarianteRopa::CalzonesMilitares: return "Calzones militares";

        case VarianteRopa::TunicaSimple: return "Tunica simple";
        case VarianteRopa::TunicaReligiosa: return "Tunica religiosa";
        case VarianteRopa::TunicaNoble: return "Tunica noble";
        case VarianteRopa::TunicaMilitar: return "Tunica militar";

        case VarianteRopa::CapaSimple: return "Capa simple";
        case VarianteRopa::CapaDeViaje: return "Capa de viaje";
        case VarianteRopa::CapaNoble: return "Capa noble";
        case VarianteRopa::CapaMilitar: return "Capa militar";

        case VarianteRopa::VestidoSimple: return "Vestido simple";
        case VarianteRopa::VestidoElegante: return "Vestido elegante";
        case VarianteRopa::VestidoNoble: return "Vestido noble";
        case VarianteRopa::VestidoMilitar: return "Vestido militar";

        case VarianteRopa::FaldaSimple: return "Falda simple";
        case VarianteRopa::FaldaDeTrabajo: return "Falda de trabajo";
        case VarianteRopa::FaldaNoble: return "Falda noble";
        case VarianteRopa::FaldaMilitar: return "Falda militar";

        case VarianteRopa::AbrigoSimple: return "Abrigo simple";
        case VarianteRopa::AbrigoDeInvierno: return "Abrigo de invierno";
        case VarianteRopa::AbrigoMilitar: return "Abrigo militar";

        case VarianteRopa::AbrigoDePielDeLobo: return "Abrigo de piel de lobo";
        case VarianteRopa::AbrigoDePielDeOso: return "Abrigo de piel de oso";
        case VarianteRopa::AbrigoDePielDeCiervo: return "Abrigo de piel de ciervo";
        case VarianteRopa::AbrigoDePielDeZorro: return "Abrigo de piel de zorro";
        case VarianteRopa::AbrigoDePielDeOveja: return "Abrigo de piel de oveja";
        case VarianteRopa::AbrigoDePielDeAlce: return "Abrigo de piel de alce";
        case VarianteRopa::AbrigoDePielMilitar: return "Abrigo de piel militar";

        case VarianteRopa::GuantesSimples: return "Guantes simples";
        case VarianteRopa::GuantesDeTrabajo: return "Guantes de trabajo";
        case VarianteRopa::GuantesDeCuero: return "Guantes de cuero";
        case VarianteRopa::GuantesDeInvierno: return "Guantes de invierno";
        case VarianteRopa::GuantesMilitares: return "Guantes militares";

        case VarianteRopa::BrazalesDeCuero: return "Brazales de cuero";
        case VarianteRopa::BrazalesReforzados: return "Brazales reforzados";
        case VarianteRopa::BrazalesDeTrabajo: return "Brazales de trabajo";
        case VarianteRopa::BrazalesMilitares: return "Brazales militares";

        case VarianteRopa::GrebasDeCuero: return "Grebas de cuero";
        case VarianteRopa::GrebasReforzadas: return "Grebas reforzadas";
        case VarianteRopa::GrebasMilitares: return "Grebas militares";

        case VarianteRopa::ZapatosSimples: return "Zapatos simples";
        case VarianteRopa::ZapatosDeTrabajo: return "Zapatos de trabajo";
        case VarianteRopa::ZapatosElegantes: return "Zapatos elegantes";
        case VarianteRopa::ZapatosMilitares: return "Zapatos militares";

        case VarianteRopa::BotasSimples: return "Botas simples";
        case VarianteRopa::BotasDeTrabajo: return "Botas de trabajo";
        case VarianteRopa::BotasDeCazador: return "Botas de cazador";
        case VarianteRopa::BotasDeInvierno: return "Botas de invierno";
        case VarianteRopa::BotasMilitares: return "Botas militares";

        case VarianteRopa::SombreroSimple: return "Sombrero simple";
        case VarianteRopa::SombreroDeCampesino: return "Sombrero de campesino";
        case VarianteRopa::SombreroElegante: return "Sombrero elegante";
        case VarianteRopa::SombreroDeViaje: return "Sombrero de viaje";
        case VarianteRopa::SombreroMilitar: return "Sombrero militar";

        case VarianteRopa::GorroSimple: return "Gorro simple";
        case VarianteRopa::GorroDeInvierno: return "Gorro de invierno";
        case VarianteRopa::GorroDeTrabajo: return "Gorro de trabajo";
        case VarianteRopa::GorroMilitar: return "Gorro militar";

        case VarianteRopa::CapuchaSimple: return "Capucha simple";
        case VarianteRopa::CapuchaDeCazador: return "Capucha de cazador";
        case VarianteRopa::CapuchaDeViaje: return "Capucha de viaje";
        case VarianteRopa::CapuchaMilitar: return "Capucha militar";

        case VarianteRopa::DelantalDeHerrero: return "Delantal de herrero";
        case VarianteRopa::DelantalDeCarpintero: return "Delantal de carpintero";
        case VarianteRopa::DelantalDeCocinero: return "Delantal de cocinero";
        case VarianteRopa::DelantalDeArtesano: return "Delantal de artesano";

        case VarianteRopa::RopaDeCampesino: return "Ropa de campesino";
        case VarianteRopa::RopaDeGranjero: return "Ropa de granjero";
        case VarianteRopa::RopaDeCriador: return "Ropa de criador";
        case VarianteRopa::RopaDeLenador: return "Ropa de leñador";
        case VarianteRopa::RopaDeMinero: return "Ropa de minero";
        case VarianteRopa::RopaDeCantero: return "Ropa de cantero";
        case VarianteRopa::RopaDeCazador: return "Ropa de cazador";
        case VarianteRopa::RopaDePescador: return "Ropa de pescador";
        case VarianteRopa::RopaDeHerrero: return "Ropa de herrero";
        case VarianteRopa::RopaDeCarpintero: return "Ropa de carpintero";
        case VarianteRopa::RopaDeAlbanil: return "Ropa de albañil";
        case VarianteRopa::RopaDeArtesano: return "Ropa de artesano";
        case VarianteRopa::RopaDeAlfarero: return "Ropa de alfarero";
        case VarianteRopa::RopaDeSastre: return "Ropa de sastre";
        case VarianteRopa::RopaDeCurtidor: return "Ropa de curtidor";
        case VarianteRopa::RopaDeComerciante: return "Ropa de comerciante";
        case VarianteRopa::RopaDeMercader: return "Ropa de mercader";
        case VarianteRopa::RopaDeCocinero: return "Ropa de cocinero";
        case VarianteRopa::RopaDeMedico: return "Ropa de medico";
        case VarianteRopa::RopaDeEscriba: return "Ropa de escriba";
        case VarianteRopa::RopaDeSacerdote: return "Ropa de sacerdote";
        case VarianteRopa::RopaDeSoldado: return "Ropa de soldado";
        case VarianteRopa::RopaDeArquero: return "Ropa de arquero";
        case VarianteRopa::RopaDeLancero: return "Ropa de lancero";
        case VarianteRopa::RopaDeCaballero: return "Ropa de caballero";
        case VarianteRopa::RopaDeGuardia: return "Ropa de guardia";
        case VarianteRopa::RopaDeExplorador: return "Ropa de explorador";
        case VarianteRopa::RopaDeIngeniero: return "Ropa de ingeniero";

        default:
            return "Ninguna";
    }
}


// ========================================
// NOMBRE DE JOYA
// ========================================

std::string obtenerNombreJoya(
    VarianteJoya variante
)
{
    switch (variante)
    {
        case VarianteJoya::AnilloDeHierro:
            return "Anillo de hierro";

        case VarianteJoya::AnilloDeCobre:
            return "Anillo de cobre";

        case VarianteJoya::AnilloDeBronce:
            return "Anillo de bronce";

        case VarianteJoya::AnilloDePlata:
            return "Anillo de plata";

        case VarianteJoya::AnilloDeOro:
            return "Anillo de oro";

        case VarianteJoya::AnilloDeFamilia:
            return "Anillo de familia";

        case VarianteJoya::AnilloDeNobleza:
            return "Anillo de nobleza";

        case VarianteJoya::CollarSimple:
            return "Collar simple";

        case VarianteJoya::CollarDeCuero:
            return "Collar de cuero";

        case VarianteJoya::CollarDePlata:
            return "Collar de plata";

        case VarianteJoya::CollarDeOro:
            return "Collar de oro";

        case VarianteJoya::CollarDePerlas:
            return "Collar de perlas";

        case VarianteJoya::CollarDeFamilia:
            return "Collar de familia";

        case VarianteJoya::AmuletoSimple:
            return "Amuleto simple";

        case VarianteJoya::AmuletoReligioso:
            return "Amuleto religioso";

        case VarianteJoya::AmuletoDeGuerra:
            return "Amuleto de guerra";

        case VarianteJoya::AmuletoDeFamilia:
            return "Amuleto de familia";

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
              << objeto.id << "\n";

    std::cout << "Nombre: "
              << objeto.nombre << "\n";

    std::cout << "Material: "
              << objeto.material << "\n";

    std::cout << "Calidad: "
              << objeto.calidad << "/100\n";

    std::cout << "\n--- DEFENSA ---\n";

    std::cout << "Defensa: "
              << objeto.defensa << "\n";

    std::cout << "Defensa corte: "
              << objeto.defensaCorte << "\n";

    std::cout << "Defensa perforacion: "
              << objeto.defensaPerforacion << "\n";

    std::cout << "Defensa golpe: "
              << objeto.defensaGolpe << "\n";

    std::cout << "Defensa proyectiles: "
              << objeto.defensaProyectiles << "\n";

    std::cout << "\n--- ATRIBUTOS ---\n";

    std::cout << "Fuerza: "
              << objeto.fuerza << "\n";

    std::cout << "Velocidad: "
              << objeto.velocidad << "\n";

    std::cout << "Resistencia: "
              << objeto.resistencia << "\n";

    std::cout << "Percepcion: "
              << objeto.percepcion << "\n";

    std::cout << "Inteligencia: "
              << objeto.inteligencia << "\n";

    std::cout << "Carisma: "
              << objeto.carisma << "\n";

    std::cout << "Prestigio: "
              << objeto.prestigio << "\n";

    std::cout << "Sigilo: "
              << objeto.sigilo << "\n";

    std::cout << "\n--- SUPERVIVENCIA ---\n";

    std::cout << "Resistencia al frio: "
              << objeto.resistenciaFrio << "\n";

    std::cout << "Resistencia al calor: "
              << objeto.resistenciaCalor << "\n";

    std::cout << "Resistencia al agua: "
              << objeto.resistenciaAgua << "\n";

    std::cout << "Resistencia enfermedades: "
              << objeto.resistenciaEnfermedades << "\n";

    std::cout << "\n--- COMBATE ---\n";

    std::cout << "Daño: "
              << objeto.daño << "\n";

    std::cout << "Precision: "
              << objeto.precision << "\n";

    std::cout << "Alcance: "
              << objeto.alcance << "\n";

    std::cout << "Penetracion: "
              << objeto.penetracion << "\n";

    std::cout << "Bloqueo: "
              << objeto.bloqueo << "\n";

    std::cout << "Cobertura: "
              << objeto.cobertura << "\n";

    std::cout << "Estabilidad: "
              << objeto.estabilidad << "\n";

    std::cout << "\n--- PROFESIONES ---\n";

    std::cout << "Agricultura: "
              << objeto.agricultura << "\n";

    std::cout << "Herreria: "
              << objeto.herreria << "\n";

    std::cout << "Carpinteria: "
              << objeto.carpinteria << "\n";

    std::cout << "Mineria: "
              << objeto.mineria << "\n";

    std::cout << "Canteria: "
              << objeto.canteria << "\n";

    std::cout << "Caza: "
              << objeto.caza << "\n";

    std::cout << "Pesca: "
              << objeto.pesca << "\n";

    std::cout << "Comercio: "
              << objeto.comercio << "\n";

    std::cout << "Medicina: "
              << objeto.medicina << "\n";

    std::cout << "Exploracion: "
              << objeto.exploracion << "\n";

    std::cout << "Cocina: "
              << objeto.cocina << "\n";

    std::cout << "Costura: "
              << objeto.costura << "\n";

    std::cout << "\n--- FISICAS ---\n";

    std::cout << "Durabilidad: "
              << objeto.durabilidad << "\n";

    std::cout << "Peso: "
              << objeto.peso << "\n";

    std::cout << "Valor: "
              << objeto.valor << "\n";

    std::cout << "\n--- ARTESANO ---\n";

    std::cout << "ID artesano: "
              << objeto.artesanoID << "\n";

    std::cout << "Artesano: "
              << objeto.artesanoNombre << "\n";

    std::cout << "Firma: "
              << objeto.firma << "\n";

    std::cout << "============================\n";
}