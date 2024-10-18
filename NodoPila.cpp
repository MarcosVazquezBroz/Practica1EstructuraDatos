#include "NodoPila.h"
#include "Proceso.h"

NodoPila::NodoPila(Proceso *proc, NodoPila *sig)
{
    proceso = proc;
    siguiente = sig;
}

NodoPila::~NodoPila(){}