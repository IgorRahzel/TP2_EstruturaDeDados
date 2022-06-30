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
    string input_file;
    string output_file;
    string input;
    string aux;
    string order;
    int size;
    int m;
    int s;
    List list;
    fstream file;

    int option_val;

    while((option_val = getopt(argc,argv,"I:i:S:s:M:m:O:O:"))!= -1){
        switch (option_val)
        {
        case 'I':
            input_file = optarg;
            break;
        case 'i':
            input_file = optarg;
            break;
        case 'S':
            s = atoi(optarg);
            break;
        case 's':
            s = atoi(optarg);
            break;
        case 'M':
            m = atoi(optarg);
        case 'm':
            m = atoi(optarg);
        case 'O':
            output_file = optarg;
            break;
        case 'o':
            output_file = optarg;
            break;
        default:
            break;
        }
    }

    file.open(input_file,ios::in);
    
    if (file.is_open()){
        
        file >> input;
        
        if(input.compare("#TEXTO") == 0){
            while(file >> input){  
                if(input.compare("#ORDEM") == 0)
                    break;
                else{
                    input = clearString(input);
                    list.Search(input);
                }
            }
            for(int i = 0; i < 26; i++){
                file >> aux;
                order += aux;
            }
        }
        else if(input.compare("#ORDEM") == 0){
            while(aux.compare("#TEXTO") != 0){
                file >> aux;
                order += aux;
            }
            while(file >> input){
                input = clearString(input);
                list.Search(input); 
            }
        
        }
        /*
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
        */

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