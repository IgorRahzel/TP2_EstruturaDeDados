#ifndef SORT_H
#define SORT_H
#include "Word.h"

class Sort{
    private:
        Word* array;
        char order[27];
        int chamada;
    public:
        Sort();
        Sort(int size);
        void SetOrder(string order);
        void printOrder();
        void SetWord(Word p, int pos);
        Word GetWord(int pos);
        void Partition(int L, int R,int *i, int *j);
        void sort(int Esq, int Dir);
        void QuickSort(int n);
        bool AllowSwap(string w1, string w2);

};




#endif