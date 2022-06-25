#ifndef SORT_H
#define SORT_H
#include "Word.h"

class Sort{
    private:
        Word* array;
    public:
        Sort();
        Sort(int size);
        void SetWord(Word p, int pos);
        Word GetWord(int pos);
        void Partition(int L, int R,int *i, int *j);
        void sort(int Esq, int Dir);
        void QuickSort(int n);

};




#endif