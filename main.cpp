#include <iostream> 
#include "Proceso.h"
#include "PilaProc.h"

using namespace std;

int main()
{
    // Creamos la pila que almacenará los procesos
    PilaProc pila_procesos;

    // Creamos los 10 procesos de prueba
    pila_procesos.apilar(new Proceso(1, 0, 480, 120, 3));  // PID 1, PPID 0 (init), 8:00 AM, 120 min, prioridad 3
    pila_procesos.apilar(new Proceso(2, 1, 540, 60, 1));   // PID 2, PPID 1, 9:00 AM, 60 min, prioridad 1
    pila_procesos.apilar(new Proceso(3, 1, 570, 90, 2));   // PID 3, PPID 1, 9:30 AM, 90 min, prioridad 2
    pila_procesos.apilar(new Proceso(4, 1, 600, 30, 0));   // PID 4, PPID 1, 10:00 AM, 30 min, prioridad 0
    pila_procesos.apilar(new Proceso(5, 3, 615, 45, 4));   // PID 5, PPID 3, 10:15 AM, 45 min, prioridad 4
    pila_procesos.apilar(new Proceso(6, 2, 630, 120, 5));  // PID 6, PPID 2, 10:30 AM, 120 min, prioridad 5
    pila_procesos.apilar(new Proceso(7, 4, 660, 90, 6));   // PID 7, PPID 4, 11:00 AM, 90 min, prioridad 6
    pila_procesos.apilar(new Proceso(8, 5, 690, 30, 3));   // PID 8, PPID 5, 11:30 AM, 30 min, prioridad 3
    pila_procesos.apilar(new Proceso(9, 6, 720, 60, 2));   // PID 9, PPID 6, 12:00 PM, 60 min, prioridad 2
    pila_procesos.apilar(new Proceso(10, 3, 750, 180, 1)); // PID 10, PPID 3, 12:30 PM, 180 min, prioridad 1

    pila_procesos.mostrar();
    //pila_procesos.ordenar_por_hora();
    //pila_procesos.mostrar();

}