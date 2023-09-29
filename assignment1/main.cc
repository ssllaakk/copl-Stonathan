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

    parser.parse();

    if(parser.getPassed()){
        std::cout << "PASSED" << std::endl;
    }else{
        std::cout << "FAILED" << std::endl;
    }
    
    return !(parser.getPassed());
}