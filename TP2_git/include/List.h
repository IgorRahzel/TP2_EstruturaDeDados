#ifndef LIST_H
#define LIST_H
#include "Node.h"

class List{
    //private: 
    public:
        int tamanho;
        Node* head;
        Node* tail;
        Node* place(int pos, bool before);
        string order;
    
        List();
        ~List();
        Word GetItem(int pos);
        void SetItem(Word word, int pos);
        void SetOrder(string order);
        void InsertBeginning(Word palavra);
        void InsertLast(Word palavra);
        void InsertPosition(string palavra, int pos);
        Word RemoveBeginning();
        Word RemoveLast();
        Word RemovePosition(int pos);
        void Sort();
        void AllowSwap();
        void Partition(Node* i, Node* j);
        void Search(string palavra);
        void print();
        void clear();
};



#endif

