#include "../include/Sospechoso.h"
#include <algorithm>
#include <iostream>
using namespace std;

NodoABB* Sospechoso::insertar (NodoABB* nodo, Transaccion t) {
    if (!nodo) {
        return new NodoABB(t);
    }
    
    if (t.getId() < nodo->data.getId()) {
        nodo->izquierdo = insertar(nodo->izquierdo, t);
    }
    else if (t.getId() > nodo->data.getId()) {
        nodo->derecho = insertar(nodo->derecho, t);
    }

    return nodo;
    }

NodoABB* Sospechoso::buscar (NodoABB* nodo, int& id) {
    if (!nodo || nodo->data.getId() == id) {
        return nodo;
    }

    if (nodo->data.getId() > id) {
        return buscar(nodo->izquierdo, id);
    }

    return buscar(nodo->derecho, id);
    }

void Sospechoso::mostrarElementos(NodoABB* nodo) {
        if (nodo) {
            mostrarElementos(nodo->izquierdo);
            cout <<  "Id: " << nodo->data.getId() << endl;
            cout << "Cuenta origen: " << nodo->data.getCuentaOrigen() << endl;
            cout << "Cuenta destino: " << nodo->data.getCuentaDestino() << endl;
            cout <<  "Monto: " << nodo->data.getMonto() << endl; 
            cout << "Fecha y Hora: " << nodo->data.getFechaHora() << endl; 
            cout << "Ubicacion: " << nodo->data.getubicacion() << endl;
            cout << "----------------------" << endl;
            mostrarElementos(nodo->derecho);
        }
    }

Sospechoso::Sospechoso() : raiz(nullptr) {
    //Constructor
}

void Sospechoso::insertar (Transaccion t) {
    raiz = insertar(raiz, t);
    }

Transaccion* Sospechoso::buscar(int& id) {
    NodoABB* resultado = buscar(raiz, id);
    return resultado ? &resultado->data : nullptr;
    }

void Sospechoso::mostrarElementos() {
    if (!raiz) {
        cout << "No hay elementos registrados como sospechosos" << endl;
    }
    mostrarElementos(raiz);
}
