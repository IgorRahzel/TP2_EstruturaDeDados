//---------------------------------------------------------------------
// Arquivo      : List.cpp
// Conteudo     : implementacao da classe List
// Autor        : Igor Rahzel Colares Galdino (igorrahzel@ufmg.br)
//---------------------------------------------------------------------
#include "List.h"
#include <iostream>

List::List(){

    head = new Node();
    tail = head;
    size = 0;
}

List::~List(){
    
    size = 0;
    delete head;
}

int List::GetSize(){

    return size;
}

/*posiciona apontador em 
um determinado nó da lista*/
Node* List::place(int pos, bool before = false){
    
    Node *p;
    int i;
    
    p = head;
    for(i=1; i<pos; i++){
        p = p->next;
    }
    /*caso queira apontar pra posicao anterior*/
    if(!before)
        p = p->next;
    return p;
}

Word List::GetItem(int pos){
    Node *p;
    p = place(pos);
    return p->w;
}

void List::SetItem(Word item, int pos){
    Node *p;
    p = place(pos);
    p->w = item;
}

void List::SetOrder(string s){
    order = s;
}

/*insere palavra no final da lista*/
void List::InsertLast(Word word){

    Node *nova;
    nova = new Node();
    nova->w = word;

    tail->next = nova;
    nova->prev = tail;
    tail = nova;
    size++;

}

/*verifica se palavra está na lista, 
se não insere-a*/
void List::Search(string palavra){

    Node *p;

    p = head->next;
    bool found = false;

    while (p!=NULL) {
        found = p->w.WordMatches(palavra);
        if (found == true) {
            p->w.AddOcurrences();
            break;
        }
        p = p->next;
    }

    if (found == false){ 
        Word nova;
        for(long unsigned int i = 0; i < palavra.length(); i++)
            palavra[i] = tolower(palavra[i]);
        
        nova.setWord(palavra);
        InsertLast(nova);
    }

}












