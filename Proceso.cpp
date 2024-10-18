#include "Proceso.h"

Proceso::Proceso(int pid, int ppid, int inicio, int t_vida, int prioridad)
{
	pid = pid;
	ppid = ppid;
	inicio = inicio;
	t_vida = t_vida;
	prioridad = prioridad;

}

int Proceso::getPID() {
    return pid;
}

int Proceso::getPPID() {
    return ppid;
}

int Proceso::getInicio() {
    return inicio;
}

int Proceso::getTiempoVida() {
    return t_vida;
}

int Proceso::getPrioridad() {
    return prioridad;
}

