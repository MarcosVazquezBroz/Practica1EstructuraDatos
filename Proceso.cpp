#include "Proceso.h" // Incluye la definición de la clase

Proceso::Proceso()
{
    _pid = 0;
    _ppid = 0;
    _inicio = 0;
    _duracion = 0;
    _prioridad = 0;
}
// Implementación del constructor
Proceso::Proceso(int pid, int ppid, int startTime, int lifeTime, int priority) {
    _pid = pid;
    _ppid = ppid;
    _inicio = startTime;
    _duracion = lifeTime;
    _prioridad = priority;
}

// Implementación de los métodos get
int Proceso::getPID() {
    return _pid;
}

int Proceso::getPPID() {
    return _ppid;
}

int Proceso::getInicio() {
    return _inicio;
}

int Proceso::getDuracion() {
    return _duracion;
}

int Proceso::getPrioridad() {
    return _prioridad;
}