#include <iostream>
#include <string>
#include "lex.h"

void Lex::addChar(){ // begin of addChar
    if(lexLen < MAXLEN - 1){
        lexeme[lexLen] = nextChar;
        lexLen++;
        lexeme[lexLen] = 0;
    }else{
        std::cerr << "lexeme is already full" << std::endl;
    }
} // end of addChar

void Lex::getChar(){ // begin of getChar

    // Expression end at \n
    lineIndex++;

    if(!(std::cin.eof() && lineIndex >= (int)currentLine.length())){

        if(lineIndex >= (int)currentLine.length()){
            std::getline(std::cin, currentLine);
            lineIndex = 0;
        }
        nextChar = currentLine[lineIndex];
    
        if(isalpha(nextChar)){
            charClass = LETTER;
        }else if(isdigit(nextChar)){
            charClass = DIGIT;
        }else{
            charClass = UNKNOWN;
        }
    }else {
        charClass = EOF;
    }
} // end of getChar

void Lex::getNonBlank(){
    while((isspace(nextChar) || nextChar == 0) && !(charClass == EOF)){
        getChar();
    }
}

int Lex::lookup(char ch){ // begin of lookup
    switch (ch)
    {
    case '(':
        addChar();
        return LEFT_PAREN;
        break;

    case ')':
        addChar();
        return RIGHT_PAREN;
        break;
    
    case '\\':
        addChar();
        return LAMBDA;
        break;
    }
    return ERROR;
} // end of lookup

int Lex::getToken(){ // begin of getToken
    lexLen = 0;
    getNonBlank();
    switch (charClass)
    {
    case LETTER:
        while(charClass == LETTER || charClass == DIGIT){
            addChar();
            getChar();
        }
        nextToken = VAR;
        break;
    case DIGIT:
        std::cerr << "Syntax error at charater " << nextChar
         << ". Variable may not start with a digit " << nextChar <<  std::endl;
        getChar();
        nextToken = ERROR;
        break;

    case UNKNOWN:
        nextToken = lookup(nextChar);
        if(nextToken == ERROR){
            std::cerr << " Next token is: " << nextToken << "\t Character "
                     << nextChar << " is unkown " << std::endl;
        }
        getChar();
        break;

    case EOF:
        nextToken = EOF;
        lexeme[0] = 'E';
        lexeme[1] = 'O';
        lexeme[2] = 'F';
        lexeme[3] = 0;
        break;
    }

    if(!(nextToken == ERROR)){
        std::cout << " Next token is: " << nextToken << "\t Next lexeme is " << lexeme << std::endl;
    }
    
    return nextToken;
} // end of getToken