#include "../include/Registro.h"
#include <algorithm>
#include <iostream>
using namespace std;

int Registro::obtenerAltura (Nodo* nodo) {
    return nodo ? nodo->altura : 0;// el ? es una condicion si existe el nodo devuele la altura y si no devuelve 0
    }

int Registro::obtenerBalance (Nodo* nodo) {
    return nodo ? obtenerAltura(nodo->izquierdo) - obtenerAltura(nodo->derecho) : 0;
    }

Nodo* Registro::rotarDerecha (Nodo* y) {
    Nodo* x = y->izquierdo;
    Nodo* T2 = x->derecho;
    x->derecho = y;
    y->izquierdo = T2;
    y->altura = max(obtenerAltura(y->izquierdo), obtenerAltura(y->derecho)) + 1;
    x->altura = max(obtenerAltura(x->izquierdo), obtenerAltura(x->derecho)) + 1;
    return x;
    }

Nodo* Registro::rotarIzquierda (Nodo* x) {
    Nodo* y = x->derecho;
    Nodo* T2 = y->izquierdo;
    y->izquierdo = x;
    x->derecho = T2;
    x->altura = max(obtenerAltura(x->izquierdo), obtenerAltura(x->derecho)) + 1;
    y->altura = max(obtenerAltura(y->izquierdo), obtenerAltura(y->derecho)) + 1;
    return y;
    }

Nodo* Registro::insertar (Nodo* nodo, Transaccion t) {
    if (!nodo) {
        return new Nodo(t);
    }
    
    if (t.getId() < nodo->data.getId()) {
        nodo->izquierdo = insertar(nodo->izquierdo, t);
    }
    else if (t.getId() > nodo->data.getId()) {
        nodo->derecho = insertar(nodo->derecho, t);
    }
    else {
        return nodo;
    }

    nodo->altura = 1 + max(obtenerAltura(nodo->izquierdo), obtenerAltura(nodo->derecho));

    int balance = obtenerBalance(nodo);

    if (balance > 1 && t.getId() < nodo->izquierdo->data.getId()) {
        return rotarDerecha(nodo);
    }
        
    if (balance < -1 && t.getId() > nodo->derecho->data.getId()) {
        return rotarIzquierda(nodo);
    }

    if (balance > 1 && t.getId() > nodo->izquierdo->data.getId()) {
        nodo->izquierdo = rotarIzquierda(nodo->izquierdo);
        return rotarDerecha(nodo);
    }

    if (balance < -1 && t.getId() < nodo->derecho->data.getId()) {
        nodo->derecho = rotarDerecha(nodo->derecho);
        return rotarIzquierda(nodo);
    }

    return nodo;
    }

Nodo* Registro::buscar (Nodo* nodo, int& id) {
    if (!nodo || nodo->data.getId() == id) {
        return nodo;
    }

    if (nodo->data.getId() > id) {
        return buscar(nodo->izquierdo, id);
    }

    return buscar(nodo->derecho, id);
    }

void Registro::mostrarElementos(Nodo* nodo) {
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

Registro::Registro() : raiz(nullptr) {
    //Constructor
}

void Registro::insertar (Transaccion t) {
    raiz = insertar(raiz, t);
    }

Transaccion* Registro::buscar(int& id) {
    Nodo* resultado = buscar(raiz, id);
    return resultado ? &resultado->data : nullptr;
    }

void Registro::mostrarElementos() {
    if (!raiz) {
        cout << "No hay elementos registrados" << endl;
    }
    mostrarElementos(raiz);
}

void Registro::modificarElemento(int& id, int &opcion) {
    switch (opcion) {
        //Modificar Id
        case 1: {break;}
        //Modificar Cuenta Origen
        case 2: {break;}
        //Modificar Cuenta Destino
        case 3: {break;}
        //Modificar Monto
        case 4: {break;}
        //Modificar Fecha y Hora
        case 5: {break;}
        //Modificar Ubicacion
        case 6: {break;}
    }
}

Registro::~Registro() {}