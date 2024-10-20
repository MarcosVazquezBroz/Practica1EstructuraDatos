#pragma once
#include "Pila.h"
#include "Cola.h"

class Simulacion {

    private:
        Pila pila_procesos;
        Cola cola_prio;

	public:
		Simulacion();
		~Simulacion();

        void mostrarMenu();         // M�todo para mostrar el men� de inicio
        void crearPila();           // Opci�n 1: Crear procesos
        void mostrarPila();         // Opci�n 2: Mostrar pila de procesos
        void borrarPila();          // Opci�n 3: Borrar pila
        void mostrarCola();         // Opci�n 4: Mostrar cola de espera (si la implementas)
        void mostrarNucleos();      // Opci�n 5: Mostrar los detalles de los n�cleos
        void simularTiempo();       // Opci�n 6: Simular el paso de N minutos
        void ejecutar();            // Opci�n 7: Simular la ejecuci�n completa
        
};

