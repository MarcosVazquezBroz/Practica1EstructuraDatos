#pragma once                        // Directiva para asegurar que este archivo se incluya solo una vez durante la compilaci�n

#include "Proceso.h"

class Queue {

    private:
        struct Nodo {
            Proceso proceso;        // Dato gen�rico almacenado en el nodo
            Nodo* siguiente;        // Puntero al siguiente nodo en la cola
        };
        Nodo* _primero;             // Puntero al primer nodo de la cola
        Nodo* _ultimo;              // Puntero al �ltimo nodo de la cola
        int   _longitud;            // N�mero de elementos en la cola

    public:
        Queue();                    // Constructor
        ~Queue();                   // Destructor
        void ordenar_prio(); 
        int longitud();             // Devuelve el n�mero de elementos en la cola
        void encolar(Proceso);      // Agrega un elemento al final de la cola
        Proceso inicio();           // Devuelve el elemento al frente de la cola
        Proceso fin();              // Devuelve el elemento al final de la cola
        Proceso desencolar();       // Elimina y devuelve el elemento al frente de la cola
        bool vacio();               // Devuelve true si la cola est� vac�a, false en caso contrario
        void mostrar();             // Muestra los elementos en la cola (necesita implementaci�n)
};
