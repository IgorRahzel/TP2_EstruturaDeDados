//---------------------------------------------------------------------
// Arquivo      : Sort.cpp
// Conteudo     : implementacao da classe Sort
//                -implementacao dos métodos de ordenação
// Autor        : Igor Rahzel Colares Galdino (igorrahzel@ufmg.br)
//---------------------------------------------------------------------
#include "Sort.h"
#include <cstring>

/*aloca um vetor 'array' 
com tamanho de size*/
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

/*Ordena através de insercao 
uma particao do vetor*/
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

/*Ordena por insercao o vetor 
usado para obter a mediana de m */
void Sort::Insertion(Word *&median,int m) {
    

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

/*Ordena uma particao do vetor */
void Sort::Partition(int L, int R,int *i, int *j,int m){

    Word x, v;
    *i = L; *j = R;
    
    /*Escolhendo pivô pela mediana de 'm'*/
    if(m > 1){

        Word *median = new Word[m];
        for(int c = L; c < L+m; c++){
            median[c-L] = array[c];
        }
        
        Insertion(median,m);
        int p = m/2;
        x = median[p];
        delete []median;
       
    }
    /*Escolhendo elemento do meio da particao como pivô*/
    else{
        x = array[(*i + *j)/2]; 

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

/* parte recursiva do quicksort */
void Sort::sort(int L, int R,int s,int m){

    int i;
    int j;
    int subArray_size = R - L + 1;
    /*Condicoes para realizar particao*/
    if((subArray_size <= s && s>1) || (subArray_size < m && subArray_size > s)){
        Insertion(L,R);
    }
    /*chamadas recursivas do método sort*/
    else{
        Partition(L, R, &i, &j, m);
        if (L < j) sort(L, j,s,m);
        if (i < R) sort(i, R,s,m);
    }
}

void Sort::QuickSort(int n,int s = 0,int m = 0){

   sort(0, n-1,s,m);
}
/*Método análogo ao operador '>'
baseado na nova ordem lexicográfica*/
bool Sort::AllowSwap(string w1, string w2){

    int min; /*tamanho da menor palavra*/

    int index1; /*posição de uma letra de 'w1' em relação a nova ordem*/
    int index2; /*posição de uma letra de 'w2' em relação a nova ordem*/

    int n1 = w1.length();
    int n2 = w2.length();

    char a1[n1 +1];
    char a2[n2 +1];
    strcpy(a1, w1.c_str()); /*transformar 'w1' em char array*/
    strcpy(a2, w2.c_str()); /*transformar 'w2' em char array*/

    bool contains = false; /*verificar se palavra está contida em outra*/
    bool found1; /*verificar se caracter de 'w1' nao esta no alfabeto */
    bool found2; /*verificar se caracter de 'w2' nao esta no alfabeto */

    string shortest; /*identifica qual é a menor palavra */

    /*encontrar menor palavra */
    if(w1.length() > w2.length()){
        min = w2.length();
        shortest = w2;
    }
    else{
        min = w1.length();
        shortest = w1;
    }

    /*loop para verificar qual palavra é maior*/
    for (int i = 0; i < min; i++){
        found1 = false;
        found2 = false;
        
        for (int j = 0; j < 26; j++){
            if(a1[i] == order[j]){
                index1 = j;
                found1 = true;
                break;
            }
            /*caso caracter da palavra 'w1' nao pertenca ao alfabeto*/
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
                /*caso caracter da palavra 'w2' nao pertenca ao alfabeto*/
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
        /*caso uma palavra esteja contida na outra, e.g 'ver' e 'verde'*/
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
