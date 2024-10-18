#include "PilaProc.h"
#include "NodoPila.h"
#include "Proceso.h"
#include <iostream>
using namespace std;

PilaProc::PilaProc() { cima = NULL; }

PilaProc::~PilaProc()
{
	while (cima)
	{
		desapilar();
	}
}

bool PilaProc::esVacia()
{
	return cima == NULL;
}

void PilaProc::apilar(Proceso *proc)
{
	pnodo nuevo = new NodoPila(proc, cima);
	cima = nuevo;
}

void PilaProc::desapilar()
{
	pnodo nodo;
	if (cima)
		nodo = cima;
	cima = nodo->siguiente;
	delete nodo;
}

void PilaProc::mostrar() //Muestra la pila entera
{
	NodoPila* actual = cima;

	if (esVacia())
	{
		cout << "Pila vacia" << endl;
	}
	else
	{
		while (actual != nullptr) {

			cout << "Proceso PID: " << actual -> proceso.getPID() << ", Hora de inicio: " << actual -> proceso.getInicio() << endl;

			actual = actual -> siguiente;
		}
	}
}

void PilaProc::ordenar_por_hora()
{

}

// Chuleta
void PilaProc::iterar_sin_destruir() {
	NodoPila* actual = cima;

	while (actual != nullptr) {

		//std::cout << "Proceso PID: " << actual->proceso.getPID() << ", Hora de inicio: " << actual->proceso.getInicio() << std::endl;

		actual = actual->siguiente;
	}
}