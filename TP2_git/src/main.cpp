#include <iostream>
#include <fstream>
#include "List.h"

int main(int argc,char **argv){

    string s;
    string aux;
    string order;

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

    list.print();

    

    return 0;
}