#pragma once
#include "../include/Transaccion.h"
using namespace std;

/**
 * @struct Estructura del NodoABB
 */
struct NodoABB {
    Transaccion data;
    NodoABB* izquierdo;
    NodoABB* derecho;

    NodoABB(Transaccion t) : data(t), izquierdo(nullptr), derecho(nullptr) {}
};

/**
 * @class Clase Sospechoso (Arbol ABB)
 */
class Sospechoso {
private:
    NodoABB* raiz;

    /**
     * Agrega el Nodo al Arbol ABB
     * @param NodoABB* nodo
     * @param Transaccion t
     * @return NodoABB*
     */
    NodoABB* insertar(NodoABB* nodo, Transaccion t);

    /**
     * Busca al Nodo en el Arbol ABB
     * @param NodoABB* nodo
     * @param int& id
     * @return NodoABB*
     */
    NodoABB* buscar(NodoABB* nodo, int& id);

    /**
     * Muestra los elementos en el Arbol ABB
     * @param NodoABB* nodo
     */
    void mostrarElementos(NodoABB* nodo);

public:
    /**
     * Constructor de la Clase Sospechoso
     */
    Sospechoso();

    /**
     * Inserta la Transaccion al Arbol ABB
     * @param Transaccion t
     */
    void insertar(Transaccion t);

    /**
     * Busca la Transaccion en el Arbol ABB
     * @param int& id
     * @return Transaccion*
     */
    Transaccion* buscar(int& id);

    /**
     * Muestra los elementos en el Arbol ABB
     */
    void mostrarElementos();
};