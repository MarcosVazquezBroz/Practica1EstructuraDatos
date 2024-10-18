#ifndef PILAPROC_H
#define PILAPROC_H
#include "NodoPila.h"
#include "Proceso.h"

class PilaProc
{
private:
    pnodo cima;

public:
    PilaProc();
    ~PilaProc();
    bool esVacia();
    void apilar(Proceso *proc);
    void desapilar();
    void mostrar(); //Muestra la pila entera
    void ordenar_por_hora();
    void iterar_sin_destruir(); //chuleta para ver cómo iterar sobre la pila sin destruirla, quitar al final
};
#endif