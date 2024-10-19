#pragma once
#include "Pila.h"

class Simulacion {

    private:
        Pila pila_procesos;

	public:
		Simulacion();
		~Simulacion();

        void mostrarMenu();         // Método para mostrar el menú de inicio
        void crearPila();           // Opción 1: Crear procesos
        void mostrarPila();         // Opción 2: Mostrar pila de procesos
        void borrarPila();          // Opción 3: Borrar pila
        void mostrarCola();         // Opción 4: Mostrar cola de espera (si la implementas)
        void mostrarNucleos();      // Opción 5: Mostrar los detalles de los núcleos
        void simularTiempo();       // Opción 6: Simular el paso de N minutos
        void ejecutar();            // Opción 7: Simular la ejecución completa
        
};

