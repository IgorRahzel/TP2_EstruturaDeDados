#include "Sort.h"
#include <cstring>

Sort::Sort(int size){
    this->size = size -1;
    array = new Word[size];
}

Word Sort::GetWord(int pos){

    return array[pos];
}

void Sort::SetOrder(string ord){
    for (long unsigned int i = 0; i < ord.length(); i++){
        ord[i] = tolower(ord[i]);
    }
    strcpy(order, ord.c_str());
    
}

void Sort::SetWord(Word p, int pos){

    array[pos] = p;

}

void Sort::Insertion(int L,int R){

    int i,j;
    Word aux;

    for (i = L; i <= R; i++) {
        aux = array[i];
        j = i - 1;
        while (( j >= 0 ) && (AllowSwap(array[j].getWord(),aux.getWord()))) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = aux;
    }
}

void Sort::Insertion(Word *&median,int m,int L) {
    

    int i,j;
    Word aux;

    for (i = 0; i < m; i++) {
    aux = median[i];
    j = i - 1;
    while (( j >= 0 ) && (AllowSwap(median[j].getWord(),aux.getWord()))) {
    median[j + 1] = median[j];
    j--;
    }
    median[j + 1] = aux;
    }
}

void Sort::Partition(int L, int R,int *i, int *j,int m){

    Word x, v;
    *i = L; *j = R;
    
    //Escolhendo pivô pela mediana
    if(m > 1){

        Word *median = new Word[m];
        for(int c = L; c < L+m; c++){
            median[c-L] = array[c];
        }
        
        Insertion(median,m,L);
        int p = m/2;
        x = median[p];
        delete []median;
       
    }
    else{
        x = array[(*i + *j)/2]; /* obtem o pivo x */

    }
    do
    {
        
        while (AllowSwap(x.getWord(),array[*i].getWord())) (*i)++;
        while (AllowSwap(array[*j].getWord(),x.getWord())) (*j)--;
        if (*i <= *j)
        {
        v = array[*i]; array[*i] = array[*j]; array[*j] = v;
        (*i)++; (*j)--;
        }
    } while (*i <= *j);
    
}
// Tamanho do subvetor <= s || tamanho do subvetor <= m

// chama inserção

// Senao

// chama quicksort
void Sort::sort(int L, int R,int s,int m){

    int i;
    int j;
    int subArray_size = R - L + 1;
    if((subArray_size <= s && s>1) || (subArray_size < m && subArray_size > s)){
        Insertion(L,R);
    }
    else{
        Partition(L, R, &i, &j, m);
        if (L < j) sort(L, j,s,m);
        if (i < R) sort(i, R,s,m);
    }
}

void Sort::QuickSort(int n,int s = 0,int m = 0){

   sort(0, n-1,s,m);
}

bool Sort::AllowSwap(string w1, string w2){

    int min;
    int index1;
    int index2;
    int n1 = w1.length();
    int n2 = w2.length();
    char a1[n1 +1];
    char a2[n2 +1];
    strcpy(a1, w1.c_str());
    strcpy(a2, w2.c_str());
    bool contains = false;
    bool found1;
    bool found2;
    string shortest;

    if(w1.length() > w2.length()){
        min = w2.length();
        shortest = w2;
    }
    else{
        min = w1.length();
        shortest = w1;
    }

    for (int i = 0; i < min; i++){
        found1 = false;
        found2 = false;
        
        for (int j = 0; j < 26; j++){
            if(a1[i] == order[j]){
                index1 = j;
                found1 = true;
                break;
            }
            else if(found1 == false && j == 25){
                index1 = a1[i];
                index2 = a2[i];
                break;
            }
        }
        if(found1 == true){
            for (int j = 0; j < 26; j++){
                if(a2[i] == order[j]){
                    index2 = j;
                    break;
                }
                else if((found2 == false && j == 25)){
                    index2 = a2[i];
                    index1 = a1[i];
                    break;
                }
            }
        }
        
        if(index1 != index2){
            break;
        }
        if(i == min-1 && index1==index2 && w1.compare(w2)!=0){
            contains = true;
        }

    }
    if(contains == false){
        if(index1 > index2){
            return true;
        }
        else{
            return false;  
        }
    }
    else{
        if(shortest.compare(w2)==0)
            return true;
        else
            return false;

    }

}
