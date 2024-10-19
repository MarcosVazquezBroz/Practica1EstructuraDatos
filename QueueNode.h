#pragma once

class QueueNode {
    friend class Queue; // Queue class can access private members of QueueNode

    private:
        QueueNode* next;   // Pointer to the next node in the queue
        char element;      // Data stored in the node

    public:
        QueueNode();                     // Default constructor
        QueueNode(char e, QueueNode* sig = NULL); // Constructor with element and next node
        ~QueueNode();                    // Destructor
};
