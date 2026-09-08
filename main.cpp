#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <algorithm>

using namespace std;

// ============================================================
// GENERADOR ALEATORIO
// ============================================================

random_device rd;
mt19937 generador(rd());

int aleatorio(int minimo, int maximo)
{
    uniform_int_distribution<int> distribucion(minimo, maximo);
    return distribucion(generador);
}

// ============================================================
// ENUMERACION DE PROFESIONES
// ============================================================

enum class Profesion
{
    Ninguna,
    Campesino,
    Herrero,
    Comerciante,
    Cazador,
    Soldado,
    Caballero,
    Artesano,
    Escriba
};

string nombreProfesion(Profesion profesion)
{
    switch (profesion)
    {
        case Profesion::Campesino:
            return "Campesino";

        case Profesion::Herrero:
            return "Herrero";

        case Profesion::Comerciante:
            return "Comerciante";

        case Profesion::Cazador:
            return "Cazador";

        case Profesion::Soldado:
            return "Soldado";

        case Profesion::Caballero:
            return "Caballero";

        case Profesion::Artesano:
            return "Artesano";

        case Profesion::Escriba:
            return "Escriba";

        default:
            return "Ninguna";
    }
}

// ============================================================
// PERSONAJE
// ============================================================

struct Personaje
{
    // --------------------------------------------------------
    // IDENTIDAD
    // --------------------------------------------------------

    int id;

    string nombre;
    string apellido;
    string sexo;

    // --------------------------------------------------------
    // EDAD
    // --------------------------------------------------------

    int edad;

    // --------------------------------------------------------
    // FAMILIA
    // --------------------------------------------------------

    int padreID;
    int madreID;
    int conyugeID;

    vector<int> hijos;

    // --------------------------------------------------------
    // ESTADISTICAS
    // --------------------------------------------------------

    int salud;
    int fuerza;
    int inteligencia;
    int agilidad;
    int belleza;

    int reputacion;
    int experiencia;

    // --------------------------------------------------------
    // FERTILIDAD
    // --------------------------------------------------------

    int fertilidadBase;

    // --------------------------------------------------------
    // ECONOMIA
    // --------------------------------------------------------

    int oro;
    int tierras;

    // --------------------------------------------------------
    // PROFESION
    // --------------------------------------------------------

    Profesion profesion;

    // --------------------------------------------------------
    // MILITAR
    // --------------------------------------------------------

    string rangoMilitar;

    // --------------------------------------------------------
    // ESTADO
    // --------------------------------------------------------

    bool vivo;

    int anoMuerte;

    bool herido;

    int gravedadHerida;

    bool enfermo;

    int gravedadEnfermedad;

    // --------------------------------------------------------
    // EMBARAZO
    // --------------------------------------------------------

    bool embarazada;

    int mesesEmbarazo;
};

// ============================================================
// BUSCAR PERSONAJE
// ============================================================

Personaje* buscarPersonaje(
    vector<Personaje>& familia,
    int id)
{
    for (Personaje& persona : familia)
    {
        if (persona.id == id)
        {
            return &persona;
        }
    }

    return nullptr;
}

// ============================================================
// ETAPA DE VIDA
// ============================================================

string calcularEtapaVida(int edad)
{
    if (edad < 3)
        return "Bebe";

    if (edad < 7)
        return "Nino pequeno";

    if (edad < 13)
        return "Nino";

    if (edad < 16)
        return "Adolescente";

    if (edad < 18)
        return "Joven";

    if (edad < 30)
        return "Adulto joven";

    if (edad < 50)
        return "Adulto";

    if (edad < 65)
        return "Adulto";

    if (edad < 80)
        return "Anciano";

    return "Anciano avanzado";
}

// ============================================================
// FERTILIDAD
// ============================================================

int calcularFertilidad(Personaje& persona)
{
    if (!persona.vivo)
        return 0;

    // --------------------------------------------------------
    // MUJER
    // --------------------------------------------------------

    if (persona.sexo == "Mujer")
    {
        if (persona.edad < 16)
            return 0;

        if (persona.edad <= 25)
            return persona.fertilidadBase;

        if (persona.edad <= 30)
            return max(0, persona.fertilidadBase - 10);

        if (persona.edad <= 35)
            return max(0, persona.fertilidadBase - 20);

        if (persona.edad <= 40)
            return max(0, persona.fertilidadBase - 35);

        if (persona.edad <= 45)
            return max(0, persona.fertilidadBase - 55);

        return 0;
    }

    // --------------------------------------------------------
    // HOMBRE
    // --------------------------------------------------------

    if (persona.sexo == "Hombre")
    {
        if (persona.edad < 16)
            return 0;

        if (persona.edad <= 65)
            return persona.fertilidadBase;

        if (persona.edad <= 70)
            return max(0, persona.fertilidadBase - 10);

        if (persona.edad <= 75)
            return max(0, persona.fertilidadBase - 25);

        if (persona.edad <= 80)
            return max(0, persona.fertilidadBase - 50);

        return 0;
    }

    return 0;
}

// ============================================================
// HERENCIA GENETICA
// ============================================================

int heredarEstadistica(
    int padre,
    int madre)
{
    int promedio = (padre + madre) / 2;

    int variacion = aleatorio(-10, 10);

    int resultado = promedio + variacion;

    if (resultado < 1)
        resultado = 1;

    if (resultado > 100)
        resultado = 100;

    return resultado;
}

// ============================================================
// HEREDAR FERTILIDAD
// ============================================================

int heredarFertilidad(
    int padre,
    int madre)
{
    int promedio = (padre + madre) / 2;

    int variacion = aleatorio(-8, 8);

    int resultado = promedio + variacion;

    if (resultado < 1)
        resultado = 1;

    if (resultado > 100)
        resultado = 100;

    return resultado;
}

// ============================================================
// RANGO MILITAR
// ============================================================

string calcularRangoMilitar(int experiencia)
{
    if (experiencia < 50)
        return "Escudero Recluta";

    if (experiencia < 100)
        return "Escudero";

    if (experiencia < 150)
        return "Escudero Avanzado";

    if (experiencia < 200)
        return "Recluta de Leva";

    if (experiencia < 300)
        return "Leva";

    if (experiencia < 400)
        return "Leva Avanzada";

    if (experiencia < 500)
        return "Recluta";

    if (experiencia < 700)
        return "Soldado";

    if (experiencia < 900)
        return "Soldado Avanzado";

    if (experiencia < 1200)
        return "Soldado Veterano";

    if (experiencia < 1600)
        return "Cabo";

    if (experiencia < 2000)
        return "Cabo Veterano";

    if (experiencia < 2500)
        return "Sargento";

    if (experiencia < 3000)
        return "Sargento Veterano";

    if (experiencia < 4000)
        return "Teniente";

    if (experiencia < 5000)
        return "Teniente Veterano";

    if (experiencia < 6500)
        return "Capitan";

    if (experiencia < 8000)
        return "Capitan Veterano";

    if (experiencia < 10000)
        return "Comandante";

    if (experiencia < 13000)
        return "Comandante Veterano";

    if (experiencia < 16000)
        return "General";

    if (experiencia < 20000)
        return "General Veterano";

    if (experiencia < 25000)
        return "Gran General";

    if (experiencia < 35000)
        return "Mariscal";

    return "Gran Mariscal";
}

// ============================================================
// CREAR PERSONAJE
// ============================================================

int crearPersonaje(
    vector<Personaje>& familia,
    string nombre,
    string apellido,
    string sexo,
    int edad,
    int padreID,
    int madreID,
    int salud,
    int fuerza,
    int inteligencia,
    int agilidad,
    int belleza,
    int fertilidad,
    int oro,
    int tierras,
    Profesion profesion)
{
    Personaje nuevo;

    nuevo.id = familia.size() + 1;

    nuevo.nombre = nombre;
    nuevo.apellido = apellido;
    nuevo.sexo = sexo;

    nuevo.edad = edad;

    nuevo.padreID = padreID;
    nuevo.madreID = madreID;
    nuevo.conyugeID = 0;

    nuevo.salud = salud;
    nuevo.fuerza = fuerza;
    nuevo.inteligencia = inteligencia;
    nuevo.agilidad = agilidad;
    nuevo.belleza = belleza;

    nuevo.fertilidadBase = fertilidad;

    nuevo.oro = oro;
    nuevo.tierras = tierras;

    nuevo.profesion = profesion;

    nuevo.experiencia = 0;
    nuevo.reputacion = 0;

    nuevo.rangoMilitar =
        calcularRangoMilitar(
            nuevo.experiencia);

    nuevo.vivo = true;

    nuevo.anoMuerte = 0;

    nuevo.herido = false;
    nuevo.gravedadHerida = 0;

    nuevo.enfermo = false;
    nuevo.gravedadEnfermedad = 0;

    nuevo.embarazada = false;
    nuevo.mesesEmbarazo = 0;

    familia.push_back(nuevo);

    // --------------------------------------------------------
    // REGISTRAR HIJO EN PADRE
    // --------------------------------------------------------

    if (padreID != 0)
    {
        Personaje* padre =
            buscarPersonaje(
                familia,
                padreID);

        if (padre != nullptr)
        {
            padre->hijos.push_back(
                nuevo.id);
        }
    }

    // --------------------------------------------------------
    // REGISTRAR HIJO EN MADRE
    // --------------------------------------------------------

    if (madreID != 0)
    {
        Personaje* madre =
            buscarPersonaje(
                familia,
                madreID);

        if (madre != nullptr)
        {
            madre->hijos.push_back(
                nuevo.id);
        }
    }

    return nuevo.id;
}

// ============================================================
// CASAMIENTO
// ============================================================

void casar(
    vector<Personaje>& familia,
    int personaID,
    int parejaID)
{
    Personaje* persona =
        buscarPersonaje(
            familia,
            personaID);

    Personaje* pareja =
        buscarPersonaje(
            familia,
            parejaID);

    if (persona == nullptr ||
        pareja == nullptr)
    {
        cout << "\nPersonaje no encontrado.\n";
        return;
    }

    if (!persona->vivo ||
        !pareja->vivo)
    {
        cout << "\nUno de los personajes esta muerto.\n";
        return;
    }

    if (persona->edad < 16 ||
        pareja->edad < 16)
    {
        cout << "\nAmbos deben tener al menos 16 anos.\n";
        return;
    }

    if (persona->conyugeID != 0 ||
        pareja->conyugeID != 0)
    {
        cout << "\nUno de ellos ya esta casado.\n";
        return;
    }

    persona->conyugeID =
        parejaID;

    pareja->conyugeID =
        personaID;

    persona->reputacion += 5;
    pareja->reputacion += 5;

    cout << "\n====================================\n";
    cout << "             MATRIMONIO\n";
    cout << "====================================\n";

    cout << persona->nombre
         << " "
         << persona->apellido
         << " se ha casado con "
         << pareja->nombre
         << " "
         << pareja->apellido
         << ".\n";
}

// ============================================================
// COMPATIBILIDAD
// ============================================================

int calcularCompatibilidad(
    Personaje& padre,
    Personaje& madre)
{
    int compatibilidad = 50;

    compatibilidad +=
        (padre.belleza +
         madre.belleza) / 20;

    compatibilidad +=
        (padre.salud +
         madre.salud) / 20;

    compatibilidad +=
        (padre.fertilidadBase +
         madre.fertilidadBase) / 20;

    if (compatibilidad > 100)
        compatibilidad = 100;

    if (compatibilidad < 1)
        compatibilidad = 1;

    return compatibilidad;
}

// ============================================================
// INTENTAR CONCEBIR
// ============================================================

void intentarTenerHijo(
    vector<Personaje>& familia,
    int padreID,
    int madreID)
{
    Personaje* padre =
        buscarPersonaje(
            familia,
            padreID);

    Personaje* madre =
        buscarPersonaje(
            familia,
            madreID);

    if (padre == nullptr ||
        madre == nullptr)
    {
        cout << "\nPadres no encontrados.\n";
        return;
    }

    if (!padre->vivo ||
        !madre->vivo)
    {
        cout << "\nUno de los padres esta muerto.\n";
        return;
    }

    if (padre->edad < 16 ||
        madre->edad < 16)
    {
        cout << "\nAmbos deben tener al menos 16 anos.\n";
        return;
    }

    if (calcularFertilidad(*padre) <= 0)
    {
        cout << "\nEl padre ya no es fertil.\n";
        return;
    }

    if (calcularFertilidad(*madre) <= 0)
    {
        cout << "\nLa madre ya no es fertil.\n";
        return;
    }

    if (madre->embarazada)
    {
        cout << "\nLa madre ya esta embarazada.\n";
        return;
    }

    int fertilidadPadre =
        calcularFertilidad(*padre);

    int fertilidadMadre =
        calcularFertilidad(*madre);

    int compatibilidad =
        calcularCompatibilidad(
            *padre,
            *madre);

    int probabilidad =
        (fertilidadPadre +
         fertilidadMadre +
         compatibilidad) / 3;

    int resultado =
        aleatorio(1, 100);

    cout << "\n====================================\n";
    cout << "        INTENTO DE CONCEPCION\n";
    cout << "====================================\n";

    cout << "Fertilidad padre: "
         << fertilidadPadre
         << "/100\n";

    cout << "Fertilidad madre: "
         << fertilidadMadre
         << "/100\n";

    cout << "Compatibilidad: "
         << compatibilidad
         << "/100\n";

    cout << "Probabilidad: "
         << probabilidad
         << "%\n";

    if (resultado <= probabilidad)
    {
        madre->embarazada = true;
        madre->mesesEmbarazo = 0;

        cout << "\n¡Embarazo confirmado!\n";
    }
    else
    {
        cout << "\nNo hubo concepcion.\n";
    }
}

// ============================================================
// NACIMIENTO
// ============================================================

void nacimiento(
    vector<Personaje>& familia,
    Personaje& madre,
    int padreID)
{
    Personaje* padre =
        buscarPersonaje(
            familia,
            padreID);

    if (padre == nullptr)
        return;

    string nombre;

    cout << "\n====================================\n";
    cout << "             NACIMIENTO\n";
    cout << "====================================\n";

    cout << "Nombre del bebe: ";
    cin >> nombre;

    string sexo;

    if (aleatorio(1, 2) == 1)
        sexo = "Hombre";
    else
        sexo = "Mujer";

    int salud =
        heredarEstadistica(
            padre->salud,
            madre.salud);

    int fuerza =
        heredarEstadistica(
            padre->fuerza,
            madre.fuerza);

    int inteligencia =
        heredarEstadistica(
            padre->inteligencia,
            madre.inteligencia);

    int agilidad =
        heredarEstadistica(
            padre->agilidad,
            madre.agilidad);

    int belleza =
        heredarEstadistica(
            padre->belleza,
            madre.belleza);

    int fertilidad =
        heredarFertilidad(
            padre->fertilidadBase,
            madre.fertilidadBase);

    crearPersonaje(
        familia,
        nombre,
        padre->apellido,
        sexo,
        0,
        padre->id,
        madre.id,
        salud,
        fuerza,
        inteligencia,
        agilidad,
        belleza,
        fertilidad,
        0,
        0,
        Profesion::Ninguna);

    madre.embarazada = false;
    madre.mesesEmbarazo = 0;

    cout << "\nHa nacido "
         << nombre
         << " "
         << padre->apellido
         << ".\n";

    cout << "Sexo: "
         << sexo
         << "\n";

    cout << "\nGENETICA\n";

    cout << "Salud: "
         << salud
         << "\n";

    cout << "Fuerza: "
         << fuerza
         << "\n";

    cout << "Inteligencia: "
         << inteligencia
         << "\n";

    cout << "Agilidad: "
         << agilidad
         << "\n";

    cout << "Belleza: "
         << belleza
         << "\n";

    cout << "Fertilidad: "
         << fertilidad
         << "\n";
}

// ============================================================
// AVANZAR EMBARAZOS
// ============================================================

void avanzarEmbarazos(
    vector<Personaje>& familia)
{
    for (Personaje& madre : familia)
    {
        if (!madre.vivo)
            continue;

        if (!madre.embarazada)
            continue;

        madre.mesesEmbarazo++;

        cout << "\n"
             << madre.nombre
             << " esta en el mes "
             << madre.mesesEmbarazo
             << "/9 del embarazo.\n";

        if (madre.mesesEmbarazo >= 9)
        {
            int padreID =
                madre.conyugeID;

            if (padreID != 0)
            {
                nacimiento(
                    familia,
                    madre,
                    padreID);
            }
            else
            {
                madre.embarazada = false;
                madre.mesesEmbarazo = 0;
            }
        }
    }
}

// ============================================================
// HEREDERO
// ============================================================

int elegirHeredero(
    vector<Personaje>& familia,
    Personaje& fallecido)
{
    // --------------------------------------------------------
    // PRIMERO: HIJOS
    // --------------------------------------------------------

    for (int hijoID :
         fallecido.hijos)
    {
        Personaje* hijo =
            buscarPersonaje(
                familia,
                hijoID);

        if (hijo != nullptr &&
            hijo->vivo)
        {
            return hijo->id;
        }
    }

    // --------------------------------------------------------
    // SEGUNDO: HERMANOS
    // --------------------------------------------------------

    if (fallecido.padreID != 0)
    {
        Personaje* padre =
            buscarPersonaje(
                familia,
                fallecido.padreID);

        if (padre != nullptr)
        {
            for (int hermanoID :
                 padre->hijos)
            {
                Personaje* hermano =
                    buscarPersonaje(
                        familia,
                        hermanoID);

                if (hermano != nullptr &&
                    hermano->vivo &&
                    hermano->id != fallecido.id)
                {
                    return hermano->id;
                }
            }
        }
    }

    return 0;
}

// ============================================================
// HERENCIA
// ============================================================

void repartirHerencia(
    vector<Personaje>& familia,
    Personaje& fallecido)
{
    int herederoID =
        elegirHeredero(
            familia,
            fallecido);

    if (herederoID == 0)
    {
        cout << "\nNo existe heredero.\n";
        return;
    }

    Personaje* heredero =
        buscarPersonaje(
            familia,
            herederoID);

    if (heredero == nullptr)
        return;

    heredero->oro +=
        fallecido.oro;

    heredero->tierras +=
        fallecido.tierras;

    cout << "\n====================================\n";
    cout << "              HERENCIA\n";
    cout << "====================================\n";

    cout << heredero->nombre
         << " "
         << heredero->apellido
         << " recibe la herencia de "
         << fallecido.nombre
         << ".\n";

    cout << "Oro heredado: "
         << fallecido.oro
         << "\n";

    cout << "Tierras heredadas: "
         << fallecido.tierras
         << "\n";
}

// ============================================================
// MUERTE
// ============================================================

void morir(
    vector<Personaje>& familia,
    int id,
    int ano)
{
    Personaje* persona =
        buscarPersonaje(
            familia,
            id);

    if (persona == nullptr)
        return;

    if (!persona->vivo)
        return;

    persona->vivo = false;
    persona->anoMuerte = ano;

    cout << "\n====================================\n";
    cout << "               MUERTE\n";
    cout << "====================================\n";

    cout << persona->nombre
         << " "
         << persona->apellido
         << " ha muerto a los "
         << persona->edad
         << " anos.\n";

    repartirHerencia(
        familia,
        *persona);
}

// ============================================================
// EVENTO DE ENFERMEDAD
// ============================================================

void eventoEnfermedad(
    Personaje& persona)
{
    if (!persona.vivo)
        return;

    int probabilidad =
        aleatorio(1, 100);

    if (probabilidad > 8)
        return;

    persona.enfermo = true;

    persona.gravedadEnfermedad =
        aleatorio(10, 50);

    persona.salud -=
        persona.gravedadEnfermedad / 2;

    if (persona.salud < 1)
        persona.salud = 1;

    cout << "\n"
         << persona.nombre
         << " ha enfermado.\n";

    cout << "Gravedad: "
         << persona.gravedadEnfermedad
         << "/100\n";
}

// ============================================================
// CURAR ENFERMEDAD
// ============================================================

void tratarEnfermedad(
    Personaje& persona)
{
    if (!persona.enfermo)
        return;

    int recuperacion =
        aleatorio(10, 30);

    persona.salud += recuperacion;

    if (persona.salud > 100)
        persona.salud = 100;

    persona.gravedadEnfermedad -=
        recuperacion;

    if (persona.gravedadEnfermedad <= 0)
    {
        persona.gravedadEnfermedad = 0;
        persona.enfermo = false;

        cout << persona.nombre
             << " se ha recuperado.\n";
    }
}

// ============================================================
// ENTRENAR
// ============================================================

void entrenar(
    Personaje& persona)
{
    if (!persona.vivo)
        return;

    if (persona.edad < 10)
    {
        cout << "\nEs demasiado joven para entrenar.\n";
        return;
    }

    int ganancia =
        aleatorio(10, 30);

    persona.experiencia +=
        ganancia;

    persona.fuerza +=
        aleatorio(1, 3);

    if (persona.fuerza > 100)
        persona.fuerza = 100;

    persona.rangoMilitar =
        calcularRangoMilitar(
            persona.experiencia);

    cout << "\n"
         << persona.nombre
         << " ha entrenado.\n";

    cout << "Experiencia ganada: "
         << ganancia
         << "\n";

    cout << "Experiencia total: "
         << persona.experiencia
         << "\n";

    cout << "Rango: "
         << persona.rangoMilitar
         << "\n";
}

// ============================================================
// PASAR ANO
// ============================================================

void pasarAno(
    vector<Personaje>& familia,
    int ano)
{
    cout << "\n====================================\n";
    cout << "          HA PASADO UN ANO\n";
    cout << "====================================\n";

    for (Personaje& persona : familia)
    {
        if (!persona.vivo)
            continue;

        persona.edad++;

        // ----------------------------------------------------
        // ENFERMEDAD
        // ----------------------------------------------------

        eventoEnfermedad(
            persona);

        if (persona.enfermo)
        {
            tratarEnfermedad(
                persona);
        }

        // ----------------------------------------------------
        // VEJEZ
        // ----------------------------------------------------

        if (persona.edad >= 80)
        {
            int probabilidad =
                10 +
                ((persona.edad - 80) * 5);

            if (probabilidad > 90)
                probabilidad = 90;

            if (aleatorio(1, 100) <= probabilidad)
            {
                morir(
                    familia,
                    persona.id,
                    ano);

                continue;
            }
        }

        // ----------------------------------------------------
        // SALUD MUY BAJA
        // ----------------------------------------------------

        if (persona.salud <= 10)
        {
            if (aleatorio(1, 100) <= 15)
            {
                morir(
                    familia,
                    persona.id,
                    ano);

                continue;
            }
        }
    }

    // --------------------------------------------------------
    // EMBARAZOS
    // --------------------------------------------------------

    avanzarEmbarazos(
        familia);
}

// ============================================================
// MOSTRAR PERSONAJE
// ============================================================

void mostrarPersonaje(
    vector<Personaje>& familia,
    int id)
{
    Personaje* persona =
        buscarPersonaje(
            familia,
            id);

    if (persona == nullptr)
    {
        cout << "\nPersonaje no encontrado.\n";
        return;
    }

    cout << "\n====================================\n";
    cout << "             PERSONAJE\n";
    cout << "====================================\n";

    cout << "\nID: "
         << persona->id;

    cout << "\nNombre: "
         << persona->nombre
         << " "
         << persona->apellido;

    cout << "\nSexo: "
         << persona->sexo;

    cout << "\nEdad: "
         << persona->edad;

    cout << "\nEtapa: "
         << calcularEtapaVida(
                persona->edad);

    cout << "\nEstado: ";

    if (persona->vivo)
        cout << "Vivo";
    else
        cout << "Fallecido";

    cout << "\n";

    if (!persona->vivo)
    {
        cout << "Ano de muerte: "
             << persona->anoMuerte
             << "\n";
    }

    // --------------------------------------------------------
    // ESTADISTICAS
    // --------------------------------------------------------

    cout << "\nESTADISTICAS\n";

    cout << "Salud: "
         << persona->salud
         << "/100\n";

    cout << "Fuerza: "
         << persona->fuerza
         << "/100\n";

    cout << "Inteligencia: "
         << persona->inteligencia
         << "/100\n";

    cout << "Agilidad: "
         << persona->agilidad
         << "/100\n";

    cout << "Belleza: "
         << persona->belleza
         << "/100\n";

    cout << "Reputacion: "
         << persona->reputacion
         << "\n";

    cout << "Experiencia: "
         << persona->experiencia
         << "\n";

    // --------------------------------------------------------
    // MILITAR
    // --------------------------------------------------------

    cout << "\nMILITAR\n";

    cout << "Rango: "
         << persona->rangoMilitar
         << "\n";

    // --------------------------------------------------------
    // PROFESION
    // --------------------------------------------------------

    cout << "\nPROFESION\n";

    cout << nombreProfesion(
        persona->profesion)
         << "\n";

    // --------------------------------------------------------
    // FERTILIDAD
    // --------------------------------------------------------

    cout << "\nFERTILIDAD\n";

    cout << "Fertilidad genetica: "
         << persona->fertilidadBase
         << "/100\n";

    cout << "Fertilidad actual: "
         << calcularFertilidad(
                *persona)
         << "/100\n";

    // --------------------------------------------------------
    // ECONOMIA
    // --------------------------------------------------------

    cout << "\nPATRIMONIO\n";

    cout << "Oro: "
         << persona->oro
         << "\n";

    cout << "Tierras: "
         << persona->tierras
         << "\n";

    // --------------------------------------------------------
    // ENFERMEDAD
    // --------------------------------------------------------

    if (persona->enfermo)
    {
        cout << "\nENFERMO\n";

        cout << "Gravedad: "
             << persona->gravedadEnfermedad
             << "/100\n";
    }

    // --------------------------------------------------------
    // EMBARAZO
    // --------------------------------------------------------

    if (persona->embarazada)
    {
        cout << "\nEMBARAZO\n";

        cout << "Mes: "
             << persona->mesesEmbarazo
             << "/9\n";
    }

    // --------------------------------------------------------
    // HIJOS
    // --------------------------------------------------------

    cout << "\nHIJOS: "
         << persona->hijos.size()
         << "\n";

    for (int hijoID :
         persona->hijos)
    {
        Personaje* hijo =
            buscarPersonaje(
                familia,
                hijoID);

        if (hijo != nullptr)
        {
            cout << "- "
                 << hijo->nombre
                 << " "
                 << hijo->apellido;

            cout << " | "
                 << hijo->edad
                 << " anos";

            if (!hijo->vivo)
                cout << " | Fallecido";

            cout << "\n";
        }
    }
}

// ============================================================
// MOSTRAR TODOS
// ============================================================

void mostrarTodos(
    vector<Personaje>& familia)
{
    cout << "\n====================================\n";
    cout << "        TODOS LOS PERSONAJES\n";
    cout << "====================================\n";

    for (Personaje& persona : familia)
    {
        cout << "\n[" << persona.id << "] ";

        cout << persona.nombre
             << " "
             << persona.apellido;

        cout << " | "
             << persona.edad
             << " anos";

        cout << " | ";

        if (persona.vivo)
            cout << "Vivo";
        else
            cout << "Fallecido";

        cout << "\n";
    }
}

// ============================================================
// MAIN
// ============================================================

int main()
{
    vector<Personaje> familia;

    // ========================================================
    // FAMILIA MARTOK
    // ========================================================

    int abuelo =
        crearPersonaje(
            familia,
            "William",
            "Martok",
            "Hombre",
            65,
            0,
            0,
            90,
            90,
            70,
            60,
            60,
            85,
            500,
            10,
            Profesion::Caballero
        );

    int abuela =
        crearPersonaje(
            familia,
            "Helena",
            "Martok",
            "Mujer",
            62,
            0,
            0,
            90,
            55,
            80,
            70,
            75,
            85,
            400,
            5,
            Profesion::Escriba
        );

    int padre =
        crearPersonaje(
            familia,
            "Edmund",
            "Martok",
            "Hombre",
            40,
            abuelo,
            abuela,
            90,
            85,
            70,
            65,
            65,
            80,
            300,
            4,
            Profesion::Caballero
        );

    // ========================================================
    // EDWULF
    // ========================================================

    int edwulfID =
        crearPersonaje(
            familia,
            "Edwulf",
            "Martok",
            "Hombre",
            17,
            padre,
            0,
            100,
            50,
            60,
            50,
            45,
            100,
            10,
            0,
            Profesion::Soldado
        );

    // ========================================================
    // HENRICK
    // ========================================================

    crearPersonaje(
        familia,
        "Henrick",
        "Martok",
        "Hombre",
        19,
        padre,
        0,
        90,
        65,
        55,
        65,
        50,
        90,
        20,
        0,
        Profesion::Soldado
    );

    // ========================================================
    // MENU PRINCIPAL
    // ========================================================

    int opcion = 0;
    int ano = 1;

    while (opcion != 9)
    {
        cout << "\n\n====================================\n";
        cout << "       MARTOK: BLOOD AND LEGACY\n";
        cout << "====================================\n";

        Personaje* edwulf =
            buscarPersonaje(
                familia,
                edwulfID);

        if (edwulf != nullptr)
        {
            cout << "\n"
                 << edwulf->nombre
                 << " "
                 << edwulf->apellido
                 << " | "
                 << edwulf->edad
                 << " anos";

            cout << "\nRango: "
                 << edwulf->rangoMilitar;

            cout << "\nOro: "
                 << edwulf->oro;

            cout << "\n";
        }

        cout << "\nAno del mundo: "
             << ano
             << "\n";

        cout << "\n1. Ver personaje";
        cout << "\n2. Ver todos los personajes";
        cout << "\n3. Pasar un ano";
        cout << "\n4. Casar a Edwulf";
        cout << "\n5. Intentar tener hijo";
        cout << "\n6. Entrenar a Edwulf";
        cout << "\n7. Matar personaje";
        cout << "\n8. Ver fertilidad de Edwulf";
        cout << "\n9. Salir";

        cout << "\n\nOpcion: ";
        cin >> opcion;

        // ====================================================
        // VER PERSONAJE
        // ====================================================

        if (opcion == 1)
        {
            mostrarPersonaje(
                familia,
                edwulfID);
        }

        // ====================================================
        // VER TODOS
        // ====================================================

        else if (opcion == 2)
        {
            mostrarTodos(
                familia);
        }

        // ====================================================
        // PASAR ANO
        // ====================================================

        else if (opcion == 3)
        {
            ano++;

            pasarAno(
                familia,
                ano);
        }

        // ====================================================
        // CASARSE
        // ====================================================

        else if (opcion == 4)
        {
            int parejaID;

            cout << "\nID de la pareja: ";
            cin >> parejaID;

            casar(
                familia,
                edwulfID,
                parejaID);
        }

        // ====================================================
        // TENER HIJO
        // ====================================================

        else if (opcion == 5)
        {
            Personaje* edwulf =
                buscarPersonaje(
                    familia,
                    edwulfID);

            if (edwulf == nullptr)
                continue;

            if (edwulf->conyugeID == 0)
            {
                cout << "\nEdwulf no esta casado.\n";
            }
            else
            {
                intentarTenerHijo(
                    familia,
                    edwulfID,
                    edwulf->conyugeID);
            }
        }

        // ====================================================
        // ENTRENAR
        // ====================================================

        else if (opcion == 6)
        {
            Personaje* edwulf =
                buscarPersonaje(
                    familia,
                    edwulfID);

            if (edwulf != nullptr)
            {
                entrenar(
                    *edwulf);
            }
        }

        // ====================================================
        // MATAR
        // ====================================================

        else if (opcion == 7)
        {
            int id;

            cout << "\nID del personaje: ";
            cin >> id;

            morir(
                familia,
                id,
                ano);
        }

        // ====================================================
        // FERTILIDAD
        // ====================================================

        else if (opcion == 8)
        {
            Personaje* edwulf =
                buscarPersonaje(
                    familia,
                    edwulfID);

            if (edwulf != nullptr)
            {
                cout << "\n====================================\n";
                cout << "        FERTILIDAD DE EDWULF\n";
                cout << "====================================\n";

                cout << "\nEdad: "
                     << edwulf->edad;

                cout << "\nFertilidad genetica: "
                     << edwulf->fertilidadBase
                     << "/100";

                cout << "\nFertilidad actual: "
                     << calcularFertilidad(*edwulf)
                     << "/100\n";
            }
        }

        // ====================================================
        // SALIR
        // ====================================================

        else if (opcion == 9)
        {
            cout << "\nSaliendo de Martok...\n";
        }

        else
        {
            cout << "\nOpcion no valida.\n";
        }
    }

    return 0;
}