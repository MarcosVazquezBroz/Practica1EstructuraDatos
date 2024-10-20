#include "Simulacion.h"
#include "Pila.h"
#include <iostream>

using namespace std;

Simulacion::Simulacion() {

}

Simulacion::~Simulacion() {

}


void Simulacion::crearPila() {

    // Creamos los 10 procesos de prueba
    pila_procesos.apilar(Proceso(1, 0, 480, 120, 3));       // PID 1, PPID 0 (init), 8:00 AM, 120 min, prioridad 3
    pila_procesos.apilar(Proceso(2, 1, 540, 60, 1));        // PID 2, PPID 1, 9:00 AM, 60 min, prioridad 1
    pila_procesos.apilar(Proceso(3, 1, 570, 90, 2));        // PID 3, PPID 1, 9:30 AM, 90 min, prioridad 2
    pila_procesos.apilar(Proceso(4, 1, 600, 30, 0));        // PID 4, PPID 1, 10:00 AM, 30 min, prioridad 0
    pila_procesos.apilar(Proceso(5, 3, 615, 45, 4));        // PID 5, PPID 3, 10:15 AM, 45 min, prioridad 4
    pila_procesos.apilar(Proceso(6, 2, 630, 120, 5));       // PID 6, PPID 2, 10:30 AM, 120 min, prioridad 5
    pila_procesos.apilar(Proceso(7, 4, 660, 90, 6));        // PID 7, PPID 4, 11:00 AM, 90 min, prioridad 6
    pila_procesos.apilar(Proceso(8, 5, 690, 30, 3));        // PID 8, PPID 5, 11:30 AM, 30 min, prioridad 3
    pila_procesos.apilar(Proceso(9, 6, 720, 60, 2));        // PID 9, PPID 6, 12:00 PM, 60 min, prioridad 2
    pila_procesos.apilar(Proceso(10, 3, 750, 180, 1));      // PID 10, PPID 3, 12:30 PM, 180 min, prioridad 1

    cout << "Pila creada con éxito" << endl;
}

void Simulacion::mostrarPila() {
    pila_procesos.ordenarPorInicio();
    pila_procesos.mostrar();
}

void Simulacion::borrarPila() {

    while (!pila_procesos.vacia()) {
        pila_procesos.desapilar();
    }
}

void Simulacion::mostrarCola() {
    cola_prio.mostrar();
}

void Simulacion::mostrarNucleos() {

}

void Simulacion::mostrarMenu() {
    cout << "\n--- Menú ---\n";
    cout << "1. Crear la pila de procesos\n";
    cout << "2. Mostrar la pila de procesos\n";
    cout << "3. Borrar la pila de procesos\n";
    cout << "4. Mostrar la cola de espera\n";
    cout << "5. Iniciar simulación\n";
    cout << "6. Salir\n";
    cout << "Seleccione una opción: ";
}



void Simulacion::simularTiempo() {
    int minutos;
    cout << "Ingrese la cantidad de minutos a simular: ";
    cin >> minutos;

    cout << "Simulación avanzada " << minutos << " minutos." << endl;
}

void Simulacion::ejecutar() {

}

void Simulacion::iniciar() {
    int opcion;

    do {
        // Limpiar pantalla
        system("cls");

        mostrarMenu();
        cout << "Elige una opción: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            if (pila_procesos.vacia()) {
                crearPila();
                cout << "Se ha creado la pila de procesos." << endl;
            }
            else {
                cout << "Ya existe una pila de procesos." << endl;
            }
            break;
        case 2:
            if (!pila_procesos.vacia()) {
                mostrarPila();
            }
            else {
                cout << "La pila está vacía." << endl;
            }
            break;
        case 3:
            if (!pila_procesos.vacia()) {
                borrarPila();
                cout << "La pila de procesos se ha eliminado." << endl;
            }
            else {
                cout << "La pila ya está vacía." << endl;
            }
            break;
        case 4:
            if (!cola_prio.vacia()) {
                mostrarCola();
            }
            else {
                cout << "La cola está vacía." << endl;
            }
            break;
        case 5:
            if (pila_procesos.vacia()) {
                cout << "Se debe crear una pila antes de comenzar la simulación." << endl;
            }
            else {
                // Asigno los últimos procesos a los núcleos porque no empieza con la prioridad, sino con la hora de inicio, y la pila ya está ordenada así
                for (int i; 0; 3) {
                    nucleos[i].asignarProceso(pila_procesos.desapilar());
                }
                cout << "Se han iniciado 3 procesos." << endl;
            }

        case 0:
            cout << "Saliendo..." << endl;
            break;
        default:
            cout << "Opción no válida." << endl;
        }

        // Pausar para que el usuario vea el resultado antes de volver al menú
        if (opcion != 0) {
            cout << "Presiona Enter para continuar...";
            cin.ignore();
            cin.get();
        }

    } while (opcion != 0);
}
