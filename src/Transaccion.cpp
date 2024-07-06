#include "../include/Transaccion.h"
using namespace std;

Transaccion::Transaccion(int id, string cuentaOrigen, string cuentaDestino, double monto, string fechaHora, string ubicacion)
 : id(id), cuentaOrigen(cuentaOrigen), cuentaDestino(cuentaDestino), monto(monto), fechaHora(fechaHora), ubicacion(ubicacion) {
    //Constructor
 }

 int Transaccion::getId() const{ 
    return id; 
    }

string Transaccion::getCuentaOrigen() const {
    return cuentaOrigen;
    }

string Transaccion::getCuentaDestino() const {
    return cuentaDestino;
    }

double Transaccion::getMonto() const {
    return monto;
    }

string Transaccion::getFechaHora() const {
    return fechaHora;
    }

string Transaccion::getubicacion() const {
    return ubicacion;
    }

Transaccion::~Transaccion() {}