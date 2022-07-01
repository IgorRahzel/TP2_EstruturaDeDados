#ifndef LIST_H
#define LIST_H
#include "Node.h"

class List{
    private: 
        int size;
        Node* head;
        Node* tail;
        Node* place(int pos, bool before);
        string order;
    public:
        List();
        ~List();
        int GetSize();
        Word GetItem(int pos);
        void SetItem(Word word, int pos);
        void SetOrder(string order);
        void InsertLast(Word palavra);
        void Search(string palavra);
        void print();
};



#endif

