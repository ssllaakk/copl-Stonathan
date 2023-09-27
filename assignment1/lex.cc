#include "lex.h" 
#include <iostream>

void Lex::addChar(){ // begin of addChar
    if(lexLen < MAXLEN - 1){
        lexeme[lexLen] = nextChar;
        lexLen++;
        lexeme[lexLen] = 0;
    }else{
        std::cerr << "lexeme is already full" << std::endl;
        exit(1);
    }
} // end of addChar

void Lex::getChar(){ // begin of getChar
    if(lineIndex < (int)currentLine.length() - 1){
        lineIndex++;
    }else{
        std::getline(std::cin, currentLine);
        currentLine = currentLine + (char)0;
        lineIndex = 0;
    }
    nextChar = currentLine[lineIndex];
    if(!std::cin.eof()){
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
    while(isspace(nextChar) || nextChar == 0){
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

int Lex::analyse(){ // begin of analyse
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
        std::cerr << "DIGIT error at character #" << std::endl;
        exit(1);
        break;

    case UNKNOWN:
        nextToken = lookup(nextChar);
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

    std::cout << " Next token is: " << nextToken << "\t Next lexeme is " << lexeme << std::endl;
    return nextToken;
} // end of analyse