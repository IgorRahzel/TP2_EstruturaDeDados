#include "Sort.h"
#include <cstring>

Sort::Sort(int size){
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

void Sort::Partition(int L, int R,int *i, int *j){

Word x, v;
*i = L; *j = R;
x = array[(*i + *j)/2]; /* obtem o pivo x */
do
{
    while (AllowSwap(x.getWord(),array[*i].getWord())) (*i)++;
    while (AllowSwap2(x.getWord(),array[*j].getWord())) (*j)--;
    if (*i <= *j)
    {
    v = array[*i]; array[*i] = array[*j]; array[*j] = v;
     for(int c = 0; c<9;c++){
        cout << array[c].getWord() << "|";
    }
    cout << endl;
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

bool Sort::AllowSwap(string w1, string w2){
    chamada ++;
    cout << "(Allow1)chamada: " << chamada << endl;

    int min;
    int index1;
    int index2;
    int n1 = w1.length();
    int n2 = w2.length();
    char a1[n1 +1];
    char a2[n2 +1];
    strcpy(a1, w1.c_str());
    strcpy(a2, w2.c_str());

    cout << "w1: ";
    for (long unsigned int i = 0; i < strlen(a1); i++)
    {
        cout<< a1[i];
    }
    cout << endl << endl;
    cout << "w2: ";
    for (long unsigned int i = 0; i < strlen(a2); i++)
    {
        cout << a2[i];
    }
    cout << endl;

    

    if(w1.length() > w2.length())
        min = w2.length();
    else
        min = w1.length();

    for (int i = 0; i < min; i++){
        
        for (int j = 0; j < 26; j++){
            if(a1[i] == order[j]){
                index1 = j;
                cout << "index1: " << index1 << " " << order[j] << endl;
                break;
            }
        }

        for (int j = 0; j < 26; j++){
            if(a2[i] == order[j]){
                index2 = j;
                cout << "index2: " << index2 << " " << order[j] << endl;
                break;
            }
        }
        
        if(index1 != index2){
            break;
        }

    }

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


bool Sort::AllowSwap2(string w1, string w2){
    chamada ++;
    cout << "(Allow2)chamada: " << chamada << endl;

    int min;
    int index1;
    int index2;
    int n1 = w1.length();
    int n2 = w2.length();
    char a1[n1 +1];
    char a2[n2 +1];
    strcpy(a1, w1.c_str());
    strcpy(a2, w2.c_str());

    cout << "w1: ";
    for (long unsigned int i = 0; i < strlen(a1); i++)
    {
        cout<< a1[i];
    }
    cout << endl << endl;
    cout << "w2: ";
    for (long unsigned int i = 0; i < strlen(a2); i++)
    {
        cout << a2[i];
    }
    
    cout << endl;

    if(w1.length() > w2.length())
        min = w2.length();
    else
        min = w1.length();

    for (int i = 0; i < min; i++){
        
        for (int j = 0; j < 26; j++){
            if(a1[i] == order[j]){
                index1 = j;
                cout << "index1: " << index1 << " " << order[j] << endl;
                break;
            }
        }

        for (int j = 0; j < 26; j++){
            if(a2[i] == order[j]){
                index2 = j;
                cout << "index2: " << index2 << " " << order[j] << endl;
                break;
            }
        }
        
        if(index1 != index2){
            break;
        }

    }

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