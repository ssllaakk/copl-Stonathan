#include <iostream>
#include "parser.h"

// 1. Lexical analysis
// 2. Parsen
//  * Grammer versimpelen naar LL form
//  * Recursive decent parser bouwen


int main(){

    // loopt de parser
    // return 1 bij error

    Parser parser;
    std::string expression;
    
    while(!std::cin.eof()){
        std::getline(std::cin, expression);
        parser.parse(expression);
        std::cout << expression << std::endl;
    }
    
    if(parser.getPassed()){
        parser.dot();
    }
    return !(parser.getPassed());
}