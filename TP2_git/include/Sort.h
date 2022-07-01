#ifndef SORT_H
#define SORT_H
#include "Word.h"

class Sort{
    private:
        Word* array;
        char order[27];
        int size;

    public:
        Sort();
        Sort(int size);
        void SetOrder(string order);
        void SetWord(Word p, int pos);
        Word GetWord(int pos);
        void Partition(int L, int R,int *i, int *j,int m);
        void sort(int Esq, int Dir,int s,int m);
        void QuickSort(int n,int s,int m);
        bool AllowSwap(string w1, string w2);
        bool AllowSwap2(string w1, string w2);
        void Insertion(int L,int R);
        void Insertion(Word *&median, int m, int L);

};




#endif