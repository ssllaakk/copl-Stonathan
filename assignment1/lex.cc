#include <lex.h>

void Lex::addChar(){
    if(lexLen < MAXLEN - 1){
        lexeme[lexLen] = nextChar;
        lexLen++;
        lexeme[lexLen] = 0;
    }
}

void Lex::getChar(){
    if(!std::cin.eof()){
        std::cin >> nextChar;
        if(isalpha(nextChar)){
            charClass = LETTER;
        }else if(isdigit(nextChar)){
            charClass = DIGIT;
        }else{
            charClass = UNKNOWN;
        }
    }
}

int Lex::lookup(char ch){
    switch (ch)
    {
    case '(':
        addChar();
        nextToken = LEFT_PAREN;
        break;

    case ')':
        addChar();
        nextToken = RIGHT_PAREN;
        break;
    
    case '\\':
        addChar();
        nextToken = LAMBDA;
        break;
    }
}