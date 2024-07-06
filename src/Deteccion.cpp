#include "../include/Deteccion.h"
using namespace std;

Deteccion::Deteccion(){
    //Constructor
    this -> montoMax = 100000;
    this -> maxTransacciones = 3;
}

int Deteccion::getMontoMax() {
    return montoMax;
}

int Deteccion::getMaxTransacciones() {
    return maxTransacciones;
}

void Deteccion::setMontoMax(int max) {
    this -> montoMax = max;
}

void Deteccion::setMaxTransacciones(int max) {
    this -> maxTransacciones = max;
}

void Deteccion::imprimirCriterios() {
    cout << "------Criterios Sospechosos------" << endl;
    cout << "[+] Monto Maximo: " << montoMax << endl;
    cout << "[+] Maxima transacciones: " << maxTransacciones << endl;
    cout << "[+] Ubicaciones distintas en corto tiempo" << endl;
}

void Deteccion::menuModificacion() {
    cout << "------Criterios Sospechosos------" << endl;
    cout << "[1] Monto Maximo"<< endl;
    cout << "[2] Maxima transacciones"<< endl;
}

Deteccion::~Deteccion() {}