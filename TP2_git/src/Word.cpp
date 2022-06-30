#include "Word.h"

Word::Word(){
    occurrences = 1;
}


string Word::getWord(){
    return word;
}

void Word::setWord(string w){
    word = w;
}

int Word::getOccurrences(){
    return occurrences;
}

void Word::AddOcurrences(){
    occurrences++;
}

 bool Word::WordMatches(string s){
    for (long unsigned int i = 0; i < s.length(); i++){
        s[i] = tolower(s[i]);
    }
        if(word.compare(s)==0){
            return true;
        }
        else
            return false;

 }

