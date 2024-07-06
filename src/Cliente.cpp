#include "../include/Cliente.h"
using namespace std;

Cliente::Cliente(string nombre, string idCliente) : nombre(nombre), idCliente(idCliente) {
    //Constructor
}

string Cliente::getNombre() {
    return nombre;
    }

string Cliente::getIdCliente() {
    return idCliente;
    }

Cliente::~Cliente() {}