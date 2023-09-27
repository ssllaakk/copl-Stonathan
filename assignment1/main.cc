#include <iostream>
#include "lex.h"

// 1. Lexical analysis
// 2. Parsen


int main(){

    // looped de lexer
    // return 1 bij error

    Lex lex;
    int token = 0;

    lex.getChar();
    do{
        token = lex.analyse();
    } while (token != EOF);

    return 0;
}