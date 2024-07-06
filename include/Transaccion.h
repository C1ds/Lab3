#pragma once
#include <string>
using namespace std;

/**
 * @class Clase Transaccion
 */
class Transaccion {
private:
    int id;
    string cuentaOrigen;
    string cuentaDestino;
    double monto;
    string fechaHora;
    string ubicacion;
public:
    /**
     * Constructor de la clase Transaccion
     * @param int id
     * @param string cuentaOrigen
     * @param string cuentaDestino
     * @param double monto
     * @param string fechaHora
     * @param string ubicacion
     */
    Transaccion(int id, string cuentaOrigen, string cuentaDestino, double monto, string fechaHora, string ubicacion);

    /**
     * Obtener el Id de la Transaccion
     * @return int
     */
    int getId() const;

    /**
     * Obtener Cuenta de Origen
     * @return string
     */
    string getCuentaOrigen() const;

    /**
     * Obtener Cuenta de Destino
     * @return string
     */
    string getCuentaDestino() const;

    /**
     * Obtener Monto
     * @return double
     */
    double getMonto() const;

    /**
     * Obtener Fecha y Hora
     * @return string
     */
    string getFechaHora() const;

    /**
     * Obtener Ubicacion
     * @return string
     */
    string getubicacion() const;

    /**
     * Destructor de la Clase Transaccion
     */
    ~Transaccion();
};

