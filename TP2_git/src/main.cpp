#include <iostream>
#include <fstream>
#include "List.h"
#include "Sort.h"

string clearString(string input){
    int p = input.length()-1;
    if(input[p] == ',' || input[p] == '.' || input[p] == '!' || input[p] == '?' || input[p] == ':' ||
       input[p] == ';' || input[p] == '_' ){

        input.pop_back();
    }

    return input;
}

int main(int argc,char **argv){

    string s;
    string aux;
    string order;
    int size;
    List list;
    fstream file;
    file.open("entrada.txt",ios::in);
    
    
    if (file.is_open()){
        
        file >> s;
        if(s.compare("#TEXTO")==0){
            while(file >> s)
                if(s.compare("#ORDEM")==0)
                    break;
                else{
                    s = clearString(s);
                    list.Search(s);
                }
        }
        if(s.compare("#ORDEM")==0){
            for(int i = 0;i<26;i++){
                file >> aux;
                order += aux;
            }
            //cout << order << endl;
        }

    }
    

    /*
    while(cin>>s){
        list.Search(s);
    }
    */
    
    size = list.GetSize();
    Sort srt(size);
    srt.SetOrder(order);
    srt.printOrder();

    for(int i = 0; i < size; i++){
        
        srt.SetWord(list.GetItem(i+1),i);
    }

    for(int c = 0; c<11;c++){
        cout << srt.GetWord(c).getWord() << "|";
    }
    cout << endl;

    srt.QuickSort(size);

     for(int i = 0; i < size; i++){
        cout << srt.GetWord(i).getWord() <<  " " << srt.GetWord(i).getOccurrences() << endl;

    }


    

    

    return 0;
}