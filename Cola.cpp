#include <iostream>
#include "Cola.h" 

Cola::Cola() {
    _primero = nullptr;
    _ultimo = nullptr;
    _longitud = 0;
}

Cola::~Cola() {
    while (!vacia()) {
        desencolar();
    }
}

int Cola::longitud() {
    return _longitud;
}

void Cola::ordenar_prio(){
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

void Cola::encolar(Proceso data) {
    // Agrega un nuevo elemento al final de la cola.
    Nodo* newNode = new Nodo;
    newNode->proceso = data;
    newNode->siguiente = nullptr;

    if (vacia()) {
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

Proceso Cola::inicio() {
    if (vacia()) {
        throw std::runtime_error("La cola está vacía");
    }
    return _primero->proceso;
}


Proceso Cola::fin() {
    if (vacia()) {
        throw std::runtime_error("La cola está vacía");
    }
    return _ultimo->proceso;
}


Proceso Cola::desencolar() {
    if (vacia()) {
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


bool Cola::vacia() {
    return _longitud == 0;
}


void Cola::mostrar() {
    if (vacia()) {
        std::cout << "La cola está vacía" << std::endl;
        return;
    }

    Nodo* current = _primero;
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