#include <iostream>
#include "Cola.h" 

Queue::Queue() {
    // Constructor: Inicializa una cola vacía.
    _primero = nullptr;
    _ultimo = nullptr;
    _longitud = 0;
}

Queue::~Queue() {
    // Destructor: Libera la memoria eliminando todos los nodos de la cola.
    while (!vacio()) {
        desencolar();
    }
}

int Queue::longitud() {
    // Devuelve el número de elementos en la cola.
    return _longitud;
}

void Queue::ordenar_prio(){
    Nodo* aux1 = new Nodo;
    Nodo* aux2 = new Nodo;
    Proceso paux;
    aux1= _primero;

    while(aux1->siguiente !=nullptr){
        aux2 = aux1->siguiente;
        while(aux2!= nullptr){
            if(aux1->proceso.getPrioridad() > aux2->proceso.getPrioridad()){
                paux = aux1->proceso;
                aux1->proceso = aux2->proceso;
                aux2->proceso = paux;
            }
            aux2 = aux2->siguiente;
        }
        aux1 = aux1->siguiente;
    }

}

void Queue::encolar(Proceso data) {
    // Agrega un nuevo elemento al final de la cola.
    Nodo* newNode = new Nodo;
    newNode->proceso = data;
    newNode->siguiente = nullptr;

    if (vacio()) {
        _primero = newNode;
        _ultimo = newNode;
    }
    else {
        _ultimo->siguiente = newNode;
        _ultimo = newNode;
    }

    _longitud++;
    ordenar_prio();
}

Proceso Queue::inicio() {
    // Devuelve el elemento al frente de la cola sin eliminarlo.
    // Lanza una excepción si la cola está vacía.
    if (vacio()) {
        throw std::runtime_error("La cola está vacía");
    }
    return _primero->proceso;
}


Proceso Queue::fin() {
    // Devuelve el elemento al final de la cola sin eliminarlo.
    // Lanza una excepción si la cola está vacía.
    if (vacio()) {
        throw std::runtime_error("La cola está vacía");
    }
    return _ultimo->proceso;
}


Proceso Queue::desencolar() {
    // Elimina y devuelve el elemento al frente de la cola.
    // Lanza una excepción si la cola está vacía.
    if (vacio()) {
        throw std::runtime_error("La cola está vacía");
    }

    Proceso data = _primero->proceso;
    Nodo* temp = _primero;
    _primero = _primero->siguiente;

    if (_primero == nullptr) {
        _ultimo = nullptr;
    }

    delete temp;
    _longitud--;
    return data;
}


bool Queue::vacio() {
    // Devuelve true si la cola está vacía, false en caso contrario.
    return _longitud == 0;
}


void Queue::mostrar() {
    // Muestra los elementos de la cola.
    if (vacio()) {
        std::cout << "La cola está vacía" << std::endl;
        return;
    }

    Nodo* current = _primero;
    while (current != nullptr) {
        std::cout << current->proceso.getPID() << " ";
        current = current->siguiente;
    }
    std::cout << std::endl;
}