//---------------------------------------------------------------------
// Arquivo      : main.cpp
// Conteudo     : implementacao do programa principal
//                -leitura do arquivo de entrada
//                -criação do arquivo de saida
// Autor        : Igor Rahzel Colares Galdino (igorrahzel@ufmg.br)
//---------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <getopt.h>
#include "List.h"
#include "Sort.h"

/*Remove sinais de pontuacao do final da palavra*/
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
    string input; /*palavras do arquivo de entrada*/
    string aux; /*ler sequencia de letras da nova ordem*/
    string order; /*ordem lexicográfica*/

    int size; /*numero de palavras diferentes*/
    int m; 
    int s;

    List list;
    fstream file;

    int option_val; /*utilizado para ler parametros da linha de comando*/

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

        /*leitura do arquivo de entrada*/
        if(input.compare("#TEXTO") == 0){  /*caso '#TEXTO' apareca prrimeiro*/
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
        else if(input.compare("#ORDEM") == 0){ /*caso '#ORDEM' apareca prrimeiro*/
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

    /*passa palavras para o 'array' de 'srt'*/
    for(int i = 0; i < size; i++){
        
        srt.SetWord(list.GetItem(i+1),i);
    }
    
    srt.QuickSort(size,s,m);
    
    /*escreve arquivo de saida*/
    file.open(output_file,ios::out);
    if(file.is_open()){
        for(int i = 0; i < size; i++){
            file << srt.GetWord(i).getWord() <<  " " << srt.GetWord(i).getOccurrences() << endl;
        }
        file << "#FIM" << endl;
    }
    file.close();

    return 0;
}