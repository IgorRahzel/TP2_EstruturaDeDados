//---------------------------------------------------------------------
// Arquivo      : Word.h
// Conteudo     : cabeçalho da classe Word
// Autor        : Igor Rahzel Colares Galdino (igorrahzel@ufmg.br)
//---------------------------------------------------------------------

#ifndef WORD_H
#define WORD_H
#include <iostream>
#include <string>

using namespace std;

class Word{
    private:
        string word;
        int occurrences;
    friend class List;
    
    public:
        Word();
        string getWord();
        void setWord(string w);
        int getOccurrences();
        void AddOcurrences();
        bool WordMatches(string s);

};

#endif 