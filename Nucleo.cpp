#include "Nucleo.h"
#include <iostream>

void Nucleo::asignarProceso(Proceso proc) {
	_proceso = proc;
	std::cout << "N�cleo " << _id << " asignado al proceso PID: " << _proceso.getPID() << std::endl;
}
