#include <iostream>
#include <fstream>
#include "List.h"
#include "Sort.h"

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
                else
                    list.Search(s);
        }
        if(s.compare("#ORDEM")==0){
            for(int i = 0;i<26;i++){
                file >> aux;
                order += aux;
            }
            cout << order << endl;
        }

    }
    

    /*
    while(cin>>s){
        list.Search(s);
    }
    */
    
    size = list.GetSize();
    Sort srt(size);

    for(int i = 0; i < size; i++){
        
        srt.SetWord(list.GetItem(i+1),i);
    }

    srt.QuickSort(size-1);

     for(int i = 0; i < size; i++){
        cout << srt.GetWord(i).getWord() <<  " " << srt.GetWord(i).getOccurrences() << endl;

    }


    

    

    return 0;
}