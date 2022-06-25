#ifndef NODE_H
#define NODE_H 
#include "Word.h"

class Node{
    private:
        Word w;
        Node* next;
    friend class List;
    public:
        Node();
};

#endif