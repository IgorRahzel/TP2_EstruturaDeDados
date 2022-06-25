#include "List.h"
#include <iostream>

List::List(){

    head = new Node();
    tail = head;
    tamanho = 0;
}

List::~List(){
    
    //clear();
    delete head;
}

Node* List::place(int pos, bool before = false){
    
    Node *p;
    int i;
    
    p = head;
    for(i=1; i<pos; i++){
        p = p->next;
    }
    
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

void List::InsertLast(Word word){

    Node *nova;
    nova = new Node();
    nova->w = word;
    tail->next = nova;
    tail = nova;
    tamanho++;

}

void List::InsertPosition(string word, int pos){
    Node *p, *nova;
    p = place(pos,true); // posiciona na célula anterior
    nova = new Node();
    nova->w.setWord(word);
    nova->next = p->next;
    p->next = nova;
    tamanho++;

    if(nova->next == NULL)
        tail = nova;

}

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

void List::print(){

    Node*p;
    p = head->next;

    while(p!=NULL){
        cout << p->w.getWord() << " " << p->w.getOccurrences() << endl;
        p = p->next;
    }

}
