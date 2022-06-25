#ifndef NODE_H
#define NODE_H 
#include "Word.h"

class Node{
    private:
        Word w;
        Node* next;
        Node* prev;
    friend class List;
    public:
        Node();
};

#endif