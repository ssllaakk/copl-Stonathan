#include <iostream>
#include "lex.h"

// 1. Lexical analysis
// 2. Parsen
//  * Grammer versimpelen naar LL form
//  * Recursive decent parser bouwen


int main(){

    // looped de lexer
    // return 1 bij error

    Lex lex;
    int token = 0;

    lex.getChar();
    do{
        token = lex.analyse();
        // voer token in de parses
    } while (token != EOF);

    return 0;
}