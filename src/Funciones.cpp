#include "../include/Funciones.h"
using namespace std;

Funciones::Funciones() {
    //Constructor
}

void Funciones::MostrarMenu() {
    cout << "------Menu Usuario------" << endl;
    cout << "[1] Registrar Transaccion" << endl;
    cout << "[2] Buscar Transaccion por ID" << endl;
    cout << "[3] Modificar Transaccion" << endl;
    cout << "[4] Criterios Transacciones Sospechosas" << endl;
    cout << "[5] Modificar Criterios Transacciones Sospechosas" << endl;
    cout << "[6] Generar Reporte" << endl;
    cout << "[7] Salir" << endl;
    cout << "Opcion: ";
}

void Funciones::MostrarReporte() {
    cout << "------Menu Reporte------" << endl;
    cout << "[1] Mostrar transacciones registradas" << endl;
    cout << "[2] Mostrar transacciones sospechosas" << endl;
    cout << "Opcion: ";
}

void Funciones::MostrarModificacion() {
    cout << "[1] Id" << endl;
    cout << "[2] Cuenta origen" << endl;
    cout << "[3] Cuenta destino" << endl;
    cout << "[4] Monto" << endl; 
    cout << "[5] Fecha y Hora" << endl; 
    cout << "[6] Ubicacion" << endl;
    cout << "Opcion: ";
}

int Funciones::validarOpcion(string& opcion) {
    try{
        if (opcion.empty()) {
            throw invalid_argument("Entrada vacia");
        }
        int i = std::stoi(opcion);
        return i;
        }
    catch(std::invalid_argument const &e){
        cout << "Ingrese un dato valido:";
        getline(cin, opcion);
        return validarOpcion(opcion);
        }
    catch(std::out_of_range const &e){
        cout << "El numero esta fuera de rango. Ingrese un dato valido:";
        getline(cin, opcion);
        return validarOpcion(opcion);
        }
}

Funciones::~Funciones() {}
