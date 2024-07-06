#include <iostream>
#include <string>
#include <vector>
#include "../include/Funciones.h"
#include "../include/Transaccion.h"
#include "../include/Cliente.h"
#include "../include/Registro.h"
#include "../include/Persistencia.h"
#include "../include/Deteccion.h"
#include "../include/Sospechoso.h"
using namespace std;

int main() {
    Funciones* funciones;
    Deteccion* deteccion = new Deteccion();
    Sospechoso arbolABB;
    Registro arbolAVL;
    Persistencia persistencia;
    vector<Transaccion> transacciones = persistencia.cargarTransacciones("transacciones.txt");

    for (const auto& t : transacciones) {
        arbolAVL.insertar(t);
    }

    for (const auto& t : transacciones) {
        if (t.getMonto() > deteccion -> getMontoMax()) {
            arbolABB.insertar(t);
            continue;
        }
    }

    string* data = new string;
    int* opcion = new int;

    do {
        funciones -> MostrarMenu();
        getline(cin, *data);

        *opcion = funciones -> validarOpcion(*data);
        switch (*opcion) {
            case 1: {
                int id;
                string co, cd, fechaHora, ubicacion;
                double monto;
                cout << "Ingrese ID: ";
                cin >> id;
                cout << "Ingrese Cuenta Origen: ";
                cin >> co;
                cout << "Ingrese Cuenta Destino: ";
                cin >> cd;
                cout << "Ingrese Monto: ";
                cin >> monto;
                cout << "Ingrese Fecha y Hora: ";
                cin >> fechaHora;
                cout << "Ingrese Ubicacion Geografica: ";
                cin >> ubicacion;
                Transaccion t(id, co, cd, monto, fechaHora, ubicacion);
                arbolAVL.insertar(t);
                transacciones.push_back(t);
                persistencia.guardarTransacciones(transacciones, "transacciones.txt");
                break;
            }
            case 2: {
                int* id = new int;
                cout << "Ingrese ID: ";
                getline(cin, *data);
                *id = funciones -> validarOpcion(*data);
                Transaccion* t = arbolAVL.buscar(*id);
                if (t) {
                    cout << "----------------------" << endl;
                    cout << "Transaccion encontrada" << endl;
                    cout << "----------------------" << endl;
                    cout << "Id: " << t->getId() << endl;
                    cout << "Cuenta origen: " << t->getCuentaOrigen() << endl;
                    cout << "Cuenta destino: " << t->getCuentaDestino() << endl;
                    cout << "Monto: " << t->getMonto() << endl; 
                    cout << "Fecha y Hora: " << t->getFechaHora() << endl; 
                    cout << "Ubicacion: " << t->getubicacion() << endl;
                    cout << "----------------------" << endl;
                } else {
                    cout << "Transaccion no encontrada.\n";
                }
                break;
            }
            case 3: {
                funciones -> MostrarModificacion();
                getline(cin, *data);
                *opcion = funciones -> validarOpcion(*data);
                if (*opcion < 7 && *opcion > 0) {
                    int* id = new int;
                    cout << "Ingrese ID: ";
                    getline(cin, *data);
                    *id = funciones -> validarOpcion(*data);
                    switch (*opcion) {
                        //Modificar Id
                        case 1: {
                            int newId;
                            cout << "Id: " << endl;
                            getline(cin, *data);
                            newId = funciones -> validarOpcion(*data);
                            break;}
                        //Modificar Cuenta Origen
                        case 2: {break;}
                            int newCuentaO;
                            cout << "Cuenta origen" << endl;
                            getline(cin, *data);
                            newCuentaO = funciones -> validarOpcion(*data);
                        //Modificar Cuenta Destino
                        case 3: {
                            int newCuentaD;
                            cout << "Cuenta Destino" << endl;
                            getline(cin, *data);
                            newCuentaD = funciones -> validarOpcion(*data);
                            break;}
                        //Modificar Monto
                        case 4: {
                            int newMonto;
                            cout << "Cuenta Monto" << endl;
                            getline(cin, *data);
                            newMonto = funciones -> validarOpcion(*data);
                            break;}
                        //Modificar Fecha y Hora
                        case 5: {
                            string fechaHora;
                            cout << "fecha y Hora" << endl;
                            getline(cin,fechaHora);
                            break;}
                        //Modificar Ubicacion
                        case 6: {
                            string ubicacion;
                            cout << "Ubicacion" << endl;
                            getline(cin,ubicacion);
                            break;}
                        default: {break;}
                    }
                }
                else {
                    cout << "---Opcion Invalida---" << endl;
                }
                break;
            }
            case 4: {
                deteccion -> imprimirCriterios();
                break;
            }
            case 5: {
                int* op = new int;
                deteccion -> menuModificacion();
                cout << "opcion: ";
                getline(cin, *data);
                *op = funciones -> validarOpcion(*data);
                if (*op == 1) {
                    cout << "Monto maximo: ";
                    getline(cin, *data);
                    int max = funciones -> validarOpcion(*data);
                    deteccion -> setMontoMax(max);

                    //Nuevo arbolABB
                    Sospechoso arbol;
                    for (const auto& t : transacciones) {
                        if (t.getMonto() > deteccion -> getMontoMax()) {
                        arbol.insertar(t);
                        continue;
                        }
                    }
                    arbolABB = arbol;
                }
                else if (*op == 2) {
                    cout << "Maximo transacciones: ";
                    getline(cin, *data);
                    int max = funciones -> validarOpcion(*data);
                    deteccion -> setMaxTransacciones(max);
                }
                else {
                    cout << "---Opcion Invalida---" << endl;
                }
                break;
            }
            case 6: {
                funciones -> MostrarReporte();
                getline(cin, *data);
                *opcion = funciones -> validarOpcion(*data);
                //Mostrar Transacciones Registradas
                if (*opcion == 1) {
                    cout << "---Transacciones Registradas---" << endl;
                    arbolAVL.mostrarElementos();
                }
                //Mostrar Transacciones Sospechosas
                else if (*opcion == 2) {
                    cout << "---Transacciones Sospechosas---" << endl;
                    arbolABB.mostrarElementos();
                }
                //Opcion fuera de rango
                else {
                    cout << "---Opcion Invalida---" << endl;
                }
                break;
            }
            default:
                break;
        }
    } while (*opcion != 7);

    //Liberado de Memoria
    delete funciones;
    delete deteccion;
    return 0;
}
