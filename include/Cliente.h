#pragma once
#include <string>
using namespace std;

/**
 * @class Clase Cliente
 */
class Cliente {
private:
    string nombre;
    string idCliente;
public:
    /**
     * Constructor de la clase Cliente
     * @param string nombre
     * @param string idCliente
     */
    Cliente(string nombre, string idCliente);

    /**
     * Obtener el nombre del Cliente
     * @return string
     */
    string getNombre();

    /**
     * Obtener el Id del Cliente
     * @return string
     */
    string getIdCliente();

    /**
     * Destructor de la Clase Cliente
     */
    ~Cliente();
};


