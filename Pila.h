#pragma once                        // Directiva para asegurar que este archivo se incluya solo una vez durante la compilaci�n

#include "Proceso.h"

class Pila {

    private:
        struct Nodo {
            Proceso proceso;        // Dato gen�rico almacenado en la pila
            Nodo* siguiente;        // Puntero al siguiente nodo en la pila
        };
        Nodo* _cima;                // Puntero al nodo superior de la pila
        int   _longitud;            // N�mero de elementos en la cola

    public:
        Pila();                     // Constructor
        ~Pila();                    // Destructor

        int longitud();             // Devuelve el n�mero de elementos en la pila
        void apilar(Proceso);       // Agrega un elemento a la parte superior de la pila
        Proceso cima();             // Devuelve el elemento en la parte superior de la pila
        Proceso desapilar();        // Elimina y devuelve el elemento en la parte superior de la pila
        bool vacia();               // Devuelve true si la pila est� vac�a, false en caso contrario
        void mostrar();             // Muestra los elementos en la pila
        void ordenarPorInicio();    // Ordena la pila seg�n la hora de inicio del proceso
};
