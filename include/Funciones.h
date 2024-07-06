#pragma once
#include <iostream>
#include <string>
using namespace std;

/**
 * @class Clase Funciones
 */
class Funciones {
private:

public:
    /**
     * Constructor de la Clase Funciones
     */
    Funciones();

    /**
     * Imprime en pantalla el Menu de Usuario
     */
    void MostrarMenu();

    /**
     * Imprime en pantalla el Menu de Reporte
     */
    void MostrarReporte();

    /**
     * Imprime en pantalla el Menu de Modificaciones
     */
    void MostrarModificacion();

    /**
     * Valida que el parametro entregado sea un numero
     * @param string
     * @return int
     */
    int validarOpcion(string& opcion);

    /**
     * Destructor de la Clase Funciones
     */
    ~Funciones();
};