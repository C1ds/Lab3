#pragma once
#include "../include/Transaccion.h"
using namespace std;

/**
 * @struct Estructura del Nodo
 */
struct Nodo {
    Transaccion data;
    Nodo* izquierdo;
    Nodo* derecho;
    int altura;

    Nodo(Transaccion t) : data(t), izquierdo(nullptr), derecho(nullptr), altura(1) {}
};

/**
 * @class Clase Registro (Arbol AVL)
 */
class Registro {
private:
    Nodo* raiz;

    /**
     * Obtiene la Altura del Nodo
     * @param Nodo* nodo
     * @return int
     */
    int obtenerAltura(Nodo* nodo);

    /**
     * Obtiene el Balance del Nodo
     * @param Nodo* nodo
     * @return int
     */
    int obtenerBalance(Nodo* nodo);

    /**
     * Balancear al Nodo hacia la Derecha
     * @param Nodo* y
     * @return Nodo*
     */
    Nodo* rotarDerecha(Nodo* y);

    /**
     * Balancear al Nodo hacia la Izquierda
     * @param Nodo* x
     * @return Nodo*
     */
    Nodo* rotarIzquierda(Nodo* x);

    /**
     * Agrega el Nodo al Arbol AVL
     * @param Nodo* nodo
     * @param Transaccion t
     * @return Nodo*
     */
    Nodo* insertar(Nodo* nodo, Transaccion t);

    /**
     * Busca al Nodo en el Arbol AVL
     * @param Nodo* nodo
     * @param int& id
     * @return Nodo*
     */
    Nodo* buscar(Nodo* nodo, int& id);

    /**
     * Muestra los elementos en el Arbol AVL
     * @param Nodo* nodo
     */
    void mostrarElementos(Nodo* nodo);

public:
    /**
     * Constructor de la Clase Registro
     */
    Registro();

    /**
     * Inserta la Transaccion al Arbol AVL
     * @param Transaccion t
     */
    void insertar(Transaccion t);

    /**
     * Busca la Transaccion en el Arbol AVL
     * @param int& id
     * @return Transaccion*
     */
    Transaccion* buscar(int& id);

    /**
     * Muestra los elementos en el Arbol AVL
     */
    void mostrarElementos();

    /**
     * Modifica los datos de una transaccion
     * en el Arbol AVL
     * @param int& id
     * @param int &opcion
     */
    void modificarElemento(int& id, int &opcion);

    /**
     * Destructor de la Clase Registro
     */
    ~Registro();
};

