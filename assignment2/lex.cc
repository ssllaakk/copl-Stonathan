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
    

    if(!(lineIndex >= (int)currentLine.length())){
        nextChar = currentLine[lineIndex];
        lineIndex++;
    
        if(isalpha(nextChar)){
            charClass = CharacterClass::LETTER;
        }else if(isdigit(nextChar)){
            charClass = CharacterClass::DIGIT;
        }else{
            charClass = CharacterClass::UNKNOWN;
        }
    } else {
        charClass = CharacterClass::EOF_;
    }
} // end of getChar

void Lex::getNonBlank(){
    while((isspace(nextChar) || nextChar == 0) && !(charClass == CharacterClass::EOF_)){
        getChar();
    }
}

TokenCodes Lex::lookup(char ch){ // begin of lookup
    switch (ch)
    {
    case '(':
        addChar();
        return TokenCodes::LEFT_PAREN;
        break;

    case ')':
        addChar();
        return TokenCodes::RIGHT_PAREN;
        break;
    
    case '\\':
        addChar();
        return TokenCodes::LAMBDA;
        break;
    }
    return TokenCodes::ERROR;
} // end of lookup

Token Lex::getToken(){ // begin of getToken
    lexLen = 0;
    getNonBlank();
    switch (charClass)
    {
    case CharacterClass::LETTER:
        while(charClass == CharacterClass::LETTER || charClass == CharacterClass::DIGIT){
            addChar();
            getChar();
        }
        nextToken.code = TokenCodes::VAR;
        break;
    case CharacterClass::DIGIT:
        std::cerr << "Syntax error at charater " << nextChar
         << ". Variable may not start with a digit " << nextChar <<  std::endl;
        getChar();
        nextToken.code = TokenCodes::ERROR;
        break;

    case CharacterClass::UNKNOWN:
        nextToken.code = lookup(nextChar);
        if(nextToken.code == TokenCodes::ERROR){
            std::cerr << "Character "
                     << nextChar << " is unkown " << std::endl;
        }
        getChar();
        break;

    case CharacterClass::EOF_:
        nextToken.code = TokenCodes::EOF_;
        lexeme[0] = 'E';
        lexeme[1] = 'O';
        lexeme[2] = 'F';
        lexeme[3] = 0;
        break;
    }
    
    nextToken.var = lexeme;
    // std::cout << "TokenCode: " << nextToken.toString();
    // if(nextToken.code == TokenCodes::VAR){
    //     std::cout << " " << nextToken.var;
    // }
    // std::cout << std::endl;
    return nextToken;
} // end of getToken