#include <iostream>
#include "Pila.h"

Pila::Pila() {
    // Constructor: Inicializa una pila vacía.
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
    // Devuelve el número de elementos en la pila.
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
    // Lanza una excepción si la pila está vacía.
    if (vacia()) {
        throw std::runtime_error("La pila está vacía");
    }
    return _cima->proceso;
}

Proceso Pila::desapilar() {
    // Elimina y devuelve el elemento en la parte superior de la pila.
    // Lanza una excepción si la pila está vacía.
    if (vacia()) {
        throw std::runtime_error("La pila está vacía");
    }

    Proceso data = _cima->proceso;
    Nodo* temp = _cima;
    _cima = _cima->siguiente;
    delete temp;
    _longitud--;
    return data;
}

bool Pila::vacia() {
    // Devuelve true si la pila está vacía, false en caso contrario.
    return _longitud == 0;
}

void Pila::mostrar() {
    // Muestra los elementos de la pila.
    if (vacia()) {
        std::cout << "La pila está vacía" << std::endl;
        return;
    }

    Nodo* current = _cima;
    while (current != nullptr) {
        std::cout << current->proceso.getPID() << " ";
        current = current->siguiente;
    }
    std::cout << std::endl;
}

void Pila::ordenarPorInicio() {
    if (vacia()) {
        std::cout << "La pila está vacía" << std::endl;
        return;
    }
    Nodo* actual;                       // Nodo para recorrer la pila
    Nodo* sig;                          // Nodo siguiente para la comparación
    bool intercambiado = true;          // Inicialmente asumimos que habrá intercambios

    while (intercambiado) {
        intercambiado = false;          // Suponemos que no habrá intercambios en esta pasada
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