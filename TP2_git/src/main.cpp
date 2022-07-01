#include <iostream>
#include <fstream>
#include <getopt.h>
#include "List.h"
#include "Sort.h"

string clearString(string input){
    int p = input.length()-1;
    while((input[p] == ',') || (input[p] == '.') || (input[p] == '!') || (input[p] == '?') || (input[p] == ':') ||
       (input[p] == ';') || (input[p] == '_' )){

        input.pop_back();
        p = input.length()-1;
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

    while((option_val = getopt(argc,argv,"I:i:S:s:M:m:O:o:"))!= -1){
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
            while(file >> aux){
                if(aux.compare("#TEXTO") == 0){
                    break;
                }
                else{
                    order += aux;
                }
            }
            while(file >> input){
                input = clearString(input);
                list.Search(input); 
            }
        
        }
    }
    file.close();
    
    size = list.GetSize();
    Sort srt(size);
    srt.SetOrder(order);

    for(int i = 0; i < size; i++){
        
        srt.SetWord(list.GetItem(i+1),i);
    }
    
    srt.QuickSort(size,s,m);
    
    file.open(output_file,ios::out);
    if(file.is_open()){
        for(int i = 0; i < size; i++){
            file << srt.GetWord(i).getWord() <<  " " << srt.GetWord(i).getOccurrences() << endl;
        }
        file << "#FIM" << endl;
    }

    return 0;
}