#pragma once
#include <iostream>
#include <string>
using namespace std;

/**
 * @class Clase Deteccion
 */
class Deteccion {
private:
    int montoMax;
    int maxTransacciones;
public:
    /**
     * Constructor de la Clase Deteccion
     */
    Deteccion();

    /**
     * Obtiene el monto maximo para que una transaccion
     * sea sospechosa
     * @return int
     */
    int getMontoMax();

    /**
     * Obtiene la cantidad maxima de transacciones
     * para que sea sospechoso
     * @return int
     */
    int getMaxTransacciones();

    /**
     * Define el monto maximo para que una transaccion
     * sea sospechosa
     * @param int max
     */
    void setMontoMax(int max);

    /**
     * Define la cantidad maxima de transacciones
     * para que sea sospechoso
     * @param int max
     */
    void setMaxTransacciones(int max);

    /**
     * Muestra por pantalla los criterios de
     * transacciones sospechosas
     */
    void imprimirCriterios();

    /**
     * Muestra los criterios a modificar
     * para las transacciones sospechosas
     */
    void menuModificacion();

    /**
     * Destructor de la Clase Funciones
     */
    ~Deteccion();
};