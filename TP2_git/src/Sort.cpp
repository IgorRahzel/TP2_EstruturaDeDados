#include "Sort.h"
#include <cstring>

Sort::Sort(int size){
    this->size = size -1;
    array = new Word[size];
    chamada = 0;
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

void Sort::printOrder(){

    for (long unsigned int i = 0; i < strlen(order); i++)
    {
        cout << order[i];
    }
    cout << endl;
}

void Sort::SetWord(Word p, int pos){

    array[pos] = p;

}

void Sort::Insertion(int L,int R){

    int i,j;
    Word aux;
    cout << "entrou na inserção" <<endl;
    cout << endl << endl << " -- SUBARRAY --" << endl << endl;
    for(int c = L; c<=R ; c++){
        cout << array[c].getWord() << "|";
    }
        cout << endl << endl;

    for (i = L; i <= R; i++) {
        aux = array[i];
        j = i - 1;
        while (( j >= 0 ) && (AllowSwap2(aux.getWord(),array[j].getWord()))) {
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
    while (( j >= 0 ) && (AllowSwap2(aux.getWord(),median[j].getWord()))) {
    median[j + 1] = median[j];
    j--;
    }
    median[j + 1] = aux;
    }
    
    cout << endl << endl;
    for(int c = 0; c < m; c++){
        cout << "Ordenados-median[" << c <<"]: " << median[c].getWord() << "|";
    }
    cout << endl << endl;
}

void Sort::Partition(int L, int R,int *i, int *j,int m){

    Word x, v;
    *i = L; *j = R;
    
    //Escolhendo pivô pela mediana
    if(m > 1){
        cout << endl << endl << " -- FAZENDO MEDIANA -- " << endl << endl;

        Word *median = new Word[m];
        for(int c = L; c < L+m; c++){
            median[c-L] = array[c];
        }
        cout <<  endl << endl;
        for(int c = 0; c < m; c++){
            cout <<" median[" << c << "]: " << median[c].getWord() << "|";
        }
        cout << endl << endl;
        Insertion(median,m,L);
        int p = m/2;
        x = median[p];
        cout << "pivô: " << x.getWord() << endl;
        delete []median;
       
    }
    else{
        cout << endl << " -- NÃO FAZ MEDIANA -- " << endl << endl;
        x = array[(*i + *j)/2]; /* obtem o pivo x */
        cout << "pivô: " << x.getWord() << endl;
    }
    do
    {
        //cout << "pivô: " << x.getWord() << endl;
        while (AllowSwap(x.getWord(),array[*i].getWord())) (*i)++;
        while (AllowSwap2(x.getWord(),array[*j].getWord())) (*j)--;
        if (*i <= *j)
        {
        v = array[*i]; array[*i] = array[*j]; array[*j] = v;
        for(int c = 0; c<size+1;c++){
            cout << array[c].getWord() << "|";
        }
        cout << endl;
        (*i)++; (*j)--;
        }
    } while (*i <= *j);
    
}
// Tamanho do subvetor <= s || tamanho do subvetor <= m

// chama inserção

// Senao

// chama quicksort
void Sort::sort(int Esq, int Dir,int s,int m){

    int i;
    int j;
    int subArray_size = Dir - Esq + 1;
    if((subArray_size <= s && s>1) || (subArray_size < m && subArray_size > s)){
        Insertion(Esq,Dir);
    }
    else{
        Partition(Esq, Dir, &i, &j, m);
        if (Esq < j) sort(Esq, j,s,m);
        if (i < Dir) sort(i, Dir,s,m);
    }
}

void Sort::QuickSort(int n,int s = 0,int m = 0){

   sort(0, n-1,s,m);
}

bool Sort::AllowSwap(string w1, string w2){
    chamada ++;
    cout << "(Allow1)chamada: " << chamada << endl <<endl;

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

    cout << "w1: ";
    for (long unsigned int i = 0; i < strlen(a1); i++)
    {
        cout<< a1[i];
    }
    cout << endl;
    cout << "w2: ";
    for (long unsigned int i = 0; i < strlen(a2); i++)
    {
        cout << a2[i];
    }
    cout << endl;

    

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
                cout << "index1: " << index1 << " " << order[j] << endl;
                break;
            }
            else if(found1 == false && j == 25){
                index1 = a1[i];
                index2 = a2[i];
                cout << " USANDO -> ASCII " << endl;
                cout << "index1: " << index1 << " " << a1[i] << endl;
                cout << "index2: " << index2 << " " << a2[i] << endl;
                break;
            }
        }
        if(found1 == true){
            for (int j = 0; j < 26; j++){
                if(a2[i] == order[j]){
                    index2 = j;
                    cout << "index2: " << index2 << " " << order[j] << endl;
                    break;
                }
                else if((found2 == false && j == 25)){
                    index2 = a2[i];
                    index1 = a1[i];
                    cout << " USANDO -> ASCII " << endl;
                    cout << "index1: " << index1 << " " << a1[i] << endl;
                    cout << "index2: " << index2 << " " << a2[i] << endl;
                    break;
                }
            }
        }
        
        if(index1 != index2){
            break;
        }
        if(i == min-1 && index1==index2 && w1.compare(w2)!=0){
            cout << "entrou no contains" << endl;
            contains = true;
        }

    }
    if(contains == false){
        if(index1 > index2){
            cout << "true: " << index1 << " >= " << index2 << endl;
            cout <<"################################" <<endl;
            return true;
        }
        else{
            cout << "false: " << index1 << " < " << index2 << endl;
            cout <<"################################" <<endl;
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


bool Sort::AllowSwap2(string w1, string w2){
    chamada ++;
    cout << "(Allow2)chamada: " << chamada << endl << endl;

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

    cout << "w1: ";
    for (long unsigned int i = 0; i < strlen(a1); i++)
    {
        cout<< a1[i];
    }
    cout << endl;
    cout << "w2: ";
    for (long unsigned int i = 0; i < strlen(a2); i++)
    {
        cout << a2[i];
    }
    
    cout << endl;

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
                cout << "index1: " << index1 << " " << order[j] << endl;
                break;
            }
            else if(found1 == false && j == 25){
                    index1 = a1[i];
                    index2 = a2[i];
                    cout << " USANDO -> ASCII " << endl;
                    cout << "index1: " << index1 << " " << a1[i] << endl;
                    cout << "index2: " << index2 << " " << a2[i] << endl;
                    break;
                }
           
        }
        if(found1==true){
            for (int j = 0; j < 26; j++){
                if(a2[i] == order[j]){
                    index2 = j;
                    found2 = true;
                    cout << "index2: " << index2 << " " << order[j] << endl;
                    break;
                }
                else if((found2 == false && j == 25)){
                    index2 = a2[i];
                    index1 = a1[i];
                    cout << " USANDO -> ASCII " << endl;
                    cout << "index1: " << index1 << " " << a1[i] << endl;
                    cout << "index2: " << index2 << " " << a2[i] << endl;
                    break;
                }
                
            }
        }
        if(index1 != index2){
            break;
        }

        if(i == min -1 && index1 == index2 && w1.compare(w2)!=0){
            cout << "entrou no contains" << endl;
            contains = true;
        }

    }
    if(contains == false){
        if(index1 < index2){
            cout << "true: " << index1 << " < " << index2 << endl;
            cout <<"################################" <<endl;
            return true;
        }
        else{
            cout << "false: " << index1 << " >= " << index2 << endl;
            cout <<"################################" <<endl;
            return false;
            
        }
    }
    else{
        if(shortest.compare(w1)==0)
            return true;
        else
            return false;
    }
    
}