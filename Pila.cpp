#include <iostream>
#include "Pila.h"

Pila::Pila() {
    // Constructor: Inicializa una pila vac�a.
    _cima = nullptr;
    _longitud = 0;
}

Pila::~Pila() {
    // Destructor: Libera la memoria eliminando todos los nodos de la pila.
    while (!vacia()) {
        desapilar();
    }
}

int Pila::longitud() {
    // Devuelve el n�mero de elementos en la pila.
    return _longitud;
}

void Pila::apilar(Proceso process) {
    // Agrega un nuevo elemento a la parte superior de la pila.
    Nodo* newNode = new Nodo;
    newNode->proceso = process;
    newNode->siguiente = _cima;
    _cima = newNode;
    _longitud++;
}

Proceso Pila::cima() {
    // Devuelve el elemento en la parte superior de la pila sin eliminarlo.
    // Lanza una excepci�n si la pila est� vac�a.
    if (vacia()) {
        throw std::runtime_error("La pila est� vac�a");
    }
    return _cima->proceso;
}

Proceso Pila::desapilar() {
    // Elimina y devuelve el elemento en la parte superior de la pila.
    // Lanza una excepci�n si la pila est� vac�a.
    if (vacia()) {
        throw std::runtime_error("La pila est� vac�a");
    }

    Proceso data = _cima->proceso;
    Nodo* temp = _cima;
    _cima = _cima->siguiente;
    delete temp;
    _longitud--;
    return data;
}

bool Pila::vacia() {
    // Devuelve true si la pila est� vac�a, false en caso contrario.
    return _longitud == 0;
}

void Pila::mostrar() {
    // Muestra los elementos de la pila.
    if (vacia()) {
        std::cout << "La pila est� vac�a" << std::endl;
        return;
    }

    Nodo* current = _cima;
    std::cout << " ------------------------------------------------------------"<<std::endl;
    printf("|%-12s%-18s%-10s%-10s%-10s|\n","Id Proceso",
    "Id Proceso Padre", "Inicio", "Duracion", "Prioridad");
    while (current != nullptr) {
        printf("|%-12d%-18d%-10d%-10d%-10d|\n",current->proceso.getPID(),
        current->proceso.getPPID(), current->proceso.getInicio(),
        current->proceso.getDuracion(),current->proceso.getPrioridad());
        current = current->siguiente;
    }
    std::cout << " ------------------------------------------------------------"<<std::endl;
}

void Pila::ordenarPorInicio() {
    if (vacia()) {
        std::cout << "La pila est� vac�a" << std::endl;
        return;
    }
    Nodo* actual;                       // Nodo para recorrer la pila
    Nodo* sig;                          // Nodo siguiente para la comparaci�n
    bool intercambiado = true;          // Inicialmente asumimos que habr� intercambios

    while (intercambiado) {
        intercambiado = false;          // Suponemos que no habr� intercambios en esta pasada
        actual = _cima;                 

        while (actual->siguiente != nullptr) {
            sig = actual->siguiente;

            if (actual->proceso.getInicio() > sig->proceso.getInicio()) {

                Proceso aux = actual->proceso;
                actual->proceso = sig->proceso;
                sig->proceso = aux;

                intercambiado = true;
            }

            actual = sig;
        }
    }

}