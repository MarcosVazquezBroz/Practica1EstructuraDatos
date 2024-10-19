#pragma once

#include "Proceso.h"

class StackNode {
private:
    Proceso* process;      // Pointer to the Process object stored in the node
    StackNode* next;     // Pointer to the next node in the stack
    friend class ProcessStack; // ProcessStack class can access private members of StackNode

public:
    StackNode(Proceso* proc, StackNode* sig = NULL); // Constructor with Process object and next node
    ~StackNode();                // Destructor
};
