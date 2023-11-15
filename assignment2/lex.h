#include <iostream>
#include "constantes.h"


#ifndef LEXICAL_ANALYSER
#define LEXICAL_ANALYSER

class Lex{

public:
    int getToken(); // performs lexical analysis for
                   // Lambda calculus. Returns the next token

    void getChar(); // a function to get the next character
                    // of input and determine its character class
    void setExpression(std::string expression){
        currentLine = expression;
        lineIndex = 0;
    }
private:
    // functions
    
    void addChar(); // a function to add nextChar to lexeme

    int lookup(char ch); // function to lookup operators
                         // and parantheses which returns their token code
    void getNonBlank(); // a function to call getChar until it returns a 
                        // non-whitespace character

    // variables

    int charClass; // character class of nextChar
    char lexeme[MAXLEN]; // lexeme of nextToken
    char nextChar; // character currently analysis
    int lexLen; // length of lexeme
    int nextToken; // token of lexeme being build;

    std::string currentLine;
    int lineIndex;
};

#endif