#ifndef NODOPILA_H
#define NODOPILA_H
#include <iostream>
#include "Proceso.h"
class NodoPila
{
private:
    Proceso *proceso;
    NodoPila *siguiente;
    friend class PilaProc;

public:
    NodoPila(Proceso *proc, NodoPila *sig = NULL);
    ~NodoPila();
};

typedef NodoPila *pnodo;

#endif