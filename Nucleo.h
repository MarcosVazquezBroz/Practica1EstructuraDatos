#pragma once
#include "Proceso.h"

class Nucleo {

	private:
		int _id;
		Proceso _proceso;

	public:
		Nucleo();
		~Nucleo();

		void asignarProceso(Proceso proc);		//Le asigna un proceso al núcleo
};

