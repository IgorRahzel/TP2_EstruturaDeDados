#include <iostream>
#include <fstream>
#include <getopt.h>
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

    string input;
    string aux;
    string order;
    int size;
    int m;
    int s;
    List list;
    fstream file;
    file.open("entrada.txt",ios::in);

    int option_val;

    while((option_val = getopt(argc,argv,"s:m:"))!= -1){
        switch (option_val)
        {
        case 's':
            s = atoi(optarg);
            break;
        case 'm':
            m = atoi(optarg);
        default:
            break;
        }
    }

    
    if (file.is_open()){
        
        file >> input;
        if(input.compare("#TEXTO")==0){
            while(file >> input)
                if(input.compare("#ORDEM")==0)
                    break;
                else{
                    input = clearString(input);
                    list.Search(input);
                }
        }
        if(input.compare("#ORDEM")==0){
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

    cout << endl;

    for(int i = 0; i < size; i++){
        
        srt.SetWord(list.GetItem(i+1),i);
    }

    for(int c = 0; c<size;c++){
        cout << srt.GetWord(c).getWord() << "|";
    }
    cout << endl;
    cout << "s: " << s << " m: " << m << endl;
    
    srt.QuickSort(size,s,m);

     for(int i = 0; i < size; i++){
        cout << srt.GetWord(i).getWord() <<  " " << srt.GetWord(i).getOccurrences() << endl;

    }
    

    return 0;
}