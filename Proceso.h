#pragma once                        // Directiva para asegurar que este archivo se incluya solo una vez durante la compilación

class Proceso {
    private:
        int _pid;                   // ID del proceso
        int _ppid;                  // ID del proceso padre
        int _inicio;                // Tiempo de inicio del proceso
        int _duracion;              // Tiempo de vida del proceso
        int _prioridad;             // Prioridad del proceso

    public:
        Proceso();
        Proceso(int pid, int ppid, int startTime, int lifeTime, int priority); // Constructor

        int getPID();               // Devuelve el ID del proceso
        int getPPID();              // Devuelve el ID del proceso padre
        int getInicio();            // Devuelve el tiempo de inicio del proceso
        int getDuracion();          // Devuelve el tiempo de vida del proceso
        int getPrioridad();         // Devuelve la prioridad del proceso
};