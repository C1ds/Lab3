#include <fstream>
#include <vector>
#include <sstream>
#include "../include/Persistencia.h"
using namespace std;

void Persistencia::guardarTransacciones (const vector<Transaccion>& transacciones, const string& archivo) {
        ofstream file(archivo);
        for (const auto& transaccion : transacciones) {
            file << transaccion.getId() << ","
                 << transaccion.getCuentaOrigen() << ","
                 << transaccion.getCuentaDestino() << ","
                 << transaccion.getMonto() << ","
                 << transaccion.getFechaHora() << ","
                 << transaccion.getubicacion() << "\n";
        }
        file.close();
    }

vector<Transaccion> Persistencia::cargarTransacciones (const string& archivo) {
        vector<Transaccion> transacciones;
        ifstream file(archivo);
        string linea;
        while (getline(file, linea)) {
            istringstream ss(linea);
            string id, co, cd, monto, fechaHora, ubicacion;
            getline(ss, id, ',');
            getline(ss, co, ',');
            getline(ss, cd, ',');
            getline(ss, monto, ',');
            getline(ss, fechaHora, ',');
            getline(ss, ubicacion, ',');
            transacciones.emplace_back(stoi(id), co, cd, stod(monto), fechaHora, ubicacion);
        }
        file.close();
        return transacciones;
    }

Persistencia::~Persistencia() {}