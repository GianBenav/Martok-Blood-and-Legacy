#pragma once

#include <string>

// ============================================================
// TIPOS DE OBJETOS
// ============================================================

enum class TipoObjeto
{
    // ARMAS
    Espada,
    Lanza,
    Maza,
    Hacha,
    Daga,
    Martillo,

    // ARMAS A DISTANCIA
    Arco,
    Ballesta,

    // ESCUDOS
    Escudo,

    // ARMADURAS
    Armadura,
    Casco,
    Pechera,
    Guantes,
    Brazales,
    Grebas,
    Botas,
    ArmaduraCompleta,

    // ROPA
    Camisa,
    Camison,
    Pantalones,
    Calzones,
    Tunica,
    Capa,
    Vestido,
    Falda,
    Abrigo,
    AbrigoDePieles,
    Delantal,
    Sombrero,
    Gorro,
    Capucha,
    Zapatos,

    // JOYERIA
    Anillo,
    Collar,
    Amuleto,

    // HERRAMIENTAS
    HachaTrabajo,
    Pico,
    MartilloTrabajo,
    Azada,
    Pala,
    Sierra
};


// ============================================================
// VARIANTES DE ARMAS
// ============================================================

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
    LanzaSimple,
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


// ============================================================
// VARIANTES DE ESCUDOS
// ============================================================

enum class VarianteEscudo
{
    Ninguno,

    Broquel,

    EscudoRedondoPequeno,
    EscudoRedondo,
    EscudoRedondoGrande,

    EscudoOvalado,
    EscudoOvaladoGrande,

    EscudoDeCometa,
    EscudoDeCometaGrande,

    EscudoAlargado,
    EscudoAlargadoGrande,

    EscudoRectangular,
    EscudoRectangularGrande,

    EscudoDeTorre,
    EscudoDeTorreGrande,

    EscudoHeraldico,
    EscudoDeGuerra,
    EscudoCeremonial
};


// ============================================================
// VARIANTES DE ARMADURA
// ============================================================

enum class VarianteArmadura
{
    Ninguna,

    ArmaduraDeCuero,
    ArmaduraDeCueroReforzado,

    Gambeson,

    CotaDeMalla,
    CotaDeMallaPesada,

    ArmaduraDeEscamas,

    ArmaduraDePlacas,
    ArmaduraDePlacasPesada,

    ArmaduraDeGuerra
};


// ============================================================
// VARIANTES DE ROPA
// ============================================================

enum class VarianteRopa
{
    Ninguna,

    // --------------------------------------------------------
    // CAMISAS
    // --------------------------------------------------------

    CamisaSimple,
    CamisaDeTrabajo,
    CamisaElegante,
    CamisaMilitar,

    // --------------------------------------------------------
    // CAMISON
    // --------------------------------------------------------

    CamisonSimple,
    CamisonDeInvierno,
    CamisonMilitar,

    // --------------------------------------------------------
    // PANTALONES
    // --------------------------------------------------------

    PantalonesSimples,
    PantalonesDeTrabajo,
    PantalonesDeCazador,
    PantalonesMilitares,

    // --------------------------------------------------------
    // CALZONES
    // --------------------------------------------------------

    CalzonesSimples,
    CalzonesDeTrabajo,
    CalzonesMilitares,

    // --------------------------------------------------------
    // TUNICAS
    // --------------------------------------------------------

    TunicaSimple,
    TunicaReligiosa,
    TunicaNoble,
    TunicaMilitar,

    // --------------------------------------------------------
    // CAPAS
    // --------------------------------------------------------

    CapaSimple,
    CapaDeViaje,
    CapaNoble,
    CapaMilitar,

    // --------------------------------------------------------
    // VESTIDOS
    // --------------------------------------------------------

    VestidoSimple,
    VestidoElegante,
    VestidoNoble,
    VestidoMilitar,

    // --------------------------------------------------------
    // FALDAS
    // --------------------------------------------------------

    FaldaSimple,
    FaldaDeTrabajo,
    FaldaNoble,
    FaldaMilitar,

    // --------------------------------------------------------
    // ABRIGOS
    // --------------------------------------------------------

    AbrigoSimple,
    AbrigoDeInvierno,
    AbrigoMilitar,

    // --------------------------------------------------------
    // ABRIGOS DE PIEL
    // --------------------------------------------------------

    AbrigoDePielDeLobo,
    AbrigoDePielDeOso,
    AbrigoDePielDeCiervo,
    AbrigoDePielDeZorro,
    AbrigoDePielDeOveja,
    AbrigoDePielDeAlce,
    AbrigoDePielMilitar,

    // --------------------------------------------------------
    // GUANTES
    // --------------------------------------------------------

    GuantesSimples,
    GuantesDeTrabajo,
    GuantesDeCuero,
    GuantesDeInvierno,
    GuantesMilitares,

    // --------------------------------------------------------
    // BRAZALES
    // --------------------------------------------------------

    BrazalesDeCuero,
    BrazalesReforzados,
    BrazalesDeTrabajo,
    BrazalesMilitares,

    // --------------------------------------------------------
    // GREBAS
    // --------------------------------------------------------

    GrebasDeCuero,
    GrebasReforzadas,
    GrebasMilitares,

    // --------------------------------------------------------
    // ZAPATOS
    // --------------------------------------------------------

    ZapatosSimples,
    ZapatosDeTrabajo,
    ZapatosElegantes,
    ZapatosMilitares,

    // --------------------------------------------------------
    // BOTAS
    // --------------------------------------------------------

    BotasSimples,
    BotasDeTrabajo,
    BotasDeCazador,
    BotasDeInvierno,
    BotasMilitares,

    // --------------------------------------------------------
    // SOMBREROS
    // --------------------------------------------------------

    SombreroSimple,
    SombreroDeCampesino,
    SombreroElegante,
    SombreroDeViaje,
    SombreroMilitar,

    // --------------------------------------------------------
    // GORROS
    // --------------------------------------------------------

    GorroSimple,
    GorroDeInvierno,
    GorroDeTrabajo,
    GorroMilitar,

    // --------------------------------------------------------
    // CAPUCHAS
    // --------------------------------------------------------

    CapuchaSimple,
    CapuchaDeCazador,
    CapuchaDeViaje,
    CapuchaMilitar,

    // --------------------------------------------------------
    // DELANTALES
    // --------------------------------------------------------

    DelantalDeHerrero,
    DelantalDeCarpintero,
    DelantalDeCocinero,
    DelantalDeArtesano,

    // --------------------------------------------------------
    // ROPA PROFESIONAL
    // --------------------------------------------------------

    RopaDeCampesino,
    RopaDeGranjero,
    RopaDeCriador,

    RopaDeLenador,
    RopaDeMinero,
    RopaDeCantero,
    RopaDeCazador,
    RopaDePescador,

    RopaDeHerrero,
    RopaDeCarpintero,
    RopaDeAlbanil,
    RopaDeArtesano,
    RopaDeAlfarero,
    RopaDeSastre,
    RopaDeCurtidor,

    RopaDeComerciante,
    RopaDeMercader,

    RopaDeCocinero,
    RopaDeMedico,
    RopaDeEscriba,
    RopaDeSacerdote,

    // --------------------------------------------------------
    // ROPA MILITAR
    // --------------------------------------------------------

    RopaDeSoldado,
    RopaDeArquero,
    RopaDeLancero,
    RopaDeCaballero,
    RopaDeGuardia,
    RopaDeExplorador,
    RopaDeIngeniero
};


// ============================================================
// VARIANTES DE JOYERIA
// ============================================================

enum class VarianteJoya
{
    Ninguna,

    // --------------------------------------------------------
    // ANILLOS
    // --------------------------------------------------------

    AnilloDeHierro,
    AnilloDeCobre,
    AnilloDeBronce,
    AnilloDePlata,
    AnilloDeOro,

    AnilloDeFamilia,
    AnilloDeNobleza,

    // --------------------------------------------------------
    // COLLARES
    // --------------------------------------------------------

    CollarSimple,
    CollarDeCuero,
    CollarDePlata,
    CollarDeOro,
    CollarDePerlas,
    CollarDeFamilia,

    // --------------------------------------------------------
    // AMULETOS
    // --------------------------------------------------------

    AmuletoSimple,
    AmuletoReligioso,
    AmuletoDeGuerra,
    AmuletoDeFamilia
};


// ============================================================
// OBJETO
// ============================================================

struct Objeto
{
    // ========================================================
    // IDENTIDAD
    // ========================================================

    int id;
    std::string nombre;


    // ========================================================
    // CLASIFICACION
    // ========================================================

    TipoObjeto tipo;

    VarianteArma varianteArma;
    VarianteEscudo varianteEscudo;
    VarianteArmadura varianteArmadura;
    VarianteRopa varianteRopa;
    VarianteJoya varianteJoya;


    // ========================================================
    // MATERIAL
    // ========================================================

    std::string material;


    // ========================================================
    // CALIDAD
    // ========================================================

    int calidad;


    // ========================================================
    // DEFENSA
    // ========================================================

    int defensa;

    int defensaCorte;
    int defensaPerforacion;
    int defensaGolpe;
    int defensaProyectiles;


    // ========================================================
    // ATRIBUTOS DEL PERSONAJE
    // ========================================================

    int fuerza;
    int velocidad;
    int resistencia;

    int percepcion;
    int inteligencia;
    int carisma;
    int sigilo;


    // ========================================================
    // SUPERVIVENCIA
    // ========================================================

    int resistenciaFrio;
    int resistenciaCalor;
    int resistenciaAgua;
    int resistenciaEnfermedades;


    // ========================================================
    // COMBATE
    // ========================================================

    int daño;

    int precision;
    int alcance;
    int penetracion;

    int bloqueo;
    int cobertura;
    int estabilidad;


    // ========================================================
    // PROFESIONES
    // ========================================================

    int agricultura;
    int herreria;
    int carpinteria;
    int mineria;
    int canteria;

    int caza;
    int pesca;

    int comercio;
    int medicina;

    int exploracion;
    int cocina;
    int costura;


    // ========================================================
    // PROPIEDADES FISICAS
    // ========================================================

    int durabilidad;
    int peso;


    // ========================================================
    // ECONOMIA
    // ========================================================

    int valor;


    // ========================================================
    // PRESTIGIO
    // ========================================================

    int prestigio;


    // ========================================================
    // ARTESANO
    // ========================================================

    int artesanoID;
    std::string artesanoNombre;

    // Firma permanente del creador
    std::string firma;
};


// ============================================================
// CREAR ARMAS
// ============================================================

Objeto crearArma(
    int id,
    VarianteArma variante,
    const std::string& material,
    int habilidadArtesano,
    int artesanoID,
    const std::string& artesanoNombre
);


// ============================================================
// CREAR ESCUDOS
// ============================================================

Objeto crearEscudo(
    int id,
    VarianteEscudo variante,
    const std::string& material,
    int habilidadArtesano,
    int artesanoID,
    const std::string& artesanoNombre
);


// ============================================================
// CREAR ARMADURAS
// ============================================================

Objeto crearArmadura(
    int id,
    VarianteArmadura variante,
    const std::string& material,
    int habilidadArtesano,
    int artesanoID,
    const std::string& artesanoNombre
);


// ============================================================
// CREAR ROPA
// ============================================================

Objeto crearRopa(
    int id,
    VarianteRopa variante,
    const std::string& material,
    int habilidadArtesano,
    int artesanoID,
    const std::string& artesanoNombre
);


// ============================================================
// CREAR JOYERIA
// ============================================================

Objeto crearJoya(
    int id,
    VarianteJoya variante,
    const std::string& material,
    int habilidadArtesano,
    int artesanoID,
    const std::string& artesanoNombre
);


// ============================================================
// NOMBRES
// ============================================================

std::string obtenerNombreVariante(
    VarianteArma variante
);

std::string obtenerNombreVarianteEscudo(
    VarianteEscudo variante
);

std::string obtenerNombreArmadura(
    VarianteArmadura variante
);

std::string obtenerNombreRopa(
    VarianteRopa variante
);

std::string obtenerNombreJoya(
    VarianteJoya variante
);


// ============================================================
// MOSTRAR OBJETO
// ============================================================

void mostrarObjeto(
    const Objeto& objeto
);