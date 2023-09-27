#include <iostream>
#include "constantes.h"


#ifndef LEXICAL_ANALYSER
#define LEXICAL_ANALYSER

class Lex{

public:
    int analyse(); // performs lexical analysis for
                   // Lambda calculus. Returns the next token

    void getChar(); // a function to get the next character
                    // of input and determine its character class

private:
    // functions
    
    void addChar(); // a function to add nextChar to lexeme

    int lookup(char ch); // function to lookup operators
                         // and parantheses which returns their token code

    // variables

    int charClass; // character class of nextChar
    char lexeme[MAXLEN]; // lexeme of nextToken
    char nextChar; // character currently analysis
    int lexLen; // length of lexeme
    int nextToken; // token of lexeme being build;
};

#endif