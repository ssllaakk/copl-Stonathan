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

    return parser.getPassed();
}