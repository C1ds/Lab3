#pragma once
#include "Transaccion.h"
using namespace std;

/**
 * @class Clase Persistencia
 */
class Persistencia {
public:
    /**
     * Guarda las Transacciones en el archivo transacciones.txt
     * @param vector<Transaccion>& transacciones
     * @param string& archivo
     */
    void guardarTransacciones(const vector<Transaccion>& transacciones, const string& archivo);

    /**
     * Carga las Transacciones del archivo transacciones.txt
     * @param string& archivo
     * @return vector<Transaccion>
     */
    vector<Transaccion> cargarTransacciones(const string& archivo);

    /**
     * Destructor de la Clase Persistencia
     */
    ~Persistencia();
};

