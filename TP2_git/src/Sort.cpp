#include "Sort.h"

Sort::Sort(int size){
    array = new Word[size];
}

Word Sort::GetWord(int pos){

    return array[pos];
}

void Sort::SetWord(Word p, int pos){

    array[pos] = p;

}

void Sort::Partition(int L, int R,int *i, int *j){

Word x, v;
*i = L; *j = R;
x = array[(*i + *j)/2]; /* obtem o pivo x */
do
{
    while (x.getWord() > array[*i].getWord()) (*i)++;
    while (x.getWord() < array[*j].getWord()) (*j)--;
    if (*i <= *j)
    {
    v = array[*i]; array[*i] = array[*j]; array[*j] = v;
    (*i)++; (*j)--;
    }
} while (*i <= *j);

}

void Sort::sort(int Esq, int Dir){

    int i;
    int j;
    Partition(Esq, Dir, &i, &j);
    if (Esq < j) sort(Esq, j);
    if (i < Dir) sort(i, Dir);

}

void Sort::QuickSort(int n){

   sort(0, n-1);
}