#include "Proceso.h"

Proceso::Proceso(int pid, int ppid, string inicio, string t_vida, int prioridad int nucleo)
{
	pid = pid;
	ppid = ppid;
	inicio = inicio;
	t_vida = t_vida;
	prioridad = prioridad;
	nucleo = nucleo;
}

Proceso::~Proceso();